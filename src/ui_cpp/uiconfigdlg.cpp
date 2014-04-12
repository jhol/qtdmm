/****************************************************************************
** Form implementation generated from reading ui file 'uiconfigdlg.ui'
**
** Created: Wed May 9 20:39:56 2001
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "uiconfigdlg.h"

#include <qbuttongroup.h>
#include <qcombobox.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qspinbox.h>
#include <qtabwidget.h>
#include <qtextview.h>
#include <qwidget.h>
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
 *  Constructs a UIConfigDlg which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
UIConfigDlg::UIConfigDlg( QWidget* parent,  const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    QPixmap image0( ( const char** ) image0_data );
    if ( !name )
	setName( "UIConfigDlg" );
    resize( 389, 391 ); 
    setCaption( tr( "QtDMM: Configuration" ) );
    setSizeGripEnabled( TRUE );
    UIConfigDlgLayout = new QGridLayout( this ); 
    UIConfigDlgLayout->setSpacing( 5 );
    UIConfigDlgLayout->setMargin( 10 );

    Layout15 = new QHBoxLayout; 
    Layout15->setSpacing( 5 );
    Layout15->setMargin( 0 );

    helpBut = new QPushButton( this, "helpBut" );
    helpBut->setMinimumSize( QSize( 26, 26 ) );
    helpBut->setText( tr( "" ) );
    helpBut->setPixmap( image0 );
    helpBut->setAutoDefault( FALSE );
    QToolTip::add(  helpBut, tr( "Direct help" ) );
    Layout15->addWidget( helpBut );
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout15->addItem( spacer );

    okBut = new QPushButton( this, "okBut" );
    okBut->setText( tr( "&OK" ) );
    okBut->setAutoDefault( TRUE );
    okBut->setDefault( TRUE );
    QWhatsThis::add(  okBut, tr( "Apply changes and close dialog." ) );
    Layout15->addWidget( okBut );

    cancelBut = new QPushButton( this, "cancelBut" );
    cancelBut->setText( tr( "&Cancel" ) );
    cancelBut->setAutoDefault( TRUE );
    QWhatsThis::add(  cancelBut, tr( "Discard changes and close dialog." ) );
    Layout15->addWidget( cancelBut );

    UIConfigDlgLayout->addLayout( Layout15, 1, 0 );

    tabWidget = new QTabWidget( this, "tabWidget" );

    samplePage = new QWidget( tabWidget, "samplePage" );
    samplePageLayout = new QVBoxLayout( samplePage ); 
    samplePageLayout->setSpacing( 5 );
    samplePageLayout->setMargin( 10 );

    ButtonGroup1 = new QButtonGroup( samplePage, "ButtonGroup1" );
    ButtonGroup1->setTitle( tr( "Sample" ) );
    ButtonGroup1->setExclusive( FALSE );
    ButtonGroup1->setColumnLayout(0, Qt::Vertical );
    ButtonGroup1->layout()->setSpacing( 0 );
    ButtonGroup1->layout()->setMargin( 0 );
    ButtonGroup1Layout = new QGridLayout( ButtonGroup1->layout() );
    ButtonGroup1Layout->setAlignment( Qt::AlignTop );
    ButtonGroup1Layout->setSpacing( 5 );
    ButtonGroup1Layout->setMargin( 10 );

    sampLabel = new QLabel( ButtonGroup1, "sampLabel" );
    sampLabel->setText( tr( "Sample every:" ) );

    ButtonGroup1Layout->addWidget( sampLabel, 0, 0 );

    sampleEvery = new QLineEdit( ButtonGroup1, "sampleEvery" );
    sampleEvery->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, sampleEvery->sizePolicy().hasHeightForWidth() ) );
    sampleEvery->setMaximumSize( QSize( 60, 32767 ) );
    sampleEvery->setText( tr( "1" ) );
    sampleEvery->setMaxLength( 10 );
    QWhatsThis::add(  sampleEvery, tr( "Enter a integer value for the sampling period. Choose the unit to the right." ) );

    ButtonGroup1Layout->addWidget( sampleEvery, 0, 1 );

    sampleUnit = new QComboBox( FALSE, ButtonGroup1, "sampleUnit" );
    sampleUnit->insertItem( tr( "Seconds" ) );
    sampleUnit->insertItem( tr( "Minutes" ) );
    sampleUnit->insertItem( tr( "Hours" ) );
    sampleUnit->insertItem( tr( "Days" ) );

    ButtonGroup1Layout->addWidget( sampleUnit, 0, 2 );
    QSpacerItem* spacer_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ButtonGroup1Layout->addItem( spacer_2, 0, 3 );

    sampLabel_2 = new QLabel( ButtonGroup1, "sampLabel_2" );
    sampLabel_2->setText( tr( "Sample time:" ) );

    ButtonGroup1Layout->addWidget( sampLabel_2, 1, 0 );

    sampleTime = new QLineEdit( ButtonGroup1, "sampleTime" );
    sampleTime->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, sampleTime->sizePolicy().hasHeightForWidth() ) );
    sampleTime->setMaximumSize( QSize( 60, 32767 ) );
    sampleTime->setText( tr( "500" ) );
    sampleTime->setMaxLength( 10 );
    QWhatsThis::add(  sampleTime, tr( "Enter a integer value for the sampling interval. Choose the unit to the right." ) );

    ButtonGroup1Layout->addWidget( sampleTime, 1, 1 );

    timeUnit = new QComboBox( FALSE, ButtonGroup1, "timeUnit" );
    timeUnit->insertItem( tr( "Seconds" ) );
    timeUnit->insertItem( tr( "Minutes" ) );
    timeUnit->insertItem( tr( "Hours" ) );
    timeUnit->insertItem( tr( "Days" ) );

    ButtonGroup1Layout->addWidget( timeUnit, 1, 2 );
    samplePageLayout->addWidget( ButtonGroup1 );

    GroupBox1 = new QGroupBox( samplePage, "GroupBox1" );
    GroupBox1->setTitle( tr( "Start" ) );
    GroupBox1->setColumnLayout(0, Qt::Vertical );
    GroupBox1->layout()->setSpacing( 0 );
    GroupBox1->layout()->setMargin( 0 );
    GroupBox1Layout = new QVBoxLayout( GroupBox1->layout() );
    GroupBox1Layout->setAlignment( Qt::AlignTop );
    GroupBox1Layout->setSpacing( 5 );
    GroupBox1Layout->setMargin( 10 );

    ButtonGroup32 = new QButtonGroup( GroupBox1, "ButtonGroup32" );
    ButtonGroup32->setFrameShape( QButtonGroup::NoFrame );
    ButtonGroup32->setTitle( tr( "" ) );
    ButtonGroup32->setExclusive( FALSE );
    ButtonGroup32->setColumnLayout(0, Qt::Vertical );
    ButtonGroup32->layout()->setSpacing( 0 );
    ButtonGroup32->layout()->setMargin( 0 );
    ButtonGroup32Layout = new QVBoxLayout( ButtonGroup32->layout() );
    ButtonGroup32Layout->setAlignment( Qt::AlignTop );
    ButtonGroup32Layout->setSpacing( 5 );
    ButtonGroup32Layout->setMargin( 0 );

    Layout23 = new QHBoxLayout; 
    Layout23->setSpacing( 5 );
    Layout23->setMargin( 0 );

    manualBut = new QRadioButton( ButtonGroup32, "manualBut" );
    manualBut->setText( tr( "Manual" ) );
    manualBut->setChecked( TRUE );
    QWhatsThis::add(  manualBut, tr( "Select this entry if you want to manually start the transient recorder. Use the <b>Start</b> and <b>Stop</b> buttons in the main window to start/stop sampling." ) );
    Layout23->addWidget( manualBut );
    QSpacerItem* spacer_3 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout23->addItem( spacer_3 );
    ButtonGroup32Layout->addLayout( Layout23 );

    Layout24 = new QHBoxLayout; 
    Layout24->setSpacing( 5 );
    Layout24->setMargin( 0 );

    predefinedBut = new QRadioButton( ButtonGroup32, "predefinedBut" );
    predefinedBut->setText( tr( "Predefined time" ) );
    QWhatsThis::add(  predefinedBut, tr( "Select this entry if you want the transient recorder to be started at a predefined time." ) );
    Layout24->addWidget( predefinedBut );
    QSpacerItem* spacer_4 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout24->addItem( spacer_4 );
    ButtonGroup32Layout->addLayout( Layout24 );

    Layout8 = new QHBoxLayout; 
    Layout8->setSpacing( 5 );
    Layout8->setMargin( 0 );

    Layout7 = new QHBoxLayout; 
    Layout7->setSpacing( 6 );
    Layout7->setMargin( 0 );

    TextLabel5 = new QLabel( ButtonGroup32, "TextLabel5" );
    TextLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, TextLabel5->sizePolicy().hasHeightForWidth() ) );
    TextLabel5->setMinimumSize( QSize( 20, 0 ) );
    Layout7->addWidget( TextLabel5 );

    Layout6 = new QHBoxLayout; 
    Layout6->setSpacing( 6 );
    Layout6->setMargin( 0 );

    hour = new QSpinBox( ButtonGroup32, "hour" );
    hour->setEnabled( FALSE );
    hour->setWrapping( TRUE );
    hour->setMaxValue( 23 );
    QWhatsThis::add(  hour, tr( "Hour of start time." ) );
    Layout6->addWidget( hour );

    TextLabel3 = new QLabel( ButtonGroup32, "TextLabel3" );
    TextLabel3->setEnabled( FALSE );
    QFont TextLabel3_font(  TextLabel3->font() );
    TextLabel3_font.setBold( TRUE );
    TextLabel3->setFont( TextLabel3_font ); 
    TextLabel3->setText( tr( ":" ) );
    TextLabel3->setAlignment( int( QLabel::AlignCenter ) );
    Layout6->addWidget( TextLabel3 );

    minute = new QSpinBox( ButtonGroup32, "minute" );
    minute->setEnabled( FALSE );
    minute->setWrapping( TRUE );
    minute->setMaxValue( 59 );
    QWhatsThis::add(  minute, tr( "Minutes of start time." ) );
    Layout6->addWidget( minute );

    TextLabel4 = new QLabel( ButtonGroup32, "TextLabel4" );
    TextLabel4->setEnabled( FALSE );
    QFont TextLabel4_font(  TextLabel4->font() );
    TextLabel4_font.setBold( TRUE );
    TextLabel4->setFont( TextLabel4_font ); 
    TextLabel4->setText( tr( ":" ) );
    TextLabel4->setAlignment( int( QLabel::AlignCenter ) );
    Layout6->addWidget( TextLabel4 );

    second = new QSpinBox( ButtonGroup32, "second" );
    second->setEnabled( FALSE );
    second->setWrapping( TRUE );
    second->setMaxValue( 59 );
    QWhatsThis::add(  second, tr( "Seconds of start time." ) );
    Layout6->addWidget( second );
    Layout7->addLayout( Layout6 );
    Layout8->addLayout( Layout7 );
    QSpacerItem* spacer_5 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout8->addItem( spacer_5 );
    ButtonGroup32Layout->addLayout( Layout8 );

    Layout25 = new QHBoxLayout; 
    Layout25->setSpacing( 5 );
    Layout25->setMargin( 0 );

    triggerBut = new QRadioButton( ButtonGroup32, "triggerBut" );
    triggerBut->setText( tr( "Trigger" ) );
    QWhatsThis::add(  triggerBut, tr( "Select this entry if you want to automatically trigger the sampling. <p>\nYou have two choices:\n<ul>\n<li><b>Raising edge:</b> Sampling is started when the measured value gets bigger than the given threshold.</li>\n<li><b>Falling edge:</b> Sampling is started when the measured value gets lower than the given threshold.</li>\n</ul>" ) );
    Layout25->addWidget( triggerBut );
    QSpacerItem* spacer_6 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout25->addItem( spacer_6 );
    ButtonGroup32Layout->addLayout( Layout25 );
    GroupBox1Layout->addWidget( ButtonGroup32 );

    ButtonGroup13 = new QButtonGroup( GroupBox1, "ButtonGroup13" );
    ButtonGroup13->setFrameShape( QButtonGroup::NoFrame );
    ButtonGroup13->setTitle( tr( "" ) );
    ButtonGroup13->setExclusive( FALSE );
    ButtonGroup13->setColumnLayout(0, Qt::Vertical );
    ButtonGroup13->layout()->setSpacing( 0 );
    ButtonGroup13->layout()->setMargin( 0 );
    ButtonGroup13Layout = new QVBoxLayout( ButtonGroup13->layout() );
    ButtonGroup13Layout->setAlignment( Qt::AlignTop );
    ButtonGroup13Layout->setSpacing( 0 );
    ButtonGroup13Layout->setMargin( 0 );

    Layout14 = new QGridLayout; 
    Layout14->setSpacing( 5 );
    Layout14->setMargin( 0 );
    QSpacerItem* spacer_7 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout14->addItem( spacer_7, 0, 3 );

    fallingThresholdEdit = new QLineEdit( ButtonGroup13, "fallingThresholdEdit" );
    fallingThresholdEdit->setEnabled( FALSE );
    fallingThresholdEdit->setMaximumSize( QSize( 80, 32767 ) );
    fallingThresholdEdit->setText( tr( "0.0" ) );
    QWhatsThis::add(  fallingThresholdEdit, tr( "Threshold for falling edge." ) );

    Layout14->addWidget( fallingThresholdEdit, 1, 2 );
    QSpacerItem* spacer_8 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout14->addItem( spacer_8, 1, 3 );

    raisingThresholdEdit = new QLineEdit( ButtonGroup13, "raisingThresholdEdit" );
    raisingThresholdEdit->setEnabled( FALSE );
    raisingThresholdEdit->setMaximumSize( QSize( 80, 32767 ) );
    raisingThresholdEdit->setText( tr( "0.0" ) );
    QWhatsThis::add(  raisingThresholdEdit, tr( "Threshold for raising edge." ) );

    Layout14->addWidget( raisingThresholdEdit, 0, 2 );

    TextLabel7 = new QLabel( ButtonGroup13, "TextLabel7" );
    TextLabel7->setEnabled( FALSE );
    TextLabel7->setText( tr( "Threshold:" ) );

    Layout14->addWidget( TextLabel7, 0, 1 );

    TextLabel8 = new QLabel( ButtonGroup13, "TextLabel8" );
    TextLabel8->setEnabled( FALSE );
    TextLabel8->setText( tr( "Threshold:" ) );

    Layout14->addWidget( TextLabel8, 1, 1 );

    Layout9 = new QHBoxLayout; 
    Layout9->setSpacing( 5 );
    Layout9->setMargin( 0 );

    TextLabel6 = new QLabel( ButtonGroup13, "TextLabel6" );
    TextLabel6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, TextLabel6->sizePolicy().hasHeightForWidth() ) );
    TextLabel6->setMinimumSize( QSize( 20, 0 ) );
    Layout9->addWidget( TextLabel6 );

    raisingBut = new QRadioButton( ButtonGroup13, "raisingBut" );
    raisingBut->setEnabled( FALSE );
    raisingBut->setText( tr( "Raising edge" ) );
    raisingBut->setChecked( TRUE );
    QWhatsThis::add(  raisingBut, tr( "Trigger sampling on raising edge." ) );
    Layout9->addWidget( raisingBut );

    Layout14->addLayout( Layout9, 0, 0 );

    Layout10 = new QHBoxLayout; 
    Layout10->setSpacing( 5 );
    Layout10->setMargin( 0 );

    TextLabel6_2 = new QLabel( ButtonGroup13, "TextLabel6_2" );
    TextLabel6_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, TextLabel6_2->sizePolicy().hasHeightForWidth() ) );
    TextLabel6_2->setMinimumSize( QSize( 20, 0 ) );
    Layout10->addWidget( TextLabel6_2 );

    fallingBut = new QRadioButton( ButtonGroup13, "fallingBut" );
    fallingBut->setEnabled( FALSE );
    fallingBut->setText( tr( "Falling edge" ) );
    QWhatsThis::add(  fallingBut, tr( "Trigger sampling on falling edge." ) );
    Layout10->addWidget( fallingBut );

    Layout14->addLayout( Layout10, 1, 0 );
    ButtonGroup13Layout->addLayout( Layout14 );
    GroupBox1Layout->addWidget( ButtonGroup13 );
    samplePageLayout->addWidget( GroupBox1 );
    QSpacerItem* spacer_9 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    samplePageLayout->addItem( spacer_9 );
    tabWidget->insertTab( samplePage, tr( "Recorder" ) );

    scalePage = new QWidget( tabWidget, "scalePage" );
    scalePageLayout = new QVBoxLayout( scalePage ); 
    scalePageLayout->setSpacing( 5 );
    scalePageLayout->setMargin( 10 );

    ButtonGroup36 = new QButtonGroup( scalePage, "ButtonGroup36" );
    ButtonGroup36->setTitle( tr( "Scale" ) );
    ButtonGroup36->setColumnLayout(0, Qt::Vertical );
    ButtonGroup36->layout()->setSpacing( 0 );
    ButtonGroup36->layout()->setMargin( 0 );
    ButtonGroup36Layout = new QVBoxLayout( ButtonGroup36->layout() );
    ButtonGroup36Layout->setAlignment( Qt::AlignTop );
    ButtonGroup36Layout->setSpacing( 5 );
    ButtonGroup36Layout->setMargin( 10 );

    autoScaleBut = new QRadioButton( ButtonGroup36, "autoScaleBut" );
    autoScaleBut->setText( tr( "Automatic" ) );
    autoScaleBut->setChecked( TRUE );
    QWhatsThis::add(  autoScaleBut, tr( "Select this entry if you want automatic scaling of the vertical scale in the transient recorder." ) );
    ButtonGroup36Layout->addWidget( autoScaleBut );

    manualScaleBut = new QRadioButton( ButtonGroup36, "manualScaleBut" );
    manualScaleBut->setText( tr( "Manual" ) );
    QWhatsThis::add(  manualScaleBut, tr( "Select this entry if you want to set the minimum and maximum value for the scale manually. If selected enter the minimum and maximum values below." ) );
    ButtonGroup36Layout->addWidget( manualScaleBut );

    Layout15_2 = new QHBoxLayout; 
    Layout15_2->setSpacing( 5 );
    Layout15_2->setMargin( 0 );

    TextLabel9 = new QLabel( ButtonGroup36, "TextLabel9" );
    TextLabel9->setMinimumSize( QSize( 20, 0 ) );
    Layout15_2->addWidget( TextLabel9 );

    TextLabel10 = new QLabel( ButtonGroup36, "TextLabel10" );
    TextLabel10->setEnabled( FALSE );
    TextLabel10->setText( tr( "Minimum:" ) );
    Layout15_2->addWidget( TextLabel10 );

    scaleMinEd = new QLineEdit( ButtonGroup36, "scaleMinEd" );
    scaleMinEd->setEnabled( FALSE );
    scaleMinEd->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, scaleMinEd->sizePolicy().hasHeightForWidth() ) );
    scaleMinEd->setMinimumSize( QSize( 60, 0 ) );
    scaleMinEd->setMaximumSize( QSize( 60, 32767 ) );
    scaleMinEd->setText( tr( "-3.999" ) );
    scaleMinEd->setMaxLength( 9 );
    QWhatsThis::add(  scaleMinEd, tr( "Enter the minimum scale value here." ) );
    Layout15_2->addWidget( scaleMinEd );

    TextLabel10_2 = new QLabel( ButtonGroup36, "TextLabel10_2" );
    TextLabel10_2->setEnabled( FALSE );
    TextLabel10_2->setText( tr( "Maximum:" ) );
    Layout15_2->addWidget( TextLabel10_2 );

    scaleMaxEd = new QLineEdit( ButtonGroup36, "scaleMaxEd" );
    scaleMaxEd->setEnabled( FALSE );
    scaleMaxEd->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, scaleMaxEd->sizePolicy().hasHeightForWidth() ) );
    scaleMaxEd->setMinimumSize( QSize( 60, 0 ) );
    scaleMaxEd->setMaximumSize( QSize( 60, 32767 ) );
    scaleMaxEd->setText( tr( "3.999" ) );
    scaleMaxEd->setMaxLength( 9 );
    QWhatsThis::add(  scaleMaxEd, tr( "Enter the maximum scale value here." ) );
    Layout15_2->addWidget( scaleMaxEd );
    QSpacerItem* spacer_10 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout15_2->addItem( spacer_10 );
    ButtonGroup36Layout->addLayout( Layout15_2 );
    scalePageLayout->addWidget( ButtonGroup36 );

    ButtonGroup37 = new QButtonGroup( scalePage, "ButtonGroup37" );
    ButtonGroup37->setTitle( tr( "Window" ) );
    ButtonGroup37->setColumnLayout(0, Qt::Vertical );
    ButtonGroup37->layout()->setSpacing( 0 );
    ButtonGroup37->layout()->setMargin( 0 );
    ButtonGroup37Layout = new QGridLayout( ButtonGroup37->layout() );
    ButtonGroup37Layout->setAlignment( Qt::AlignTop );
    ButtonGroup37Layout->setSpacing( 5 );
    ButtonGroup37Layout->setMargin( 10 );

    TextLabel11 = new QLabel( ButtonGroup37, "TextLabel11" );
    TextLabel11->setText( tr( "Size:" ) );

    ButtonGroup37Layout->addWidget( TextLabel11, 0, 0 );

    TextLabel12 = new QLabel( ButtonGroup37, "TextLabel12" );
    TextLabel12->setText( tr( "Max. length:" ) );

    ButtonGroup37Layout->addWidget( TextLabel12, 1, 0 );
    QSpacerItem* spacer_11 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ButtonGroup37Layout->addItem( spacer_11, 0, 3 );

    sizeUnit = new QComboBox( FALSE, ButtonGroup37, "sizeUnit" );
    sizeUnit->insertItem( tr( "Seconds" ) );
    sizeUnit->insertItem( tr( "Minutes" ) );
    sizeUnit->insertItem( tr( "Hours" ) );
    sizeUnit->insertItem( tr( "Days" ) );

    ButtonGroup37Layout->addWidget( sizeUnit, 0, 2 );

    winSize = new QLineEdit( ButtonGroup37, "winSize" );
    winSize->setMinimumSize( QSize( 60, 0 ) );
    winSize->setMaximumSize( QSize( 60, 32767 ) );
    winSize->setText( tr( "600" ) );
    winSize->setMaxLength( 10 );
    QWhatsThis::add(  winSize, tr( "Enter the size (length in time) of the visual part of the transient recorder here. Choose the unit to the right." ) );

    ButtonGroup37Layout->addWidget( winSize, 0, 1 );

    winLength = new QLineEdit( ButtonGroup37, "winLength" );
    winLength->setMinimumSize( QSize( 60, 0 ) );
    winLength->setMaximumSize( QSize( 60, 32767 ) );
    winLength->setText( tr( "3600" ) );
    winLength->setMaxLength( 10 );
    QWhatsThis::add(  winLength, tr( "Maximum time for sampling. If this value is reached sampling is not stopped but the first values are discarded." ) );

    ButtonGroup37Layout->addWidget( winLength, 1, 1 );

    lengthUnit = new QComboBox( FALSE, ButtonGroup37, "lengthUnit" );
    lengthUnit->insertItem( tr( "Seconds" ) );
    lengthUnit->insertItem( tr( "Minutes" ) );
    lengthUnit->insertItem( tr( "Hours" ) );
    lengthUnit->insertItem( tr( "Days" ) );

    ButtonGroup37Layout->addWidget( lengthUnit, 1, 2 );
    scalePageLayout->addWidget( ButtonGroup37 );
    QSpacerItem* spacer_12 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    scalePageLayout->addItem( spacer_12 );
    tabWidget->insertTab( scalePage, tr( "Scale" ) );

    dmmPage = new QWidget( tabWidget, "dmmPage" );
    dmmPageLayout = new QVBoxLayout( dmmPage ); 
    dmmPageLayout->setSpacing( 5 );
    dmmPageLayout->setMargin( 10 );

    TextLabel1_2 = new QLabel( dmmPage, "TextLabel1_2" );
    TextLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, TextLabel1_2->sizePolicy().hasHeightForWidth() ) );
    QFont TextLabel1_2_font(  TextLabel1_2->font() );
    TextLabel1_2_font.setBold( TRUE );
    TextLabel1_2->setFont( TextLabel1_2_font ); 
    TextLabel1_2->setText( tr( "Select yor DMM or set parameter manually" ) );
    dmmPageLayout->addWidget( TextLabel1_2 );

    modelCombo = new QComboBox( FALSE, dmmPage, "modelCombo" );
    modelCombo->insertItem( tr( "Manual settings" ) );
    modelCombo->insertItem( tr( "Metex/Voltcraft ME-32" ) );
    modelCombo->insertItem( tr( "PeakTech-451" ) );
    modelCombo->setSizeLimit( 25 );
    modelCombo->setAutoCompletion( TRUE );
    dmmPageLayout->addWidget( modelCombo );

    ButtonGroup11 = new QButtonGroup( dmmPage, "ButtonGroup11" );
    ButtonGroup11->setTitle( tr( "Port settings" ) );
    ButtonGroup11->setColumnLayout(0, Qt::Vertical );
    ButtonGroup11->layout()->setSpacing( 0 );
    ButtonGroup11->layout()->setMargin( 0 );
    ButtonGroup11Layout = new QGridLayout( ButtonGroup11->layout() );
    ButtonGroup11Layout->setAlignment( Qt::AlignTop );
    ButtonGroup11Layout->setSpacing( 5 );
    ButtonGroup11Layout->setMargin( 10 );

    TextLabel1_3 = new QLabel( ButtonGroup11, "TextLabel1_3" );
    TextLabel1_3->setText( tr( "Bits:" ) );
    TextLabel1_3->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup11Layout->addWidget( TextLabel1_3, 1, 0 );

    bitsCombo = new QComboBox( FALSE, ButtonGroup11, "bitsCombo" );
    bitsCombo->insertItem( tr( "5 bits" ) );
    bitsCombo->insertItem( tr( "6 bits" ) );
    bitsCombo->insertItem( tr( "7 bits" ) );
    bitsCombo->insertItem( tr( "8 bits" ) );

    ButtonGroup11Layout->addWidget( bitsCombo, 1, 1 );

    TextLabel2_2 = new QLabel( ButtonGroup11, "TextLabel2_2" );
    TextLabel2_2->setText( tr( "Stop bits:" ) );
    TextLabel2_2->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup11Layout->addWidget( TextLabel2_2, 1, 2 );

    baudRate = new QComboBox( FALSE, ButtonGroup11, "baudRate" );
    baudRate->insertItem( tr( "600 baud" ) );
    baudRate->insertItem( tr( "1200 baud" ) );
    baudRate->insertItem( tr( "1800 baud" ) );
    baudRate->insertItem( tr( "2400 baud" ) );
    baudRate->insertItem( tr( "4800 baud" ) );
    baudRate->insertItem( tr( "9600 baud" ) );
    baudRate->setCurrentItem( 0 );
    QWhatsThis::add(  baudRate, tr( "Select the baud rate for the DMM here. If you encounter problems connecting to your DMM try lowering the baud rate. I had some problems with my <b>Metex ME-32</b>. The Documentation said 1200 baud but it only worked at 600." ) );

    ButtonGroup11Layout->addWidget( baudRate, 0, 3 );

    TextLabel1 = new QLabel( ButtonGroup11, "TextLabel1" );
    TextLabel1->setText( tr( "Baud rate:" ) );
    TextLabel1->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup11Layout->addWidget( TextLabel1, 0, 2 );

    port = new QComboBox( FALSE, ButtonGroup11, "port" );
    port->insertItem( tr( "/dev/ttyS0" ) );
    port->insertItem( tr( "/dev/ttyS1" ) );
    port->insertItem( tr( "/dev/ttyS2" ) );
    port->insertItem( tr( "/dev/ttyS3" ) );
    port->insertItem( tr( "/dev/modem" ) );
    port->setCurrentItem( 0 );
    QWhatsThis::add(  port, tr( "Choose the serial device here. <i>(Hint for DOS people: /dev/ttyS0 corresponds to COM1. /dev/ttyS1 to COM2 ...)</i>" ) );

    ButtonGroup11Layout->addWidget( port, 0, 1 );

    TextLabel2 = new QLabel( ButtonGroup11, "TextLabel2" );
    TextLabel2->setText( tr( "Port:" ) );
    TextLabel2->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup11Layout->addWidget( TextLabel2, 0, 0 );

    stopBitsCombo = new QComboBox( FALSE, ButtonGroup11, "stopBitsCombo" );
    stopBitsCombo->insertItem( tr( "1 Stop bit" ) );
    stopBitsCombo->insertItem( tr( "2 Stop bits" ) );

    ButtonGroup11Layout->addWidget( stopBitsCombo, 1, 3 );
    dmmPageLayout->addWidget( ButtonGroup11 );

    ButtonGroup7 = new QButtonGroup( dmmPage, "ButtonGroup7" );
    ButtonGroup7->setTitle( tr( "Protocol" ) );
    ButtonGroup7->setColumnLayout(0, Qt::Vertical );
    ButtonGroup7->layout()->setSpacing( 0 );
    ButtonGroup7->layout()->setMargin( 0 );
    ButtonGroup7Layout = new QGridLayout( ButtonGroup7->layout() );
    ButtonGroup7Layout->setAlignment( Qt::AlignTop );
    ButtonGroup7Layout->setSpacing( 5 );
    ButtonGroup7Layout->setMargin( 10 );

    protocolCombo = new QComboBox( FALSE, ButtonGroup7, "protocolCombo" );
    protocolCombo->insertItem( tr( "14 bytes, polling (Metex/Voltcraft)" ) );
    protocolCombo->insertItem( tr( "10 bytes, continuous (PeakTech 451)" ) );
    QWhatsThis::add(  protocolCombo, tr( "Here you may select the DMM type. Currently you can select between <b>Metex/Voltcraft</b> and a <b>PeakTech-451</b>. Selecting <b>Metex/Voltcraft</b> it should run with all DMM's of this brand wich are compatible with their 14 byte protocol.<p>The PeakTech setting was only tested with this model." ) );

    ButtonGroup7Layout->addMultiCellWidget( protocolCombo, 0, 0, 0, 2 );

    TextLabel1_4 = new QLabel( ButtonGroup7, "TextLabel1_4" );
    TextLabel1_4->setText( tr( "Ignore lines:" ) );

    ButtonGroup7Layout->addWidget( TextLabel1_4, 1, 0 );

    ignoreSpin = new QSpinBox( ButtonGroup7, "ignoreSpin" );
    ignoreSpin->setMaxValue( 10 );

    ButtonGroup7Layout->addWidget( ignoreSpin, 1, 1 );
    QSpacerItem* spacer_13 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ButtonGroup7Layout->addItem( spacer_13, 1, 2 );
    dmmPageLayout->addWidget( ButtonGroup7 );
    QSpacerItem* spacer_14 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    dmmPageLayout->addItem( spacer_14 );

    message = new QLabel( dmmPage, "message" );
    message->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)3, message->sizePolicy().hasHeightForWidth() ) );
    message->setText( tr( "If you have a DMM not listed above and find manual settings that work, please report to <u>qtdmm@mtoussaint.de</u>. This way future users of this DMM can benefit from your help." ) );
    message->setAlignment( int( QLabel::AlignBottom | QLabel::AlignLeft ) );
    dmmPageLayout->addWidget( message );
    tabWidget->insertTab( dmmPage, tr( "DMM" ) );

    copyTab = new QWidget( tabWidget, "copyTab" );
    copyTabLayout = new QGridLayout( copyTab ); 
    copyTabLayout->setSpacing( 5 );
    copyTabLayout->setMargin( 10 );

    TextView1 = new QTextView( copyTab, "TextView1" );
    TextView1->setText( tr( "<center><h1>QtDMM</h1>\nA simple display software for <b>Metex</b> and compatible hand held digital multimeter including min/max memory and a configurable recorder with export and printing function.<p>\n&copy; 2001 Matthias Toussaint<br><font color=blue>&lt;qtdmm@mtoussaint.de&gt;</font><p>\n<b>QtDMM</b> uses the platform independent toolkit <b>Qt</b> from Trolltech AS Norway <font color=blue>&lt;www.trolltech.com&gt;</font> and is licensed under <b>GPL</b>." ) );
    QWhatsThis::add(  TextView1, tr( "Just some blurb." ) );

    copyTabLayout->addWidget( TextView1, 0, 0 );
    tabWidget->insertTab( copyTab, tr( "Copyright" ) );

    UIConfigDlgLayout->addWidget( tabWidget, 0, 0 );

    // signals and slots connections
    connect( okBut, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( cancelBut, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( predefinedBut, SIGNAL( toggled(bool) ), hour, SLOT( setEnabled(bool) ) );
    connect( predefinedBut, SIGNAL( toggled(bool) ), TextLabel3, SLOT( setEnabled(bool) ) );
    connect( predefinedBut, SIGNAL( toggled(bool) ), minute, SLOT( setEnabled(bool) ) );
    connect( predefinedBut, SIGNAL( toggled(bool) ), TextLabel4, SLOT( setEnabled(bool) ) );
    connect( predefinedBut, SIGNAL( toggled(bool) ), second, SLOT( setEnabled(bool) ) );
    connect( triggerBut, SIGNAL( toggled(bool) ), raisingBut, SLOT( setEnabled(bool) ) );
    connect( triggerBut, SIGNAL( toggled(bool) ), fallingBut, SLOT( setEnabled(bool) ) );
    connect( triggerBut, SIGNAL( toggled(bool) ), TextLabel7, SLOT( setEnabled(bool) ) );
    connect( triggerBut, SIGNAL( toggled(bool) ), TextLabel8, SLOT( setEnabled(bool) ) );
    connect( triggerBut, SIGNAL( toggled(bool) ), raisingThresholdEdit, SLOT( setEnabled(bool) ) );
    connect( triggerBut, SIGNAL( toggled(bool) ), fallingThresholdEdit, SLOT( setEnabled(bool) ) );
    connect( manualScaleBut, SIGNAL( toggled(bool) ), scaleMinEd, SLOT( setEnabled(bool) ) );
    connect( manualScaleBut, SIGNAL( toggled(bool) ), TextLabel10, SLOT( setEnabled(bool) ) );
    connect( manualScaleBut, SIGNAL( toggled(bool) ), TextLabel10_2, SLOT( setEnabled(bool) ) );
    connect( manualScaleBut, SIGNAL( toggled(bool) ), scaleMaxEd, SLOT( setEnabled(bool) ) );

    // tab order
    setTabOrder( sampleEvery, sampleUnit );
    setTabOrder( sampleUnit, sampleTime );
    setTabOrder( sampleTime, timeUnit );
    setTabOrder( timeUnit, manualBut );
    setTabOrder( manualBut, predefinedBut );
    setTabOrder( predefinedBut, hour );
    setTabOrder( hour, minute );
    setTabOrder( minute, second );
    setTabOrder( second, triggerBut );
    setTabOrder( triggerBut, raisingBut );
    setTabOrder( raisingBut, raisingThresholdEdit );
    setTabOrder( raisingThresholdEdit, fallingBut );
    setTabOrder( fallingBut, fallingThresholdEdit );
    setTabOrder( fallingThresholdEdit, autoScaleBut );
    setTabOrder( autoScaleBut, manualScaleBut );
    setTabOrder( manualScaleBut, scaleMinEd );
    setTabOrder( scaleMinEd, scaleMaxEd );
    setTabOrder( scaleMaxEd, winSize );
    setTabOrder( winSize, sizeUnit );
    setTabOrder( sizeUnit, winLength );
    setTabOrder( winLength, lengthUnit );
    setTabOrder( lengthUnit, baudRate );
    setTabOrder( baudRate, port );
    setTabOrder( port, helpBut );
    setTabOrder( helpBut, okBut );
    setTabOrder( okBut, cancelBut );
    setTabOrder( cancelBut, tabWidget );
    setTabOrder( tabWidget, TextView1 );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
UIConfigDlg::~UIConfigDlg()
{
    // no need to delete child widgets, Qt does it all for us
}

/*  
 *  Main event handler. Reimplemented to handle application
 *  font changes
 */
bool UIConfigDlg::event( QEvent* ev )
{
    bool ret = QDialog::event( ev ); 
    if ( ev->type() == QEvent::ApplicationFontChange ) {
	QFont TextLabel3_font(  TextLabel3->font() );
	TextLabel3_font.setBold( TRUE );
	TextLabel3->setFont( TextLabel3_font ); 
	QFont TextLabel4_font(  TextLabel4->font() );
	TextLabel4_font.setBold( TRUE );
	TextLabel4->setFont( TextLabel4_font ); 
	QFont TextLabel1_2_font(  TextLabel1_2->font() );
	TextLabel1_2_font.setBold( TRUE );
	TextLabel1_2->setFont( TextLabel1_2_font ); 
    }
    return ret;
}

