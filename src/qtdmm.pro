TEMPLATE        = app
CONFIG          = qt release warn_on thread
INCLUDEPATH     = . moc
MOC_DIR         = moc
OBJECTS_DIR     = tmp
DEPENDPATH      = . 

HEADERS   = configdlg.h \
            dmm.h \
            dmmbar.h \
            dmmgraph.h \
            mainwid.h \
            mainwin.h \
            simplecfg.h \
            printdlg.h \
            readerthread.h \
            readevent.h \
            colorbutton.h

INTERFACES = uiconfigdlg.ui \
             uimainwid.ui \
             uiprintdlg.ui
                        
SOURCES   = main.cpp \
            configdlg.cpp \
            dmm.cpp \
            dmmbar.cpp \
            dmmgraph.cpp \
            mainwid.cpp \
            mainwin.cpp \
            simplecfg.cpp \
            printdlg.cpp \
            readerthread.cpp \
            colorbutton.cpp

LIBS      = 
TARGET    = qtdmm
VERSION   = 0.4
DESTDIR   = ../bin

