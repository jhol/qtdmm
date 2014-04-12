/****************************************************************************
** Form interface generated from reading ui file 'uiexecuteprefs.ui'
**
** Created: Tue Dec 25 12:40:33 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef UIEXECUTEPREFS_H
#define UIEXECUTEPREFS_H

#include <qvariant.h>
#include <qpixmap.h>
#include <prefwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QCheckBox;
class QButtonGroup;
class QLabel;
class QLineEdit;
class QRadioButton;
class QPushButton;

class UIExecutePrefs : public PrefWidget
{
    Q_OBJECT

public:
    UIExecutePrefs( QWidget* parent = 0, const char* name = 0 );
    ~UIExecutePrefs();

    QCheckBox* ui_executeCommand;
    QButtonGroup* ButtonGroup9;
    QLabel* TextLabel8_2_2_2;
    QLineEdit* ui_execRaisingThreshold;
    QLabel* TextLabel7_2_2_2;
    QLineEdit* ui_execFallingThreshold;
    QRadioButton* ui_execRaising;
    QRadioButton* ui_execFalling;
    QButtonGroup* ButtonGroup10;
    QCheckBox* ui_disconnectExec;
    QLineEdit* ui_commandExec;
    QPushButton* ui_browseExec;

protected:
    QVBoxLayout* UIExecutePrefsLayout;
    QSpacerItem* Spacer1_8;
    QGridLayout* ButtonGroup9Layout;
    QSpacerItem* Spacer4_2_2_2_2;
    QSpacerItem* Spacer3_3_2_2;
    QVBoxLayout* ButtonGroup10Layout;
    QHBoxLayout* Layout32_2_2;
    QSpacerItem* Spacer1_9_2_2;
    QHBoxLayout* Layout30_2_2;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;
    QPixmap image1;

};

#endif // UIEXECUTEPREFS_H
