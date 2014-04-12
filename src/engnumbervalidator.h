//======================================================================
// File:		engnumbervalidator.h
// Author:	Matthias Toussaint
// Created:	Fri Oct 11 20:29:37 CEST 2002
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
// (c) 2000-2002 Matthias Toussaint
//======================================================================

#ifndef ENGNUMBERVALIDATOR_HH
#define ENGNUMBERVALIDATOR_HH

#include <qvalidator.h>

class EngNumberValidator : public QValidator
{
public:
  EngNumberValidator( QWidget *parent=0, const char *name=0 );
  virtual ~EngNumberValidator();
  
  QValidator::State validate( QString &, int & ) const;
  
  static double value( const QString & );
  
};
  
#endif // ENGNUMBERVALIDATOR_HH
