/****************************************************************************
** Form interface generated from reading ui file 'uiintegrationprefs.ui'
**
** Created: Tue Dec 25 12:40:33 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef UIINTEGRATIONPREFS_H
#define UIINTEGRATIONPREFS_H

#include <qvariant.h>
#include <qpixmap.h>
#include <prefwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class ColorButton;
class QCheckBox;
class QButtonGroup;
class QLabel;
class QComboBox;
class QSpinBox;
class QLineEdit;

class UIIntegrationPrefs : public PrefWidget
{
    Q_OBJECT

public:
    UIIntegrationPrefs( QWidget* parent = 0, const char* name = 0 );
    ~UIIntegrationPrefs();

    QCheckBox* ui_showInt;
    QButtonGroup* ButtonGroup15;
    ColorButton* ui_intColor;
    QLabel* label_2_2_2_3;
    ColorButton* ui_intThresholdColor;
    QLabel* label_2_2_2_2_2;
    QButtonGroup* ButtonGroup16;
    QLabel* TextLabel1_3_2_2;
    QLabel* TextLabel1_5_2;
    QComboBox* ui_intPointMode;
    QComboBox* ui_intLineMode;
    QLabel* TextLabel1_3;
    QSpinBox* ui_intLineWidth;
    QButtonGroup* ButtonGroup12;
    QLabel* TextLabel2_4_2_2;
    QLabel* TextLabel3_3_2_2_2;
    QLineEdit* ui_intScale;
    QLineEdit* ui_intOffset;
    QLabel* TextLabel3_3_2_3;
    QLineEdit* ui_intThreshold;

protected:
    QVBoxLayout* UIIntegrationPrefsLayout;
    QSpacerItem* Spacer47;
    QHBoxLayout* Layout53_2;
    QSpacerItem* Spacer40_2_2;
    QGridLayout* ButtonGroup15Layout;
    QHBoxLayout* Layout17_2_2;
    QHBoxLayout* Layout17_2_2_2;
    QGridLayout* ButtonGroup16Layout;
    QSpacerItem* Spacer3_2_3_2;
    QSpacerItem* Spacer234;
    QGridLayout* ButtonGroup12Layout;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // UIINTEGRATIONPREFS_H
