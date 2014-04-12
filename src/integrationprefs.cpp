//======================================================================
// File:		integrationprefs.cpp
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 15:30:12 CEST 2002
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
#include <qspinbox.h>

#include <colorbutton.h>
#include <engnumbervalidator.h>
#include <integrationprefs.h>
#include <simplecfg.h>

#include <integration.xpm>

IntegrationPrefs::IntegrationPrefs( QWidget *parent, const char *name ) :
  UIIntegrationPrefs( parent, name )
{
  m_label = tr( "Integration" );
  m_description = tr( "<b>Here you can configure the parameter"
                      " for the integration curve.</b>" );
  m_pixmap = new QPixmap( (const char **)integration_xpm );

  EngNumberValidator *validator = new EngNumberValidator( this );
  
  ui_intScale->setValidator( validator );
  ui_intThreshold->setValidator( validator );
  ui_intOffset->setValidator( validator );
}

IntegrationPrefs::~IntegrationPrefs()
{
}

void
IntegrationPrefs::defaultsSLOT()
{
  ui_intColor->setColor( QColor( m_cfg->getRGB( "Graph", "integration", Qt::darkBlue.rgb() )));
  ui_intThresholdColor->setColor( QColor( m_cfg->getRGB( "Graph", "integration-threshold", Qt::darkBlue.rgb() )));
  ui_intLineMode->setCurrentItem( m_cfg->getInt( "Graph", "int-line-mode", 0 ));
  ui_intPointMode->setCurrentItem( m_cfg->getInt( "Graph", "int-point-mode", 1 ));  
  ui_showInt->setChecked( m_cfg->getBool( "Graph", "show-integration", false ));  
  ui_intScale->setText( m_cfg->getString( "Graph", "int-scale", "1.0" ));
  ui_intOffset->setText( m_cfg->getString( "Graph", "int-offset", "0.0" ));
  ui_intThreshold->setText( m_cfg->getString( "Graph", "int-threshold", "0.0" ));
  ui_intLineWidth->setValue( m_cfg->getInt( "Graph", "int-line-width", 2 ) );
}

void
IntegrationPrefs::factoryDefaultsSLOT()
{
  ui_intColor->setColor( Qt::darkBlue );
  ui_intThresholdColor->setColor( Qt::darkBlue.rgb() );
  ui_intLineMode->setCurrentItem( 0 );
  ui_intPointMode->setCurrentItem( 1 );
  ui_intLineWidth->setValue( 1 );
  ui_showInt->setChecked( false );  
  ui_intScale->setText( "0.1" );
  ui_intOffset->setText( "0.0" );
  ui_intThreshold->setText( "0.0" );
}

void
IntegrationPrefs::applySLOT()
{
  m_cfg->setRGB( "Graph", "integration", ui_intColor->color().rgb() );
  m_cfg->setRGB( "Graph", "integration-threshold", ui_intThresholdColor->color().rgb() );
  m_cfg->setInt( "Graph", "int-line-width", ui_intLineWidth->value() );
  m_cfg->setInt( "Graph", "int-line-mode", ui_intLineMode->currentItem() );
  m_cfg->setInt( "Graph", "int-point-mode", ui_intPointMode->currentItem() );
  m_cfg->setBool( "Graph", "show-integration", ui_showInt->isChecked() );
  m_cfg->setString( "Graph", "int-scale", ui_intScale->text() );
  m_cfg->setString( "Graph", "int-offset", ui_intOffset->text() );
  m_cfg->setString( "Graph", "int-threshold", ui_intThreshold->text() );
}

double
IntegrationPrefs::intScale() const
{
  return EngNumberValidator::value( ui_intScale->text() );
}

double
IntegrationPrefs::intThreshold() const
{
  return EngNumberValidator::value( ui_intThreshold->text() );
}

double
IntegrationPrefs::intOffset() const
{
  return EngNumberValidator::value( ui_intOffset->text() );
}

void
IntegrationPrefs::setThreshold( double value )
{
  ui_intThreshold->setText( EngNumberValidator::engValue( value ) );
}

bool
IntegrationPrefs::showIntegration() const
{
  return ui_showInt->isChecked();
}

QColor
IntegrationPrefs::intColor() const
{
  return ui_intColor->color();
}

QColor
IntegrationPrefs::intThresholdColor() const
{
  return ui_intThresholdColor->color();
}

int
IntegrationPrefs::intLineWidth() const
{
  return ui_intLineWidth->value();
}

int
IntegrationPrefs::intLineMode() const
{
  return ui_intLineMode->currentItem();
}

int
IntegrationPrefs::intPointMode() const
{
  return ui_intPointMode->currentItem();
}
