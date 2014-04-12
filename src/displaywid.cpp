//======================================================================
// File:		displaywid.cpp
// Author:	Matthias Toussaint
// Created:	Fri Nov 23 22:34:30 CET 2001
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

#include <displaywid.h>
#include <qpixmap.h>
#include <qbitmap.h>
#include <qimage.h>
#include <qpainter.h>

// less than elegant use of single pixmaps for everything.
// But hey, it works!
//
#include <xpm/numbers.xpm>
#include <xpm/decimal.xpm>
#include <xpm/minus.xpm>
#include <xpm/l.xpm>
#include <xpm/G.xpm>
#include <xpm/M.xpm>
#include <xpm/k.xpm>
#include <xpm/m.xpm>
#include <xpm/u.xpm>
#include <xpm/n.xpm>
#include <xpm/p.xpm>
#include <xpm/Hz.xpm>
#include <xpm/F.xpm>
#include <xpm/V.xpm>
#include <xpm/A.xpm>
#include <xpm/Ohm.xpm>
#include <xpm/deg.xpm>

#include <xpm/numbers_small.xpm>
#include <xpm/decimal_small.xpm>
#include <xpm/minus_small.xpm>
#include <xpm/l_small.xpm>
#include <xpm/G_small.xpm>
#include <xpm/M_small.xpm>
#include <xpm/k_small.xpm>
#include <xpm/m_small.xpm>
#include <xpm/u_small.xpm>
#include <xpm/n_small.xpm>
#include <xpm/p_small.xpm>
#include <xpm/Hz_small.xpm>
#include <xpm/F_small.xpm>
#include <xpm/V_small.xpm>
#include <xpm/A_small.xpm>
#include <xpm/Ohm_small.xpm>
#include <xpm/deg_small.xpm>

#include <xpm/min_str.xpm>
#include <xpm/max_str.xpm>

#include <xpm/diode.xpm>
#include <xpm/ac.xpm>
#include <xpm/dc.xpm>

DisplayWid::DisplayWid( QWidget *parent, const char *name ) :
  QWidget( parent, name )
{
  // HACK: My GIMP doesn't save XBM !!!!
  //
  m_bigDigit = createBitmap((const char **)numbers_xpm);
  
  m_bigDecimal = createBitmap((const char **)decimal_xpm);
  m_bigMinus = createBitmap((const char **)minus_xpm);
  m_bigL = createBitmap((const char **)l_xpm);
  m_bigG = createBitmap((const char **)G_xpm);
  m_bigM = createBitmap((const char **)M_xpm);
  m_bigk = createBitmap((const char **)k_xpm);
  m_bigm = createBitmap((const char **)m_xpm);
  m_bigu = createBitmap((const char **)u_xpm);
  m_bign = createBitmap((const char **)n_xpm);
  m_bigp = createBitmap((const char **)p_xpm);
  m_bigHz = createBitmap((const char **)Hz_xpm);
  m_bigF = createBitmap((const char **)F_xpm);
  m_bigV = createBitmap((const char **)V_xpm);
  m_bigA = createBitmap((const char **)A_xpm);
  m_bigOhm = createBitmap((const char **)Ohm_xpm);
  m_bigDeg = createBitmap((const char **)deg_xpm);
  
  m_smallDigit = createBitmap((const char **)numbers_small_xpm);
  
  m_smallDecimal = createBitmap((const char **)decimal_small_xpm);
  m_smallMinus = createBitmap((const char **)minus_small_xpm);
  m_smallL = createBitmap((const char **)l_small_xpm);
  m_smallG = createBitmap((const char **)G_small_xpm);
  m_smallM = createBitmap((const char **)M_small_xpm);
  m_smallk = createBitmap((const char **)k_small_xpm);
  m_smallm = createBitmap((const char **)m_small_xpm);
  m_smallu = createBitmap((const char **)u_small_xpm);
  m_smalln = createBitmap((const char **)n_small_xpm);
  m_smallp = createBitmap((const char **)p_small_xpm);
  m_smallHz = createBitmap((const char **)Hz_small_xpm);
  m_smallF = createBitmap((const char **)F_small_xpm);
  m_smallV = createBitmap((const char **)V_small_xpm);
  m_smallA = createBitmap((const char **)A_small_xpm);
  m_smallOhm = createBitmap((const char **)Ohm_small_xpm);
  m_smallDeg = createBitmap((const char **)deg_small_xpm);
  
  m_minStr = createBitmap((const char **)min_str_xpm);
  m_maxStr = createBitmap((const char **)max_str_xpm);
  
  m_diode = createBitmap((const char **)diode_xpm);
  m_ac = createBitmap((const char **)ac_xpm);
  m_dc = createBitmap((const char **)dc_xpm);  
  
  setBackgroundMode( QWidget::NoBackground );
}

QBitmap *
DisplayWid::createBitmap( const char **data )
{
  QBitmap *bm = new QBitmap;
  *bm = QImage(data).convertDepth( 1, ThresholdDither ); 
  bm->setMask( *bm );
  
  return bm;  
}

DisplayWid::~DisplayWid()
{
  delete m_bigDigit;
  delete m_smallDigit;
  delete m_bigDecimal;
  delete m_smallDecimal;
}

void
DisplayWid::setValue( const QString & value )
{
  m_value = value;
}

void
DisplayWid::setMinValue( const QString & value )
{
  m_minValue = value;
}

void
DisplayWid::setMaxValue( const QString & value )
{
  m_maxValue = value;
}

void
DisplayWid::setUnit( const QString & value )
{
  m_unit = value;
}

void
DisplayWid::setMinUnit( const QString & value )
{
  m_minUnit = value;
}

void
DisplayWid::setMaxUnit( const QString & value )
{
  m_maxUnit = value;
}

void
DisplayWid::setMode( const QString & value )
{
  m_mode = value;
}

void
DisplayWid::paintEvent( QPaintEvent * )
{
  QPixmap pix( width(), height() );
  pix.fill( colorGroup().background() );
  QPainter p;
  
  if (!m_value.isEmpty())
  {
    p.begin(&pix);
    
    p.setPen( colorGroup().foreground() );

    p.translate( 3+12+12, 8 );
    p.drawPixmap( -22, 2, *m_minStr );
    drawSmallNumber( &p, m_minValue );
    p.translate( 5*16+2, 12 );
    drawSmallUnit( &p, m_minUnit );

    p.translate( -5*16-2, 1+32-12 );
    p.drawPixmap( -22, 2, *m_maxStr );
    drawSmallNumber( &p, m_maxValue );
    p.translate( 5*16+2, 12 );
    drawSmallUnit( &p, m_maxUnit );

    p.translate( 40, -38-12 );
    drawBigNumber( &p, m_value );
    p.translate( 5*43+2, 42 );
    drawBigUnit( &p, m_unit );

    if (m_mode == "DI")
    {
      p.drawPixmap( 0, -36, *m_diode );
    }
    else if (m_mode == "AC")
    {
      p.drawPixmap( 0, -36, *m_ac );
    }
    else if (m_mode == "DC")
    {
      p.drawPixmap( 0, -36, *m_dc );
    }
    
    p.end();
  }
  
  p.begin(this);
  p.drawPixmap(0,0,pix);
  p.end();
}

void
DisplayWid::drawSmallNumber( QPainter *p, const QString & num )
{
  int x = 0;  
  int start = 0;
  
  if (num[0] == ' ' || num[0] == '-')
  {
    if (num[0] == '-')
    {
      p->drawPixmap( 0, 9, *m_smallMinus );
    }
    x += 12;
    start = 1;
  }
     
  for (unsigned i=1; i<num.length(); i++)
  {
    if (num[i] == '.')
    {
      p->drawPixmap( x-5, 0, *m_smallDecimal );
    }
    else if (num[i] == 'O')
    {
      p->drawPixmap( x, 0, *m_smallDigit, 0, 0, 12, 21 );
      x += 18;
    }
    else if (num[i] == 'L')
    {
      p->drawPixmap( x, 0, *m_smallL );
      x += 18;
    }
    else
    {
      int digit = num[i].latin1()-'0';
      
      if (digit >= 0 && digit <= 9)
      {
        p->drawPixmap( x, 0, *m_smallDigit, 12*digit, 0, 12, 21 );
      }
      x += 18;
    }
  }
}

void
DisplayWid::drawBigUnit( QPainter *p, const QString & str )
{
  int index = 0;
  int x = 0;
  
  if (str[0] == 'G')
  {
    p->drawPixmap( x, 0, *m_bigG );
    x += m_bigG->width()+2;
    index++;
  }
  else if (str[0] == 'M')
  {
    p->drawPixmap( x, 0, *m_bigM );
    x += m_bigM->width()+2;
    index++;
  }
  else if (str[0] == 'k')
  {
    p->drawPixmap( x, 0, *m_bigk );
    x += m_bigk->width()+2;
    index++;
  }
  else if (str[0] == 'm')
  {
    p->drawPixmap( x, 0, *m_bigm );
    x += m_bigm->width()+2;
    index++;
  }
  else if (str[0] == 'u')
  {
    p->drawPixmap( x, 3, *m_bigu );
    x += m_bigu->width()+2;
    index++;
  }
  else if (str[0] == 'n')
  {
    p->drawPixmap( x, 0, *m_bign );
    x += m_bign->width()+2;
    index++;
  }
  
  if (str.mid(index) == "Ohm")
  {
    p->drawPixmap( x, 0, *m_bigOhm );
  }
  else if (str.mid(index) == "C")
  {
    p->drawPixmap( x, 0, *m_bigDeg );
  }
  else if (str.mid(index) == "Hz")
  {
    p->drawPixmap( x, 0, *m_bigHz );
  }
  else if (str.mid(index) == "F")
  {
    p->drawPixmap( x, 0, *m_bigF );
  }
  else if (str.mid(index) == "A")
  {
    p->drawPixmap( x, 0, *m_bigA );
  }
  else if (str.mid(index) == "V")
  {
    p->drawPixmap( x, 0, *m_bigV );
  }
}

void
DisplayWid::drawSmallUnit( QPainter *p, const QString & str )
{
  int index = 0;
  int x = 0;
  
  if (str[0] == 'G')
  {
    p->drawPixmap( x, 0, *m_smallG );
    x += m_smallG->width()+1;
    index++;
  }
  else if (str[0] == 'M')
  {
    p->drawPixmap( x, 0, *m_smallM );
    x += m_smallM->width()+1;
    index++;
  }
  else if (str[0] == 'k')
  {
    p->drawPixmap( x, 0, *m_smallk );
    x += m_smallk->width()+1;
    index++;
  }
  else if (str[0] == 'm')
  {
    p->drawPixmap( x, 0, *m_smallm );
    x += m_smallm->width()+1;
    index++;
  }
  else if (str[0] == 'u')
  {
    p->drawPixmap( x, 3, *m_smallu );
    x += m_smallu->width()+1;
    index++;
  }
  else if (str[0] == 'n')
  {
    p->drawPixmap( x, 0, *m_smalln );
    x += m_smalln->width()+1;
    index++;
  }
  
  if (str.mid(index) == "Ohm")
  {
    p->drawPixmap( x, 0, *m_smallOhm );
  }
  else if (str.mid(index) == "C")
  {
    p->drawPixmap( x, 0, *m_smallDeg );
  }
  else if (str.mid(index) == "Hz")
  {
    p->drawPixmap( x, 0, *m_smallHz );
  }
  else if (str.mid(index) == "F")
  {
    p->drawPixmap( x, 0, *m_smallF );
  }
  else if (str.mid(index) == "A")
  {
    p->drawPixmap( x, 0, *m_smallA );
  }
  else if (str.mid(index) == "V")
  {
    p->drawPixmap( x, 0, *m_smallV );
  }
}

void
DisplayWid::drawBigNumber( QPainter *p, const QString & num )
{
  int x = 0;  
  int start = 0;

  if (num[0] == ' ' || num[0] == '-')
  {
    if (num[0] == '-')
    {
      p->drawPixmap( 0, 0, *m_bigMinus );
    }
    x += 28;
    start = 1;
  }
    
  for (unsigned i=start; i<num.length(); i++)
  {
    if (num[i] == '.')
    {
      p->drawPixmap( x-11, 0, *m_bigDecimal );
    }
    else if (num[i] == 'O')
    {
      p->drawPixmap( x+2, 2, *m_bigDigit, 0, 0, 34, 60 );
      x += 49;
    }
    else if (num[i] == 'L')
    {
      p->drawPixmap( x, 0, *m_bigL );
      x += 49;
    }
    else
    {
      int digit = num[i].latin1()-'0';
      
      if (digit >= 0 && digit <= 9)
      {
        p->drawPixmap( x+2, 2, *m_bigDigit, 34*digit, 0, 34, 60 );
      }
      x += 49;
    }
  }
}
