/****************************************************************************
** Form interface generated from reading ui file 'uimainwid.ui'
**
** Created: Tue Dec 25 12:40:33 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef UIMAINWID_H
#define UIMAINWID_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qframe.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class DMMGraph;

class UIMainWid : public QFrame
{
    Q_OBJECT

public:
    UIMainWid( QWidget* parent = 0, const char* name = 0 );
    ~UIMainWid();

    DMMGraph* ui_graph;

protected:
    QVBoxLayout* UIMainWidLayout;
    QHBoxLayout* Layout5;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;
    QPixmap image1;

};

#endif // UIMAINWID_H
