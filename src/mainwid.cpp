//======================================================================
// File:		mainwid.cpp
// Author:	Matthias Toussaint
// Created:	Tue Apr 10 17:29:01 CEST 2001
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

#include <mainwid.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qapplication.h>
#include <qwhatsthis.h>
#include <dmmgraph.h>
#include <qpixmap.h>
#include <qmessagebox.h>
#include <configdlg.h>

#include <icon.xpm>

#include <iostream.h>

MainWid::MainWid( QWidget *parent, const char *name ) :
  UIMainWid( parent, name )
{
  setIcon( QPixmap((const char **)icon_xpm ) );
  
  m_dmm = new DMM( this );
  
  m_configDlg = new ConfigDlg( 0 );
  m_configDlg->hide();
  
  m_configDlg->readPrinter( &m_printer );
  
  m_printDlg = new PrintDlg( this );
  m_printDlg->hide();
  
  connect( m_dmm, SIGNAL( value( double, const QString &, 
                                 const QString &, const QString & )),
           this,  SLOT( valueSLOT( double, const QString &, 
                                   const QString &, const QString & )));
  connect( m_dmm, SIGNAL( error( const QString & ) ),
           this, SIGNAL( error( const QString & )));
  connect( ui_graph, SIGNAL( info( const QString & ) ),
           this, SIGNAL( info( const QString & ) ));
  connect( ui_graph, SIGNAL( error( const QString & ) ),
           this, SIGNAL( error( const QString & ) ));
  connect( ui_graph, SIGNAL( running( bool ) ),
           this, SLOT( runningSLOT( bool ) ));
  connect( m_configDlg, SIGNAL( accepted() ),
           this, SLOT( applySLOT() ));
  connect( ui_graph, SIGNAL( sampleTime( int ) ),
           m_configDlg, SLOT( setSampleTimeSLOT( int ) ));
  connect( ui_graph, SIGNAL( graphSize( int,int ) ),
           m_configDlg, SLOT( setGraphSizeSLOT( int,int ) ));
  
  resetSLOT();
  
}

MainWid::~MainWid()
{
}

bool
MainWid::closeWin()
{
  m_dmm->close();
  m_configDlg->setWinRect( parentRect() );
  m_configDlg->applySLOT();
  
  emit setConnect( false );
  
  if (ui_graph->dirty() && m_configDlg->alertUnsavedData())
  {
    QMessageBox question( tr("QtDMM: Unsaved data" ),
                          tr("<font size=+2><b>Unsaved data</b></font><p>"
                             "You still have unsaved measured data in memory."
                             " If you quit now it will be lost."
                             "<p>Do you want to export your unsaved data first?" ),
                             QMessageBox::Information,
                             QMessageBox::Yes | QMessageBox::Default,
                             QMessageBox::No,
                             QMessageBox::Cancel | QMessageBox::Escape );
    
    question.setButtonText( QMessageBox::Yes, tr("Export data first") );
    question.setButtonText( QMessageBox::No, tr("Quit without saving") );
    question.setIconPixmap( QPixmap((const char **)icon_xpm ) );
    
    switch (question.exec())
    {
    case QMessageBox::Yes:
      ui_graph->exportDataSLOT();
      break;
      
    case QMessageBox::No:
      break;
      
    case QMessageBox::Cancel:
      return false;
    }
  }
  
  return true;
}

QRect
MainWid::winRect() const
{ 
  if (m_configDlg->saveWindowPosition())
  {
    return m_configDlg->winRect();
  }
  
  return QRect();
}

QRect
MainWid::parentRect() const
{
  QRect fRect = parentWidget()->frameGeometry();
  QRect rect  = parentWidget()->rect();
  
  return QRect( fRect.x(), fRect.y(), rect.width(), rect.height() ); 
}

void
MainWid::valueSLOT( double dval,
                    const QString & val, const QString & u, const QString & s )
{
  ui_value->setText( val );
  
  if (m_lastUnit != s)
  {
    resetSLOT();
    ui_graph->setUnit( u );
  }
  m_lastUnit = s;
  
  QString tmpUnit = u;
  
  if (s == "AC ")
  {
    tmpUnit += " AC";
  }
  
  if (dval > m_max)
  {
    m_max = dval;  
    ui_maxValue->setText( val );
    ui_maxUnit->setText( u );
  }
  
  if (dval < m_min)
  {
    m_min = dval;  
    ui_minValue->setText( val );
    ui_minUnit->setText( u );
  }
  
  ui_unit->setText( tmpUnit );
  
  ui_graph->addValue( dval );
}

void
MainWid::resetSLOT()
{
  m_min =  1.0E9;
  m_max = -1.0E9;
  
  ui_minValue->setText( "" );
  ui_maxValue->setText( "" );
  ui_minUnit->setText( "" );
  ui_maxUnit->setText( "" );
}

void
MainWid::connectSLOT( bool on )
{
  if (on)
  {
    m_dmm->open();
    ui_graph->clearSLOT();
  }
  else
  {
    m_dmm->close();
    ui_graph->stopSLOT();
  }
  
  m_configDlg->connectSLOT( on );
}

void
MainWid::quitSLOT()
{
  if (closeWin()) qApp->quit();
}

void
MainWid::helpSLOT()
{
  QWhatsThis::enterWhatsThisMode();
}

void
MainWid::configSLOT()
{
  m_configDlg->show();
}

void
MainWid::applySLOT()
{
  readConfig();
  
  ui_graph->setAlertUnsaved( m_configDlg->alertUnsavedData() );
}

void
MainWid::exportSLOT()
{
  ui_graph->exportDataSLOT();
}

void
MainWid::importSLOT()
{
  ui_graph->importDataSLOT();
}

void
MainWid::printSLOT()
{
  m_printDlg->setPrinter( &m_printer );
  
  if (m_printDlg->exec())
  {
    m_configDlg->writePrinter( &m_printer );
    ui_graph->print( &m_printer, m_printDlg->title(), m_printDlg->comment() );    
  }
}

void
MainWid::clearSLOT()
{
  ui_graph->clearSLOT();
}

void
MainWid::startSLOT()
{
  ui_graph->startSLOT();
}

void
MainWid::stopSLOT()
{
  ui_graph->stopSLOT();
}

void
MainWid::readConfig()
{
  m_dmm->setDevice( m_configDlg->device() );
  m_dmm->setSpeed( m_configDlg->speed() );
  m_dmm->setFormat( m_configDlg->format() );
  m_dmm->setPortSettings( m_configDlg->bits(), m_configDlg->stopBits() );
  
  ui_graph->setGraphSize( m_configDlg->windowSeconds(),
                          m_configDlg->totalSeconds() );
  ui_graph->setStartTime( m_configDlg->startTime() );
  ui_graph->setMode( m_configDlg->sampleMode() );
  
  ui_graph->setSampleTime( m_configDlg->sampleStep() );
  ui_graph->setSampleLength( m_configDlg->sampleLength() );
  
  ui_graph->setThresholds( m_configDlg->fallingThreshold(), 
                           m_configDlg->raisingThreshold() );
  
  ui_graph->setScale( m_configDlg->automaticScale(), 
                      m_configDlg->scaleMin(),
                      m_configDlg->scaleMax() );
  
  ui_graph->setColors( m_configDlg->bgColor(), 
                       m_configDlg->gridColor(),
                       m_configDlg->dataColor(),
                       m_configDlg->cursorColor() );
  
  QColorGroup cg = colorGroup();
  cg.setColor( QColorGroup::Background, m_configDlg->displayBgColor() );
  cg.setColor( QColorGroup::Foreground, m_configDlg->displayTextColor() );
  
  ui_displayFrame->setPalette( QPalette( cg, cg, cg ) );
  ui_minValue->setPalette( QPalette( cg, cg, cg ) );
  ui_minUnit->setPalette( QPalette( cg, cg, cg ) );
  ui_maxUnit->setPalette( QPalette( cg, cg, cg ) );
  ui_label1->setPalette( QPalette( cg, cg, cg ) );
  ui_label2->setPalette( QPalette( cg, cg, cg ) );
  ui_value->setPalette( QPalette( cg, cg, cg ) );
  ui_unit->setPalette( QPalette( cg, cg, cg ) );
  ui_label2->setPalette( QPalette( cg, cg, cg ) );
  ui_maxValue->setPalette( QPalette( cg, cg, cg ) );
      
  ui_graph->setLine( m_configDlg->lineWidth() );
  
  if (m_configDlg->sampleMode() == DMMGraph::Time)
  {
    QString txt;
    txt.sprintf( "%s %s", tr( "Automatic start at" ).latin1(),
        m_configDlg->startTime().toString().latin1() );
    
    emit info( txt );
  }
  else if (m_configDlg->sampleMode() == DMMGraph::Raising)
  {
    QString txt;
    txt.sprintf( "%s %g", tr( "Raising threshold" ).latin1(),
        m_configDlg->raisingThreshold() );
    
    emit info( txt );
  }
  else if (m_configDlg->sampleMode() == DMMGraph::Falling)
  {
    QString txt;
    txt.sprintf( "%s %g", tr( "Falling threshold" ).latin1(),
        m_configDlg->fallingThreshold() );
    
    emit info( txt );
  }
  
  emit useTextLabel( m_configDlg->useTextLabel() );
}

void
MainWid::runningSLOT( bool on )
{
  emit running( on );
}
