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

MainWid::MainWid( QWidget *parent, const char *name ) :
  UIMainWid( parent, name )
{
  m_dmm = new DMM( this );
  m_configDlg = new ConfigDlg( this );
  m_configDlg->hide();
  m_printDlg = new PrintDlg( this );
  m_printDlg->hide();
  
  connect( m_dmm, SIGNAL( value( double, const QString &, 
                                 const QString &, const QString & )),
           this,  SLOT( valueSLOT( double, const QString &, 
                                   const QString &, const QString & )));
  connect( resetBut, SIGNAL( clicked() ), this, SLOT( resetSLOT() ));
  connect( m_dmm, SIGNAL( error( const QString & ) ),
           statusBar, SLOT( setText( const QString & )));
  connect( connectBut, SIGNAL( toggled( bool )),
           this, SLOT( connectSLOT( bool ) ));
  connect( quitBut, SIGNAL( clicked() ),
           this, SLOT( quitSLOT() ));
  connect( helpBut, SIGNAL( clicked() ),
           this, SLOT( helpSLOT() ));
  connect( configBut, SIGNAL( clicked() ),
           this, SLOT( configSLOT() ));
  connect( printBut, SIGNAL( clicked() ),
           this, SLOT( printSLOT() ));
  connect( exportBut, SIGNAL( clicked() ),
           graph, SLOT( exportDataSLOT() ));
  connect( clearBut, SIGNAL( clicked() ),
           graph, SLOT( clearSLOT() ));
  connect( startBut, SIGNAL( clicked() ),
           graph, SLOT( startSLOT() ));
  connect( stopBut, SIGNAL( clicked() ),
           graph, SLOT( stopSLOT() ));
  connect( graph, SIGNAL( info( const QString & ) ),
           infoLabel, SLOT( setText( const QString & ) ));
  connect( graph, SIGNAL( running( bool ) ),
           this, SLOT( runningSLOT( bool ) ));
  
  resetSLOT();
  readConfig();
}

MainWid::~MainWid()
{
}

void
MainWid::valueSLOT( double dval,
                    const QString & val, const QString & u, const QString & s )
{
  value->setText( val );
  
  if (m_lastUnit != s)
  {
    resetSLOT();
    graph->setUnit( u );
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
    maxValue->setText( val );
    maxUnit->setText( u );
  }
  
  if (dval < m_min)
  {
    m_min = dval;  
    minValue->setText( val );
    minUnit->setText( u );
  }
  
  unit->setText( tmpUnit );
  
  graph->addValue( dval );
}

void
MainWid::resetSLOT()
{
  m_min =  1.0E9;
  m_max = -1.0E9;
  
  minValue->setText( "" );
  maxValue->setText( "" );
  minUnit->setText( "" );
  maxUnit->setText( "" );
}

void
MainWid::connectSLOT( bool on )
{
  if (on)
  {
    m_dmm->open();
    graph->clearSLOT();
    startBut->setEnabled( true );
  }
  else
  {
    m_dmm->close();
    graph->stopSLOT();
    startBut->setEnabled( false );
  }
}

void
MainWid::quitSLOT()
{
  m_dmm->close();
  qApp->quit();
}

void
MainWid::helpSLOT()
{
  QWhatsThis::enterWhatsThisMode();
}

void
MainWid::configSLOT()
{
  if (m_configDlg->exec())
  {
    readConfig();
  }
}

void
MainWid::printSLOT()
{
  m_printDlg->setPrinter( &m_printer );
  
  if (m_printDlg->exec())
  {
    graph->print( &m_printer, m_printDlg->title(), m_printDlg->comment() );
  }
}

void
MainWid::readConfig()
{
  m_dmm->setDevice( m_configDlg->device() );
  m_dmm->setSpeed( m_configDlg->speed() );
  m_dmm->setFormat( m_configDlg->format() );
  m_dmm->setPortSettings( m_configDlg->bits(), m_configDlg->stopBits() );
  
  graph->setGraphSize( m_configDlg->windowSeconds(),
                       m_configDlg->totalSeconds() );
  graph->setStartTime( m_configDlg->startTime() );
  graph->setMode( m_configDlg->sampleMode() );
  
  graph->setSampleTime( m_configDlg->sampleStep() );
  graph->setSampleLength( m_configDlg->sampleLength() );
  
  graph->setThresholds( m_configDlg->fallingThreshold(), 
                        m_configDlg->raisingThreshold() );
  
  graph->setScale( m_configDlg->automaticScale(), 
                   m_configDlg->scaleMin(),
                   m_configDlg->scaleMax() );
  
  if (m_configDlg->sampleMode() == DMMGraph::Time)
  {
    QString txt;
    txt.sprintf( "%s %s", tr( "Automatic start at" ).latin1(),
        m_configDlg->startTime().toString().latin1() );
    infoLabel->setText( txt );
  }
  else if (m_configDlg->sampleMode() == DMMGraph::Raising)
  {
    QString txt;
    txt.sprintf( "%s %g", tr( "Raising threshold" ).latin1(),
        m_configDlg->raisingThreshold() );
    infoLabel->setText( txt );
  }
  else if (m_configDlg->sampleMode() == DMMGraph::Falling)
  {
    QString txt;
    txt.sprintf( "%s %g", tr( "Falling threshold" ).latin1(),
        m_configDlg->fallingThreshold() );
    infoLabel->setText( txt );
  }
}

void
MainWid::runningSLOT( bool on )
{
  startBut->setEnabled( !on );
  stopBut->setEnabled( on );
  printBut->setEnabled( !on );
  exportBut->setEnabled( !on );
}
