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
  ReadEvent( QString str ) : 
    QCustomEvent( QEvent::User ),
    m_str( str ) {}
  QString string() const { return m_str; }
  
private:
  QString m_str;

};  
#endif // READEVENT_HH
