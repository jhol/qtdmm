//======================================================================
// File:		guiprefs.h
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 15:29:05 CEST 2002
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

#ifndef GUIPREFS_HH
#define GUIPREFS_HH

#include <uiguiprefs.h>

class GuiPrefs : public UIGuiPrefs
{
  Q_OBJECT
public:
  GuiPrefs( QWidget *parent=0, const char *name=0 );
  virtual ~GuiPrefs();
  
  bool showTip() const;
  bool showBar() const;
  bool showMinMax() const;
  bool alertUnsavedData() const;
  bool useTextLabel() const;
  QColor displayBgColor() const;
  QColor displayTextColor() const;
  bool saveWindowPosition() const;
  bool saveWindowSize() const;
  void setShowTipsSLOT( bool on );
  bool showDmmToolbar() const;
  bool showGraphToolbar() const;
  bool showFileToolbar() const;
  bool showHelpToolbar() const;
  bool showDisplay() const;
  void setToolbarVisibility( bool, bool, bool, bool, bool );
  
signals:
  void showTips( bool );
  
public slots:
  virtual void defaultsSLOT();
  virtual void factoryDefaultsSLOT();
  virtual void applySLOT();
  
};

#endif // GUIPREFS_HH

