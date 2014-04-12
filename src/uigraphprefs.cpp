/****************************************************************************
** Form implementation generated from reading ui file 'uigraphprefs.ui'
**
** Created: Tue Dec 25 12:41:13 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "uigraphprefs.h"

#include <qvariant.h>
#include <prefwidget.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qbuttongroup.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include <qcheckbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "colorbutton.h"

/*
 *  Constructs a UIGraphPrefs which is a child of 'parent', with the
 *  name 'name'.' 
 */
UIGraphPrefs::UIGraphPrefs( QWidget* parent,  const char* name )
    : PrefWidget( parent, name )
{
    if ( !name )
	setName( "UIGraphPrefs" );
    UIGraphPrefsLayout = new QVBoxLayout( this, 10, 5, "UIGraphPrefsLayout"); 

    GroupBox7 = new QGroupBox( this, "GroupBox7" );
    GroupBox7->setFrameShape( QGroupBox::Box );
    GroupBox7->setFrameShadow( QGroupBox::Sunken );
    GroupBox7->setColumnLayout(0, Qt::Vertical );
    GroupBox7->layout()->setSpacing( 5 );
    GroupBox7->layout()->setMargin( 10 );
    GroupBox7Layout = new QGridLayout( GroupBox7->layout() );
    GroupBox7Layout->setAlignment( Qt::AlignTop );

    Layout17_2 = new QHBoxLayout( 0, 0, 5, "Layout17_2"); 

    ui_dataColor = new ColorButton( GroupBox7, "ui_dataColor" );
    ui_dataColor->setMinimumSize( QSize( 50, 0 ) );
    ui_dataColor->setMaximumSize( QSize( 50, 32767 ) );
    Layout17_2->addWidget( ui_dataColor );

    label_2 = new QLabel( GroupBox7, "label_2" );
    label_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)1, 0, 0, label_2->sizePolicy().hasHeightForWidth() ) );
    Layout17_2->addWidget( label_2 );

    GroupBox7Layout->addLayout( Layout17_2, 1, 0 );

    Layout19_4 = new QHBoxLayout( 0, 0, 5, "Layout19_4"); 

    ui_bgColor = new ColorButton( GroupBox7, "ui_bgColor" );
    ui_bgColor->setMinimumSize( QSize( 50, 0 ) );
    ui_bgColor->setMaximumSize( QSize( 50, 32767 ) );
    Layout19_4->addWidget( ui_bgColor );

    TextLabel2_2_4 = new QLabel( GroupBox7, "TextLabel2_2_4" );
    TextLabel2_2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)1, 0, 0, TextLabel2_2_4->sizePolicy().hasHeightForWidth() ) );
    Layout19_4->addWidget( TextLabel2_2_4 );

    GroupBox7Layout->addLayout( Layout19_4, 0, 0 );

    Layout20_2 = new QHBoxLayout( 0, 0, 5, "Layout20_2"); 

    ui_gridColor = new ColorButton( GroupBox7, "ui_gridColor" );
    ui_gridColor->setMinimumSize( QSize( 50, 0 ) );
    ui_gridColor->setMaximumSize( QSize( 50, 32767 ) );
    Layout20_2->addWidget( ui_gridColor );

    TextLabel3_2_2 = new QLabel( GroupBox7, "TextLabel3_2_2" );
    TextLabel3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)1, 0, 0, TextLabel3_2_2->sizePolicy().hasHeightForWidth() ) );
    Layout20_2->addWidget( TextLabel3_2_2 );

    GroupBox7Layout->addLayout( Layout20_2, 0, 1 );

    Layout18_4 = new QHBoxLayout( 0, 0, 5, "Layout18_4"); 

    ui_cursorColor = new ColorButton( GroupBox7, "ui_cursorColor" );
    ui_cursorColor->setMinimumSize( QSize( 50, 0 ) );
    ui_cursorColor->setMaximumSize( QSize( 50, 32767 ) );
    Layout18_4->addWidget( ui_cursorColor );

    label2_4 = new QLabel( GroupBox7, "label2_4" );
    label2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)1, 0, 0, label2_4->sizePolicy().hasHeightForWidth() ) );
    Layout18_4->addWidget( label2_4 );

    GroupBox7Layout->addLayout( Layout18_4, 1, 1 );

    Layout18_2_2 = new QHBoxLayout( 0, 0, 5, "Layout18_2_2"); 

    ui_startColor = new ColorButton( GroupBox7, "ui_startColor" );
    ui_startColor->setMinimumSize( QSize( 50, 0 ) );
    ui_startColor->setMaximumSize( QSize( 50, 32767 ) );
    Layout18_2_2->addWidget( ui_startColor );

    label2_2_2 = new QLabel( GroupBox7, "label2_2_2" );
    label2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)1, 0, 0, label2_2_2->sizePolicy().hasHeightForWidth() ) );
    Layout18_2_2->addWidget( label2_2_2 );

    GroupBox7Layout->addLayout( Layout18_2_2, 2, 0 );

    Layout18_3_2 = new QHBoxLayout( 0, 0, 5, "Layout18_3_2"); 

    ui_extColor = new ColorButton( GroupBox7, "ui_extColor" );
    ui_extColor->setMinimumSize( QSize( 50, 0 ) );
    ui_extColor->setMaximumSize( QSize( 50, 32767 ) );
    Layout18_3_2->addWidget( ui_extColor );

    label2_3_2 = new QLabel( GroupBox7, "label2_3_2" );
    label2_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)1, 0, 0, label2_3_2->sizePolicy().hasHeightForWidth() ) );
    Layout18_3_2->addWidget( label2_3_2 );

    GroupBox7Layout->addLayout( Layout18_3_2, 2, 1 );
    UIGraphPrefsLayout->addWidget( GroupBox7 );

    ButtonGroup11_2 = new QButtonGroup( this, "ButtonGroup11_2" );
    ButtonGroup11_2->setColumnLayout(0, Qt::Vertical );
    ButtonGroup11_2->layout()->setSpacing( 5 );
    ButtonGroup11_2->layout()->setMargin( 10 );
    ButtonGroup11_2Layout = new QGridLayout( ButtonGroup11_2->layout() );
    ButtonGroup11_2Layout->setAlignment( Qt::AlignTop );

    TextLabel1_3_3_2 = new QLabel( ButtonGroup11_2, "TextLabel1_3_3_2" );
    TextLabel1_3_3_2->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup11_2Layout->addWidget( TextLabel1_3_3_2, 1, 0 );

    ui_lineMode = new QComboBox( FALSE, ButtonGroup11_2, "ui_lineMode" );

    ButtonGroup11_2Layout->addWidget( ui_lineMode, 0, 1 );

    TextLabel1_6_2 = new QLabel( ButtonGroup11_2, "TextLabel1_6_2" );
    TextLabel1_6_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)1, 0, 0, TextLabel1_6_2->sizePolicy().hasHeightForWidth() ) );
    TextLabel1_6_2->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup11_2Layout->addWidget( TextLabel1_6_2, 0, 0 );
    Spacer3_2_2_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ButtonGroup11_2Layout->addItem( Spacer3_2_2_2, 0, 4 );

    ui_lineWidth = new QSpinBox( ButtonGroup11_2, "ui_lineWidth" );
    ui_lineWidth->setMaximumSize( QSize( 50, 32767 ) );
    ui_lineWidth->setMaxValue( 5 );
    ui_lineWidth->setMinValue( 1 );
    ui_lineWidth->setValue( 2 );

    ButtonGroup11_2Layout->addWidget( ui_lineWidth, 0, 3 );

    TextLabel1 = new QLabel( ButtonGroup11_2, "TextLabel1" );
    TextLabel1->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup11_2Layout->addWidget( TextLabel1, 0, 2 );

    ui_pointMode = new QComboBox( FALSE, ButtonGroup11_2, "ui_pointMode" );

    ButtonGroup11_2Layout->addWidget( ui_pointMode, 1, 1 );
    Spacer233 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ButtonGroup11_2Layout->addMultiCell( Spacer233, 1, 1, 2, 4 );
    UIGraphPrefsLayout->addWidget( ButtonGroup11_2 );

    ui_crosshair = new QCheckBox( this, "ui_crosshair" );
    ui_crosshair->setChecked( TRUE );
    UIGraphPrefsLayout->addWidget( ui_crosshair );
    Spacer41 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    UIGraphPrefsLayout->addItem( Spacer41 );
    languageChange();
    resize( QSize(339, 225).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // tab order
    setTabOrder( ui_lineMode, ui_lineWidth );
    setTabOrder( ui_lineWidth, ui_pointMode );
    setTabOrder( ui_pointMode, ui_crosshair );

    // buddies
    label_2->setBuddy( ui_dataColor );
    TextLabel2_2_4->setBuddy( ui_bgColor );
    TextLabel3_2_2->setBuddy( ui_gridColor );
    label2_4->setBuddy( ui_cursorColor );
    label2_2_2->setBuddy( ui_startColor );
    label2_3_2->setBuddy( ui_extColor );
}

/*
 *  Destroys the object and frees any allocated resources
 */
UIGraphPrefs::~UIGraphPrefs()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void UIGraphPrefs::languageChange()
{
    setCaption( tr( "QFrameForm" ) );
    GroupBox7->setTitle( tr( "Colors" ) );
    QWhatsThis::add( ui_dataColor, tr( "Click this button so change the color of the data graph in the recorder." ) );
    label_2->setText( tr( "&Data" ) );
    QWhatsThis::add( ui_bgColor, tr( "Click this button to change the background color of the recorder graph." ) );
    TextLabel2_2_4->setText( tr( "&Background" ) );
    QWhatsThis::add( ui_gridColor, tr( "Click this button to change the color of the grid and grid text in the recorder." ) );
    TextLabel3_2_2->setText( tr( "&Grid" ) );
    QWhatsThis::add( ui_cursorColor, tr( "Click this button to change the color of the cursor at the current sampling position in the recorder." ) );
    label2_4->setText( tr( "Cu&rsor" ) );
    QWhatsThis::add( ui_startColor, tr( "Click this button to change the color of the cursor at the current sampling position in the recorder." ) );
    label2_2_2->setText( tr( "Start threshold" ) );
    QWhatsThis::add( ui_extColor, tr( "Click this button to change the color of the cursor at the current sampling position in the recorder." ) );
    label2_3_2->setText( tr( "E&xternal threshold" ) );
    ButtonGroup11_2->setTitle( tr( "Drawing style" ) );
    TextLabel1_3_3_2->setText( tr( "Data points:" ) );
    ui_lineMode->clear();
    ui_lineMode->insertItem( tr( "No line" ) );
    ui_lineMode->insertItem( tr( "Solid line" ) );
    ui_lineMode->insertItem( tr( "Dotted line" ) );
    ui_lineMode->setCurrentItem( 1 );
    TextLabel1_6_2->setText( tr( "Data:" ) );
    QWhatsThis::add( ui_lineWidth, tr( "Here you can choose the line width of the data graph in the recorder." ) );
    TextLabel1->setText( tr( "Width:" ) );
    ui_pointMode->clear();
    ui_pointMode->insertItem( tr( "No points" ) );
    ui_pointMode->insertItem( tr( "Circle" ) );
    ui_pointMode->insertItem( tr( "Square" ) );
    ui_pointMode->insertItem( tr( "Diamond" ) );
    ui_pointMode->insertItem( tr( "X" ) );
    ui_pointMode->insertItem( tr( "Large Circle" ) );
    ui_pointMode->insertItem( tr( "Large Square" ) );
    ui_pointMode->insertItem( tr( "Large Diamond" ) );
    ui_pointMode->insertItem( tr( "Large X" ) );
    ui_crosshair->setText( tr( "Crosshair cursor" ) );
}

