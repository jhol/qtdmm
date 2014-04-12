//======================================================================
// File:		scaleprefs.h
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 15:33:41 CEST 2002
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

#ifndef SCALEPREFS_HH
#define SCALEPREFS_HH

#include <uiscaleprefs.h>

class ScalePrefs : public UIScalePrefs
{
  Q_OBJECT
public:
  ScalePrefs( QWidget *parent=0, const char *name=0 );
  virtual ~ScalePrefs();

  bool automaticScale() const;
  bool includeZero() const;
  double scaleMin() const;
  double scaleMax() const;
  int windowSeconds() const;
  int totalSeconds() const;
  
public slots:
  virtual void defaultsSLOT();
  virtual void factoryDefaultsSLOT();
  virtual void applySLOT();
  
  void setAutoScaleSLOT( bool autoScale );
  void zoomInSLOT( double fac );
  void zoomOutSLOT( double fac );
  void setGraphSizeSLOT( int size, int length );
  
};

#endif // SCALEPREFS_HH

