//======================================================================
// File:		displaywid.h
// Author:	Matthias Toussaint
// Created:	Fri Nov 23 22:28:36 CET 2001
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

#ifndef DISPLAYWID_HH
#define DISPLAYWID_HH

#include <qwidget.h>

class QPixmap;
class QPainter;

class DisplayWid : public QWidget
{
  Q_OBJECT
public:
  DisplayWid( QWidget *parent=0, const char *name=0 );
  virtual ~DisplayWid();
  
  void setValue( const QString & );
  void setUnit( const QString & );
  void setMinValue( const QString & );
  void setMaxValue( const QString & );
  void setMinUnit( const QString & );
  void setMaxUnit( const QString & );
  void setMode( const QString & );
  
protected:
  QBitmap *m_bigDigit;
  QBitmap *m_bigDecimal;
  QBitmap *m_bigMinus;
  QBitmap *m_bigL;
  QBitmap *m_bigG;
  QBitmap *m_bigM;
  QBitmap *m_bigk;
  QBitmap *m_bigm;
  QBitmap *m_bigu;
  QBitmap *m_bign;
  QBitmap *m_bigp;
  QBitmap *m_bigHz;
  QBitmap *m_bigF;
  QBitmap *m_bigV;
  QBitmap *m_bigA;
  QBitmap *m_bigOhm;
  QBitmap *m_bigDeg;
  QBitmap *m_smallDigit;
  QPixmap *m_smallDecimal;
  QPixmap *m_smallMinus;
  QPixmap *m_smallL;
  QPixmap *m_smallG;
  QPixmap *m_smallM;
  QPixmap *m_smallk;
  QPixmap *m_smallm;
  QPixmap *m_smallu;
  QPixmap *m_smalln;
  QPixmap *m_smallp;
  QPixmap *m_smallHz;
  QPixmap *m_smallF;
  QPixmap *m_smallV;
  QPixmap *m_smallA;
  QPixmap *m_smallOhm;
  QPixmap *m_smallDeg;
  QBitmap *m_minStr;
  QBitmap *m_maxStr;
  QBitmap *m_diode;
  QBitmap *m_ac;
  QBitmap *m_dc;
  QString  m_value;
  QString  m_minValue;
  QString  m_maxValue;
  QString  m_unit;
  QString  m_minUnit;
  QString  m_maxUnit;
  QString  m_mode;
  
  void paintEvent( QPaintEvent *ev );
  void drawSmallNumber( QPainter *, const QString & str );
  void drawSmallUnit( QPainter *, const QString & str );
  void drawBigNumber( QPainter *, const QString & str );
  void drawBigUnit( QPainter *, const QString & str );
  
private:
  QBitmap *createBitmap( const char ** );

};

#endif // DISPLAYWID_HH
