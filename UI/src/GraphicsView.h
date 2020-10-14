//******************************************************************************
// GraphicsView.h
//	: header file for graphics scene
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Jun 19 02:36:37 2019
//
//******************************************************************************

#ifndef Ui_GraphicsView_H
#define Ui_GraphicsView_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <thread>

using namespace std;

#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsSceneDragDropEvent>
#include <QtWidgets/QFileDialog>
#include <QtGui/QMouseEvent>
#include <QtCore/QMimeData>
#include <QtCore/QDir>
#include <QtCore/QTimer>
#include <QtSvg/QSvgGenerator>

#ifndef Q_MOC_RUN
#include "Base.h"
#include "Common.h"
#include "GraphicsVertexItem.h"
#include "GraphicsBallItem.h"
#include "GraphicsEdgeItem.h"
#endif // Q_MOC_RUN

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

namespace Ui{

    //------------------------------------------------------------------------------
    //	Class definition
    //------------------------------------------------------------------------------
    class GraphicsView : public QGraphicsView
    {
        Q_OBJECT

    private:

        //------------------------------------------------------------------------------
        //	UI
        //------------------------------------------------------------------------------
        double      _min_point_distance;

        QPoint      _oldCursor, _cursor;
        bool        _left_button_pressed,
                    _middle_button_pressed,
                    _right_button_pressed;

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
//        virtual void _init              ( void ) = 0;
//	    virtual void _clear             ( void ) = 0;

    protected:
	
	    // picking testing
	    QPainterPath                    _selectionArea;
	    unsigned int                    _test;
	
	    //------------------------------------------------------------------------------
	    //	Data
	    //------------------------------------------------------------------------------
	    // scene
	    QGraphicsScene                  *_scenePtr;
	    KeiRo::Base::Base               *_basePtr;
	    
	    //------------------------------------------------------------------------------
        //	Event handlers
        //------------------------------------------------------------------------------
//	    void keyPressEvent      ( QKeyEvent *event )    Q_DECL_OVERRIDE;
//	    void mousePressEvent    ( QMouseEvent *event )  Q_DECL_OVERRIDE;
//	    void mouseMoveEvent     ( QMouseEvent *event )  Q_DECL_OVERRIDE;
//	    void mouseReleaseEvent  ( QMouseEvent *event )  Q_DECL_OVERRIDE;
	
	    //------------------------------------------------------------------------------
        //	Drawing functions
        //------------------------------------------------------------------------------


        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        virtual void readInputData( void ) = 0;
        
    public:

        //settings
        // QWidget* getSettings() override;

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        explicit GraphicsView( QWidget *parent = Q_NULLPTR );
        // copy constructor
        explicit GraphicsView( GraphicsView *parent = Q_NULLPTR ) {}
        // destructor
        ~GraphicsView( void ) {}

        //------------------------------------------------------------------------------
        //      Reimplementation
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //      Reference to elements
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	    Special functions
        //------------------------------------------------------------------------------
	
	    virtual void init               ( KeiRo::Base::Base *__b_ptr ) = 0;
        virtual void initSceneItems     ( void ) = 0;
        virtual void updateSceneItems   ( void ) = 0;
	
	    void simulateKey        ( Qt::Key key );
        void exportPNG ( double x, double y, double w, double h );
        void exportSVG ( double x, double y, double w, double h );

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream &	operator << ( ostream & s, const GraphicsView & m );
        // input
        friend istream &	operator >> ( istream & s, GraphicsView & m );
        // class name
        virtual const char * className( void ) const { return "GraphicsView"; }
        
    Q_SIGNALS:
    	
	    virtual void dataChanged() = 0;
     
    public Q_SLOTS:

    };

} // namespace Ui

#endif // Ui_Vector_GraphicsView_H
