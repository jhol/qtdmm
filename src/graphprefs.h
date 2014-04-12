//======================================================================
// File:		graphprefs.h
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 15:28:30 CEST 2002
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

#ifndef GRAPHPREFS_HH
#define GRAPHPREFS_HH

#include <uigraphprefs.h>

class GraphPrefs : public UIGraphPrefs
{
  Q_OBJECT
public:
  GraphPrefs( QWidget *parent=0, const char *name=0 );
  virtual ~GraphPrefs();
  
  QColor bgColor() const;
  QColor gridColor() const;
  QColor dataColor() const;
  QColor startColor() const;
  QColor externalColor() const;
  QColor cursorColor() const;
  int    lineWidth() const;
  int    lineMode() const;
  int    pointMode() const;
  bool   crosshair() const;

public slots:
  virtual void defaultsSLOT();
  virtual void factoryDefaultsSLOT();
  virtual void applySLOT();
  
};

#endif // GRAPHPREFS_HH

