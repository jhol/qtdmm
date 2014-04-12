//======================================================================
// File:		graphprefs.cpp
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 15:27:46 CEST 2002
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

#include <qcheckbox.h>
#include <qcombobox.h>
#include <qspinbox.h>

#include <colorbutton.h>
#include <graphprefs.h>
#include <simplecfg.h>

#include <graph.xpm>

GraphPrefs::GraphPrefs( QWidget *parent, const char *name ) :
  PrefWidget( parent, name )
{
  setupUi(this);

  m_label = tr( "Graph settings" );
  m_description = tr( "<b>Here you can configure the colors and"
                      " drawing style for the graph.</b>" );
  m_pixmap = new QPixmap( (const char **)graph_xpm );
}

GraphPrefs::~GraphPrefs()
{
}

void
GraphPrefs::defaultsSLOT()
{
  ui_bgColor->setColor( QColor( m_cfg->getRGB( "Graph", "background", Qt::white.rgb() )));
  ui_gridColor->setColor( QColor( m_cfg->getRGB( "Graph", "grid", Qt::gray.rgb() )));
  ui_dataColor->setColor( QColor( m_cfg->getRGB( "Graph", "data", Qt::blue.rgb() )));
  ui_cursorColor->setColor( QColor( m_cfg->getRGB( "Graph", "cursor", Qt::black.rgb() )));
  ui_startColor->setColor( QColor( m_cfg->getRGB( "Graph", "start-trigger", Qt::magenta.rgb() )));
  ui_extColor->setColor( QColor( m_cfg->getRGB( "Graph", "external-trigger", Qt::cyan.rgb() )));
  
  ui_lineMode->setCurrentItem( m_cfg->getInt( "Graph", "line-mode", 1 ));
  ui_pointMode->setCurrentItem( m_cfg->getInt( "Graph", "point-mode", 0 ));
  ui_crosshair->setChecked( m_cfg->getBool( "Graph", "crosshair-cursor", true ));
  
  ui_lineWidth->setValue( m_cfg->getInt( "Graph", "line-width", 2 ) );
  
}

void
GraphPrefs::factoryDefaultsSLOT()
{
  ui_bgColor->setColor( Qt::white );
  ui_gridColor->setColor( Qt::gray );
  ui_dataColor->setColor( Qt::blue );
  ui_cursorColor->setColor( Qt::black );
  ui_startColor->setColor( Qt::magenta.rgb() );
  ui_extColor->setColor( Qt::cyan.rgb() );
  ui_lineMode->setCurrentItem( 1 );
  ui_pointMode->setCurrentItem( 0 );  
  ui_lineWidth->setValue( 2 );
  ui_crosshair->setChecked( true );

}

void
GraphPrefs::applySLOT()
{
  m_cfg->setRGB( "Graph", "background", ui_bgColor->color().rgb() );
  m_cfg->setRGB( "Graph", "grid", ui_gridColor->color().rgb() );
  m_cfg->setRGB( "Graph", "data", ui_dataColor->color().rgb() );
  m_cfg->setRGB( "Graph", "cursor", ui_cursorColor->color().rgb() );
  m_cfg->setRGB( "Graph", "start-trigger", ui_startColor->color().rgb() );
  m_cfg->setRGB( "Graph", "external-trigger", ui_extColor->color().rgb() );
  m_cfg->setInt( "Graph", "line-width", ui_lineWidth->value() );
  m_cfg->setInt( "Graph", "line-mode", ui_lineMode->currentItem() );
  m_cfg->setInt( "Graph", "point-mode", ui_pointMode->currentItem() );
  m_cfg->setBool( "Graph", "crosshair-cursor", ui_crosshair->isChecked() );
}

QColor
GraphPrefs::bgColor() const
{
  return ui_bgColor->color();
}

QColor
GraphPrefs::gridColor() const
{
  return ui_gridColor->color();
}

QColor
GraphPrefs::dataColor() const
{
  return ui_dataColor->color();
}

QColor
GraphPrefs::startColor() const
{
  return ui_startColor->color();
}

QColor
GraphPrefs::externalColor() const
{
  return ui_extColor->color();
}

QColor
GraphPrefs::cursorColor() const
{
  return ui_cursorColor->color();
}

int
GraphPrefs::lineWidth() const
{
  return ui_lineWidth->value();
}

int
GraphPrefs::lineMode() const
{
  return ui_lineMode->currentItem();
}

int
GraphPrefs::pointMode() const
{
  return ui_pointMode->currentItem();
}

bool
GraphPrefs::crosshair() const
{
  return ui_crosshair->isChecked();
}
