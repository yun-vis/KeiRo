//******************************************************************************
// GraphicsPolygonItem.h
//	: header file for polygon items
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Jun 19 02:36:37 2019
//
//******************************************************************************

#ifndef Ui_Vector_GraphicsPolygonItem_H
#define Ui_Vector_GraphicsPolygonItem_H

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

namespace Ui {
namespace Vector {

    //------------------------------------------------------------------------------
    //	Class definition
    //------------------------------------------------------------------------------
    class GraphicsPolygonItem : public QObject, public QGraphicsPolygonItem, public GraphicsBase {

	    Q_OBJECT
	    Q_PROPERTY( QPolygonF polygon READ getPolygon WRITE setPolygon )
	    Q_INTERFACES( QGraphicsItem )
	    
    private:

        QRect           _bbox;
	    unsigned long   _attributeID;
	    QBrush          _defaultBrush;
	    QPen            _defaultPen;

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
        explicit GraphicsPolygonItem( QGraphicsItem *parent = Q_NULLPTR );
        // copy constructor
        explicit GraphicsPolygonItem( QPolygonF &polygon, QGraphicsItem *parent = Q_NULLPTR ) {}
        // destructor
        ~GraphicsPolygonItem( void ) {}

        // source from the qt library
        //QPainterPath path() const;
        //void setPath(const QPainterPath &path);

        //QPainterPath shape() const Q_DECL_OVERRIDE;
        //bool contains(const QPointF &point) const Q_DECL_OVERRIDE;

        //------------------------------------------------------------------------------
        //      Reimplementation
        //------------------------------------------------------------------------------
        QRectF boundingRect() const Q_DECL_OVERRIDE;
        int type( void ) const Q_DECL_OVERRIDE;

        void paint( QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget = Q_NULLPTR ) Q_DECL_OVERRIDE;

        //------------------------------------------------------------------------------
        //      Reference to elements
        //------------------------------------------------------------------------------

        QRect &	                bbox( void )        { return _bbox; }
        const QRect &	        bbox( void ) const	{ return _bbox; }
	
	    unsigned long &	        attributeID( void )         { return _attributeID; }
	    const unsigned long &	attributeID( void ) const	{ return _attributeID; }
	
	    QBrush &	            defaultBrush( void )        { return _defaultBrush; }
	    const QBrush &	        defaultBrush( void ) const	{ return _defaultBrush; }
	    void                    settoDefaultBrush( void ) 	{ this->setBrush( _defaultBrush ); }
	
	    QPen &	                defaultPen( void )          { return _defaultPen; }
	    const QPen &	        defaultPen( void ) const	{ return _defaultPen; }
	    void                    settoDefaultPen( void ) 	{ this->setPen( _defaultPen ); }

	    QPolygonF               getPolygon() const {
            return polygon();
        }
	    
	    //------------------------------------------------------------------------------
	    //	Special functions
	    //------------------------------------------------------------------------------
	    void init( void ) { _init(); }
    };

} // namespace Vector
} // namespace Ui

#endif // Ui_Vector_GraphicsPolygonItem_H
