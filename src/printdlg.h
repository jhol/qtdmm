//======================================================================
// File:		printdlg.h
// Author:	Matthias Toussaint
// Created:	Wed Apr 11 16:53:46 CEST 2001
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

#ifndef PRINTDLG_HH
#define PRINTDLG_HH

#include <uiprintdlg.h>
#include <qlineedit.h>
#include <qmultilineedit.h>

class PrintDlg : public UIPrintDlg
{
  Q_OBJECT
public:
  PrintDlg( QWidget *parent=0, const char *name=0 );
  virtual ~PrintDlg();

  void setPrinter( QPrinter * prt );
    
  QString title() const { return printTitle->text(); }
  QString comment() const { return printComment->text(); }
  
protected:
  QPrinter *m_printer;
  
protected slots:
  void configSLOT();
  void helpSLOT();
  void createPrinterString();

};

#endif // PRINTDLG_HH
