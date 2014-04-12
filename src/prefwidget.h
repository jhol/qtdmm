//======================================================================
// File:		prefwidget.h
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 14:22:16 CEST 2002
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

#ifndef PREFWIDGET_HH
#define PREFWIDGET_HH

#include <qwidget.h>
#include <qpixmap.h>

class SimpleCfg;

class PrefWidget : public QWidget
{
  Q_OBJECT
public:
  PrefWidget( QWidget *parent=0, const char *name=0 );
  virtual ~PrefWidget();

  QString label() const { return m_label; }
  QString description() const { return m_description; }
  QPixmap pixmap() const { return *m_pixmap; }
  
  void setId( int id ) { m_id = id; }
  int id() const { return m_id; }
  
  void setCfg( SimpleCfg *cfg ) { m_cfg = cfg; }
  
public slots:
  virtual void defaultsSLOT() = 0;
  virtual void factoryDefaultsSLOT() = 0;
  virtual void applySLOT() = 0;

protected:
  SimpleCfg *m_cfg;
  QString    m_label;
  QString    m_description;
  QPixmap   *m_pixmap;
  int        m_id;

};

#endif // PREFWIDGET_HH
