/****************************************************************************
** Form implementation generated from reading ui file 'uimainwid.ui'
**
** Created: Sun Sep 2 19:18:58 2001
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


/* 
 *  Constructs a UIMainWid which is a child of 'parent', with the 
 *  name 'name'.' 
 */
UIMainWid::UIMainWid( QWidget* parent,  const char* name )
    : QFrame( parent, name )
{
    QPixmap image0( ( const char** ) image0_data );
    if ( !name )
	setName( "UIMainWid" );
    resize( 645, 451 ); 
    setCaption( tr( "QtDMM: (c) 2001 M. Toussaint" ) );
    setIcon( image0 );
    setIconText( tr( "QtDMM 0.4" ) );
    setFrameShape( QFrame::StyledPanel );
    setFrameShadow( QFrame::Raised );
    UIMainWidLayout = new QGridLayout( this ); 
    UIMainWidLayout->setSpacing( 5 );
    UIMainWidLayout->setMargin( 5 );
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    UIMainWidLayout->addItem( spacer, 0, 2 );

    TextLabel7 = new QLabel( this, "TextLabel7" );
    TextLabel7->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, TextLabel7->sizePolicy().hasHeightForWidth() ) );
    TextLabel7->setText( tr( "<center><b>QtDMM</b><br>&copy; 2001<br>M.Toussaint</center>" ) );
    TextLabel7->setTextFormat( QLabel::RichText );
    TextLabel7->setAlignment( int( QLabel::WordBreak | QLabel::AlignVCenter | QLabel::AlignLeft ) );

    UIMainWidLayout->addMultiCellWidget( TextLabel7, 0, 1, 3, 3 );

    ui_displayFrame = new QFrame( this, "ui_displayFrame" );
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
    ui_displayFrame->setPalette( pal );
    ui_displayFrame->setFrameShape( QFrame::StyledPanel );
    ui_displayFrame->setFrameShadow( QFrame::Sunken );
    ui_displayFrameLayout = new QGridLayout( ui_displayFrame ); 
    ui_displayFrameLayout->setSpacing( 2 );
    ui_displayFrameLayout->setMargin( 4 );

    ui_minValue = new QLabel( ui_displayFrame, "ui_minValue" );
    ui_minValue->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, ui_minValue->sizePolicy().hasHeightForWidth() ) );
    ui_minValue->setMinimumSize( QSize( 70, 0 ) );
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
    ui_minValue->setPalette( pal );
    QFont ui_minValue_font(  ui_minValue->font() );
    ui_minValue_font.setFamily( "adobe-courier" );
    ui_minValue_font.setPointSize( 16 );
    ui_minValue_font.setBold( TRUE );
    ui_minValue->setFont( ui_minValue_font ); 
    ui_minValue->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    QWhatsThis::add(  ui_minValue, tr( "Here you see the smallest measured value. You can clear this memory by clicking the <b>Reset</b> button to the right." ) );

    ui_displayFrameLayout->addWidget( ui_minValue, 0, 1 );

    ui_minUnit = new QLabel( ui_displayFrame, "ui_minUnit" );
    ui_minUnit->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, ui_minUnit->sizePolicy().hasHeightForWidth() ) );
    ui_minUnit->setMinimumSize( QSize( 40, 0 ) );
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
    ui_minUnit->setPalette( pal );
    QFont ui_minUnit_font(  ui_minUnit->font() );
    ui_minUnit_font.setBold( TRUE );
    ui_minUnit->setFont( ui_minUnit_font ); 
    ui_minUnit->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignLeft ) );

    ui_displayFrameLayout->addWidget( ui_minUnit, 0, 2 );

    ui_maxUnit = new QLabel( ui_displayFrame, "ui_maxUnit" );
    ui_maxUnit->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, ui_maxUnit->sizePolicy().hasHeightForWidth() ) );
    ui_maxUnit->setMinimumSize( QSize( 40, 0 ) );
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
    ui_maxUnit->setPalette( pal );
    QFont ui_maxUnit_font(  ui_maxUnit->font() );
    ui_maxUnit_font.setBold( TRUE );
    ui_maxUnit->setFont( ui_maxUnit_font ); 
    ui_maxUnit->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignLeft ) );

    ui_displayFrameLayout->addWidget( ui_maxUnit, 1, 2 );

    ui_label1 = new QLabel( ui_displayFrame, "ui_label1" );
    ui_label1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, ui_label1->sizePolicy().hasHeightForWidth() ) );
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
    ui_label1->setPalette( pal );
    ui_label1->setText( tr( "Max:" ) );

    ui_displayFrameLayout->addWidget( ui_label1, 1, 0 );

    ui_maxValue = new QLabel( ui_displayFrame, "ui_maxValue" );
    ui_maxValue->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, ui_maxValue->sizePolicy().hasHeightForWidth() ) );
    ui_maxValue->setMinimumSize( QSize( 70, 0 ) );
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
    ui_maxValue->setPalette( pal );
    QFont ui_maxValue_font(  ui_maxValue->font() );
    ui_maxValue_font.setFamily( "adobe-courier" );
    ui_maxValue_font.setPointSize( 16 );
    ui_maxValue_font.setBold( TRUE );
    ui_maxValue->setFont( ui_maxValue_font ); 
    ui_maxValue->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    QWhatsThis::add(  ui_maxValue, tr( "Here you see the largest measured value. You can clear this memory by clicking the <b>Reset</b> button to the right." ) );

    ui_displayFrameLayout->addWidget( ui_maxValue, 1, 1 );

    ui_label2 = new QLabel( ui_displayFrame, "ui_label2" );
    ui_label2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, ui_label2->sizePolicy().hasHeightForWidth() ) );
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
    ui_label2->setPalette( pal );
    ui_label2->setText( tr( "Min:" ) );

    ui_displayFrameLayout->addWidget( ui_label2, 0, 0 );

    Layout17 = new QGridLayout; 
    Layout17->setSpacing( 6 );
    Layout17->setMargin( 0 );

    ui_value = new QLabel( ui_displayFrame, "ui_value" );
    ui_value->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, ui_value->sizePolicy().hasHeightForWidth() ) );
    ui_value->setMinimumSize( QSize( 120, 0 ) );
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
    cg.setColor( QColorGroup::Background, QColor( 212, 220, 207) );
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
    cg.setColor( QColorGroup::Background, QColor( 212, 220, 207) );
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
    cg.setColor( QColorGroup::Background, QColor( 212, 220, 207) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 100, 100, 145) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    ui_value->setPalette( pal );
    QFont ui_value_font(  ui_value->font() );
    ui_value_font.setFamily( "adobe-courier" );
    ui_value_font.setPointSize( 28 );
    ui_value_font.setBold( TRUE );
    ui_value->setFont( ui_value_font ); 
    ui_value->setText( tr( "0.000" ) );
    ui_value->setAlignment( int( QLabel::AlignCenter ) );
    QWhatsThis::add(  ui_value, tr( "Here you see the current measured value. The display is updated once per second." ) );

    Layout17->addWidget( ui_value, 0, 0 );

    ui_unit = new QLabel( ui_displayFrame, "ui_unit" );
    ui_unit->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, ui_unit->sizePolicy().hasHeightForWidth() ) );
    ui_unit->setMinimumSize( QSize( 50, 0 ) );
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
    ui_unit->setPalette( pal );
    QFont ui_unit_font(  ui_unit->font() );
    ui_unit_font.setPointSize( 12 );
    ui_unit_font.setBold( TRUE );
    ui_unit->setFont( ui_unit_font ); 
    QWhatsThis::add(  ui_unit, tr( "Here you see the unit of the measured value." ) );

    Layout17->addWidget( ui_unit, 0, 1 );

    ui_displayFrameLayout->addMultiCellLayout( Layout17, 0, 1, 3, 3 );

    UIMainWidLayout->addMultiCellWidget( ui_displayFrame, 0, 1, 0, 0 );

    Line3 = new QFrame( this, "Line3" );
    Line3->setFrameStyle( QFrame::HLine | QFrame::Sunken );

    UIMainWidLayout->addMultiCellWidget( Line3, 2, 2, 0, 3 );

    Layout5 = new QHBoxLayout; 
    Layout5->setSpacing( 5 );
    Layout5->setMargin( 0 );

    ui_graph = new DMMGraph( this, "ui_graph" );
    ui_graph->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, ui_graph->sizePolicy().hasHeightForWidth() ) );
    ui_graph->setMinimumSize( QSize( 0, 60 ) );
    ui_graph->setCursor( QCursor( 0 ) );
    QWhatsThis::add(  ui_graph, tr( "This is the plotting area for the transient recorder. It is widely configurable by clicking the <b>config ...</b> button to the right. Data aquisition may be started by hand, at a specific time or automatically triggered by the measured value itself <i>(See configuration dialog)</i><p>\nThe maximum resolution for data aquisition is one second, but may also be configured to sample once a week or what ever you want.\n<p>\n<b>Note:</b> Connecting to the DMM as well as a change of the measuring unit automatically clears the graph." ) );
    Layout5->addWidget( ui_graph );

    UIMainWidLayout->addMultiCellLayout( Layout5, 3, 3, 0, 3 );
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
    bool ret = QFrame::event( ev ); 
    if ( ev->type() == QEvent::ApplicationFontChange ) {
	QFont ui_minValue_font(  ui_minValue->font() );
	ui_minValue_font.setFamily( "adobe-courier" );
	ui_minValue_font.setPointSize( 16 );
	ui_minValue_font.setBold( TRUE );
	ui_minValue->setFont( ui_minValue_font ); 
	QFont ui_minUnit_font(  ui_minUnit->font() );
	ui_minUnit_font.setBold( TRUE );
	ui_minUnit->setFont( ui_minUnit_font ); 
	QFont ui_maxUnit_font(  ui_maxUnit->font() );
	ui_maxUnit_font.setBold( TRUE );
	ui_maxUnit->setFont( ui_maxUnit_font ); 
	QFont ui_maxValue_font(  ui_maxValue->font() );
	ui_maxValue_font.setFamily( "adobe-courier" );
	ui_maxValue_font.setPointSize( 16 );
	ui_maxValue_font.setBold( TRUE );
	ui_maxValue->setFont( ui_maxValue_font ); 
	QFont ui_value_font(  ui_value->font() );
	ui_value_font.setFamily( "adobe-courier" );
	ui_value_font.setPointSize( 28 );
	ui_value_font.setBold( TRUE );
	ui_value->setFont( ui_value_font ); 
	QFont ui_unit_font(  ui_unit->font() );
	ui_unit_font.setPointSize( 12 );
	ui_unit_font.setBold( TRUE );
	ui_unit->setFont( ui_unit_font ); 
    }
    return ret;
}

