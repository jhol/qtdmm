//======================================================================
// File:		main.cpp
// Author:	Matthias Toussaint
// Created:	Tue Apr 10 17:36:39 CEST 2001
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

#include <qapplication.h>
#include <mainwin.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <qstring.h>

void myMessageOutput( QtMsgType type, const char *msg )
{
  QString txt = msg;
  
  switch ( type ) {
    case QtDebugMsg:
      fprintf( stderr, "Debug: %s\n", msg );
      //abort();
      break;
    case QtWarningMsg:     
      if (txt.contains( "Absolute index" )) abort();
      //fprintf( stderr, "Warning: %s\n", msg );
      //abort();
      break;
    case QtFatalMsg:
      fprintf( stderr, "Fatal: %s\n", msg );
      //abort();                    // deliberately core dump
  }
}

int
main( int argc, char **argv )
{
  qInstallMsgHandler( myMessageOutput );
  QApplication app( argc, argv );
  
  MainWin mainWin;
  
  // very simple parsing (tm)
  for (int i=0; i<argc; ++i)
  {
    if (QString(argv[i]) == "--console")
    {
      mainWin.setConsoleLogging( true );
      break;
    }
  }
  
  app.setMainWidget( &mainWin );
  mainWin.show();
  mainWin.move( 100, 100 );
  
  return app.exec();
}
