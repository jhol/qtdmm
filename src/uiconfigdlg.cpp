/****************************************************************************
** Form implementation generated from reading ui file 'uiconfigdlg.ui'
**
** Created: Tue Dec 25 12:41:07 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "uiconfigdlg.h"

#include <qvariant.h>
#include <qwidgetstack.h>
#include <qpushbutton.h>
#include <qheader.h>
#include <qlistview.h>
#include <qlabel.h>
#include <qframe.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a UIConfigDlg as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
UIConfigDlg::UIConfigDlg( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "UIConfigDlg" );
    setSizeGripEnabled( TRUE );
    UIConfigDlgLayout = new QVBoxLayout( this, 10, 5, "UIConfigDlgLayout"); 

    Layout48 = new QHBoxLayout( 0, 0, 10, "Layout48"); 

    ui_list = new QListView( this, "ui_list" );
    ui_list->addColumn( tr( "Column 1" ) );
    ui_list->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)7, 0, 0, ui_list->sizePolicy().hasHeightForWidth() ) );
    ui_list->setHScrollBarMode( QListView::AlwaysOff );
    ui_list->setAllColumnsShowFocus( TRUE );
    Layout48->addWidget( ui_list );

    Layout47 = new QVBoxLayout( 0, 0, 5, "Layout47"); 

    Layout16 = new QHBoxLayout( 0, 0, 5, "Layout16"); 

    ui_helpPixmap = new QLabel( this, "ui_helpPixmap" );
    ui_helpPixmap->setFrameShape( QLabel::MShape );
    ui_helpPixmap->setFrameShadow( QLabel::MShadow );
    ui_helpPixmap->setAlignment( int( QLabel::AlignTop | QLabel::AlignHCenter ) );
    Layout16->addWidget( ui_helpPixmap );

    ui_helpText = new QLabel( this, "ui_helpText" );
    ui_helpText->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)1, 0, 0, ui_helpText->sizePolicy().hasHeightForWidth() ) );
    ui_helpText->setTextFormat( QLabel::RichText );
    ui_helpText->setAlignment( int( QLabel::AlignTop | QLabel::AlignLeft ) );
    Layout16->addWidget( ui_helpText );
    Layout47->addLayout( Layout16 );

    TextLabel1 = new QLabel( this, "TextLabel1" );
    TextLabel1->setMinimumSize( QSize( 0, 5 ) );
    TextLabel1->setMaximumSize( QSize( 32767, 5 ) );
    Layout47->addWidget( TextLabel1 );

    ui_stack = new QWidgetStack( this, "ui_stack" );
    ui_stack->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, ui_stack->sizePolicy().hasHeightForWidth() ) );
    Layout47->addWidget( ui_stack );

    Layout46 = new QHBoxLayout( 0, 0, 5, "Layout46"); 

    ui_undo = new QPushButton( this, "ui_undo" );
    ui_undo->setAutoDefault( FALSE );
    Layout46->addWidget( ui_undo );
    Spacer45 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout46->addItem( Spacer45 );

    ui_factoryDefaults = new QPushButton( this, "ui_factoryDefaults" );
    ui_factoryDefaults->setAutoDefault( FALSE );
    Layout46->addWidget( ui_factoryDefaults );
    Layout47->addLayout( Layout46 );
    Layout48->addLayout( Layout47 );
    UIConfigDlgLayout->addLayout( Layout48 );

    Line7 = new QFrame( this, "Line7" );
    Line7->setFrameStyle( QFrame::HLine | QFrame::Sunken );
    UIConfigDlgLayout->addWidget( Line7 );

    Layout17 = new QHBoxLayout( 0, 0, 5, "Layout17"); 
    Spacer61 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout17->addItem( Spacer61 );

    ui_apply = new QPushButton( this, "ui_apply" );
    ui_apply->setMinimumSize( QSize( 0, 0 ) );
    ui_apply->setMaximumSize( QSize( 32767, 32767 ) );
    Layout17->addWidget( ui_apply );

    ui_ok = new QPushButton( this, "ui_ok" );
    ui_ok->setDefault( TRUE );
    Layout17->addWidget( ui_ok );

    ui_cancel = new QPushButton( this, "ui_cancel" );
    Layout17->addWidget( ui_cancel );
    UIConfigDlgLayout->addLayout( Layout17 );
    languageChange();
    resize( QSize(334, 260).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // tab order
    setTabOrder( ui_list, ui_undo );
    setTabOrder( ui_undo, ui_factoryDefaults );
    setTabOrder( ui_factoryDefaults, ui_apply );
    setTabOrder( ui_apply, ui_ok );
    setTabOrder( ui_ok, ui_cancel );
}

/*
 *  Destroys the object and frees any allocated resources
 */
UIConfigDlg::~UIConfigDlg()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void UIConfigDlg::languageChange()
{
    setCaption( tr( "QtDMM: Preferences" ) );
    ui_list->header()->setLabel( 0, tr( "Column 1" ) );
    ui_undo->setText( tr( "&Undo" ) );
    ui_factoryDefaults->setText( tr( "&Factory defaults" ) );
    ui_apply->setText( tr( "&Apply" ) );
    QWhatsThis::add( ui_apply, tr( "Click this button so change the color of the data graph in the recorder." ) );
    ui_ok->setText( tr( "&Ok" ) );
    ui_cancel->setText( tr( "&Cancel" ) );
}

