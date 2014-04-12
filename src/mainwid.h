//======================================================================
// File:		mainwid.h
// Author:	Matthias Toussaint
// Created:	Tue Apr 10 17:25:07 CEST 2001
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

#ifndef MAINWID_HH
#define MAINWID_HH

#include <uimainwid.h>
#include <dmm.h>
#include <printdlg.h>
#include <qprinter.h>

class ConfigDlg;

class MainWid : public UIMainWid
{
  Q_OBJECT
public:
  MainWid( QWidget *parent=0, const char *name=0 );
  virtual ~MainWid();

  bool closeWin();
  QRect winRect() const;

signals:
  void running( bool );
  void info( const QString & );
  void error( const QString & );
  void useTextLabel( bool );
  void winGeometry( const QRect & );
  void setConnect( bool );
  
public slots:
  void valueSLOT( double, const QString &, const QString &, const QString & );
  void resetSLOT();
  void connectSLOT( bool );
  void quitSLOT();
  void helpSLOT();
  void clearSLOT();
  void startSLOT();
  void stopSLOT();
  void configSLOT();
  void printSLOT();
  void exportSLOT();
  void importSLOT();
  void runningSLOT( bool );
  void applySLOT();
  
protected:
  DMM       *m_dmm;
  double     m_min;
  double     m_max;
  QString    m_lastUnit;
  ConfigDlg *m_configDlg;
  PrintDlg  *m_printDlg;
  QPrinter   m_printer;
  
  void readConfig();
  QRect parentRect() const;
};

#endif // MAINWID_HH
