//======================================================================
// File:		readerthread.h
// Author:	Matthias Toussaint
// Created:	Sat Apr 14 12:42:06 CEST 2001
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

#ifndef READERTHREAD_HH
#define READERTHREAD_HH

#include <qobject.h>
#include <qthread.h>
#include <readevent.h>

#define FIFO_LENGTH 100

class QSocketNotifier;

class ReaderThread : public QObject, public QThread
{
  Q_OBJECT
      
public:
  enum ReadStatus
  {
    Ok,
    Timeout,
    Error,
    NotConnected
  };
  
  ReaderThread( QObject *receiver );
  virtual ~ReaderThread();
  
  void run(); 
  void startRead();
  void setHandle( int handle );
  void setFormat( ReadEvent::DataFormat );
  
  ReadStatus status() const { return m_status; }
  void setNumValues( int num ) { m_numValues = num; }
  
protected:
  QObject              *m_receiver;
  int                   m_handle;
  ReadStatus            m_status;
  bool                  m_readValue;
  char                  m_fifo[FIFO_LENGTH];
  char                  m_buffer[FIFO_LENGTH];
  ReadEvent::DataFormat m_format;
  QSocketNotifier      *m_notifier;
  int                   m_length;
  bool                  m_sendRequest;
  int                   m_id;
  int                   m_numValues;
  
  void readDMM();
  void readMetex14();
  void readVoltcraft14Continuous();
  void readVoltcraft15Continuous();
  void readM9803RContinuous();
  void readPeakTech10();
  
  int formatLength() const;
  bool checkFormat();
  
protected slots:
  void socketNotifierSLOT( int );

};

#endif // READERTHREAD_HH
