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

#include "GraphicsEdgeItem.h"


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
	void GraphicsEdgeItem::_init( void )
	{
		GraphicsBase::_init();
	}
	
	QVariant pathInterpolator(const QLineF &start, const QLineF &end, qreal progress )
	{
//    	cerr << "progress = " << progress << endl;
//		cerr << "0 x = " << end[0].x() << " y = " << end[0].y() << endl;
//		cerr << "1 x = " << end[1].x() << " y = " << end[1].y() << endl;
//		QLineF line;
//		for( unsigned int i = 0; i < start.size(); i++ ){
		QPointF p1, p2;
		
		p1.setX( progress * end.p1().x() + (1.0-progress) * start.p1().x() );
		p1.setY( progress * end.p1().y() + (1.0-progress) * start.p1().y() );
		p2.setX( progress * end.p2().x() + (1.0-progress) * start.p2().x() );
		p2.setY( progress * end.p2().y() + (1.0-progress) * start.p2().y() );
//		line = QLineF( p1, p2 );
//			poly.append( p );
//		}

//		cerr << "size = " << poly.size() << endl;
		return  QLineF( p1, p2 );
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
    GraphicsEdgeItem::GraphicsEdgeItem( QGraphicsItem *parent )
    {
	    qRegisterAnimationInterpolator< QLineF >( pathInterpolator );
	
	    //setFlag( QGraphicsItem::ItemIsSelectable );
        //setFlag( QGraphicsItem::ItemIsMovable );
        //setFlag( QGraphicsItem::ItemSendsGeometryChanges );
        //setAcceptDrops( true );

//        pen().setJoinStyle( Qt::MiterJoin );
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
    GraphicsEdgeItem::GraphicsEdgeItem( const QLineF &line, QGraphicsItem *parent )
    {
        setLine( line );
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
//    QRectF GraphicsEdgeItem::boundingRect( void ) const
//    {
//        return line().controlPointRect();
//    }

    //
    //  GraphicsEdgeItem::paint -- paint the object
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void GraphicsEdgeItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option,
                                  QWidget *widget )
    {
        // draw boundary
        painter->setRenderHints( QPainter::Antialiasing );
        painter->setPen( pen() );
//        painter->setBrush( brush() );
//        painter->drawPath( path() );
        painter->drawLine( line() );

        // draw text
//        if( _textOn == true ){
//            painter->setPen( _textpen );
//            painter->setFont( _font );
//            painter->drawText( path().boundingRect().x()+0.5*( path().boundingRect().width() ),
//                               path().boundingRect().y()+0.5*( path().boundingRect().height() ),
//                               _text );
//        }

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
    int GraphicsEdgeItem::type( void ) const
    {
        return 0; // GRAPHICS_EDGE+QGraphicsItem::UserType;
    }


} // namespace Vector
} // namespace Ui