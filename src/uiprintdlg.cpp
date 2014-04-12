/****************************************************************************
** Form implementation generated from reading ui file 'uiprintdlg.ui'
**
** Created: Sun Apr 15 20:03:16 2001
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "uiprintdlg.h"

#include <qframe.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qmultilineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

static const char* const image0_data[] = { 
"22 22 4 1",
". c None",
"# c #000000",
"a c #000083",
"b c #4a484a",
"......................",
"......................",
"......................",
"...#........aaaaa.....",
"...##......aaabaaa....",
"...###....aaabb.aaa...",
"...####...aabb...aab..",
"...#####..aab....aab..",
"...######..ab...aaab..",
"...#######..b..aaabb..",
"...########...aaabb...",
"...#########.aaabb....",
"...#####bbbbbaaab.....",
"...##b###.....bbb.....",
"...#bb###b...aaa......",
"....b..###...aaab.....",
".......###b...bbb.....",
"........###...........",
"........###b..........",
".........bbb..........",
"......................",
"......................"};


/* 
 *  Constructs a UIPrintDlg which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
UIPrintDlg::UIPrintDlg( QWidget* parent,  const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    QPixmap image0( ( const char** ) image0_data );
    if ( !name )
	setName( "UIPrintDlg" );
    resize( 592, 362 ); 
    setCaption( tr( "QtDMM: Print graph ..." ) );
    UIPrintDlgLayout = new QGridLayout( this ); 
    UIPrintDlgLayout->setSpacing( 4 );
    UIPrintDlgLayout->setMargin( 8 );

    Line4 = new QFrame( this, "Line4" );
    Line4->setFrameStyle( QFrame::HLine | QFrame::Sunken );

    UIPrintDlgLayout->addMultiCellWidget( Line4, 1, 1, 0, 2 );

    configBut = new QPushButton( this, "configBut" );
    configBut->setText( tr( "Configure ..." ) );
    configBut->setAutoDefault( FALSE );
    QWhatsThis::add(  configBut, tr( "Click here to configure the printer." ) );

    UIPrintDlgLayout->addWidget( configBut, 0, 2 );

    TextLabel2 = new QLabel( this, "TextLabel2" );
    TextLabel2->setText( tr( "Comment:" ) );
    TextLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, TextLabel2->sizePolicy().hasHeightForWidth() ) );

    UIPrintDlgLayout->addWidget( TextLabel2, 3, 0 );
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    UIPrintDlgLayout->addItem( spacer, 4, 0 );

    TextLabel1 = new QLabel( this, "TextLabel1" );
    TextLabel1->setText( tr( "Title:" ) );
    TextLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, TextLabel1->sizePolicy().hasHeightForWidth() ) );

    UIPrintDlgLayout->addWidget( TextLabel1, 2, 0 );

    TextLabel3 = new QLabel( this, "TextLabel3" );
    TextLabel3->setText( tr( "Printer:" ) );
    TextLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, TextLabel3->sizePolicy().hasHeightForWidth() ) );

    UIPrintDlgLayout->addWidget( TextLabel3, 0, 0 );

    printerLabel = new QLabel( this, "printerLabel" );
    printerLabel->setText( tr( "Please select printer ->" ) );
    printerLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, printerLabel->sizePolicy().hasHeightForWidth() ) );
    QFont printerLabel_font(  printerLabel->font() );
    printerLabel_font.setBold( TRUE );
    printerLabel->setFont( printerLabel_font ); 
    QWhatsThis::add(  printerLabel, tr( "This label shows the currently selected printer. Click the button to the right to configure the printer. <i>(You have to select a printer in order to be able to print)</i>" ) );

    UIPrintDlgLayout->addWidget( printerLabel, 0, 1 );

    printTitle = new QLineEdit( this, "printTitle" );
    QWhatsThis::add(  printTitle, tr( "Enter a title for the document <i>(Optional)</i>" ) );

    UIPrintDlgLayout->addMultiCellWidget( printTitle, 2, 2, 1, 2 );

    printComment = new QMultiLineEdit( this, "printComment" );
    printComment->setWordWrap( QMultiLineEdit::WidgetWidth );
    QWhatsThis::add(  printComment, tr( "Here you may enter an comment which will be printed on top of the page <i>(Optional)</i>" ) );

    UIPrintDlgLayout->addMultiCellWidget( printComment, 3, 4, 1, 2 );

    Line3 = new QFrame( this, "Line3" );
    Line3->setFrameStyle( QFrame::HLine | QFrame::Sunken );

    UIPrintDlgLayout->addMultiCellWidget( Line3, 5, 5, 0, 2 );

    Layout28 = new QHBoxLayout; 
    Layout28->setSpacing( 4 );
    Layout28->setMargin( 0 );

    helpBut = new QPushButton( this, "helpBut" );
    helpBut->setText( tr( "" ) );
    helpBut->setPixmap( image0 );
    helpBut->setAutoDefault( FALSE );
    helpBut->setMinimumSize( QSize( 26, 26 ) );
    QToolTip::add(  helpBut, tr( "Direct help" ) );
    Layout28->addWidget( helpBut );
    QSpacerItem* spacer_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout28->addItem( spacer_2 );

    printBut = new QPushButton( this, "printBut" );
    printBut->setText( tr( "&Print" ) );
    printBut->setDefault( TRUE );
    printBut->setEnabled( FALSE );
    QWhatsThis::add(  printBut, tr( "Click here to print." ) );
    Layout28->addWidget( printBut );

    cancelBut = new QPushButton( this, "cancelBut" );
    cancelBut->setText( tr( "&Cancel" ) );
    QWhatsThis::add(  cancelBut, tr( "Click here to abort printing." ) );
    Layout28->addWidget( cancelBut );

    UIPrintDlgLayout->addMultiCellLayout( Layout28, 6, 6, 0, 2 );

    // signals and slots connections
    connect( printBut, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( cancelBut, SIGNAL( clicked() ), this, SLOT( reject() ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
UIPrintDlg::~UIPrintDlg()
{
    // no need to delete child widgets, Qt does it all for us
}

/*  
 *  Main event handler. Reimplemented to handle application
 *  font changes
 */
bool UIPrintDlg::event( QEvent* ev )
{
    bool ret = QDialog::event( ev ); 
    if ( ev->type() == QEvent::ApplicationFontChange ) {
	QFont printerLabel_font(  printerLabel->font() );
	printerLabel_font.setBold( TRUE );
	printerLabel->setFont( printerLabel_font ); 
    }
    return ret;
}

