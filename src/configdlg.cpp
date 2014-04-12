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
#include <qbuttongroup.h>
#include <qtextview.h>
#include <qcheckbox.h>
#include <colorbutton.h>
#include <qcolordialog.h>
#include <qmessagebox.h>
#include <qprinter.h>

#include <icon.xpm>

#define MINUTE_SECS   60
#define HOUR_SECS     60*60
#define DAY_SECS      60*60*24

// when all needed parameter are found this hardcoded version will
// be replaced by a file
struct DMMInfo dmm_info[] = { 
                              {"22-805 Radioshack DMM", 0, 0, 7, 2, 0},
                              {"Metex/Voltcraft ME-11", 0, 0, 7, 2, 0},
                              {"Metex/Voltcraft ME-32", 0, 0, 7, 2, 0},
                              {"PeakTech-451", 0, 0, 7, 2, 0},
                              {"Voltcraft M-4660", 1, 0, 7, 2, 3},
                              {"Voltcraft ME-22T", 3, 0, 7, 2, 0},
                              {"",0,0,0,0,0} 
                            };
                      
ConfigDlg::ConfigDlg( QWidget *parent, const char *name ) :
  UIConfigDlg( parent, name, false )
{
  QString path = QDir::homeDirPath();
  path += "/.qtdmmrc";
  
  m_cfg = new SimpleCfg( path );
  m_cfg->setComment( "#####################################################################\n"
                     "# This file was automagically created by QtDMM a simple DMM readout #\n"
                     "# software. QtDMM is copyright  by Matthias Toussaint. Don't change #\n"
                     "# this file unless you know what you are doing.                     #\n"
                     "#                                                                   #\n"
                     "# Contact: qtdmm@mtoussaint.de                                      #\n"
                     "#####################################################################\n\n" );
      
  // Check if configuration file exists. If not welcome user
  //
  QFile cfg( path );
  if (!cfg.exists())
  {
    QMessageBox welcome( tr("QtDMM: Welcome!" ),
                         tr("<font size=+2><b>Welcome!</b></font><p>"
                            "This seems to be your first invocation of QtDMM "
                            "(Or you have deleted it's configuration file).<p>QtDMM"
                            " has created the file ~/.qtdmmrc in your home directory"
                            " to save its settings."),
                         QMessageBox::Information,
                         QMessageBox::Yes | QMessageBox::Default,
                         QMessageBox::NoButton,
                         QMessageBox::NoButton );
                                 
    welcome.setButtonText( QMessageBox::Yes, tr("Continue") );
    welcome.setIconPixmap( QPixmap((const char **)icon_xpm ) );
    welcome.exec();
    
    m_cfg->save();
  }
        
  QDoubleValidator *dval = new QDoubleValidator( -99999.9, 99999.9, 5, this );
  scaleMinEd->setValidator( dval );
  scaleMaxEd->setValidator( dval );
  
  /*QIntValidator *ival = new QIntValidator( 1, 99999, this );
  winSize->setValidator( ival );
  winLength->setValidator( ival );
  sampleEvery->setValidator( ival );
  sampleTime->setValidator( ival );*/
  
  connect( helpBut, SIGNAL( clicked() ), this, SLOT( helpSLOT() ));
  connect( okBut, SIGNAL( clicked() ), this, SLOT( applySLOT() ));
  connect( ui_applyBut, SIGNAL( clicked() ), this, SLOT( applySLOT() ));
  connect( cancelBut, SIGNAL( clicked() ), this, SLOT( cancelSLOT() ));
  
  connect( ui_defaultRecorder, SIGNAL( clicked() ),
           this, SLOT( recorderDefaultSLOT() ));
  connect( ui_factoryRecorder, SIGNAL( clicked() ),
           this, SLOT( recorderFactorySLOT() ));
  connect( ui_defaultScale, SIGNAL( clicked() ),
           this, SLOT( scaleDefaultSLOT() ));
  connect( ui_factoryScale, SIGNAL( clicked() ),
           this, SLOT( scaleFactorySLOT() ));
  connect( ui_defaultDMM, SIGNAL( clicked() ),
           this, SLOT( dmmDefaultSLOT() ));
  connect( ui_factoryDMM, SIGNAL( clicked() ),
           this, SLOT( dmmFactorySLOT() ));
  connect( ui_defaultPreferences, SIGNAL( clicked() ),
           this, SLOT( preferencesDefaultSLOT() ));
  connect( ui_factoryPreferences, SIGNAL( clicked() ),
           this, SLOT( preferencesFactorySLOT() ));
  
  ui_defaultRecorder->hide();
  ui_defaultScale->hide();
  ui_defaultDMM->hide();
  ui_defaultPreferences->hide();
      
  modelCombo->clear();
  modelCombo->insertItem( "Manual settings" );
  
  int id = 0;
  while (*dmm_info[id].name)
  {
    modelCombo->insertItem( dmm_info[id++].name );
  }

  connect( modelCombo, SIGNAL( activated( int ) ),
           this, SLOT( modelSLOT( int )));
  
  cancelSLOT();
  
}

ConfigDlg::~ConfigDlg()
{
}

void
ConfigDlg::setWinRect( const QRect & rect )
{
  m_winRect = rect; 
}

QRect
ConfigDlg::winRect() const
{
  QRect rect( m_cfg->getInt( "Position", "x", 0 ),
              m_cfg->getInt( "Position", "y", 0 ),
              m_cfg->getInt( "Position", "width", 500 ),
              m_cfg->getInt( "Position", "height", 350 ) );
             
  return rect;
}

void
ConfigDlg::connectSLOT( bool connected )
{
  okBut->setDisabled( connected );
  ui_applyBut->setDisabled( connected );
}

void
ConfigDlg::applySLOT()
{
  m_cfg->clear();
  
  m_cfg->setInt( "Sample", "rate", sampleEvery->value() );
  m_cfg->setInt( "Sample", "rate-unit", sampleUnit->currentItem() );
  m_cfg->setInt( "Sample", "time", sampleTime->value() );
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
  
  m_cfg->setInt( "Window", "size", winSize->value() );
  m_cfg->setInt( "Window", "size-unit", sizeUnit->currentItem() );
  m_cfg->setInt( "Window", "length", winLength->value() );
  m_cfg->setInt( "Window", "length-unit", lengthUnit->currentItem() );
  
  m_cfg->setInt( "Port settings", "device", port->currentItem() );
  m_cfg->setInt( "Port settings", "baud", baudRate->currentItem() );
  m_cfg->setInt( "Port settings", "bits", bitsCombo->currentItem()+5 );
  m_cfg->setInt( "Port settings", "stop-bits", stopBitsCombo->currentItem()+1 );
  
  m_cfg->setInt( "DMM", "data-format", protocolCombo->currentItem() );
  m_cfg->setInt( "DMM", "ignore-lines", ignoreSpin->value() );
  m_cfg->setInt( "DMM", "model", modelCombo->currentItem() );
  
  m_cfg->setBool( "Save", "window", ui_saveWindowCheck->isChecked() );
  
  m_cfg->setRGB( "Graph", "background", ui_bgColor->color().rgb() );
  m_cfg->setRGB( "Graph", "grid", ui_gridColor->color().rgb() );
  m_cfg->setRGB( "Graph", "data", ui_dataColor->color().rgb() );
  m_cfg->setRGB( "Graph", "cursor", ui_cursorColor->color().rgb() );
  m_cfg->setInt( "Graph", "line-width", ui_lineWidth->value() );

  m_cfg->setRGB( "Graph", "display-background", ui_bgColorDisplay->color().rgb() );
  m_cfg->setRGB( "Graph", "display-text", ui_textColor->color().rgb() );
  
  m_cfg->setInt( "Custom colors", "count", QColorDialog::customCount() );
  
  m_cfg->setInt( "Printer", "page-size", (int)m_printer->pageSize() );
  m_cfg->setInt( "Printer", "page-orientation", (int)m_printer->orientation() );
  m_cfg->setInt( "Printer", "color", (int)m_printer->colorMode() );
  m_cfg->setString( "Printer", "name", m_printer->printerName() );
  m_cfg->setString( "Printer", "filename", m_printer->outputFileName() );
  m_cfg->setBool( "Printer", "print-file", m_printer->outputToFile() );
  
  m_cfg->setBool( "Alert", "unsaved-file", alertUnsavedData() );
  
  m_cfg->setBool( "Icons", "text-label", useTextLabel() );
  
  for (int i=0; i<QColorDialog::customCount(); i++)
  {
    QString color;
    color.sprintf( "color_%d", i );
    m_cfg->setRGB( "Custom colors", color, QColorDialog::customColor( i ) );
  }
  
  if (saveWindowPosition())
  {    
    m_cfg->setInt( "Position", "x", m_winRect.x() );
    m_cfg->setInt( "Position", "y", m_winRect.y() );
    m_cfg->setInt( "Position", "width", m_winRect.width() );
    m_cfg->setInt( "Position", "height", m_winRect.height() );
  }
  else
  {
    m_cfg->remove( "Position" );
  }
  
  m_cfg->save();
  
  emit accepted();
  
  if (sender() == okBut)
  {
    hide();
  }
}

void
ConfigDlg::writePrinter( QPrinter * printer )
{
  m_printer = printer; 
  
  applySLOT();
}

void
ConfigDlg::readPrinter( QPrinter * printer )
{
  m_printer = printer; 
  
  m_printer->setPageSize( (QPrinter::PageSize) m_cfg->getInt( "Printer", "page-size", 0 ) );
  m_printer->setOrientation( (QPrinter::Orientation) m_cfg->getInt( "Printer", "page-orientation", 0 ) );
  m_printer->setColorMode( (QPrinter::ColorMode) m_cfg->getInt( "Printer", "color", 1 ) );
  m_printer->setPrinterName( m_cfg->getString( "Printer", "name", "lp" ) ); 
  m_printer->setOutputFileName( m_cfg->getString( "Printer", "filename", "" ) ); 
  m_printer->setOutputToFile( m_cfg->getBool( "Printer", "print-file", false ) ); 
}

void
ConfigDlg::recorderDefaultSLOT()
{
  sampleEvery->setValue( m_cfg->getInt( "Sample", "rate", 1 ));
  sampleUnit->setCurrentItem( m_cfg->getInt( "Sample", "rate-unit", 0 ));
  sampleTime->setValue( m_cfg->getInt( "Sample", "time", 500 ));
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
}

void
ConfigDlg::recorderFactorySLOT()
{
  sampleEvery->setValue( 1 );
  sampleUnit->setCurrentItem( 0 );
  sampleTime->setValue( 500 );
  timeUnit->setCurrentItem( 0 );
  
  manualBut->setChecked( true );
  
  hour->setValue( 0 );
  minute->setValue( 0 );
  second->setValue( 0 );
  raisingThresholdEdit->setText( "0.0" );
  fallingThresholdEdit->setText( "0.0" );
}

void
ConfigDlg::scaleDefaultSLOT()
{
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
  
  winSize->setValue( m_cfg->getInt( "Window", "size", 600 ));
  sizeUnit->setCurrentItem( m_cfg->getInt( "Window", "size-unit", 0 ));
  winLength->setValue( m_cfg->getInt( "Window", "length", 3600 ));
  lengthUnit->setCurrentItem( m_cfg->getInt( "Window", "length-unit", 0 ));
}

void
ConfigDlg::scaleFactorySLOT()
{
  autoScaleBut->setChecked( true );

  scaleMinEd->setText( "-3.999" );
  scaleMaxEd->setText( "3.999" );
  
  winSize->setValue( 600 );
  sizeUnit->setCurrentItem( 0 );
  winLength->setValue( 3600 );
  lengthUnit->setCurrentItem( 0 );
}

void
ConfigDlg::dmmDefaultSLOT()
{
  port->setCurrentItem( m_cfg->getInt( "Port settings", "device", 0 ) );
  baudRate->setCurrentItem( m_cfg->getInt( "Port settings", "baud", 0 ) );
  bitsCombo->setCurrentItem( m_cfg->getInt( "Port settings", "bits", 7 )-5 );
  stopBitsCombo->setCurrentItem( m_cfg->getInt( "Port settings", "stop-bits", 2 )-1);
  
  protocolCombo->setCurrentItem( m_cfg->getInt( "DMM", "data-format", 0 ));
  ignoreSpin->setValue( m_cfg->getInt( "DMM", "ignore-lines", 0 ));
  modelCombo->setCurrentItem( m_cfg->getInt( "DMM", "model", 0 ));
  
  modelSLOT( modelCombo->currentItem() );
}

void
ConfigDlg::dmmFactorySLOT()
{
  port->setCurrentItem( 0 );
  baudRate->setCurrentItem( 0 );
  bitsCombo->setCurrentItem( 2 );
  stopBitsCombo->setCurrentItem( 1 );
  
  protocolCombo->setCurrentItem( 0 );
  ignoreSpin->setValue( 0 );
  modelCombo->setCurrentItem( 0 );
  
  modelSLOT( modelCombo->currentItem() );
}

void
ConfigDlg::preferencesDefaultSLOT()
{
  ui_saveWindowCheck->setChecked( m_cfg->getBool( "Save", "window", true ));
  
  ui_bgColor->setColor( QColor( m_cfg->getRGB( "Graph", "background", Qt::white.rgb() )));
  ui_gridColor->setColor( QColor( m_cfg->getRGB( "Graph", "grid", Qt::gray.rgb() )));
  ui_dataColor->setColor( QColor( m_cfg->getRGB( "Graph", "data", Qt::blue.rgb() )));
  ui_cursorColor->setColor( QColor( m_cfg->getRGB( "Graph", "cursor", Qt::black.rgb() )));
  
  ui_bgColorDisplay->setColor( QColor( m_cfg->getRGB( "Graph", "display-background", QColor( 212,220,207 ).rgb() )));
  ui_textColor->setColor( QColor( m_cfg->getRGB( "Graph", "display-text", Qt::black.rgb() )));
  
  ui_lineWidth->setValue( m_cfg->getInt( "Graph", "line-width", 2 ) );

  ui_alertUnsavedData->setChecked( m_cfg->getBool( "Alert", "unsaved-file", true ));
  ui_textLabel->setChecked( m_cfg->getBool( "Icons", "text-label", true ));
}

void
ConfigDlg::preferencesFactorySLOT()
{
  ui_saveWindowCheck->setChecked( true );
  
  ui_bgColor->setColor( Qt::white );
  ui_gridColor->setColor( Qt::gray );
  ui_dataColor->setColor( Qt::blue );
  ui_cursorColor->setColor( Qt::black );

  ui_bgColorDisplay->setColor( QColor( 212,220,207 ) );
  ui_textColor->setColor( Qt::black );
  
  ui_lineWidth->setValue( 2 );
  
  ui_alertUnsavedData->setChecked( true );
  ui_textLabel->setChecked( true );
}

void
ConfigDlg::cancelSLOT()
{
  m_cfg->clear();
  m_cfg->load();
  
  recorderDefaultSLOT();
  scaleDefaultSLOT();
  dmmDefaultSLOT();
  preferencesDefaultSLOT();
     
  int count = m_cfg->getInt( "Custom colors", "count", 0 );
  
  for (int i=0; i<count; i++)
  {
    QString color;
    color.sprintf( "color_%d", i );
    QColorDialog::setCustomColor( i, m_cfg->getRGB( "Custom colors", color, Qt::white.rgb() ) );
  }
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
    sec *= MINUTE_SECS;
    break;
  case 2:
    sec *= HOUR_SECS;
    break;
  case 3:
    sec *= DAY_SECS;
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
    sec *= MINUTE_SECS;
    break;
  case 2:
    sec *= HOUR_SECS;
    break;
  case 3:
    sec *= DAY_SECS;
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
    sec *= MINUTE_SECS;
    break;
  case 2:
    sec *= HOUR_SECS;
    break;
  case 3:
    sec *= DAY_SECS;
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
    sec *= MINUTE_SECS;
    break;
  case 2:
    sec *= HOUR_SECS;
    break;
  case 3:
    sec *= DAY_SECS;
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

int
ConfigDlg::ignoreLines() const
{
  return ignoreSpin->value();
}

void
ConfigDlg::modelSLOT( int id )
{
  baudRate->setDisabled( id != 0 );
  ui_protocol->setDisabled( id != 0 );
  ui_baudLabel->setDisabled( id != 0 );
  ui_bitsLabel->setDisabled( id != 0 );
  ui_stopLabel->setDisabled( id != 0 );
  bitsCombo->setDisabled( id != 0 );
  stopBitsCombo->setDisabled( id != 0 );
  ignoreSpin->setDisabled( id != 0 );
  if (id != 0) message->hide();
  else         message->show();
  
  if (id > 0)
  {
    baudRate->setCurrentItem( dmm_info[id-1].baud );
    protocolCombo->setCurrentItem( dmm_info[id-1].protocol );
    bitsCombo->setCurrentItem( dmm_info[id-1].bits-5 );
    stopBitsCombo->setCurrentItem( dmm_info[id-1].stopBits-1 );
    ignoreSpin->setValue( dmm_info[id-1].ignoreLines );
  }
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

QColor
ConfigDlg::displayBgColor() const
{
  return ui_bgColorDisplay->color();
}

QColor
ConfigDlg::displayTextColor() const
{
  return ui_textColor->color();
}

QColor
ConfigDlg::bgColor() const
{
  return ui_bgColor->color();
}

QColor
ConfigDlg::gridColor() const
{
  return ui_gridColor->color();
}

QColor
ConfigDlg::dataColor() const
{
  return ui_dataColor->color();
}

QColor
ConfigDlg::cursorColor() const
{
  return ui_cursorColor->color();
}

int
ConfigDlg::lineWidth() const
{
  return ui_lineWidth->value();
}

bool
ConfigDlg::saveWindowPosition() const
{
  return ui_saveWindowCheck->isChecked();
}

bool
ConfigDlg::alertUnsavedData() const
{
  return ui_alertUnsavedData->isChecked();
}

bool
ConfigDlg::useTextLabel() const
{
  return ui_textLabel->isChecked();
}

void
ConfigDlg::setSampleTimeSLOT( int sampleTime )
{
  sampleEvery->setValue( sampleTime );
  
  applySLOT();
}

void
ConfigDlg::setGraphSizeSLOT( int size, int length )
{
  winSize->setValue( size );
  winLength->setValue( length );
  
  applySLOT();
}
