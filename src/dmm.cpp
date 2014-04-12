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
#include <iostream.h>

DMM::DMM( QObject *parent, const char *name ) :
  QObject( parent, name ),
  m_handle( -1 ),
  m_speed( 600 ),
  m_device( "/dev/ttyS1" ),
  m_oldStatus( ReaderThread::NotConnected )
{
  m_readerThread = new ReaderThread( this );
  m_readerThread->start();
  
  m_c_cflag = CS7 | PARODD | CSTOPB | CREAD | CLOCAL;
}

DMM::~DMM()
{
}

void
DMM::setPortSettings( int bits, int stopBits )
{
  m_c_cflag = PARODD | CREAD | CLOCAL;
  
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
DMM::setIgnoreLines( int lines )
{
  m_readerThread->setIgnoreLines( lines );
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
  
  m_handle = ::open( m_device.latin1(), O_RDWR | O_NOCTTY );
  
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
  
  attr.c_oflag = 0;
  attr.c_lflag = 0;
  attr.c_iflag = IGNBRK;
  attr.c_cflag = m_c_cflag;
  //attr.c_iflag = IGNBRK | IGNPAR;
  //attr.c_cflag = CS7 | CSTOPB | CREAD | CLOCAL;
  attr.c_cc[VTIME]= 20;
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
  if (-1 != m_handle)
  {
    ::close( m_handle );
  }
  
  killTimers();
  
  m_error = tr( "Not connected" );
  emit error( m_error );
  
  m_handle = -1;
  m_readerThread->setHandle( m_handle );
  
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

bool
DMM::event( QEvent *ev )
{
  if (QObject::event(ev)) return true;
  
  if (QEvent::User == ev->type())
  {
    QString val;
    QString special;
    QString unit;
  
    if (ReaderThread::Ok == m_readerThread->status())
    {
      ReadEvent *re = (ReadEvent *)ev;
      QString tmp = re->string();

      if (re->format() == ReadEvent::Metex14)
      {
        val     = tmp.mid( 3, 6 ); //.stripWhiteSpace();
        unit    = tmp.mid( 9, 4 ).stripWhiteSpace();
        special = tmp.left( 3 ).stripWhiteSpace();
      }
      else if (re->format() == ReadEvent::PeakTech10)
      {
        val     = tmp.mid( 1, 6 ); //.stripWhiteSpace();
        unit    = tmp.mid( 7, 4 ).stripWhiteSpace();
      }
      
      double d_val = val.toDouble();

      if (unit.left(1) == "n")
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

      emit value( d_val, val, unit, special );

      m_error = tr( "Connected" );
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
    
    return false;
  }
  
  return true;
}
