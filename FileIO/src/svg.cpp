//******************************************************************************
// svg.cpp
//	: program file svg
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sat Mar 7 15:02:45 2020
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include "svg.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace FileIO {

    //------------------------------------------------------------------------------
    //	Private Static Variables
    //------------------------------------------------------------------------------
    int SVG::_curveDownSample = 2;

    //------------------------------------------------------------------------------
    //	Private Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Public Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  SVG::SVG --	constructor
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    SVG::SVG( void )
    {
    }

    //
    //  SVG::SVG --	copy constructor
    //
    //  Input
    //	none
    //
    //  Output
    //	none
    //
    SVG::SVG( const SVG & v )
    {
	    _id                 = v._id;
	    _attributeID        = v._attributeID;
	
	    // glyphs in SVG
	    _polygonVec         = v._polygonVec;
	    // arcs in SVG
	    _polylineVec        = v._polylineVec;
	
	    _gridPtr            = v._gridPtr;
	
	    _svgCanvas          = v._svgCanvas;
		_screenCanvas       = v._screenCanvas;
		_compressionGrid    = v._compressionGrid;
    }

    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    void SVG::_init( Grid2 * __gridPtr, double __x, double __y, int __width, int __height )
    {
        _gridPtr    = __gridPtr;
        _screenCanvas = KeiRo::Base::Rectangle2( __x, __y, __width, __height );
//		double ww = KeiRo::Base::Common::getMainwidgetWidth();
//	    double wh = KeiRo::Base::Common::getMainwidgetHeight();
//	    _screenCanvas = KeiRo::Base::Rectangle2( 0.0, 0.0, ww, wh );
     
//	    cerr << "initializing SVG file..." << endl;
    }

    //
    //  SVG::getPolygonElements --	get polygon elements
    //
    //  Inputs
    //	string: file name
    //
    //  Outputs
    //	none
    //
    void SVG::getPolygonElements( const QString fileName )
    {
        // document object
        QDomDocument doc;
        // Open your SVG-file
        QFile file( fileName );

        // If it is not opened, or have failed to transmit the contents in QDocDocument
        if ( !file.open( QIODevice::ReadOnly ) || !doc.setContent( &file ) ) {
            // the refund list, but empty
            cerr << "something is wrong here... at " << __LINE__ << " in " << __FILE__ << endl;
            return;
        }

        // get rectangles
        QDomNodeList rectList = doc.elementsByTagName( "polygon" );
        for( unsigned int i = 0; i < rectList.size(); i++ ) {

            // Select from the node list
            QDomNode gNode = rectList.item( i );
            // QDomElement rectangle = gNode.firstChildElement("rect" );
            QDomElement gElement = gNode.toElement();

            // element id
            QString id = gElement.attribute( "id" );
#ifdef SVG_DEBUG
            cerr << "id = " << id.toStdString() << endl;
#endif // SVG_DEBUG

            // element style -- InkScape
            vector< unsigned int > fill( 4 );
            fill[0] = fill[1] = fill[2] = 200;
            fill[3] = 255;
            vector< unsigned int > stroke( 4 );
            stroke[0] = stroke[1] = stroke[2] = 100;
            stroke[3] = 255;
            QStringList styles = gElement.attribute( "style" ).split( ";" );
            for( unsigned int j = 0; j < styles.size(); j++ ){

                QStringList type = styles.at( j ).split( ":" );
                if( type.at(0).toStdString() == "fill" ){
                    QColor c( type.at(1) );
                    fill[0] = c.red();
                    fill[1] = c.green();
                    fill[2] = c.blue();
                    fill[3] = 255;
#ifdef SVG_DEBUG
                    cerr << "color = " << c.red() << ", " << c.green() << ", " << c.blue() << endl;
                    cerr << "fill = " << fill[0] << ", "<< fill[1] << ", " << fill[2] << ", " << fill[3] << endl;
#endif // SVG_DEBUG
                }
                if( type.at(0).toStdString() == "stroke" ){
                    QColor c( type.at(1) );
                    stroke[0] = c.red();
                    stroke[1] = c.green();
                    stroke[2] = c.blue();
                    stroke[3] = 255;
#ifdef SVG_DEBUG
                    cerr << "color = " << c.red() << ", " << c.green() << ", " << c.blue() << endl;
                    cerr << "stroke = " << stroke[0] << ", "<< stroke[1] << ", " << stroke[2] << ", " << stroke[3] << endl;
#endif // SVG_DEBUG
                }
            }

            // element style -- illustrator
            QString strFill = gElement.attribute( "fill" );
            if( strFill == "" ){
                // cerr << "no AI fill information" << endl;
            }
            else if( strFill.size() > 0 ){
                QColor c( strFill );
                fill[0] = c.red();
                fill[1] = c.green();
                fill[2] = c.blue();
                fill[3] = 255;
#ifdef SVG_DEBUG
                cerr << "strFill = " << strFill.toStdString() << endl;
                cerr << "fill = " << fill[0] << ", "<< fill[1] << ", " << fill[2] << ", " << fill[3] << endl;
#endif // SVG_DEBUG
            }

            QString strStroke = gElement.attribute( "stroke" );
            if( strStroke.size() == 0 ){
                // cerr << "no AI stroke information" << endl;
            }
            else if( strStroke.size() > 0 ){
                QColor c( strStroke );
                stroke[0] = c.red();
                stroke[1] = c.green();
                stroke[2] = c.blue();
                stroke[3] = 255;
#ifdef SVG_DEBUG
                cerr << "strStroke = " << strStroke.toStdString() << endl;
                cerr << "stroke = " << stroke[0] << ", "<< stroke[1] << ", " << stroke[2] << ", " << stroke[3] << endl;
#endif // SVG_DEBUG
            }

            // element position, width, and height
            QStringList points = gElement.attribute( "points" ).split( " " );

            // create rectangle
	        KeiRo::Base::Polygon2 polygon;
            polygon.name() = id.toStdString();
            polygon.fill() = fill;
            polygon.stroke() = stroke;

            // add polygon contour
            for( unsigned int j = 0; j < points.size(); j++ ){

                // cerr << " points = " << points.at( j ).toStdString() << endl;
                QStringList coords = points.at( j ).split( "," );
                if( coords.size() == 2 ){
                    double x = coords.at( 0 ).toDouble();
                    double y = -coords.at( 1 ).toDouble();
                    polygon.elements().push_back( KeiRo::Base::Coord2( x, y ) );
                }
            }

            polygon.fixedElements() = polygon.elements();
	        polygon.update();
            _polygonVec.push_back( polygon );

#ifdef SVG_DEBUG
            cerr << "id = " << id.toStdString()
                 << ", points = " << gElement.attribute( "points" ).toStdString() << endl;
#endif // SVG_DEBUG
        }

        file.close();
    }

    //
    //  SVG::getCircleElements --	get circle elements
    //
    //  Inputs
    //	string: file name
    //
    //  Outputs
    //	none
    //
    void SVG::getCircleElements( const QString fileName )
    {
        // document object
        QDomDocument doc;
        // Open your SVG-file
        QFile file( fileName );

        // If it is not opened, or have failed to transmit the contents in QDocDocument
        if ( !file.open( QIODevice::ReadOnly ) || !doc.setContent( &file ) ) {
            // the refund list, but empty
            cerr << "something is wrong here... at " << __LINE__ << " in " << __FILE__ << endl;
            return;
        }

        // get rectangles
        QDomNodeList rectList = doc.elementsByTagName( "circle" );
        for( unsigned int i = 0; i < rectList.size(); i++ ) {

            // Select from the node list
            QDomNode gNode = rectList.item( i );
            // QDomElement rectangle = gNode.firstChildElement("rect" );
            QDomElement gElement = gNode.toElement();

            // element id
            QString id = gElement.attribute( "id" );
#ifdef SVG_DEBUG
            cerr << "id = " << id.toStdString() << endl;
#endif // SVG_DEBUG

            // element style -- InkScape
            vector< unsigned int > fill( 4 );
            fill[0] = fill[1] = fill[2] = 200;
            fill[3] = 255;
            vector< unsigned int > stroke( 4 );
            stroke[0] = stroke[1] = stroke[2] = 100;
            stroke[3] = 255;
            QStringList styles = gElement.attribute( "style" ).split( ";" );
            for( unsigned int j = 0; j < styles.size(); j++ ){

                QStringList type = styles.at( j ).split( ":" );
                if( type.at(0).toStdString() == "fill" ){
                    QColor c( type.at(1) );
                    fill[0] = c.red();
                    fill[1] = c.green();
                    fill[2] = c.blue();
                    fill[3] = 255;
#ifdef SVG_DEBUG
                    cerr << "color = " << c.red() << ", " << c.green() << ", " << c.blue() << endl;
                    cerr << "fill = " << fill[0] << ", "<< fill[1] << ", " << fill[2] << ", " << fill[3] << endl;
#endif // SVG_DEBUG
                }
                if( type.at(0).toStdString() == "stroke" ){
                    QColor c( type.at(1) );
                    stroke[0] = c.red();
                    stroke[1] = c.green();
                    stroke[2] = c.blue();
                    stroke[3] = 255;
#ifdef SVG_DEBUG
                    cerr << "color = " << c.red() << ", " << c.green() << ", " << c.blue() << endl;
                    cerr << "stroke = " << stroke[0] << ", "<< stroke[1] << ", " << stroke[2] << ", " << stroke[3] << endl;
#endif // SVG_DEBUG
                }
            }

            // element style -- illustrator
            QString strFill = gElement.attribute( "fill" );
            if( strFill == "" ){
                // cerr << "no AI fill information" << endl;
            }
            else if( strFill.size() > 0 ){
                QColor c( strFill );
                fill[0] = c.red();
                fill[1] = c.green();
                fill[2] = c.blue();
                fill[3] = 255;
#ifdef SVG_DEBUG
                cerr << "strFill = " << strFill.toStdString() << endl;
                cerr << "fill = " << fill[0] << ", "<< fill[1] << ", " << fill[2] << ", " << fill[3] << endl;
#endif // SVG_DEBUG
            }

            QString strStroke = gElement.attribute( "stroke" );
            if( strStroke.size() == 0 ){
                // cerr << "no AI stroke information" << endl;
            }
            else if( strStroke.size() > 0 ){
                QColor c( strStroke );
                stroke[0] = c.red();
                stroke[1] = c.green();
                stroke[2] = c.blue();
                stroke[3] = 255;
#ifdef SVG_DEBUG
                cerr << "strStroke = " << strStroke.toStdString() << endl;
                cerr << "stroke = " << stroke[0] << ", "<< stroke[1] << ", " << stroke[2] << ", " << stroke[3] << endl;
#endif // SVG_DEBUG
            }

            // element position, width, and height
            double r = gElement.attribute( "r" ).toDouble();
            double x = gElement.attribute( "cx" ).toDouble();
            double y = -gElement.attribute( "cy" ).toDouble();

            // create rectangle
	        KeiRo::Base::Polygon2 polygon;
            polygon.name() = id.toStdString();
            polygon.fill() = fill;
            polygon.stroke() = stroke;
            polygon.boundingBox().leftBottom().x() = x-r;
            polygon.boundingBox().leftBottom().y() = y-r;
	        polygon.boundingBox().updateOldElement();
	        
            // add polygon contour
            const int nDiv = 10;
            for ( int k = 0; k <= nDiv; k++ ) {
            }
            for( unsigned int j = 0; j < nDiv; j++ ){
                double theta = 2.0*M_PI*(double)j / (double)nDiv;
                polygon.elements().push_back( KeiRo::Base::Coord2( x + r*cos( theta ), y + r*sin( theta ) ) );
            }
            polygon.fixedElements() = polygon.elements();
            _polygonVec.push_back( polygon );

#ifdef SVG_DEBUG
            cerr << "id = " << id.toStdString()
                 << ", cx = " << x
                 << " cy = " << y << " r = " << r << endl;
#endif // SVG_DEBUG
        }

        file.close();
    }
    
    //
    //  SVG::getRectangleElements --	get rectangle elements
    //
    //  Inputs
    //	string: file name
    //
    //  Outputs
    //	none
    //
    void SVG::getRectangleElements( const QString fileName )
    {
        // document object
        QDomDocument doc;
        // Open your SVG-file
        QFile file( fileName );

        // If it is not opened, or have failed to transmit the contents in QDocDocument
        if ( !file.open( QIODevice::ReadOnly ) || !doc.setContent( &file ) ) {
            // the refund list, but empty
            cerr << "something is wrong here... at " << __LINE__ << " in " << __FILE__ << endl;
            return;
        }

        // get rectangles
        QDomNodeList rectList = doc.elementsByTagName( "rect" );
        for( unsigned int i = 0; i < rectList.size(); i++ ) {

            // Select from the node list
            QDomNode gNode = rectList.item( i );
            // QDomElement rectangle = gNode.firstChildElement("rect" );
            QDomElement gElement = gNode.toElement();

            // element id
            QString id = gElement.attribute( "id" );
	        QString label = gElement.attribute( "label" );

#ifdef SVG_DEBUG
            cerr << "label = " << label.toStdString() << endl;
#endif // SVG_DEBUG

            // element style -- InkScape
            vector< unsigned int > fill( 4 );
            vector< unsigned int > stroke( 4 );
	        double strokeWidth = 0.0;
	        double strokeOpacity = 0.0;
            QStringList styles = gElement.attribute( "style" ).split( ";" );
            for( unsigned int j = 0; j < styles.size(); j++ ){

                QStringList type = styles.at( j ).split( ":" );
                if( type.at(0).toStdString() == "fill" ){
                    QColor c( type.at(1) );
                    fill[0] = c.red();
                    fill[1] = c.green();
                    fill[2] = c.blue();
#ifdef SVG_DEBUG
                    cerr << "color = " << c.red() << ", " << c.green() << ", " << c.blue() << endl;
#endif // SVG_DEBUG
                }
	            if( type.at(0).toStdString() == "fill-opacity" ){
		            fill[3] = 255.0 * type.at(1).toDouble();
#ifdef SVG_DEBUG
		            cerr << "fill = " << fill[0] << ", "<< fill[1] << ", " << fill[2] << ", " << fill[3] << endl;
#endif // SVG_DEBUG
	            }
                if( type.at(0).toStdString() == "stroke" ){
                    QColor c( type.at(1) );
                    stroke[0] = c.red();
                    stroke[1] = c.green();
                    stroke[2] = c.blue();
                    stroke[3] = 255;
#ifdef SVG_DEBUG
                    cerr << "color = " << c.red() << ", " << c.green() << ", " << c.blue() << endl;
                    cerr << "stroke = " << stroke[0] << ", "<< stroke[1] << ", " << stroke[2] << ", " << stroke[3] << endl;
#endif // SVG_DEBUG
                }
	            if( type.at(0).toStdString() == "stroke-width" ){
		            strokeWidth = type.at(1).toDouble();
#ifdef SVG_DEBUG
		            cerr << "stroke-width = " << strokeWidth << endl;
#endif // SVG_DEBUG
                }
	            if( type.at(0).toStdString() == "stroke-opacity" ){
		            strokeOpacity = type.at(1).toDouble();
#ifdef SVG_DEBUG
		            cerr << "stroke-width = " << strokeWidth << endl;
#endif // SVG_DEBUG
	            }
            }

            // element position, width, and height
            double w = gElement.attribute( "width" ).toDouble();
            double h = gElement.attribute( "height" ).toDouble();
            double x = gElement.attribute( "x" ).toDouble();
            double y = -gElement.attribute( "y" ).toDouble();
			w = w * _screenCanvas.width()/_svgCanvas.width();
			h = h * _screenCanvas.height()/_svgCanvas.height();
	        x -= 0.5 * _svgCanvas.width();
 			y += 0.5 * _svgCanvas.height();
			x *= _screenCanvas.width()/_svgCanvas.width();
			y *= _screenCanvas.height()/_svgCanvas.height();
			
#ifdef DEBUG
	        cerr << "_screenCanvas.leftbottom = " << _screenCanvas.leftBottom();
			cerr << "_screenCanvas.width = " << _screenCanvas.width() << endl;
	        cerr << "_screenCanvas.height = " << _screenCanvas.height() << endl;
	        cerr << "_svgCanvas.leftbottom = " << _svgCanvas.leftBottom();
	        cerr << "_svgCanvas.width = " << _svgCanvas.width() << endl;
	        cerr << "_svgCanvas.height = " << _svgCanvas.height() << endl;
#endif // DEBUG

	        // create rectangle
	        KeiRo::Base::Polygon2 polygon;
            polygon.name() = id.toStdString();
            polygon.label() = label.toStdString();
            polygon.fill() = fill;
            polygon.stroke() = stroke;
	        polygon.strokeWidth() = strokeWidth;
//	        polygon.strokeOpacity() = strokeOpacity;

            int lbx = round( x );
            int lby = round( y );
            int rtx = round( x + w );
            int rty = round( y + h );

            x = lbx;
            y = lby;
            w = rtx - lbx;
            h = rty - lby;

            polygon.boundingBox().leftBottom().x() = x;
            polygon.boundingBox().leftBottom().y() = y-h;
            polygon.boundingBox().width() = w;
            polygon.boundingBox().height() = h;
	        
            // add polygon contour
            polygon.elements().push_back( KeiRo::Base::Coord2( x, y-h ) );
            polygon.elements().push_back( KeiRo::Base::Coord2( x, y ) );
            polygon.elements().push_back( KeiRo::Base::Coord2( x+w, y ) );
            polygon.elements().push_back( KeiRo::Base::Coord2( x+w, y-h ) );
            polygon.fixedElements() = polygon.elements();
            polygon.update();
	        polygon.boundingBox().updateOldElement();
            _polygonVec.push_back( polygon );

#ifdef SVG_DEBUG
            cerr << "read poly = " << polygon << endl;
	        KeiRo::Base::Rectangle2 &bbox = polygon.boundingBox();
//	        cerr << "old = " << bbox.oldLeftBottom();
//	        cerr << "ow = " << bbox.oldWidth() << endl;
	        cerr << "new = " << bbox.leftBottom();
	        cerr << " nw = " << bbox.width() << " nh = " << bbox.height() << endl;
            cerr << "id = " << id.toStdString()
                 << ", x = " << x << " y = " << y
                 << " w = " << w << " h = " << h << endl;
            cerr << "polygon = " << polygon << endl;
#endif // SVG_DEBUG
        }

        file.close();
    }

    //
    //  SVG::getPathElements --	get path elements
    //
    //  Inputs
    //	string: file name
    //
    //  Outputs
    //	none
    //
    void SVG::getPathElements( const QString fileName )
    {
        // document object
        QDomDocument doc;
        // Open your SVG-file
        QFile file( fileName );

        // If it is not opened, or have failed to transmit the contents in QDocDocument
        if ( !file.open( QIODevice::ReadOnly ) || !doc.setContent( &file ) ) {
            // the refund list, but empty
            cerr << "something is wrong here... at " << __LINE__ << " in " << __FILE__ << endl;
            return;
        }

        // get path
        QDomNodeList pathList = doc.elementsByTagName( "path" );

        // get path data
        for( unsigned int i = 0; i < pathList.size(); i++ ) {

            // Select from the node list
            QDomNode gNode = pathList.item( i );
            // QDomElement rectangle = gNode.firstChildElement("rect" );
            QDomElement gElement = gNode.toElement();

            // get if the path is closed or open
            bool isClosed = false;
            QStringList dList = gElement.attribute( "d" ).split(" " );
#ifdef SVG_DEBUG
            cerr << "dList.size() = " << dList.size() << endl;
#endif // SVG_DEBUG
            for( unsigned int j = 2; j < dList.size(); j++ ) {

                QStringList d = dList.at( j ).split( "," );
                if ( d.at( 0 ).toStdString() == "z" ) {
                    cerr << "The path is closed!" << endl;
                    isClosed = true;
                }
            }

            // element id
            QString id = gElement.attribute( "id" );
#ifdef SVG_DEBUG
            cerr << "id = " << id.toStdString() << endl;
#endif // SVG_DEBUG

            // element style
            vector< unsigned int > fill( 4 );
            vector< unsigned int > stroke( 4 );
	        double strokeWidth = 1.0;
	        double strokeOpacity = 1.0;
	        QStringList styles = gElement.attribute( "style" ).split( ";" );
            for( unsigned int j = 0; j < styles.size(); j++ ){

                QStringList type = styles.at( j ).split( ":" );
                if( type.at(0).toStdString() == "fill" ){
                    QColor c( type.at(1) );
                    fill[0] = c.red();
                    fill[1] = c.green();
                    fill[2] = c.blue();
#ifdef SVG_DEBUG
                    cerr << "color = " << c.red() << ", " << c.green() << ", " << c.blue() << endl;
                    cerr << "fill = " << fill[0] << ", "<< fill[1] << ", " << fill[2] << ", " << fill[3] << endl;
#endif // SVG_DEBUG
                }
	            if( type.at(0).toStdString() == "fill-opacity" ){
		            fill[3] = 255.0 * type.at(1).toDouble();
#ifdef SVG_DEBUG
		            cerr << "fill = " << fill[0] << ", "<< fill[1] << ", " << fill[2] << ", " << fill[3] << endl;
#endif // SVG_DEBUG
	            }
	            if( type.at(0).toStdString() == "stroke" ){
                    QColor c( type.at(1) );
                    stroke[0] = c.red();
                    stroke[1] = c.green();
                    stroke[2] = c.blue();
                    stroke[3] = 255;
#ifdef SVG_DEBUG
                    cerr << "color = " << c.red() << ", " << c.green() << ", " << c.blue() << endl;
                    cerr << "stroke = " << stroke[0] << ", "<< stroke[1] << ", " << stroke[2] << ", " << stroke[3] << endl;
#endif // SVG_DEBUG
                }
	            if( type.at(0).toStdString() == "stroke-width" ){
		            strokeWidth = type.at(1).toDouble();
#ifdef SVG_DEBUG
		            cerr << "stroke-width = " << strokeWidth << endl;
#endif // SVG_DEBUG
	            }
	            if( type.at(0).toStdString() == "stroke-opacity" ){
		            strokeOpacity = type.at(1).toDouble();
#ifdef SVG_DEBUG
		            cerr << "stroke-opacity = " << strokeWidth << endl;
#endif // SVG_DEBUG
	            }
            }
            // element coordinates
            XMLTAGTYPE tag;
            vector< KeiRo::Base::Coord2 > coordElements;
	        KeiRo::Base::Coord2 origin;
#ifdef SVG_DEBUG
            for( unsigned int j = 0; j < dList.size(); j++ ) {
                cerr << "j = " << j << ", " << dList.at( j ).toStdString() << endl;
            }
            cerr << endl << endl;
#endif // SVG_DEBUG

            for( unsigned int j = 0; j < dList.size(); j++ ) {

#ifdef SVG_DEBUG
                cerr << "origin = " << origin;
	            cerr << "dList.size() = " << dList.size() << endl;
                cerr << "j = " << j << " str = " << dList.at( j ).toStdString() << endl;
#endif // SVG_DEBUG


                QStringList coords = dList.at( j ).split( "," );
                if( coords.size() == 1 ){
                    // check if c exists
	                if ( coords.at( 0 ).toStdString() == "M" ) {
		                tag = XMLTAGTYPE_M;
		                j++;
		                coords = dList.at( j ).split( "," );
	                }
                    if ( coords.at( 0 ).toStdString() == "m" ) {
                    	tag = XMLTAGTYPE_m;
	                    j++;
	                    coords = dList.at( j ).split( "," );
                    }
                    if ( coords.at( 0 ).toStdString() == "c" ) {
                    	tag = XMLTAGTYPE_c;
	                    j++;
	                    coords = dList.at( j ).split( "," );
                    }
                    if ( coords.at( 0 ).toStdString() == "v" ) {
                    	tag = XMLTAGTYPE_v;
                    }
                    if ( coords.at( 0 ).toStdString() == "h" ) {
                    	tag = XMLTAGTYPE_h;
                    }
                    if ( coords.at( 0 ).toStdString() == "l" ) {
                    	tag = XMLTAGTYPE_l;
	                    j++;
	                    coords = dList.at( j ).split( "," );
                    }
                    if ( coords.at( 0 ).toStdString() == "z" ) {
                        tag = XMLTAGTYPE_z;
                        break;
                    }
                }
#ifdef SVG_DEBUG
                cerr << "j = " << j << ", coords.size() = " << coords.size() << ", tag = " << tag << endl;
#endif // SVG_DEBUG

                switch( tag ){
	                case XMLTAGTYPE_M:
	                {
		                origin.x() = coords.at(0).toDouble();
		                origin.y() = -coords.at(1).toDouble();
	#ifdef SVG_DEBUG
		                cerr << "coord = " << origin << endl;
	#endif // SVG_DEBUG
		                coordElements.push_back( origin );
		                tag = XMLTAGTYPE_DEFAULT;
	                }
		                break;
                    case XMLTAGTYPE_m:
                    {
                        origin.x() = coords.at(0).toDouble();
                        origin.y() = -coords.at(1).toDouble();
#ifdef SVG_DEBUG
                        cerr << "coord = " << origin << endl;
#endif // SVG_DEBUG
                        coordElements.push_back( origin );
                        tag = XMLTAGTYPE_DEFAULT;
                    }
                        break;
                    case XMLTAGTYPE_c:
                    {
                        while( true ){

                            QPainterPath path;
                            path.moveTo( origin.x(), origin.y() );

                            QStringList c1s = dList.at( j ).split( "," );
                            QStringList c2s = dList.at( j+1 ).split( "," );
                            QStringList es = dList.at( j+2 ).split( "," );

                            QPointF c1( origin.x() + c1s.at(0).toDouble(),
                                        origin.y() - c1s.at(1).toDouble()  );
                            QPointF c2( origin.x() + c2s.at(0).toDouble(),
                                        origin.y() - c2s.at(1).toDouble() );
                            QPointF  e( origin.x()+es.at(0).toDouble(),
                                        origin.y()-es.at(1).toDouble()) ;
                            path.cubicTo( c1, c2, e );
#ifdef SVG_DEBUG
                            cerr << "j = " << j << endl;
                            cerr << "c1s.size() = " << c1s.size() << endl;
                            cerr << "c2s.size() = " << c2s.size() << endl;
                            cerr << "es.size() = " << es.size() << endl;
                            cerr << "Subpath.size() = " << path.toSubpathPolygons().at(0).size() << endl;
                            cerr << "origin = " << origin.x() << ", " << origin.y() << endl;
                            cerr << "c1 = " << c1.x() << ", " << c1.y() << endl;
                            cerr << "c2 = " << c2.x() << ", " << c2.y() << endl;
                            cerr << "e = " << e.x() << ", " << e.y() << endl;
#endif // SVG_DEBUG

                            QPolygonF polygon = path.toSubpathPolygons().at(0);
                            for( unsigned int k = 1; k < polygon.size();  ){
                                QPointF point = polygon.at( k );
	                            KeiRo::Base::Coord2 coord( point.x(), point.y() );
                                coordElements.push_back( coord );
                                if( ( k+_curveDownSample >= polygon.size() ) && ( k != polygon.size()-1 ) ){
                                    QPointF point = polygon.at( polygon.size()-1 );
	                                KeiRo::Base::Coord2 coord( point.x(), point.y() );
                                    coordElements.push_back( coord );
                                }
                                k += _curveDownSample;
                            }
                            // coordElements.push_back( Base::Coord2( e.x(), e.y() ) );
                            j += 3;
                            origin = KeiRo::Base::Coord2( e.x(), e.y() );

                            // check if the end of tag c
                            if( j == dList.size() ) break;
                            if( dList.at( j ).split( "," ).size() == 1 ) {
                                j = j-1;
                                break;
                            }
                        }
                    }
                        break;
                    case XMLTAGTYPE_v:
                    {
                        // coords = dList.at( j ).split( "," );
                        // cerr << "v coords.size() = " << coords.size() << endl;
                        if( coords.size() == 1 ){

                            QStringList coords = dList.at( j ).split( "," );
                            // relative path
	                        KeiRo::Base::Coord2 coord( origin.x(),
                                                origin.y() - coords.at(0).toDouble() );
                            if ( origin != coord ) coordElements.push_back( coord );
                            origin = coord;
#ifdef SVG_DEBUG
                            cerr << "coord = " << coord;
#endif // SVG_DEBUG
                        }
                    }
                        break;
                    case XMLTAGTYPE_h:
                    {
                        // coords = dList.at( j ).split( "," );
                        // cerr << "h coords.size() = " << coords.size() << endl;
                        if( coords.size() == 1 ){

                            QStringList coords = dList.at( j ).split( "," );
                            // relative path
	                        KeiRo::Base::Coord2 coord( origin.x() + coords.at(0).toDouble(),
                                                origin.y() );
                            if ( origin != coord ) coordElements.push_back( coord );
                            origin = coord;
#ifdef SVG_DEBUG
                            cerr << "coord = " << coord;
#endif // SVG_DEBUG
                        }
                    }
                        break;
                    case XMLTAGTYPE_l:
                    case XMLTAGTYPE_DEFAULT:
                    {
                        coords = dList.at( j ).split( "," );
                        if( coords.size() == 2 ){

                            QStringList coords = dList.at( j ).split( "," );
	                        // absolute path
	                        KeiRo::Base::Coord2 coord( coords.at(0).toDouble(),
	                                                   -coords.at(1).toDouble() );
//                            // relative path
//	                        KeiRo::Base::Coord2 coord( origin.x() + coords.at(0).toDouble(),
//                                                origin.y() - coords.at(1).toDouble() );
                            if ( origin != coord ) coordElements.push_back( coord );
                            origin = coord;
#ifdef SVG_DEBUG
                            cerr << "x = " << coords.at(0).toDouble() << " y = " << coords.at(1).toDouble() << endl;
                            cerr << "coord = " << coord;
#endif // SVG_DEBUG
                        }
                    }
                        break;
                    default:
                        break;
                }
            }

#ifdef SVG_DEBUG
            cerr << endl << "coordElements = " << endl;
            for( unsigned int j = 0; j < coordElements.size(); j++ ){
                cerr << coordElements[j];
            }
            cerr << endl;
#endif // SVG_DEBUG

            for( unsigned int k = 0; k < coordElements.size(); k++ ){
            	coordElements[k].x() -= 0.5 * _svgCanvas.width();
	            coordElements[k].y() += 0.5 * _svgCanvas.height();
	            coordElements[k].x() *= _screenCanvas.width()/_svgCanvas.width();;
	            coordElements[k].y() *= _screenCanvas.height()/_svgCanvas.height();;
            }
            
            // remove intermediate points on the straight line
	        KeiRo::Base::Line2 line;
            line.elements() = coordElements;
	        line.simplifyGeometry();
	        coordElements = line.elements();
	        
            // create object
            if( isClosed ){
	            KeiRo::Base::Polygon2 polygon;
                polygon.fixedElements() = polygon.elements() = coordElements;
	            polygon.name() = id.toStdString();
	            polygon.fill() = fill;
                polygon.stroke() = stroke;
	            polygon.strokeWidth() = strokeWidth;
//	            polygon.strokeOpacity() = strokeOpacity;
	            polygon.update();
	            polygon.boundingBox().updateOldElement();
                _polygonVec.push_back( polygon );
            }
            else {
	            KeiRo::Base::Line2 polyline;
                polyline.fixedElements() = polyline.oldElements() = polyline.elements() = coordElements;
	            polyline.name() = id.toStdString();
	            polyline.fill() = fill;
                polyline.stroke() = stroke;
	            polyline.strokeWidth() = strokeWidth;
//	            polyline.strokeOpacity() = strokeOpacity;
                _polylineVec.push_back( polyline );
            }
        }

        file.close();
    }

    //
    //  SVG::getCanvasSize --	get SVG canvas size
    //
    //  Inputs
    //	string: file name
    //
    //  Outputs
    //	none
    //
    KeiRo::Base::Rectangle2 SVG::getCanvasSize( const QString fileName )
    {
        // initialize the stack object QDomDocument
        QDomDocument doc;
	    KeiRo::Base::Rectangle2 r( 0.0, 0.0, 100.0, 100.0 );
	    
        // Open your SVG-file
        QFile file( fileName );

        // If it is not opened, or have failed to transmit the contents in QDocDocument
        if ( !file.open( QIODevice::ReadOnly ) || !doc.setContent( &file ) ) {
            // the return values for the default scene
            return r;
        }

        // Then pick up a list of items with the tag svg.
        // If a list of elements is not empty, take the size of the graphic scenes.
        QDomNodeList list = doc.elementsByTagName( "svg" );
        // cerr << "list.length() = " << list.length() << endl;
        if( list.length() > 0 ) {
            QDomElement svgElement = list.item(0).toElement();
            QString id = svgElement.attribute( "id" );
            QStringList viewBox = svgElement.attribute( "viewBox" ).split(" ");
#ifdef SVG_DEBUG
            cerr << "id = " << id.toStdString() << endl;
            cerr << "viewBox = " << viewBox.at(0).toDouble() << ", "
                                 << viewBox.at(1).toDouble() << ", "
                                 << viewBox.at(2).toDouble() << ", "
                                 << viewBox.at(3).toDouble() << endl;
#endif // SVG_DEBUG
            r.leftBottom().x() = viewBox.at(0).toDouble();
	        r.leftBottom().y() = viewBox.at(1).toDouble();
	        r.width() = viewBox.at(2).toDouble();
	        r.height() = viewBox.at(3).toDouble();
            return r;
        }
        return r;
    }
	
    //
    //  SVG::normalize --	normalize the objects in the SVG file
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    void SVG::normalize( void )
    {
        double xMin =  INFINITY;
        double xMax = -INFINITY;
        double yMin =  INFINITY;
        double yMax = -INFINITY;
        double x = _screenCanvas.leftBottom().x();
	    double y = _screenCanvas.leftBottom().y();
	    double width = _screenCanvas.width();
	    double height = _screenCanvas.height();
        double aspect = ( double )width/( double )height;

        // cerr << "_w = " << _width << " _h = " << _height << endl;
        // Scan all the vertex coordinates first
        for( unsigned int i = 0; i < _polygonVec.size(); i++ ){
            for( unsigned int j = 0; j < _polygonVec[i].elements().size(); j++ ){

	            KeiRo::Base::Coord2 &coord = _polygonVec[i].elements()[j];
                if ( coord.x() < xMin ) xMin = coord.x();
                if ( coord.x() > xMax ) xMax = coord.x();
                if ( coord.y() < yMin ) yMin = coord.y();
                if ( coord.y() > yMax ) yMax = coord.y();
            }
        }
        for( unsigned int i = 0; i < _polylineVec.size(); i++ ){
            for( unsigned int j = 0; j < _polylineVec[i].elements().size(); j++ ){

	            KeiRo::Base::Coord2 &coord = _polylineVec[i].elements()[j];
                if ( coord.x() < xMin ) xMin = coord.x();
                if ( coord.x() > xMax ) xMax = coord.x();
                if ( coord.y() < yMin ) yMin = coord.y();
                if ( coord.y() > yMax ) yMax = coord.y();
            }
        }

        double xRange;
        double yRange;
        double xMid;
        double yMid;
        if( ( xMax - xMin ) / ( double )width > ( yMax - yMin ) / ( double )height ) {
            xRange  = ( xMax - xMin );
            yRange  = ( xMax - xMin ) * ( 1.0/ aspect );
        }
        else {
            xRange  = ( yMax - yMin ) * aspect;
            yRange  = ( yMax - yMin );
        }

        xRange *= 1.2;
        yRange *= 1.2;
        xMid    = 0.5 * ( xMin + xMax );
        yMid    = 0.5 * ( yMin + yMax );

        // normalize polygons
        for( unsigned int i = 0; i < _polygonVec.size(); i++ ){
            for( unsigned int j = 0; j < _polygonVec[i].elements().size(); j++ ){

	            KeiRo::Base::Coord2 coord = _polygonVec[i].elements()[j];

                coord.setX( (double)width  * ( coord.x() - xMid ) / xRange + x );
                coord.setY( (double)height * ( coord.y() - yMid ) / yRange + y );

                // cerr << "coord = " << coord;
                _polygonVec[i].elements()[j].x() = coord.x();
                _polygonVec[i].elements()[j].y() = coord.y();
            }
            _polygonVec[i].fixedElements() = _polygonVec[i].elements();

            // normalize boundingBox
            _polygonVec[i].update();
	        _polygonVec[i].boundingBox().updateOldElement();
	        }

        // normalize polylines
        for( unsigned int i = 0; i < _polylineVec.size(); i++ ){
            for( unsigned int j = 0; j < _polylineVec[i].elements().size(); j++ ){

	            KeiRo::Base::Coord2 coord = _polylineVec[i].elements()[j];

                coord.setX( (double)width  * ( coord.x() - xMid ) / xRange + x );
                coord.setY( (double)height * ( coord.y() - yMid ) / yRange + y );

                // cerr << "coord = " << coord;
                _polylineVec[i].elements()[j].x() = coord.x();
                _polylineVec[i].elements()[j].y() = coord.y();
            }
            _polylineVec[i].fixedElements() = _polylineVec[i].elements();
        }
    }
	
    //
    //  SVG::readSVG --	read SVG file
    //
    //  Inputs
    //	string filename
    //
    //  Outputs
    //	bool
    //
    bool SVG::readSVG( const QString fileName, bool isCompressionOn )
    {
        if ( fileName.isEmpty() ){
            cerr << "something is wrong here... at " << __LINE__ << " in " << __FILE__ << endl;
            return false;
        }
	
	    _svgCanvas = getCanvasSize( fileName );

//        getPolygonElements( fileName );
        getRectangleElements( fileName );
        getPathElements( fileName );
//        getCircleElements( fileName );
//        normalize();

#ifdef SVG_DEBUG
	    cerr << "fileName = " << fileName.toStdString() << endl;
	    cerr << "canvas( " << canvas.x() << ", " << canvas.y() << ", " << canvas.width() << ", " << canvas.height() << " )" << endl;
        cerr << "_polygonVec.size() = " << _polygonVec.size() << endl;
	    cerr << "_polylineVec.size() = " << _polylineVec.size() << endl;
#endif // SVG_DEBUG
	    
        // create compression
        _compressionGrid.init( _gridPtr, &_polygonVec, &_polylineVec );
        _compressionGrid.createCompression( isCompressionOn );

        return true;
    }

    //
    //  SVG::writeSVG --	write SVG file
    //
    //  Inputs
    //	string filename
    //
    //  Outputs
    //	bool
    //
    bool SVG::writeSVG( const QString fileName )
    {
        cerr << "Need to be implemented..." << endl;
        return true;
    }
    
} // namespace FileIO