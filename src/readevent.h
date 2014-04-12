//======================================================================
// File:		readevent.h
// Author:	Matthias Toussaint
// Created:	Sat Apr 14 13:01:28 CEST 2001
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

#ifndef READEVENT_HH
#define READEVENT_HH

class ReadEvent : public QCustomEvent
{
public:
  enum DataFormat
  {
    Metex14,
    PeakTech10
  };
    
  ReadEvent( QString str, DataFormat df ) : 
    QCustomEvent( QEvent::User ),
    m_str( str ),
    m_format (df ) {}
  QString string() const { return m_str; }
  DataFormat format() const { return m_format; }
  
private:
  QString    m_str;
  DataFormat m_format;
  
};  
#endif // READEVENT_HH
