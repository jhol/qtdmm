//======================================================================
// File:		dmm.h
// Author:	Matthias Toussaint
// Created:	Tue Apr 10 15:10:49 CEST 2001
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

#ifndef DMM_HH
#define DMM_HH

#include <qobject.h>
#include <readerthread.h>
#include <readevent.h>
#include <fcntl.h>
#include <sys/termios.h>
#include <sys/ioctl.h>

class DMM : public QObject
{
  Q_OBJECT
      
public:
  DMM( QObject *parent=0, const char *name=0 );
  virtual ~DMM();
  
  void setSpeed( int );
  void setDevice( const QString & );
  bool open();
  void close();
  QString errorString() const { return m_error; }
  bool isOpen() const { return m_handle >= 0; }
  void setFormat( ReadEvent::DataFormat );
  void setName( const QString & );
  void setPortSettings( int bits, int stopBits, int parity );
  void setNumValues( int );
  void setConsoleLogging( bool on ) { m_consoleLogging = on; }
  
signals:
  void value( double dval,
              const QString & val, 
              const QString & unit, 
              const QString & special,
              bool showBar, 
              int id );
  void error( const QString & );
  
protected:
  int                       m_handle;
  int                       m_speed;
  int                       m_parity;
  QString                   m_device;
  QString                   m_error;
  ReaderThread             *m_readerThread;
  tcflag_t                  m_c_cflag;
  ReaderThread::ReadStatus  m_oldStatus;
  QString                   m_name;
  struct termios            m_oldSettings;
  bool                      m_consoleLogging;
  
  void timerEvent( QTimerEvent * );
  void customEvent( QCustomEvent * );
  QString insertComma( const QString &, int );
  QString insertCommaIT( const QString &, int );
  
  void readASCII( ReadEvent * );
  void readVC820Continuous( ReadEvent * );
  void readM9803RContinuous( ReadEvent * );
  void readIsoTechContinuous( ReadEvent * );
  void readVC940Continuous( ReadEvent * );
  void readQM1537Continuous( ReadEvent * );
  void readRS22812Continuous( ReadEvent * );
  char *vc820Digit( int );
  char *RS22812Digit( int );
  
};

#endif // DMM_HH
