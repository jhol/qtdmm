//======================================================================
// File:		scaleprefs.cpp
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 15:34:13 CEST 2002
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
#include <qlineedit.h>
#include <qradiobutton.h>
#include <qspinbox.h>

#include <engnumbervalidator.h>
#include <scaleprefs.h>
#include <simplecfg.h>

#include <scale.xpm>

#define MINUTE_SECS   60
#define HOUR_SECS     60*60
#define DAY_SECS      60*60*24

ScalePrefs::ScalePrefs( QWidget *parent, const char *name ) :
  UIScalePrefs( parent, name )
{
  m_label = tr( "Scale settings" );
  m_description = tr( "<b>Here you can configure the vertical scale"
                      " of the recorder and the length (in time)"
                      " of the window.</b>" );
  m_pixmap = new QPixmap( (const char **)scale_xpm );
  
  EngNumberValidator *validator = new EngNumberValidator( this );
  
  ui_scaleMin->setValidator( validator );
  ui_scaleMax->setValidator( validator );
}

ScalePrefs::~ScalePrefs()
{
}

void
ScalePrefs::defaultsSLOT()
{
  bool autoScale = m_cfg->getBool( "Scale", "automatic", true );
  if (autoScale)
  {
    autoScaleBut->setChecked( true );
  }
  else
  {
    manualScaleBut->setChecked( true );
  }

  bool includeZero = m_cfg->getBool( "Scale", "automatic-include-zero", true );
  if (includeZero)
  {
    ui_includeZero->setChecked( true );
  }
  else
  {
    ui_includeZero->setChecked( false );
  }

  ui_scaleMin->setText( m_cfg->getString( "Scale", "minimum", "-3.999" ));
  ui_scaleMax->setText( m_cfg->getString( "Scale", "maximum", "3.999" ));
  
  ui_winSize->setValue( m_cfg->getInt( "Window", "size", 600 ));
  sizeUnit->setCurrentItem( m_cfg->getInt( "Window", "size-unit", 0 ));
  winLength->setValue( m_cfg->getInt( "Window", "length", 3600 ));
  lengthUnit->setCurrentItem( m_cfg->getInt( "Window", "length-unit", 0 ));
}

void
ScalePrefs::factoryDefaultsSLOT()
{
  autoScaleBut->setChecked( true );
  ui_includeZero->setChecked( true );
  
  ui_scaleMin->setText( "-3.999" );
  ui_scaleMax->setText( "3.999" );
  
  ui_winSize->setValue( 600 );
  sizeUnit->setCurrentItem( 0 );
  winLength->setValue( 3600 );
  lengthUnit->setCurrentItem( 0 );
}

void
ScalePrefs::applySLOT()
{
  m_cfg->setBool( "Scale", "automatic", automaticScale() );
  m_cfg->setBool( "Scale", "automatic-include-zero", includeZero() );
  m_cfg->setString( "Scale", "minimum", ui_scaleMin->text() );
  m_cfg->setString( "Scale", "maximum", ui_scaleMax->text() );  
  m_cfg->setInt( "Window", "size", ui_winSize->value() );
  m_cfg->setInt( "Window", "size-unit", sizeUnit->currentItem() );
  m_cfg->setInt( "Window", "length", winLength->value() );
  m_cfg->setInt( "Window", "length-unit", lengthUnit->currentItem() );
}

bool
ScalePrefs::includeZero() const
{
  return ui_includeZero->isChecked();
}

bool 
ScalePrefs::automaticScale() const
{
  return autoScaleBut->isChecked();
}

double
ScalePrefs::scaleMin() const
{
  return EngNumberValidator::value( ui_scaleMin->text() );
}

double
ScalePrefs::scaleMax() const
{
  return EngNumberValidator::value( ui_scaleMax->text() );
}

void
ScalePrefs::zoomInSLOT( double fac )
{
  double val = ui_winSize->value();
  
  if (val > 10)
  {
    val /= fac;
  }
  else
  {
    val /= 2.;
  }
  
  val = QMAX( 1, val );
  
  ui_winSize->setValue( (int)val );
}

void
ScalePrefs::zoomOutSLOT( double fac )
{
  double val = ui_winSize->value();
  
  if (val > 10)
  {
    val *= fac;
  }
  else
  {
    val *= 2.;
  }
  
  val = QMAX( 2, val );
  ui_winSize->setValue( (int)val );
}

int
ScalePrefs::windowSeconds() const
{
  int sec = ui_winSize->text().toInt();
  
  switch (sizeUnit->currentItem())
  {
  case 1:
    sec *= MINUTE_SECS;
    break;
  case 2:
    sec *= HOUR_SECS;
    break;
  case 3:
    sec *= DAY_SECS;
    break;
  }
  
  return sec;
}

int
ScalePrefs::totalSeconds() const
{
  int sec = winLength->text().toInt();
  
  switch (lengthUnit->currentItem())
  {
  case 1:
    sec *= MINUTE_SECS;
    break;
  case 2:
    sec *= HOUR_SECS;
    break;
  case 3:
    sec *= DAY_SECS;
    break;
  }
  
  return sec;
}

void
ScalePrefs::setGraphSizeSLOT( int size, int length )
{
  ui_winSize->setValue( size );
  winLength->setValue( length );
}
