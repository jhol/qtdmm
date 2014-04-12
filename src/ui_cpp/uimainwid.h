/****************************************************************************
** Form interface generated from reading ui file 'uimainwid.ui'
**
** Created: Sun Sep 2 19:18:45 2001
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef UIMAINWID_H
#define UIMAINWID_H

#include <qvariant.h>
#include <qframe.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class DMMGraph;
class QLabel;

class UIMainWid : public QFrame
{ 
    Q_OBJECT

public:
    UIMainWid( QWidget* parent = 0, const char* name = 0 );
    ~UIMainWid();

    QLabel* TextLabel7;
    QFrame* ui_displayFrame;
    QLabel* ui_minValue;
    QLabel* ui_minUnit;
    QLabel* ui_maxUnit;
    QLabel* ui_label1;
    QLabel* ui_maxValue;
    QLabel* ui_label2;
    QLabel* ui_value;
    QLabel* ui_unit;
    QFrame* Line3;
    DMMGraph* ui_graph;

protected:
    QGridLayout* UIMainWidLayout;
    QGridLayout* ui_displayFrameLayout;
    QGridLayout* Layout17;
    QHBoxLayout* Layout5;
    bool event( QEvent* );
};

#endif // UIMAINWID_H
