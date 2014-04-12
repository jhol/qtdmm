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
  
  setMinimumSize( 500, 450 );
  
  setCaption( tr("QtDMM: (c) 2001 M.Toussaint" ));
  
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
  m_resetAction   = new QAction ( tr("Reset"), 
                                  QIconSet(QPixmap((const char **)reset_xpm)), 
                                  tr("Reset"), 
                                  CTRL+Key_R, 
                                  this );
  m_startAction   = new QAction ( tr("Start"), 
                                  QIconSet(QPixmap((const char **)start_xpm)), 
                                  tr("Start"), 
                                  CTRL+Key_S, 
                                  this );
  m_stopAction    = new QAction ( tr("Stop"), 
                                  QIconSet(QPixmap((const char **)stop_xpm)), 
                                  tr("Stop"), 
                                  CTRL+Key_X, 
                                  this );
  m_clearAction   = new QAction ( tr("Clear"), 
                                  QIconSet(QPixmap((const char **)clear_xpm)), 
                                  tr("Clear"), 
                                  Key_Delete, 
                                  this );
  m_printAction   = new QAction ( tr("Print"), 
                                  QIconSet(QPixmap((const char **)print_xpm)), 
                                  tr("Print ..."), 
                                  CTRL+Key_P, 
                                  this );
  m_exportAction   = new QAction ( tr("Export"), 
                                  QIconSet(QPixmap((const char **)export_xpm)), 
                                  tr("Export ..."), 
                                  CTRL+Key_E, 
                                  this );
  m_importAction   = new QAction ( tr("Import"), 
                                  QIconSet(QPixmap((const char **)import_xpm)), 
                                  tr("Import ..."), 
                                  CTRL+Key_I, 
                                  this );
  m_configAction   = new QAction ( tr("Configure"), 
                                  QIconSet(QPixmap((const char **)config_xpm)), 
                                  tr("Configure ..."), 
                                  Key_F2, 
                                  this );
  m_quitAction     = new QAction ( tr("Quit"), 
                                  QIconSet(QPixmap((const char **)quit_xpm)), 
                                  tr("Quit"), 
                                  CTRL+Key_Q, 
                                  this );
  m_helpAction     = new QAction ( tr("Help"), 
                                  QIconSet(QPixmap((const char **)help_xpm)), 
                                  tr("Direct Help"), 
                                  SHIFT+Key_F1, 
                                  this );
  m_versionAction  = new QAction ( this );
  m_versionAction->setText( tr("On version") );
  m_versionAction->setMenuText( tr("On version...") );
    
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
  connect( m_quitAction, SIGNAL( activated() ),
           m_wid, SLOT( quitSLOT() ));
  connect( m_helpAction, SIGNAL( activated() ),
           m_wid, SLOT( helpSLOT() ));
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
  QMessageBox version( tr("QtDMM: Welcome!" ),
                       tr("<h1>QtDMM 0.4</h1><hr>"
                          "<div align=right><i>A simple recorder for DMM's</i></div><p><br>"
                          "A simple display software for <b>Metex</b> and compatible hand held"
                          " digital multimeter including min/max memory and a configurable "
                          "recorder with import/export and printing function. Sampling may"
                          " be started manually, at a given time or triggered by a measured threshold<p>"
                          "<b>QtDMM</b> uses the platform independent toolkit "
                          "<b>Qt</b> from Trolltech AS Norway <font color=blue><u>www.trolltech.com</u></font>"
                          " and is licensed under <b>GPL</b>.<p><br>"
                          "&copy; 2001 Matthias Toussaint<br><font color=blue><u>qtdmm@mtoussaint.de</u></font>"
                          "<p><br>The icons (except the DMM icon) are taken from the KDE project.<p>" ),
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
}

void
MainWin::createMenu()
{
  QToolBar *tb = new QToolBar( this );
  QMenuBar *menu = new QMenuBar( tb );
  menu->setFrameStyle( QFrame::NoFrame );
  tb->setStretchableWidget( menu ); 
  addToolBar( tb, tr("Menubar"), QMainWindow::Top, false );
  setDockEnabled( tb, Left, false );
  setDockEnabled( tb, Right, false );
  
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
  
  menu->insertItem( tr("DMM"), dmm );
  
  QPopupMenu *recorder = new QPopupMenu( menu );
  m_startAction->addTo( recorder );
  m_stopAction->addTo( recorder );
  recorder->insertSeparator();
  m_clearAction->addTo( recorder );
  
  menu->insertItem( tr("Recorder"), recorder );
  
  QPopupMenu *help = new QPopupMenu( menu );
  m_versionAction->addTo( help );
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
