//******************************************************************************
// GraphicsPolygonItem.cpp
//	: program file for polygon items
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Jun 19 02:36:37 2019
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include "GraphicsPolygonItem.h"


namespace Ui {
namespace Vector {

    //------------------------------------------------------------------------------
    //	Private functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected functions
    //------------------------------------------------------------------------------
    //
    //  GraphicsPolygonItem::init -- initialization
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void GraphicsPolygonItem::_init( void )
    {
	    GraphicsBase::_init();
    }
	
	QVariant polygonInterpolator(const QPolygonF &start, const QPolygonF &end, qreal progress)
	{
//    	cerr << "progress = " << progress << endl;
//		cerr << "0 x = " << end[0].x() << " y = " << end[0].y() << endl;
//		cerr << "1 x = " << end[1].x() << " y = " << end[1].y() << endl;
		QPolygonF poly;
		for( unsigned int i = 0; i < start.size(); i++ ){
			QPointF p;
			p.setX( progress * end[i].x() + (1.0-progress) * start[i].x() );
			p.setY( progress * end[i].y() + (1.0-progress) * start[i].y() );
			poly.append( p );
		}

//		cerr << "size = " << poly.size() << endl;
		return poly;
	}
	
    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------
    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  GraphicsPolygonItem::GraphicsPolygonItem -- constructor
    //
    //  Inputs
    //  parent: parent object
    //
    //  Outputs
    //  none
    //
    GraphicsPolygonItem::GraphicsPolygonItem( QGraphicsItem *parent )
    {
	    qRegisterAnimationInterpolator< QPolygonF >( polygonInterpolator );
    	
        setFlag( QGraphicsItem::ItemIsSelectable );
        setFlag( QGraphicsItem::ItemIsMovable );
        setFlag( QGraphicsItem::ItemSendsGeometryChanges );
        //setAcceptDrops( true );

        //pen().setJoinStyle( Qt::MiterJoin );
        pen().setJoinStyle( Qt::RoundJoin );
    }
    
    //
    //  GraphicsPolygonItem::boundingRect -- find bounding box
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  reference to the bounding box
    //
    QRectF GraphicsPolygonItem::boundingRect( void ) const
    {
#ifdef GRAPHICSPOLYGONITEM_DEBUG
        cerr << "id = " << _id
             << setw(10 )<< " bx = " << polygon().boundingRect().x()
             << setw(10 )<< " by = " << polygon().boundingRect().y()
             << setw(10 )<< " bw = " << polygon().boundingRect().width()
             << setw(10 )<< " bh = " << polygon().boundingRect().height()
             << endl;
#endif // GRAPHICSPOLYGONITEM_DEBUG
        return polygon().boundingRect();
    }

    //
    //  GraphicsPolygonItem::paint -- paint scene
    //
    //  Inputs
    //  painter: Qpainter
    //  option: QStyleOptionGraphicsItem
    //  widget: QWidget
    //
    //  Outputs
    //  none
    //
    void GraphicsPolygonItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option,
                                     QWidget *widget )
    {
        QFontMetrics metrics( _font );
        double sx = metrics.width( _text );
        double sy = 0.5*metrics.height();

        // draw boundary
        painter->setRenderHints( QPainter::Antialiasing );
        painter->setPen( pen() );
        painter->setBrush( brush() );
	    painter->drawPolygon( polygon() );

	    double minX = INFINITY, maxX = -INFINITY;
	    double minY = INFINITY, maxY = -INFINITY;
	    for( unsigned int i = 0; i < polygon().size(); i++ ){
			if( minX > polygon()[i].x() ) minX = polygon()[i].x();
		    if( maxX < polygon()[i].x() ) maxX = polygon()[i].x();
		    if( minY > polygon()[i].y() ) minY = polygon()[i].y();
		    if( maxY < polygon()[i].y() ) maxY = polygon()[i].y();
	    }
	    
	    QPointF p( 0.5*(minX+maxX), 0.5*(minY+maxY) );
        if( _textOn == true ){

            painter->setPen( _textpen );
#ifdef SKIP
            for( unsigned int i = 0; i < p.size(); i++ ){
                painter->drawText( p.at(i).x()+5, p.at(i).y()-5, QString::fromStdString( to_string( _id ) ) );
            }
#endif // SKIP

	        painter->drawText( p.x() - 0.5 * sx, p.y() + 0.5 * sy, _text );
//            painter->drawText(
//                    _bbox.x() + 0.5 * _bbox.width() - 0.5 * sx,
//                    -_bbox.y() - 0.5 * _bbox.height() + 0.5 * sy,
//                    _text
//                    );
        }

        //cerr << "paint x = " << pos().x() << " y = " << pos().y() << endl;
        // Qt function
        //if ( option->state & QStyle::State_Selected )
        //	qt_graphicsItem_highlightSelected( this, painter, option );
    }

    //
    //  GraphicsPolygonItem::type -- find type
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  reference to the type of the object
    //
    int GraphicsPolygonItem::type( void ) const
    {
        return 0; //GRAPHICS_POLYGON+QGraphicsItem::UserType;
    }

} // namespace Vector
} // namespace Ui