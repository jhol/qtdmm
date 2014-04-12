/****************************************************************************
** Form implementation generated from reading ui file 'uiprintdlg.ui'
**
** Created: Tue Sep 4 11:08:10 2001
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
"32 32 14 1",
". c None",
"# c #000000",
"i c #0018ff",
"k c #0020ff",
"l c #101010",
"c c #393939",
"b c #5a5a5a",
"a c #7b7b7b",
"e c #949494",
"j c #c5c5c5",
"d c #c5dec5",
"f c #ff0000",
"h c #ffee00",
"g c #ffffff",
"................................",
"......#####################.....",
".....#aaaaaaaaaaaaaaaaaaaaa#....",
"....#abbbbbbbbbbbbbbbbbbbbbc#...",
"....#ab###################bc#...",
"....#ab#ddddddddddddddddd#bc#...",
"....#ab#d###ddd#d#d###d#d#bc#...",
"....#ab#ddd#ddd#d#ddd#d#d#bc#...",
"....#ab#d###ddd###d###d#d#bc#...",
"....#ab#ddd#ddddd#d#ddd#d#bc#...",
"....#ab#d###d#ddd#d###d#d#bc#...",
"....#ab#ddddddddddddddddd#bc#...",
"....#ab#d#e#e#e#ddddddddd#bc#...",
"....#ab#d#e#e#e#ddddddddd#bc#...",
"....#ab#ddddddddddddddddd#bc#...",
"....#ab###################bc#...",
"....#abbbbbbbbbbbbbbbbbbbbbc#...",
"....#abffbbbbbbbbbbbbbbbbbbb#...",
"....#afgffbbbbbbb##########c#...",
"....#afggfbbbb###eeeeeeeeeec#...",
"....#abffbb###eeeeeeheeeiiec#...",
"....#bbbb##eeeeeeeehhheiiiic#...",
"....#a###eeeeejjeejeeeeiiiic#...",
"....#aeeeeejeeeeeeeeeejeiiec#...",
"....#aheeeeeehhhjjjjeejeeeec#...",
"....#ahejeejjhhhjjjjjjeeeeec#...",
"....#ahjeejjj#######jjkeejec#...",
"....#aheejjj#########kkkejec#...",
"....#aheejj#g#ccccc###kkeeec#...",
"....#aheff##cglccccc###kkeec#...",
"....#aheff##clllccccc##kkeec#...",
"....ccccccccccccccccccccccccc..."};

static const char* const image1_data[] = { 
"22 22 4 1",
". c None",
"# c #000000",
"a c #000083",
"b c #4a4a4a",
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
    QPixmap image1( ( const char** ) image1_data );
    if ( !name )
	setName( "UIPrintDlg" );
    resize( 531, 311 ); 
    setCaption( tr( "QtDMM: Print graph ..." ) );
    setIcon( image0 );
    setIconText( tr( "Print ..." ) );
    setSizeGripEnabled( TRUE );
    UIPrintDlgLayout = new QVBoxLayout( this ); 
    UIPrintDlgLayout->setSpacing( 6 );
    UIPrintDlgLayout->setMargin( 11 );

    Layout2 = new QHBoxLayout; 
    Layout2->setSpacing( 5 );
    Layout2->setMargin( 0 );

    TextLabel3 = new QLabel( this, "TextLabel3" );
    TextLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, TextLabel3->sizePolicy().hasHeightForWidth() ) );
    QFont TextLabel3_font(  TextLabel3->font() );
    TextLabel3_font.setPointSize( 12 );
    TextLabel3_font.setBold( TRUE );
    TextLabel3->setFont( TextLabel3_font ); 
    TextLabel3->setText( tr( "Printer:" ) );
    Layout2->addWidget( TextLabel3 );

    printerLabel = new QLabel( this, "printerLabel" );
    printerLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, printerLabel->sizePolicy().hasHeightForWidth() ) );
    printerLabel->setFrameShape( QLabel::NoFrame );
    printerLabel->setFrameShadow( QLabel::Sunken );
    printerLabel->setMargin( 0 );
    printerLabel->setText( tr( "Please select printer ->" ) );
    printerLabel->setIndent( 8 );
    QWhatsThis::add(  printerLabel, tr( "This label shows the currently selected printer. Click the button to the right to configure the printer. <i>(You have to select a printer in order to be able to print)</i>" ) );
    Layout2->addWidget( printerLabel );

    configBut = new QPushButton( this, "configBut" );
    configBut->setText( tr( "Configure ..." ) );
    configBut->setAutoDefault( FALSE );
    QWhatsThis::add(  configBut, tr( "Click here to configure the printer." ) );
    Layout2->addWidget( configBut );
    UIPrintDlgLayout->addLayout( Layout2 );

    Frame5 = new QFrame( this, "Frame5" );
    Frame5->setFrameShape( QFrame::WinPanel );
    Frame5->setFrameShadow( QFrame::Raised );
    Frame5Layout = new QVBoxLayout( Frame5 ); 
    Frame5Layout->setSpacing( 5 );
    Frame5Layout->setMargin( 10 );

    TextLabel1 = new QLabel( Frame5, "TextLabel1" );
    TextLabel1->setText( tr( "Title" ) );
    Frame5Layout->addWidget( TextLabel1 );

    printTitle = new QLineEdit( Frame5, "printTitle" );
    printTitle->setFrame( TRUE );
    QWhatsThis::add(  printTitle, tr( "Enter a title for the document <i>(Optional)</i>" ) );
    Frame5Layout->addWidget( printTitle );

    TextLabel2 = new QLabel( Frame5, "TextLabel2" );
    TextLabel2->setText( tr( "Comment" ) );
    Frame5Layout->addWidget( TextLabel2 );

    printComment = new QMultiLineEdit( Frame5, "printComment" );
    printComment->setFrameShape( QMultiLineEdit::WinPanel );
    printComment->setFrameShadow( QMultiLineEdit::Sunken );
    printComment->setLineWidth( 1 );
    printComment->setWordWrap( QMultiLineEdit::WidgetWidth );
    QWhatsThis::add(  printComment, tr( "Here you may enter an comment which will be printed on top of the page <i>(Optional)</i>" ) );
    Frame5Layout->addWidget( printComment );
    UIPrintDlgLayout->addWidget( Frame5 );

    Layout28 = new QHBoxLayout; 
    Layout28->setSpacing( 4 );
    Layout28->setMargin( 0 );

    helpBut = new QPushButton( this, "helpBut" );
    helpBut->setMinimumSize( QSize( 26, 26 ) );
    helpBut->setText( tr( "" ) );
    helpBut->setPixmap( image1 );
    helpBut->setAutoDefault( FALSE );
    QToolTip::add(  helpBut, tr( "Direct help (SHIFT+F1)" ) );
    Layout28->addWidget( helpBut );
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout28->addItem( spacer );

    printBut = new QPushButton( this, "printBut" );
    printBut->setEnabled( FALSE );
    printBut->setText( tr( "&Print" ) );
    printBut->setDefault( TRUE );
    QWhatsThis::add(  printBut, tr( "Click here to print." ) );
    Layout28->addWidget( printBut );

    cancelBut = new QPushButton( this, "cancelBut" );
    cancelBut->setText( tr( "&Cancel" ) );
    QWhatsThis::add(  cancelBut, tr( "Click here to abort printing." ) );
    Layout28->addWidget( cancelBut );
    UIPrintDlgLayout->addLayout( Layout28 );

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
	QFont TextLabel3_font(  TextLabel3->font() );
	TextLabel3_font.setPointSize( 12 );
	TextLabel3_font.setBold( TRUE );
	TextLabel3->setFont( TextLabel3_font ); 
    }
    return ret;
}

