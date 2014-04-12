/****************************************************************************
** Form implementation generated from reading ui file 'uimainwid.ui'
**
** Created: Wed May 9 20:40:03 2001
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "uimainwid.h"

#include <qframe.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include "dmmgraph.h"
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
 *  Constructs a UIMainWid which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
UIMainWid::UIMainWid( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    QPixmap image0( ( const char** ) image0_data );
    if ( !name )
	setName( "UIMainWid" );
    resize( 570, 360 ); 
    setCaption( tr( "QtDMM: (c) 2001 M. Toussaint" ) );
    UIMainWidLayout = new QGridLayout( this ); 
    UIMainWidLayout->setSpacing( 4 );
    UIMainWidLayout->setMargin( 8 );

    Line1 = new QFrame( this, "Line1" );
    Line1->setFrameStyle( QFrame::HLine | QFrame::Sunken );

    UIMainWidLayout->addMultiCellWidget( Line1, 4, 4, 0, 3 );

    connectBut = new QPushButton( this, "connectBut" );
    connectBut->setText( tr( "Connect" ) );
    connectBut->setAutoDefault( FALSE );
    connectBut->setToggleButton( TRUE );
    QWhatsThis::add(  connectBut, tr( "Click here to connect to your multi meter." ) );

    UIMainWidLayout->addWidget( connectBut, 0, 1 );
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    UIMainWidLayout->addItem( spacer, 0, 2 );

    TextLabel7 = new QLabel( this, "TextLabel7" );
    TextLabel7->setText( tr( "<center><b>QtDMM</b><br>&copy; 2001<br>M.Toussaint</center>" ) );
    TextLabel7->setTextFormat( QLabel::RichText );
    TextLabel7->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, TextLabel7->sizePolicy().hasHeightForWidth() ) );
    TextLabel7->setAlignment( int( QLabel::WordBreak | QLabel::AlignVCenter | QLabel::AlignLeft ) );

    UIMainWidLayout->addMultiCellWidget( TextLabel7, 0, 1, 3, 3 );

    resetBut = new QPushButton( this, "resetBut" );
    resetBut->setText( tr( "Reset" ) );
    resetBut->setToggleButton( FALSE );
    resetBut->setAutoDefault( FALSE );
    QWhatsThis::add(  resetBut, tr( "Click this button to reset the memory for the min/max values to the left of the main display." ) );

    UIMainWidLayout->addWidget( resetBut, 1, 1 );

    Frame3 = new QFrame( this, "Frame3" );
    Frame3->setFrameShadow( QFrame::Sunken );
    Frame3->setFrameShape( QFrame::StyledPanel );
    QPalette pal;
    QColorGroup cg;
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 237, 237, 237) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    Frame3->setPalette( pal );
    Frame3Layout = new QGridLayout( Frame3 ); 
    Frame3Layout->setSpacing( 2 );
    Frame3Layout->setMargin( 4 );

    minValue = new QLabel( Frame3, "minValue" );
    minValue->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, minValue->sizePolicy().hasHeightForWidth() ) );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 237, 237, 237) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    minValue->setPalette( pal );
    QFont minValue_font(  minValue->font() );
    minValue_font.setFamily( "adobe-courier" );
    minValue_font.setPointSize( 18 );
    minValue_font.setBold( TRUE );
    minValue->setFont( minValue_font ); 
    minValue->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    minValue->setMinimumSize( QSize( 70, 0 ) );
    QWhatsThis::add(  minValue, tr( "Here you see the smallest measured value. You can clear this memory by clicking the <b>Reset</b> button to the right." ) );

    Frame3Layout->addWidget( minValue, 0, 1 );

    minUnit = new QLabel( Frame3, "minUnit" );
    minUnit->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, minUnit->sizePolicy().hasHeightForWidth() ) );
    minUnit->setMinimumSize( QSize( 40, 0 ) );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 237, 237, 237) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    minUnit->setPalette( pal );
    QFont minUnit_font(  minUnit->font() );
    minUnit_font.setBold( TRUE );
    minUnit->setFont( minUnit_font ); 
    minUnit->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignLeft ) );

    Frame3Layout->addWidget( minUnit, 0, 2 );

    maxUnit = new QLabel( Frame3, "maxUnit" );
    maxUnit->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, maxUnit->sizePolicy().hasHeightForWidth() ) );
    maxUnit->setMinimumSize( QSize( 40, 0 ) );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 237, 237, 237) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    maxUnit->setPalette( pal );
    QFont maxUnit_font(  maxUnit->font() );
    maxUnit_font.setBold( TRUE );
    maxUnit->setFont( maxUnit_font ); 
    maxUnit->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignLeft ) );

    Frame3Layout->addWidget( maxUnit, 1, 2 );

    TextLabel2 = new QLabel( Frame3, "TextLabel2" );
    TextLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, TextLabel2->sizePolicy().hasHeightForWidth() ) );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 237, 237, 237) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    TextLabel2->setPalette( pal );
    TextLabel2->setText( tr( "Max:" ) );

    Frame3Layout->addWidget( TextLabel2, 1, 0 );

    maxValue = new QLabel( Frame3, "maxValue" );
    maxValue->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, maxValue->sizePolicy().hasHeightForWidth() ) );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 237, 237, 237) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    maxValue->setPalette( pal );
    QFont maxValue_font(  maxValue->font() );
    maxValue_font.setFamily( "adobe-courier" );
    maxValue_font.setPointSize( 18 );
    maxValue_font.setBold( TRUE );
    maxValue->setFont( maxValue_font ); 
    maxValue->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    maxValue->setMinimumSize( QSize( 70, 0 ) );
    QWhatsThis::add(  maxValue, tr( "Here you see the largest measured value. You can clear this memory by clicking the <b>Reset</b> button to the right." ) );

    Frame3Layout->addWidget( maxValue, 1, 1 );

    TextLabel1 = new QLabel( Frame3, "TextLabel1" );
    TextLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, TextLabel1->sizePolicy().hasHeightForWidth() ) );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 237, 237, 237) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    TextLabel1->setPalette( pal );
    TextLabel1->setText( tr( "Min:" ) );

    Frame3Layout->addWidget( TextLabel1, 0, 0 );

    Layout17 = new QGridLayout; 
    Layout17->setSpacing( 6 );
    Layout17->setMargin( 0 );

    value = new QLabel( Frame3, "value" );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 237, 237, 237) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    value->setPalette( pal );
    QFont value_font(  value->font() );
    value_font.setFamily( "adobe-courier" );
    value_font.setPointSize( 28 );
    value_font.setBold( TRUE );
    value->setFont( value_font ); 
    value->setText( tr( "0.000" ) );
    value->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, value->sizePolicy().hasHeightForWidth() ) );
    value->setMinimumSize( QSize( 120, 0 ) );
    value->setAlignment( int( QLabel::AlignCenter ) );
    QWhatsThis::add(  value, tr( "Here you see the current measured value. The display is updated once per second." ) );

    Layout17->addWidget( value, 0, 0 );

    unit = new QLabel( Frame3, "unit" );
    unit->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, unit->sizePolicy().hasHeightForWidth() ) );
    unit->setMinimumSize( QSize( 50, 0 ) );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 237, 237, 237) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 220, 220, 220) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 110, 110, 110) );
    cg.setColor( QColorGroup::Mid, QColor( 146, 146, 146) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 214, 220, 201) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    unit->setPalette( pal );
    QFont unit_font(  unit->font() );
    unit_font.setPointSize( 12 );
    unit_font.setBold( TRUE );
    unit->setFont( unit_font ); 
    QWhatsThis::add(  unit, tr( "Here you see the unit of the measured value." ) );

    Layout17->addWidget( unit, 0, 1 );

    Frame3Layout->addMultiCellLayout( Layout17, 0, 1, 3, 3 );

    UIMainWidLayout->addMultiCellWidget( Frame3, 0, 1, 0, 0 );

    Line3 = new QFrame( this, "Line3" );
    Line3->setFrameStyle( QFrame::HLine | QFrame::Sunken );

    UIMainWidLayout->addMultiCellWidget( Line3, 2, 2, 0, 3 );

    Layout5 = new QHBoxLayout; 
    Layout5->setSpacing( 5 );
    Layout5->setMargin( 0 );

    graph = new DMMGraph( this, "graph" );
    graph->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, graph->sizePolicy().hasHeightForWidth() ) );
    graph->setCursor( QCursor( 2 ) );
    QWhatsThis::add(  graph, tr( "This is the plotting area for the transient recorder. It is widely configurable by clicking the <b>config ...</b> button to the right. Data aquisition may be started by hand, at a specific time or automatically triggered by the measured value itself <i>(See configuration dialog)</i><p>\nThe maximum resolution for data aquisition is one second, but may also be configured to sample once a week or what ever you want.\n<p>\n<b>Note:</b> Connecting to the DMM as well as a change of the measuring unit automatically clears the graph." ) );
    Layout5->addWidget( graph );

    Layout4 = new QVBoxLayout; 
    Layout4->setSpacing( 4 );
    Layout4->setMargin( 0 );

    startBut = new QPushButton( this, "startBut" );
    startBut->setText( tr( "&Start" ) );
    startBut->setAutoDefault( FALSE );
    startBut->setEnabled( FALSE );
    QWhatsThis::add(  startBut, tr( "Click here to start the transient recorder <i>(Only in manual mode. See configuration dialog)</i>" ) );
    Layout4->addWidget( startBut );

    stopBut = new QPushButton( this, "stopBut" );
    stopBut->setText( tr( "Sto&p" ) );
    stopBut->setAutoDefault( FALSE );
    stopBut->setEnabled( FALSE );
    QWhatsThis::add(  stopBut, tr( "Click here to stop the transient recorder." ) );
    Layout4->addWidget( stopBut );

    clearBut = new QPushButton( this, "clearBut" );
    clearBut->setText( tr( "&Clear" ) );
    clearBut->setAutoDefault( FALSE );
    QWhatsThis::add(  clearBut, tr( "Click here to clear the graph <i>(Warning: You can't undo that)</i>" ) );
    Layout4->addWidget( clearBut );
    QSpacerItem* spacer_2 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    Layout4->addItem( spacer_2 );

    configBut = new QPushButton( this, "configBut" );
    configBut->setText( tr( "Config ..." ) );
    configBut->setAutoDefault( FALSE );
    QWhatsThis::add(  configBut, tr( "Click here to call the configuration dialog. In this dialog you can configure the sampling rate, scaling of the graph, port settings etc. <i>(Note: You have to be disconnected in order to be able to call the configuration dialog)</i>" ) );
    Layout4->addWidget( configBut );
    Layout5->addLayout( Layout4 );

    UIMainWidLayout->addMultiCellLayout( Layout5, 3, 3, 0, 3 );

    Layout27 = new QHBoxLayout; 
    Layout27->setSpacing( 4 );
    Layout27->setMargin( 0 );

    helpBut = new QPushButton( this, "helpBut" );
    helpBut->setText( tr( "" ) );
    helpBut->setPixmap( image0 );
    helpBut->setMinimumSize( QSize( 26, 26 ) );
    helpBut->setAutoDefault( FALSE );
    QToolTip::add(  helpBut, tr( "Direct help" ) );
    Layout27->addWidget( helpBut );

    quitBut = new QPushButton( this, "quitBut" );
    quitBut->setText( tr( "&Quit" ) );
    quitBut->setAutoDefault( FALSE );
    QWhatsThis::add(  quitBut, tr( "You guessed it :) Click here to quit the program. All settings are saved in the file <tt>\".qtdmmrc\"</tt>" ) );
    Layout27->addWidget( quitBut );
    QSpacerItem* spacer_3 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout27->addItem( spacer_3 );

    printBut = new QPushButton( this, "printBut" );
    printBut->setText( tr( "&Print ..." ) );
    printBut->setAutoDefault( FALSE );
    QWhatsThis::add(  printBut, tr( "Click here to print the graph. <i>(Note: This will always print the visible portion of your window)</i>" ) );
    Layout27->addWidget( printBut );

    exportBut = new QPushButton( this, "exportBut" );
    exportBut->setText( tr( "&Export ..." ) );
    exportBut->setAutoDefault( FALSE );
    QWhatsThis::add(  exportBut, tr( "Click here to export the sampled data as tab separated list. The data format is:<br>\n<b>DD.MM.YYYY</b> TAB <b>HH:MM:SS</b> TAB <b>value</b> TAB <b>unit</b><p>\n<i>(Note: This will always export all your data. Depending the way you configured the recorder this may result in huge files!)</i>" ) );
    Layout27->addWidget( exportBut );

    UIMainWidLayout->addMultiCellLayout( Layout27, 5, 5, 0, 3 );

    Layout27_2 = new QHBoxLayout; 
    Layout27_2->setSpacing( 1 );
    Layout27_2->setMargin( 0 );

    statusBar = new QLabel( this, "statusBar" );
    statusBar->setFrameShape( QLabel::Panel );
    statusBar->setFrameShadow( QLabel::Sunken );
    statusBar->setText( tr( "Not connected" ) );
    statusBar->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, statusBar->sizePolicy().hasHeightForWidth() ) );
    QWhatsThis::add(  statusBar, tr( "Here you find some status information and error messages that may occur, when you have problems connecting to your DMM." ) );
    Layout27_2->addWidget( statusBar );

    infoLabel = new QLabel( this, "infoLabel" );
    infoLabel->setText( tr( "1/10000" ) );
    infoLabel->setFrameShape( QLabel::Panel );
    infoLabel->setFrameShadow( QLabel::Sunken );
    infoLabel->setMinimumSize( QSize( 200, 0 ) );
    Layout27_2->addWidget( infoLabel );

    UIMainWidLayout->addMultiCellLayout( Layout27_2, 6, 6, 0, 3 );

    // signals and slots connections
    connect( connectBut, SIGNAL( toggled(bool) ), configBut, SLOT( setDisabled(bool) ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
UIMainWid::~UIMainWid()
{
    // no need to delete child widgets, Qt does it all for us
}

/*  
 *  Main event handler. Reimplemented to handle application
 *  font changes
 */
bool UIMainWid::event( QEvent* ev )
{
    bool ret = QWidget::event( ev ); 
    if ( ev->type() == QEvent::ApplicationFontChange ) {
	QFont minValue_font(  minValue->font() );
	minValue_font.setFamily( "adobe-courier" );
	minValue_font.setPointSize( 18 );
	minValue_font.setBold( TRUE );
	minValue->setFont( minValue_font ); 
	QFont minUnit_font(  minUnit->font() );
	minUnit_font.setBold( TRUE );
	minUnit->setFont( minUnit_font ); 
	QFont maxUnit_font(  maxUnit->font() );
	maxUnit_font.setBold( TRUE );
	maxUnit->setFont( maxUnit_font ); 
	QFont maxValue_font(  maxValue->font() );
	maxValue_font.setFamily( "adobe-courier" );
	maxValue_font.setPointSize( 18 );
	maxValue_font.setBold( TRUE );
	maxValue->setFont( maxValue_font ); 
	QFont value_font(  value->font() );
	value_font.setFamily( "adobe-courier" );
	value_font.setPointSize( 28 );
	value_font.setBold( TRUE );
	value->setFont( value_font ); 
	QFont unit_font(  unit->font() );
	unit_font.setPointSize( 12 );
	unit_font.setBold( TRUE );
	unit->setFont( unit_font ); 
    }
    return ret;
}

