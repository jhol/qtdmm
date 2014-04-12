/****************************************************************************
** Form interface generated from reading ui file 'uimainwid.ui'
**
** Created: Sun Apr 15 20:02:39 2001
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef UIMAINWID_H
#define UIMAINWID_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class DMMGraph;
class QFrame;
class QLabel;
class QPushButton;

class UIMainWid : public QWidget
{ 
    Q_OBJECT

public:
    UIMainWid( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~UIMainWid();

    QFrame* Line1;
    QPushButton* connectBut;
    QLabel* TextLabel7;
    QPushButton* resetBut;
    QFrame* Frame3;
    QLabel* minValue;
    QLabel* minUnit;
    QLabel* maxUnit;
    QLabel* TextLabel2;
    QLabel* maxValue;
    QLabel* TextLabel1;
    QLabel* value;
    QLabel* unit;
    QFrame* Line3;
    DMMGraph* graph;
    QPushButton* startBut;
    QPushButton* stopBut;
    QPushButton* clearBut;
    QPushButton* configBut;
    QPushButton* helpBut;
    QPushButton* quitBut;
    QPushButton* printBut;
    QPushButton* exportBut;
    QLabel* statusBar;
    QLabel* infoLabel;

protected:
    QGridLayout* UIMainWidLayout;
    QGridLayout* Frame3Layout;
    QGridLayout* Layout17;
    QHBoxLayout* Layout5;
    QVBoxLayout* Layout4;
    QHBoxLayout* Layout27;
    QHBoxLayout* Layout27_2;
    bool event( QEvent* );
};

#endif // UIMAINWID_H
