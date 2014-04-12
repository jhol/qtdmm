//======================================================================
// File:		colorbutton.cpp
// Author:	Matthias Toussaint
// Created:	Sam Jan 27 23:30:28 CET 2001
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
// (c) 2000 Matthias Toussaint
//======================================================================

#include <colorbutton.h>
#include <qcolordialog.h>
#include <qpainter.h>

ColorButton::ColorButton( QWidget *parent, const char *name ) :
  QPushButton( parent, name )
{
  setAutoDefault( false );
  
  connect( this, SIGNAL( clicked() ), this, SLOT( clickedSLOT() ));
}

ColorButton::~ColorButton()
{
}

QColor
ColorButton::color() const
{
  return backgroundColor();
}

void
ColorButton::setColor( const QColor & c )
{
  setBackgroundColor( c );
}

void
ColorButton::clickedSLOT()
{
  QColor c = QColorDialog::getColor( color(), this );
  
  if (c.isValid())
  {
    setColor( c );
  
    emit valueChanged();
    emit valueChanged( c );
  }
}

void
ColorButton::drawButtonLabel( QPainter *p )
{
  p->setBrush( color() );
  p->drawRoundRect( 6, 6, width()-12, height()-12, 30, 30 );
}
