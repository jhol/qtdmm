/****************************************************************************
** Form implementation generated from reading ui file 'uiexecuteprefs.ui'
**
** Created: Tue Dec 25 12:41:11 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "uiexecuteprefs.h"

#include <qvariant.h>
#include <prefwidget.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qbuttongroup.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qradiobutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

static const char* const image0_data[] = { 
"16 16 7 1",
". c None",
"# c #000000",
"e c #a4a1a4",
"a c #acaaac",
"d c #c5c2c5",
"b c #d5d2d5",
"c c #dedede",
"................",
"................",
"................",
".####...........",
"#abba#######....",
"#bbbbaaaaaaa#...",
"#bb#############",
"#ba#ccccccccccc#",
"#b#cddddededee#.",
"#a#cdddededeee#.",
"##cdddededeee#..",
"##cddededeeee#..",
"#cddededeeee#...",
"#############...",
"................",
"................"};


/*
 *  Constructs a UIExecutePrefs which is a child of 'parent', with the
 *  name 'name'.' 
 */
UIExecutePrefs::UIExecutePrefs( QWidget* parent,  const char* name )
    : PrefWidget( parent, name ),
      image0( (const char **) image0_data )
{
    if ( !name )
	setName( "UIExecutePrefs" );
    UIExecutePrefsLayout = new QVBoxLayout( this, 10, 5, "UIExecutePrefsLayout"); 

    ui_executeCommand = new QCheckBox( this, "ui_executeCommand" );
    UIExecutePrefsLayout->addWidget( ui_executeCommand );

    ButtonGroup9 = new QButtonGroup( this, "ButtonGroup9" );
    ButtonGroup9->setEnabled( FALSE );
    ButtonGroup9->setFrameShape( QButtonGroup::Box );
    ButtonGroup9->setFrameShadow( QButtonGroup::Sunken );
    ButtonGroup9->setColumnLayout(0, Qt::Vertical );
    ButtonGroup9->layout()->setSpacing( 5 );
    ButtonGroup9->layout()->setMargin( 10 );
    ButtonGroup9Layout = new QGridLayout( ButtonGroup9->layout() );
    ButtonGroup9Layout->setAlignment( Qt::AlignTop );

    TextLabel8_2_2_2 = new QLabel( ButtonGroup9, "TextLabel8_2_2_2" );

    ButtonGroup9Layout->addWidget( TextLabel8_2_2_2, 1, 1 );

    ui_execRaisingThreshold = new QLineEdit( ButtonGroup9, "ui_execRaisingThreshold" );
    ui_execRaisingThreshold->setMaximumSize( QSize( 80, 32767 ) );
    ui_execRaisingThreshold->setMaxLength( 12 );

    ButtonGroup9Layout->addWidget( ui_execRaisingThreshold, 0, 2 );

    TextLabel7_2_2_2 = new QLabel( ButtonGroup9, "TextLabel7_2_2_2" );

    ButtonGroup9Layout->addWidget( TextLabel7_2_2_2, 0, 1 );

    ui_execFallingThreshold = new QLineEdit( ButtonGroup9, "ui_execFallingThreshold" );
    ui_execFallingThreshold->setMaximumSize( QSize( 80, 32767 ) );
    ui_execFallingThreshold->setMaxLength( 12 );

    ButtonGroup9Layout->addWidget( ui_execFallingThreshold, 1, 2 );

    ui_execRaising = new QRadioButton( ButtonGroup9, "ui_execRaising" );
    ui_execRaising->setChecked( TRUE );

    ButtonGroup9Layout->addWidget( ui_execRaising, 0, 0 );

    ui_execFalling = new QRadioButton( ButtonGroup9, "ui_execFalling" );

    ButtonGroup9Layout->addWidget( ui_execFalling, 1, 0 );
    Spacer4_2_2_2_2 = new QSpacerItem( 20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum );
    ButtonGroup9Layout->addItem( Spacer4_2_2_2_2, 1, 3 );
    Spacer3_3_2_2 = new QSpacerItem( 20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum );
    ButtonGroup9Layout->addItem( Spacer3_3_2_2, 0, 3 );
    UIExecutePrefsLayout->addWidget( ButtonGroup9 );

    ButtonGroup10 = new QButtonGroup( this, "ButtonGroup10" );
    ButtonGroup10->setEnabled( FALSE );
    ButtonGroup10->setColumnLayout(0, Qt::Vertical );
    ButtonGroup10->layout()->setSpacing( 5 );
    ButtonGroup10->layout()->setMargin( 10 );
    ButtonGroup10Layout = new QVBoxLayout( ButtonGroup10->layout() );
    ButtonGroup10Layout->setAlignment( Qt::AlignTop );

    Layout32_2_2 = new QHBoxLayout( 0, 0, 5, "Layout32_2_2"); 

    ui_disconnectExec = new QCheckBox( ButtonGroup10, "ui_disconnectExec" );
    ui_disconnectExec->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)0, 0, 0, ui_disconnectExec->sizePolicy().hasHeightForWidth() ) );
    Layout32_2_2->addWidget( ui_disconnectExec );
    Spacer1_9_2_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout32_2_2->addItem( Spacer1_9_2_2 );
    ButtonGroup10Layout->addLayout( Layout32_2_2 );

    Layout30_2_2 = new QHBoxLayout( 0, 0, 5, "Layout30_2_2"); 

    ui_commandExec = new QLineEdit( ButtonGroup10, "ui_commandExec" );
    Layout30_2_2->addWidget( ui_commandExec );

    ui_browseExec = new QPushButton( ButtonGroup10, "ui_browseExec" );
    ui_browseExec->setMinimumSize( QSize( 24, 24 ) );
    ui_browseExec->setPixmap( image0 );
    ui_browseExec->setAutoDefault( FALSE );
    Layout30_2_2->addWidget( ui_browseExec );
    ButtonGroup10Layout->addLayout( Layout30_2_2 );
    UIExecutePrefsLayout->addWidget( ButtonGroup10 );
    Spacer1_8 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    UIExecutePrefsLayout->addItem( Spacer1_8 );
    languageChange();
    resize( QSize(297, 221).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( ui_executeCommand, SIGNAL( toggled(bool) ), ButtonGroup9, SLOT( setEnabled(bool) ) );
    connect( ui_executeCommand, SIGNAL( toggled(bool) ), ButtonGroup10, SLOT( setEnabled(bool) ) );

    // tab order
    setTabOrder( ui_executeCommand, ui_execRaising );
    setTabOrder( ui_execRaising, ui_execRaisingThreshold );
    setTabOrder( ui_execRaisingThreshold, ui_execFalling );
    setTabOrder( ui_execFalling, ui_execFallingThreshold );
    setTabOrder( ui_execFallingThreshold, ui_disconnectExec );
    setTabOrder( ui_disconnectExec, ui_commandExec );
    setTabOrder( ui_commandExec, ui_browseExec );
}

/*
 *  Destroys the object and frees any allocated resources
 */
UIExecutePrefs::~UIExecutePrefs()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void UIExecutePrefs::languageChange()
{
    setCaption( tr( "QFrameForm" ) );
    ui_executeCommand->setText( tr( "Execute external command at given threshold" ) );
    QWhatsThis::add( ui_executeCommand, tr( "Check this if you want QtDMM to execute an external command when given thresholds are reached (Falling or raising edge)." ) );
    ButtonGroup9->setTitle( tr( "Threshold" ) );
    TextLabel8_2_2_2->setText( tr( "Threshold:" ) );
    ui_execRaisingThreshold->setText( tr( "0" ) );
    QWhatsThis::add( ui_execRaisingThreshold, tr( "Threshold for raising edge.<p>\n"
"You can enter your values with a suffix like m, u, n, p, k, M, G, T<br>Example:<br>\n"
"10k - 10000<br>100m - 0.1" ) );
    TextLabel7_2_2_2->setText( tr( "Threshold:" ) );
    ui_execFallingThreshold->setText( tr( "0.0" ) );
    QWhatsThis::add( ui_execFallingThreshold, tr( "Threshold for falling edge.<p>\n"
"You can enter your values with a suffix like m, u, n, p, k, M, G, T<br>Example:<br>\n"
"10k - 10000<br>100m - 0.1" ) );
    ui_execRaising->setText( tr( "&Raising edge" ) );
    QWhatsThis::add( ui_execRaising, tr( "Call command on raising edge." ) );
    ui_execFalling->setText( tr( "&Falling edge" ) );
    QWhatsThis::add( ui_execFalling, tr( "Call command on falling edge." ) );
    ButtonGroup10->setTitle( tr( "Command" ) );
    ui_disconnectExec->setText( tr( "Disconnect before executing command" ) );
    QWhatsThis::add( ui_disconnectExec, tr( "Check this if you want QtDMM to disconnect (close the serial port) before executing the external command." ) );
    QWhatsThis::add( ui_commandExec, tr( "Enter here the external command to be executed." ) );
    ui_browseExec->setText( QString::null );
    QToolTip::add( ui_browseExec, tr( "Browse" ) );
    QWhatsThis::add( ui_browseExec, tr( "Here you can browse your harddisk for the external command (Altenative to directly typing it into the field to the left)." ) );
}

