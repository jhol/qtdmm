/****************************************************************************
** Form interface generated from reading ui file 'uiguiprefs.ui'
**
** Created: Tue Dec 25 12:40:33 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef UIGUIPREFS_H
#define UIGUIPREFS_H

#include <qvariant.h>
#include <qpixmap.h>
#include <prefwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class ColorButton;
class QGroupBox;
class QCheckBox;
class QLabel;
class QButtonGroup;

class UIGuiPrefs : public PrefWidget
{
    Q_OBJECT

public:
    UIGuiPrefs( QWidget* parent = 0, const char* name = 0 );
    ~UIGuiPrefs();

    QGroupBox* GroupBox4;
    QCheckBox* ui_showBar;
    QCheckBox* ui_showMinMax;
    QCheckBox* ui_showDisplay;
    ColorButton* ui_bgColorDisplay;
    QLabel* TextLabel2_2_2;
    ColorButton* ui_textColor;
    QLabel* TextLabel2_2_3;
    QGroupBox* GroupBox4_2;
    QCheckBox* ui_alertUnsavedData;
    QCheckBox* ui_saveWindowPos;
    QCheckBox* ui_saveWindowSize;
    QButtonGroup* ButtonGroup12_2;
    QCheckBox* ui_textLabel;
    QCheckBox* ui_dmmToolBar;
    QCheckBox* ui_fileToolBar;
    QCheckBox* ui_helpToolBar;
    QCheckBox* ui_graphToolBar;
    QCheckBox* ui_tipOfTheDay;

protected:
    QVBoxLayout* UIGuiPrefsLayout;
    QSpacerItem* Spacer1_5;
    QGridLayout* GroupBox4Layout;
    QHBoxLayout* Layout37;
    QSpacerItem* Spacer34;
    QHBoxLayout* Layout37_2;
    QSpacerItem* Spacer34_2;
    QHBoxLayout* Layout19_2;
    QHBoxLayout* Layout19_3;
    QGridLayout* GroupBox4_2Layout;
    QHBoxLayout* Layout28;
    QSpacerItem* Spacer1_10;
    QHBoxLayout* Layout29;
    QSpacerItem* Spacer2_3;
    QHBoxLayout* Layout29_2;
    QSpacerItem* Spacer2_3_2;
    QGridLayout* ButtonGroup12_2Layout;
    QHBoxLayout* Layout30;
    QSpacerItem* Spacer3_4_2;
    QHBoxLayout* Layout30_3;
    QSpacerItem* Spacer3_4_2_2;
    QHBoxLayout* Layout30_4;
    QSpacerItem* Spacer3_4_2_3;
    QHBoxLayout* Layout30_5;
    QSpacerItem* Spacer3_4_2_4;
    QHBoxLayout* Layout30_5_2;
    QSpacerItem* Spacer3_4_2_4_2;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // UIGUIPREFS_H
