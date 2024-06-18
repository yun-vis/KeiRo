//******************************************************************************
// GraphicsEdgeItem.h
//	: header file for edge items
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Jun 19 02:36:37 2019
//
//******************************************************************************

#ifndef Ui_Vector_GraphicsPathItem_H
#define Ui_Vector_GraphicsPathItem_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsItem>
//#include <QtGui/QPainter>
//#include <QtCore/QString>
//#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>

#ifndef Q_MOC_RUN
#include "GraphicsBase.h"
#endif // Q_MOC_RUN

Q_DECLARE_METATYPE (QPainterPath)

namespace Ui {
namespace Vector {
	
	
	//------------------------------------------------------------------------------
    //	Class definition
    //------------------------------------------------------------------------------
    class GraphicsPathItem : public  QGraphicsPathItem, public GraphicsBase {
    
	    
    private:
    
    protected:
	    
    	//------------------------------------------------------------------------------
	    //	Special functions
	    //------------------------------------------------------------------------------
	    void            _init( void );
	    
    public:

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        explicit GraphicsPathItem( QGraphicsItem *parent = Q_NULLPTR );
        // copy constructor
        explicit GraphicsPathItem( const QPainterPath &path, QGraphicsItem *parent = Q_NULLPTR );
        // destructor
        ~GraphicsPathItem( void ) {}

        //------------------------------------------------------------------------------
        //      Reimplementation
        //------------------------------------------------------------------------------
        // source from the qt library
        //QPainterPath path() const;
        //void setPath(const QPainterPath &path);

        //QPainterPath shape() const Q_DECL_OVERRIDE;
        //bool contains(const QPointF &point) const Q_DECL_OVERRIDE;

        QRectF boundingRect() const Q_DECL_OVERRIDE;
        int type( void ) const Q_DECL_OVERRIDE;

        void paint( QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget = Q_NULLPTR ) Q_DECL_OVERRIDE;

        //------------------------------------------------------------------------------
        //      Reference to elements
        //------------------------------------------------------------------------------
	
	    //------------------------------------------------------------------------------
	    //	Special functions
	    //------------------------------------------------------------------------------
	    void init( void ) { _init(); }

    };

} // namespace Vector
} // namespace Ui


#endif // Ui_Vector_GraphicsPathItem_H
