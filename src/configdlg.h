//======================================================================
// File:		configdlg.h
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 14:53:06 CEST 2002
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
// (c) 2000-2002 Matthias Toussaint
//======================================================================

#ifndef CONFIGDLG_HH
#define CONFIGDLG_HH

#include <uiconfigdlg.h>
#include <dmmgraph.h>
#include <readevent.h>

class SimpleCfg;
class QPrinter;
class RecorderPrefs;
class ScalePrefs;
class DmmPrefs;
class GuiPrefs;
class GraphPrefs;
class IntegrationPrefs;
class ExecutePrefs;

class ConfigDlg : public UIConfigDlg
{
  Q_OBJECT
public:
  enum PageType
  {
    Recorder = 0,
    Scale,
    DMM,
    GUI,
    Graph,
    Integration,
    External,
    NumItems
  };
    
  ConfigDlg( QWidget *parent=0, const char *name=0 );
  virtual ~ConfigDlg();

  QString device() const;
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
  bool includeZero() const;
  bool showMinMax() const;
  bool showBar() const;
  ReadEvent::DataFormat format() const;
  int parity() const;
  int display() const;
  int bits() const;
  int stopBits() const;
  int numValues() const;
  QColor bgColor() const;
  QColor gridColor() const;
  QColor dataColor() const;
  QColor cursorColor() const;
  QColor displayBgColor() const;
  QColor displayTextColor() const;
  QColor startColor() const;
  QColor externalColor() const;
  QColor intColor() const;
  QColor intThresholdColor() const;
  int lineWidth() const;
  int intLineWidth() const;
  int lineMode() const;
  int pointMode() const;
  int intLineMode() const;
  int intPointMode() const;
  void writePrinter( QPrinter * );
  void readPrinter( QPrinter * );
  void setWinRect( const QRect & );
  QRect winRect() const;
  bool saveWindowPosition() const;
  bool saveWindowSize() const;
  bool alertUnsavedData() const;
  bool useTextLabel() const;
  bool startExternal() const;
  bool externalFalling() const;
  double externalThreshold() const;
  QString externalCommand() const;
  bool disconnectExternal() const;
  bool crosshair() const;
  double intScale() const;
  double intThreshold() const;
  double intOffset() const;
  bool showIntegration() const;
  bool showTip() const;
  int currentTipId() const;
  QString dmmName() const;
  void showPage( PageType );
  bool showDmmToolbar() const;
  bool showGraphToolbar() const;
  bool showFileToolbar() const;
  bool showHelpToolbar() const;
  bool showDisplay() const;
  void setToolbarVisibility( bool, bool, bool, bool, bool );
  
  QString deviceListText() const;

public slots:
  void connectSLOT( bool );
  void applySLOT();
  void setSampleTimeSLOT( int );
  void setGraphSizeSLOT( int,int );
  void setShowTipsSLOT( bool );
  void setCurrentTipSLOT( int );
  void zoomInSLOT( double );
  void zoomOutSLOT( double );
  void cancelSLOT();
  void thresholdChangedSLOT( DMMGraph::CursorMode, double );
  
signals:
  void accepted();
  void showTips( bool );
  void zoomed();
  
protected:
  SimpleCfg         *m_cfg;
  QPrinter          *m_printer;
  QRect              m_winRect;
  RecorderPrefs     *m_recorder;
  ScalePrefs        *m_scale;
  DmmPrefs          *m_dmm;
  GuiPrefs          *m_gui;
  GraphPrefs        *m_graph;
  IntegrationPrefs  *m_integration;
  ExecutePrefs      *m_execute;
  
protected slots:
  void pageSelectedSLOT( QListViewItem *item );
  void factoryDefaultsSLOT();
  
};

#endif // CONFIGDLG_HH
