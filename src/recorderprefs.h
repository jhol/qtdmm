//======================================================================
// File:		recorderprefs.h
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 14:34:19 CEST 2002
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

#ifndef RECORDERPREFS_HH
#define RECORDERPREFS_HH

#include <uirecorderprefs.h>
#include <dmmgraph.h>

class RecorderPrefs : public UIRecorderPrefs
{
  Q_OBJECT
public:
  RecorderPrefs( QWidget *parent=0, const char *name=0 );
  virtual ~RecorderPrefs();
  
  DMMGraph::SampleMode sampleMode() const;
  int sampleStep() const;
  int sampleLength() const;
  double fallingThreshold() const;
  double raisingThreshold() const;
  QTime startTime() const;
  void setThreshold( double );
  
public slots:
  virtual void defaultsSLOT();
  virtual void factoryDefaultsSLOT();
  virtual void applySLOT();

  void setSampleTimeSLOT( int sampleTime );
  
};

#endif // RECORDERPREFS_HH

