/****************************************************************************
** Form interface generated from reading ui file 'uiscaleprefs.ui'
**
** Created: Tue Dec 25 12:40:33 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef UISCALEPREFS_H
#define UISCALEPREFS_H

#include <qvariant.h>
#include <qpixmap.h>
#include <prefwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QButtonGroup;
class QRadioButton;
class QLabel;
class QCheckBox;
class QLineEdit;
class QComboBox;
class QSpinBox;

class UIScalePrefs : public PrefWidget
{
    Q_OBJECT

public:
    UIScalePrefs( QWidget* parent = 0, const char* name = 0 );
    ~UIScalePrefs();

    QButtonGroup* ButtonGroup36;
    QRadioButton* autoScaleBut;
    QLabel* TextLabel9_2;
    QCheckBox* ui_includeZero;
    QRadioButton* manualScaleBut;
    QLabel* TextLabel9;
    QLabel* TextLabel10;
    QLineEdit* ui_scaleMin;
    QLabel* TextLabel10_2;
    QLineEdit* ui_scaleMax;
    QButtonGroup* ButtonGroup37;
    QLabel* TextLabel11;
    QLabel* TextLabel12;
    QComboBox* sizeUnit;
    QComboBox* lengthUnit;
    QSpinBox* ui_winSize;
    QSpinBox* winLength;

protected:
    QVBoxLayout* UIScalePrefsLayout;
    QSpacerItem* Spacer5;
    QVBoxLayout* ButtonGroup36Layout;
    QHBoxLayout* Layout12;
    QSpacerItem* Spacer14;
    QHBoxLayout* Layout15_2;
    QSpacerItem* Spacer7;
    QGridLayout* ButtonGroup37Layout;
    QSpacerItem* Spacer8;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // UISCALEPREFS_H
