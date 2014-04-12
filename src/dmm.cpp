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
// (c) 2001-2007 Matthias Toussaint
//======================================================================

#include <dmm.h>
#include <unistd.h>
#include <errno.h>
#include <qapplication.h>

#include <stdio.h>

#include <iostream>
#include <qdatetime.h>
#include <math.h>

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
  
  // According to Thomas Hoffman flags should be like this
  //
  if (0 == m_parity)          // Ignore parity errors
  {
    attr.c_iflag = IGNBRK | IGNPAR ;
  }
  else
  {
    attr.c_iflag = IGNBRK | INPCK | ISTRIP;
  }
  /*
  if (0 == m_parity)          // Ignore parity errors
  {
    attr.c_iflag = IGNBRK | IGNPAR | INPCK;
  }
  else
  {
    attr.c_iflag = IGNBRK | IGNPAR;
  }
  */
  //attr.c_cflag = CS7 | CSTOPB | CREAD | CLOCAL;
  attr.c_cc[VTIME]= 0;
  attr.c_cc[VMIN]= 1;
  
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
  else if (9600 == m_speed)
  {
    cfsetospeed( &attr, B9600 ); 
    cfsetispeed( &attr, B9600 );
  }
  else if (19200 == m_speed)
  {
    cfsetospeed( &attr, B19200 ); 
    cfsetispeed( &attr, B19200 );
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
  
  tcsetattr( m_handle, TCSAFLUSH, &attr );
  
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
    if (ReaderThread::Ok == m_readerThread->status())
    {
      ReadEvent *re = (ReadEvent *)ev;
      
      if (m_consoleLogging)
      {
        for (int i=0; i<re->length(); ++i)
        {
          fprintf( stdout, "%02X ", re->string()[i] & 0x0ff );
        }
        fprintf( stdout, "\n" );
      }

      switch (re->format())
      {
      case ReadEvent::Metex14:
      case ReadEvent::PeakTech10:
      case ReadEvent::Voltcraft14Continuous:
      case ReadEvent::Voltcraft15Continuous:
        readASCII( re );
        break;
      case ReadEvent::M9803RContinuous:
        readM9803RContinuous( re );
        break;
      case ReadEvent::VC820Continuous:
        readVC820Continuous( re );
        break;
      case ReadEvent::IsoTech:
        readIsoTechContinuous( re );
        break;
      case ReadEvent::VC940Continuous:
        readVC940Continuous( re );
        break;
      case ReadEvent::QM1537Continuous:
        readQM1537Continuous( re );
        break;
      case ReadEvent::RS22812Continuous:
        readRS22812Continuous( re );
        break;
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

QString 
DMM::insertCommaIT( const QString & val, int pos )
{
  return val.left(pos) + "." + val.mid(pos);
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

void DMM::readVC940Continuous( ReadEvent *re )
{
  QString val;
  QString special;
  QString unit;
  
  // Just guessing
  for (int i=0; i<4; ++i)
  {
    val += re->string()[i];
  }
  if (re->string()[4]&0x0f != 0x0a)
  {
    val += re->string()[4];
  }
  
  double scale = 1.0;
  
  int function = re->string()[6] & 0x0f;
  int range    = re->string()[5] & 0x0f;
  
  switch (function)
  {
    case 0:
      insertCommaIT( val, 3 );
      special = "AC";
      unit = "mV";
      scale = 1e-3;
      break;
    case 1:
      insertCommaIT( val, range );
      special = "DC";
      unit = "V";
      break;
    case 2:
      insertCommaIT( val, range );
      special = "AC";
      unit = "V";
      break;
    case 3:
      insertCommaIT( val, 3 );
      special = "DC";
      unit = "mV";
      scale = 1e-3;
      break;
    case 4:
      unit = "Ohm";
      switch (range)
      {
        case 1:
          insertCommaIT( val, 3 );
          break;
        case 2:
          insertCommaIT( val, 4 );
          break;
        case 3:
          break;
        case 4:
          insertCommaIT( val, 3 );
          unit = "kOhm";
          scale = 1e3;
          break;
        case 5:
          insertCommaIT( val, 1 );
          unit = "MOhm";
          scale = 1e6;
          break;
        case 6:
          insertCommaIT( val, 2 );
          unit = "MOhm";
          scale = 1e6;
          break;
      }
      special = "OH";
      break;
    case 5:
      unit = "F";
      switch (range)
      {
        case 1:
          insertCommaIT( val, 2 );
          unit = "nF";
          scale = 1e-9;
          break;
        case 2:
          insertCommaIT( val, 3 );
          unit = "nF";
          scale = 1e-9;
          break;
        case 3:
          insertCommaIT( val, 4 );
          unit = "nF";
          scale = 1e-9;
          break;
        case 4:
          insertCommaIT( val, 2 );
          unit = "uF";
          scale = 1e-6;
          break;
        case 5:
          insertCommaIT( val, 3 );
          unit = "uF";
          scale = 1e-6;
          break;
        case 6:
          insertCommaIT( val, 4 );
          unit = "uF";
          scale = 1e-6;
          break;
        case 7:
          insertCommaIT( val, 2 );
          unit = "mF";
          scale = 1e-3;
          break;
      }
      special = "CA";
      break;
    case 6:
      special = "TE";
      unit = "C";
      break;
    case 7:
      special = "DC";
      switch (range)
      {
        case 0:
          insertCommaIT( val, 3 );
          break;
        case 1:
          insertCommaIT( val, 4 );
          break;
      }
      unit = "uA";
      scale = 1e-6;
      break;
    case 8:
      special = "DC";
      switch (range)
      {
        case 0:
          insertCommaIT( val, 2 );
          break;
        case 1:
          insertCommaIT( val, 3 );
          break;
      }
      unit = "mA";
      scale = 1e-3;
      break;
    case 9:
      special = "DC";
      unit = "A";
      break;
    case 10:   // what the heck is this?
      special = "FR";
      unit = "Hz";
      break;
    case 11:
      special = "DI";
      unit = "";
      break;
  }
  
  double d_val = val.toDouble() * scale;
  
  emit value( d_val, val, unit, special, true, re->id() );

  m_error = tr( "Connected" ) + " (" + m_name + " @ " + m_device + ")";
}

void DMM::readRS22812Continuous( ReadEvent *re )
{
  QString val;
  QString special;
  QString unit;
  
  const char *in = re->string();
  
  if (m_consoleLogging)
  {
    for (int i=0; i<re->length(); ++i)
    {
      fprintf( stdout, "%02X ", in[i] & 0x0ff );
    }
    fprintf( stdout, "\n" );
  }
  
  // check for overflow else find sign and fill in digits
  //
  if (((in[3] & 0x0f7) == 0x000) && 
      ((in[4] & 0x0f7) == 0x027) && 
      ((in[5] & 0x0f7) == 0x0d7))
  {
    val = "   0L ";
  }
  else
  {
    if(in[7] & 0x08)
    {
      val = " -";   // negative;
    }
    else
    {
      val = "  ";
    }
    
    // create string;
    //
    for (int i=0; i<4; ++i)
    {
      val += RS22812Digit( in[6-i] );
    }
  }
  
  // find comma (really decimal point) [germans use commas instead of decimal points] position
  //
  if (in[3] & 0x08)
  {
    val = insertComma( val, 3 );
  }
  else if (in[4] & 0x08)
  {
    val = insertComma( val, 2 );
  }
  else if(in[5] & 0x08)
  {
    val = insertComma( val, 1 );
  }
  
  double d_val = val.toDouble();
  
  // try to find some special modes
  //
  if (in[7] & 0x40) 
  {
    special = "DI";
  }
  if (in[7] & 0x04)
  {
    special = "AC";
  }
  else
  {
    special = "DC";
  }
   
  // try to find mode
  //
  if (in[1] & 0x08)
  {
    unit    = "F";
    special = "CA";
  }
  else if (in[1] & 0x40)
  {
    unit    = "Ohm";
    special = "OH";
  }
  else if (in[1] & 0x04)
  {
    unit = "A";
  }
  else if (in[1] & 0x80)
  {
    unit    = "Hz";
    special = "HZ";
  }
  else if (in[1] & 0x02)
  {
    unit = "V";
  }
  else if (in[2] & 0x80)
  {
    unit    = "%";
    special = "PC";
  }
  else 
  {
    std::cerr << "Unknown unit!" << std::endl;
  }
  
  // try to find prefix
  //
  if (in[2] & 0x40)
  {
    d_val /= 1e9;
    unit.prepend( "n" );
  }
  else if (in[2] & 0x80)
  {
    d_val /= 1e6;
    unit.prepend( "u" );
  }
  else if (in[1] & 0x01)
  {
    d_val /= 1e3;
    unit.prepend( "m" );
  }
  else if (in[1] & 0x20)
  {
    d_val *= 1e3;
    unit.prepend( "k" );
  }
  else if (in[1] & 0x10)
  {
    d_val *= 1e6;
    unit.prepend( "M" );
  }
  
  emit value( d_val, val, unit, special, true, re->id() );
  
  m_error = tr( "Connected" ) + " (" + m_name + " @ " + m_device + ")";
}

char *DMM::RS22812Digit( int byte )
{
  int     digit[10] = { 0xd7, 0x50, 0xb5, 0xf1, 0x72, 0xe3, 0xe7, 0x51, 0xf7, 0xf3 };
  char *c_digit[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
     
  byte &= 0x0f7;
     
  for (int n=0; n<10; n++)
  {
    if (byte == digit[n]) return c_digit[n];
  }
    
  return 0;
}

void DMM::readASCII( ReadEvent *re )
{
  QString val;
  QString special;
  QString unit;
  
  QString tmp = re->string();
        
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

  //std::cerr << "d_val=" << d_val << " val=" << val.latin1() 
  //    << " unit=" << unit.latin1() << " special=" << special.latin1() << std::endl;
      
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

void DMM::readQM1537Continuous( ReadEvent *re )
{
  QString val;
  QString special;
  QString unit;
  const char *pStr = re->string();

  if (pStr[0]!=0x0A)
    return;

  if (pStr[1] == '-')
  {
    val = " -";
  }
  else
  {
    val = "  ";
  }
  
  if ((pStr[2] == ';') &&
      (pStr[3] == '0') &&
      (pStr[4] == ':') &&
      (pStr[5] == ';'))
  {
     val += "  0L";
  }
  else
  {
    val += pStr[2];
    val += pStr[3];
    val += pStr[4];
    val += pStr[5];
  }
         
  bool showBar = true;
  bool doACDC = false;
  bool doUnits = true;
  
  switch (pStr[7])
  {
    case 0x31:
      val = insertComma (val,1);
      break;
    case 0x32:
      val = insertComma (val,2);
      break;
    case 0x34:
      val = insertComma (val,3);
      break;
    // default case is no comma/decimal point at all.
  }

  double d_val = val.toDouble();

  /* OK, now let's figure out what we're looking at. */
  if (pStr[11] & 0x80)
  {
    /* Voltage, including diode test */
    unit = "V";
    if (pStr[10] & 0x04)
    {
      /* Diode test */
      special = "DI";
      unit = "V";
    }
    else
      doACDC = true;
  }
  else if (pStr[11] & 0x40)
  {
    /* Current */
    unit = "A";
    doACDC = true;
  }
  else if (pStr[11] & 0x20)
  {
    /* Resistance, including continuity test */
    unit = "Ohm";
    special = "OH";
  }
  else if (pStr[11] & 0x08)
  {
    /* Frequency */
    unit = "Hz";
    special = "HZ";
  }
  else if (pStr[11] & 0x04)
  {
    /* Capacitance */
    unit = "F";
    special = "CA";
  }
  else if (pStr[10] & 0x02)
  {
    /* Duty cycle */
    unit = "%";
    special = "PC";
    doUnits = false;
  }

  if (doACDC)
  {
    if (pStr[8] & 0x08)
      special = "AC";
    else
      special = "DC";
  }

  if (doUnits)
  {
    if (pStr[9] & 0x02)
    {
      d_val /= 1e9;
      unit.prepend ('n');
    }
    else if (pStr[10] & 0x80)
    {
      d_val /= 1e6;
      unit.prepend ('u');
    }
    else if (pStr[10] & 0x40)
    {
      d_val /= 1e3;
      unit.prepend ('m');
    }
    else if (pStr[10] & 0x20)
    {
      d_val *= 1e3;
      unit.prepend ('k');
    }
    else if (pStr[10] & 0x10)
    {
      d_val *= 1e6;
      unit.prepend ('M');
    }
  }
   
  emit value( d_val, val, unit, special, showBar, re->id() );
  m_error = tr( "Connected" ) + " (" + m_name + " @ " + m_device + ")";
}

void DMM::readM9803RContinuous( ReadEvent *re )
{
  QString val;
  QString special;
  QString unit;
  
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

void DMM::readIsoTechContinuous(ReadEvent *re) 
{
  QString tmp = re->string();
  QString val = tmp.mid(11,4);
  QString unit, special;
  const char* tmpstring = re->string();
  
  double d_val = val.toDouble();
  
  // Type of measurement
  int typecode = tmpstring[15] & 0xf;
  int rangecode = re->string()[10] & 0xf;
  int acdccode = re->string()[18] & 0xc;
  //  printf("ISO: value %s, type: %d, range: %d, ac/dc: %c\n", 
  //      re->string(), typecode, rangecode, acdccode == 0x8 ? 'D': 'A' );
  
  double multiplier = 1.0;
  
  switch(typecode) {
    case 0xb:
      // voltage
      if (rangecode < 4)
      rangecode += 5;
      rangecode -= 4;
      multiplier = pow(10, rangecode - 4);
      if (acdccode == 0x8) {
         special = "DC";
      } else {
         special = "AC";
      }
      switch (rangecode) {
        case 0:
          val = insertCommaIT(val, 3);
          unit = "mV";
          break;
        case 1:
          val = insertCommaIT(val, 1);
          unit = "V";
          break;
        case 2:
          val = insertCommaIT(val, 2);
          unit = "V";
          break;
        case 3:
          val = insertCommaIT(val, 3);
          unit = "V";
          break;
        case 4:
          unit = "V";
          break;
        default:
          // error
              ;
      }
      break;
    case 0x3:
      // resistance
      multiplier = pow(10,rangecode - 1);
      special = "OH";
      switch (rangecode) {
        case 0:
          val = insertCommaIT(val, 3);
          unit = "Ohm";
          break;
        case 1:
          val = insertCommaIT(val, 1);
          unit = "kOhm";
          break;
        case 2:
          val = insertCommaIT(val, 2);
          unit = "kOhm";
          break;
        case 3:
          val = insertCommaIT(val, 3);
          unit = "kOhm";
          break;
        case 4:
          val = insertCommaIT(val, 1);
          unit = "MOhm";
          break;
        case 5:
          val = insertCommaIT(val, 2);
          unit = "MOhm";
          break;
        default:
          // error
          ;
      }
      break;
   case 0x1:
      // diode
      multiplier = 0.001;
      val = insertCommaIT(val,1);
      unit = "V";
      break;
   case 0xd:
      // current micro
      multiplier = pow(10,rangecode - 7);
      special = "DC";
      if (rangecode == 0) {
        val = insertCommaIT(val,3);
        unit = "uA";
      } else {
        val = insertCommaIT(val,1);
        unit = "mA";
      }
      break;
   case 0x0:
      // current
      multiplier = pow(10,rangecode - 3);
      unit = "A";
      val = insertCommaIT(val,rangecode + 1);
      if (acdccode == 0x8) {
        special = "DC";
      } else {
        special = "AC";
      }
      break;
   case 0x2: 
      // frequency
      special = "HZ";
      multiplier = pow(10,rangecode);
      switch (rangecode) {
        case 0x0:
          val = insertCommaIT(val, 1);
          unit = "kHz";
          break;
        case 0x1:
          val = insertCommaIT(val, 2);
          unit = "kHz";
          break;
        case 0x2:
          val = insertCommaIT(val, 3);
          unit = "kHz";
          break;
        case 0x3:
          val = insertCommaIT(val, 1);
          unit = "MHz";
          break;
        case 0x4:
          val = insertCommaIT(val, 2);
          unit = "MHz";
          break;
        default:
          // error
          ;

      }
      break;
   case 0x6:
      // capacity
      special = "CA";
      multiplier = pow(10, rangecode - 12);
      switch (rangecode) {
        case 0x0:
          val = insertCommaIT(val, 1);
          unit = "nF";
          break;
        case 0x1:
          val = insertCommaIT(val, 2);
          unit = "nF";
          break;
        case 0x2:
          val = insertCommaIT(val, 3);
          unit = "nF";
          break;
        case 0x3:
          val = insertCommaIT(val, 1);
          unit = "uF";
          break;
        case 0x4:
          val = insertCommaIT(val, 2);
          unit = "uF";
          break;
        case 0x5:
          val = insertCommaIT(val, 3);
          unit = "uF";
          break;
        case 0x6:
          val = insertCommaIT(val, 1);
          unit = "mF";
          break;
        default:
          // error
          ;
      }
      break;
   default:
      // error - unknown type of measurement
      ;
   }
  d_val *= multiplier;

  if (re->string()[16] & 0x01) {
    val = "  0L";
  }
  if (re->string()[16] & 0x4) {
    d_val = - d_val;
    val = " -" + val;
  } else {
    val = "  " + val;
  }

 // printf ("DVAL: %f\n", d_val);

  emit value( d_val, val, unit, special, true, re->id() );
  m_error = tr( "Connected" ) + " (" + m_name + " @ " + m_device + ")";
}

void DMM::readVC820Continuous( ReadEvent *re )
{
  QString val;
  QString special;
  QString unit;
    
  const char *in = re->string();
  
  // check for overload else find sign and fill in digits
  //
  if (((in[3] & 0x07) == 0x07) && 
      ((in[4] & 0x0f) == 0x0d) && 
      ((in[5] & 0x07) == 0x06) &&
      ((in[6] & 0x0f) == 0x08))
  {
    val = "  0L";
  }
  else
  {
    if(in[1] & 0x08)
    {
      val = " -";   // negative;
    }
    else
    {
      val = "  ";
    }
    
    // create string;
    //
    for (int i=0; i<4; ++i)
    {
      val += vc820Digit( ((in[1+2*i] << 4 ) & 0xf0) | (in[2+2*i] & 0x0f) );
    }
  }
  
  // find comma position
  //
  if (in[3] & 0x08)
  {
    val = insertComma( val, 1 );
  }
  else if (in[5] & 0x08)
  {
    val = insertComma( val, 2 );
  }
  else if(in[7] & 0x08)
  {
    val = insertComma( val, 3 );
  }

  double d_val = val.toDouble();
  
  // try to find some special modes
  //
  if (in[9] & 0x01) 
  {
    special = "DI";
  }
  if (in[0] & 0x08)
  {
    special = "AC";
  }
  else
  {
    special = "DC";
  }

  // try to find mode
  //
  if (in[11] & 0x08)
  {
    unit    = "F";
    special = "CA";
  }
  else if (in[11] & 0x04)
  {
    unit    = "Ohm";
    special = "OH";
  }
  else if (in[12] & 0x08)
  {
    unit = "A";
  }
  else if (in[12] & 0x02)
  {
    unit    = "Hz";
    special = "HZ";
  }
  else if (in[12] & 0x04)
  {
    unit = "V";
  }
  else if (in[10] & 0x04)
  {
    unit    = "%";
    special = "PC";
  }
  else if (in[13] & 0x04)
  {
    unit    = "C";
    special = "TE";
  } 
  else if (in[13] & 0x02)
  {
    unit    = "F";
    special = "TE";
  }
  else 
  {
    std::cerr << "Unknown unit!" << std::endl;
  }

  // try to find prefix
  //
  if (in[9] & 0x04)
  {
    d_val /= 1e9;
    unit.prepend( "n" );
  }
  else if (in[9] & 0x08)
  {
    d_val /= 1e6;
    unit.prepend( "u" );
  }
  else if (in[10] & 0x08)
  {
    d_val /= 1e3;
    unit.prepend( "m" );
  }
  else if (in[9] & 0x02)
  {
    d_val *= 1e3;
    unit.prepend( "k" );
  }
  else if (in[10] & 0x02)
  {
    d_val *= 1e6;
    unit.prepend( "M" );
  }

  emit value( d_val, val, unit, special, true, re->id() );
  
  m_error = tr( "Connected" ) + " (" + m_name + " @ " + m_device + ")";
}

char *DMM::vc820Digit( int byte )
{
  int     digit[10] = { 0x7d, 0x05, 0x5b, 0x1f, 0x27, 0x3e, 0x7e, 0x15, 0x7f, 0x3f };
  char *c_digit[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
  
  byte &= 0x7f;
  
  for (int n=0; n<10; n++)
  {
    if (byte == digit[n]) return c_digit[n];
  }
  
  return 0;
}

