TEMPLATE        = app
CONFIG          = qt release warn_on thread
INCLUDEPATH     = . moc xpm
MOC_DIR         = moc
OBJECTS_DIR     = tmp
DEPENDPATH      = . 

HEADERS   = \
            colorbutton.h \
            configdlg.h \
            configitem.h \
            displaywid.h \
            dmm.h \
            dmmbar.h \
            dmmgraph.h \
            dmmprefs.h \
            engnumbervalidator.h \
            executeprefs.h \
            graphprefs.h \
            guiprefs.h \
            integrationprefs.h \
            mainwid.h \
            mainwin.h \
            prefwidget.h \
            printdlg.h \
            qcleanuphandler.h \
            qprocess.h \
            qprocess_unix.h \
            readerthread.h \
            readevent.h \
            recorderprefs.h \
            scaleprefs.h \
            simplecfg.h \
            tipdlg.h

INTERFACES = \
             uiconfigdlg.ui \
             uidmmprefs.ui \
             uiexecuteprefs.ui \
             uigraphprefs.ui \
             uiguiprefs.ui \
             uiintegrationprefs.ui \
             uimainwid.ui \
             uiprintdlg.ui \
             uirecorderprefs.ui \
             uiscaleprefs.ui \
             uitipdlg.ui
                        
SOURCES   = \
            colorbutton.cpp \
            configdlg.cpp \
            configitem.cpp \
            displaywid.cpp \
            dmm.cpp \
            dmmbar.cpp \
            dmmgraph.cpp \
            dmmprefs.cpp \
            engnumbervalidator.cpp \
            executeprefs.cpp \
            graphprefs.cpp \
            guiprefs.cpp \
            integrationprefs.cpp \
            main.cpp \
            mainwid.cpp \
            mainwin.cpp \
            prefwidget.cpp \
            printdlg.cpp \
            qprocess.cpp \
            qprocess_unix.cpp \
            readerthread.cpp \
            readevent.cpp \
            recorderprefs.cpp \
            scaleprefs.cpp \
            simplecfg.cpp \
            tipdlg.cpp

LIBS      = 
TARGET    = qtdmm
VERSION   = 0.8.2
DESTDIR   = ../bin

