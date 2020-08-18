//******************************************************************************
// GraphicsView.cpp
//	: program file for graphics view
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Jun 19 02:36:37 2019
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include "GraphicsBallItem.h"
#include "GraphicsEdgeItem.h"
#include "GraphicsView.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Ui {
	namespace Vector {
		
		//------------------------------------------------------------------------------
		//	Private functions
		//------------------------------------------------------------------------------
		//
		//  GraphicsView::_init -- initialize data
		//
		//  Inputs
		//  none
		//
		//  Outputs
		//  none
		//
		void GraphicsView::_init( void )
		{
		}
		
		//
		//  GraphicsView::_clear -- clear data
		//
		//  Inputs
		//  none
		//
		//  Outputs
		//  none
		//
		void GraphicsView::_clear( void )
		{
		}

		
		//------------------------------------------------------------------------------
		//	Protected functions
		//------------------------------------------------------------------------------
		//
		//  GraphicsView::_item_metro -- draw metro
		//
		//  Inputs
		//  none
		//
		//  Outputs
		//  none
		//
		void GraphicsView::_item_data( void )
		{
		}
		
		//
		//  GraphicsView::_item_metro -- update metro
		//
		//  Inputs
		//  none
		//
		//  Outputs
		//  none
		//
		void GraphicsView::_update_item_data( void )
		{
		}
		
		//------------------------------------------------------------------------------
		//	Public functions
		//------------------------------------------------------------------------------
		
		//------------------------------------------------------------------------------
		//	Constructors & Destructors
		//------------------------------------------------------------------------------
		//
		//  GraphicsView::GraphicsView -- constructor
		//
		//  Inputs
		//  none
		//
		//  Outputs
		//  none
		//
		GraphicsView::GraphicsView( QWidget *parent )
				: QGraphicsView( parent ) {
			//------------------------------------------------------------------------------
			// configuration file
			//------------------------------------------------------------------------------
//			string configFilePath = qApp->applicationDirPath().toStdString() + "/config/MainWindow.conf";
//			Base::Config conf( configFilePath );
			_basePtr = nullptr;
			_scenePtr = new QGraphicsScene;
            _scenePtr->setSceneRect( -KeiRo::Base::Common::getMainwidgetWidth() / 2.0, -KeiRo::Base::Common::getMainwidgetHeight() / 2.0,
                                     KeiRo::Base::Common::getMainwidgetWidth(), KeiRo::Base::Common::getMainwidgetHeight() );  // x, y, w, h
			cerr << "mainwidget_width = " << KeiRo::Base::Common::getMainwidgetWidth() << endl;
			cerr << "mainwidget_height = " << KeiRo::Base::Common::getMainwidgetHeight() << endl;
			cerr << "dockwidget_width = " << KeiRo::Base::Common::getDockWidgetWidth() << endl;

			this->setScene( _scenePtr );
		}
		

		//------------------------------------------------------------------------------
		//	Event handlers
		//------------------------------------------------------------------------------
		void GraphicsView::simulateKey( Qt::Key key ) {

			// press the key
			QKeyEvent eventP( QEvent::KeyPress, key, Qt::NoModifier );
			QApplication::sendEvent( this, &eventP );
			// release the key
			QKeyEvent eventR( QEvent::KeyRelease, key, Qt::NoModifier );
			QApplication::sendEvent( this, &eventR );
		}
		
		//
		//  GraphicsView::keyPressEvent -- key press event
		//
		//  Inputs
		//  event: key event
		//
		//  Outputs
		//  none
		//
		void GraphicsView::keyPressEvent( QKeyEvent *event )
		{
			switch( event->key() ) {

                case Qt::Key_L: {
                    break;
                }
                default: {
                    // QWidget::keyPressEvent( event );
                    // QGraphicsView::keyPressEvent( event );
                    break;
                }
			}
			
			QGraphicsView::keyPressEvent( event );
			updateSceneItems();
		}
		
		//
		//  GraphicsView::mousePressEvent -- mouse press event
		//
		//  Inputs
		//  event: mouse event
		//
		//  Outputs
		//  none
		//
		void GraphicsView::mousePressEvent( QMouseEvent *event ) {

			QPointF coord = mapToScene( event->pos() );
			// centerOn( coord.x(), coord.y() );
			
			//QPainterPath selectionArea;
			double square = 10.0;
//			_selectionArea.clear();
//			_selectionArea.addPolygon( mapToScene(
//					QRect( event->pos().x() - square / 2.0, event->pos().y() - square / 2.0, square, square ) ) );
//			_selectionArea.closeSubpath();
//
//			_scenePtr->setSelectionArea( _selectionArea, this->rubberBandSelectionMode() ); //, viewportTransform() );
			
			switch( event->buttons() ) {
			
			case Qt::RightButton:
				break;
			case Qt::LeftButton:
				break;
			case Qt::MiddleButton:
				break;
			default: {
				break;
			}
			}
			
			QGraphicsView::mousePressEvent( event );

#ifdef GRAPHICSVIEW_DEBUG
			cerr << "mouse pressing..." << endl
				 << " x = " << event->pos().x() << " y = " << event->pos().y() << endl
				 << " sx = " << coord.x() << " sy = " << coord.y() << endl;
			cerr << "_right_button_pressed = " << _right_button_pressed << endl
				 << "_left_button_pressed = " << _left_button_pressed << endl
				 << "_middle_button_pressed = " << _middle_button_pressed << endl;
#endif // GRAPHICSVIEW_DEBUG
		}
		
		//
		//  GraphicsView::mouseMoveEvent -- mouse move event
		//
		//  Inputs
		//  event: mouse event
		//
		//  Outputs
		//  none
		//
		void GraphicsView::mouseMoveEvent( QMouseEvent *event ) {
//			_cursor = QPoint( event->pos().x() - Base::Common::getMainwidgetWidth() / 2,
//			                  -( event->pos().y() - Base::Common::getMainwidgetHeight() / 2 ) );
			double norm = QLineF( _cursor, _oldCursor ).length();
			
			// static int test = 0;
			
			if( norm > 1.0 * _min_point_distance ) {
				simulateKey( Qt::Key_Z );

#ifdef GRAPHICSVIEW_DEBUG
				// sleep( 3 );
				test = test+1;
				cerr << "#######################" << endl;
				cerr << "norm = " << norm << endl;
				cerr << "Moving mouse ... " << endl;
				cerr << test << ", className = " << className() << endl;
				cerr << "_oldCursor = " << _oldCursor.x() << ", " << _oldCursor.y() << endl;
				cerr << "_cursor = " << _cursor.x() << ", " << _cursor.y() << endl;
				cerr << "norm = " << norm << endl;
#endif // GRAPHICSVIEW_DEBUG
				_oldCursor = _cursor;
			}
			QGraphicsView::mouseMoveEvent( event );
		}
		
		//
		//  GraphicsView::mouseReleaseEvent -- mouse release event
		//
		//  Inputs
		//  event: mouse event
		//
		//  Outputs
		//  none
		//
		void GraphicsView::mouseReleaseEvent( QMouseEvent *event ) {
			_right_button_pressed = false;
			_left_button_pressed = false;
			_middle_button_pressed = false;
			
			QGraphicsView::mouseReleaseEvent( event );

#ifdef GRAPHICSVIEW_DEBUG
			cerr << "Releasing mouse ..." << endl;
			cerr << "_right_button_pressed = " << _right_button_pressed << endl
				 << "_left_button_pressed = " << _left_button_pressed << endl
				 << "_middle_button_pressed = " << _middle_button_pressed << endl;
#endif // GRAPHICSVIEW_DEBUG
		}
		
		
		//------------------------------------------------------------------------------
		//	Special functions
		//------------------------------------------------------------------------------
		//
		//  GraphicsView::initSceneItems -- initialize SceneItems
		//
		//  Inputs
		//  none
		//
		//  Outputs
		//  none
		//
		void GraphicsView::initSceneItems( void ) {
			// initialization
			_scenePtr->clear();
//			_updateVisibility();
			
//			if( _update_doimap_flag == true ) {
//				_item_doimap();
//				_updateDOIMap();
//				this->setScene( _scenePtr );
//				_update_doimap_flag = !_update_doimap_flag;
//			}
			
//			if( _is_polygonFlag == true ) _item_polygons();
//			if( _is_polylineFlag == true ) _item_polylines();
//			if( _is_gridFlag == true ) {
//				// _item_grid();
//				_item_nestedgrid();
//			}

            _item_data();
#ifdef DEBUG
			cerr << "_scene.size = " << _scene->items().size() << endl;
#endif // DEBUG
		}
		
		//
		//  GraphicsView::updateSceneItems -- initialize SceneItems
		//
		//  Inputs
		//  none
		//
		//  Outputs
		//  none
		//
		void GraphicsView::updateSceneItems( void ) {
//			if( _update_doimap_flag == true ) {
//				_item_doimap();
//				_updateDOIMap();
//				this->setScene( _scenePtr );
//				_update_doimap_flag = !_update_doimap_flag;
//			}
//
//			if( _is_polygonFlag == true ) _update_item_polygons();
//			if( _is_polylineFlag == true ) _update_item_polylines();
//			if( _is_gridFlag == true ) _update_item_nestedgrid();
			scene()->update();

#ifdef DEBUG
			cerr << "_scene.size = " << _scene->items().size() << endl;
#endif // DEBUG
		}
		
		//
		//  GraphicsView::exportPNG -- export png
		//
		//  Inputs
		//  x, y, w, h: center, width, height
		//
		//  Outputs
		//  none
		//
		void GraphicsView::exportPNG( double x, double y, double w, double h ) {
			// Take file path and name that will create
			//QString newPath = QFileDialog::getSaveFileName(this, trUtf8("Save SVG"),
			//                                               path, tr("SVG files (*.svg)"));
			static int id = 0;
			ostringstream ss;
			ss << setw( 8 ) << std::setfill( '0' ) << id;
			string s2( ss.str() );
			QString idStr = QString::fromStdString( s2 );
			// cerr << "s2 = " << s2 << endl;
			QString newPath =
					QString( QLatin1String( "../png/pathway-" ) ) + idStr + QString( QLatin1String( ".png" ) );
			_scenePtr->setSceneRect( x, y, w, h );  // x, y, w, h
			
			if( newPath.isEmpty() ) return;
			
			QImage screenshot( w, h, QImage::Format_RGB32 ); // maximum 32767x32767
			
			//int dpm = 300 / 0.0254; // ~300 DPI
			//screenshot.setDotsPerMeterX( dpm );
			//screenshot.setDotsPerMeterY( dpm );
			
			QPainter painter( &screenshot );
			painter.setRenderHint( QPainter::Antialiasing );
			painter.fillRect( 0, 0, w, h, Qt::white );
			_scenePtr->render( &painter );
			screenshot.save( newPath );
			
			id++;
		}
		
		//
		//  GraphicsView::exportSVG -- export svg
		//
		//  Inputs
		//  x, y, w, h: center, width, height
		//
		//  Outputs
		//  none
		//
		void GraphicsView::exportSVG( double x, double y, double w, double h ) {
		
//			// Take file path and name that will create
//			//QString newPath = QFileDialog::getSaveFileName(this, trUtf8("Save SVG"),
//			//                                               path, tr("SVG files (*.svg)"));
//			static int id = 0;
//			ostringstream ss;
//			ss << setw( 8 ) << std::setfill( '0' ) << id;
//			string s2( ss.str() );
//			QString idStr = QString::fromStdString( s2 );
//			// cerr << "s2 = " << s2 << endl;
//			QString newPath =
//					QString( QLatin1String( "../svg/pathway-" ) ) + idStr + QString( QLatin1String( ".svg" ) );
//			_scenePtr->setSceneRect( x, y, w, h );  // x, y, w, h
//
//			if( newPath.isEmpty() ) return;
//
//			QSvgGenerator generator;            // Create a file generator object
//			generator.setFileName( newPath );    // We set the path to the file where to save vector graphics
//			generator.setSize(
//					QSize( w, h ) );  // Set the dimensions of the working area of the document in millimeters
//			generator.setViewBox( QRect( 0, 0, w, h ) ); // Set the work area in the coordinates
//			generator.setTitle( trUtf8( "SVG Example" ) );                                // The title document
//			generator.setDescription( trUtf8( "File created by SVG Example" ) );
//
//			QPainter painter;
//			painter.begin( &generator );
//			_scenePtr->render( &painter );
//			painter.end();
//
//			id++;
		}
		
	} // namespace Vector
} // namespace Ui