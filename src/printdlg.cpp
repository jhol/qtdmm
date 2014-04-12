//======================================================================
// File:		printdlg.cpp
// Author:	Matthias Toussaint
// Created:	Wed Apr 11 16:54:59 CEST 2001
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
// (c) 2001 Matthias Toussaint
//======================================================================

#include <printdlg.h>
#include <qprinter.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qwhatsthis.h>

PrintDlg::PrintDlg( QWidget *parent, const char *name ) :
  UIPrintDlg( parent, name, true )
{
  connect( configBut, SIGNAL( clicked() ),
           this, SLOT( configSLOT() ));
  connect( helpBut, SIGNAL( clicked() ),
           this, SLOT( helpSLOT() ));
}

PrintDlg::~PrintDlg()
{
}

void
PrintDlg::setPrinter( QPrinter * prt )
{
  m_printer = prt;
  createPrinterString();
}

void
PrintDlg::configSLOT()
{
  if (m_printer->setup())
  {
    createPrinterString();
  }
}

void
PrintDlg::createPrinterString()
{
  QString txt = m_printer->printerName();

  if (m_printer->outputToFile())
  {
    txt = "File: ";
    txt += m_printer->outputFileName();
  }
  txt += " ";

  switch (m_printer->pageSize())
  {
  case QPrinter::A4:
    txt += "A4 ";
    break;
  case QPrinter::B5:
    txt += "B5 ";
    break;
  case QPrinter::Letter:
    txt += "Letter ";
    break;
  case QPrinter::Legal:
    txt += "Legal ";
    break;
  case QPrinter::Executive:
    txt += "Executive ";
    break;
  case QPrinter::A0:
    txt += "A0 ";
    break;
  case QPrinter::A1:
    txt += "A1 ";
    break;
  case QPrinter::A2:
    txt += "A2 ";
    break;
  case QPrinter::A3:
    txt += "A3 ";
    break;
  case QPrinter::A5:
    txt += "A5 ";
    break;
  case QPrinter::A6:
    txt += "A6 ";
    break;
  case QPrinter::A7:
    txt += "A7 ";
    break;
  case QPrinter::A8:
    txt += "A8 ";
    break;
  case QPrinter::A9:
    txt += "A9 ";
    break;
  case QPrinter::B0:
    txt += "B0 ";
    break;
  case QPrinter::B1:
    txt += "B1 ";
    break;
  case QPrinter::B10:
    txt += "B10 ";
    break;
  case QPrinter::B2:
    txt += "B2 ";
    break;
  case QPrinter::B3:
    txt += "B3 ";
    break;
  case QPrinter::B4:
    txt += "B4 ";
    break;
  case QPrinter::B6:
    txt += "B6 ";
    break;
  case QPrinter::B7:
    txt += "B7 ";
    break;
  case QPrinter::B8:
    txt += "B8 ";
    break;
  case QPrinter::B9:
    txt += "B9 ";
    break;
  case QPrinter::C5E:
    txt += "C5E ";
    break;
  case QPrinter::Comm10E:
    txt += "Comm10E ";
    break;
  case QPrinter::DLE:
    txt += "DLE ";
    break;
  case QPrinter::Folio:
    txt += "Folio ";
    break;
  case QPrinter::Ledger:
    txt += "Ledger ";
    break;
  case QPrinter::Tabloid:
    txt += "Tabloid ";
    break;
  case QPrinter::NPageSize:
    txt += "NPageSize ";
    break;
  }

  if (m_printer->orientation() == QPrinter::Landscape)
  {
    txt += "Landscape";
  }
  else
  {
    txt += "Portrait";
  }

  if (m_printer->colorMode() == QPrinter::Color)
  {
    txt += " Color";
  }
  else
  {
    txt += " Grayscale";
  }
  
  printerLabel->setText( txt );

  printBut->setEnabled( true );
}

void
PrintDlg::helpSLOT()
{
  QWhatsThis::enterWhatsThisMode();
}
