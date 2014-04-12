//======================================================================
// File:		dmmbar.h
// Author:	Matthias Toussaint
// Created:	Tue Apr 10 17:42:19 CEST 2001
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

#ifndef DMMBAR_HH
#define DMMBAR_HH

#include <qwidget.h>

class DMMBar : public QWidget
{
  Q_OBJECT
public:
  DMMBar( QWidget *parent=0, const char *name=0 );
  virtual ~DMMBar();
  
public slots:
  void setValue( double );

protected:
  double m_value;

  void paintEvent( QPaintEvent * );

};

#endif // DMMBAR_HH
