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
  
  
  connect( helpBut, SIGNAL( clicked() ), this, SLOT( helpSLOT() ));
  
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
  connect( tabWidget, SIGNAL( currentChanged( QWidget * )),
           this, SLOT( descriptionSLOT( QWidget * ) ));
  
  ui_defaultRecorder->hide();
  ui_defaultScale->hide();
  ui_defaultDMM->hide();
  ui_defaultPreferences->hide();
  ui_defaultExecute->hide();
  ui_defaultGraph->hide();
  
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
ConfigDlg::applySLOT()
{
//  m_cfg->clear();
  
  m_cfg->setInt( "QtDMM", "version", 0 );
  m_cfg->setInt( "QtDMM", "revision", 62 );
  m_cfg->setBool( "QtDMM", "show-tip", showTip() );
  
  m_cfg->setInt( "Sample", "rate", sampleEvery->value() );
  m_cfg->setInt( "Sample", "rate-unit", ui_sampleUnit->currentItem() );
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
ConfigDlg::helpSLOT()
{
  QWhatsThis::enterWhatsThisMode();
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
