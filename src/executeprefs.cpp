//======================================================================
// File:		executeprefs.cpp
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 15:26:42 CEST 2002
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
#include <qfiledialog.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qradiobutton.h>

#include <engnumbervalidator.h>
#include <executeprefs.h>
#include <simplecfg.h>

#include <execute.xpm>

ExecutePrefs::ExecutePrefs( QWidget *parent, const char *name ) :
  UIExecutePrefs( parent, name )
{
  m_label = tr( "External application" );
  m_description = tr( "<b>Here you can configure if an external"
                      " command is to be started and when.</b>" );
  m_pixmap = new QPixmap( (const char **)execute_xpm );
  
  EngNumberValidator *validator = new EngNumberValidator( this );
  
  ui_execRaisingThreshold->setValidator( validator );
  ui_execFallingThreshold->setValidator( validator );
  
  connect( ui_browseExec, SIGNAL( clicked() ),
           this, SLOT( browseExecSLOT() ));
}

ExecutePrefs::~ExecutePrefs()
{
}

void
ExecutePrefs::defaultsSLOT()
{
  ui_executeCommand->setChecked( m_cfg->getBool( "External", "exec", false ));
  
  ui_execRaising->setChecked( m_cfg->getBool( "External", "raising", true ));
  ui_execRaisingThreshold->setText( m_cfg->getString( "External", "raising-threshold", "" ));
  ui_execFallingThreshold->setText( m_cfg->getString( "External", "falling-threshold", "" ));
  
  ui_disconnectExec->setChecked( m_cfg->getBool( "External", "disconnect", false ));
  ui_commandExec->setText( m_cfg->getString( "External", "command", "" ));
}

void
ExecutePrefs::factoryDefaultsSLOT()
{
  ui_executeCommand->setChecked( false );
  
  ui_execRaising->setChecked( true );
  ui_execRaisingThreshold->setText( "" );
  ui_execFallingThreshold->setText( "" );
  
  ui_disconnectExec->setChecked( false );
  ui_commandExec->setText( "" );
}

void
ExecutePrefs::applySLOT()
{
  m_cfg->setBool( "External", "exec", startExternal() );  
  m_cfg->setBool( "External", "raising", !externalFalling() );
  m_cfg->setString( "External", "raising-threshold", ui_execRaisingThreshold->text() );
  m_cfg->setString( "External", "falling-threshold", ui_execFallingThreshold->text() );  
  m_cfg->setBool( "External", "disconnect", disconnectExternal() );
  m_cfg->setString( "External", "command", externalCommand() );
}

bool
ExecutePrefs::startExternal() const
{
  return ui_executeCommand->isChecked();
}

bool
ExecutePrefs::externalFalling() const
{
  return ui_execFalling->isChecked();
}

double
ExecutePrefs::externalThreshold() const
{
  if (ui_execFalling->isChecked())
  {
    return EngNumberValidator::value( ui_execFallingThreshold->text() );
  }
  
  return EngNumberValidator::value( ui_execRaisingThreshold->text() );
}

void
ExecutePrefs::setThreshold( double value )
{
  if (ui_execFalling->isChecked())
  {
    ui_execFallingThreshold->setText( EngNumberValidator::engValue( value ) );
  }
  else
  {
    ui_execRaisingThreshold->setText( EngNumberValidator::engValue( value ) );
  }
}

bool
ExecutePrefs::disconnectExternal() const
{
  return ui_disconnectExec->isChecked();
}

QString
ExecutePrefs::externalCommand() const
{
  return ui_commandExec->text();
}

void
ExecutePrefs::browseExecSLOT()
{
  QString filename = QFileDialog::getOpenFileName( QString::null, "*", this );
    
  if (!filename.isEmpty()) 
  {
    ui_commandExec->setText( filename );
  }  
}
