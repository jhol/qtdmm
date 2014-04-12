/****************************************************************************
** Form implementation generated from reading ui file 'uirecorderprefs.ui'
**
** Created: Tue Dec 25 12:41:22 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "uirecorderprefs.h"

#include <qvariant.h>
#include <prefwidget.h>
#include <qpushbutton.h>
#include <qbuttongroup.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include <qgroupbox.h>
#include <qradiobutton.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a UIRecorderPrefs which is a child of 'parent', with the
 *  name 'name'.' 
 */
UIRecorderPrefs::UIRecorderPrefs( QWidget* parent,  const char* name )
    : PrefWidget( parent, name )
{
    if ( !name )
	setName( "UIRecorderPrefs" );
    UIRecorderPrefsLayout = new QVBoxLayout( this, 10, 5, "UIRecorderPrefsLayout"); 

    ButtonGroup1 = new QButtonGroup( this, "ButtonGroup1" );
    ButtonGroup1->setExclusive( FALSE );
    ButtonGroup1->setColumnLayout(0, Qt::Vertical );
    ButtonGroup1->layout()->setSpacing( 5 );
    ButtonGroup1->layout()->setMargin( 10 );
    ButtonGroup1Layout = new QGridLayout( ButtonGroup1->layout() );
    ButtonGroup1Layout->setAlignment( Qt::AlignTop );

    sampLabel = new QLabel( ButtonGroup1, "sampLabel" );
    sampLabel->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup1Layout->addWidget( sampLabel, 0, 0 );

    ui_sampleUnit = new QComboBox( FALSE, ButtonGroup1, "ui_sampleUnit" );

    ButtonGroup1Layout->addWidget( ui_sampleUnit, 0, 2 );
    Spacer9 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ButtonGroup1Layout->addItem( Spacer9, 0, 3 );

    sampLabel_2 = new QLabel( ButtonGroup1, "sampLabel_2" );
    sampLabel_2->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup1Layout->addWidget( sampLabel_2, 1, 0 );

    timeUnit = new QComboBox( FALSE, ButtonGroup1, "timeUnit" );

    ButtonGroup1Layout->addWidget( timeUnit, 1, 2 );

    sampleEvery = new QSpinBox( ButtonGroup1, "sampleEvery" );
    sampleEvery->setMaxValue( 99999 );
    sampleEvery->setMinValue( 1 );
    sampleEvery->setValue( 1 );

    ButtonGroup1Layout->addWidget( sampleEvery, 0, 1 );

    sampleTime = new QSpinBox( ButtonGroup1, "sampleTime" );
    sampleTime->setMaxValue( 99999 );
    sampleTime->setMinValue( 0 );
    sampleTime->setValue( 0 );

    ButtonGroup1Layout->addWidget( sampleTime, 1, 1 );
    UIRecorderPrefsLayout->addWidget( ButtonGroup1 );

    GroupBox1 = new QGroupBox( this, "GroupBox1" );
    GroupBox1->setColumnLayout(0, Qt::Vertical );
    GroupBox1->layout()->setSpacing( 5 );
    GroupBox1->layout()->setMargin( 10 );
    GroupBox1Layout = new QVBoxLayout( GroupBox1->layout() );
    GroupBox1Layout->setAlignment( Qt::AlignTop );

    ButtonGroup32 = new QButtonGroup( GroupBox1, "ButtonGroup32" );
    ButtonGroup32->setFrameShape( QButtonGroup::NoFrame );
    ButtonGroup32->setExclusive( FALSE );
    ButtonGroup32->setColumnLayout(0, Qt::Vertical );
    ButtonGroup32->layout()->setSpacing( 5 );
    ButtonGroup32->layout()->setMargin( 0 );
    ButtonGroup32Layout = new QVBoxLayout( ButtonGroup32->layout() );
    ButtonGroup32Layout->setAlignment( Qt::AlignTop );

    Layout23 = new QHBoxLayout( 0, 0, 5, "Layout23"); 

    manualBut = new QRadioButton( ButtonGroup32, "manualBut" );
    manualBut->setChecked( TRUE );
    Layout23->addWidget( manualBut );
    Spacer7_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout23->addItem( Spacer7_2 );
    ButtonGroup32Layout->addLayout( Layout23 );

    Layout24 = new QHBoxLayout( 0, 0, 5, "Layout24"); 

    predefinedBut = new QRadioButton( ButtonGroup32, "predefinedBut" );
    Layout24->addWidget( predefinedBut );
    Spacer8_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout24->addItem( Spacer8_2 );
    ButtonGroup32Layout->addLayout( Layout24 );

    Layout8 = new QHBoxLayout( 0, 0, 5, "Layout8"); 

    Layout7 = new QHBoxLayout( 0, 0, 6, "Layout7"); 

    TextLabel5 = new QLabel( ButtonGroup32, "TextLabel5" );
    TextLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, 0, 0, TextLabel5->sizePolicy().hasHeightForWidth() ) );
    TextLabel5->setMinimumSize( QSize( 20, 0 ) );
    Layout7->addWidget( TextLabel5 );

    Layout6 = new QHBoxLayout( 0, 0, 6, "Layout6"); 

    hour = new QSpinBox( ButtonGroup32, "hour" );
    hour->setEnabled( FALSE );
    hour->setWrapping( TRUE );
    hour->setMaxValue( 23 );
    Layout6->addWidget( hour );

    TextLabel3 = new QLabel( ButtonGroup32, "TextLabel3" );
    TextLabel3->setEnabled( FALSE );
    QFont TextLabel3_font(  TextLabel3->font() );
    TextLabel3_font.setBold( TRUE );
    TextLabel3->setFont( TextLabel3_font ); 
    TextLabel3->setAlignment( int( QLabel::AlignCenter ) );
    Layout6->addWidget( TextLabel3 );

    minute = new QSpinBox( ButtonGroup32, "minute" );
    minute->setEnabled( FALSE );
    minute->setWrapping( TRUE );
    minute->setMaxValue( 59 );
    Layout6->addWidget( minute );

    TextLabel4 = new QLabel( ButtonGroup32, "TextLabel4" );
    TextLabel4->setEnabled( FALSE );
    QFont TextLabel4_font(  TextLabel4->font() );
    TextLabel4_font.setBold( TRUE );
    TextLabel4->setFont( TextLabel4_font ); 
    TextLabel4->setAlignment( int( QLabel::AlignCenter ) );
    Layout6->addWidget( TextLabel4 );

    second = new QSpinBox( ButtonGroup32, "second" );
    second->setEnabled( FALSE );
    second->setWrapping( TRUE );
    second->setMaxValue( 59 );
    Layout6->addWidget( second );
    Layout7->addLayout( Layout6 );
    Layout8->addLayout( Layout7 );
    Spacer2_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout8->addItem( Spacer2_2 );
    ButtonGroup32Layout->addLayout( Layout8 );

    Layout25 = new QHBoxLayout( 0, 0, 5, "Layout25"); 

    triggerBut = new QRadioButton( ButtonGroup32, "triggerBut" );
    Layout25->addWidget( triggerBut );
    Spacer9_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout25->addItem( Spacer9_2 );
    ButtonGroup32Layout->addLayout( Layout25 );
    GroupBox1Layout->addWidget( ButtonGroup32 );

    ButtonGroup13 = new QButtonGroup( GroupBox1, "ButtonGroup13" );
    ButtonGroup13->setFrameShape( QButtonGroup::NoFrame );
    ButtonGroup13->setExclusive( FALSE );
    ButtonGroup13->setColumnLayout(0, Qt::Vertical );
    ButtonGroup13->layout()->setSpacing( 0 );
    ButtonGroup13->layout()->setMargin( 0 );
    ButtonGroup13Layout = new QVBoxLayout( ButtonGroup13->layout() );
    ButtonGroup13Layout->setAlignment( Qt::AlignTop );

    Layout14 = new QGridLayout( 0, 1, 1, 0, 5, "Layout14"); 
    Spacer3 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout14->addItem( Spacer3, 0, 3 );

    ui_fallingThreshold = new QLineEdit( ButtonGroup13, "ui_fallingThreshold" );
    ui_fallingThreshold->setEnabled( FALSE );
    ui_fallingThreshold->setMaximumSize( QSize( 80, 32767 ) );
    ui_fallingThreshold->setMaxLength( 12 );

    Layout14->addWidget( ui_fallingThreshold, 1, 2 );
    Spacer4_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout14->addItem( Spacer4_2, 1, 3 );

    ui_raisingThreshold = new QLineEdit( ButtonGroup13, "ui_raisingThreshold" );
    ui_raisingThreshold->setEnabled( FALSE );
    ui_raisingThreshold->setMaximumSize( QSize( 80, 32767 ) );
    ui_raisingThreshold->setMaxLength( 12 );

    Layout14->addWidget( ui_raisingThreshold, 0, 2 );

    TextLabel7 = new QLabel( ButtonGroup13, "TextLabel7" );
    TextLabel7->setEnabled( FALSE );

    Layout14->addWidget( TextLabel7, 0, 1 );

    TextLabel8 = new QLabel( ButtonGroup13, "TextLabel8" );
    TextLabel8->setEnabled( FALSE );

    Layout14->addWidget( TextLabel8, 1, 1 );

    Layout9 = new QHBoxLayout( 0, 0, 5, "Layout9"); 

    TextLabel6 = new QLabel( ButtonGroup13, "TextLabel6" );
    TextLabel6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, 0, 0, TextLabel6->sizePolicy().hasHeightForWidth() ) );
    TextLabel6->setMinimumSize( QSize( 20, 0 ) );
    Layout9->addWidget( TextLabel6 );

    raisingBut = new QRadioButton( ButtonGroup13, "raisingBut" );
    raisingBut->setEnabled( FALSE );
    raisingBut->setChecked( TRUE );
    Layout9->addWidget( raisingBut );

    Layout14->addLayout( Layout9, 0, 0 );

    Layout10 = new QHBoxLayout( 0, 0, 5, "Layout10"); 

    TextLabel6_2 = new QLabel( ButtonGroup13, "TextLabel6_2" );
    TextLabel6_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, 0, 0, TextLabel6_2->sizePolicy().hasHeightForWidth() ) );
    TextLabel6_2->setMinimumSize( QSize( 20, 0 ) );
    Layout10->addWidget( TextLabel6_2 );

    fallingBut = new QRadioButton( ButtonGroup13, "fallingBut" );
    fallingBut->setEnabled( FALSE );
    Layout10->addWidget( fallingBut );

    Layout14->addLayout( Layout10, 1, 0 );
    ButtonGroup13Layout->addLayout( Layout14 );
    GroupBox1Layout->addWidget( ButtonGroup13 );

    Layout11 = new QGridLayout( 0, 1, 1, 0, 5, "Layout11"); 

    ui_preTrigger = new QCheckBox( GroupBox1, "ui_preTrigger" );
    ui_preTrigger->setEnabled( FALSE );

    Layout11->addWidget( ui_preTrigger, 0, 1 );
    Spacer9_3 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout11->addItem( Spacer9_3, 1, 4 );

    ui_preTriggerTime = new QSpinBox( GroupBox1, "ui_preTriggerTime" );
    ui_preTriggerTime->setEnabled( FALSE );
    ui_preTriggerTime->setMaxValue( 99999 );
    ui_preTriggerTime->setMinValue( 1 );
    ui_preTriggerTime->setValue( 1 );

    Layout11->addWidget( ui_preTriggerTime, 1, 2 );

    ui_preTriggerUnit = new QComboBox( FALSE, GroupBox1, "ui_preTriggerUnit" );
    ui_preTriggerUnit->setEnabled( FALSE );

    Layout11->addWidget( ui_preTriggerUnit, 1, 3 );

    TextLabel6_2_2_2 = new QLabel( GroupBox1, "TextLabel6_2_2_2" );
    TextLabel6_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, 0, 0, TextLabel6_2_2_2->sizePolicy().hasHeightForWidth() ) );
    TextLabel6_2_2_2->setMinimumSize( QSize( 20, 0 ) );

    Layout11->addWidget( TextLabel6_2_2_2, 1, 0 );

    TextLabel6_2_2 = new QLabel( GroupBox1, "TextLabel6_2_2" );
    TextLabel6_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, 0, 0, TextLabel6_2_2->sizePolicy().hasHeightForWidth() ) );
    TextLabel6_2_2->setMinimumSize( QSize( 20, 0 ) );

    Layout11->addWidget( TextLabel6_2_2, 0, 0 );
    Spacer10 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout11->addMultiCell( Spacer10, 0, 0, 2, 4 );

    sampLabel_2_2 = new QLabel( GroupBox1, "sampLabel_2_2" );
    sampLabel_2_2->setEnabled( FALSE );
    sampLabel_2_2->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    Layout11->addWidget( sampLabel_2_2, 1, 1 );
    GroupBox1Layout->addLayout( Layout11 );
    UIRecorderPrefsLayout->addWidget( GroupBox1 );
    Spacer1_2 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    UIRecorderPrefsLayout->addItem( Spacer1_2 );
    languageChange();
    resize( QSize(317, 366).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( predefinedBut, SIGNAL( toggled(bool) ), hour, SLOT( setEnabled(bool) ) );
    connect( predefinedBut, SIGNAL( toggled(bool) ), TextLabel3, SLOT( setEnabled(bool) ) );
    connect( predefinedBut, SIGNAL( toggled(bool) ), minute, SLOT( setEnabled(bool) ) );
    connect( predefinedBut, SIGNAL( toggled(bool) ), second, SLOT( setEnabled(bool) ) );
    connect( predefinedBut, SIGNAL( toggled(bool) ), TextLabel4, SLOT( setEnabled(bool) ) );
    connect( triggerBut, SIGNAL( toggled(bool) ), raisingBut, SLOT( setEnabled(bool) ) );
    connect( triggerBut, SIGNAL( toggled(bool) ), fallingBut, SLOT( setEnabled(bool) ) );
    connect( triggerBut, SIGNAL( toggled(bool) ), TextLabel7, SLOT( setEnabled(bool) ) );
    connect( triggerBut, SIGNAL( toggled(bool) ), TextLabel8, SLOT( setEnabled(bool) ) );
    connect( triggerBut, SIGNAL( toggled(bool) ), ui_raisingThreshold, SLOT( setEnabled(bool) ) );
    connect( triggerBut, SIGNAL( toggled(bool) ), ui_fallingThreshold, SLOT( setEnabled(bool) ) );
    connect( raisingBut, SIGNAL( toggled(bool) ), TextLabel7, SLOT( setEnabled(bool) ) );
    connect( raisingBut, SIGNAL( toggled(bool) ), ui_raisingThreshold, SLOT( setEnabled(bool) ) );
    connect( raisingBut, SIGNAL( toggled(bool) ), TextLabel8, SLOT( setDisabled(bool) ) );
    connect( raisingBut, SIGNAL( toggled(bool) ), ui_fallingThreshold, SLOT( setDisabled(bool) ) );

    // tab order
    setTabOrder( sampleEvery, ui_sampleUnit );
    setTabOrder( ui_sampleUnit, sampleTime );
    setTabOrder( sampleTime, timeUnit );
    setTabOrder( timeUnit, manualBut );
    setTabOrder( manualBut, predefinedBut );
    setTabOrder( predefinedBut, hour );
    setTabOrder( hour, minute );
    setTabOrder( minute, second );
    setTabOrder( second, triggerBut );
    setTabOrder( triggerBut, raisingBut );
    setTabOrder( raisingBut, ui_raisingThreshold );
    setTabOrder( ui_raisingThreshold, fallingBut );
    setTabOrder( fallingBut, ui_fallingThreshold );

    // buddies
    sampLabel->setBuddy( sampleEvery );
    sampLabel_2->setBuddy( sampleTime );
    sampLabel_2_2->setBuddy( sampleTime );
}

/*
 *  Destroys the object and frees any allocated resources
 */
UIRecorderPrefs::~UIRecorderPrefs()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void UIRecorderPrefs::languageChange()
{
    setCaption( tr( "QFrameForm" ) );
    ButtonGroup1->setTitle( tr( "Sampling" ) );
    sampLabel->setText( tr( "Sample &every:" ) );
    ui_sampleUnit->clear();
    ui_sampleUnit->insertItem( tr( "1/10 Seconds" ) );
    ui_sampleUnit->insertItem( tr( "Seconds" ) );
    ui_sampleUnit->insertItem( tr( "Minutes" ) );
    ui_sampleUnit->insertItem( tr( "Hours" ) );
    ui_sampleUnit->insertItem( tr( "Days" ) );
    QWhatsThis::add( ui_sampleUnit, tr( "Unit for sampling period." ) );
    sampLabel_2->setText( tr( "Sample t&ime:" ) );
    timeUnit->clear();
    timeUnit->insertItem( tr( "Seconds" ) );
    timeUnit->insertItem( tr( "Minutes" ) );
    timeUnit->insertItem( tr( "Hours" ) );
    timeUnit->insertItem( tr( "Days" ) );
    QWhatsThis::add( timeUnit, tr( "Unit for maximum sampling time." ) );
    QWhatsThis::add( sampleEvery, tr( "Specify the sampling period. See unit to the right." ) );
    sampleTime->setSpecialValueText( tr( "Infinite" ) );
    QWhatsThis::add( sampleTime, tr( "Maximum sampling time. When this time expires, the recorder is stopped automatically." ) );
    GroupBox1->setTitle( tr( "Start" ) );
    ButtonGroup32->setTitle( QString::null );
    manualBut->setText( tr( "&Manual" ) );
    QWhatsThis::add( manualBut, tr( "Select this entry if you want to manually start the transient recorder. Use the <b>Start</b> and <b>Stop</b> buttons in the main window to start/stop sampling." ) );
    predefinedBut->setText( tr( "&Predefined time" ) );
    QWhatsThis::add( predefinedBut, tr( "Select this entry if you want the transient recorder to be started at a predefined time." ) );
    QWhatsThis::add( hour, tr( "Hour of start time." ) );
    TextLabel3->setText( tr( ":" ) );
    QWhatsThis::add( minute, tr( "Minutes of start time." ) );
    TextLabel4->setText( tr( ":" ) );
    QWhatsThis::add( second, tr( "Seconds of start time." ) );
    triggerBut->setText( tr( "&Trigger" ) );
    QWhatsThis::add( triggerBut, tr( "Select this entry if you want to automatically trigger the sampling. <p>\n"
"You have two choices:\n"
"<ul>\n"
"<li><b>Raising edge:</b> Sampling is started when the measured value gets bigger than the given threshold.</li>\n"
"<li><b>Falling edge:</b> Sampling is started when the measured value gets lower than the given threshold.</li>\n"
"</ul>" ) );
    ButtonGroup13->setTitle( QString::null );
    ui_fallingThreshold->setText( tr( "0.0" ) );
    QWhatsThis::add( ui_fallingThreshold, tr( "Threshold for falling edge.<p>\n"
"You can enter your values with a suffix like m, u, n, p, k, M, G, T<br>Example:<br>\n"
"10k - 10000<br>100m - 0.1" ) );
    ui_raisingThreshold->setText( tr( "0.0" ) );
    QWhatsThis::add( ui_raisingThreshold, tr( "Threshold for raising edge.<p>\n"
"You can enter your values with a suffix like m, u, n, p, k, M, G, T<br>Example:<br>\n"
"10k - 10000<br>100m - 0.1" ) );
    TextLabel7->setText( tr( "Threshold:" ) );
    TextLabel8->setText( tr( "Threshold:" ) );
    raisingBut->setText( tr( "&Raising edge" ) );
    QWhatsThis::add( raisingBut, tr( "Trigger sampling on raising edge." ) );
    fallingBut->setText( tr( "&Falling edge" ) );
    QWhatsThis::add( fallingBut, tr( "Trigger sampling on falling edge." ) );
    ui_preTrigger->setText( tr( "Pre trigger" ) );
    QWhatsThis::add( ui_preTriggerTime, tr( "Maximum sampling time. When this time expires, the recorder is stopped automatically." ) );
    ui_preTriggerUnit->clear();
    ui_preTriggerUnit->insertItem( tr( "Seconds" ) );
    ui_preTriggerUnit->insertItem( tr( "Minutes" ) );
    ui_preTriggerUnit->insertItem( tr( "Hours" ) );
    ui_preTriggerUnit->insertItem( tr( "Days" ) );
    QWhatsThis::add( ui_preTriggerUnit, tr( "Unit for maximum sampling time." ) );
    sampLabel_2_2->setText( tr( "Pre trigger time:" ) );
}

