/****************************************************************************
** Form interface generated from reading ui file 'uigraphprefs.ui'
**
** Created: Tue Dec 25 12:40:33 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef UIGRAPHPREFS_H
#define UIGRAPHPREFS_H

#include <qvariant.h>
#include <qpixmap.h>
#include <prefwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class ColorButton;
class QGroupBox;
class QLabel;
class QButtonGroup;
class QComboBox;
class QSpinBox;
class QCheckBox;

class UIGraphPrefs : public PrefWidget
{
    Q_OBJECT

public:
    UIGraphPrefs( QWidget* parent = 0, const char* name = 0 );
    ~UIGraphPrefs();

    QGroupBox* GroupBox7;
    ColorButton* ui_dataColor;
    QLabel* label_2;
    ColorButton* ui_bgColor;
    QLabel* TextLabel2_2_4;
    ColorButton* ui_gridColor;
    QLabel* TextLabel3_2_2;
    ColorButton* ui_cursorColor;
    QLabel* label2_4;
    ColorButton* ui_startColor;
    QLabel* label2_2_2;
    ColorButton* ui_extColor;
    QLabel* label2_3_2;
    QButtonGroup* ButtonGroup11_2;
    QLabel* TextLabel1_3_3_2;
    QComboBox* ui_lineMode;
    QLabel* TextLabel1_6_2;
    QSpinBox* ui_lineWidth;
    QLabel* TextLabel1;
    QComboBox* ui_pointMode;
    QCheckBox* ui_crosshair;

protected:
    QVBoxLayout* UIGraphPrefsLayout;
    QSpacerItem* Spacer41;
    QGridLayout* GroupBox7Layout;
    QHBoxLayout* Layout17_2;
    QHBoxLayout* Layout19_4;
    QHBoxLayout* Layout20_2;
    QHBoxLayout* Layout18_4;
    QHBoxLayout* Layout18_2_2;
    QHBoxLayout* Layout18_3_2;
    QGridLayout* ButtonGroup11_2Layout;
    QSpacerItem* Spacer3_2_2_2;
    QSpacerItem* Spacer233;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // UIGRAPHPREFS_H
