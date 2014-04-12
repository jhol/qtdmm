//======================================================================
// File:		dmmprefs.h
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 15:08:57 CEST 2002
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

#ifndef DMMPREFS_HH
#define DMMPREFS_HH

#include <prefwidget.h>
#include <readevent.h>

#include <ui_uidmmprefs.h>

struct DMMInfo
{
  const char *name;
  int   baud;
  int   protocol;
  int   bits;
  int   stopBits;
  int   numValues;
  int   parity;
  int   display;
  bool  externalSetup;
  bool  rts;
  bool  cts;
  bool  dsr;
  bool  dtr;
};

class DmmPrefs : public PrefWidget, public Ui::UIDmmPrefs
{
  Q_OBJECT
public:
  DmmPrefs( QWidget *parent=0, const char *name=0 );
  virtual ~DmmPrefs();
  
  int parity() const;
  int bits() const;
  int stopBits() const;
  int speed() const;
  int numValues() const;
  bool externalSetup() const;
  bool rts() const;
  bool cts() const;
  bool dsr() const;
  bool dtr() const;
  ReadEvent::DataFormat format() const;
  int display() const;
  QString dmmName() const;
  QString device() const;
  
  QString deviceListText() const;

public slots:
  virtual void defaultsSLOT();
  virtual void factoryDefaultsSLOT();
  virtual void applySLOT();

protected slots:
  void modelSLOT( int );
  void loadSLOT();
  void saveSLOT();
  // empty function as damn moc doesn't know about defines
  void scanDevicesSLOT();
  void externalSetupSLOT();
  
protected:
  QString m_path;
      
};

#endif // DMMPREFS_HH

