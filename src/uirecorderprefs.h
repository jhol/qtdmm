/****************************************************************************
** Form interface generated from reading ui file 'uirecorderprefs.ui'
**
** Created: Tue Dec 25 12:40:33 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef UIRECORDERPREFS_H
#define UIRECORDERPREFS_H

#include <qvariant.h>
#include <qpixmap.h>
#include <prefwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QButtonGroup;
class QLabel;
class QComboBox;
class QSpinBox;
class QGroupBox;
class QRadioButton;
class QLineEdit;
class QCheckBox;

class UIRecorderPrefs : public PrefWidget
{
    Q_OBJECT

public:
    UIRecorderPrefs( QWidget* parent = 0, const char* name = 0 );
    ~UIRecorderPrefs();

    QButtonGroup* ButtonGroup1;
    QLabel* sampLabel;
    QComboBox* ui_sampleUnit;
    QLabel* sampLabel_2;
    QComboBox* timeUnit;
    QSpinBox* sampleEvery;
    QSpinBox* sampleTime;
    QGroupBox* GroupBox1;
    QButtonGroup* ButtonGroup32;
    QRadioButton* manualBut;
    QRadioButton* predefinedBut;
    QLabel* TextLabel5;
    QSpinBox* hour;
    QLabel* TextLabel3;
    QSpinBox* minute;
    QLabel* TextLabel4;
    QSpinBox* second;
    QRadioButton* triggerBut;
    QButtonGroup* ButtonGroup13;
    QLineEdit* ui_fallingThreshold;
    QLineEdit* ui_raisingThreshold;
    QLabel* TextLabel7;
    QLabel* TextLabel8;
    QLabel* TextLabel6;
    QRadioButton* raisingBut;
    QLabel* TextLabel6_2;
    QRadioButton* fallingBut;
    QCheckBox* ui_preTrigger;
    QSpinBox* ui_preTriggerTime;
    QComboBox* ui_preTriggerUnit;
    QLabel* TextLabel6_2_2_2;
    QLabel* TextLabel6_2_2;
    QLabel* sampLabel_2_2;

protected:
    QVBoxLayout* UIRecorderPrefsLayout;
    QSpacerItem* Spacer1_2;
    QGridLayout* ButtonGroup1Layout;
    QSpacerItem* Spacer9;
    QVBoxLayout* GroupBox1Layout;
    QVBoxLayout* ButtonGroup32Layout;
    QHBoxLayout* Layout23;
    QSpacerItem* Spacer7_2;
    QHBoxLayout* Layout24;
    QSpacerItem* Spacer8_2;
    QHBoxLayout* Layout8;
    QSpacerItem* Spacer2_2;
    QHBoxLayout* Layout7;
    QHBoxLayout* Layout6;
    QHBoxLayout* Layout25;
    QSpacerItem* Spacer9_2;
    QVBoxLayout* ButtonGroup13Layout;
    QGridLayout* Layout14;
    QSpacerItem* Spacer3;
    QSpacerItem* Spacer4_2;
    QHBoxLayout* Layout9;
    QHBoxLayout* Layout10;
    QGridLayout* Layout11;
    QSpacerItem* Spacer9_3;
    QSpacerItem* Spacer10;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // UIRECORDERPREFS_H
