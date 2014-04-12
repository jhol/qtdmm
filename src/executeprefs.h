//======================================================================
// File:		executeprefs.h
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 15:26:02 CEST 2002
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

#ifndef EXECUTEPREFS_HH
#define EXECUTEPREFS_HH

#include <uiexecuteprefs.h>

class ExecutePrefs : public UIExecutePrefs
{
  Q_OBJECT
public:
  ExecutePrefs( QWidget *parent=0, const char *name=0 );
  virtual ~ExecutePrefs();

  bool startExternal() const;
  bool externalFalling() const;
  double externalThreshold() const;
  bool disconnectExternal() const;
  QString externalCommand() const;
  void setThreshold( double );
  
public slots:
  virtual void defaultsSLOT();
  virtual void factoryDefaultsSLOT();
  virtual void applySLOT();
  
protected slots:
  void browseExecSLOT();

};

#endif // EXECUTEPREFS_HH

