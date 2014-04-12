/****************************************************************************
** $Id: qprocess_unix.h,v 1.3 2002/10/11 20:08:59 mt Exp $
**
** Implementation of QProcess class for Unix
**
** Created : 20000905
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of the kernel module of the Qt GUI Toolkit.
**
** This file may be distributed under the terms of the Q Public License
** as defined by Trolltech AS of Norway and appearing in the file
** LICENSE.QPL included in the packaging of this file.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
** licenses may use this file in accordance with the Qt Commercial License
** Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about Qt Commercial License Agreements.
** See http://www.trolltech.com/qpl/ for QPL licensing information.
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#include "qprocess.h"

#ifndef QT_NO_PROCESS

#include "qapplication.h"
#include "qqueue.h"
#include "qlist.h"
#include "qsocketnotifier.h"
#include "qtimer.h"
#include "qcleanuphandler.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/types.h>

//#define QT_QPROCESS_DEBUG

#ifdef __MIPSEL__
#ifndef SOCK_DGRAM
#define SOCK_DGRAM 1
#endif
#ifndef SOCK_STREAM
#define SOCK_STREAM 2
#endif
#endif

#if defined(SIGNAL_HACK)
#undef SIGNAL_HACK
#endif

#if defined(Q_OS_MACX)
// these platforms work one way
#define SIGNAL_HACK
#elif defined(Q_CC_GNU) && ( defined(Q_OS_IRIX) || defined(Q_OS_SUN) )
// gcc on these platforms works above, but native compiler doesn't.
#define SIGNAL_HACK
#endif


#if defined(Q_C_CALLBACKS)
extern "C" {
#endif
    // this looks like two unconnected platform differences that just
    // happen to match up... perhaps we should use two defines, one
    // for each yuckyness.
#if defined(SIGNAL_HACK)
static void qt_C_sigign() { (*SIG_IGN)(SIGPIPE); }
static void qt_C_sigchldHnd();
#else
#define qt_C_sigign SIG_IGN
static void qt_C_sigchldHnd( int );
#endif
#if defined(Q_C_CALLBACKS)
}
#endif

class QProc;
class QProcessManager;
class QProcessPrivate
{
public:
    QProcessPrivate();
    ~QProcessPrivate();

    void closeOpenSocketsForChild();
    void newProc( pid_t pid, QProcess *process );

    QQueue<QByteArray> stdinBuf;

    QSocketNotifier *notifierStdin;
    QSocketNotifier *notifierStdout;
    QSocketNotifier *notifierStderr;
    int socketStdin[2];
    int socketStdout[2];
    int socketStderr[2];

    ssize_t stdinBufRead;
    QProc *proc;

    bool exitValuesCalculated;

    static QProcessManager *procManager;
};


/***********************************************************************
 *
 * QProc
 *
 **********************************************************************/
/*
  The class QProcess does not necessarily map exactly to the running
  child processes: if the process is finished, the QProcess class may still be
  there; furthermore a user can use QProcess to start more than one process.

  The helper-class QProc has the semantics that one instance of this class maps
  directly to a running child process.
*/
class QProc
{
public:
    QProc( pid_t p, QProcess *proc=0 ) : pid(p), process(proc)
    {
#if defined(QT_QPROCESS_DEBUG)
	qDebug( "QProc: Constructor for pid %d and QProcess %p", pid, process );
#endif
    }
    ~QProc()
    {
#if defined(QT_QPROCESS_DEBUG)
	qDebug( "QProc: Destructor for pid %d and QProcess %p", pid, process );
#endif
	if ( process != 0 )
	    process->d->proc = 0;
    }

    pid_t pid;
    QProcess *process;
};

/***********************************************************************
 *
 * QProcessManager
 *
 **********************************************************************/
class QProcessManager : public QObject
{
    Q_OBJECT

public:
    QProcessManager();
    ~QProcessManager();

    void append( QProc *p );
    void remove( QProc *p );

public slots:
    void removeMe();
    void sigchldHnd( int );

public:
    struct sigaction oldactChld;
    struct sigaction oldactPipe;
    QList<QProc> *procList;
    int sigchldFd[2];
};

#endif // QT_NO_PROCESS
