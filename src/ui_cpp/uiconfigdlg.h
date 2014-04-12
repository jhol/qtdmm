/****************************************************************************
** Form interface generated from reading ui file 'uiconfigdlg.ui'
**
** Created: Wed May 9 20:39:28 2001
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
class QButtonGroup;
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QRadioButton;
class QSpinBox;
class QTabWidget;
class QTextView;
class QWidget;

class UIConfigDlg : public QDialog
{ 
    Q_OBJECT

public:
    UIConfigDlg( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~UIConfigDlg();

    QPushButton* helpBut;
    QPushButton* okBut;
    QPushButton* cancelBut;
    QTabWidget* tabWidget;
    QWidget* samplePage;
    QButtonGroup* ButtonGroup1;
    QLabel* sampLabel;
    QLineEdit* sampleEvery;
    QComboBox* sampleUnit;
    QLabel* sampLabel_2;
    QLineEdit* sampleTime;
    QComboBox* timeUnit;
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
    QLineEdit* winSize;
    QLineEdit* winLength;
    QComboBox* lengthUnit;
    QWidget* dmmPage;
    QLabel* TextLabel1_2;
    QComboBox* modelCombo;
    QButtonGroup* ButtonGroup11;
    QLabel* TextLabel1_3;
    QComboBox* bitsCombo;
    QLabel* TextLabel2_2;
    QComboBox* baudRate;
    QLabel* TextLabel1;
    QComboBox* port;
    QLabel* TextLabel2;
    QComboBox* stopBitsCombo;
    QButtonGroup* ButtonGroup7;
    QComboBox* protocolCombo;
    QLabel* TextLabel1_4;
    QSpinBox* ignoreSpin;
    QLabel* message;
    QWidget* copyTab;
    QTextView* TextView1;

protected:
    QGridLayout* UIConfigDlgLayout;
    QHBoxLayout* Layout15;
    QVBoxLayout* samplePageLayout;
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
    QVBoxLayout* scalePageLayout;
    QVBoxLayout* ButtonGroup36Layout;
    QHBoxLayout* Layout15_2;
    QGridLayout* ButtonGroup37Layout;
    QVBoxLayout* dmmPageLayout;
    QGridLayout* ButtonGroup11Layout;
    QGridLayout* ButtonGroup7Layout;
    QGridLayout* copyTabLayout;
    bool event( QEvent* );
};

#endif // UICONFIGDLG_H
