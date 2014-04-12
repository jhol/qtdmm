//======================================================================
// File:		configdlg.h
// Author:	Matthias Toussaint
// Created:	Tue Apr 10 17:22:30 CEST 2001
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

#ifndef CONFIGDLG_HH
#define CONFIGDLG_HH

#include <uiconfigdlg.h>
#include <simplecfg.h>
#include <qcombobox.h>
#include <dmmgraph.h>
#include <readevent.h>

class QPrinter;

struct DMMInfo
{
  char *name;
  int   baud;
  int   protocol;
  int   bits;
  int   stopBits;
  int   ignoreLines;
};

class ConfigDlg : public UIConfigDlg
{
  Q_OBJECT
public:
  ConfigDlg( QWidget *parent=0, const char *name=0 );
  virtual ~ConfigDlg();
  
  QString device() const { return port->currentText(); }
  int speed() const;
  int windowSeconds() const;
  int totalSeconds() const;
  QTime startTime() const;
  DMMGraph::SampleMode sampleMode() const;
  int sampleStep() const;
  int sampleLength() const;
  double raisingThreshold() const;
  double fallingThreshold() const;
  double scaleMin() const;
  double scaleMax() const;
  bool automaticScale() const;
  ReadEvent::DataFormat format() const;
  int bits() const;
  int stopBits() const;
  int ignoreLines() const;
  QColor bgColor() const;
  QColor gridColor() const;
  QColor dataColor() const;
  QColor cursorColor() const;
  QColor displayBgColor() const;
  QColor displayTextColor() const;
  int lineWidth() const;
  void writePrinter( QPrinter * );
  void readPrinter( QPrinter * );
  void setWinRect( const QRect & );
  QRect winRect() const;
  bool saveWindowPosition() const;
  bool alertUnsavedData() const;
  bool useTextLabel() const;
  
public slots:
  void connectSLOT( bool );
  void applySLOT();
  void setSampleTimeSLOT( int );
  void setGraphSizeSLOT( int,int );
  
signals:
  void accepted();

protected:
  SimpleCfg *m_cfg;
  QPrinter  *m_printer;
  QRect      m_winRect;
  
protected slots:
  void cancelSLOT();
  void helpSLOT();
  void modelSLOT( int );
  void recorderDefaultSLOT();
  void recorderFactorySLOT();
  void scaleDefaultSLOT();
  void scaleFactorySLOT();
  void dmmDefaultSLOT();
  void dmmFactorySLOT();
  void preferencesDefaultSLOT();
  void preferencesFactorySLOT();
  
};

#endif // CONFIGDLG_HH

