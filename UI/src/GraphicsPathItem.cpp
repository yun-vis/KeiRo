//******************************************************************************
// GraphicsEdgeItem.cpp
//	: program file for edge items
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Jun 19 02:36:37 2019
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include "GraphicsPathItem.h"


namespace Ui {
namespace Vector {

    //------------------------------------------------------------------------------
    //	Private functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected functions
    //------------------------------------------------------------------------------
	//
	//  GraphicsEdgeItem::init -- initialization
	//
	//  Inputs
	//  none
	//
	//  Outputs
	//  none
	//
	void GraphicsPathItem::_init( void )
	{
		GraphicsBase::_init();
	}
	
	
    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------
    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  GraphicsBallItem::GraphicsBallItem -- constructor
    //
    //  Inputs
    //  parent: parent object
    //
    //  Outputs
    //  none
    //
    GraphicsPathItem::GraphicsPathItem( QGraphicsItem *parent )
    {
	    //setFlag( QGraphicsItem::ItemIsSelectable );
        //setFlag( QGraphicsItem::ItemIsMovable );
        //setFlag( QGraphicsItem::ItemSendsGeometryChanges );
        //setAcceptDrops( true );

        //pen().setJoinStyle( Qt::MiterJoin );
        pen().setJoinStyle( Qt::RoundJoin );
	
	    GraphicsBase::_init();
    }

    //
    //  GraphicsEdgeItem::GraphicsEdgeItem -- copy constructor
    //
    //  Inputs
    //  parent: parent object
    //
    //  Outputs
    //  none
    //
    GraphicsPathItem::GraphicsPathItem( const QPainterPath &path, QGraphicsItem *parent )
    {
        if ( !path.isEmpty() ) setPath( path );
    }

    //
    //  GraphicsEdgeItem::boundingRect -- find bounding box
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  reference to the bounding box
    //
    QRectF GraphicsPathItem::boundingRect( void ) const
    {
        return path().controlPointRect();
    }

    //
    //  GraphicsEdgeItem::paint -- paint the object
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void GraphicsPathItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option,
                                  QWidget *widget )
    {
        // draw boundary
        painter->setRenderHints( QPainter::Antialiasing );
        painter->setPen( pen() );
        painter->setBrush( brush() );
        painter->drawPath( path() );

        // draw text
        if( _textOn == true ){
            painter->setPen( _textpen );
            painter->setFont( _font );
            painter->drawText( path().boundingRect().x()+0.5*( path().boundingRect().width() ),
                               path().boundingRect().y()+0.5*( path().boundingRect().height() ),
                               _text );
        }

        //cerr << "paint x = " << pos().x() << " y = " << pos().y() << endl;

        // Qt function
        //if ( option->state & QStyle::State_Selected )
        //	qt_graphicsItem_highlightSelected( this, painter, option );
    }

    //
    //  GraphicsEdgeItem::paint -- find the object type
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  reference to the object type
    //
    int GraphicsPathItem::type( void ) const
    {
        return 0; // GRAPHICS_EDGE+QGraphicsItem::UserType;
    }


} // namespace Vector
} // namespace Ui