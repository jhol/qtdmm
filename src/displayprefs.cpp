//======================================================================
// File:		displayprefs.cpp
// Author:	Matthias Toussaint
// Created:	Sun Nov 24 15:08:22 CET 2002
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

#include <colorbutton.h>
#include <displayprefs.h>
#include <simplecfg.h>

#include <display.xpm>

DisplayPrefs::DisplayPrefs( QWidget *parent, const char *name ) :
  UIDisplayPrefs( parent, name )
{
  m_label = tr( "Display settings" );
  m_description = tr( "<b>Here you can configure the visual"
                      " appearance of the DMM display.</b>" );
  m_pixmap = new QPixmap( (const char **)display_xpm );
}

DisplayPrefs::~DisplayPrefs()
{
}

void
DisplayPrefs::defaultsSLOT()
{
  ui_bgColorDisplay->setColor( QColor( m_cfg->getRGB( "Display", "display-background", QColor( 212,220,207 ).rgb() )));
  ui_textColor->setColor( QColor( m_cfg->getRGB( "Display", "display-text", Qt::black.rgb() )));
  
  ui_showBar->setChecked( m_cfg->getBool( "Display", "display-bar", true ));
  ui_showMinMax->setChecked( m_cfg->getBool( "Display", "display-min-max", true ));
}

void
DisplayPrefs::factoryDefaultsSLOT()
{
  ui_bgColorDisplay->setColor( QColor( 212,220,207 ) );
  ui_textColor->setColor( Qt::black );

  ui_showBar->setChecked( true );
  ui_showMinMax->setChecked( true );
}

void
DisplayPrefs::applySLOT()
{
  m_cfg->setRGB( "Display", "display-background", ui_bgColorDisplay->color().rgb() );
  m_cfg->setRGB( "Display", "display-text", ui_textColor->color().rgb() );
  m_cfg->setBool( "Display", "display-bar", showBar() );
  m_cfg->setBool( "Display", "display-min-max", showMinMax() );
}

bool 
DisplayPrefs::showBar() const
{
  return ui_showBar->isChecked();
}

bool 
DisplayPrefs::showMinMax() const
{
  return ui_showMinMax->isChecked();
}

QColor
DisplayPrefs::displayBgColor() const
{
  return ui_bgColorDisplay->color();
}

QColor
DisplayPrefs::displayTextColor() const
{
  return ui_textColor->color();
}
