/****************************************************************************
** Form interface generated from reading ui file 'uiprintdlg.ui'
**
** Created: Tue Dec 25 12:40:33 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef UIPRINTDLG_H
#define UIPRINTDLG_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QPushButton;
class QFrame;
class QLineEdit;
class QMultiLineEdit;

class UIPrintDlg : public QDialog
{
    Q_OBJECT

public:
    UIPrintDlg( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~UIPrintDlg();

    QLabel* TextLabel3;
    QLabel* printerLabel;
    QPushButton* configBut;
    QFrame* Frame5;
    QLabel* TextLabel1;
    QLineEdit* printTitle;
    QLabel* TextLabel2;
    QMultiLineEdit* printComment;
    QPushButton* helpBut;
    QPushButton* printBut;
    QPushButton* cancelBut;

protected:
    QVBoxLayout* UIPrintDlgLayout;
    QHBoxLayout* Layout2;
    QVBoxLayout* Frame5Layout;
    QHBoxLayout* Layout28;
    QSpacerItem* Spacer2;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;
    QPixmap image1;

};

#endif // UIPRINTDLG_H
