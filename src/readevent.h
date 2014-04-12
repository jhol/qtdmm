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

#include <qevent.h>

class ReadEvent : public QCustomEvent
{
public:
  enum DataFormat
  {
    Metex14 = 0,
    PeakTech10,
    Voltcraft14Continuous,
    Voltcraft15Continuous,
    M9803RContinuous,
    VC820Continuous,
    IsoTech,
    VC940Continuous,
    QM1537Continuous,
    RS22812Continuous
  };
    
  ReadEvent( char *str, int len, int id, DataFormat df );
  ~ReadEvent();
  
  const char *string() const { return m_str; }
  DataFormat format() const { return m_format; }
  int id() const { return m_id; }
  int length() const { return m_length; }
  
private:
  char       m_str[23];
  int        m_length;
  DataFormat m_format;
  int        m_id;
  
};  
#endif // READEVENT_HH
