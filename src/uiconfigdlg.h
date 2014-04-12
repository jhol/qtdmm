/****************************************************************************
** Form interface generated from reading ui file 'uiconfigdlg.ui'
**
** Created: Tue Dec 25 12:40:33 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef UICONFIGDLG_H
#define UICONFIGDLG_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QWidgetStack;
class QListView;
class QListViewItem;
class QLabel;
class QPushButton;
class QFrame;

class UIConfigDlg : public QDialog
{
    Q_OBJECT

public:
    UIConfigDlg( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~UIConfigDlg();

    QListView* ui_list;
    QLabel* ui_helpPixmap;
    QLabel* ui_helpText;
    QLabel* TextLabel1;
    QWidgetStack* ui_stack;
    QPushButton* ui_undo;
    QPushButton* ui_factoryDefaults;
    QFrame* Line7;
    QPushButton* ui_apply;
    QPushButton* ui_ok;
    QPushButton* ui_cancel;

protected:
    QVBoxLayout* UIConfigDlgLayout;
    QHBoxLayout* Layout48;
    QVBoxLayout* Layout47;
    QHBoxLayout* Layout16;
    QHBoxLayout* Layout46;
    QSpacerItem* Spacer45;
    QHBoxLayout* Layout17;
    QSpacerItem* Spacer61;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // UICONFIGDLG_H
