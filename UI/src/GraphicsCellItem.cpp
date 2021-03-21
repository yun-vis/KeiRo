//******************************************************************************
// GraphicsCellItem.cpp
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

#include "GraphicsCellItem.h"

namespace Ui {
	namespace Vector {
		
		//------------------------------------------------------------------------------
		//	Private functions
		//------------------------------------------------------------------------------
		
		//------------------------------------------------------------------------------
		//	Protected functions
		//------------------------------------------------------------------------------
		//
		//  GraphicsCellItem::init -- initialization
		//
		//  Inputs
		//  none
		//
		//  Outputs
		//  none
		//
		void GraphicsCellItem::_init( void ) {
			
			GraphicsBase::_init();
		}
		
		//------------------------------------------------------------------------------
		//	Public functions
		//------------------------------------------------------------------------------
		//------------------------------------------------------------------------------
		//	Constructors & Destructors
		//------------------------------------------------------------------------------
		//
		//  GraphicsCellItem::GraphicsCellItem -- constructor
		//
		//  Inputs
		//  parent: parent object
		//
		//  Outputs
		//  none
		//
		GraphicsCellItem::GraphicsCellItem( QGraphicsItem *parent )
		{
			//setFlag( QGraphicsItem::ItemIsSelectable );
			//setFlag( QGraphicsItem::ItemIsMovable );
			//setFlag( QGraphicsItem::ItemSendsGeometryChanges );
			//setAcceptDrops( true );
			
			_init();
		}
		
		//
		//  GraphicsCellItem::GraphicsCellItem -- parameterized constructor
		//
		//  Inputs
		//  parent: parent object
		//
		//  Outputs
		//  none
		//
		GraphicsCellItem::GraphicsCellItem( qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent )
		{
			setRect( QRectF( x, y, w, h ) );
		}
		
		//
		//  GraphicsCellItem::GraphicsCellItem -- copy constructor
		//
		//  Inputs
		//  parent: parent object
		//
		//  Outputs
		//  none
		//
		GraphicsCellItem::GraphicsCellItem( const QRectF &rect, QGraphicsItem *parent )
		{
			setRect( rect );
		}
		
		
		//
		//  GraphicsCellItem::boundingRect -- find bounding box
		//
		//  Inputs
		//  none
		//
		//  Outputs
		//  reference to the bounding box
		//
		QRectF GraphicsCellItem::boundingRect( void ) const
		{
			return rect();
		}
		
		//
		//  GraphicsCellItem::paint -- paint the object
		//
		//  Inputs
		//  none
		//
		//  Outputs
		//  none
		//
		void GraphicsCellItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option,
		                                QWidget *widget )
		{
			Q_UNUSED(option)
			Q_UNUSED(widget)
			
			painter->setRenderHints( QPainter::Antialiasing );
			painter->setPen( pen() );
			painter->setBrush( brush() );
			//painter->drawRect( _sourceRect );
			painter->drawRoundedRect( _sourceRect, 1, 1);
			
			if( _textOn == true ) {
				QFontMetrics fm( _font );
				double sx = fm.width( _text );
				double sy = 0.5*fm.height();

				painter->setFont( _font );
				painter->setPen( _textpen );

				painter->drawText(
				    _sourceRect.x() + 0.5 * _sourceRect.width() - 0.5 * sx,
				    _sourceRect.y() + 0.5 * _sourceRect.height() + 0.5 * sy,
				    _text
				);
				//cerr << "id = " << _id << endl;
				//painter->drawText( rect().x()+10, rect().y()-10, QString::fromStdString( to_string( _id ) ) );
				//painter->drawText( rect().x()+0.5*( rect().width() ),
				                   //rect().y()+0.5*( rect().height() ), _text ); // (x ,y) must be left-upper corner
				//painter->drawText( fineRect.x()+0.5*( fineRect.width()-sx ) - 0.5*MIN_NEIGHBOR_DISTANCE,
				//                   fineRect.y()+0.5*( fineRect.height()+0.5*sy ) + MIN_NEIGHBOR_DISTANCE, _name );
				
				//cerr << "paint x = " << pos().x() << " y = " << pos().y() << endl;
			}
			
			// Qt function
			//if ( option->state & QStyle::State_Selected )
			//	qt_graphicsItem_highlightSelected( this, painter, option );
			// cerr << "painting ball..." << endl;
		}
		
		//
		//  GraphicsCellItem::type -- find type
		//
		//  Inputs
		//  none
		//
		//  Outputs
		//  reference to the type of the object
		//
		int GraphicsCellItem::type( void ) const
		{
			return 0; //GRAPHICS_VERTEX+QGraphicsItem::UserType;
		}
	
	} // namespace Vector
} // namespace Ui