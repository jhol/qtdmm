//======================================================================
// File:		dmm.cpp
// Author:	Matthias Toussaint
// Created:	Tue Apr 10 15:10:29 CEST 2001
//----------------------------------------------------------------------
// Permission to use, copy, modify, and distribute this software and its
// documentation  for any  purpose and  without fee is  hereby  granted,
// provided  that below copyright notice appear  in all copies  and that
// both  that  copyright  notice and  this permission  notice  appear in
// supporting documentation.
// 
// This  file is  provided AS IS  with no  warranties  of any kind.  The
// author shall  have no liability  with respect  to the infringement of
// copyrights, trade  secrets  or any patents by  this file  or any part
// thereof.  In no event will the author be liable  for any lost revenue
// or profits or other special, indirect and consequential damages.
//----------------------------------------------------------------------
// (c) 2001 Matthias Toussaint
//======================================================================

#include <dmm.h>
#include <unistd.h>
#include <errno.h>
#include <qapplication.h>

#include <stdio.h>

#include <iostream>
#include <qdatetime.h>

#define LOG_OUTPUT

DMM::DMM( QObject *parent, const char *name ) :
  QObject( parent, name ),
  m_handle( -1 ),
  m_speed( 600 ),
  m_parity( 0 ),
  m_device( "/dev/ttyS0" ),
  m_oldStatus( ReaderThread::NotConnected ),
  m_consoleLogging( false )
{
  m_readerThread = new ReaderThread( this );
  m_readerThread->start();
  
  m_c_cflag = CS7 | PARODD | CSTOPB | CREAD | CLOCAL;
}

DMM::~DMM()
{
}

void
DMM::setPortSettings( int bits, int stopBits, int parity )
{
  m_parity  = parity;
  m_c_cflag = CREAD | CLOCAL;
  
  if (stopBits == 2)
  {
    m_c_cflag |= CSTOPB;
  }
  switch (bits)
  {
  case 5:
    m_c_cflag |= CS5;
    break;
  case 6:
    m_c_cflag |= CS6;
    break;
  case 7:
    m_c_cflag |= CS7;
    break;
  case 8:
    m_c_cflag |= CS8;
    break;
  default:
    m_c_cflag |= CS7;
    break;
  }     
  switch (parity)
  {
  case 0:     // None
    break;
  case 1:     // Even
    m_c_cflag |= PARENB;
    break;
  case 2:     // Odd
    m_c_cflag |= PARENB;
    m_c_cflag |= PARODD;
  }    
}

void
DMM::setFormat( ReadEvent::DataFormat format )
{
  m_readerThread->setFormat( format );
}

void
DMM::setSpeed( int speed )
{
  m_speed = speed;
}

void
DMM::setDevice( const QString & device )
{
  m_device = device;
}

bool
DMM::open()
{
  struct termios attr;
  int    mdlns;
  
  memset( &attr, 0, sizeof( struct termios ) );
  
  m_handle = ::open( m_device.latin1(), O_RDWR | O_NOCTTY | O_NDELAY);
  
  if (-1 == m_handle)
  {
    switch (errno) 
    {
    case EACCES:
      m_error = tr( "Access denied for" );
      m_error += " ";
      m_error += m_device;
      m_error += ". ";
      break;
    case ENXIO: 
    case ENODEV: 
    case ENOENT:
      m_error = tr( "No such device" );
      m_error += " ";
      m_error += m_device;
      m_error += ". ";
      break;
    default:  
      m_error = tr( "Error opening" );
      m_error += " ";
      m_error += m_device;
      m_error += ". ";
      m_error += tr( "DMM connected and switched on?" );
      break;
    }
    
    emit error( m_error );
    
    return false;
  }
  
  fcntl( m_handle, F_SETFL, 0 );
  tcgetattr( m_handle, &m_oldSettings );
  
  attr.c_oflag = 0;
  attr.c_lflag = 0;
  //attr.c_iflag = IGNBRK;
  attr.c_cflag = m_c_cflag;
  if (0 == m_parity)          // Ignore parity errors
  {
    attr.c_iflag = IGNBRK | IGNPAR | INPCK;
  }
  else
  {
    attr.c_iflag = IGNBRK | IGNPAR;
  }
  
  //attr.c_cflag = CS7 | CSTOPB | CREAD | CLOCAL;
  attr.c_cc[VTIME]= 0;
  attr.c_cc[VMIN]= 0;
  
  if (600 == m_speed)
  {
    cfsetospeed( &attr, B600 ); 
    cfsetispeed( &attr, B600 );
  }
  else if (1200 == m_speed)
  {
    cfsetospeed( &attr, B1200 ); 
    cfsetispeed( &attr, B1200 );
  }
  else if (1800 == m_speed)
  {
    cfsetospeed( &attr, B1800 ); 
    cfsetispeed( &attr, B1800 );
  }
  else if (2400 == m_speed)
  {
    cfsetospeed( &attr, B2400 ); 
    cfsetispeed( &attr, B2400 );
  }
  else if (4800 == m_speed)
  {
    cfsetospeed( &attr, B4800 ); 
    cfsetispeed( &attr, B4800 );
  }
  else
  {
    cfsetospeed( &attr, B9600 ); 
    cfsetispeed( &attr, B9600 );
  }
  
  m_error = tr( "Error configuring serial port." );
  m_error += " ";
  m_error += m_device;
  m_error += ". ";
  
  if (-1 == tcsetattr( m_handle, TCSANOW, &attr )) 
  {  
    ::close(m_handle);
    m_handle = -1;
    
    emit error( m_error );
    
    return false;
  }
  
  mdlns = 0;
  if (-1 == ioctl( m_handle, TIOCMGET, &mdlns )) 
  {
    ::close(m_handle);
    m_handle = -1;
    
    emit error( m_error );
    
    return false;
  }

  mdlns &= ~TIOCM_RTS;
  if (-1 == ioctl( m_handle, TIOCMSET, &mdlns )) 
  {
    ::close(m_handle);
    m_handle = -1;
    
    emit error( m_error );
    
    return false;
  }
  
  m_error = tr( "Connecting ..." );
  emit error( m_error );
  
  m_readerThread->setHandle( m_handle );
  
  timerEvent( 0 );
  
  startTimer( 1000 );
  
  return true;
}

void
DMM::close()
{
  QTime t; t.start();
  killTimers();
  
  m_error = tr( "Not connected" );
  emit error( m_error );
  
  m_readerThread->setHandle( -1 );
  
  if (-1 != m_handle)
  {
    // restore
    ::tcsetattr( m_handle, TCSANOW, &m_oldSettings );
    
    ::close( m_handle );
    m_handle = -1;
  }
  
  m_oldStatus = ReaderThread::NotConnected;
}

void
DMM::timerEvent( QTimerEvent * )
{
  if (-1 == m_handle)
  {
    emit error( m_error );
  }
  else
  {
    m_readerThread->startRead();
  }
}

void
DMM::customEvent( QCustomEvent *ev )
{
  if (QEvent::User == ev->type())
  {
    QString val;
    QString special;
    QString unit;
  
    if (ReaderThread::Ok == m_readerThread->status())
    {
      ReadEvent *re = (ReadEvent *)ev;
      
      if (re->format() != ReadEvent::M9803RContinuous)
      {
        QString tmp = re->string();

        if (m_consoleLogging)
        {
          for (int i=0; i<tmp.length(); ++i)
          {
            fprintf( stdout, "%02X ", re->string()[i] );
          }
          fprintf( stdout, "\n" );
        }
        
        if (re->format() == ReadEvent::Metex14 ||
            re->format() == ReadEvent::Voltcraft14Continuous ||
            re->format() == ReadEvent::Voltcraft15Continuous)
        {
          val     = tmp.mid( 2, 7 ); //.stripWhiteSpace();
          unit    = tmp.mid( 9, 4 ).stripWhiteSpace();
          special = tmp.left( 3 ).stripWhiteSpace();
        }
        else if (re->format() == ReadEvent::PeakTech10)
        {
          val     = tmp.mid( 1, 6 ); //.stripWhiteSpace();
          unit    = tmp.mid( 7, 4 ).stripWhiteSpace();
        }

        double d_val = val.toDouble();

        if (unit.left(1) == "p")
        {
          d_val /= 1.0E12;
        }
        else if (unit.left(1) == "n")
        {
          d_val /= 1.0E9;
        }
        else if (unit.left(1) == "u")
        {
          d_val /= 1.0E6;
        }
        else if (unit.left(1) == "m")
        {
          d_val /= 1.0E3;
        }
        else if (unit.left(1) == "k")
        {
          d_val *= 1.0E3;
        }
        else if (unit.left(1) == "M")
        {
          d_val *= 1.0E6;
        }
        else if (unit.left(1) == "G")
        {
          d_val *= 1.0E9;
        }
        
        emit value( d_val, val, unit, special, true, re->id() );

        m_error = tr( "Connected" ) + " (" + m_name + " @ " + m_device + ")";
      }
      else
      {        
        if (re->string()[0] & 0x01)
        {
          val = "  0L";
        }
        else
        {
          val = re->string()[0] == 0x08 ? " -" : "  ";
          val += QChar( '0'+re->string()[4] );
          val += QChar( '0'+re->string()[3] );
          val += QChar( '0'+re->string()[2] );
          val += QChar( '0'+re->string()[1] );
        }
        
        double d_val = val.toDouble();

        bool showBar = true;
        
        switch (re->string()[5])
        {
        case 0x00:
          switch (re->string()[6])
          {
          case 0x00:
            unit = "mV";
            val = insertComma( val, 3 );
            d_val /= 10000.;
            break;
          case 0x01:
            unit = "V";
            val = insertComma( val, 1 );
            d_val /= 1000.;
            break;
          case 0x02:
            unit = "V";
            val = insertComma( val, 2 );
            d_val /= 100.;
            break;
          case 0x03:
            unit = "V";
            val = insertComma( val, 3 );
            d_val /= 10.;
            break;
          case 0x04:
            unit = "V";
            break;
          }
          special = "DC";
          break;
        case 0x01:
          switch (re->string()[6])
          {
          case 0x00:
            unit = "mV";
            val = insertComma( val, 3 );
            d_val /= 10000.;
            break;
          case 0x01:
            unit = "V";
            val = insertComma( val, 1 );
            d_val /= 1000.;
            break;
          case 0x02:
            unit = "V";
            val = insertComma( val, 2 );
            d_val /= 100.;
            break;
          case 0x03:
            unit = "V";
            val = insertComma( val, 3 );
            d_val /= 10.;
            break;
          case 0x04:
            unit = "V";
            break;
          }
          special = "AC";
          break;
        case 0x02:
          switch (re->string()[6])
          {
          case 0x00:
            unit = "mA";
            val = insertComma( val, 1 );
            d_val /= 1000.;
            break;
          case 0x01:
            unit = "mA";
            val = insertComma( val, 2 );
            d_val /= 100.;
            break;
          case 0x02:
            unit = "mA";
            val = insertComma( val, 3 );
            d_val /= 10.;
            break;
          }
          special = "DC";
          break;
        case 0x03:
          switch (re->string()[6])
          {
          case 0x00:
            unit = "mA";
            val = insertComma( val, 1 );
            d_val /= 1000.;
            break;
          case 0x01:
            unit = "mA";
            val = insertComma( val, 2 );
            d_val /= 100.;
            break;
          case 0x02:
            unit = "mA";
            val = insertComma( val, 3 );
            d_val /= 10.;
            break;
          }
          special = "AC";
          break;
        case 0x04:
          switch (re->string()[6])
          {
          case 0x00:
            unit = "Ohm";
            val = insertComma( val, 1 );
            d_val /= 10.;
            break;
          case 0x01:
            unit = "kOhm";
            val = insertComma( val, 1 );
            d_val /= 1000.;
            break;
          case 0x02:
            unit = "kOhm";
            val = insertComma( val, 2 );
            d_val /= 100.;
            break;
          case 0x03:
            unit = "kOhm";
            val = insertComma( val, 3 );
            d_val /= 10.;
            break;
          case 0x04:
            unit = "kOhm";
            break;
          case 0x05:
            unit = "MOhm";
            val = insertComma( val, 2 );
            d_val /= 100.;
            break;
          }
          special = "OH";
          break;
        case 0x05:
          switch (re->string()[6])
          {
          case 0x00:
            unit = "Ohm";
            val = insertComma( val, 3 );
            d_val /= 10.;
            break;
          }
          special = "OH";
          break;
        case 0x06:
          unit = "V";
          val = insertComma( val, 1 );
          d_val /= 1000.;
          special = "DI";
          break;
        case 0x08:
          unit = "A";
          val = insertComma( val, 2 );
          d_val /= 100.;
          special = "DC";
          break;
        case 0x09:
          unit = "A";
          val = insertComma( val, 2 );
          d_val /= 100.;
          special = "AC";
          break;
        case 0x0A:
          showBar = false;
          switch (re->string()[6])
          {
          case 0x00:
            unit = "kHz";
            val = insertComma( val, 1 );
            //d_val /= 1000.;
            break;
          case 0x01:
            unit = "kHz";
            val = insertComma( val, 2 );
            d_val *= 10.;
            break;
          case 0x05:
            unit = "Hz";
            val = insertComma( val, 2 );
            d_val /= 100.;
            break;
          case 0x06:
            unit = "Hz";
            val = insertComma( val, 3 );
            d_val /= 10.;
            break;
          }
          special = "HZ";
          break;
        case 0x0C:
          switch (re->string()[6])
          {
          case 0x00:
            unit = "nF";
            val = insertComma( val, 1 );
            d_val /= 1e12;
            break;
          case 0x01:
            unit = "nF";
            val = insertComma( val, 2 );
            d_val /= 1e11;
            break;
          case 0x02:
            unit = "nF";
            val = insertComma( val, 3 );
            d_val /= 1e10;
            break;
          case 0x03:
            unit = "uF";
            val = insertComma( val, 1 );
            d_val /= 1e9;
            break;
          case 0x04:
            unit = "uF";
            val = insertComma( val, 2 );
            d_val /= 1e8;
            break;
          }
          special = "CA";
          break;
        }
          
        emit value( d_val, val, unit, special, showBar, re->id() );
        m_error = tr( "Connected" ) + " (" + m_name + " @ " + m_device + ")";
      }
    }
    else
    {
      if (ReaderThread::Error == m_readerThread->status())
      {
        m_error = tr( "Read error on device" );
        m_error += " ";
        m_error += m_device;
        m_error += ". ";
        m_error += tr( "DMM connected and switched on?" );
      }
      else if (ReaderThread::Timeout == m_readerThread->status())
      {
        m_error = tr( "Timeout on device" );
        m_error += " ";
        m_error += m_device;
        m_error += ". ";
        m_error += tr( "DMM connected and switched on?" );
      }
      else if (ReaderThread::NotConnected == m_readerThread->status())
      {
        m_error = tr( "Not connected" );
      }
    }
    if (m_oldStatus != m_readerThread->status())
    {
      emit error( m_error );
    }
    m_oldStatus = m_readerThread->status();
  }
}

QString
DMM::insertComma( const QString & val, int pos )
{
  return val.left(2+pos) + "." + val.right(4-pos);
}

void
DMM::setName( const QString & name )
{
  m_name = name;
}

void
DMM::setNumValues( int numValues )
{
  m_readerThread->setNumValues( numValues );
}
