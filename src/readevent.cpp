//======================================================================
// File:		readevent.cpp
// Author:	Matthias Toussaint
// Created:	Sun Oct  6 17:11:40 CEST 2002
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

#include <readevent.h>

#include <iostream>

ReadEvent::ReadEvent( char *str, int len, int id, DataFormat df ) :
  QCustomEvent( QEvent::User ),
  m_length( len ),
  m_format (df ),
  m_id( id )
{
  memcpy( m_str, str, len );
}

ReadEvent::~ReadEvent()
{
}
