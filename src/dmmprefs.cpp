//======================================================================
// File:		dmmprefs.cpp
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 15:26:51 CEST 2002
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

#include <qbuttongroup.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qspinbox.h>

#include <dmmprefs.h>
#include <simplecfg.h>

#include <dmm.xpm>

// when all needed parameter are found this hardcoded version will
// be replaced by a file
//    name
//    baud (600=0,1200,1800,2400,4800,9600)
//    protocol (14 bytes polling 'D'=0, 10 bytes continuous [PeakTech]
//              14 continuous, 15 continuous, 11 bin continuous)
//    bits
//    stopBits
//    number of values (For DMM's that send several lines at once)
//    parity (0,1,2 - None,Even,Odd) 
//    display digits (0,1,2,3 - 3 1/2, 3 3/4, 4 1/1, 4 3/4)
//
struct DMMInfo dmm_info[] = { 
                              {"ELV M9803R", 5, 4, 7, 1, 1, 1, 1},
                              {"Metex M-3660D", 1, 0, 7, 2, 1, 0, 1},
                              {"Metex M-3830D", 1, 0, 7, 2, 4, 0, 1},
                              {"Metex M-3850D", 1, 0, 7, 2, 4, 0, 1},
                              {"Metex ME-11", 0, 0, 7, 2, 1, 0, 1},
                              {"Metex ME-22", 3, 0, 7, 2, 1, 0, 1},
                              {"Metex ME-32", 0, 0, 7, 2, 1, 0, 1},
                              {"Metex universal system 9160", 1, 0, 7, 2, 4, 0, 1},
                              {"PeakTech-4010", 5, 0, 7, 2, 1, 0, 1},
                              {"PeakTech-451", 0, 1, 7, 2, 1, 0, 1},
                              {"Radioshack 22-805 DMM", 0, 0, 7, 2, 1, 0, 1},
                              {"Voltcraft M-3650D", 1, 0, 7, 2, 1, 0, 1},
                              {"Voltcraft M-4660", 1, 0, 7, 2, 4, 0, 3},
                              {"Voltcraft ME-11", 0, 0, 7, 2, 1, 0, 1},
                              {"Voltcraft ME-22T", 3, 0, 7, 2, 1, 0, 1},
                              {"Voltcraft ME-32", 0, 0, 7, 2, 1, 0, 1},
                              {"Voltcraft VC 670", 4, 2, 7, 1, 1, 0, 3},
                              {"*Voltcraft ME-42", 0, 0, 7, 2, 1, 0, 1},
                              {"*Voltcraft M-3860", 5, 0, 7, 2, 4, 0, 2},
                              {"*Voltcraft M-4660A", 5, 0, 7, 2, 4, 0, 3},
                              {"*Voltcraft M-4660M", 5, 0, 7, 2, 4, 0, 3},
                              {"*Voltcraft MXD-4660A", 5, 0, 7, 2, 4, 0, 3},
                              {"*Voltcraft VC 630", 4, 2, 7, 1, 1, 0, 3},
                              {"*Voltcraft VC 650", 4, 2, 7, 1, 1, 0, 3},
                              {"*Voltcraft VC 635", 3, 3, 7, 1, 1, 0, 3},
                              {"*Voltcraft VC 655", 3, 3, 7, 1, 1, 0, 3},
                              
                              {"",0,0,0,0,0,0,0} // End Of List
                            };

DmmPrefs::DmmPrefs( QWidget *parent, const char *name ) :
  UIDmmPrefs( parent, name )
{
  m_label = tr( "Multimeter settings" );
  m_description = tr( "<b>Here you can configure the serial port"
                      " and protocol for your DMM. There is"
                      " also a number of predefined models.</b>" );
  m_pixmap = new QPixmap( (const char **)dmm_xpm );
      
  ui_model->clear();
  ui_model->insertItem( "Manual settings" );
  
  int id = 0;
  while (*dmm_info[id].name)
  {
    ui_model->insertItem( dmm_info[id++].name );
  }

  message2->hide();
  
  connect( ui_model, SIGNAL( activated( int ) ),
           this, SLOT( modelSLOT( int )));

}

DmmPrefs::~DmmPrefs()
{
}

void
DmmPrefs::defaultsSLOT()
{
  port->setCurrentItem( m_cfg->getInt( "Port settings", "device", 0 ) );
  baudRate->setCurrentItem( m_cfg->getInt( "Port settings", "baud", 0 ) );
  bitsCombo->setCurrentItem( m_cfg->getInt( "Port settings", "bits", 7 )-5 );
  stopBitsCombo->setCurrentItem( m_cfg->getInt( "Port settings", "stop-bits", 2 )-1);
  parityCombo->setCurrentItem( m_cfg->getInt( "Port settings", "parity", 0 ) );  
  displayCombo->setCurrentItem( m_cfg->getInt( "DMM", "display", 1 ) );
  
  protocolCombo->setCurrentItem( m_cfg->getInt( "DMM", "data-format", 0 ));
  ui_numValues->setValue( m_cfg->getInt( "DMM", "number-of-values", 1 ));
  
  QString model = m_cfg->getString( "DMM", "model", "" );
  
  ui_model->setCurrentItem( 0 );
  int id=0;
  while (*dmm_info[id].name)
  {
    if (model == dmm_info[id].name)
    {
      ui_model->setCurrentItem( id+1 );
      break;
    }
    id++;
  }
   
  modelSLOT( ui_model->currentItem() );
}

void
DmmPrefs::factoryDefaultsSLOT()
{
  port->setCurrentItem( 0 );
  baudRate->setCurrentItem( 0 );
  bitsCombo->setCurrentItem( 2 );
  stopBitsCombo->setCurrentItem( 1 );
  parityCombo->setCurrentItem( 0 );  
  displayCombo->setCurrentItem( 1 );
  
  protocolCombo->setCurrentItem( 0 );
  ui_numValues->setValue( 1 );
  ui_model->setCurrentItem( 0 );
  
  modelSLOT( ui_model->currentItem() );
}

void
DmmPrefs::applySLOT()
{
  m_cfg->setInt( "Port settings", "device", port->currentItem() );
  m_cfg->setInt( "Port settings", "baud", baudRate->currentItem() );
  m_cfg->setInt( "Port settings", "bits", bitsCombo->currentItem()+5 );
  m_cfg->setInt( "Port settings", "stop-bits", stopBitsCombo->currentItem()+1 );
  m_cfg->setInt( "Port settings", "parity", parityCombo->currentItem() );
  
  m_cfg->setInt( "DMM", "display", displayCombo->currentItem() );
  
  m_cfg->setInt( "DMM", "data-format", protocolCombo->currentItem() );
  m_cfg->setInt( "DMM", "number-of-values", ui_numValues->value() );
  m_cfg->setString( "DMM", "model", 
      (ui_model->currentItem() == 0 ? "Manual" : dmm_info[ui_model->currentItem()-1].name ));
}

void
DmmPrefs::modelSLOT( int id )
{
  baudRate->setDisabled( id != 0 );
  ui_protocol->setDisabled( id != 0 );
  ui_baudLabel->setDisabled( id != 0 );
  ui_bitsLabel->setDisabled( id != 0 );
  ui_stopLabel->setDisabled( id != 0 );
  ui_displayLabel->setDisabled( id != 0 );
  ui_parityLabel->setDisabled( id != 0 );
  bitsCombo->setDisabled( id != 0 );
  displayCombo->setDisabled( id != 0 );
  stopBitsCombo->setDisabled( id != 0 );
  parityCombo->setDisabled( id != 0 );
  ui_numValues->setDisabled( id != 0 );
  if (id != 0) message->hide();
  else         message->show();
  if (ui_model->text(id)[0] == '*')
  {
    message2->show();
  }
  else
  {
    message2->hide();
  }
  
  if (id > 0)
  {
    baudRate->setCurrentItem( dmm_info[id-1].baud );
    protocolCombo->setCurrentItem( dmm_info[id-1].protocol );
    bitsCombo->setCurrentItem( dmm_info[id-1].bits-5 );
    stopBitsCombo->setCurrentItem( dmm_info[id-1].stopBits-1 );
    parityCombo->setCurrentItem( dmm_info[id-1].parity );
    displayCombo->setCurrentItem( dmm_info[id-1].display );
    ui_numValues->setValue( dmm_info[id-1].numValues );
  }
}

int
DmmPrefs::parity() const
{
  return parityCombo->currentItem();
}

int
DmmPrefs::bits() const
{
  return 5+bitsCombo->currentItem();
}

int
DmmPrefs::stopBits() const
{
  return 1+stopBitsCombo->currentItem();
}

int
DmmPrefs::speed() const
{
  switch (baudRate->currentItem())
  {
  case 0:
    return 600;
  case 1:
    return 1200;
  case 2:
    return 1800;
  case 3:
    return 2400;
  case 4:
    return 4800;
  case 5:
    return 9600;
  }
  
  return 600;
}

int
DmmPrefs::numValues() const
{
  return ui_numValues->value();
}

ReadEvent::DataFormat
DmmPrefs::format() const
{
  return (ReadEvent::DataFormat)protocolCombo->currentItem();
}

int
DmmPrefs::display() const
{
  return displayCombo->currentItem();
}

QString
DmmPrefs::dmmName() const
{
  return ui_model->currentText();
}

QString
DmmPrefs::device() const
{
  return port->currentText();
}
