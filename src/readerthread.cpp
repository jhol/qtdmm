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
#include <iostream.h>

ReaderThread::ReaderThread( QObject *receiver ) :
  QThread(),
  m_receiver( receiver ),
  m_readValue( false ),
  m_format( ReadEvent::Metex14 ),
  m_ignoreLines( 0 )
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
ReaderThread::setIgnoreLines( int lines )
{
  m_ignoreLines = lines;
}

void
ReaderThread::run()
{
  while (1)
  {
    if (m_readValue) 
    {
      readDMM();
      m_readValue = false;
      
      QThread::postEvent( m_receiver, new ReadEvent( m_buffer, m_format ) );
    }
    msleep( 10 );
  }
}

void
ReaderThread::startRead()
{
  m_readValue = true;
}

void
ReaderThread::readDMM()
{
  memset( m_buffer, ' ', 14 );
  
  char byte;
  int  i = -1;
  int  retval;
  bool flag = false;
  
  if (m_format == ReadEvent::Metex14)
  {
    ::write( m_handle, "d\n", 2 );
  
    do 
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
        m_buffer[(++i)%14] = byte;
      }
    } 
    while ('\r' != byte);

    // ignore additional lines
    // <Michael Petruzelka>                          
    for (int i=0; i<m_ignoreLines; i++)                                     
    {                                                                 
      do                                                              
      {                                                               
        retval = ::read( m_handle, &byte, 1);      
                
        // Do some errorchecking (mt)           
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
      }                                                               
      while ('\r' != byte);                                           
    }        
  }
  else if (m_format == ReadEvent::PeakTech10)
  {
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
	        for(i=0; i<11; i++){
	          retval = ::read( m_handle, &byte, 1);
	          m_buffer[i] = byte;
	        }
        }
      }
    } 
  }
   
  m_status = ReaderThread::Ok;
}
