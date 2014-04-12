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
  
signals:
  void value( double dval,
              const QString & val, 
              const QString & unit, 
              const QString & special );
  void error( const QString & );
  
protected:
  int           m_handle;
  int           m_speed;
  QString       m_device;
  QString       m_error;
  char          m_buffer[15];
  ReaderThread *m_readerThread;
    
  void timerEvent( QTimerEvent * );
  bool event( QEvent * );
  
};

#endif // DMM_HH
