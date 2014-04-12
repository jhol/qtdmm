/****************************************************************************
** Form implementation generated from reading ui file 'uiconfigdlg.ui'
**
** Created: Sun Sep 2 19:18:58 2001
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "uiconfigdlg.h"

#include <qbuttongroup.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qspinbox.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include "colorbutton.h"
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
    QPixmap image1( ( const char** ) image1_data );
    if ( !name )
	setName( "UIConfigDlg" );
    resize( 391, 443 ); 
    setCaption( tr( "QtDMM: Configuration" ) );
    setIcon( image0 );
    setIconText( tr( "Configuration" ) );
    setSizeGripEnabled( TRUE );
    UIConfigDlgLayout = new QVBoxLayout( this ); 
    UIConfigDlgLayout->setSpacing( 5 );
    UIConfigDlgLayout->setMargin( 10 );

    tabWidget = new QTabWidget( this, "tabWidget" );

    recorderPage = new QWidget( tabWidget, "recorderPage" );
    recorderPageLayout = new QVBoxLayout( recorderPage ); 
    recorderPageLayout->setSpacing( 5 );
    recorderPageLayout->setMargin( 10 );

    ButtonGroup1 = new QButtonGroup( recorderPage, "ButtonGroup1" );
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
    sampLabel->setText( tr( "Sample &every:" ) );

    ButtonGroup1Layout->addWidget( sampLabel, 0, 0 );

    sampleUnit = new QComboBox( FALSE, ButtonGroup1, "sampleUnit" );
    sampleUnit->insertItem( tr( "Seconds" ) );
    sampleUnit->insertItem( tr( "Minutes" ) );
    sampleUnit->insertItem( tr( "Hours" ) );
    sampleUnit->insertItem( tr( "Days" ) );

    ButtonGroup1Layout->addWidget( sampleUnit, 0, 2 );
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ButtonGroup1Layout->addItem( spacer, 0, 3 );

    sampLabel_2 = new QLabel( ButtonGroup1, "sampLabel_2" );
    sampLabel_2->setText( tr( "Sample t&ime:" ) );

    ButtonGroup1Layout->addWidget( sampLabel_2, 1, 0 );

    timeUnit = new QComboBox( FALSE, ButtonGroup1, "timeUnit" );
    timeUnit->insertItem( tr( "Seconds" ) );
    timeUnit->insertItem( tr( "Minutes" ) );
    timeUnit->insertItem( tr( "Hours" ) );
    timeUnit->insertItem( tr( "Days" ) );

    ButtonGroup1Layout->addWidget( timeUnit, 1, 2 );

    sampleEvery = new QSpinBox( ButtonGroup1, "sampleEvery" );
    sampleEvery->setMaxValue( 99999 );
    sampleEvery->setMinValue( 1 );
    sampleEvery->setValue( 1 );

    ButtonGroup1Layout->addWidget( sampleEvery, 0, 1 );

    sampleTime = new QSpinBox( ButtonGroup1, "sampleTime" );
    sampleTime->setMaxValue( 99999 );
    sampleTime->setMinValue( 1 );
    sampleTime->setValue( 500 );

    ButtonGroup1Layout->addWidget( sampleTime, 1, 1 );
    recorderPageLayout->addWidget( ButtonGroup1 );

    GroupBox1 = new QGroupBox( recorderPage, "GroupBox1" );
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
    manualBut->setText( tr( "&Manual" ) );
    manualBut->setChecked( TRUE );
    QWhatsThis::add(  manualBut, tr( "Select this entry if you want to manually start the transient recorder. Use the <b>Start</b> and <b>Stop</b> buttons in the main window to start/stop sampling." ) );
    Layout23->addWidget( manualBut );
    QSpacerItem* spacer_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout23->addItem( spacer_2 );
    ButtonGroup32Layout->addLayout( Layout23 );

    Layout24 = new QHBoxLayout; 
    Layout24->setSpacing( 5 );
    Layout24->setMargin( 0 );

    predefinedBut = new QRadioButton( ButtonGroup32, "predefinedBut" );
    predefinedBut->setText( tr( "&Predefined time" ) );
    QWhatsThis::add(  predefinedBut, tr( "Select this entry if you want the transient recorder to be started at a predefined time." ) );
    Layout24->addWidget( predefinedBut );
    QSpacerItem* spacer_3 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout24->addItem( spacer_3 );
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
    QSpacerItem* spacer_4 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout8->addItem( spacer_4 );
    ButtonGroup32Layout->addLayout( Layout8 );

    Layout25 = new QHBoxLayout; 
    Layout25->setSpacing( 5 );
    Layout25->setMargin( 0 );

    triggerBut = new QRadioButton( ButtonGroup32, "triggerBut" );
    triggerBut->setText( tr( "&Trigger" ) );
    QWhatsThis::add(  triggerBut, tr( "Select this entry if you want to automatically trigger the sampling. <p>\nYou have two choices:\n<ul>\n<li><b>Raising edge:</b> Sampling is started when the measured value gets bigger than the given threshold.</li>\n<li><b>Falling edge:</b> Sampling is started when the measured value gets lower than the given threshold.</li>\n</ul>" ) );
    Layout25->addWidget( triggerBut );
    QSpacerItem* spacer_5 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout25->addItem( spacer_5 );
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
    QSpacerItem* spacer_6 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout14->addItem( spacer_6, 0, 3 );

    fallingThresholdEdit = new QLineEdit( ButtonGroup13, "fallingThresholdEdit" );
    fallingThresholdEdit->setEnabled( FALSE );
    fallingThresholdEdit->setMaximumSize( QSize( 80, 32767 ) );
    fallingThresholdEdit->setText( tr( "0.0" ) );
    QWhatsThis::add(  fallingThresholdEdit, tr( "Threshold for falling edge." ) );

    Layout14->addWidget( fallingThresholdEdit, 1, 2 );
    QSpacerItem* spacer_7 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout14->addItem( spacer_7, 1, 3 );

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
    raisingBut->setText( tr( "&Raising edge" ) );
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
    fallingBut->setText( tr( "&Falling edge" ) );
    QWhatsThis::add(  fallingBut, tr( "Trigger sampling on falling edge." ) );
    Layout10->addWidget( fallingBut );

    Layout14->addLayout( Layout10, 1, 0 );
    ButtonGroup13Layout->addLayout( Layout14 );
    GroupBox1Layout->addWidget( ButtonGroup13 );
    recorderPageLayout->addWidget( GroupBox1 );
    QSpacerItem* spacer_8 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    recorderPageLayout->addItem( spacer_8 );

    Layout52 = new QHBoxLayout; 
    Layout52->setSpacing( 5 );
    Layout52->setMargin( 0 );

    ui_defaultRecorder = new QPushButton( recorderPage, "ui_defaultRecorder" );
    ui_defaultRecorder->setText( tr( "&Undo" ) );
    ui_defaultRecorder->setAccel( 276824149 );
    ui_defaultRecorder->setAutoDefault( FALSE );
    QWhatsThis::add(  ui_defaultRecorder, tr( "Return to the previously saved settings for this page." ) );
    Layout52->addWidget( ui_defaultRecorder );
    QSpacerItem* spacer_9 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout52->addItem( spacer_9 );

    ui_factoryRecorder = new QPushButton( recorderPage, "ui_factoryRecorder" );
    ui_factoryRecorder->setText( tr( "Factory defaults" ) );
    ui_factoryRecorder->setAutoDefault( FALSE );
    QWhatsThis::add(  ui_factoryRecorder, tr( "Return this page to the built in values." ) );
    Layout52->addWidget( ui_factoryRecorder );
    recorderPageLayout->addLayout( Layout52 );
    tabWidget->insertTab( recorderPage, tr( "Recorder" ) );

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
    autoScaleBut->setText( tr( "&Automatic" ) );
    autoScaleBut->setChecked( TRUE );
    QWhatsThis::add(  autoScaleBut, tr( "Select this entry if you want automatic scaling of the vertical scale in the transient recorder." ) );
    ButtonGroup36Layout->addWidget( autoScaleBut );

    manualScaleBut = new QRadioButton( ButtonGroup36, "manualScaleBut" );
    manualScaleBut->setText( tr( "&Manual" ) );
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
    TextLabel10->setText( tr( "M&inimum:" ) );
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
    TextLabel10_2->setText( tr( "Ma&ximum:" ) );
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
    TextLabel11->setText( tr( "&Size:" ) );

    ButtonGroup37Layout->addWidget( TextLabel11, 0, 0 );

    TextLabel12 = new QLabel( ButtonGroup37, "TextLabel12" );
    TextLabel12->setText( tr( "Max. &length:" ) );

    ButtonGroup37Layout->addWidget( TextLabel12, 1, 0 );
    QSpacerItem* spacer_11 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ButtonGroup37Layout->addItem( spacer_11, 0, 3 );

    sizeUnit = new QComboBox( FALSE, ButtonGroup37, "sizeUnit" );
    sizeUnit->insertItem( tr( "Seconds" ) );
    sizeUnit->insertItem( tr( "Minutes" ) );
    sizeUnit->insertItem( tr( "Hours" ) );
    sizeUnit->insertItem( tr( "Days" ) );

    ButtonGroup37Layout->addWidget( sizeUnit, 0, 2 );

    lengthUnit = new QComboBox( FALSE, ButtonGroup37, "lengthUnit" );
    lengthUnit->insertItem( tr( "Seconds" ) );
    lengthUnit->insertItem( tr( "Minutes" ) );
    lengthUnit->insertItem( tr( "Hours" ) );
    lengthUnit->insertItem( tr( "Days" ) );

    ButtonGroup37Layout->addWidget( lengthUnit, 1, 2 );

    winSize = new QSpinBox( ButtonGroup37, "winSize" );
    winSize->setMaxValue( 99999 );
    winSize->setMinValue( 1 );
    winSize->setValue( 600 );

    ButtonGroup37Layout->addWidget( winSize, 0, 1 );

    winLength = new QSpinBox( ButtonGroup37, "winLength" );
    winLength->setMaxValue( 99999 );
    winLength->setMinValue( 1 );
    winLength->setValue( 3600 );

    ButtonGroup37Layout->addWidget( winLength, 1, 1 );
    scalePageLayout->addWidget( ButtonGroup37 );
    QSpacerItem* spacer_12 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    scalePageLayout->addItem( spacer_12 );

    Layout51 = new QHBoxLayout; 
    Layout51->setSpacing( 5 );
    Layout51->setMargin( 0 );

    ui_defaultScale = new QPushButton( scalePage, "ui_defaultScale" );
    ui_defaultScale->setText( tr( "&Undo" ) );
    ui_defaultScale->setAccel( 276824149 );
    ui_defaultScale->setAutoDefault( FALSE );
    QWhatsThis::add(  ui_defaultScale, tr( "Return to the previously saved settings for this page." ) );
    Layout51->addWidget( ui_defaultScale );
    QSpacerItem* spacer_13 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout51->addItem( spacer_13 );

    ui_factoryScale = new QPushButton( scalePage, "ui_factoryScale" );
    ui_factoryScale->setText( tr( "Factory defaults" ) );
    ui_factoryScale->setAutoDefault( FALSE );
    QWhatsThis::add(  ui_factoryScale, tr( "Return this page to the built in values." ) );
    Layout51->addWidget( ui_factoryScale );
    scalePageLayout->addLayout( Layout51 );
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
    TextLabel1_2->setText( tr( "Select yor &DMM or set parameter manually" ) );
    dmmPageLayout->addWidget( TextLabel1_2 );

    modelCombo = new QComboBox( FALSE, dmmPage, "modelCombo" );
    modelCombo->setSizeLimit( 25 );
    modelCombo->setAutoCompletion( TRUE );
    QWhatsThis::add(  modelCombo, tr( "Here you may select your DMM model. If your DMM is not in the list, try to find working settings and mail them to me (<font color=blue><u>qtdmm@mtoussaint.de</u></font>). So I can add them to the list in the next release." ) );
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

    ui_bitsLabel = new QLabel( ButtonGroup11, "ui_bitsLabel" );
    ui_bitsLabel->setText( tr( "&Bits:" ) );
    ui_bitsLabel->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup11Layout->addWidget( ui_bitsLabel, 1, 0 );

    bitsCombo = new QComboBox( FALSE, ButtonGroup11, "bitsCombo" );
    bitsCombo->insertItem( tr( "5 bits" ) );
    bitsCombo->insertItem( tr( "6 bits" ) );
    bitsCombo->insertItem( tr( "7 bits" ) );
    bitsCombo->insertItem( tr( "8 bits" ) );
    QWhatsThis::add(  bitsCombo, tr( "Number of bits for serial communication." ) );

    ButtonGroup11Layout->addWidget( bitsCombo, 1, 1 );

    ui_stopLabel = new QLabel( ButtonGroup11, "ui_stopLabel" );
    ui_stopLabel->setText( tr( "&Stop bits:" ) );
    ui_stopLabel->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup11Layout->addWidget( ui_stopLabel, 1, 2 );

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

    ui_baudLabel = new QLabel( ButtonGroup11, "ui_baudLabel" );
    ui_baudLabel->setText( tr( "Baud &rate:" ) );
    ui_baudLabel->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup11Layout->addWidget( ui_baudLabel, 0, 2 );

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
    TextLabel2->setText( tr( "&Port:" ) );
    TextLabel2->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    ButtonGroup11Layout->addWidget( TextLabel2, 0, 0 );

    stopBitsCombo = new QComboBox( FALSE, ButtonGroup11, "stopBitsCombo" );
    stopBitsCombo->insertItem( tr( "1 Stop bit" ) );
    stopBitsCombo->insertItem( tr( "2 Stop bits" ) );
    QWhatsThis::add(  stopBitsCombo, tr( "Number of stop bits for serial communication." ) );

    ButtonGroup11Layout->addWidget( stopBitsCombo, 1, 3 );
    dmmPageLayout->addWidget( ButtonGroup11 );

    ui_protocol = new QButtonGroup( dmmPage, "ui_protocol" );
    ui_protocol->setTitle( tr( "Protocol" ) );
    ui_protocol->setColumnLayout(0, Qt::Vertical );
    ui_protocol->layout()->setSpacing( 0 );
    ui_protocol->layout()->setMargin( 0 );
    ui_protocolLayout = new QGridLayout( ui_protocol->layout() );
    ui_protocolLayout->setAlignment( Qt::AlignTop );
    ui_protocolLayout->setSpacing( 5 );
    ui_protocolLayout->setMargin( 10 );

    protocolCombo = new QComboBox( FALSE, ui_protocol, "protocolCombo" );
    protocolCombo->insertItem( tr( "14 bytes, polling (Metex/Voltcraft)" ) );
    protocolCombo->insertItem( tr( "10 bytes, continuous (PeakTech 451)" ) );
    QWhatsThis::add(  protocolCombo, tr( "Here you may select the DMM type. Currently you can select between <b>Metex/Voltcraft</b> and a <b>PeakTech-451</b>. Selecting <b>Metex/Voltcraft</b> it should run with all DMM's of this brand wich are compatible with their 14 byte protocol.<p>The PeakTech setting was only tested with this model." ) );

    ui_protocolLayout->addMultiCellWidget( protocolCombo, 0, 0, 0, 2 );

    TextLabel1_4 = new QLabel( ui_protocol, "TextLabel1_4" );
    TextLabel1_4->setText( tr( "&Ignore lines:" ) );

    ui_protocolLayout->addWidget( TextLabel1_4, 1, 0 );

    ignoreSpin = new QSpinBox( ui_protocol, "ignoreSpin" );
    ignoreSpin->setMaxValue( 10 );
    QWhatsThis::add(  ignoreSpin, tr( "Some multimeter send several lines of data containing different measured values. As QtDMM only shows one variable here you can set the number of lines to be ignored for each measurement (That means that QtDMM only uses the first line)." ) );

    ui_protocolLayout->addWidget( ignoreSpin, 1, 1 );
    QSpacerItem* spacer_14 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ui_protocolLayout->addItem( spacer_14, 1, 2 );
    dmmPageLayout->addWidget( ui_protocol );
    QSpacerItem* spacer_15 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    dmmPageLayout->addItem( spacer_15 );

    message = new QLabel( dmmPage, "message" );
    message->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)3, message->sizePolicy().hasHeightForWidth() ) );
    message->setText( tr( "If you have a DMM not listed above and find manual settings that work, please report to <font color=blue><u>qtdmm@mtoussaint.de</u></font>. This way future users of this DMM can benefit from your help." ) );
    message->setAlignment( int( QLabel::AlignBottom | QLabel::AlignLeft ) );
    dmmPageLayout->addWidget( message );

    Layout50 = new QHBoxLayout; 
    Layout50->setSpacing( 5 );
    Layout50->setMargin( 0 );

    ui_defaultDMM = new QPushButton( dmmPage, "ui_defaultDMM" );
    ui_defaultDMM->setText( tr( "&Undo" ) );
    ui_defaultDMM->setAccel( 276824149 );
    ui_defaultDMM->setAutoDefault( FALSE );
    QWhatsThis::add(  ui_defaultDMM, tr( "Return to the previously saved settings for this page." ) );
    Layout50->addWidget( ui_defaultDMM );
    QSpacerItem* spacer_16 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout50->addItem( spacer_16 );

    ui_factoryDMM = new QPushButton( dmmPage, "ui_factoryDMM" );
    ui_factoryDMM->setText( tr( "Factory defaults" ) );
    ui_factoryDMM->setAutoDefault( FALSE );
    QWhatsThis::add(  ui_factoryDMM, tr( "Return this page to the built in values." ) );
    Layout50->addWidget( ui_factoryDMM );
    dmmPageLayout->addLayout( Layout50 );
    tabWidget->insertTab( dmmPage, tr( "DMM" ) );

    qtdmmTab = new QWidget( tabWidget, "qtdmmTab" );
    qtdmmTabLayout = new QVBoxLayout( qtdmmTab ); 
    qtdmmTabLayout->setSpacing( 5 );
    qtdmmTabLayout->setMargin( 10 );

    GroupBox7 = new QGroupBox( qtdmmTab, "GroupBox7" );
    GroupBox7->setTitle( tr( "Graph" ) );
    GroupBox7->setColumnLayout(0, Qt::Vertical );
    GroupBox7->layout()->setSpacing( 0 );
    GroupBox7->layout()->setMargin( 0 );
    GroupBox7Layout = new QVBoxLayout( GroupBox7->layout() );
    GroupBox7Layout->setAlignment( Qt::AlignTop );
    GroupBox7Layout->setSpacing( 5 );
    GroupBox7Layout->setMargin( 10 );

    Layout24_2 = new QHBoxLayout; 
    Layout24_2->setSpacing( 5 );
    Layout24_2->setMargin( 0 );

    Layout19 = new QHBoxLayout; 
    Layout19->setSpacing( 5 );
    Layout19->setMargin( 0 );

    ui_bgColor = new ColorButton( GroupBox7, "ui_bgColor" );
    ui_bgColor->setMinimumSize( QSize( 50, 0 ) );
    ui_bgColor->setMaximumSize( QSize( 50, 32767 ) );
    Layout19->addWidget( ui_bgColor );

    TextLabel2_2 = new QLabel( GroupBox7, "TextLabel2_2" );
    TextLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, TextLabel2_2->sizePolicy().hasHeightForWidth() ) );
    TextLabel2_2->setMinimumSize( QSize( 100, 0 ) );
    TextLabel2_2->setText( tr( "&Background" ) );
    Layout19->addWidget( TextLabel2_2 );
    Layout24_2->addLayout( Layout19 );
    QSpacerItem* spacer_17 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout24_2->addItem( spacer_17 );

    Layout20 = new QHBoxLayout; 
    Layout20->setSpacing( 5 );
    Layout20->setMargin( 0 );

    ui_gridColor = new ColorButton( GroupBox7, "ui_gridColor" );
    ui_gridColor->setMinimumSize( QSize( 50, 0 ) );
    ui_gridColor->setMaximumSize( QSize( 50, 32767 ) );
    Layout20->addWidget( ui_gridColor );

    TextLabel3_2 = new QLabel( GroupBox7, "TextLabel3_2" );
    TextLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, TextLabel3_2->sizePolicy().hasHeightForWidth() ) );
    TextLabel3_2->setMinimumSize( QSize( 100, 0 ) );
    TextLabel3_2->setText( tr( "&Grid" ) );
    Layout20->addWidget( TextLabel3_2 );
    Layout24_2->addLayout( Layout20 );
    GroupBox7Layout->addLayout( Layout24_2 );

    Layout23_2 = new QHBoxLayout; 
    Layout23_2->setSpacing( 5 );
    Layout23_2->setMargin( 0 );

    Layout17 = new QHBoxLayout; 
    Layout17->setSpacing( 5 );
    Layout17->setMargin( 0 );

    ui_dataColor = new ColorButton( GroupBox7, "ui_dataColor" );
    ui_dataColor->setMinimumSize( QSize( 50, 0 ) );
    ui_dataColor->setMaximumSize( QSize( 50, 32767 ) );
    Layout17->addWidget( ui_dataColor );

    label = new QLabel( GroupBox7, "label" );
    label->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, label->sizePolicy().hasHeightForWidth() ) );
    label->setMinimumSize( QSize( 100, 0 ) );
    label->setText( tr( "&Data" ) );
    Layout17->addWidget( label );
    Layout23_2->addLayout( Layout17 );
    QSpacerItem* spacer_18 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout23_2->addItem( spacer_18 );

    Layout18 = new QHBoxLayout; 
    Layout18->setSpacing( 5 );
    Layout18->setMargin( 0 );

    ui_cursorColor = new ColorButton( GroupBox7, "ui_cursorColor" );
    ui_cursorColor->setMinimumSize( QSize( 50, 0 ) );
    ui_cursorColor->setMaximumSize( QSize( 50, 32767 ) );
    Layout18->addWidget( ui_cursorColor );

    label2 = new QLabel( GroupBox7, "label2" );
    label2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, label2->sizePolicy().hasHeightForWidth() ) );
    label2->setMinimumSize( QSize( 100, 0 ) );
    label2->setText( tr( "&Cursor" ) );
    Layout18->addWidget( label2 );
    Layout23_2->addLayout( Layout18 );
    GroupBox7Layout->addLayout( Layout23_2 );

    TextLabel2_3 = new QLabel( GroupBox7, "TextLabel2_3" );
    TextLabel2_3->setMinimumSize( QSize( 0, 10 ) );
    TextLabel2_3->setMaximumSize( QSize( 32767, 10 ) );
    GroupBox7Layout->addWidget( TextLabel2_3 );

    Layout48 = new QHBoxLayout; 
    Layout48->setSpacing( 5 );
    Layout48->setMargin( 0 );

    TextLabel1 = new QLabel( GroupBox7, "TextLabel1" );
    TextLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, TextLabel1->sizePolicy().hasHeightForWidth() ) );
    TextLabel1->setText( tr( "Data line &width:" ) );
    Layout48->addWidget( TextLabel1 );

    ui_lineWidth = new QSpinBox( GroupBox7, "ui_lineWidth" );
    ui_lineWidth->setMaximumSize( QSize( 50, 32767 ) );
    ui_lineWidth->setMaxValue( 5 );
    ui_lineWidth->setMinValue( 1 );
    ui_lineWidth->setValue( 1 );
    Layout48->addWidget( ui_lineWidth );
    QSpacerItem* spacer_19 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout48->addItem( spacer_19 );
    GroupBox7Layout->addLayout( Layout48 );
    qtdmmTabLayout->addWidget( GroupBox7 );

    GroupBox4 = new QGroupBox( qtdmmTab, "GroupBox4" );
    GroupBox4->setTitle( tr( "Display" ) );
    GroupBox4->setColumnLayout(0, Qt::Vertical );
    GroupBox4->layout()->setSpacing( 0 );
    GroupBox4->layout()->setMargin( 0 );
    GroupBox4Layout = new QHBoxLayout( GroupBox4->layout() );
    GroupBox4Layout->setAlignment( Qt::AlignTop );
    GroupBox4Layout->setSpacing( 5 );
    GroupBox4Layout->setMargin( 10 );

    Layout19_2 = new QHBoxLayout; 
    Layout19_2->setSpacing( 5 );
    Layout19_2->setMargin( 0 );

    ui_bgColorDisplay = new ColorButton( GroupBox4, "ui_bgColorDisplay" );
    ui_bgColorDisplay->setMinimumSize( QSize( 50, 0 ) );
    ui_bgColorDisplay->setMaximumSize( QSize( 50, 32767 ) );
    Layout19_2->addWidget( ui_bgColorDisplay );

    TextLabel2_2_2 = new QLabel( GroupBox4, "TextLabel2_2_2" );
    TextLabel2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, TextLabel2_2_2->sizePolicy().hasHeightForWidth() ) );
    TextLabel2_2_2->setMinimumSize( QSize( 100, 0 ) );
    TextLabel2_2_2->setText( tr( "Back&ground" ) );
    Layout19_2->addWidget( TextLabel2_2_2 );
    GroupBox4Layout->addLayout( Layout19_2 );
    QSpacerItem* spacer_20 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    GroupBox4Layout->addItem( spacer_20 );

    Layout19_3 = new QHBoxLayout; 
    Layout19_3->setSpacing( 5 );
    Layout19_3->setMargin( 0 );

    ui_textColor = new ColorButton( GroupBox4, "ui_textColor" );
    ui_textColor->setMinimumSize( QSize( 50, 0 ) );
    ui_textColor->setMaximumSize( QSize( 50, 32767 ) );
    Layout19_3->addWidget( ui_textColor );

    TextLabel2_2_3 = new QLabel( GroupBox4, "TextLabel2_2_3" );
    TextLabel2_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, TextLabel2_2_3->sizePolicy().hasHeightForWidth() ) );
    TextLabel2_2_3->setMinimumSize( QSize( 100, 0 ) );
    TextLabel2_2_3->setText( tr( "&Text" ) );
    Layout19_3->addWidget( TextLabel2_2_3 );
    GroupBox4Layout->addLayout( Layout19_3 );
    qtdmmTabLayout->addWidget( GroupBox4 );

    ui_alertUnsavedData = new QCheckBox( qtdmmTab, "ui_alertUnsavedData" );
    ui_alertUnsavedData->setText( tr( "Alert unsaved data" ) );
    ui_alertUnsavedData->setChecked( TRUE );
    QWhatsThis::add(  ui_alertUnsavedData, tr( "When this option is checked QtDMM will alert you if you are going to overwrite or loose unsaved data (import, quit)." ) );
    qtdmmTabLayout->addWidget( ui_alertUnsavedData );

    ui_saveWindowCheck = new QCheckBox( qtdmmTab, "ui_saveWindowCheck" );
    ui_saveWindowCheck->setText( tr( "&Save window position and size on exit" ) );
    ui_saveWindowCheck->setChecked( TRUE );
    QWhatsThis::add(  ui_saveWindowCheck, tr( "When this option is checked the window position and size saved and restored in the next session." ) );
    qtdmmTabLayout->addWidget( ui_saveWindowCheck );

    ui_textLabel = new QCheckBox( qtdmmTab, "ui_textLabel" );
    ui_textLabel->setText( tr( "Icons with text label" ) );
    ui_textLabel->setChecked( TRUE );
    qtdmmTabLayout->addWidget( ui_textLabel );
    QSpacerItem* spacer_21 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    qtdmmTabLayout->addItem( spacer_21 );

    Layout49 = new QHBoxLayout; 
    Layout49->setSpacing( 5 );
    Layout49->setMargin( 0 );

    ui_defaultPreferences = new QPushButton( qtdmmTab, "ui_defaultPreferences" );
    ui_defaultPreferences->setText( tr( "&Undo" ) );
    ui_defaultPreferences->setAutoDefault( FALSE );
    QWhatsThis::add(  ui_defaultPreferences, tr( "Return to the previously saved settings for this page." ) );
    Layout49->addWidget( ui_defaultPreferences );
    QSpacerItem* spacer_22 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout49->addItem( spacer_22 );

    ui_factoryPreferences = new QPushButton( qtdmmTab, "ui_factoryPreferences" );
    ui_factoryPreferences->setText( tr( "Factory defaults" ) );
    ui_factoryPreferences->setAutoDefault( FALSE );
    QWhatsThis::add(  ui_factoryPreferences, tr( "Return this page to the built in values." ) );
    Layout49->addWidget( ui_factoryPreferences );
    qtdmmTabLayout->addLayout( Layout49 );
    tabWidget->insertTab( qtdmmTab, tr( "QtDMM" ) );
    UIConfigDlgLayout->addWidget( tabWidget );

    Layout105 = new QHBoxLayout; 
    Layout105->setSpacing( 5 );
    Layout105->setMargin( 0 );

    helpBut = new QPushButton( this, "helpBut" );
    helpBut->setMinimumSize( QSize( 26, 26 ) );
    helpBut->setText( tr( "" ) );
    helpBut->setPixmap( image1 );
    helpBut->setAccel( 2101296 );
    helpBut->setAutoDefault( FALSE );
    QToolTip::add(  helpBut, tr( "Direct help (SHIFT+F1)" ) );
    Layout105->addWidget( helpBut );
    QSpacerItem* spacer_23 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout105->addItem( spacer_23 );

    ui_applyBut = new QPushButton( this, "ui_applyBut" );
    ui_applyBut->setEnabled( TRUE );
    ui_applyBut->setText( tr( "&Apply" ) );
    QWhatsThis::add(  ui_applyBut, tr( "Apply changes and don't close dialog. You can only apply changes in your configuration, when QtDMM is not connected to the DMM." ) );
    Layout105->addWidget( ui_applyBut );

    okBut = new QPushButton( this, "okBut" );
    okBut->setEnabled( TRUE );
    okBut->setText( tr( "&OK" ) );
    okBut->setAutoDefault( TRUE );
    okBut->setDefault( TRUE );
    QWhatsThis::add(  okBut, tr( "Apply changes and close dialog. You can only apply changes in your configuration, when QtDMM is not connected to the DMM." ) );
    Layout105->addWidget( okBut );

    cancelBut = new QPushButton( this, "cancelBut" );
    cancelBut->setText( tr( "&Cancel" ) );
    cancelBut->setAutoDefault( TRUE );
    QWhatsThis::add(  cancelBut, tr( "Discard changes and close dialog." ) );
    Layout105->addWidget( cancelBut );
    UIConfigDlgLayout->addLayout( Layout105 );

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
    setTabOrder( fallingThresholdEdit, ui_defaultRecorder );
    setTabOrder( ui_defaultRecorder, ui_factoryRecorder );
    setTabOrder( ui_factoryRecorder, autoScaleBut );
    setTabOrder( autoScaleBut, manualScaleBut );
    setTabOrder( manualScaleBut, scaleMinEd );
    setTabOrder( scaleMinEd, scaleMaxEd );
    setTabOrder( scaleMaxEd, winSize );
    setTabOrder( winSize, sizeUnit );
    setTabOrder( sizeUnit, winLength );
    setTabOrder( winLength, lengthUnit );
    setTabOrder( lengthUnit, ui_defaultScale );
    setTabOrder( ui_defaultScale, ui_factoryScale );
    setTabOrder( ui_factoryScale, modelCombo );
    setTabOrder( modelCombo, port );
    setTabOrder( port, baudRate );
    setTabOrder( baudRate, bitsCombo );
    setTabOrder( bitsCombo, stopBitsCombo );
    setTabOrder( stopBitsCombo, protocolCombo );
    setTabOrder( protocolCombo, ignoreSpin );
    setTabOrder( ignoreSpin, ui_defaultDMM );
    setTabOrder( ui_defaultDMM, ui_factoryDMM );
    setTabOrder( ui_factoryDMM, ui_saveWindowCheck );
    setTabOrder( ui_saveWindowCheck, ui_lineWidth );
    setTabOrder( ui_lineWidth, ui_defaultPreferences );
    setTabOrder( ui_defaultPreferences, ui_factoryPreferences );
    setTabOrder( ui_factoryPreferences, helpBut );
    setTabOrder( helpBut, ui_applyBut );
    setTabOrder( ui_applyBut, okBut );
    setTabOrder( okBut, cancelBut );
    setTabOrder( cancelBut, tabWidget );

    // buddies
    sampLabel->setBuddy( sampleEvery );
    sampLabel_2->setBuddy( sampleTime );
    TextLabel10->setBuddy( scaleMinEd );
    TextLabel10_2->setBuddy( scaleMaxEd );
    TextLabel11->setBuddy( winSize );
    TextLabel12->setBuddy( winLength );
    TextLabel1_2->setBuddy( modelCombo );
    ui_bitsLabel->setBuddy( bitsCombo );
    ui_stopLabel->setBuddy( stopBitsCombo );
    ui_baudLabel->setBuddy( baudRate );
    TextLabel2->setBuddy( port );
    TextLabel1_4->setBuddy( ignoreSpin );
    TextLabel2_2->setBuddy( ui_bgColor );
    TextLabel3_2->setBuddy( ui_gridColor );
    label->setBuddy( ui_dataColor );
    label2->setBuddy( ui_cursorColor );
    TextLabel1->setBuddy( ui_lineWidth );
    TextLabel2_2_2->setBuddy( ui_bgColor );
    TextLabel2_2_3->setBuddy( ui_bgColor );
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

