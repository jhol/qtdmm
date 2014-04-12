/****************************************************************************
** Form interface generated from reading ui file 'uiconfigdlg.ui'
**
** Created: Sun Sep 2 19:18:45 2001
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef UICONFIGDLG_H
#define UICONFIGDLG_H

#include <qvariant.h>
#include <qdialog.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class ColorButton;
class QButtonGroup;
class QCheckBox;
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QRadioButton;
class QSpinBox;
class QTabWidget;
class QWidget;

class UIConfigDlg : public QDialog
{ 
    Q_OBJECT

public:
    UIConfigDlg( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~UIConfigDlg();

    QTabWidget* tabWidget;
    QWidget* recorderPage;
    QButtonGroup* ButtonGroup1;
    QLabel* sampLabel;
    QComboBox* sampleUnit;
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
    QLineEdit* fallingThresholdEdit;
    QLineEdit* raisingThresholdEdit;
    QLabel* TextLabel7;
    QLabel* TextLabel8;
    QLabel* TextLabel6;
    QRadioButton* raisingBut;
    QLabel* TextLabel6_2;
    QRadioButton* fallingBut;
    QPushButton* ui_defaultRecorder;
    QPushButton* ui_factoryRecorder;
    QWidget* scalePage;
    QButtonGroup* ButtonGroup36;
    QRadioButton* autoScaleBut;
    QRadioButton* manualScaleBut;
    QLabel* TextLabel9;
    QLabel* TextLabel10;
    QLineEdit* scaleMinEd;
    QLabel* TextLabel10_2;
    QLineEdit* scaleMaxEd;
    QButtonGroup* ButtonGroup37;
    QLabel* TextLabel11;
    QLabel* TextLabel12;
    QComboBox* sizeUnit;
    QComboBox* lengthUnit;
    QSpinBox* winSize;
    QSpinBox* winLength;
    QPushButton* ui_defaultScale;
    QPushButton* ui_factoryScale;
    QWidget* dmmPage;
    QLabel* TextLabel1_2;
    QComboBox* modelCombo;
    QButtonGroup* ButtonGroup11;
    QLabel* ui_bitsLabel;
    QComboBox* bitsCombo;
    QLabel* ui_stopLabel;
    QComboBox* baudRate;
    QLabel* ui_baudLabel;
    QComboBox* port;
    QLabel* TextLabel2;
    QComboBox* stopBitsCombo;
    QButtonGroup* ui_protocol;
    QComboBox* protocolCombo;
    QLabel* TextLabel1_4;
    QSpinBox* ignoreSpin;
    QLabel* message;
    QPushButton* ui_defaultDMM;
    QPushButton* ui_factoryDMM;
    QWidget* qtdmmTab;
    QGroupBox* GroupBox7;
    ColorButton* ui_bgColor;
    QLabel* TextLabel2_2;
    ColorButton* ui_gridColor;
    QLabel* TextLabel3_2;
    ColorButton* ui_dataColor;
    QLabel* label;
    ColorButton* ui_cursorColor;
    QLabel* label2;
    QLabel* TextLabel2_3;
    QLabel* TextLabel1;
    QSpinBox* ui_lineWidth;
    QGroupBox* GroupBox4;
    ColorButton* ui_bgColorDisplay;
    QLabel* TextLabel2_2_2;
    ColorButton* ui_textColor;
    QLabel* TextLabel2_2_3;
    QCheckBox* ui_alertUnsavedData;
    QCheckBox* ui_saveWindowCheck;
    QCheckBox* ui_textLabel;
    QPushButton* ui_defaultPreferences;
    QPushButton* ui_factoryPreferences;
    QPushButton* helpBut;
    QPushButton* ui_applyBut;
    QPushButton* okBut;
    QPushButton* cancelBut;

protected:
    QVBoxLayout* UIConfigDlgLayout;
    QVBoxLayout* recorderPageLayout;
    QGridLayout* ButtonGroup1Layout;
    QVBoxLayout* GroupBox1Layout;
    QVBoxLayout* ButtonGroup32Layout;
    QHBoxLayout* Layout23;
    QHBoxLayout* Layout24;
    QHBoxLayout* Layout8;
    QHBoxLayout* Layout7;
    QHBoxLayout* Layout6;
    QHBoxLayout* Layout25;
    QVBoxLayout* ButtonGroup13Layout;
    QGridLayout* Layout14;
    QHBoxLayout* Layout9;
    QHBoxLayout* Layout10;
    QHBoxLayout* Layout52;
    QVBoxLayout* scalePageLayout;
    QVBoxLayout* ButtonGroup36Layout;
    QHBoxLayout* Layout15_2;
    QGridLayout* ButtonGroup37Layout;
    QHBoxLayout* Layout51;
    QVBoxLayout* dmmPageLayout;
    QGridLayout* ButtonGroup11Layout;
    QGridLayout* ui_protocolLayout;
    QHBoxLayout* Layout50;
    QVBoxLayout* qtdmmTabLayout;
    QVBoxLayout* GroupBox7Layout;
    QHBoxLayout* Layout24_2;
    QHBoxLayout* Layout19;
    QHBoxLayout* Layout20;
    QHBoxLayout* Layout23_2;
    QHBoxLayout* Layout17;
    QHBoxLayout* Layout18;
    QHBoxLayout* Layout48;
    QHBoxLayout* GroupBox4Layout;
    QHBoxLayout* Layout19_2;
    QHBoxLayout* Layout19_3;
    QHBoxLayout* Layout49;
    QHBoxLayout* Layout105;
    bool event( QEvent* );
};

#endif // UICONFIGDLG_H
