/****************************************************************************
** Form interface generated from reading ui file 'uiprintdlg.ui'
**
** Created: Sun Sep 2 19:18:45 2001
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
    bool event( QEvent* );
};

#endif // UIPRINTDLG_H
