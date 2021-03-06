//******************************************************************************
// GraphicsVertexItem.h
//	: header file for vertex items
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Jun 19 02:36:37 2019
//
//******************************************************************************

#ifndef Ui_Vector_GraphicsVertexItem_H
#define Ui_Vector_GraphicsVertexItem_H

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
#include <cassert>

using namespace std;

#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsItem>

#ifndef Q_MOC_RUN
#include "GraphicsBase.h"
#endif // Q_MOC_RUN


namespace Ui {
namespace Vector {

    //------------------------------------------------------------------------------
    //	Class definition
    //------------------------------------------------------------------------------
    class GraphicsVertexItem : public  QGraphicsRectItem, public GraphicsBase {
    
    private:

        double          _radius;
        bool            _isSimple;

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
        explicit GraphicsVertexItem( QGraphicsItem *parent = Q_NULLPTR );
        // parameterized constructor
        explicit GraphicsVertexItem( qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = Q_NULLPTR );
        // copy constructor
        explicit GraphicsVertexItem( const QRectF &rect, QGraphicsItem *parent = Q_NULLPTR );
        // destructor
        ~GraphicsVertexItem( void ) {}

        // source from the qt library
        //QRectF rect() const;
        //void setRect(const QRectF &rect);
        //inline void setRect(qreal x, qreal y, qreal w, qreal h);

        //QPainterPath shape() const Q_DECL_OVERRIDE;
        //bool contains(const QPointF &point) const Q_DECL_OVERRIDE;

        //bool isObscuredBy(const QGraphicsItem *item) const Q_DECL_OVERRIDE;
        //QPainterPath opaqueArea() const Q_DECL_OVERRIDE;

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
        bool &isSimple( void ) { return _isSimple; }
	
	    const bool &isSimple( void ) const { return _isSimple; }
	    
	    //------------------------------------------------------------------------------
	    //	Special functions
	    //------------------------------------------------------------------------------
	    void init( void ) { _init(); }

    private:

    };

} // namespace Vector
} // namespace Ui

#endif // Ui_Vector_GraphicsVertexItem_H
