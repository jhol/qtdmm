//======================================================================
// File:		dmmbar.cpp
// Author:	Matthias Toussaint
// Created:	Tue Apr 10 17:45:35 CEST 2001
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

#include <dmmbar.h>

DMMBar::DMMBar( QWidget *parent, const char *name ) :
  QWidget( parent, name ),
  m_value( 0.0 )
{
}

DMMBar::~DMMBar()
{
}

void
DMMBar::setValue( double value )
{
  while (value > 4)
  {
    value /= 10.;
  }
  
  m_value = value;
  
  update();
}

void
DMMBar::paintEvent( QPaintEvent * )
{
  
}
