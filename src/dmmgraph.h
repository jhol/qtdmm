//======================================================================
// File:		dmmgraph.h
// Author:	Matthias Toussaint
// Created:	Tue Apr 10 17:43:46 CEST 2001
//----------------------------------------------------------------------
// Permission to use, copy, modify, and distribute this software and its
// documentation  for any  purpose and  without fee is  hereby  granted,
// provided  that below copyright notice appear  in all copies  and that
// both  that  copyright  notice and  this permission  notice  appear in
// supporting documentation.
// 
// This  file is  provided AS IS  with no  warranties  of any kind.  The
// author shall  have no liability  with respect  to the infringement of
// copyrights, trade  secrets  or any patents by  this file  or any part
// thereof.  In no event will the author be liable  for any lost revenue
// or profits or other special, indirect and consequential damages.
//----------------------------------------------------------------------
// (c) 2001 Matthias Toussaint
//======================================================================

#ifndef DMMGRAPH_HH
#define DMMGRAPH_HH

#include <qwidget.h>
#include <qscrollbar.h>
#include <qarray.h>
#include <qdatetime.h>
#include <qprinter.h>
#include <qlabel.h>

class DMMGraph : public QWidget
{
  Q_OBJECT
public:
  enum SampleMode
  {
    Manual,
    Time,
    Raising,
    Falling
  };
    
  DMMGraph( QWidget *parent=0, const char *name=0 );
  virtual ~DMMGraph();
  
  void setGraphSize( int size, int length );
  void addValue( double );
  void setUnit( const QString & );
  void setSampleTime( int v ) { m_sampleTime = v; }
  void setSampleLength( int v ) { m_sampleLength = v; }
  void setStartTime( const QTime & time ) { m_startTime = time; }
  void setMode( DMMGraph::SampleMode mode ) { m_mode = mode; }
  void print( QPrinter *prt, const QString &, const QString & );
  void setThresholds( double falling, double raising );
  void setScale( bool autoScale, double min, double max );
  
signals:
  void info( const QString & );
  void running( bool );
  
public slots:
  void clearSLOT();
  void startSLOT();
  void stopSLOT();
  void exportDataSLOT();
  
protected:
  QScrollBar     *scrollbar;
  int             m_size;
  int             m_length;
  double          m_scaleMin;
  double          m_scaleMax;
  bool            m_autoScale;
  QArray<double> *m_array;
  int             m_pointer;
  double          m_yfactor;
  double          m_xfactor;
  double          m_ystep;
  QString         m_unit;
  QString         m_hUnit;
  double          m_xstep;
  double          m_hUnitFact;
  double          m_maxUnit;
  int             m_sampleTime;
  int             m_sampleLength;
  bool            m_running;
  int             m_sampleCounter;
  int             m_remainingLength;
  SampleMode      m_mode;
  QTime           m_startTime;
  QDateTime       m_graphStart;
  double          m_sum;
  bool            m_first;
  QPoint          m_mpos;
  QLabel         *m_infoBox;
  bool            m_mouseDown;
  double          m_raisingThreshold;
  double          m_fallingThreshold;
  double          m_lastVal;
  bool            m_lastValValid;
  
  void paintEvent( QPaintEvent * );
  void resizeEvent( QResizeEvent * );
  double createYScale( int h, double & ystep );
  double createTimeScale( int w, double & xstep, double & hUnitFact,
                          double & maxUnit, QString & hUnit );
  void emitInfo();
  void paint( QPainter *p, int w, int h, 
              double xfactor, double xstep,
              double yfactor, double ystep,
              double maxUnit, double hUnitFact, 
              const QString & hUnit, bool color, bool printer );
  void paintHorizontalGrid( QPainter *p, int w, int h, 
                            double yfactor, double ystep, bool color );
  void paintVerticalGrid( QPainter *p, int w, int h, 
                          double xfactor, double xstep,
                          double maxUnit, double hUnitFact, 
                          const QString & hUnit, bool color );
  void paintData( QPainter *p, int w, int h, double xfactor, 
                  double yfactor, bool color, bool printer );
  void mousePressEvent( QMouseEvent * );
  void mouseMoveEvent( QMouseEvent * );
  void mouseReleaseEvent( QMouseEvent * );
  void drawCursor( const QPoint & );
  void fillInfoBox( const QPoint & );
  
};

#endif // DMMGRAPH_HH
