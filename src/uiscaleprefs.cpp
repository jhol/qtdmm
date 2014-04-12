/****************************************************************************
** Form implementation generated from reading ui file 'uiscaleprefs.ui'
**
** Created: Tue Dec 25 12:41:25 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "uiscaleprefs.h"

#include <qvariant.h>
#include <prefwidget.h>
#include <qpushbutton.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qlabel.h>
#include <qcheckbox.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a UIScalePrefs which is a child of 'parent', with the
 *  name 'name'.' 
 */
UIScalePrefs::UIScalePrefs( QWidget* parent,  const char* name )
    : PrefWidget( parent, name )
{
    if ( !name )
	setName( "UIScalePrefs" );
    setMaximumSize( QSize( 32767, 32767 ) );
    UIScalePrefsLayout = new QVBoxLayout( this, 10, 5, "UIScalePrefsLayout"); 

    ButtonGroup36 = new QButtonGroup( this, "ButtonGroup36" );
    ButtonGroup36->setFrameShape( QButtonGroup::Box );
    ButtonGroup36->setFrameShadow( QButtonGroup::Sunken );
    ButtonGroup36->setColumnLayout(0, Qt::Vertical );
    ButtonGroup36->layout()->setSpacing( 5 );
    ButtonGroup36->layout()->setMargin( 10 );
    ButtonGroup36Layout = new QVBoxLayout( ButtonGroup36->layout() );
    ButtonGroup36Layout->setAlignment( Qt::AlignTop );

    autoScaleBut = new QRadioButton( ButtonGroup36, "autoScaleBut" );
    autoScaleBut->setChecked( TRUE );
    ButtonGroup36Layout->addWidget( autoScaleBut );

    Layout12 = new QHBoxLayout( 0, 0, 5, "Layout12"); 

    TextLabel9_2 = new QLabel( ButtonGroup36, "TextLabel9_2" );
    TextLabel9_2->setMinimumSize( QSize( 20, 0 ) );
    Layout12->addWidget( TextLabel9_2 );

    ui_includeZero = new QCheckBox( ButtonGroup36, "ui_includeZero" );
    ui_includeZero->setChecked( TRUE );
    Layout12->addWidget( ui_includeZero );
    Spacer14 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout12->addItem( Spacer14 );
    ButtonGroup36Layout->addLayout( Layout12 );

    manualScaleBut = new QRadioButton( ButtonGroup36, "manualScaleBut" );
    ButtonGroup36Layout->addWidget( manualScaleBut );

    Layout15_2 = new QHBoxLayout( 0, 0, 5, "Layout15_2"); 

    TextLabel9 = new QLabel( ButtonGroup36, "TextLabel9" );
    TextLabel9->setMinimumSize( QSize( 20, 0 ) );
    Layout15_2->addWidget( TextLabel9 );

    TextLabel10 = new QLabel( ButtonGroup36, "TextLabel10" );
    TextLabel10->setEnabled( FALSE );
    Layout15_2->addWidget( TextLabel10 );

    ui_scaleMin = new QLineEdit( ButtonGroup36, "ui_scaleMin" );
    ui_scaleMin->setEnabled( FALSE );
    ui_scaleMin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, ui_scaleMin->sizePolicy().hasHeightForWidth() ) );
    ui_scaleMin->setMinimumSize( QSize( 60, 0 ) );
    ui_scaleMin->setMaximumSize( QSize( 60, 32767 ) );
    ui_scaleMin->setMaxLength( 12 );
    Layout15_2->addWidget( ui_scaleMin );

    TextLabel10_2 = new QLabel( ButtonGroup36, "TextLabel10_2" );
    TextLabel10_2->setEnabled( FALSE );
    Layout15_2->addWidget( TextLabel10_2 );

    ui_scaleMax = new QLineEdit( ButtonGroup36, "ui_scaleMax" );
    ui_scaleMax->setEnabled( FALSE );
    ui_scaleMax->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, ui_scaleMax->sizePolicy().hasHeightForWidth() ) );
    ui_scaleMax->setMinimumSize( QSize( 60, 0 ) );
    ui_scaleMax->setMaximumSize( QSize( 60, 32767 ) );
    ui_scaleMax->setMaxLength( 12 );
    Layout15_2->addWidget( ui_scaleMax );
    Spacer7 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout15_2->addItem( Spacer7 );
    ButtonGroup36Layout->addLayout( Layout15_2 );
    UIScalePrefsLayout->addWidget( ButtonGroup36 );

    ButtonGroup37 = new QButtonGroup( this, "ButtonGroup37" );
    ButtonGroup37->setColumnLayout(0, Qt::Vertical );
    ButtonGroup37->layout()->setSpacing( 5 );
    ButtonGroup37->layout()->setMargin( 10 );
    ButtonGroup37Layout = new QGridLayout( ButtonGroup37->layout() );
    ButtonGroup37Layout->setAlignment( Qt::AlignTop );

    TextLabel11 = new QLabel( ButtonGroup37, "TextLabel11" );
    TextLabel11->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup37Layout->addWidget( TextLabel11, 0, 0 );

    TextLabel12 = new QLabel( ButtonGroup37, "TextLabel12" );
    TextLabel12->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup37Layout->addWidget( TextLabel12, 1, 0 );
    Spacer8 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ButtonGroup37Layout->addItem( Spacer8, 0, 3 );

    sizeUnit = new QComboBox( FALSE, ButtonGroup37, "sizeUnit" );

    ButtonGroup37Layout->addWidget( sizeUnit, 0, 2 );

    lengthUnit = new QComboBox( FALSE, ButtonGroup37, "lengthUnit" );

    ButtonGroup37Layout->addWidget( lengthUnit, 1, 2 );

    ui_winSize = new QSpinBox( ButtonGroup37, "ui_winSize" );
    ui_winSize->setMaxValue( 99999 );
    ui_winSize->setMinValue( 1 );
    ui_winSize->setValue( 600 );

    ButtonGroup37Layout->addWidget( ui_winSize, 0, 1 );

    winLength = new QSpinBox( ButtonGroup37, "winLength" );
    winLength->setMaxValue( 99999 );
    winLength->setMinValue( 1 );
    winLength->setValue( 3600 );

    ButtonGroup37Layout->addWidget( winLength, 1, 1 );
    UIScalePrefsLayout->addWidget( ButtonGroup37 );
    Spacer5 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    UIScalePrefsLayout->addItem( Spacer5 );
    languageChange();
    resize( QSize(315, 240).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( manualScaleBut, SIGNAL( toggled(bool) ), TextLabel10, SLOT( setEnabled(bool) ) );
    connect( manualScaleBut, SIGNAL( toggled(bool) ), ui_scaleMin, SLOT( setEnabled(bool) ) );
    connect( manualScaleBut, SIGNAL( toggled(bool) ), TextLabel10_2, SLOT( setEnabled(bool) ) );
    connect( manualScaleBut, SIGNAL( toggled(bool) ), ui_scaleMax, SLOT( setEnabled(bool) ) );
    connect( autoScaleBut, SIGNAL( toggled(bool) ), ui_includeZero, SLOT( setEnabled(bool) ) );

    // tab order
    setTabOrder( autoScaleBut, manualScaleBut );
    setTabOrder( manualScaleBut, ui_scaleMin );
    setTabOrder( ui_scaleMin, ui_scaleMax );
    setTabOrder( ui_scaleMax, ui_winSize );
    setTabOrder( ui_winSize, sizeUnit );
    setTabOrder( sizeUnit, winLength );
    setTabOrder( winLength, lengthUnit );

    // buddies
    TextLabel10->setBuddy( ui_scaleMin );
    TextLabel10_2->setBuddy( ui_scaleMax );
    TextLabel11->setBuddy( ui_winSize );
    TextLabel12->setBuddy( winLength );
}

/*
 *  Destroys the object and frees any allocated resources
 */
UIScalePrefs::~UIScalePrefs()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void UIScalePrefs::languageChange()
{
    setCaption( tr( "QFrameForm" ) );
    QWhatsThis::add( this, tr( "Threshold for raising edge.<p>\n"
"You can enter your values with a suffix like m, u, n, p, k, M, G, T<br>Example:<br>\n"
"10k - 10000<br>100m - 0.1" ) );
    ButtonGroup36->setTitle( tr( "Scale" ) );
    autoScaleBut->setText( tr( "Au&tomatic" ) );
    QWhatsThis::add( autoScaleBut, tr( "Select this entry if you want automatic scaling of the vertical scale in the transient recorder." ) );
    ui_includeZero->setText( tr( "Include zero line" ) );
    manualScaleBut->setText( tr( "&Manual" ) );
    QWhatsThis::add( manualScaleBut, tr( "Select this entry if you want to set the minimum and maximum value for the scale manually. If selected enter the minimum and maximum values below." ) );
    TextLabel10->setText( tr( "M&inimum:" ) );
    ui_scaleMin->setText( tr( "-3.999" ) );
    QWhatsThis::add( ui_scaleMin, tr( "Enter the minimum scale value here.<p>\n"
"You can enter your values with a suffix like m, u, n, p, k, M, G, T<br>Example:<br>\n"
"10k - 10000<br>100m - 0.1" ) );
    TextLabel10_2->setText( tr( "Ma&ximum:" ) );
    ui_scaleMax->setText( tr( "3.999" ) );
    QWhatsThis::add( ui_scaleMax, tr( "Enter the maximum scale value here.<p>\n"
"You can enter your values with a suffix like m, u, n, p, k, M, G, T<br>Example:<br>\n"
"10k - 10000<br>100m - 0.1" ) );
    ButtonGroup37->setTitle( tr( "Window" ) );
    TextLabel11->setText( tr( "&Size:" ) );
    TextLabel12->setText( tr( "Max. &length:" ) );
    sizeUnit->clear();
    sizeUnit->insertItem( tr( "Seconds" ) );
    sizeUnit->insertItem( tr( "Minutes" ) );
    sizeUnit->insertItem( tr( "Hours" ) );
    sizeUnit->insertItem( tr( "Days" ) );
    QWhatsThis::add( sizeUnit, tr( "Unit for visible window width." ) );
    lengthUnit->clear();
    lengthUnit->insertItem( tr( "Seconds" ) );
    lengthUnit->insertItem( tr( "Minutes" ) );
    lengthUnit->insertItem( tr( "Hours" ) );
    lengthUnit->insertItem( tr( "Days" ) );
    QWhatsThis::add( ui_winSize, tr( "Size (in time) of the visible part of the recorder graph. See unit to the right." ) );
    QWhatsThis::add( winLength, tr( "Maximum length (in time) of the recorder graph. If this time is reached the first recorded values will be discarded. It will not stop recording." ) );
}

