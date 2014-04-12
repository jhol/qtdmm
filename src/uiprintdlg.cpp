/****************************************************************************
** Form implementation generated from reading ui file 'uiprintdlg.ui'
**
** Created: Tue Dec 25 12:41:20 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "uiprintdlg.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qframe.h>
#include <qlineedit.h>
#include <qmultilineedit.h>
#include <qlayout.h>
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
 *  Constructs a UIPrintDlg as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
UIPrintDlg::UIPrintDlg( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl ),
      image0( (const char **) image0_data ),
      image1( (const char **) image1_data )
{
    if ( !name )
	setName( "UIPrintDlg" );
    setIcon( image0 );
    setSizeGripEnabled( TRUE );
    UIPrintDlgLayout = new QVBoxLayout( this, 11, 6, "UIPrintDlgLayout"); 

    Layout2 = new QHBoxLayout( 0, 0, 5, "Layout2"); 

    TextLabel3 = new QLabel( this, "TextLabel3" );
    TextLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, TextLabel3->sizePolicy().hasHeightForWidth() ) );
    QFont TextLabel3_font(  TextLabel3->font() );
    TextLabel3_font.setPointSize( 12 );
    TextLabel3_font.setBold( TRUE );
    TextLabel3->setFont( TextLabel3_font ); 
    Layout2->addWidget( TextLabel3 );

    printerLabel = new QLabel( this, "printerLabel" );
    printerLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, printerLabel->sizePolicy().hasHeightForWidth() ) );
    printerLabel->setFrameShape( QLabel::NoFrame );
    printerLabel->setFrameShadow( QLabel::Sunken );
    printerLabel->setMargin( 0 );
    printerLabel->setIndent( 8 );
    Layout2->addWidget( printerLabel );

    configBut = new QPushButton( this, "configBut" );
    configBut->setAutoDefault( FALSE );
    Layout2->addWidget( configBut );
    UIPrintDlgLayout->addLayout( Layout2 );

    Frame5 = new QFrame( this, "Frame5" );
    Frame5->setFrameShape( QFrame::WinPanel );
    Frame5->setFrameShadow( QFrame::Raised );
    Frame5Layout = new QVBoxLayout( Frame5, 10, 5, "Frame5Layout"); 

    TextLabel1 = new QLabel( Frame5, "TextLabel1" );
    Frame5Layout->addWidget( TextLabel1 );

    printTitle = new QLineEdit( Frame5, "printTitle" );
    printTitle->setFrame( TRUE );
    Frame5Layout->addWidget( printTitle );

    TextLabel2 = new QLabel( Frame5, "TextLabel2" );
    Frame5Layout->addWidget( TextLabel2 );

    printComment = new QMultiLineEdit( Frame5, "printComment" );
    printComment->setFrameShape( QMultiLineEdit::WinPanel );
    printComment->setFrameShadow( QMultiLineEdit::Sunken );
    printComment->setLineWidth( 1 );
    printComment->setWordWrap( QMultiLineEdit::WidgetWidth );
    Frame5Layout->addWidget( printComment );
    UIPrintDlgLayout->addWidget( Frame5 );

    Layout28 = new QHBoxLayout( 0, 0, 4, "Layout28"); 

    helpBut = new QPushButton( this, "helpBut" );
    helpBut->setMinimumSize( QSize( 26, 26 ) );
    helpBut->setPixmap( image1 );
    helpBut->setAutoDefault( FALSE );
    Layout28->addWidget( helpBut );
    Spacer2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout28->addItem( Spacer2 );

    printBut = new QPushButton( this, "printBut" );
    printBut->setEnabled( FALSE );
    printBut->setDefault( TRUE );
    Layout28->addWidget( printBut );

    cancelBut = new QPushButton( this, "cancelBut" );
    Layout28->addWidget( cancelBut );
    UIPrintDlgLayout->addLayout( Layout28 );
    languageChange();
    resize( QSize(531, 311).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

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
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void UIPrintDlg::languageChange()
{
    setCaption( tr( "QtDMM: Print graph ..." ) );
    setIconText( tr( "Print ..." ) );
    TextLabel3->setText( tr( "Printer:" ) );
    printerLabel->setText( tr( "Please select printer ->" ) );
    QWhatsThis::add( printerLabel, tr( "This label shows the currently selected printer. Click the button to the right to configure the printer. <i>(You have to select a printer in order to be able to print)</i>" ) );
    configBut->setText( tr( "Configure ..." ) );
    QWhatsThis::add( configBut, tr( "Click here to configure the printer." ) );
    TextLabel1->setText( tr( "Title" ) );
    QWhatsThis::add( printTitle, tr( "Enter a title for the document <i>(Optional)</i>" ) );
    TextLabel2->setText( tr( "Comment" ) );
    QWhatsThis::add( printComment, tr( "Here you may enter an comment which will be printed on top of the page <i>(Optional)</i>" ) );
    helpBut->setText( QString::null );
    QToolTip::add( helpBut, tr( "Direct help (SHIFT+F1)" ) );
    printBut->setText( tr( "&Print" ) );
    QWhatsThis::add( printBut, tr( "Click here to print." ) );
    cancelBut->setText( tr( "&Cancel" ) );
    QWhatsThis::add( cancelBut, tr( "Click here to abort printing." ) );
}

