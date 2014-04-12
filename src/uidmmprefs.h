/****************************************************************************
** Form interface generated from reading ui file 'uidmmprefs.ui'
**
** Created: Tue Dec 25 12:40:33 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef UIDMMPREFS_H
#define UIDMMPREFS_H

#include <qvariant.h>
#include <qpixmap.h>
#include <prefwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QToolButton;
class QButtonGroup;
class QSpinBox;
class QPushButton;

class UIDmmPrefs : public PrefWidget
{
    Q_OBJECT

public:
    UIDmmPrefs( QWidget* parent = 0, const char* name = 0 );
    ~UIDmmPrefs();

    QLabel* ui_hint;
    QComboBox* ui_model;
    QLineEdit* ui_filename;
    QToolButton* ui_load;
    QToolButton* ui_save;
    QButtonGroup* ButtonGroup11;
    QComboBox* port;
    QSpinBox* portNumber;
    QPushButton* ui_scanPorts;
    QLabel* ui_bitsLabel;
    QLabel* ui_parityLabel;
    QComboBox* stopBitsCombo;
    QComboBox* displayCombo;
    QLabel* ui_stopLabel;
    QComboBox* baudRate;
    QLabel* ui_displayLabel;
    QLabel* ui_baudLabel;
    QLabel* TextLabel2;
    QComboBox* bitsCombo;
    QComboBox* parityCombo;
    QButtonGroup* ui_protocol;
    QComboBox* protocolCombo;
    QLabel* TextLabel1_4;
    QSpinBox* ui_numValues;
    QLabel* message2;
    QLabel* message;

protected:
    QVBoxLayout* UIDmmPrefsLayout;
    QSpacerItem* Spacer1_3;
    QHBoxLayout* layout2;
    QGridLayout* ButtonGroup11Layout;
    QHBoxLayout* layout2_2;
    QGridLayout* ui_protocolLayout;
    QSpacerItem* Spacer1;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;
    QPixmap image1;
    QPixmap image2;

};

#endif // UIDMMPREFS_H
