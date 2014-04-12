//======================================================================
// File:		tipdlg.h
// Author:	Matthias Toussaint
// Created:	Sun Nov 11 19:20:02 CET 2001
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

#ifndef TIPDLG_HH
#define TIPDLG_HH

#include <uitipdlg.h>

class TipDlg : public UITipDlg
{
  Q_OBJECT
public:
  TipDlg( QWidget *parent=0, const char *name=0 );
  virtual ~TipDlg();
  
  bool showTips() const;
  
  static const char *s_tipText[];
  
  void setCurrentTip( int c );
  int currentTip() const { return m_curTip; }

signals:
	void showTips( bool );
	void currentTip( int );
  
public slots:
  void setShowTipsSLOT( bool );
	
protected:
  int m_numTips;
  int m_curTip;
  QString m_formatTip;
	
  void showTipText();
  void closeEvent( QCloseEvent * );
  
protected slots:
  void nextSLOT();
  void previousSLOT();
  void closeSLOT();
  void showTipsSLOT( bool );
  
};

#endif // TIPDLG_HH
