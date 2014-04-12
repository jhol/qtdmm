//======================================================================
// File:		configitem.cpp
// Author:	Matthias Toussaint
// Created:	Sat Oct 19 17:38:54 CEST 2002
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

#include <configitem.h>

ConfigItem::ConfigItem( int id, const QPixmap & pixmap,
                        const QString & label, QListView *parent ) :
  QListViewItem( parent, label ),
  m_id( id )
{
  setPixmap( 0, pixmap );
}

ConfigItem::~ConfigItem()
{
}
