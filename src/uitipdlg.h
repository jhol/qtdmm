/****************************************************************************
** Form interface generated from reading ui file 'uitipdlg.ui'
**
** Created: Tue Dec 25 12:40:33 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef UITIPDLG_H
#define UITIPDLG_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTextView;
class QLabel;
class QCheckBox;
class QPushButton;

class UITipDlg : public QDialog
{
    Q_OBJECT

public:
    UITipDlg( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~UITipDlg();

    QTextView* ui_tip;
    QLabel* ui_logo;
    QCheckBox* ui_showTip;
    QPushButton* ui_previousBut;
    QPushButton* ui_nextBut;
    QPushButton* ui_closeBut;

protected:
    QVBoxLayout* UITipDlgLayout;
    QHBoxLayout* Layout8;
    QVBoxLayout* Layout8_2;
    QSpacerItem* Spacer2;
    QHBoxLayout* Layout7;
    QSpacerItem* Spacer1;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;
    QPixmap image1;

};

#endif // UITIPDLG_H
