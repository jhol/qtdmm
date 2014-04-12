//======================================================================
// File:		colorbutton.h
// Author:	Matthias Toussaint
// Created:	Sam Jan 27 23:28:24 CET 2001
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

#ifndef COLORBUTTON_HH
#define COLORBUTTON_HH

#include <qpushbutton.h>
#include <qcolor.h>

class QPainter;

class ColorButton : public QPushButton
{
  Q_OBJECT
public:
  ColorButton( QWidget *parent=0, const char *name=0 );
  virtual ~ColorButton();

  QColor color() const;
  void setColor( const QColor & );
  
signals:
  void valueChanged();
  void valueChanged( const QColor & );
    
protected slots:
  void clickedSLOT();

protected:
  QColor m_color;
//  void drawButtonLabel( QPainter * );

};

#endif // COLORBUTTON_HH
