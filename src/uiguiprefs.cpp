/****************************************************************************
** Form implementation generated from reading ui file 'uiguiprefs.ui'
**
** Created: Tue Dec 25 12:41:15 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "uiguiprefs.h"

#include <qvariant.h>
#include <prefwidget.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qcheckbox.h>
#include <qlabel.h>
#include <qbuttongroup.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "prefwidget.h"
#include "colorbutton.h"

/*
 *  Constructs a UIGuiPrefs which is a child of 'parent', with the
 *  name 'name'.' 
 */
UIGuiPrefs::UIGuiPrefs( QWidget* parent,  const char* name )
    : PrefWidget( parent, name )
{
    if ( !name )
	setName( "UIGuiPrefs" );
    UIGuiPrefsLayout = new QVBoxLayout( this, 10, 5, "UIGuiPrefsLayout"); 

    GroupBox4 = new QGroupBox( this, "GroupBox4" );
    GroupBox4->setColumnLayout(0, Qt::Vertical );
    GroupBox4->layout()->setSpacing( 5 );
    GroupBox4->layout()->setMargin( 10 );
    GroupBox4Layout = new QGridLayout( GroupBox4->layout() );
    GroupBox4Layout->setAlignment( Qt::AlignTop );

    Layout37 = new QHBoxLayout( 0, 0, 0, "Layout37"); 

    ui_showBar = new QCheckBox( GroupBox4, "ui_showBar" );
    ui_showBar->setChecked( TRUE );
    Layout37->addWidget( ui_showBar );
    Spacer34 = new QSpacerItem( 20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum );
    Layout37->addItem( Spacer34 );

    GroupBox4Layout->addMultiCellLayout( Layout37, 1, 1, 0, 1 );

    Layout37_2 = new QHBoxLayout( 0, 0, 0, "Layout37_2"); 

    ui_showMinMax = new QCheckBox( GroupBox4, "ui_showMinMax" );
    ui_showMinMax->setChecked( TRUE );
    Layout37_2->addWidget( ui_showMinMax );
    Spacer34_2 = new QSpacerItem( 20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum );
    Layout37_2->addItem( Spacer34_2 );

    GroupBox4Layout->addMultiCellLayout( Layout37_2, 1, 1, 2, 3 );

    ui_showDisplay = new QCheckBox( GroupBox4, "ui_showDisplay" );
    ui_showDisplay->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)0, 0, 0, ui_showDisplay->sizePolicy().hasHeightForWidth() ) );
    ui_showDisplay->setChecked( TRUE );

    GroupBox4Layout->addWidget( ui_showDisplay, 0, 0 );

    Layout19_2 = new QHBoxLayout( 0, 0, 5, "Layout19_2"); 

    ui_bgColorDisplay = new ColorButton( GroupBox4, "ui_bgColorDisplay" );
    ui_bgColorDisplay->setMinimumSize( QSize( 50, 0 ) );
    ui_bgColorDisplay->setMaximumSize( QSize( 50, 32767 ) );
    Layout19_2->addWidget( ui_bgColorDisplay );

    TextLabel2_2_2 = new QLabel( GroupBox4, "TextLabel2_2_2" );
    TextLabel2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)1, 0, 0, TextLabel2_2_2->sizePolicy().hasHeightForWidth() ) );
    TextLabel2_2_2->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignLeft ) );
    Layout19_2->addWidget( TextLabel2_2_2 );

    GroupBox4Layout->addMultiCellLayout( Layout19_2, 0, 0, 1, 2 );

    Layout19_3 = new QHBoxLayout( 0, 0, 5, "Layout19_3"); 

    ui_textColor = new ColorButton( GroupBox4, "ui_textColor" );
    ui_textColor->setMinimumSize( QSize( 50, 0 ) );
    ui_textColor->setMaximumSize( QSize( 50, 32767 ) );
    Layout19_3->addWidget( ui_textColor );

    TextLabel2_2_3 = new QLabel( GroupBox4, "TextLabel2_2_3" );
    TextLabel2_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)1, 0, 0, TextLabel2_2_3->sizePolicy().hasHeightForWidth() ) );
    Layout19_3->addWidget( TextLabel2_2_3 );

    GroupBox4Layout->addLayout( Layout19_3, 0, 3 );
    UIGuiPrefsLayout->addWidget( GroupBox4 );

    GroupBox4_2 = new QGroupBox( this, "GroupBox4_2" );
    GroupBox4_2->setColumnLayout(0, Qt::Vertical );
    GroupBox4_2->layout()->setSpacing( 5 );
    GroupBox4_2->layout()->setMargin( 10 );
    GroupBox4_2Layout = new QGridLayout( GroupBox4_2->layout() );
    GroupBox4_2Layout->setAlignment( Qt::AlignTop );

    Layout28 = new QHBoxLayout( 0, 0, 0, "Layout28"); 

    ui_alertUnsavedData = new QCheckBox( GroupBox4_2, "ui_alertUnsavedData" );
    ui_alertUnsavedData->setChecked( TRUE );
    Layout28->addWidget( ui_alertUnsavedData );
    Spacer1_10 = new QSpacerItem( 20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum );
    Layout28->addItem( Spacer1_10 );

    GroupBox4_2Layout->addMultiCellLayout( Layout28, 0, 0, 0, 1 );

    Layout29 = new QHBoxLayout( 0, 0, 0, "Layout29"); 

    ui_saveWindowPos = new QCheckBox( GroupBox4_2, "ui_saveWindowPos" );
    ui_saveWindowPos->setChecked( TRUE );
    Layout29->addWidget( ui_saveWindowPos );
    Spacer2_3 = new QSpacerItem( 20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum );
    Layout29->addItem( Spacer2_3 );

    GroupBox4_2Layout->addLayout( Layout29, 1, 0 );

    Layout29_2 = new QHBoxLayout( 0, 0, 0, "Layout29_2"); 

    ui_saveWindowSize = new QCheckBox( GroupBox4_2, "ui_saveWindowSize" );
    ui_saveWindowSize->setChecked( TRUE );
    Layout29_2->addWidget( ui_saveWindowSize );
    Spacer2_3_2 = new QSpacerItem( 20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum );
    Layout29_2->addItem( Spacer2_3_2 );

    GroupBox4_2Layout->addLayout( Layout29_2, 1, 1 );
    UIGuiPrefsLayout->addWidget( GroupBox4_2 );

    ButtonGroup12_2 = new QButtonGroup( this, "ButtonGroup12_2" );
    ButtonGroup12_2->setColumnLayout(0, Qt::Vertical );
    ButtonGroup12_2->layout()->setSpacing( 5 );
    ButtonGroup12_2->layout()->setMargin( 10 );
    ButtonGroup12_2Layout = new QGridLayout( ButtonGroup12_2->layout() );
    ButtonGroup12_2Layout->setAlignment( Qt::AlignTop );

    Layout30 = new QHBoxLayout( 0, 0, 0, "Layout30"); 

    ui_textLabel = new QCheckBox( ButtonGroup12_2, "ui_textLabel" );
    ui_textLabel->setChecked( TRUE );
    Layout30->addWidget( ui_textLabel );
    Spacer3_4_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout30->addItem( Spacer3_4_2 );

    ButtonGroup12_2Layout->addMultiCellLayout( Layout30, 0, 0, 0, 1 );

    Layout30_3 = new QHBoxLayout( 0, 0, 0, "Layout30_3"); 

    ui_dmmToolBar = new QCheckBox( ButtonGroup12_2, "ui_dmmToolBar" );
    ui_dmmToolBar->setChecked( TRUE );
    Layout30_3->addWidget( ui_dmmToolBar );
    Spacer3_4_2_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout30_3->addItem( Spacer3_4_2_2 );

    ButtonGroup12_2Layout->addLayout( Layout30_3, 1, 0 );

    Layout30_4 = new QHBoxLayout( 0, 0, 0, "Layout30_4"); 

    ui_fileToolBar = new QCheckBox( ButtonGroup12_2, "ui_fileToolBar" );
    ui_fileToolBar->setChecked( TRUE );
    Layout30_4->addWidget( ui_fileToolBar );
    Spacer3_4_2_3 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout30_4->addItem( Spacer3_4_2_3 );

    ButtonGroup12_2Layout->addLayout( Layout30_4, 2, 0 );

    Layout30_5 = new QHBoxLayout( 0, 0, 0, "Layout30_5"); 

    ui_helpToolBar = new QCheckBox( ButtonGroup12_2, "ui_helpToolBar" );
    ui_helpToolBar->setChecked( TRUE );
    Layout30_5->addWidget( ui_helpToolBar );
    Spacer3_4_2_4 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout30_5->addItem( Spacer3_4_2_4 );

    ButtonGroup12_2Layout->addLayout( Layout30_5, 2, 1 );

    Layout30_5_2 = new QHBoxLayout( 0, 0, 0, "Layout30_5_2"); 

    ui_graphToolBar = new QCheckBox( ButtonGroup12_2, "ui_graphToolBar" );
    ui_graphToolBar->setChecked( TRUE );
    Layout30_5_2->addWidget( ui_graphToolBar );
    Spacer3_4_2_4_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout30_5_2->addItem( Spacer3_4_2_4_2 );

    ButtonGroup12_2Layout->addLayout( Layout30_5_2, 1, 1 );
    UIGuiPrefsLayout->addWidget( ButtonGroup12_2 );

    ui_tipOfTheDay = new QCheckBox( this, "ui_tipOfTheDay" );
    ui_tipOfTheDay->setChecked( TRUE );
    UIGuiPrefsLayout->addWidget( ui_tipOfTheDay );
    Spacer1_5 = new QSpacerItem( 20, 70, QSizePolicy::Minimum, QSizePolicy::Expanding );
    UIGuiPrefsLayout->addItem( Spacer1_5 );
    languageChange();
    resize( QSize(559, 360).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // tab order
    setTabOrder( ui_showBar, ui_showMinMax );
    setTabOrder( ui_showMinMax, ui_alertUnsavedData );
    setTabOrder( ui_alertUnsavedData, ui_saveWindowPos );
    setTabOrder( ui_saveWindowPos, ui_saveWindowSize );
    setTabOrder( ui_saveWindowSize, ui_textLabel );
    setTabOrder( ui_textLabel, ui_dmmToolBar );
    setTabOrder( ui_dmmToolBar, ui_graphToolBar );
    setTabOrder( ui_graphToolBar, ui_fileToolBar );
    setTabOrder( ui_fileToolBar, ui_helpToolBar );
    setTabOrder( ui_helpToolBar, ui_tipOfTheDay );

    // buddies
    TextLabel2_2_2->setBuddy( ui_bgColorDisplay );
    TextLabel2_2_3->setBuddy( ui_textColor );
}

/*
 *  Destroys the object and frees any allocated resources
 */
UIGuiPrefs::~UIGuiPrefs()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void UIGuiPrefs::languageChange()
{
    setCaption( tr( "QFrameForm" ) );
    GroupBox4->setTitle( tr( "Display" ) );
    ui_showBar->setText( tr( "Show bargraph" ) );
    ui_showMinMax->setText( tr( "Show Min/Max" ) );
    ui_showDisplay->setText( tr( "Show" ) );
    QWhatsThis::add( ui_bgColorDisplay, tr( "Click this button to change the color of the numerical display for the dmm." ) );
    TextLabel2_2_2->setText( tr( "Back&ground" ) );
    QWhatsThis::add( ui_textColor, tr( "Click this button to change the color of the text in the numerical display." ) );
    TextLabel2_2_3->setText( tr( "&Text" ) );
    GroupBox4_2->setTitle( tr( "At program exit" ) );
    ui_alertUnsavedData->setText( tr( "Alert unsaved data" ) );
    QWhatsThis::add( ui_alertUnsavedData, tr( "When this option is checked QtDMM will alert you if you are going to overwrite or loose unsaved data (import, quit)." ) );
    ui_saveWindowPos->setText( tr( "Save window position" ) );
    QWhatsThis::add( ui_saveWindowPos, tr( "When this option is checked the window position and size saved and restored in the next session." ) );
    ui_saveWindowSize->setText( tr( "Save window size" ) );
    QWhatsThis::add( ui_saveWindowSize, tr( "When this option is checked the window position and size saved and restored in the next session." ) );
    ButtonGroup12_2->setTitle( tr( "Toolbar" ) );
    ui_textLabel->setText( tr( "Icons with text label" ) );
    QWhatsThis::add( ui_textLabel, tr( "Check this if you want text labels in the toolbar." ) );
    ui_dmmToolBar->setText( tr( "DMM toolbar" ) );
    QWhatsThis::add( ui_dmmToolBar, tr( "Check this if you want text labels in the toolbar." ) );
    ui_fileToolBar->setText( tr( "File toolbar" ) );
    QWhatsThis::add( ui_fileToolBar, tr( "Check this if you want text labels in the toolbar." ) );
    ui_helpToolBar->setText( tr( "Help toolbar" ) );
    QWhatsThis::add( ui_helpToolBar, tr( "Check this if you want text labels in the toolbar." ) );
    ui_graphToolBar->setText( tr( "Graph toolbar" ) );
    QWhatsThis::add( ui_graphToolBar, tr( "Check this if you want text labels in the toolbar." ) );
    ui_tipOfTheDay->setText( tr( "Show tip of the day" ) );
}

