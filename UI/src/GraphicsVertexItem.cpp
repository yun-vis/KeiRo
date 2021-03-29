//******************************************************************************
// GraphicsVertexItem.cpp
//	: program file for vertex items
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Jun 19 02:36:37 2019
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include "GraphicsVertexItem.h"

namespace Ui {
namespace Vector {

    //------------------------------------------------------------------------------
    //	Private functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected functions
    //------------------------------------------------------------------------------
    //
    //  GraphicsVertexItem::init -- initialization
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void GraphicsVertexItem::_init( void ) {
	
	    GraphicsBase::_init();
	    _radius = 10;
	    _isSimple = false;
    }
    
    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------
    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  GraphicsVertexItem::GraphicsVertexItem -- constructor
    //
    //  Inputs
    //  parent: parent object
    //
    //  Outputs
    //  none
    //
    GraphicsVertexItem::GraphicsVertexItem( QGraphicsItem *parent )
    {
        //setFlag( QGraphicsItem::ItemIsSelectable );
        //setFlag( QGraphicsItem::ItemIsMovable );
        //setFlag( QGraphicsItem::ItemSendsGeometryChanges );
        //setAcceptDrops( true );

	    _init();
    }

    //
    //  GraphicsVertexItem::GraphicsVertexItem -- parameterized constructor
    //
    //  Inputs
    //  parent: parent object
    //
    //  Outputs
    //  none
    //
    GraphicsVertexItem::GraphicsVertexItem( qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent )
    {
        setRect( QRectF( x, y, w, h ) );
    }

    //
    //  GraphicsVertexItem::GraphicsVertexItem -- copy constructor
    //
    //  Inputs
    //  parent: parent object
    //
    //  Outputs
    //  none
    //
    GraphicsVertexItem::GraphicsVertexItem( const QRectF &rect, QGraphicsItem *parent )
    {
        setRect( rect );
    }
    

    //
    //  GraphicsVertexItem::boundingRect -- find bounding box
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  reference to the bounding box
    //
    QRectF GraphicsVertexItem::boundingRect( void ) const
    {
        return rect();
    }

    //
    //  GraphicsVertexItem::paint -- paint the object
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void GraphicsVertexItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option,
                                    QWidget *widget )
    {
	    painter->setRenderHints( QPainter::Antialiasing );
	    painter->setPen( pen() );
	    painter->setBrush( brush() );

	    QRectF fineRect( rect() );
	    _radius = rect().width();
    	QFontMetrics fm( _font );
	    double sx = fm.width( _text );
	    double sy = 0.5*fm.height();
	    
    	if( _isSimple == true ){
		
		    double sx = _radius, sy = _radius;
		
		    fineRect.setX( rect().x() - 0.5 * sx );
		    fineRect.setY( rect().y() - 0.5 * sy );
//		    fineRect.setX( rect().x() - 0.5 * sx );
//		    fineRect.setY( rect().y() - 0.5 * sy );
		    fineRect.setWidth( sx );
		    fineRect.setHeight( sy );
		    _sourceRect = fineRect;
		    painter->drawEllipse( _sourceRect );
    	}
    	else{

		    fineRect.setX( rect().x() );
		    fineRect.setY( rect().y() );
		    fineRect.setWidth( rect().width() );
		    fineRect.setHeight( rect().height() );
		    _sourceRect = fineRect;
    		
		    painter->drawRoundedRect( _sourceRect, _radius, _radius, Qt::AbsoluteSize );
    	}
    	
        if( _textOn == true ) {
	        
	        painter->setFont( _font );
	        painter->setPen( _textpen );
	        painter->drawText(
			        _sourceRect.x() + 0.5 * _sourceRect.width() - 0.5 * sx,
			        _sourceRect.y() + 0.5 * _sourceRect.height() + 0.5 * sy,
			        _text
	        );
        }

        // Qt function
        //if ( option->state & QStyle::State_Selected )
        //	qt_graphicsItem_highlightSelected( this, painter, option );
        // cerr << "painting ball..." << endl;
    }

    //
    //  GraphicsVertexItem::type -- find type
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  reference to the type of the object
    //
    int GraphicsVertexItem::type( void ) const
    {
        return 0; //GRAPHICS_VERTEX+QGraphicsItem::UserType;
    }

} // namespace Vector
} // namespace Ui