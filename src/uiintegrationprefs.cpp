/****************************************************************************
** Form implementation generated from reading ui file 'uiintegrationprefs.ui'
**
** Created: Tue Dec 25 12:41:17 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "uiintegrationprefs.h"

#include <qvariant.h>
#include <prefwidget.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qbuttongroup.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "colorbutton.h"

/*
 *  Constructs a UIIntegrationPrefs which is a child of 'parent', with the
 *  name 'name'.' 
 */
UIIntegrationPrefs::UIIntegrationPrefs( QWidget* parent,  const char* name )
    : PrefWidget( parent, name )
{
    if ( !name )
	setName( "UIIntegrationPrefs" );
    UIIntegrationPrefsLayout = new QVBoxLayout( this, 10, 5, "UIIntegrationPrefsLayout"); 

    Layout53_2 = new QHBoxLayout( 0, 0, 5, "Layout53_2"); 

    ui_showInt = new QCheckBox( this, "ui_showInt" );
    Layout53_2->addWidget( ui_showInt );
    Spacer40_2_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout53_2->addItem( Spacer40_2_2 );
    UIIntegrationPrefsLayout->addLayout( Layout53_2 );

    ButtonGroup15 = new QButtonGroup( this, "ButtonGroup15" );
    ButtonGroup15->setEnabled( FALSE );
    ButtonGroup15->setColumnLayout(0, Qt::Vertical );
    ButtonGroup15->layout()->setSpacing( 5 );
    ButtonGroup15->layout()->setMargin( 10 );
    ButtonGroup15Layout = new QGridLayout( ButtonGroup15->layout() );
    ButtonGroup15Layout->setAlignment( Qt::AlignTop );

    Layout17_2_2 = new QHBoxLayout( 0, 0, 5, "Layout17_2_2"); 

    ui_intColor = new ColorButton( ButtonGroup15, "ui_intColor" );
    ui_intColor->setMinimumSize( QSize( 50, 0 ) );
    ui_intColor->setMaximumSize( QSize( 50, 32767 ) );
    Layout17_2_2->addWidget( ui_intColor );

    label_2_2_2_3 = new QLabel( ButtonGroup15, "label_2_2_2_3" );
    label_2_2_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)1, 0, 0, label_2_2_2_3->sizePolicy().hasHeightForWidth() ) );
    Layout17_2_2->addWidget( label_2_2_2_3 );

    ButtonGroup15Layout->addLayout( Layout17_2_2, 0, 0 );

    Layout17_2_2_2 = new QHBoxLayout( 0, 0, 5, "Layout17_2_2_2"); 

    ui_intThresholdColor = new ColorButton( ButtonGroup15, "ui_intThresholdColor" );
    ui_intThresholdColor->setMinimumSize( QSize( 50, 0 ) );
    ui_intThresholdColor->setMaximumSize( QSize( 50, 32767 ) );
    Layout17_2_2_2->addWidget( ui_intThresholdColor );

    label_2_2_2_2_2 = new QLabel( ButtonGroup15, "label_2_2_2_2_2" );
    label_2_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)1, 0, 0, label_2_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    Layout17_2_2_2->addWidget( label_2_2_2_2_2 );

    ButtonGroup15Layout->addLayout( Layout17_2_2_2, 0, 1 );
    UIIntegrationPrefsLayout->addWidget( ButtonGroup15 );

    ButtonGroup16 = new QButtonGroup( this, "ButtonGroup16" );
    ButtonGroup16->setEnabled( FALSE );
    ButtonGroup16->setColumnLayout(0, Qt::Vertical );
    ButtonGroup16->layout()->setSpacing( 5 );
    ButtonGroup16->layout()->setMargin( 10 );
    ButtonGroup16Layout = new QGridLayout( ButtonGroup16->layout() );
    ButtonGroup16Layout->setAlignment( Qt::AlignTop );

    TextLabel1_3_2_2 = new QLabel( ButtonGroup16, "TextLabel1_3_2_2" );
    TextLabel1_3_2_2->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup16Layout->addWidget( TextLabel1_3_2_2, 1, 0 );

    TextLabel1_5_2 = new QLabel( ButtonGroup16, "TextLabel1_5_2" );
    TextLabel1_5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)1, 0, 0, TextLabel1_5_2->sizePolicy().hasHeightForWidth() ) );
    TextLabel1_5_2->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup16Layout->addWidget( TextLabel1_5_2, 0, 0 );

    ui_intPointMode = new QComboBox( FALSE, ButtonGroup16, "ui_intPointMode" );

    ButtonGroup16Layout->addWidget( ui_intPointMode, 1, 1 );

    ui_intLineMode = new QComboBox( FALSE, ButtonGroup16, "ui_intLineMode" );

    ButtonGroup16Layout->addWidget( ui_intLineMode, 0, 1 );

    TextLabel1_3 = new QLabel( ButtonGroup16, "TextLabel1_3" );
    TextLabel1_3->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup16Layout->addWidget( TextLabel1_3, 0, 2 );

    ui_intLineWidth = new QSpinBox( ButtonGroup16, "ui_intLineWidth" );
    ui_intLineWidth->setMaximumSize( QSize( 50, 32767 ) );
    ui_intLineWidth->setMaxValue( 5 );
    ui_intLineWidth->setMinValue( 1 );
    ui_intLineWidth->setValue( 1 );

    ButtonGroup16Layout->addWidget( ui_intLineWidth, 0, 3 );
    Spacer3_2_3_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ButtonGroup16Layout->addMultiCell( Spacer3_2_3_2, 1, 1, 2, 4 );
    Spacer234 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ButtonGroup16Layout->addItem( Spacer234, 0, 4 );
    UIIntegrationPrefsLayout->addWidget( ButtonGroup16 );

    ButtonGroup12 = new QButtonGroup( this, "ButtonGroup12" );
    ButtonGroup12->setEnabled( FALSE );
    ButtonGroup12->setColumnLayout(0, Qt::Vertical );
    ButtonGroup12->layout()->setSpacing( 5 );
    ButtonGroup12->layout()->setMargin( 10 );
    ButtonGroup12Layout = new QGridLayout( ButtonGroup12->layout() );
    ButtonGroup12Layout->setAlignment( Qt::AlignTop );

    TextLabel2_4_2_2 = new QLabel( ButtonGroup12, "TextLabel2_4_2_2" );
    TextLabel2_4_2_2->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup12Layout->addWidget( TextLabel2_4_2_2, 1, 0 );

    TextLabel3_3_2_2_2 = new QLabel( ButtonGroup12, "TextLabel3_3_2_2_2" );
    TextLabel3_3_2_2_2->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup12Layout->addWidget( TextLabel3_3_2_2_2, 2, 0 );

    ui_intScale = new QLineEdit( ButtonGroup12, "ui_intScale" );
    ui_intScale->setMaxLength( 12 );

    ButtonGroup12Layout->addWidget( ui_intScale, 1, 1 );

    ui_intOffset = new QLineEdit( ButtonGroup12, "ui_intOffset" );
    ui_intOffset->setMaxLength( 12 );

    ButtonGroup12Layout->addWidget( ui_intOffset, 1, 3 );

    TextLabel3_3_2_3 = new QLabel( ButtonGroup12, "TextLabel3_3_2_3" );
    TextLabel3_3_2_3->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup12Layout->addWidget( TextLabel3_3_2_3, 1, 2 );

    ui_intThreshold = new QLineEdit( ButtonGroup12, "ui_intThreshold" );
    ui_intThreshold->setMaxLength( 12 );

    ButtonGroup12Layout->addWidget( ui_intThreshold, 2, 1 );
    UIIntegrationPrefsLayout->addWidget( ButtonGroup12 );
    Spacer47 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    UIIntegrationPrefsLayout->addItem( Spacer47 );
    languageChange();
    resize( QSize(366, 267).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( ui_showInt, SIGNAL( toggled(bool) ), ButtonGroup15, SLOT( setEnabled(bool) ) );
    connect( ui_showInt, SIGNAL( toggled(bool) ), ButtonGroup16, SLOT( setEnabled(bool) ) );
    connect( ui_showInt, SIGNAL( toggled(bool) ), ButtonGroup12, SLOT( setEnabled(bool) ) );

    // tab order
    setTabOrder( ui_showInt, ui_intLineMode );
    setTabOrder( ui_intLineMode, ui_intLineWidth );
    setTabOrder( ui_intLineWidth, ui_intPointMode );
    setTabOrder( ui_intPointMode, ui_intScale );
    setTabOrder( ui_intScale, ui_intOffset );
    setTabOrder( ui_intOffset, ui_intThreshold );
}

/*
 *  Destroys the object and frees any allocated resources
 */
UIIntegrationPrefs::~UIIntegrationPrefs()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void UIIntegrationPrefs::languageChange()
{
    setCaption( tr( "QFrameForm" ) );
    ui_showInt->setText( tr( "Show integration" ) );
    ButtonGroup15->setTitle( tr( "Colors" ) );
    QWhatsThis::add( ui_intColor, tr( "Click this button so change the color of the data graph in the recorder." ) );
    label_2_2_2_3->setText( tr( "Integration graph" ) );
    QWhatsThis::add( ui_intThresholdColor, tr( "Click this button so change the color of the data graph in the recorder." ) );
    label_2_2_2_2_2->setText( tr( "Integration threshold" ) );
    ButtonGroup16->setTitle( tr( "Drawing style" ) );
    TextLabel1_3_2_2->setText( tr( "Point style:" ) );
    TextLabel1_5_2->setText( tr( "Line style:" ) );
    ui_intPointMode->clear();
    ui_intPointMode->insertItem( tr( "No points" ) );
    ui_intPointMode->insertItem( tr( "Circle" ) );
    ui_intPointMode->insertItem( tr( "Square" ) );
    ui_intPointMode->insertItem( tr( "Diamond" ) );
    ui_intPointMode->insertItem( tr( "X" ) );
    ui_intPointMode->insertItem( tr( "Large Circle" ) );
    ui_intPointMode->insertItem( tr( "Large Square" ) );
    ui_intPointMode->insertItem( tr( "Large Diamond" ) );
    ui_intPointMode->insertItem( tr( "Large X" ) );
    ui_intPointMode->setCurrentItem( 1 );
    ui_intLineMode->clear();
    ui_intLineMode->insertItem( tr( "No line" ) );
    ui_intLineMode->insertItem( tr( "Solid line" ) );
    ui_intLineMode->insertItem( tr( "Dotted line" ) );
    TextLabel1_3->setText( tr( "Width:" ) );
    QWhatsThis::add( ui_intLineWidth, tr( "Here you can choose the line width of the data graph in the recorder." ) );
    ButtonGroup12->setTitle( tr( "Graph" ) );
    TextLabel2_4_2_2->setText( tr( "Scale:" ) );
    TextLabel3_3_2_2_2->setText( tr( "Threshold:" ) );
    ui_intScale->setText( tr( "1.0" ) );
    QWhatsThis::add( ui_intScale, tr( "Scaling factor for integration curve.<p>\n"
"You can enter your values with a suffix like m, u, n, p, k, M, G, T<br>Example:<br>\n"
"10k - 10000<br>100m - 0.1" ) );
    ui_intOffset->setText( tr( "0.0" ) );
    QWhatsThis::add( ui_intOffset, tr( "Amplitude offset for integration curve.<p>\n"
"You can enter your values with a suffix like m, u, n, p, k, M, G, T<br>Example:<br>\n"
"10k - 10000<br>100m - 0.1" ) );
    TextLabel3_3_2_3->setText( tr( "Offset:" ) );
    ui_intThreshold->setText( tr( "0.0" ) );
    QWhatsThis::add( ui_intThreshold, tr( "If sampled value gets below this offset the integration curve is reset to zero.<p>\n"
"You can enter your values with a suffix like m, u, n, p, k, M, G, T<br>Example:<br>\n"
"10k - 10000<br>100m - 0.1" ) );
}

