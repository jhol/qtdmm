//======================================================================
// File:		mainwin.cpp
// Author:	Matthias Toussaint
// Created:	Sun Sep  2 12:15:28 CEST 2001
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

#include <mainwin.h>
#include <mainwid.h>
#include <qtoolbar.h>
#include <qiconset.h>
#include <qtoolbutton.h>
#include <qpopupmenu.h>
#include <qmenubar.h>
#include <qaction.h>
#include <qmessagebox.h>
#include <qlabel.h>
#include <qstatusbar.h>
#include <displaywid.h>

#include <connect_on.xpm>
#include <reset.xpm>
#include <start.xpm>
#include <stop.xpm>
#include <clear.xpm>
#include <print.xpm>
#include <export.xpm>
#include <import.xpm>
#include <config.xpm>
#include <quit.xpm>
#include <help.xpm>
#include <icon.xpm>

#define VERSION_STRING "0.8.3"

MainWin::MainWin( QWidget *parent, const char *name ) :
  QMainWindow( parent, name ),
  m_running( false )
{
  setIcon( QPixmap((const char **)icon_xpm) );
  
  m_wid = new MainWid( this );
  setCentralWidget( m_wid );
  
  createActions();
  createMenu();
  createToolBars();
  
  m_wid->setDisplay( m_display );
  
  setMinimumSize( 500, 450 );
  
  QString ver = "QtDMM ";
  ver += VERSION_STRING;
  
  setCaption( ver );
  
  adjustSize();
  
  connect( m_wid, SIGNAL( running(bool) ),
           this, SLOT( runningSLOT(bool) ));
  
  connectSLOT( false );
  
  m_error = new QLabel( statusBar() );
  m_error->setFrameStyle( QFrame::Panel | QFrame::Sunken );
  statusBar()->addWidget( m_error, 2, true );
  m_error->setLineWidth( 1 );  
  
  m_info = new QLabel( statusBar() );
  m_info->setFrameStyle( QFrame::Panel | QFrame::Sunken );
  statusBar()->addWidget( m_info, 1, true );
  m_info->setLineWidth( 1 );
  
  connect( m_wid, SIGNAL( error( const QString & ) ),
           m_error, SLOT( setText( const QString & ) ));
  connect( m_wid, SIGNAL( info( const QString & ) ),
           m_info, SLOT( setText( const QString & ) ));
  connect( m_wid, SIGNAL( useTextLabel( bool ) ),
           this, SLOT( setUsesTextLabel( bool ) ));
  connect( m_wid, SIGNAL( setConnect( bool ) ),
           this, SLOT( setConnectSLOT( bool ) ));

  m_wid->applySLOT();  
  
  QRect winRect = m_wid->winRect();
  
  if (!winRect.isEmpty())
  {
    setGeometry( winRect );
  }
  
}

MainWin::~MainWin()
{
}

void
MainWin::createActions()
{
  m_connectAction = new QAction ( tr("Connect"), 
                                  QIconSet(QPixmap((const char **)connect_on_xpm)), 
                                  tr("Connect"), 
                                  CTRL+Key_C, 
                                  this, 0, true );
  m_connectAction->setWhatsThis( tr("<b>Connect to the Multimeter</b><p>This will establish"
      " the serial connection to the dmm. If not connected the serial port is free"
      " and can be used by other software." ));
  m_resetAction   = new QAction ( tr("Reset"), 
                                  QIconSet(QPixmap((const char **)reset_xpm)), 
                                  tr("Reset"), 
                                  CTRL+Key_R, 
                                  this );
  m_resetAction->setWhatsThis( tr("<b>Reset min/max values</b><p>The min/max values in the"
      " display will be reset. You can activate this option at any time." ));
  m_startAction   = new QAction ( tr("Start"), 
                                  QIconSet(QPixmap((const char **)start_xpm)), 
                                  tr("Start"), 
                                  CTRL+Key_S, 
                                  this );
  m_startAction->setWhatsThis( tr("<b>Start the recorder</b><p>If you are in manual mode"
      " this will start the recorder. Press F2 to set the recorder options" ));
  m_stopAction    = new QAction ( tr("Stop"), 
                                  QIconSet(QPixmap((const char **)stop_xpm)), 
                                  tr("Stop"), 
                                  CTRL+Key_X, 
                                  this );
  m_stopAction->setWhatsThis( tr("<b>Stop the recorder</b><p>The recorder will be stopped."
      " This is independent from the start mode of the recorder" ));
  m_clearAction   = new QAction ( tr("Clear"), 
                                  QIconSet(QPixmap((const char **)clear_xpm)), 
                                  tr("Clear"), 
                                  Key_Delete, 
                                  this );
  m_clearAction->setWhatsThis( tr("<b>Clear the recorder graph</b><p>If the recorder is already"
      " started it will clear the graph and continue recording." ));
  m_printAction   = new QAction ( tr("Print"), 
                                  QIconSet(QPixmap((const char **)print_xpm)), 
                                  tr("Print ..."), 
                                  CTRL+Key_P, 
                                  this );
  m_printAction->setWhatsThis( tr("<b>Print recorder graph</b><p>A dialog will open where you can"
      " define a title and a comment for your printout. The printer itself can also be configured here."
      " To be able to print you need at least one working postscript printer configured in your"
      " system. Printing into a file is also supported." ));
  m_exportAction   = new QAction ( tr("Export"), 
                                  QIconSet(QPixmap((const char **)export_xpm)), 
                                  tr("Export ..."), 
                                  CTRL+Key_E, 
                                  this );
  m_exportAction->setWhatsThis( tr("<b>Export recorder graph</b><p>Here you can export the recorded"
      " data as tab separated list. Each line contains the following values (separated by a tab "
      "character): date (dd.mm.yyyy) time (hh:mm:ss) value (float) unit." ));
  m_importAction   = new QAction ( tr("Import"), 
                                  QIconSet(QPixmap((const char **)import_xpm)), 
                                  tr("Import ..."), 
                                  CTRL+Key_I, 
                                  this );
  m_importAction->setWhatsThis( tr("<b>Import data into recorder</b><p>Here you can import previously"
      " exported data files. QtDMM tries to do an educated guess if the file format is correct and"
      " rejects import of files which to not match." ));
  m_configAction   = new QAction ( tr("Configure"), 
                                  QIconSet(QPixmap((const char **)config_xpm)), 
                                  tr("Configure ..."), 
                                  Key_F2, 
                                  this );
  m_configDmmAction   = new QAction ( tr("Configure"), 
                                  QIconSet(QPixmap((const char **)config_xpm)), 
                                  tr("Configure ..."), 
                                  SHIFT+Key_F2, 
                                  this );
  m_configRecorderAction   = new QAction ( tr("Configure"), 
                                  QIconSet(QPixmap((const char **)config_xpm)), 
                                  tr("Configure ..."), 
                                  CTRL+Key_F2, 
                                  this );
  m_configAction->setWhatsThis( tr("<b>Configure QtDMM</b><p>This will open QtDMM's configuration"
      " dialog. Here you can configure it's visual appearance and all options regarding the "
      "multimeter hardware and the recorder." ));
  m_configDmmAction->setWhatsThis( tr("<b>Configure QtDMM</b><p>This will open QtDMM's configuration"
      " dialog. Here you can configure it's visual appearance and all options regarding the "
      "multimeter hardware and the recorder." ));
  m_configRecorderAction->setWhatsThis( tr("<b>Configure QtDMM</b><p>This will open QtDMM's configuration"
      " dialog. Here you can configure it's visual appearance and all options regarding the "
      "multimeter hardware and the recorder." ));
  m_quitAction     = new QAction ( tr("Quit"), 
                                  QIconSet(QPixmap((const char **)quit_xpm)), 
                                  tr("Quit"), 
                                  CTRL+Key_Q, 
                                  this );
  m_quitAction->setWhatsThis( tr("<b>Quit QtDMM</b><p>If the recorder contains unsaved data QtDMM"
      " will give you the option to savve your data first." ));
  m_helpAction     = new QAction ( tr("Help"), 
                                  QIconSet(QPixmap((const char **)help_xpm)), 
                                  tr("Direct Help"), 
                                  SHIFT+Key_F1, 
                                  this );
  m_helpAction->setWhatsThis( tr("<b>Direct Help</b><p>Enter the direct help mode. You have done this"
      " already when reading this text :)" ));
  m_showTipsAction  = new QAction ( this );
  m_showTipsAction->setText( tr("Show tip of the day") );
  m_showTipsAction->setMenuText( tr("Tip of the day...") );
  m_versionAction  = new QAction ( this );
  m_versionAction->setText( tr("On version") );
  m_versionAction->setMenuText( tr("On version...") );
  m_versionAction->setWhatsThis( tr("<b>Copyright information</b><p>Show copyright information and some"
      " blurb about QtDMM." ));
  
  connect( m_connectAction, SIGNAL( toggled(bool) ),
           m_wid, SLOT( connectSLOT(bool) ));
  connect( m_connectAction, SIGNAL( toggled(bool) ),
           this, SLOT( connectSLOT(bool) ));
  connect( m_resetAction, SIGNAL( activated() ),
           m_wid, SLOT( resetSLOT() ));
  connect( m_startAction, SIGNAL( activated() ),
           m_wid, SLOT( startSLOT() ));
  connect( m_stopAction, SIGNAL( activated() ),
           m_wid, SLOT( stopSLOT() ));
  connect( m_clearAction, SIGNAL( activated() ),
           m_wid, SLOT( clearSLOT() ));
  connect( m_printAction, SIGNAL( activated() ),
           m_wid, SLOT( printSLOT() ));
  connect( m_importAction, SIGNAL( activated() ),
           m_wid, SLOT( importSLOT() ));
  connect( m_exportAction, SIGNAL( activated() ),
           m_wid, SLOT( exportSLOT() ));
  connect( m_configAction, SIGNAL( activated() ),
           m_wid, SLOT( configSLOT() ));
  connect( m_configDmmAction, SIGNAL( activated() ),
           m_wid, SLOT( configDmmSLOT() ));
  connect( m_configRecorderAction, SIGNAL( activated() ),
           m_wid, SLOT( configRecorderSLOT() ));
  connect( m_quitAction, SIGNAL( activated() ),
           m_wid, SLOT( quitSLOT() ));
  connect( m_helpAction, SIGNAL( activated() ),
           m_wid, SLOT( helpSLOT() ));
  connect( m_showTipsAction, SIGNAL( activated() ),
           m_wid, SLOT( showTipsSLOT() ));
  connect( m_versionAction, SIGNAL( activated() ),
           this, SLOT( versionSLOT() ));
  
}

void
MainWin::runningSLOT( bool on )
{
  m_running = on;
  
  m_startAction->setEnabled( !on );
  m_stopAction->setEnabled( on );
  m_printAction->setEnabled( !on );
  m_exportAction->setEnabled( !on );
  m_importAction->setEnabled( !on );
}

void
MainWin::connectSLOT( bool on )
{
  m_startAction->setEnabled( on );
  m_stopAction->setEnabled( on );
   
  m_startAction->setEnabled( on );
  m_stopAction->setEnabled( on && m_running );
  m_printAction->setEnabled( !(on || m_running) );
  m_exportAction->setEnabled( !(on || m_running) );
  m_importAction->setEnabled( !(on || m_running) );
  
  if (!on) m_running = false;
}

void
MainWin::versionSLOT()
{
  QString ver = "QtDMM ";
  ver += VERSION_STRING;
  QString msg = "<h1>";
  msg += ver;
  msg += "</h1><hr>"
         "<div align=right><i>A simple recorder for DMM's</i></div><p>"
         "<div align=justify>A simple display software for a variety of digital multimeter such as:<p>"
         "<table><tr><td><b>ELV</b></td><td>M9803R</td></tr>"
         "<tr><td><b>Metex</b></td><td>M-3660D, M-3830D, M-3850D, ME-11, ME-22, ME-32 and Universal system 9160</td></tr>"
         "<tr><td><b>PeakTech</b></td><td>4010 and 451</td></tr>"
         "<tr><td><b>RadioShack</b></td><td>22-805</td></tr>"
         "<tr><td><b>Voltcraft</b></td><td>M-3650D, M-4660, ME-11, ME-22T, ME-32 and VC&nbsp;670</td></tr>"
         "<tr><td colspan=2>Implemented, but not yet confirmed by a user are:</td></tr>"
         "<tr><td><b>Voltcraft</b></td><td>ME-42, M-3860, M-4660A, M-4660M, MXD-4660A, VC&nbsp;630, VC&nbsp;650"
         ", VC&nbsp;635 and VC&nbsp;655</td></tr></table>"
         "Other compatible models may work also.<p>"
         "QtDMM features min/max memory and a configurable "
         "recorder with import/export and printing function. Sampling may"
         " be started manually, at a given time or triggered by a measured threshold. "
         "Additionally an external program may be started when given thresholds are reached.</div>"
         "<div align=justify><b>QtDMM</b> uses the platform independent toolkit "
         "<b>Qt</b> version ";
  msg += qVersion();
  msg += " from Trolltech AS Norway <font color=blue><u>www.trolltech.com</u></font>"
         " and is licensed under <b>GPL</b>.</div><br>"
         "&copy; 2001-2005 Matthias Toussaint &nbsp;-&nbsp;&nbsp;<font color=blue><u>qtdmm@mtoussaint.de</u></font>"
         "<p><br>The icons (except the DMM icon) are taken from the KDE project.<p>";
          
  QMessageBox version( tr("QtDMM: Welcome!" ),
                       tr( msg ),
                       QMessageBox::Information,
                       QMessageBox::Yes | QMessageBox::Default,
                       QMessageBox::NoButton,
                       QMessageBox::NoButton );

  version.setButtonText( QMessageBox::Yes, tr("Ok") );
  version.setIconPixmap( QPixmap((const char **)icon_xpm ) );
  version.exec();
}
    
void
MainWin::createToolBars()
{
  m_dmmTB = new QToolBar( this );
  m_connectAction->addTo( m_dmmTB );
  m_resetAction->addTo( m_dmmTB );
  addToolBar( m_dmmTB, tr("DMM"), QMainWindow::Top, true );
  
  m_graphTB = new QToolBar( this );
  m_startAction->addTo( m_graphTB );
  m_stopAction->addTo( m_graphTB );
  m_graphTB->addSeparator();
  m_clearAction->addTo( m_graphTB );
  addToolBar( m_graphTB, tr("Recorder") );
  
  m_fileTB = new QToolBar( this );
  m_printAction->addTo( m_fileTB );
  m_exportAction->addTo( m_fileTB );
  m_importAction->addTo( m_fileTB );
  m_fileTB->addSeparator();
  m_configAction->addTo( m_fileTB );
  m_fileTB->addSeparator();
  m_quitAction->addTo( m_fileTB );
  addToolBar( m_fileTB, tr("File") );
  
  m_helpTB = new QToolBar( this );
  m_helpAction->addTo( m_helpTB );
  
  m_displayTB = new QToolBar( this );
  m_display = new DisplayWid( m_displayTB );
  addToolBar( m_displayTB, tr("Display"), Top, true );
}

void
MainWin::createMenu()
{
  QMenuBar *menu = menuBar();
  
  QPopupMenu *file = new QPopupMenu( menu );
  m_exportAction->addTo( file );
  m_importAction->addTo( file );
  file->insertSeparator();
  m_printAction->addTo( file );
  file->insertSeparator();
  m_configAction->addTo( file );
  file->insertSeparator();
  m_quitAction->addTo( file );
  
  menu->insertItem( tr("File"), file );
  
  QPopupMenu *dmm = new QPopupMenu( menu );
  m_connectAction->addTo( dmm );
  m_resetAction->addTo( dmm );
  dmm->insertSeparator();
  m_configDmmAction->addTo( dmm );
  
  menu->insertItem( tr("DMM"), dmm );
  
  QPopupMenu *recorder = new QPopupMenu( menu );
  m_startAction->addTo( recorder );
  m_stopAction->addTo( recorder );
  recorder->insertSeparator();
  m_clearAction->addTo( recorder );
  recorder->insertSeparator();
  m_configRecorderAction->addTo( recorder );
  
  menu->insertItem( tr("Recorder"), recorder );
  
  QPopupMenu *help = new QPopupMenu( menu );
  m_versionAction->addTo( help );
  m_showTipsAction->addTo( help );
  m_helpAction->addTo( help );
  
  menu->insertSeparator();
  menu->insertItem( tr("Help"), help );
  
}
     
void
MainWin::closeEvent( QCloseEvent *ev )
{
  if (m_wid->closeWin())
  {
    ev->accept();
  }
  else
  {
    ev->ignore();
  } 
}

void
MainWin::setConnectSLOT( bool on )
{
  m_connectAction->setOn( on );
}
