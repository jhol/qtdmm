//======================================================================
// File:		mainwin.h
// Author:	Matthias Toussaint
// Created:	Sun Sep  2 12:14:07 CEST 2001
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

#ifndef MAINWIN_HH
#define MAINWIN_HH

#include <qmainwindow.h>

class MainWid;
class QAction;
class QToolBar;
class QLabel;
class DisplayWid;

class MainWin : public QMainWindow
{
  Q_OBJECT
public:
  MainWin( QWidget *parent=0, const char *name=0 );
  virtual ~MainWin();

  void setConsoleLogging( bool );
  
protected slots:
  void runningSLOT( bool );
  void connectSLOT( bool );
  void versionSLOT();
  void setConnectSLOT( bool );
  void toolbarVisibilitySLOT( bool, bool, bool, bool, bool );
  void setToolbarVisibilitySLOT();
  
protected:
  MainWid     *m_wid;  
  QToolBar    *m_dmmTB;
  QToolBar    *m_graphTB;
  QToolBar    *m_fileTB;
  QToolBar    *m_helpTB;
  QToolBar    *m_displayTB;
  DisplayWid  *m_display;
  QAction     *m_connectAction;
  QAction     *m_resetAction;
  QAction     *m_startAction;
  QAction     *m_stopAction;
  QAction     *m_clearAction;
  QAction     *m_printAction;
  QAction     *m_exportAction;
  QAction     *m_importAction;
  QAction     *m_configAction;
  QAction     *m_configDmmAction;
  QAction     *m_configRecorderAction;
  QAction     *m_quitAction;
  QAction     *m_helpAction;
  QAction     *m_showTipsAction;
  QAction     *m_versionAction;
  bool         m_running;
  QLabel      *m_error;
  QLabel      *m_info;
  
  void createToolBars();
  void createActions();
  void createMenu();
  void closeEvent( QCloseEvent * );
};

#endif // MAINWIN_HH
