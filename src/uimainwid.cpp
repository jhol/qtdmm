/****************************************************************************
** Form implementation generated from reading ui file 'uimainwid.ui'
**
** Created: Tue Dec 25 12:41:19 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "uimainwid.h"

#include <qvariant.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "dmmgraph.h"
static const char* const image0_data[] = { 
"32 32 14 1",
". c None",
"# c #000000",
"i c #0018ff",
"k c #0020ff",
"l c #101010",
"c c #393839",
"b c #5a595a",
"a c #7b797b",
"e c #949594",
"j c #c5c6c5",
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
    : QFrame( parent, name ),
      image0( (const char **) image0_data )
{
    if ( !name )
	setName( "UIMainWid" );
    setIcon( image0 );
    setFrameShape( QFrame::StyledPanel );
    setFrameShadow( QFrame::Raised );
    UIMainWidLayout = new QVBoxLayout( this, 0, 5, "UIMainWidLayout"); 

    Layout5 = new QHBoxLayout( 0, 0, 5, "Layout5"); 

    ui_graph = new DMMGraph( this, "ui_graph" );
    ui_graph->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, ui_graph->sizePolicy().hasHeightForWidth() ) );
    ui_graph->setMinimumSize( QSize( 0, 60 ) );
    ui_graph->setCursor( QCursor( 0 ) );
    Layout5->addWidget( ui_graph );
    UIMainWidLayout->addLayout( Layout5 );
    languageChange();
    resize( QSize(605, 496).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
UIMainWid::~UIMainWid()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void UIMainWid::languageChange()
{
    setCaption( tr( "QtDMM 0.4.1" ) );
    setIconText( tr( "QtDMM 0.4" ) );
    QWhatsThis::add( ui_graph, tr( "This is the plotting area for the transient recorder. It is widely configurable by clicking the <b>config ...</b> button to the right. Data aquisition may be started by hand, at a specific time or automatically triggered by the measured value itself <i>(See configuration dialog)</i><p>\n"
"The maximum resolution for data aquisition is 1/10th of a second, but may also be configured to sample once a week or what ever you want.\n"
"<p>\n"
"<b>Note:</b> Connecting to the DMM as well as a change of the measuring unit automatically clears the graph." ) );
}

