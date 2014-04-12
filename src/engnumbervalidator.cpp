//======================================================================
// File:		engnumbervalidator.cpp
// Author:	Matthias Toussaint
// Created:	Fri Oct 11 20:32:01 CEST 2002
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

#include <math.h>
#include <engnumbervalidator.h>

EngNumberValidator::EngNumberValidator( QObject *parent, 
                                        const char *name ) :
  QValidator( parent, name )
{
}
  
EngNumberValidator::~EngNumberValidator()
{
}

// TODO: RegExp is still a simple hack
//
QValidator::State
EngNumberValidator::validate( QString & input, int & pos ) const
{
  static QRegExp doubleRe( "-?\\d+\\.?\\d*"  );
  static QRegExp fullRe( "-?\\d+\\.?\\d*[munpkMGT]?"  );
  
  input = input.stripWhiteSpace();
  pos = QMIN( (int)input.length(), pos );
  
  if (fullRe.match( input ) == 0) return Acceptable;
  if (doubleRe.match( input ) == 0) return Intermediate;

  return Invalid;  
}

double
EngNumberValidator::value( const QString & string )
{
  double factor = 1.;
  
  switch (string[string.length()-1])
  {
  case 'm':
    factor = 1e-3;
    break;
  case 'u':
    factor = 1e-6;
    break;
  case 'n':
    factor = 1e-9;
    break;
  case 'p':
    factor = 1e-12;
    break;
  case 'k':
    factor = 1e3;
    break;
  case 'M':
    factor = 1e6;
    break;
  case 'G':
    factor = 1e9;
    break;
  case 'T':
    factor = 1e12;
    break;
  }
  
  return string.toDouble() * factor;
}

QString
EngNumberValidator::engValue( double value )
{
  QString suffix = "";
  
  if (fabs(value) < 1.)
  {
    value *= 1000;
    suffix = "m";
  }
  if (fabs(value) < 1.)
  {
    value *= 1000;
    suffix = "µ";
  }
  if (fabs(value) < 1.)
  {
    value *= 1000;
    suffix = "n";
  }
  if (fabs(value) < 1.)
  {
    value *= 1000;
    suffix = "p";
  }
  if (fabs(value) >= 1000.)
  {
    value /= 1000;
    suffix = "k";
  }
  if (fabs(value) >= 1000.)
  {
    value /= 1000;
    suffix = "M";
  }
  if (fabs(value) >= 1000.)
  {
    value /= 1000;
    suffix = "G";
  }
  if (fabs(value) >= 1000.)
  {
    value /= 1000;
    suffix = "T";
  }
  
  QString str;
  str.setNum( ((int)qRound( value * 10. )) / 10. );
  str += suffix;
  
  return str;
}
