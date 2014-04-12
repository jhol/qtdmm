//======================================================================
// File:		dmmgraph.cpp
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

#include <qapplication.h>
#include <qcursor.h>
#include <qdatetime.h>
#include <qfile.h>
#include <qfiledialog.h>
#include <qlabel.h>
#include <qmessagebox.h>
#include <qpaintdevicemetrics.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qpopupmenu.h>
#include <qprinter.h>
#include <qregexp.h>
#include <qscrollbar.h>
#include <qtextstream.h>
#include <qtooltip.h>

#include <dmmgraph.h>

#include <math.h> // RedHat needs it

#include <iostream>

#include <icon.xpm>

DMMGraph::DMMGraph( QWidget *parent, const char *name ) :
  QWidget( parent, name ),
  m_size( 600 ),
  m_length( 3600 ),
  m_scaleMin( 0 ),
  m_scaleMax( 0 ),
  m_autoScale( true ),
  m_pointer( 0 ),
  m_ystep( 1 ),
  m_sampleTime( 1 ),
  m_sampleLength( 0 ),
  m_running( false ),
  m_mode( DMMGraph::Manual ),
  m_mouseDown( false ),
  m_lastValValid( false ),
  m_dirty( false ),
  m_alertUnsaved( true ),
  m_externalStarted( false ),
  m_crosshair( true ),
  m_pointMode( Circle ),
  m_intPointMode( Square ),
  m_lineMode( Solid ),
  m_intLineMode( NoLine ),
  m_integrationScale( 1.0 ),
  m_integrationThreshold( 0.0 ),
  m_integrationOffset( 0.0 ),
  m_includeZero( false ),
  m_mousePan( false )
{
  m_array    = new QArray<double> (m_length);
  m_arrayInt = new QArray<double> (m_length);
  
  m_drawArray.resize( m_length );
  
  scrollbar = new QScrollBar( QScrollBar::Horizontal, this );
  scrollbar->setGeometry( 0, height()-16, width(), 16 );
  scrollbar->setTracking( true );
  scrollbar->setCursor( arrowCursor );
  
  connect( scrollbar, SIGNAL( valueChanged(int) ),
           this, SLOT( update() ));
  
  m_remainingLength = m_sampleLength;
  emitInfo();
  
  m_infoBox = new QLabel( 0, 0, WStyle_Customize | 
                                WStyle_NoBorder |
                                WStyle_Tool );
  m_infoBox->resize( 100, 50 );
  m_infoBox->setFrameStyle( QFrame::Box | QFrame::Plain );
  m_infoBox->setPalette( QToolTip::palette() );
  
  setBackgroundMode( QWidget::NoBackground );
  
  startTimer( 200 );
  
  setMouseTracking( true );
  
  m_popup = new QPopupMenu( this );
}

DMMGraph::~DMMGraph()
{
}

void
DMMGraph::timerEvent( QTimerEvent * )
{
  update();
}

void
DMMGraph::paintEvent( QPaintEvent * )
{
  QPixmap pix( width(), height()-16 );
  QPainter p;
  p.begin( &pix );
  
  paint( &p, width(), height()-16, m_xfactor, m_xstep, m_yfactor, m_ystep,
         m_maxUnit, m_hUnitFact, m_hUnit, true, false );
  
  p.end();
  p.begin( this );
  p.drawPixmap( 0, 0, pix );   
  
  if (m_mouseDown)
  {
    drawCursor( m_mpos );
    fillInfoBox( m_mpos );
  }
}

void
DMMGraph::print( QPrinter *prt, const QString & title, const QString & comment )
{
  if (!title.isEmpty())
  {
    prt->setDocName( title );
  }
  else
  {
    QString tmpStr;
    tmpStr.sprintf( "QtDMM: %s", QDateTime::currentDateTime().toString().latin1() );
  }
  
  prt->setCreator( "QtDMM: (c) 2001 Matthias Toussaint" );
  prt->setPrintProgram( "QtDMM: (c) 2001 Matthias Toussaint" );
  
  QPainter p;
  p.begin( prt );
  
  QPaintDeviceMetrics pdm( prt );
 
  int w = pdm.width();
  int h = pdm.height();
 
  p.setFont( QFont( "Helvetica", 16 ) );
  
  QRect tRect = p.boundingRect( 0, 0, w, h, Qt::AlignTop | Qt::AlignHCenter | Qt::WordBreak, title );
  
  p.drawText( tRect, Qt::AlignTop | Qt::AlignHCenter | Qt::WordBreak, title );
  
  p.setFont( QFont( "Helvetica", 10 ));
  
  QFontMetrics fm = p.fontMetrics();
  int maxWidth = QMAX( fm.width( tr( "Sampling start:" ) ), 
                       fm.width( tr( "Sampling resolution:" )));
  int tHeight = fm.height();
  
  p.drawText( 0, tRect.height()+10, maxWidth, tHeight, Qt::AlignLeft | Qt::AlignVCenter, 
              tr( "Sampling start:" ) );
  p.drawText( maxWidth+10, tRect.height()+10, w-maxWidth-10, tHeight, Qt::AlignLeft | Qt::AlignVCenter, 
              m_graphStart.toString() );
  
  p.drawText( 0, tRect.height()+10+tHeight, maxWidth, tHeight, Qt::AlignLeft | Qt::AlignVCenter, 
              tr( "Sampling resolution:" ) );
  QString tmpStr;
  tmpStr.sprintf( "%d %s", m_sampleTime, tr( "Seconds" ).latin1() );
  p.drawText( maxWidth+10, tRect.height()+10+tHeight, 
              w-maxWidth-10, tHeight, Qt::AlignLeft | Qt::AlignVCenter, 
              tmpStr );
  
  //p.setFont( QFont( "Helvetica", 10 ));
  
  QRect cRect = p.boundingRect( 0, 0, w, h, Qt::AlignTop | Qt::AlignLeft | Qt::WordBreak, comment );
  
  p.drawText( 0, tRect.height()+20+2*tHeight, w, cRect.height(), 
              Qt::AlignLeft | Qt::AlignTop | Qt::WordBreak, comment );
  
  h -= tRect.height()+30+2*tHeight+cRect.height();
  
  double yfactor, ystep;  
  yfactor = createYScale( h, ystep );
   
  double xfactor, xstep, hUnitFact, maxUnit;
  QString hUnit;
  xfactor = createTimeScale( w, xstep, hUnitFact, maxUnit, hUnit );
  
  p.setClipRect( 0, tRect.height()+30+2*tHeight+cRect.height(), w, h );
  p.setClipping( true );

  p.translate( 0, tRect.height()+30+2*tHeight+cRect.height() );
  
  paint( &p, w, h, xfactor, xstep, yfactor, ystep,
         maxUnit, hUnitFact, hUnit, prt->colorMode() == QPrinter::Color, true );
  
  p.end();
}

void
DMMGraph::paint( QPainter *p, int w, int h, 
                 double xfactor, double xstep,
                 double yfactor, double ystep,
                 double maxUnit, double hUnitFact, const QString & hUnit,
                 bool color, bool printer )
{
  p->setBrush( m_bgColor );
  p->setPen( Qt::black );
  p->drawRect( 0, 0, w, h );
  
  if (m_scaleMin != m_scaleMax)
  {
    paintHorizontalGrid( p, yfactor, ystep, color );
    paintVerticalGrid( p, xfactor, xstep, maxUnit, hUnitFact, hUnit, color );
    paintData( p, xfactor, yfactor, color, printer );
    paintThresholds( p, xfactor, yfactor, color, printer );
  }
}

void
DMMGraph::paintHorizontalGrid( QPainter *p, double yfactor, double ystep, bool color )
{
  if (color)
  {
    p->setPen( m_gridColor );
  }
  else
  {
    p->setPen( Qt::black );
  }
  
  // draw border
  //
  p->drawRect( m_graphRect );
  
  // draw zero line
  //
  int y = (int)qRound( m_graphRect.y()+(m_scaleMax)/yfactor );
    
  if (y>m_graphRect.y()+m_fontHeight && y<m_graphRect.y()+m_graphRect.height())
  {
    p->drawLine( m_graphRect.x()-3, y, m_graphRect.x()+m_graphRect.width(), y );
  }

  if (color)
  {
    p->setPen( QPen( m_gridColor, 0, Qt::DotLine ) );
  }
  else
  {
    p->setPen( QPen( Qt::black, 0, Qt::DotLine ) );
  }
    
  QString scaleVal;
   
  // Draw horizontal lines  
  // from 0 to max
  //
  double val = 0.0;
  
  while (val < m_scaleMax)
  {
    y = (int)qRound( m_graphRect.y()+(m_scaleMax-val)/yfactor );
    
    if (y>m_graphRect.y()+m_fontHeight && y<m_graphRect.y()+m_graphRect.height())
    {
      p->drawLine( m_graphRect.x()-3, y, m_graphRect.x()+m_graphRect.width(), y );
      scaleVal.sprintf( "%g", val*m_factor );
      p->drawText( 1, y-10, m_graphRect.x()-4, 20, Qt::AlignRight | Qt::AlignVCenter, scaleVal );
    }
    val += ystep;
  }
  
  // from 0 to min
  //
  val = -ystep;
  
  while (val > m_scaleMin)
  {
    y = (int)qRound( m_graphRect.y()+(m_scaleMax-val)/yfactor );
    
    if (y>m_graphRect.y()+m_fontHeight && y<m_graphRect.y()+m_graphRect.height())
    {
      p->drawLine( m_graphRect.x()-3, y, m_graphRect.x()+m_graphRect.width(), y );    
      scaleVal.sprintf( "%g", val*m_factor );
      p->drawText( 1, y-10, m_graphRect.x()-4, 20, Qt::AlignRight | Qt::AlignVCenter, scaleVal );
    }
    val -= ystep;
  }

  if (!m_unit.isEmpty())
  {
    QString tmp = "[";
    tmp += m_prefix;
    tmp += m_unit;
    tmp += "]";
  
    p->drawText( 4, 4, 40, 20, Qt::AlignLeft | Qt::AlignTop, tmp ); //m_unit );
  }
}

void
DMMGraph::paintVerticalGrid( QPainter *p, double xfactor, double xstep,
                             double maxUnit, double hUnitFact, const QString & hUnit, bool color )
{
  if (color)
  {
    p->setPen( QPen( m_gridColor, 0, Qt::DotLine ) );
  }
  else
  {
    p->setPen( QPen( Qt::black, 0, Qt::DotLine ) );
  }
    
  QString scaleVal;
  double val = xstep;
  while (val < maxUnit)
  {
    int x = m_graphRect.x() + (int)qRound( 1+(val)/hUnitFact - scrollbar->value()/xfactor );
    if (x > m_graphRect.x() && x < m_graphRect.x()+m_graphRect.width()-1)
    {
      p->drawLine( x, m_graphRect.y(), x, m_graphRect.y()+m_graphRect.height()+3 );
      if (x > m_graphRect.x() && x < m_graphRect.x()+m_graphRect.width()-1)
      {
        scaleVal.sprintf( "%g", val );
        p->drawText( x-20, m_graphRect.y()+m_graphRect.height()+3, 
                     40, m_fontHeight-3, Qt::AlignCenter, scaleVal );
      }
    }
    val += xstep;
  }
  p->drawText( width()-40, m_graphRect.y()+m_graphRect.height(), 
               36, 20, Qt::AlignRight | Qt::AlignVCenter, hUnit );
}

void
DMMGraph::paintData( QPainter *p, double xfactor, 
                     double yfactor, bool color, bool printer )
{  
  p->setClipRect( m_graphRect );
  
  // draw cursor
  //
  int x = (int)qRound( (m_pointer-scrollbar->value()-1)/xfactor ) + m_graphRect.x();
  
  if (!printer && x>m_graphRect.x() && x <= m_graphRect.x()+m_graphRect.width()-1)
  {
    p->setPen( m_cursorColor );
    p->drawLine( x, 6, x, m_graphRect.y()+m_graphRect.height()-1 );
  }
  
  // draw integration curve
  //
  int y;
  int pCnt;
  
  if (m_showIntegration)
  {
    y = (int)qRound( m_graphRect.y()+
        (m_scaleMax-m_integrationOffset-
          (*m_arrayInt)[scrollbar->value()]*m_integrationScale)/yfactor );

    if (color)
    {
      p->setPen( QPen( m_intColor, m_intLineWidth, 
                 penStyle( m_intLineMode ), Qt::RoundCap, Qt::RoundJoin ) );
    }
    else
    {
      p->setPen( QPen( Qt::darkGray, m_intLineWidth, 
                 penStyle( m_intLineMode ), Qt::RoundCap, Qt::RoundJoin ) );
    }

    pCnt = 1;
    m_drawArray.setPoint( 0, QPoint( m_graphRect.x(), y ) );

    for (int i=scrollbar->value()+1; i<m_pointer; i++)
    {
      int x = (int)qRound( (i-scrollbar->value())/xfactor ) + 51;
      if (x <= m_graphRect.x()+m_graphRect.width())
      {
        y = (int)qRound( m_graphRect.y()+(m_scaleMax-m_integrationOffset-
            (*m_arrayInt)[i]*m_integrationScale)/yfactor );
        //y = (int)qRound( 1+(m_scaleMax-(*m_arrayInt)[i])/yfactor );

        m_drawArray.setPoint( pCnt++, QPoint( x, y ) );
      }
    }   
    if (pCnt)
      p->drawPolyline( m_drawArray, 0, pCnt );
    
    //y = (int)qRound( 1+(m_scaleMax-(*m_arrayInt)[scrollbar->value()])/yfactor );
    y = (int)qRound( m_graphRect.y()+(m_scaleMax-m_integrationOffset-
        (*m_arrayInt)[scrollbar->value()]*m_integrationScale)/yfactor );
    
    if (color)
    {
      p->setPen( m_intColor );
    }
    else
    {
      p->setPen( Qt::darkGray );
    }

    for (int i=scrollbar->value()+1; i<m_pointer; i++)
    {
      int x = (int)qRound( (i-scrollbar->value())/xfactor ) + m_graphRect.x();
      if (x <= m_graphRect.x()+m_graphRect.width())
      {
        y = (int)qRound( m_graphRect.y()+(m_scaleMax-m_integrationOffset-
            (*m_arrayInt)[i]*m_integrationScale)/yfactor );
        //y = (int)qRound( 1+(m_scaleMax-(*m_arrayInt)[i])/yfactor );

        drawPoint( m_intPointMode, p, x, y );
      }
    }   
  }
  
  // draw data curve
  //
  y = (int)qRound( m_graphRect.y()+(m_scaleMax-(*m_array)[scrollbar->value()])/yfactor );

  if (color)
  {
    p->setPen( QPen( m_dataColor, m_lineWidth, 
               penStyle( m_lineMode ), Qt::RoundCap, Qt::RoundJoin ) );
  }
  else
  {
    p->setPen( QPen( Qt::black, m_lineWidth, 
               penStyle( m_lineMode ), Qt::RoundCap, Qt::RoundJoin ) );
  }
  
  pCnt = 1;
  m_drawArray.setPoint( 0, QPoint( m_graphRect.x(), y ) );

  for (int i=scrollbar->value()+1; i<m_pointer; i++)
  {
    int x = (int)qRound( (i-scrollbar->value())/xfactor ) + m_graphRect.x();
    if (x <= m_graphRect.x()+m_graphRect.width())
    {
      int y = (int)qRound( m_graphRect.y()+(m_scaleMax-(*m_array)[i])/yfactor );

      m_drawArray.setPoint( pCnt++, QPoint( x, y ) );
    }
  }   
  if (pCnt)
    p->drawPolyline( m_drawArray, 0, pCnt );
  
  y = (int)qRound( m_graphRect.y()+(m_scaleMax-(*m_array)[scrollbar->value()])/yfactor );

  if (color)
  {
    p->setPen( m_dataColor );
  }
  else
  {
    p->setPen( Qt::black );
  }
  
  for (int i=scrollbar->value()+1; i<m_pointer; i++)
  {
    int x = (int)qRound( (i-scrollbar->value())/xfactor ) + m_graphRect.x();
    if (x <= m_graphRect.x()+m_graphRect.width())
    {
      int y = (int)qRound( m_graphRect.y()+(m_scaleMax-(*m_array)[i])/yfactor );

      drawPoint( m_pointMode, p, x, y );
    }
  }   
  
  p->setClipping( false );
}

void
DMMGraph::paintThresholds( QPainter *p, double /* xfactor */, 
                           double /*yfactor*/, bool color, bool printer )
{
  if (m_startExternal)
  {
    if (printer && !color)
    {
      p->setPen( Qt::gray );
    }
    else
    {
      p->setPen( m_externalColor );
    }

    p->drawLine( m_graphRect.x(), m_externalThresholdY, 
                 m_graphRect.x()+m_graphRect.width(), m_externalThresholdY );
  }
  
  if (m_showIntegration)
  {
    if (printer && !color)
    {
      p->setPen( Qt::darkGray );
    }
    else
    {
      p->setPen( m_intThresholdColor );
    }

    p->drawLine( m_graphRect.x(), m_integrationThresholdY, 
                 m_graphRect.x()+m_graphRect.width(), m_integrationThresholdY );
  }
  
  if (m_mode == Raising || m_mode == Falling)
  {
    if (printer && !color)
    {
      p->setPen( Qt::gray );
    }
    else
    {
      p->setPen( m_startColor );
    }

    p->drawLine( m_graphRect.x(), m_triggerThresholdY, 
                 m_graphRect.x()+m_graphRect.width(), m_triggerThresholdY );
  }
}

void
DMMGraph::resizeEvent( QResizeEvent * )
{
  QFontMetrics fm = fontMetrics();
  
  int xOff = fm.width( "-999.99" );
  m_fontHeight = fm.height() + 4;
  
  m_graphRect = QRect(xOff, 5, width()-5-xOff, height()-16-5-m_fontHeight );
  
  scrollbar->setGeometry( 0, height()-16, width(), 16 );
  
  m_yfactor = createYScale( m_graphRect.height(), m_ystep );
  m_xfactor = createTimeScale( m_graphRect.width(), m_xstep, m_hUnitFact,
                               m_maxUnit, m_hUnit );
  
  m_externalThresholdY = (int)qRound( m_graphRect.y()+(m_scaleMax-m_externalThreshold)/m_yfactor );   
  m_integrationThresholdY = (int)qRound( m_graphRect.y()+(m_scaleMax-m_integrationThreshold)/m_yfactor );   
  
  double val = m_mode == Raising ? m_raisingThreshold : m_fallingThreshold;
  
  m_triggerThresholdY = (int)qRound( m_graphRect.y()+(m_scaleMax-val)/m_yfactor );   
}

void
DMMGraph::setGraphSize( int size, int length )
{
  m_size = (int)((double)size/m_sampleTime*10.);
  m_length = (int)((double)length/m_sampleTime*10. + 1);
  
  scrollbar->setMaxValue( m_length-1-m_size );
  scrollbar->setLineStep( (m_size-1)/10 );
  scrollbar->setPageStep( m_size );
  
  m_array->resize( m_length );
  m_arrayInt->resize( m_length );
  if (m_pointer >= m_length)
  {
    m_pointer = m_length-1;
  }

  emitInfo();
  
  resizeEvent( 0 );
  update();
}

void
DMMGraph::startSLOT()
{
  m_sampleCounter = 0;
  m_sum = 0;
  clearSLOT();
  m_running = true;
  
  m_remainingLength = m_sampleLength;
  m_pointer = 0;
  
  emitInfo();  
  emit running( true );
  
  m_graphStart = QDateTime::currentDateTime();
  m_externalStarted = false;
  
  (*m_arrayInt)[0] = 0;
}

void
DMMGraph::stopSLOT()
{
  m_running = false;
  
  emitInfo();  
  emit running( false );
}
 
void
DMMGraph::addValue( double val )
{
  if (m_mode == DMMGraph::Time && !m_running)
  {
    // we may miss the start due to aliasing otherwise
    int diff = m_startTime.secsTo( QTime::currentTime() );
    
    if (diff >= 0 && diff < 2)
    {
      qApp->beep();
      startSLOT();
    }
  }
  
  if (m_mode == DMMGraph::Raising && !m_running)
  {
    if (m_lastValValid)
    {
      if (m_lastVal < m_raisingThreshold && val >= m_raisingThreshold)
      {
        qApp->beep();
        startSLOT();
      }
    }
  }
  
  if (m_mode == DMMGraph::Falling && !m_running)
  {
    if (m_lastValValid)
    {
      if (m_lastVal > m_fallingThreshold && val <= m_fallingThreshold)
      {
        qApp->beep();
        startSLOT();
      }
    }
  }
  
  if (!m_externalStarted && m_running && m_startExternal)
  {
    if (m_externalFalling && 
        m_lastVal > m_externalThreshold && 
        val <= m_externalThreshold)
    {
      m_externalStarted = true;
      emit externalTriggered();
    }
    else if (!m_externalFalling && 
             m_lastVal < m_externalThreshold && 
             val >= m_externalThreshold)
    {
      m_externalStarted = true;
      emit externalTriggered();
    }
  }
  
  m_lastValValid = true;
  m_lastVal = val;
  
  if (!m_running) return;
    
  m_sum += val;
  
  if (0 == m_sampleCounter)
  {
    m_dirty = true;

    if (!m_first)
    {
      val = m_sum / (double)m_sampleTime;
    }
    m_first = false;
    m_sum = 0.0;
    
    if (m_pointer >= m_length)
    {
      for (int i=1; i<m_length; i++)
      {
        (*m_array)[i-1] = (*m_array)[i];
        (*m_arrayInt)[i-1] = (*m_arrayInt)[i];
      }
      m_pointer = m_length-1;
    }

    if (m_pointer > 0)
    {
      if (m_lastVal <= m_integrationThreshold)
      {
        (*m_arrayInt)[m_pointer] = 0.0;
      }
      else
      {
        (*m_arrayInt)[m_pointer] = (*m_arrayInt)[m_pointer-1]+val;
      }
    }
    else
    {
      (*m_arrayInt)[m_pointer] = QMAX( val, m_integrationThreshold );
    }
    
    (*m_array)[m_pointer++] = val;
    bool resFlag = false;

    if (m_autoScale)
    {
      resFlag = computeMinMax( val );
      //cerr << "val=" << val << " min=" << m_scaleMin << " max=" << m_scaleMax << endl;
      computeUnitFactor();
    }
    
    if (resFlag)
      resizeEvent( 0 );

    //update();
  }

  emitInfo();
    
  m_sampleCounter++;
  if (m_sampleCounter == m_sampleTime) m_sampleCounter = 0;
  
  if (0 == m_remainingLength && m_sampleLength != 0)
  {
    qApp->beep();
    stopSLOT();
    return;
  }
  
  m_remainingLength = QMAX( 0, m_remainingLength-1 );
}

double
DMMGraph::createYScale( int h, double & ystep )
{
  double yfactor = (m_scaleMax-m_scaleMin) / (double)h;
  
  double idiv = (double)(h-2)/(double)(3*m_fontHeight);
  double ddiv = (m_scaleMax-m_scaleMin)/idiv;
  
  // try to find 1-2-5 division between 1e-18 and 1e18
  //
  double one = 1e-18;
  double two = 2e-18;
  double five = 5e-18;
  bool gotcha = false;
  
  do 
  {
    if (ddiv > one && ddiv <= two)
    {
      ystep = one; 
      gotcha = true;
    }
    else if (ddiv > two && ddiv <= five)
    {
      ystep = two;
      gotcha = true;
    }
    else if (ddiv > five && ddiv < one*10.)
    {
      ystep = five;
      gotcha = true;
    }
    
    one  *= 10.;
    two  *= 10.;
    five *= 10.;
  }
  while (!gotcha && one < 1e18);
  
  return yfactor;
}

// returns xfactor
double 
DMMGraph::createTimeScale( int w, double & xstep, double & hUnitFact,
                           double & maxUnit, QString & hUnit )
{
  double xfactor = (double)m_size/(double)(w-52);
  
  double idiv = (double)(w-2-50)/80.;
  double ddiv = m_size*m_sampleTime/10./idiv;
  
  hUnit = tr( "[sec]" );
  hUnitFact = xfactor*m_sampleTime/10.;
  maxUnit = (m_length-1)*m_sampleTime/10.;
  
  if (ddiv > 60)
  {
    ddiv /= 60;
    hUnit = tr( "[min]" );
    hUnitFact /= 60;
    maxUnit /= 60;
    
    if (ddiv > 60)
    {
      ddiv /= 60;
      hUnitFact /= 60;
      maxUnit /= 60;
      
      hUnit = tr( "[hour]" );
      
      if (ddiv > 24)
      {
        ddiv /= 24;
        hUnitFact /= 24;
        maxUnit /= 24;
        
        hUnit = tr( "[day]" );
      }
    }
  }
  
  // try to find 1-2-5 division between 1 and 1e9
  //
  double one = 1;
  double two = 2;
  double five = 5;
  bool gotcha = false;
  
  do 
  {
    if (ddiv > one && ddiv <= two)
    {
      xstep = one; 
      gotcha = true;
    }
    else if (ddiv > two && ddiv <= five)
    {
      xstep = two;
      gotcha = true;
    }
    else if (ddiv > five && ddiv < one*10.)
    {
      xstep = five;
      gotcha = true;
    }
    
    one  *= 10.;
    two  *= 10.;
    five *= 10.;
  }
  while (!gotcha && one < 1e9);
    
  return xfactor;
}

void
DMMGraph::setUnit( const QString & unit )
{
  if (unit.left(1) == "n")
  {
    m_unit = unit.mid( 1 );
  }
  else if (unit.left(1) == "u")
  {
    m_unit = unit.mid( 1 );
  }
  else if (unit.left(1) == "m")
  {
    m_unit = unit.mid( 1 );
  }
  else if (unit.left(1) == "k")
  {
    m_unit = unit.mid( 1 );
  }
  else if (unit.left(1) == "M")
  {
    m_unit = unit.mid( 1 );
  }
  else
  {
    m_unit = unit;
  }
  
  return;
}

void
DMMGraph::clearSLOT()
{
  m_pointer = 0;
  if (m_autoScale)
  {
    if (m_includeZero)
    {
      m_scaleMin = m_scaleMax = 0;
    }
    else
    {
      m_scaleMin =  1e40;
      m_scaleMax = -1e40;
    }
  }
  
  m_graphStart = QDateTime::currentDateTime();
  m_first = true;
  m_dirty = false;
  
  update();
}

void
DMMGraph::emitInfo()
{
  int w = m_remainingLength / 60 / 60 / 24 / 7;
  int d = ( m_remainingLength / 60 / 60 / 24 ) % 7;
  int h = ( m_remainingLength / 60 / 60 ) % (24);
  int m = (m_remainingLength / 60 ) % 60;
  int s = m_remainingLength % 60;
  
  QString txt;
  
  if (w)
  {
    txt.sprintf( "%d/%d - %dweek%s %dday%s %02d:%02d:%02d - %s", 
                 m_pointer, m_length, w, (w>1 ? "s" : ""), d, (d>1 ? "s" : ""), h, m, s, 
                 m_running ? tr( "Sampling" ).latin1() : tr( "Stopped" ).latin1() );
  }
  else if (d)
  {
    txt.sprintf( "%d/%d - %dday%s %02d:%02d:%02d - %s", 
                 m_pointer, m_length, d, (d>1 ? "s" : ""), h, m, s, 
                 m_running ? tr( "Sampling" ).latin1() : tr( "Stopped" ).latin1() );
  }
  else if (h)
  {
    txt.sprintf( "%d/%d - %02d:%02d:%02d - %s", 
                 m_pointer, m_length, h, m, s, 
                 m_running ? tr( "Sampling" ).latin1() : tr( "Stopped" ).latin1() );
  }
  else
  {
    txt.sprintf( "%d/%d - %02d:%02d - %s", 
                 m_pointer, m_length, m, s, 
                 m_running ? tr( "Sampling" ).latin1() : tr( "Stopped" ).latin1() );
  }
  
  emit info( txt );
}

void
DMMGraph::wheelEvent( QWheelEvent *ev )
{
  if (ev->delta() > 0)
  {
    emit zoomOut( 1.1 );
  }
  else
  {
    emit zoomIn( 1.1 );
  }
}
  
void
DMMGraph::mousePressEvent( QMouseEvent *ev )
{
  if (ev->button() == LeftButton)
  {
    if (m_scaleMin == m_scaleMax || m_scaleMin == 1e40) return;
    if (ev->x() < m_graphRect.x()) return;

    m_mouseDown = true;
    m_mousePan = false;
    
    if (m_cursorMode == NoCursor)
    {
      drawCursor( ev->pos() );
      m_mpos = ev->pos();

      m_infoBox->move( ev->globalPos().x()+4, ev->globalPos().y()+4 );
      fillInfoBox( ev->pos() );
      m_infoBox->show();
    }
  }
  else if(ev->button() == RightButton)
  {
    /*m_popup->clear();
    
    if (m_running)
    {
      m_popup->insertItem( tr("Stop recorder") );
    }
    else
    {
      m_popup->insertItem( tr("Start recorder") );
    }    
    m_popup->insertItem( tr("Clear graph") );
    m_popup->insertSeparator();
    m_popup->insertItem( tr("Automatic scale") );
    m_popup->insertItem( tr("Include zero line") );
    m_popup->insertSeparator();
    m_popup->insertItem( tr("Configure recorder") );
    m_popup->insertItem( tr("Configure scale") );
    m_popup->insertItem( tr("Configure graph") );

    m_popup->popup( ev->globalPos() );*/
  }
  else if (ev->button() == MidButton)
  {
    m_mouseDown = false;
    m_mousePan = true;
    
    m_mpos = ev->pos();
  }  
}

void
DMMGraph::mouseMoveEvent( QMouseEvent *ev )
{
  if (m_scaleMin == m_scaleMax || m_scaleMin == 1e40) return;
  
  if (!m_mouseDown)
  {
    if (m_mousePan)
    {
      //cerr << "delta: " << m_mpos.x()-ev->pos().x() << " " << m_mpos.y()-ev->pos().y() << endl;
      
      double offset = (m_mpos.x()-ev->pos().x())*m_xfactor;
      //cerr << "delta=" << m_mpos.x()-ev->pos().x() << " offset=" << offset << endl;
      if (fabs(offset) >= 1)
      {
        scrollbar->setValue( scrollbar->value() + (int)qRound(offset) );
        m_mpos = ev->pos();
      }
    }
    else
    {
      if (abs(ev->y()-m_triggerThresholdY) < 3)
      {
        setCursor( splitVCursor );
        m_cursorMode = Trigger;
      }
      else if (abs(ev->y()-m_externalThresholdY) < 3)
      {
        setCursor( splitVCursor );
        m_cursorMode = External;
      }
      else if (abs(ev->y()-m_integrationThresholdY) < 3)
      {
        setCursor( splitVCursor );
        m_cursorMode = Integration;
      }
      else
      {
        setCursor( arrowCursor );
        m_cursorMode = NoCursor;
      }
    }
  }
  else if (m_cursorMode == Trigger)
  {
    m_triggerThresholdY = ev->y();  
    
    if (m_mode == Raising)
    {
      m_raisingThreshold = m_scaleMax - ( m_triggerThresholdY - m_graphRect.y()) * m_yfactor;
      
      emit thresholdChanged( Trigger, m_raisingThreshold );
    }
    else
    {
      m_fallingThreshold = m_scaleMax - ( m_triggerThresholdY - m_graphRect.y()) * m_yfactor;
      
      emit thresholdChanged( Trigger, m_fallingThreshold );
    }
     
    update();
  }
  else if (m_cursorMode == External)
  {
    m_externalThresholdY = ev->y();
    m_externalThreshold = m_scaleMax - ( m_externalThresholdY - m_graphRect.y()) * m_yfactor;
    
    emit thresholdChanged( External, m_externalThreshold );
    update();
  }
  else if (m_cursorMode == Integration)
  {
    m_integrationThresholdY = ev->y();
    m_integrationThreshold = m_scaleMax - ( m_integrationThresholdY - m_graphRect.y()) * m_yfactor;
    
    emit thresholdChanged( Integration, m_integrationThreshold );
    update();
  }
  else if (m_cursorMode == NoCursor)
  {  
    drawCursor( m_mpos );
    if (ev->x() < 51)
    {
      drawCursor( QPoint( 51, ev->y() ));
      m_mpos = QPoint( 51, ev->y() );
    }
    else
    {
      drawCursor( ev->pos() );
      m_mpos = ev->pos();
    }
    m_infoBox->move( ev->globalPos().x()+4, ev->globalPos().y()+4 );
    fillInfoBox( ev->pos() );
  }
}

void
DMMGraph::mouseReleaseEvent( QMouseEvent * )
{
  if (m_scaleMin == m_scaleMax || m_scaleMin == 1e40) return;
  
  if (m_mouseDown)
  {
    drawCursor( m_mpos );
    m_infoBox->hide();
  }
  m_mouseDown = false;
  m_mousePan = false;
}

void
DMMGraph::drawCursor( const QPoint & pos )
{
  QPainter p(this);
  p.setRasterOp( Qt::XorROP );
  p.setPen( Qt::white );
  p.drawLine( pos.x(), m_graphRect.y(), pos.x(), m_graphRect.height()+m_graphRect.y()-1 );
  
  if (m_crosshair)
  {
    int x = (int)qRound( (pos.x()-m_graphRect.x())*m_xfactor + scrollbar->value() );
    if (x < 0) x = 0;
  
    if (x < m_pointer)
    {
      double y = (*m_array)[x];
      int Y = (int)qRound( m_graphRect.y()+(m_scaleMax-y)/m_yfactor );
      p.drawLine( m_graphRect.x(), Y, m_graphRect.x()+m_graphRect.width()-1, Y );  
    }
  }
}

void
DMMGraph::fillInfoBox( const QPoint & pos )
{
  int x = (int)qRound( (pos.x()-m_graphRect.x())*m_xfactor + scrollbar->value() );
  if (x < 0) x = 0;
  int sec = (int)((double)x * m_sampleTime/10.);
  
  QTime t = m_graphStart.time().addSecs( sec );
  QString tmpStr = t.toString();
  
  if (x < m_pointer)
  {
    tmpStr += "\n";
  
    QString prefix ="";
    double val = (*m_array)[x];
    
    //tmpStr += EngNumberValidator::engValue( val );
    
    if (fabs(val) < 1 && val != 0)
    {
      val *= 1000;
      prefix = "m";
    }
    if (fabs(val) < 1 && val != 0)
    {
      val *= 1000;
      prefix = "�";
    }
    if (fabs(val) < 1 && val != 0)
    {
      val *= 1000;
      prefix = "n";
    }
    if (fabs(val) < 1 && val != 0)
    {
      val *= 1000;
      prefix = "p";
    }
    if (fabs(val) >= 1000)
    {
      val /= 1000;
      prefix = "k";
    }
    if (fabs(val) >= 1000)
    {
      val /= 1000;
      prefix = "M";
    }
    if (fabs(val) >= 1000)
    {
      val /= 1000;
      prefix = "G";
    }
    
    QString unit = prefix + m_unit;
        
    
    QString tmpVal;
    tmpVal.sprintf( "%g %s", val, (const char *)unit.local8Bit() );
    
    tmpStr += tmpVal; 
        
  }
  
  m_infoBox->setText( tmpStr );
  m_infoBox->adjustSize();
}

void
DMMGraph::exportDataSLOT()
{
  QString fn = QFileDialog::getSaveFileName( QString::null, 
                                             "All files (*.*)", 
                                             this );
    
  if (!fn.isNull()) 
  {                 
    QFile file( fn );      
    file.open( IO_WriteOnly );
    
    QTextStream ts( &file );
    
    for (int i=0; i<m_pointer; i++)
    {
      QDateTime dt = m_graphStart.addSecs( i*(int)qRound(m_sampleTime/10.) );
      QString line;
      line.sprintf( "%02d.%02d.%04d\t%02d:%02d:%02d\t%g\t%s\n",
          dt.date().day(), dt.date().month(), dt.date().year(),
          dt.time().hour(), dt.time().minute(), dt.time().second(),
          (*m_array)[i],
          m_unit.mid( 1, m_unit.length()-2 ).latin1() );
      
      ts << line;
    }
    
    m_dirty = false;
    
    file.close();
  }
}

void
DMMGraph::importDataSLOT()
{
  if (m_dirty && m_alertUnsaved)
  {
    QMessageBox question( tr("QtDMM: Unsaved data" ),
                          tr("<font size=+2><b>Unsaved data</b></font><p>"
                             "Importing data will overwrite your measured data"
                             "<p>Do you want to export your unsaved data first?" ),
                             QMessageBox::Information,
                             QMessageBox::Yes | QMessageBox::Default,
                             QMessageBox::No,
                             QMessageBox::Cancel | QMessageBox::Escape );
    
    question.setButtonText( QMessageBox::Yes, tr("Export data first") );
    question.setButtonText( QMessageBox::No, tr("Import & overwrite data") );
    question.setIconPixmap( QPixmap((const char **)icon_xpm ) );
    
    switch (question.exec())
    {
    case QMessageBox::Yes:
      exportDataSLOT();
      return;
    case QMessageBox::Cancel:
      return;
    }
  }
  
  QString fn = QFileDialog::getOpenFileName( QString::null, 
                                             "All files (*.*)", 
                                             this );
    
  int cnt = 0;
  int sample = 0;
  
  QDateTime graphEnd;
  
  if (!fn.isNull()) 
  { 
    // First pass -> figure out size and sample time              
    QFile file( fn );      
    
    if (file.open( IO_ReadOnly ))
    {
      QTextStream ts( &file );

      QString line = ts.readLine();

      if (!line.isNull())
      {
        /*QRegExp re( "[0-9]+\\.[0-9]+\\.[0-9]+\t[0-9]+:[0-9]+:[0-9]+\t[0-9]*\\.[0-9]+\t.*" );
        if (re.match(line) == -1)
        {
          emit error( tr("Oops! Seems not to be a valid file") );
          
          return;
        }*/
        
        QTime startTime = QTime( line.mid( 11, 2 ).toInt(), 
                                 line.mid( 14, 2 ).toInt(),
                                 line.mid( 17, 2 ).toInt() );
        QDate startDate = QDate( line.mid( 6, 4 ).toInt(), 
                                 line.mid( 3, 2 ).toInt(),
                                 line.mid( 0, 2 ).toInt() );

        m_graphStart = QDateTime( startDate, startTime );
        graphEnd = QDateTime( startDate, startTime );
        
        setUnit( line.mid( 27, 1 ) );
        
        cnt++;

        while (!(line = ts.readLine()).isNull())
        {
          QTime nowTime = QTime( line.mid( 11, 2 ).toInt(), 
                                 line.mid( 14, 2 ).toInt(),
                                 line.mid( 17, 2 ).toInt() );   
          QDate nowDate = QDate( line.mid( 6, 4 ).toInt(), 
                                 line.mid( 3, 2 ).toInt(),
                                 line.mid( 0, 2 ).toInt() );

          sample += QDateTime( startDate, startTime ).secsTo( 
              QDateTime( nowDate, nowTime ) );

          startTime = nowTime;
          startDate = nowDate;

          graphEnd = QDateTime( startDate, startTime );
          
          cnt++;

        }
      }
      file.close();
    }
    
    m_sampleTime = m_graphStart.secsTo( graphEnd );
    
    int size = m_size*m_sampleTime;
    int length = (m_length-1)*m_sampleTime;
    
    if (cnt > 1)
    {
      if (sample/(cnt-1) != m_sampleTime)
      {
        emit sampleTime( m_sampleTime );
      }
      m_sampleTime = sample/(cnt-1);
    }
    
    if (cnt*m_sampleTime > length)
    {
      if (size > cnt*m_sampleTime) size = cnt*m_sampleTime;
      emit graphSize( size, cnt*m_sampleTime );
      setGraphSize( size, cnt*m_sampleTime );
    }
    
    m_scaleMin =  1e40;
    m_scaleMax = -1e40;
    
    if (file.open( IO_ReadOnly ))
    {
      int i = 0;
      
      QTextStream ts( &file );
      QString line;
      
      while (!(line = ts.readLine()).isNull())
      {
        (*m_array)[i++] = line.mid( 20, 6 ).toDouble();
      }
            
      m_sampleCounter = m_pointer = cnt;
      setScale( true, true, 0, 0 );
      
      file.close();
      m_dirty = false;
      
      emit error( fn );
      
      update();
      
      computeUnitFactor();
    }
  }
}

void
DMMGraph::setThresholds( double falling, double raising )
{
  m_fallingThreshold = falling;
  m_raisingThreshold = raising;
}

void
DMMGraph::setScale( bool autoScale, bool includeZero, double min, double max )
{
  m_autoScale = autoScale;
  m_includeZero = includeZero;
  
  if (!autoScale)
  {
    m_scaleMin = min;
    m_scaleMax = max;
    
    computeUnitFactor();
  }
  else
  {
    if (m_includeZero)
    {
      m_scaleMin = m_scaleMax = 0;
    }
    else
    {
      m_scaleMin =  1e40;
      m_scaleMax = -1e40;
    }
    
    
    for (int i=0; i<m_pointer; i++)
    {
      const double val = (*m_array)[i];
      computeMinMax( val );
    }

    computeUnitFactor();
  }
  
  resizeEvent( 0 );
}

bool
DMMGraph::computeMinMax( double val )
{
  bool ret = false;
  
  if (val > m_scaleMax*0.95)
  { 
    if (val > 0)
    {
      m_scaleMax = val*1.2;
    }
    else
    {
      m_scaleMax = val/1.2;
    }
    
    ret = true;
  }
  if (val < m_scaleMin*0.95)
  { 
    if (val > 0)
    {
      m_scaleMin = val/1.2;
    }
    else
    {
      m_scaleMin = val*1.2;
    }
    
    ret = true;
  }
  
  return ret;
}

void
DMMGraph::setColors( const QColor & bg, const QColor & grid,
                     const QColor & data, const QColor & cursor,
                     const QColor & start, const QColor & external,
                     const QColor & integration, const QColor & intThreshold )
{
  m_bgColor           = bg;
  m_gridColor         = grid;
  m_dataColor         = data;
  m_cursorColor       = cursor;
  m_startColor        = start;
  m_externalColor     = external;
  m_intColor          = integration;
  m_intThresholdColor = intThreshold;
   
  update();
}

void
DMMGraph::setLineStyle( int lineMode, int pointMode,
                        int intLineMode, int intPointMode )
{
  m_lineMode = (LineMode)lineMode;
  m_pointMode = (PointMode)pointMode;
  m_intLineMode = (LineMode)intLineMode;
  m_intPointMode = (PointMode)intPointMode;  
}

void
DMMGraph::setLine( int d, int i )
{
  m_lineWidth    = d;
  m_intLineWidth = i;
  
  update();
}

void
DMMGraph::setExternal( bool on, bool falling, double threshold ) 
{
  m_startExternal = on;
  m_externalFalling = falling;
  m_externalThreshold = threshold;
}

void
DMMGraph::drawPoint( PointMode mode, QPainter *p, int x, int y )
{
  static QPointArray arr(4);
  
  switch (mode)
  {
  case NoPoint:
    return;
  case Square:
    p->drawRect( x-2, y-2, 5, 5 );
    return;
  case Circle:
    p->drawEllipse( x-2, y-2, 5, 5 );
    return;
  case Diamond:
    arr.setPoint( 0, QPoint( x-3, y ) );
    arr.setPoint( 1, QPoint( x, y+3 ) );
    arr.setPoint( 2, QPoint( x+3, y ) );
    arr.setPoint( 3, QPoint( x, y-3 ) );
    p->drawPolygon( arr );
    return;
  case X:
    p->drawLine( x-3, y-3, x+3, y+3 );
    p->drawLine( x+3, y-3, x-3, y+3 );
    return;
  case LargeSquare:
    p->drawRect( x-3, y-3, 7, 7 );
    return;
  case LargeCircle:
    p->drawEllipse( x-3, y-3, 7, 7 );
    return;
  case LargeDiamond:
    arr.setPoint( 0, QPoint( x-4, y ) );
    arr.setPoint( 1, QPoint( x, y+4 ) );
    arr.setPoint( 2, QPoint( x+4, y ) );
    arr.setPoint( 3, QPoint( x, y-4 ) );
    p->drawPolygon( arr );
    return;
  case LargeX:
    p->drawLine( x-4, y-4, x+4, y+4 );
    p->drawLine( x+4, y-4, x-4, y+4 );
    return;
  }
}

Qt::PenStyle
DMMGraph::penStyle( LineMode mode )
{
  switch (mode)
  {
  case NoLine:
    return Qt::NoPen;
  case Solid:
    return Qt::SolidLine;
  case Dot:
    return Qt::DotLine;
  }
  
  return Qt::SolidLine;
}

void
DMMGraph::setIntegration( bool showInt, double sc, double th, double off )
{
  m_showIntegration = showInt;
  m_integrationScale = sc;
  m_integrationThreshold = th;
  m_integrationOffset = off;
}

void
DMMGraph::computeUnitFactor()
{
  m_factor = 1.;
  m_prefix = "";
  
  if (m_unit == "C") return;
  
  if (QMAX( fabs(m_scaleMax*m_factor), fabs(m_scaleMin*m_factor)) > 1000)
  {
    m_factor /= 1000.;
    m_prefix = "k";
  }
  if (QMAX( fabs(m_scaleMax*m_factor), fabs(m_scaleMin*m_factor)) > 1000)
  {
    m_factor /= 1000.;
    m_prefix = "M";
  }
  if (QMAX( fabs(m_scaleMax*m_factor), fabs(m_scaleMin*m_factor)) > 1000)
  {
    m_factor /= 1000.;
    m_prefix = "G";
  }
  if (QMAX( fabs(m_scaleMax*m_factor), fabs(m_scaleMin*m_factor)) < 1)
  {
    m_factor *= 1000.;
    m_prefix = "m";
  }
  if (QMAX( fabs(m_scaleMax*m_factor), fabs(m_scaleMin*m_factor)) < 1)
  {
    m_factor *= 1000.;
    m_prefix = "�";
  }
  if (QMAX( fabs(m_scaleMax*m_factor), fabs(m_scaleMin*m_factor)) < 1)
  {
    m_factor *= 1000.;
    m_prefix = "n";
  }
  if (QMAX( fabs(m_scaleMax*m_factor), fabs(m_scaleMin*m_factor)) < 1)
  {
    m_factor *= 1000.;
    m_prefix = "p";
  }
}
