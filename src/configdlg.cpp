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
#include <engnumbervalidator.h>
#include <qradiobutton.h>
#include <qbuttongroup.h>
#include <qtextview.h>
#include <qcheckbox.h>
#include <colorbutton.h>
#include <qcolordialog.h>
#include <qmessagebox.h>
#include <qprinter.h> 
#include <qfiledialog.h>
#include <qtabwidget.h>
#include <qvalidator.h>
#include <qlabel.h>

#include <iostream.h>

#include <xpm/icon.xpm>

#define MINUTE_SECS   60
#define HOUR_SECS     60*60
#define DAY_SECS      60*60*24

// when all needed parameter are found this hardcoded version will
// be replaced by a file
//    name
//    baud (600=0,1200,1800,2400,4800,9600)
//    protocol (14 bytes polling 'D'=0, 10 bytes continuous [PeakTech]
//              14 continuous, 15 continuous, 11 bin continuous)
//    bits
//    stopBits
//    number of values (For DMM's that send several lines at once)
//    parity (0,1,2 - None,Even,Odd) 
//    display digits (0,1,2,3 - 3 1/2, 3 3/4, 4 1/1, 4 3/4)
//
struct DMMInfo dmm_info[] = { 
                              {"ELV M9803R", 5, 4, 7, 1, 1, 1, 1},
                              {"Metex M-3660D", 1, 0, 7, 2, 1, 0, 1},
                              {"Metex M-3830D", 1, 0, 7, 2, 4, 0, 1},
                              {"Metex M-3850D", 1, 0, 7, 2, 4, 0, 1},
                              {"Metex ME-11", 0, 0, 7, 2, 1, 0, 1},
                              {"Metex ME-22", 3, 0, 7, 2, 1, 0, 1},
                              {"Metex ME-32", 0, 0, 7, 2, 1, 0, 1},
                              {"Metex universal system 9160", 1, 0, 7, 2, 4, 0, 1},
                              {"PeakTech-4010", 5, 0, 7, 2, 1, 0, 1},
                              {"PeakTech-451", 0, 1, 7, 2, 1, 0, 1},
                              {"Radioshack 22-805 DMM", 0, 0, 7, 2, 1, 0, 1},
                              {"Voltcraft M-4660", 1, 0, 7, 2, 4, 0, 3},
                              {"Voltcraft ME-11", 0, 0, 7, 2, 1, 0, 1},
                              {"Voltcraft ME-22T", 3, 0, 7, 2, 1, 0, 1},
                              {"Voltcraft ME-32", 0, 0, 7, 2, 1, 0, 1},
                              {"Voltcraft VC 670", 4, 2, 7, 1, 1, 0, 3},
                              {"*Voltcraft ME-42", 0, 0, 7, 2, 1, 0, 1},
                              {"*Voltcraft M-3860", 5, 0, 7, 2, 4, 0, 2},
                              {"*Voltcraft M-4660A", 5, 0, 7, 2, 4, 0, 3},
                              {"*Voltcraft M-4660M", 5, 0, 7, 2, 4, 0, 3},
                              {"*Voltcraft MXD-4660A", 5, 0, 7, 2, 4, 0, 3},
                              {"*Voltcraft VC 630", 4, 2, 7, 1, 1, 0, 3},
                              {"*Voltcraft VC 650", 4, 2, 7, 1, 1, 0, 3},
                              {"*Voltcraft VC 635", 3, 3, 7, 1, 1, 0, 3},
                              {"*Voltcraft VC 655", 3, 3, 7, 1, 1, 0, 3},
                              
                              {"",0,0,0,0,0,0,0} // End Of List
                            };
                      
ConfigDlg::ConfigDlg( QWidget *parent, const char *name ) :
  UIConfigDlg( parent, name, false )
{
  EngNumberValidator *validator = new EngNumberValidator( this );
  
  ui_raisingThreshold->setValidator( validator );
  ui_fallingThreshold->setValidator( validator );
  ui_execRaisingThreshold->setValidator( validator );
  ui_execFallingThreshold->setValidator( validator );
  ui_intScale->setValidator( validator );
  ui_intThreshold->setValidator( validator );
  ui_intOffset->setValidator( validator );
  ui_scaleMin->setValidator( validator );
  ui_scaleMax->setValidator( validator );
  
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
  else
  {
    m_cfg->load();
    
    int version  = m_cfg->getInt( "QtDMM", "version", 0 );
    int revision = m_cfg->getInt( "QtDMM", "revision", 0 );
    
    if ((version <= 0 && revision < 62) || version >= 7)
    {
      QMessageBox welcome( tr("QtDMM: Welcome!" ),
                           tr("<font size=+2><b>Welcome!</b></font><p>"
                              "You seem to have upgraded <b>QtDMM</b> from a version prior to 0.8"
                              " Please check your configuration. There are some new parameter to be"
                              " configured."
                              "<p>Thank you for choosing <b>QtDMM</b>.<p><i>Matthias Toussaint</i>"),
                            QMessageBox::Information,
                            QMessageBox::Yes | QMessageBox::Default,
                            QMessageBox::NoButton,
                            QMessageBox::NoButton );
                                 
      welcome.setButtonText( QMessageBox::Yes, tr("Continue") );
      welcome.setIconPixmap( QPixmap((const char **)icon_xpm ) );
      welcome.exec();   
    }   
  }
  
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
  connect( ui_defaultExecute, SIGNAL( clicked() ),
           this, SLOT( executeDefaultSLOT() ));
  connect( ui_factoryExecute, SIGNAL( clicked() ),
           this, SLOT( executeFactorySLOT() ));
  connect( ui_defaultGraph, SIGNAL( clicked() ),
           this, SLOT( graphDefaultSLOT() ));
  connect( ui_factoryGraph, SIGNAL( clicked() ),
           this, SLOT( graphFactorySLOT() ));
  connect( ui_browseExec, SIGNAL( clicked() ),
           this, SLOT( browseExecSLOT() ));
  connect( tabWidget, SIGNAL( currentChanged( QWidget * )),
           this, SLOT( descriptionSLOT( QWidget * ) ));
  
  ui_defaultRecorder->hide();
  ui_defaultScale->hide();
  ui_defaultDMM->hide();
  ui_defaultPreferences->hide();
  ui_defaultExecute->hide();
  ui_defaultGraph->hide();
      
  ui_model->clear();
  ui_model->insertItem( "Manual settings" );
  
  int id = 0;
  while (*dmm_info[id].name)
  {
    ui_model->insertItem( dmm_info[id++].name );
  }

  connect( ui_model, SIGNAL( activated( int ) ),
           this, SLOT( modelSLOT( int )));
  
  cancelSLOT();
  
  ui_description->setBackgroundColor( colorGroup().light() );
  ui_pixmap->setBackgroundColor( colorGroup().light() );
  ui_spacer->setBackgroundColor( colorGroup().light() );
  
  connect( ui_tipOfTheDay, SIGNAL( toggled( bool ) ),
           this, SIGNAL( showTips( bool ) ));
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
//  m_cfg->clear();
  
  m_cfg->setInt( "QtDMM", "version", 0 );
  m_cfg->setInt( "QtDMM", "revision", 62 );
  m_cfg->setBool( "QtDMM", "show-tip", showTip() );
  
  m_cfg->setInt( "Sample", "rate", sampleEvery->value() );
  m_cfg->setInt( "Sample", "rate-unit", sampleUnit->currentItem() );
  m_cfg->setInt( "Sample", "time", sampleTime->value() );
  m_cfg->setInt( "Sample", "time-unit", timeUnit->currentItem() );
  
  m_cfg->setInt( "Start", "mode", sampleMode() );
  m_cfg->setInt( "Start", "hour", hour->value() );
  m_cfg->setInt( "Start", "minute", minute->value() );
  m_cfg->setInt( "Start", "second", second->value() );
  m_cfg->setString( "Start", "raising-threshold", ui_raisingThreshold->text() );
  m_cfg->setString( "Start", "falling-threshold", ui_fallingThreshold->text() );
  
  m_cfg->setBool( "Scale", "automatic", automaticScale() );
  m_cfg->setString( "Scale", "minimum", ui_scaleMin->text() );
  m_cfg->setString( "Scale", "maximum", ui_scaleMax->text() );
  
  m_cfg->setInt( "Window", "size", ui_winSize->value() );
  m_cfg->setInt( "Window", "size-unit", sizeUnit->currentItem() );
  m_cfg->setInt( "Window", "length", winLength->value() );
  m_cfg->setInt( "Window", "length-unit", lengthUnit->currentItem() );
  
  m_cfg->setInt( "Port settings", "device", port->currentItem() );
  m_cfg->setInt( "Port settings", "baud", baudRate->currentItem() );
  m_cfg->setInt( "Port settings", "bits", bitsCombo->currentItem()+5 );
  m_cfg->setInt( "Port settings", "stop-bits", stopBitsCombo->currentItem()+1 );
  m_cfg->setInt( "Port settings", "parity", parityCombo->currentItem() );
  
  m_cfg->setInt( "DMM", "display", displayCombo->currentItem() );
  
  m_cfg->setInt( "DMM", "data-format", protocolCombo->currentItem() );
  m_cfg->setInt( "DMM", "number-of-values", ui_numValues->value() );
  m_cfg->setString( "DMM", "model", 
      (ui_model->currentItem() == 0 ? "Manual" : dmm_info[ui_model->currentItem()-1].name ));
  
  m_cfg->setBool( "Save", "window", ui_saveWindowCheck->isChecked() );
  
  m_cfg->setRGB( "Graph", "background", ui_bgColor->color().rgb() );
  m_cfg->setRGB( "Graph", "grid", ui_gridColor->color().rgb() );
  m_cfg->setRGB( "Graph", "data", ui_dataColor->color().rgb() );
  m_cfg->setRGB( "Graph", "integration", ui_intColor->color().rgb() );
  m_cfg->setRGB( "Graph", "integration-threshold", ui_intThresholdColor->color().rgb() );
  m_cfg->setRGB( "Graph", "cursor", ui_cursorColor->color().rgb() );
  m_cfg->setRGB( "Graph", "start-trigger", ui_startColor->color().rgb() );
  m_cfg->setRGB( "Graph", "external-trigger", ui_extColor->color().rgb() );
  m_cfg->setInt( "Graph", "line-width", ui_lineWidth->value() );
  m_cfg->setInt( "Graph", "line-mode", ui_lineMode->currentItem() );
  m_cfg->setInt( "Graph", "point-mode", ui_pointMode->currentItem() );
  m_cfg->setInt( "Graph", "int-line-width", ui_intLineWidth->value() );
  m_cfg->setInt( "Graph", "int-line-mode", ui_intLineMode->currentItem() );
  m_cfg->setInt( "Graph", "int-point-mode", ui_intPointMode->currentItem() );
  m_cfg->setBool( "Graph", "crosshair-cursor", ui_crosshair->isChecked() );
  m_cfg->setBool( "Graph", "show-integration", ui_showInt->isChecked() );
  m_cfg->setString( "Graph", "int-scale", ui_intScale->text() );
  m_cfg->setString( "Graph", "int-offset", ui_intOffset->text() );
  m_cfg->setString( "Graph", "int-threshold", ui_intThreshold->text() );

  m_cfg->setRGB( "Graph", "display-background", ui_bgColorDisplay->color().rgb() );
  m_cfg->setRGB( "Graph", "display-text", ui_textColor->color().rgb() );
  m_cfg->setBool( "Graph", "display-bar", showBar() );
  m_cfg->setBool( "Graph", "display-min-max", showMinMax() );
  
  m_cfg->setInt( "Custom colors", "count", QColorDialog::customCount() );
  
  m_cfg->setInt( "Printer", "page-size", (int)m_printer->pageSize() );
  m_cfg->setInt( "Printer", "page-orientation", (int)m_printer->orientation() );
  m_cfg->setInt( "Printer", "color", (int)m_printer->colorMode() );
  m_cfg->setString( "Printer", "name", m_printer->printerName() );
  m_cfg->setString( "Printer", "filename", m_printer->outputFileName() );
  m_cfg->setBool( "Printer", "print-file", m_printer->outputToFile() );
  
  m_cfg->setBool( "Alert", "unsaved-file", alertUnsavedData() );
  
  m_cfg->setBool( "Icons", "text-label", useTextLabel() );

  m_cfg->setBool( "External", "exec", startExternal() );  
  m_cfg->setBool( "External", "raising", !externalFalling() );
  m_cfg->setString( "External", "raising-threshold", ui_execRaisingThreshold->text() );
  m_cfg->setString( "External", "falling-threshold", ui_execFallingThreshold->text() );  
  m_cfg->setBool( "External", "disconnect", disconnectExternal() );
  m_cfg->setString( "External", "command", externalCommand() );
  
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
  ui_raisingThreshold->setText( m_cfg->getString( "Start", "raising-threshold", "0.0" ));
  ui_fallingThreshold->setText( m_cfg->getString( "Start", "falling-threshold", "0.0" ));
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
  ui_raisingThreshold->setText( "0.0" );
  ui_fallingThreshold->setText( "0.0" );
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

  ui_scaleMin->setText( m_cfg->getString( "Scale", "minimum", "-3.999" ));
  ui_scaleMax->setText( m_cfg->getString( "Scale", "maximum", "3.999" ));
  
  ui_winSize->setValue( m_cfg->getInt( "Window", "size", 600 ));
  sizeUnit->setCurrentItem( m_cfg->getInt( "Window", "size-unit", 0 ));
  winLength->setValue( m_cfg->getInt( "Window", "length", 3600 ));
  lengthUnit->setCurrentItem( m_cfg->getInt( "Window", "length-unit", 0 ));
}

void
ConfigDlg::scaleFactorySLOT()
{
  autoScaleBut->setChecked( true );

  ui_scaleMin->setText( "-3.999" );
  ui_scaleMax->setText( "3.999" );
  
  ui_winSize->setValue( 600 );
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
  parityCombo->setCurrentItem( m_cfg->getInt( "Port settings", "parity", 0 ) );  
  displayCombo->setCurrentItem( m_cfg->getInt( "DMM", "display", 1 ) );
  
  protocolCombo->setCurrentItem( m_cfg->getInt( "DMM", "data-format", 0 ));
  ui_numValues->setValue( m_cfg->getInt( "DMM", "number-of-values", 1 ));
  
  QString model = m_cfg->getString( "DMM", "model", "" );
  
  ui_model->setCurrentItem( 0 );
  int id=0;
  while (*dmm_info[id].name)
  {
    if (model == dmm_info[id].name)
    {
      ui_model->setCurrentItem( id+1 );
      break;
    }
    id++;
  }
   
  modelSLOT( ui_model->currentItem() );
}

void
ConfigDlg::dmmFactorySLOT()
{
  port->setCurrentItem( 0 );
  baudRate->setCurrentItem( 0 );
  bitsCombo->setCurrentItem( 2 );
  stopBitsCombo->setCurrentItem( 1 );
  parityCombo->setCurrentItem( 0 );  
  displayCombo->setCurrentItem( 1 );
  
  protocolCombo->setCurrentItem( 0 );
  ui_numValues->setValue( 1 );
  ui_model->setCurrentItem( 0 );
  
  modelSLOT( ui_model->currentItem() );
}

void
ConfigDlg::preferencesDefaultSLOT()
{
  ui_saveWindowCheck->setChecked( m_cfg->getBool( "Save", "window", true ));
  
  ui_bgColorDisplay->setColor( QColor( m_cfg->getRGB( "Graph", "display-background", QColor( 212,220,207 ).rgb() )));
  ui_textColor->setColor( QColor( m_cfg->getRGB( "Graph", "display-text", Qt::black.rgb() )));
  
  ui_showBar->setChecked( m_cfg->getBool( "Graph", "display-bar", true ));
  ui_showMinMax->setChecked( m_cfg->getBool( "Graph", "display-min-max", true ));
  
  ui_alertUnsavedData->setChecked( m_cfg->getBool( "Alert", "unsaved-file", true ));
  ui_textLabel->setChecked( m_cfg->getBool( "Icons", "text-label", true ));
  ui_crosshair->setChecked( m_cfg->getBool( "Graph", "crosshair-cursor", true ));
  
  ui_tipOfTheDay->setChecked( m_cfg->getBool( "QtDMM", "show-tip", true ));
}

void
ConfigDlg::preferencesFactorySLOT()
{
  ui_saveWindowCheck->setChecked( true );
  
  ui_bgColorDisplay->setColor( QColor( 212,220,207 ) );
  ui_textColor->setColor( Qt::black );

  ui_showBar->setChecked( true );
  ui_showMinMax->setChecked( true );
  
  ui_alertUnsavedData->setChecked( true );
  ui_textLabel->setChecked( true );
  
  ui_tipOfTheDay->setChecked( true );
}

void
ConfigDlg::graphDefaultSLOT()
{
  ui_bgColor->setColor( QColor( m_cfg->getRGB( "Graph", "background", Qt::white.rgb() )));
  ui_gridColor->setColor( QColor( m_cfg->getRGB( "Graph", "grid", Qt::gray.rgb() )));
  ui_dataColor->setColor( QColor( m_cfg->getRGB( "Graph", "data", Qt::blue.rgb() )));
  ui_intColor->setColor( QColor( m_cfg->getRGB( "Graph", "integration", Qt::darkBlue.rgb() )));
  ui_intThresholdColor->setColor( QColor( m_cfg->getRGB( "Graph", "integration-threshold", Qt::darkBlue.rgb() )));
  ui_cursorColor->setColor( QColor( m_cfg->getRGB( "Graph", "cursor", Qt::black.rgb() )));
  ui_startColor->setColor( QColor( m_cfg->getRGB( "Graph", "start-trigger", Qt::magenta.rgb() )));
  ui_extColor->setColor( QColor( m_cfg->getRGB( "Graph", "external-trigger", Qt::cyan.rgb() )));
  
  ui_lineMode->setCurrentItem( m_cfg->getInt( "Graph", "line-mode", 1 ));
  ui_pointMode->setCurrentItem( m_cfg->getInt( "Graph", "point-mode", 0 ));
  ui_intLineMode->setCurrentItem( m_cfg->getInt( "Graph", "int-line-mode", 0 ));
  ui_intPointMode->setCurrentItem( m_cfg->getInt( "Graph", "int-point-mode", 1 ));
  
  ui_lineWidth->setValue( m_cfg->getInt( "Graph", "line-width", 2 ) );
  ui_intLineWidth->setValue( m_cfg->getInt( "Graph", "int-line-width", 2 ) );
  
  ui_showInt->setChecked( m_cfg->getBool( "Graph", "show-integration", false ));
  
  ui_intScale->setText( m_cfg->getString( "Graph", "int-scale", "1.0" ));
  ui_intOffset->setText( m_cfg->getString( "Graph", "int-offset", "0.0" ));
  ui_intThreshold->setText( m_cfg->getString( "Graph", "int-threshold", "0.0" ));
}

void
ConfigDlg::graphFactorySLOT()
{
  ui_bgColor->setColor( Qt::white );
  ui_gridColor->setColor( Qt::gray );
  ui_dataColor->setColor( Qt::blue );
  ui_cursorColor->setColor( Qt::black );
  ui_intColor->setColor( Qt::darkBlue );
  ui_intThresholdColor->setColor( Qt::darkBlue.rgb() );
  ui_startColor->setColor( Qt::magenta.rgb() );
  ui_extColor->setColor( Qt::cyan.rgb() );
  
  ui_lineMode->setCurrentItem( 1 );
  ui_pointMode->setCurrentItem( 0 );
  ui_intLineMode->setCurrentItem( 0 );
  ui_intPointMode->setCurrentItem( 1 );
  
  ui_lineWidth->setValue( 2 );
  ui_intLineWidth->setValue( 1 );

  ui_showInt->setChecked( false );
  
  ui_intScale->setText( "0.1" );
  ui_intOffset->setText( "0.0" );
  ui_intThreshold->setText( "0.0" );
}

void
ConfigDlg::executeDefaultSLOT()
{
  ui_executeCommand->setChecked( m_cfg->getBool( "External", "exec", false ));
  
  ui_execRaising->setChecked( m_cfg->getBool( "External", "raising", true ));
  ui_execRaisingThreshold->setText( m_cfg->getString( "External", "raising-threshold", "" ));
  ui_execFallingThreshold->setText( m_cfg->getString( "External", "falling-threshold", "" ));
  
  ui_disconnectExec->setChecked( m_cfg->getBool( "External", "disconnect", false ));
  ui_commandExec->setText( m_cfg->getString( "External", "command", "" ));
}

void
ConfigDlg::executeFactorySLOT()
{
  ui_executeCommand->setChecked( false );
  
  ui_execRaising->setChecked( true );
  ui_execRaisingThreshold->setText( "" );
  ui_execFallingThreshold->setText( "" );
  
  ui_disconnectExec->setChecked( false );
  ui_commandExec->setText( "" );
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
  executeDefaultSLOT();
  graphDefaultSLOT();
     
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
  int sec = ui_winSize->text().toInt();
  
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
  return EngNumberValidator::value( ui_fallingThreshold->text() );
}

double
ConfigDlg::raisingThreshold() const
{
  return EngNumberValidator::value( ui_raisingThreshold->text() );
}

double
ConfigDlg::scaleMin() const
{
  return EngNumberValidator::value( ui_scaleMin->text() );
}

double
ConfigDlg::scaleMax() const
{
  return EngNumberValidator::value( ui_scaleMax->text() );
}

bool 
ConfigDlg::automaticScale() const
{
  return autoScaleBut->isChecked();
}

bool 
ConfigDlg::showBar() const
{
  return ui_showBar->isChecked();
}

bool 
ConfigDlg::showMinMax() const
{
  return ui_showMinMax->isChecked();
}

ReadEvent::DataFormat
ConfigDlg::format() const
{
  return (ReadEvent::DataFormat)protocolCombo->currentItem();
}

int
ConfigDlg::numValues() const
{
  return ui_numValues->value();
}

void
ConfigDlg::modelSLOT( int id )
{
  baudRate->setDisabled( id != 0 );
  ui_protocol->setDisabled( id != 0 );
  ui_baudLabel->setDisabled( id != 0 );
  ui_bitsLabel->setDisabled( id != 0 );
  ui_stopLabel->setDisabled( id != 0 );
  ui_displayLabel->setDisabled( id != 0 );
  ui_parityLabel->setDisabled( id != 0 );
  bitsCombo->setDisabled( id != 0 );
  displayCombo->setDisabled( id != 0 );
  stopBitsCombo->setDisabled( id != 0 );
  parityCombo->setDisabled( id != 0 );
  ui_numValues->setDisabled( id != 0 );
  if (id != 0) message->hide();
  else         message->show();
  if (ui_model->text(id)[0] == '*')
  {
    message2->show();
  }
  else
  {
    message2->hide();
  }
  
  if (id > 0)
  {
    baudRate->setCurrentItem( dmm_info[id-1].baud );
    protocolCombo->setCurrentItem( dmm_info[id-1].protocol );
    bitsCombo->setCurrentItem( dmm_info[id-1].bits-5 );
    stopBitsCombo->setCurrentItem( dmm_info[id-1].stopBits-1 );
    parityCombo->setCurrentItem( dmm_info[id-1].parity );
    displayCombo->setCurrentItem( dmm_info[id-1].display );
    ui_numValues->setValue( dmm_info[id-1].numValues );
  }
}

int
ConfigDlg::display() const
{
  return displayCombo->currentItem();
}

int
ConfigDlg::parity() const
{
  return parityCombo->currentItem();
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
ConfigDlg::startColor() const
{
  return ui_startColor->color();
}

QColor
ConfigDlg::externalColor() const
{
  return ui_extColor->color();
}

QColor
ConfigDlg::cursorColor() const
{
  return ui_cursorColor->color();
}

QColor
ConfigDlg::intColor() const
{
  return ui_intColor->color();
}

QColor
ConfigDlg::intThresholdColor() const
{
  return ui_intThresholdColor->color();
}

int
ConfigDlg::intLineWidth() const
{
  return ui_intLineWidth->value();
}

int
ConfigDlg::lineWidth() const
{
  return ui_lineWidth->value();
}

int
ConfigDlg::lineMode() const
{
  return ui_lineMode->currentItem();
}

int
ConfigDlg::pointMode() const
{
  return ui_pointMode->currentItem();
}

int
ConfigDlg::intLineMode() const
{
  return ui_intLineMode->currentItem();
}

int
ConfigDlg::intPointMode() const
{
  return ui_intPointMode->currentItem();
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

bool
ConfigDlg::startExternal() const
{
  return ui_executeCommand->isChecked();
}

bool
ConfigDlg::crosshair() const
{
  return ui_crosshair->isChecked();
}

bool
ConfigDlg::disconnectExternal() const
{
  return ui_disconnectExec->isChecked();
}

bool
ConfigDlg::externalFalling() const
{
  return ui_execFalling->isChecked();
}

double
ConfigDlg::externalThreshold() const
{
  if (ui_execFalling->isChecked())
  {
    return EngNumberValidator::value( ui_execFallingThreshold->text() );
  }
  
  return EngNumberValidator::value( ui_execRaisingThreshold->text() );
}

bool
ConfigDlg::showIntegration() const
{
  return ui_showInt->isChecked();
}

bool
ConfigDlg::showTip() const
{
  return ui_tipOfTheDay->isChecked();
}

void
ConfigDlg::setShowTipsSLOT( bool on )
{
  ui_tipOfTheDay->setChecked( on );
}

double
ConfigDlg::intScale() const
{
  return EngNumberValidator::value( ui_intScale->text() );
}

double
ConfigDlg::intThreshold() const
{
  return EngNumberValidator::value( ui_intThreshold->text() );
}

double
ConfigDlg::intOffset() const
{
  return EngNumberValidator::value( ui_intOffset->text() );
}

QString
ConfigDlg::externalCommand() const
{
  return ui_commandExec->text();
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
  ui_winSize->setValue( size );
  winLength->setValue( length );
  
  applySLOT();
}

void
ConfigDlg::browseExecSLOT()
{
  QString filename = QFileDialog::getOpenFileName( QString::null, "*", this );
    
  if (!filename.isEmpty()) 
  {
    ui_commandExec->setText( filename );
  }  
}

void
ConfigDlg::descriptionSLOT( QWidget * )
{
  switch (tabWidget->currentPageIndex())
  {
  case 0:
    ui_description->setText( tr("Here you can configure the sampling"
                                " frequency and start options for the"
                                " recorder." ));
    break;
    
  case 1:
    ui_description->setText( tr("Here you can configure the vertical scale"
                                " of the recorder and the length (in time)"
                                " of the window." ));
    break;
    
  case 2:
    ui_description->setText( tr("Here you can configure the serial port"
                                " and protocol for your DMM. There is"
                                " also a number of predefined models." ));
    break;
    
  case 3:
    ui_description->setText( tr("Here you can configure QtDMM's visual"
                                " appearance and behaviour." ));
    break;
    
  case 4:
    ui_description->setText( tr("Here you can configure the colors and"
                                " drawing style for the graph." ));
    break;
    
  case 5:
    ui_description->setText( tr("Here you can configure the parameter"
                                " for the integration curve." ));
    break;    
    
  case 6:
    ui_description->setText( tr("Here you can configure if an external"
                                " command is to be started and when." ));
    break;    
  } 
}

void
ConfigDlg::setCurrentTipSLOT( int id )
{
  m_cfg->setInt( "QtDMM", "tip-id", id );  
  m_cfg->save();
}

int
ConfigDlg::currentTipId() const
{
  return m_cfg->getInt( "QtDMM", "tip-id", 0 );
}

QString
ConfigDlg::dmmName() const
{
  return ui_model->currentText();
}

void
ConfigDlg::zoomInSLOT( double fac )
{
  double val = ui_winSize->value();
  
  if (val > 10)
  {
    val /= fac;
  }
  else
  {
    val /= 2.;
  }
  
  val = QMAX( 1, val );
  
  ui_winSize->setValue( (int)val );
  
  emit accepted();
}

void
ConfigDlg::zoomOutSLOT( double fac )
{
  double val = ui_winSize->value();
  
  if (val > 10)
  {
    val *= fac;
  }
  else
  {
    val *= 2.;
  }
  
  val = QMAX( 2, val );
  ui_winSize->setValue( (int)val );
  
  emit accepted();
}
