//======================================================================
// File:		configdlg.cpp
// Author:	Matthias Toussaint
// Created:	Tue Apr 10 17:24:08 CEST 2001
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

#include <configdlg.h>
#include <qdir.h>
#include <qwhatsthis.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qspinbox.h>
#include <qvalidator.h>
#include <qradiobutton.h>

struct DMMInfo dmm_info[] = { {"Metex/Voltcraft ME-32", 0, 0, 7, 2},
                              {"PeakTech-451", 1, 1, 7, 2},
                              { "",0,0,0,0} };
                      
ConfigDlg::ConfigDlg( QWidget *parent, const char *name ) :
  UIConfigDlg( parent, name, true )
{
  QString path = QDir::homeDirPath();
  path += "/.qtdmmrc";
  
  m_cfg = new SimpleCfg( path );
  cancelSLOT();
  
  QDoubleValidator *dval = new QDoubleValidator( -99999.9, 99999.9, 5, this );
  scaleMinEd->setValidator( dval );
  scaleMaxEd->setValidator( dval );
  
  QIntValidator *ival = new QIntValidator( 1, 99999, this );
  winSize->setValidator( ival );
  winLength->setValidator( ival );
  sampleEvery->setValidator( ival );
  sampleTime->setValidator( ival );
  
  connect( helpBut, SIGNAL( clicked() ), this, SLOT( helpSLOT() ));
  connect( okBut, SIGNAL( clicked() ), this, SLOT( applySLOT() ));
  connect( cancelBut, SIGNAL( clicked() ), this, SLOT( cancelSLOT() ));
  
  modelCombo->clear();
  modelCombo->insertItem( "Manual settings" );
  
  int id = 0;
  while (*dmm_info[id].name)
  {
    modelCombo->insertItem( dmm_info[id++].name );
  }
  
  connect( modelCombo, SIGNAL( activated( int ) ),
           this, SLOT( modelSLOT( int )));
}

ConfigDlg::~ConfigDlg()
{
}

void
ConfigDlg::applySLOT()
{
  m_cfg->clear();
  
  m_cfg->setInt( "Sample", "rate", sampleEvery->text().toInt() );
  m_cfg->setInt( "Sample", "rate-unit", sampleUnit->currentItem() );
  m_cfg->setInt( "Sample", "time", sampleTime->text().toInt() );
  m_cfg->setInt( "Sample", "time-unit", timeUnit->currentItem() );
  
  m_cfg->setInt( "Start", "mode", sampleMode() );
  m_cfg->setInt( "Start", "hour", hour->value() );
  m_cfg->setInt( "Start", "minute", minute->value() );
  m_cfg->setInt( "Start", "second", second->value() );
  m_cfg->setInt( "Start", "raising-threshold", raisingThreshold() );
  m_cfg->setInt( "Start", "falling-threshold", fallingThreshold() );
  
  m_cfg->setBool( "Scale", "automatic", automaticScale() );
  m_cfg->setDouble( "Scale", "minimum", scaleMin() );
  m_cfg->setDouble( "Scale", "maximum", scaleMax() );
  
  m_cfg->setInt( "Window", "size", winSize->text().toInt() );
  m_cfg->setInt( "Window", "size-unit", sizeUnit->currentItem() );
  m_cfg->setInt( "Window", "length", winLength->text().toInt() );
  m_cfg->setInt( "Window", "length-unit", lengthUnit->currentItem() );
  
  m_cfg->setInt( "Port settings", "device", port->currentItem() );
  m_cfg->setInt( "Port settings", "baud", baudRate->currentItem() );
  m_cfg->setInt( "Port settings", "bits", bitsCombo->currentItem()+5 );
  m_cfg->setInt( "Port settings", "stop-bits", stopBitsCombo->currentItem()+1 );
  
  m_cfg->setInt( "DMM", "data-format", protocolCombo->currentItem() );
  
  m_cfg->save();
}

void
ConfigDlg::cancelSLOT()
{
  m_cfg->clear();
  m_cfg->load();
  
  sampleEvery->setText( m_cfg->getString( "Sample", "rate", "1" ));
  sampleUnit->setCurrentItem( m_cfg->getInt( "Sample", "rate-unit", 0 ));
  sampleTime->setText( m_cfg->getString( "Sample", "time", "500" ));
  timeUnit->setCurrentItem( m_cfg->getInt( "Sample", "time-unit", 0 ));
  
  DMMGraph::SampleMode mode = (DMMGraph::SampleMode)m_cfg->getInt( "Start", "mode", 0 );
  if (mode == DMMGraph::Manual)
  {
    manualBut->setChecked( true );
  }
  else if (mode == DMMGraph::Time)
  {
    predefinedBut->setChecked( true );
  }
  if (mode == DMMGraph::Raising)
  {
    triggerBut->setChecked( true );
    raisingBut->setChecked( true );
  }
  if (mode == DMMGraph::Falling)
  {
    triggerBut->setChecked( true );
    fallingBut->setChecked( true );
  }
  
  hour->setValue( m_cfg->getInt( "Start", "hour", 0 ));
  minute->setValue( m_cfg->getInt( "Start", "minute", 0 ));
  second->setValue( m_cfg->getInt( "Start", "second", 0 ));
  raisingThresholdEdit->setText( m_cfg->getString( "Start", "raising-threshold", "0.0" ));
  fallingThresholdEdit->setText( m_cfg->getString( "Start", "falling-threshold", "0.0" ));
  
  bool autoScale = m_cfg->getBool( "Scale", "automatic", true );
  if (autoScale)
  {
    autoScaleBut->setChecked( true );
  }
  else
  {
    manualScaleBut->setChecked( true );
  }
  
  scaleMinEd->setText( m_cfg->getString( "Scale", "minimum", "-3.999" ));
  scaleMaxEd->setText( m_cfg->getString( "Scale", "maximum", "3.999" ));
  
  winSize->setText( m_cfg->getString( "Window", "size", "3600" ));
  sizeUnit->setCurrentItem( m_cfg->getInt( "Window", "size-unit", 0 ));
  winLength->setText( m_cfg->getString( "Window", "length", "600" ));
  lengthUnit->setCurrentItem( m_cfg->getInt( "Window", "length-unit", 0 ));

  port->setCurrentItem( m_cfg->getInt( "Port settings", "device", 0 ) );
  baudRate->setCurrentItem( m_cfg->getInt( "Port settings", "baud", 0 ) );
  bitsCombo->setCurrentItem( m_cfg->getInt( "Port settings", "bits", 7 )-5 );
  stopBitsCombo->setCurrentItem( m_cfg->getInt( "Port settings", "stop-bits", 2 )-1);
  
  protocolCombo->setCurrentItem( m_cfg->getInt( "DMM", "data-format", 0 ));

}

void
ConfigDlg::helpSLOT()
{
  QWhatsThis::enterWhatsThisMode();
}

int
ConfigDlg::speed() const
{
  switch (baudRate->currentItem())
  {
  case 0:
    return 600;
  case 1:
    return 1200;
  case 2:
    return 1800;
  case 3:
    return 2400;
  case 4:
    return 4800;
  case 5:
    return 9600;
  }
  
  return 600;
}

int
ConfigDlg::windowSeconds() const
{
  int sec = winSize->text().toInt();
  
  switch (sizeUnit->currentItem())
  {
  case 1:
    sec *= 60;
    break;
  case 2:
    sec *= 60*60;
    break;
  case 3:
    sec *= 60*60*24;
    break;
  }
  
  return sec;
}

int
ConfigDlg::totalSeconds() const
{
  int sec = winLength->text().toInt();
  
  switch (lengthUnit->currentItem())
  {
  case 1:
    sec *= 60;
    break;
  case 2:
    sec *= 60*60;
    break;
  case 3:
    sec *= 60*60*24;
    break;
  }
  
  return sec;
}

QTime
ConfigDlg::startTime() const
{
  QTime time( hour->value(), minute->value(), second->value() );
  
  return time;
}

DMMGraph::SampleMode
ConfigDlg::sampleMode() const
{
  if (predefinedBut->isChecked())
  {
    return DMMGraph::Time;
  }
  if (triggerBut->isChecked())
  {
    if (raisingBut->isChecked())
    {
      return DMMGraph::Raising;
    }
      
    return DMMGraph::Falling;
  }
  
  return DMMGraph::Manual;
}

int
ConfigDlg::sampleStep() const
{
  int sec = sampleEvery->text().toInt();
  
  switch (sampleUnit->currentItem())
  {
  case 1:
    sec *= 60;
    break;
  case 2:
    sec *= 60*60;
    break;
  case 3:
    sec *= 60*60*24;
    break;
  }
  
  return sec;
}

int
ConfigDlg::sampleLength() const
{
  int sec = sampleTime->text().toInt();
  
  switch (timeUnit->currentItem())
  {
  case 1:
    sec *= 60;
    break;
  case 2:
    sec *= 60*60;
    break;
  case 3:
    sec *= 60*60*24;
    break;
  }
  
  return sec;
}

double
ConfigDlg::fallingThreshold() const
{
  return fallingThresholdEdit->text().toDouble();
}

double
ConfigDlg::raisingThreshold() const
{
  return raisingThresholdEdit->text().toDouble();
}

double
ConfigDlg::scaleMin() const
{
  return scaleMinEd->text().toDouble();
}

double
ConfigDlg::scaleMax() const
{
  return scaleMaxEd->text().toDouble();
}

bool 
ConfigDlg::automaticScale() const
{
  return autoScaleBut->isChecked();
}

ReadEvent::DataFormat
ConfigDlg::format() const
{
  if (1 == protocolCombo->currentItem())
  {
    return ReadEvent::PeakTech10;
  }
  
  return ReadEvent::Metex14;
}

void
ConfigDlg::modelSLOT( int id )
{
  baudRate->setDisabled( id != 0 );
  protocolCombo->setDisabled( id != 0 );
  bitsCombo->setDisabled( id != 0 );
  stopBitsCombo->setDisabled( id != 0 );
  if (id != 0) message->hide();
  else         message->show();
  
  baudRate->setCurrentItem( dmm_info[id-1].baud );
  protocolCombo->setCurrentItem( dmm_info[id-1].protocol );
  bitsCombo->setCurrentItem( dmm_info[id-1].bits-5 );
  stopBitsCombo->setCurrentItem( dmm_info[id-1].stopBits-1 );
}

int
ConfigDlg::bits() const
{
  return 5+bitsCombo->currentItem();
}

int
ConfigDlg::stopBits() const
{
  return 1+stopBitsCombo->currentItem();
}

