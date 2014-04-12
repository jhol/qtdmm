//======================================================================
// File:		guiprefs.cpp
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 15:29:34 CEST 2002
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
#include <guiprefs.h>
#include <simplecfg.h>

#include <gui.xpm>

GuiPrefs::GuiPrefs( QWidget *parent, const char *name ) :
  UIGuiPrefs( parent, name )
{
  m_label = tr( "GUI settings" );
  m_description = tr( "<b>Here you can configure QtDMM's visual"
                      " appearance and behaviour.</b>" );
  m_pixmap = new QPixmap( (const char **)gui_xpm );
  
  connect( ui_tipOfTheDay, SIGNAL( toggled( bool ) ),
           this, SIGNAL( showTips( bool ) ));
}

GuiPrefs::~GuiPrefs()
{
}

void
GuiPrefs::defaultsSLOT()
{
  ui_saveWindowCheck->setChecked( m_cfg->getBool( "Save", "window", true ));
  
  ui_bgColorDisplay->setColor( QColor( m_cfg->getRGB( "Display", "display-background", QColor( 212,220,207 ).rgb() )));
  ui_textColor->setColor( QColor( m_cfg->getRGB( "Display", "display-text", Qt::black.rgb() )));
  
  ui_showBar->setChecked( m_cfg->getBool( "Display", "display-bar", true ));
  ui_showMinMax->setChecked( m_cfg->getBool( "Display", "display-min-max", true ));
  
  ui_alertUnsavedData->setChecked( m_cfg->getBool( "Alert", "unsaved-file", true ));
  ui_textLabel->setChecked( m_cfg->getBool( "Icons", "text-label", true ));
  
  ui_tipOfTheDay->setChecked( m_cfg->getBool( "QtDMM", "show-tip", true ));
}

void
GuiPrefs::factoryDefaultsSLOT()
{
  ui_saveWindowCheck->setChecked( true );
  
  ui_bgColorDisplay->setColor( QColor( 212,220,207 ) );
  ui_textColor->setColor( Qt::black );

  ui_showBar->setChecked( true );
  ui_showMinMax->setChecked( true );
  
  ui_alertUnsavedData->setChecked( true );
  ui_textLabel->setChecked( true );
  
  ui_tipOfTheDay->setChecked( true );
}

void
GuiPrefs::applySLOT()
{
  m_cfg->setInt( "QtDMM", "version", 0 );
  m_cfg->setInt( "QtDMM", "revision", 62 );
  m_cfg->setBool( "QtDMM", "show-tip", showTip() );
  m_cfg->setRGB( "Display", "display-background", ui_bgColorDisplay->color().rgb() );
  m_cfg->setRGB( "Display", "display-text", ui_textColor->color().rgb() );
  m_cfg->setBool( "Display", "display-bar", showBar() );
  m_cfg->setBool( "Display", "display-min-max", showMinMax() );
  m_cfg->setBool( "Alert", "unsaved-file", alertUnsavedData() );  
  m_cfg->setBool( "Icons", "text-label", useTextLabel() );
}

bool
GuiPrefs::showTip() const
{
  return ui_tipOfTheDay->isChecked();
}

bool 
GuiPrefs::showBar() const
{
  return ui_showBar->isChecked();
}

bool 
GuiPrefs::showMinMax() const
{
  return ui_showMinMax->isChecked();
}

bool
GuiPrefs::alertUnsavedData() const
{
  return ui_alertUnsavedData->isChecked();
}

bool
GuiPrefs::useTextLabel() const
{
  return ui_textLabel->isChecked();
}

QColor
GuiPrefs::displayBgColor() const
{
  return ui_bgColorDisplay->color();
}

QColor
GuiPrefs::displayTextColor() const
{
  return ui_textColor->color();
}

bool
GuiPrefs::saveWindowPosition() const
{
  return ui_saveWindowCheck->isChecked();
}

void
GuiPrefs::setShowTipsSLOT( bool on )
{
  ui_tipOfTheDay->setChecked( on );
}
