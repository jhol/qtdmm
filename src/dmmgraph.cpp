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

#include <dmmgraph.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <iostream.h>
#include <qapplication.h>
#include <qpaintdevicemetrics.h>
#include <qcursor.h>
#include <qtooltip.h>
#include <qfiledialog.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qdatetime.h>
#include <qmessagebox.h>

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
  m_sampleLength( 500 ),
  m_running( false ),
  m_mode( DMMGraph::Manual ),
  m_mouseDown( false ),
  m_lastValValid( false ),
  m_dirty( false ),
  m_alertUnsaved( true )
{
  m_array = new QArray<double> (m_length);
  
  scrollbar = new QScrollBar( QScrollBar::Horizontal, this );
  scrollbar->setGeometry( 0, height()-16, width(), 16 );
  scrollbar->setTracking( true );
  scrollbar->setCursor( arrowCursor );
  
  connect( scrollbar, SIGNAL( valueChanged(int) ),
           this, SLOT( update() ));
  
  m_remainingLength = m_sampleLength;
  emitInfo();
  
  m_infoBox = new QLabel( 0, 0, WStyle_Customize | WStyle_NoBorder |
                                WStyle_Tool );
  m_infoBox->resize( 100, 50 );
  m_infoBox->setFrameStyle( QFrame::Box | QFrame::Plain );
  m_infoBox->setPalette( QToolTip::palette() );
  
  setBackgroundMode( QWidget::NoBackground );
}

DMMGraph::~DMMGraph()
{
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
 
  p.setFont( QFont( "Helvetica", 20 ) );
  
  QRect tRect = p.boundingRect( 0, 0, w, h, Qt::AlignTop | Qt::AlignHCenter | Qt::WordBreak, title );
  
  p.drawText( tRect, Qt::AlignTop | Qt::AlignHCenter | Qt::WordBreak, title );
  
  p.setFont( QFont( "Helvetica", 12 ));
  
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
  
  p.setFont( QFont( "Helvetica", 10 ));
  
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
    paintHorizontalGrid( p, w, h, yfactor, ystep, color );
    paintVerticalGrid( p, w, h, xfactor, xstep, maxUnit, hUnitFact, hUnit, color );
    paintData( p, w, h, xfactor, yfactor, color, printer );
  }
}

void
DMMGraph::paintHorizontalGrid( QPainter *p, int w, int h, double yfactor, double ystep, bool color )
{
  if (color)
  {
    p->setPen( m_gridColor );
  }
  else
  {
    p->setPen( Qt::black );
  }
  int y = (int)qRound( 1+(m_scaleMax)/yfactor );
  p->drawLine( 47, y, w-1, y );
  p->drawLine( 50, 1, 50, h-1-20 );
  p->drawLine( 50, h-1-20, w-1, h-1-20 );

  if (color)
  {
    p->setPen( QPen( m_gridColor, 0, Qt::DotLine ) );
  }
  else
  {
    p->setPen( QPen( Qt::black, 0, Qt::DotLine ) );
  }
    
  QString scaleVal;
  double val = 0.0;
  while (val < m_scaleMax)
  {
    y = (int)qRound( 1+(m_scaleMax-val)/yfactor );
    p->drawLine( 47, y, w-1, y );
    if (y>20)
    {
      scaleVal.sprintf( "%g", val );
      p->drawText( 1, y-10, 44, 20, Qt::AlignRight | Qt::AlignVCenter, scaleVal );
    }
    val += ystep;
  }
  val = -ystep;
  while (val > m_scaleMin)
  {
    y = (int)qRound( 1+(m_scaleMax-val)/yfactor );
    p->drawLine( 47, y, w-1, y );
    scaleVal.sprintf( "%g", val );
    p->drawText( 1, y-10, 44, 20, Qt::AlignRight | Qt::AlignVCenter, scaleVal );
    val -= ystep;
  }

  p->drawText( 4, 4, 40, 20, Qt::AlignLeft | Qt::AlignVCenter, m_unit );
}

void
DMMGraph::paintVerticalGrid( QPainter *p, int w, int h, double xfactor, double xstep,
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
    int x = 50 + (int)qRound( 1+(val)/hUnitFact - scrollbar->value()/xfactor );
    if (x > 51 && x < w-20)
    {
      p->drawLine( x, 1, x, h-1-20 );
      if (x < w-45)
      {
        scaleVal.sprintf( "%g", val );
        p->drawText( x-20, h-1-20, 40, 20, Qt::AlignCenter, scaleVal );
      }
    }
    val += xstep;
  }
  p->drawText( w-40, h-1-20, 36, 20, Qt::AlignRight | Qt::AlignVCenter, hUnit );
}

void
DMMGraph::paintData( QPainter *p, int w, int h, double xfactor, double yfactor, bool color, bool printer )
{  
  int x = (int)qRound( (m_pointer-scrollbar->value()-1)/xfactor ) + 51;
  if (!printer && x>50 && x <= w)
  {
    p->setPen( m_cursorColor );
    p->drawLine( x, 1, x, h-1-20 );
  }

  int y = (int)qRound( 1+(m_scaleMax-(*m_array)[scrollbar->value()])/yfactor );

  if (color)
  {
    p->setPen( QPen( m_dataColor, m_lineWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin ) );
  }
  else
  {
    p->setPen( QPen( Qt::black, m_lineWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin ) );
  }
  
  p->moveTo( 51, y );

  for (int i=scrollbar->value()+1; i<m_pointer; i++)
  {
    int x = (int)qRound( (i-scrollbar->value())/xfactor ) + 51;
    if (x <= w)
    {
      int y = (int)qRound( 1+(m_scaleMax-(*m_array)[i])/yfactor );

      p->lineTo( x, y );
    }
  }   
}

void
DMMGraph::resizeEvent( QResizeEvent * )
{
  scrollbar->setGeometry( 0, height()-16, width(), 16 );
   
  m_yfactor = createYScale( height()-16, m_ystep );
  m_xfactor = createTimeScale( width(), m_xstep, m_hUnitFact,
                               m_maxUnit, m_hUnit );
}

void
DMMGraph::setGraphSize( int size, int length )
{
  m_size = size/m_sampleTime;
  m_length = length/m_sampleTime + 1;
  
  scrollbar->setMaxValue( m_length-1-m_size );
  scrollbar->setLineStep( (m_size-1)/10 );
  scrollbar->setPageStep( m_size );
  
  m_array->resize( m_length );
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
      }
      m_pointer = m_length-1;
    }

    (*m_array)[m_pointer++] = val;

    bool resFlag = false;

    if (m_autoScale)
    {
      if (val > m_scaleMax*0.95) { m_scaleMax = val*1.2; resFlag = true; }
      if (val < m_scaleMin*0.95) { m_scaleMin = val*1.2; resFlag = true; }
    }
    
    if (resFlag)
      resizeEvent( 0 );

    update();
  }

  emitInfo();
    
  m_sampleCounter++;
  if (m_sampleCounter == m_sampleTime) m_sampleCounter = 0;
  
  if (0 == m_remainingLength)
  {
    qApp->beep();
    stopSLOT();
    return;
  }
  
  m_remainingLength--;
}

double
DMMGraph::createYScale( int h, double & ystep )
{
  double yfactor = (m_scaleMax-m_scaleMin) / (double)(h-1-20);
  
  double idiv = (double)(h-2)/40.;
  double ddiv = (m_scaleMax-m_scaleMin)/idiv;
  
  if (ddiv > 0.001 && ddiv <=0.002 )
  {
    ystep = 0.001;
  }
  else if (ddiv > 0.002 && ddiv <=0.005 )
  {
    ystep = 0.002;
  }
  else if (ddiv > 0.005 && ddiv <=0.01 )
  {
    ystep = 0.005;
  }
  else if (ddiv > 0.01 && ddiv <=0.02 )
  {
    ystep = 0.01;
  }
  else if (ddiv > 0.02 && ddiv <=0.05 )
  {
    ystep = 0.02;
  }
  else if (ddiv > 0.05 && ddiv <=0.1 )
  {
    ystep = 0.05;
  }
  else if (ddiv > 0.1 && ddiv <=0.2 )
  {
    ystep = 0.1;
  }
  else if (ddiv > 0.2 && ddiv <=0.5 )
  {
    ystep = 0.2;
  }
  else if (ddiv > 0.5 && ddiv <=1 )
  {
    ystep = 0.5;
  }
  else if (ddiv > 1 && ddiv <=2 )
  {
    ystep = 1;
  }
  else if (ddiv > 2 && ddiv <=5 )
  {
    ystep = 2;
  }
  else if (ddiv > 5 && ddiv <=10 )
  {
    ystep = 5;
  }
  else if (ddiv > 10 && ddiv <=20 )
  {
    ystep = 10;
  }
  else if (ddiv > 20 && ddiv <=50 )
  {
    ystep = 20;
  }
  else if (ddiv > 50 && ddiv <=100 )
  {
    ystep = 50;
  }
  else if (ddiv > 50 && ddiv <=100 )
  {
    ystep = 50;
  }
  else if (ddiv > 100 && ddiv <=200 )
  {
    ystep = 100;
  }
  else if (ddiv > 200 && ddiv <=500 )
  {
    ystep = 200;
  }
  else if (ddiv > 500 && ddiv <=1000 )
  {
    ystep = 500;
  }
  else if (ddiv > 1000 && ddiv <=2000 )
  {
    ystep = 1000;
  }
  else if (ddiv > 2000 && ddiv <=5000 )
  {
    ystep = 2000;
  }
  else if (ddiv > 5000 && ddiv <=10000 )
  {
    ystep = 5000;
  }
  else
  {
    ystep = 10000;
  }
  
  return yfactor;
}

// returns xfactor
double 
DMMGraph::createTimeScale( int w, double & xstep, double & hUnitFact,
                           double & maxUnit, QString & hUnit )
{
  double xfactor = (double)m_size/(double)(w-52);
  
  double idiv = (double)(w-2-50)/80.;
  double ddiv = m_size*m_sampleTime/idiv;
  
  hUnit = tr( "[sec]" );
  hUnitFact = xfactor*m_sampleTime;
  maxUnit = (m_length-1)*m_sampleTime;
  
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
  
  if (ddiv > 1 && ddiv <=2 )
  {
    xstep = 1;
  }
  else if (ddiv > 2 && ddiv <=5 )
  {
    xstep = 2;
  }
  else if (ddiv > 5 && ddiv <=10 )
  {
    xstep = 5;
  }
  else if (ddiv > 10 && ddiv <=15 )
  {
    xstep = 10;
  }
  else if (ddiv > 15 && ddiv <=30 )
  {
    xstep = 15;
  }
  else if (ddiv > 30 && ddiv <=60 )
  {
    xstep = 30;
  }
  else if (ddiv > 60 && ddiv <=120 )
  {
    xstep = 60;
  }
  else if (ddiv > 120 && ddiv <=180 )
  {
    xstep = 120;
  }
  else if (ddiv > 180 && ddiv <=300 )
  {
    xstep = 180;
  }
  else if (ddiv > 300 && ddiv <=600 )
  {
    xstep = 300;
  }
  else if (ddiv > 600 && ddiv <=1000 )
  {
    xstep = 600;
  }
  else if (ddiv > 1000 && ddiv <=2000 )
  {
    xstep = 1000;
  }
  else if (ddiv > 2000 && ddiv <=5000 )
  {
    xstep = 2000;
  }
  else if (ddiv > 5000 && ddiv <=10000 )
  {
    xstep = 5000;
  }
  else if (ddiv > 10000 && ddiv <=20000 )
  {
    xstep = 10000;
  }
  else
  {
    xstep = 20000;
  }
  
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
  
  QString tmp = m_unit;
  m_unit = "[";
  m_unit += tmp;
  m_unit += "]";
}

void
DMMGraph::clearSLOT()
{
  m_pointer = 0;
  if (m_autoScale)
  {
    m_scaleMin = m_scaleMax = 0;
  }
  
  m_graphStart = QDateTime::currentDateTime();
  m_first = true;
  m_dirty = false;
  
  update();
}

void
DMMGraph::emitInfo()
{
  int h = m_remainingLength / 60 / 60;
  int m = (m_remainingLength / 60 ) % 60;
  int s = m_remainingLength % 60;
  
  QString txt;
  txt.sprintf( "%d/%d - %02d:%02d:%02d - %s", 
               m_pointer, m_length, h, m, s, 
               m_running ? tr( "Sampling" ).latin1() : tr( "Stopped" ).latin1() );
  emit info( txt );
}

void
DMMGraph::mousePressEvent( QMouseEvent *ev )
{
  if (m_scaleMin == m_scaleMax) return;
  if (ev->x() < 51) return;
  
  drawCursor( ev->pos() );
  m_mpos = ev->pos();
  m_mouseDown = true;
  
  m_infoBox->move( ev->globalPos().x()+4, ev->globalPos().y()+4 );
  fillInfoBox( ev->pos() );
  m_infoBox->show();
}

void
DMMGraph::mouseMoveEvent( QMouseEvent *ev )
{
  if (m_scaleMin == m_scaleMax) return;
  if (!m_mouseDown) return;
  
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

void
DMMGraph::mouseReleaseEvent( QMouseEvent * )
{
  if (m_scaleMin == m_scaleMax) return;
  if (!m_mouseDown) return;
  
  drawCursor( m_mpos );
  m_mouseDown = false;
  
  m_infoBox->hide();
}

void
DMMGraph::drawCursor( const QPoint & pos )
{
  QPainter p(this);
  p.setRasterOp( Qt::XorROP );
  p.setPen( Qt::white );
  p.drawLine( pos.x(), 1, pos.x(), height()-20-17 );
}

void
DMMGraph::fillInfoBox( const QPoint & pos )
{
  int x = (int)qRound( (pos.x()-51)*m_xfactor + scrollbar->value() );
  if (x < 0) x = 0;
  int sec = x * m_sampleTime;
  
  QTime t = m_graphStart.time().addSecs( sec );
  QString tmpStr = t.toString();
  
  if (x < m_pointer)
  {
    tmpStr += "\n";
    
    QString tmpVal;
    tmpVal.sprintf( "%g %s", (*m_array)[x], m_unit.latin1() );
    
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
      QDateTime dt = m_graphStart.addSecs( i*m_sampleTime );
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
        QTime startTime = QTime( line.mid( 11, 2 ).toInt(), 
                                 line.mid( 14, 2 ).toInt(),
                                 line.mid( 17, 2 ).toInt() );
        QDate startDate = QDate( line.mid( 6, 4 ).toInt(), 
                                 line.mid( 3, 2 ).toInt(),
                                 line.mid( 0, 2 ).toInt() );

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

          cnt++;

        }
      }
      file.close();
    }
    
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
      setScale( true, 0, 0 );
      
      file.close();
      m_dirty = false;
      update();
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
DMMGraph::setScale( bool autoScale, double min, double max )
{
  m_autoScale = autoScale;
  
  if (!autoScale)
  {
    m_scaleMin = min;
    m_scaleMax = max;
  }
  else
  {
    m_scaleMin = m_scaleMax = 0;
    
    for (int i=0; i<m_pointer; i++)
    {
      double val = (*m_array)[i];
      
      if (val > m_scaleMax*0.95) { m_scaleMax = val*1.2; }
      if (val < m_scaleMin*0.95) { m_scaleMin = val*1.2; }
    }
  }
  
  resizeEvent( 0 );
}

void
DMMGraph::setColors( const QColor & bg, const QColor & grid,
                     const QColor & data, const QColor & cursor )
{
  m_bgColor     = bg;
  m_gridColor   = grid;
  m_dataColor   = data;
  m_cursorColor = cursor;
  
  update();
}

void
DMMGraph::setLine( int w )
{
  m_lineWidth = w;
  
  update();
}
