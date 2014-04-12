//======================================================================
// File:		readerthread.cpp
// Author:	Matthias Toussaint
// Created:	Sat Apr 14 12:44:00 CEST 2001
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

#include <readerthread.h>
#include <unistd.h>
#include <stdio.h>

#include <qapplication.h>
#include <qsocketnotifier.h>

#include <iostream>

ReaderThread::ReaderThread( QObject *receiver ) :
  QThread(),
  m_receiver( receiver ),
  m_readValue( false ),
  m_format( ReadEvent::Metex14 ),
  m_notifier( 0 ),
  m_length( 0 ),
  m_sendRequest( true ),
  m_id( 0 ),
  m_numValues( 1 )
{
  m_buffer[14] = '\0';
}

ReaderThread::~ReaderThread()
{
}

void 
ReaderThread::setFormat( ReadEvent::DataFormat format )
{
  m_format = format;
}

void 
ReaderThread::setHandle( int handle ) 
{ 
  delete m_notifier;
  m_notifier = 0;
  
  m_handle = handle; 
  m_readValue = false;
  
  if (-1 == m_handle) 
  {
    m_status = ReaderThread::NotConnected;
    m_readValue = false;
  }
  else
  {
    m_notifier = new QSocketNotifier( m_handle, QSocketNotifier::Read );
    
    connect( m_notifier, SIGNAL( activated(int) ),
             this, SLOT( socketNotifierSLOT(int) ));
  }
}

void
ReaderThread::run()
{
  while (1)
  {
    if (m_readValue) 
    {
     // std::cerr << "going to read" << std::endl;
      readDMM();
      m_readValue = false;
    }
    msleep( 10 );
  }
}

void
ReaderThread::startRead()
{
  //std::cerr << "start read" << std::endl;
  m_readValue = true;
  m_sendRequest = true;
}

void
ReaderThread::socketNotifierSLOT( int socket )
{
  //std::cerr << "socket call" << std::endl;
  
  if (m_handle != socket) return;

  if (-1 == m_handle) 
  {
    m_status = ReaderThread::NotConnected;
    return;
  }

  int  retval;
  char byte;
 
  m_status = ReaderThread::Ok;
  
  {
    retval = ::read( m_handle, &byte, 1);  

    if (-1 == retval)
    {
      m_status = ReaderThread::Error;
      return;
    }
    else if (0 == retval)
    {
      m_status = ReaderThread::Timeout;
      return;
    }
    else
    { 
      m_fifo[m_length] = byte;

      if (checkFormat())
      {
        m_length = (m_length-formatLength()+1+FIFO_LENGTH)%FIFO_LENGTH;

        for (int i=0; i<formatLength(); ++i)
        {
          m_buffer[i] = m_fifo[m_length];
          m_length = (m_length+1)%FIFO_LENGTH;
        }

        m_sendRequest = true;
        m_length = 0;

        QApplication::postEvent( m_receiver, 
            new ReadEvent( m_buffer, formatLength(), m_id, m_format ) );
        
        m_id = (m_id+1) % m_numValues;
      }
      else
      {
        m_length = (m_length+1) % FIFO_LENGTH;
      }
    }
  }
}

int 
ReaderThread::formatLength() const
{
  switch (m_format)
  {
  case ReadEvent::Metex14:
    return 14;
  case ReadEvent::Voltcraft14Continuous:
    return 14;
  case ReadEvent::Voltcraft15Continuous:
    return 15;
  case ReadEvent::M9803RContinuous:
    return 11;
  case ReadEvent::PeakTech10:
    return 12;
  }
  
  return 0;
}

void
ReaderThread::readDMM()
{
  m_id = 0;
  memset( m_buffer, 0, 20 );
    
  if (m_format == ReadEvent::Metex14)
  {
    readMetex14();
  }
  else if (m_format == ReadEvent::Voltcraft14Continuous)
  {
    readVoltcraft14Continuous();
  }
  else if (m_format == ReadEvent::Voltcraft15Continuous)
  {
    readVoltcraft15Continuous();
  }
  else if (m_format == ReadEvent::M9803RContinuous)
  {
    readM9803RContinuous();
  }
  else if (m_format == ReadEvent::PeakTech10)
  {
    readPeakTech10();
  }
}

bool
ReaderThread::checkFormat()
{
  if (m_format == ReadEvent::Metex14)
  {
    if (m_fifo[m_length] == 0x0d) return true;
  }
  else if (m_format == ReadEvent::Voltcraft14Continuous)
  {
    if (m_fifo[m_length] == 0x0d) return true;
  }
  else if (m_format == ReadEvent::Voltcraft15Continuous)
  {
    if (m_fifo[(m_length-1+FIFO_LENGTH)%FIFO_LENGTH] == 0x0d && 
        m_fifo[m_length] == 0x0a) return true; 
  }
  else if (m_format == ReadEvent::M9803RContinuous && m_length >= 10)
  {
    if (m_fifo[(m_length-1+FIFO_LENGTH)%FIFO_LENGTH] == 0x0d && 
        m_fifo[m_length] == 0x0a) return true; 
  }
  else if (m_format == ReadEvent::PeakTech10 && m_length >= 11)
  {
    if (m_fifo[(m_length-11+FIFO_LENGTH)%FIFO_LENGTH] == '#') return true; 
  }
  
  return false;
}

void
ReaderThread::readMetex14()
{
  if (m_sendRequest)
  {
    /* TODO: Errorhandling */
    /*size_t ret = */ ::write( m_handle, "D\n", 2 );
    //std::cerr << "WROTE: " << ret << std::endl;
    m_sendRequest = false;
  }
}  

void
ReaderThread::readVoltcraft14Continuous()
{
}


void
ReaderThread::readVoltcraft15Continuous()
{
}  

void
ReaderThread::readM9803RContinuous()
{
}

void
ReaderThread::readPeakTech10()
{
/*  char byte;
  int  i = -1;
  int  retval;
  bool flag = false;
  
  while(false == flag)
  {    
    if (-1 == m_handle) 
    {
      m_status = ReaderThread::NotConnected;
      return;
    }

    retval = ::read( m_handle, &byte, 1);

    if (-1 == retval)
    {
      m_status = ReaderThread::Error;

      return;
    }
    else if (0 == retval)
    {
      m_status = ReaderThread::Timeout;

      return;
    }
    else
    {
      // wait for #
      // (Dr. Ralf Wieland)
      if(byte=='#')
      {
	      flag=true;
	      for(i=0; i<11; i++)
        {
	        retval = ::read( m_handle, &byte, 1);
	        m_buffer[i] = byte;
	      }
      }
    }
  } */
}  
