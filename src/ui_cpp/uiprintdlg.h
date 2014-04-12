/****************************************************************************
** Form interface generated from reading ui file 'uiprintdlg.ui'
**
** Created: Wed May 9 20:39:29 2001
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef UIPRINTDLG_H
#define UIPRINTDLG_H

#include <qvariant.h>
#include <qdialog.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QFrame;
class QLabel;
class QLineEdit;
class QMultiLineEdit;
class QPushButton;

class UIPrintDlg : public QDialog
{ 
    Q_OBJECT

public:
    UIPrintDlg( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~UIPrintDlg();

    QFrame* Line4;
    QPushButton* configBut;
    QLabel* TextLabel2;
    QLabel* TextLabel1;
    QLabel* TextLabel3;
    QLabel* printerLabel;
    QLineEdit* printTitle;
    QMultiLineEdit* printComment;
    QFrame* Line3;
    QPushButton* helpBut;
    QPushButton* printBut;
    QPushButton* cancelBut;

protected:
    QGridLayout* UIPrintDlgLayout;
    QHBoxLayout* Layout28;
    bool event( QEvent* );
};

#endif // UIPRINTDLG_H
