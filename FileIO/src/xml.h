#ifndef _File_XML_H
#define _File_XML_H

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

//#include <QtWidgets/QApplication>
#include <QtXml/QDomDocument>
#include <QtCore/QFile>
#include <QtGui/QColor>
#include <QtGui/QPainterPath>

//#include <QtCore/QRegExp>
//#include <QtSvg/QGraphicsSvgItem>
//#include <QtSvg/QSvgRenderer>
//#include <QtGui/QPainterPath>

#ifndef Q_MOC_RUN
#include "Object.h"
#include "Polygon2.h"
#include "CompressionGrid.h"
#include "Grid2.h"
#endif // Q_MOC_RUN

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

namespace FileIO {
	//------------------------------------------------------------------------------
	//	Private Static Variables
	//------------------------------------------------------------------------------
	
    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class XML : public  KeiRo::Base::Object {

    private:
		
	    static int                  _curveDownSample;
	    
    protected:
		
        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------

    public:

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        XML( void );
        // copy constructor
        XML( const XML & v );
        // destructor
        virtual ~XML( void ) {}

        //------------------------------------------------------------------------------
        //	Reference to elements
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
	    static void getEdgeDElement( const QDomElement edgeElement,
									 KeiRo::Base::Edge2 &edge, bool &isClosed )
		{
			// element coordinates
			XMLTAGTYPE tag;
			vector< KeiRo::Base::Coord2 > coordElements;
			KeiRo::Base::Coord2 origin( 0.0, 0.0 );
#ifdef XML_DEBUG
		    for( unsigned int j = 0; j < dList.size(); j++ ) {
                cerr << "j = " << j << ", " << dList.at( j ).toStdString() << endl;
            }
            cerr << endl << endl;
#endif // XML_DEBUG
		
		    QStringList dList = edgeElement.attribute( "d" ).split(" " );
		    
			// check if the edge is closed
			for( unsigned int j = 2; j < dList.size(); j++ ) {
			
			    QStringList d = dList.at( j ).split( "," );
			    if ( d.at( 0 ).toStdString() == "z" ) {
				    cerr << "The path is closed!" << endl;
				    isClosed = true;
			    }
		    }
			
			// read edge coordinates
		    for( unsigned int j = 0; j < dList.size(); j++ ) {

#ifdef XML_DEBUG
			    cerr << "origin = " << origin;
	            cerr << "dList.size() = " << dList.size() << endl;
                cerr << "j = " << j << " str = " << dList.at( j ).toStdString() << endl;
#endif // XML_DEBUG
			
			
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
#ifdef XML_DEBUG
			    cerr << "j = " << j << ", coords.size() = " << coords.size() << ", tag = " << tag << endl;
#endif // XML_DEBUG
			
			    switch( tag ){
			    case XMLTAGTYPE_M:
			    {
				    origin.x() = coords.at(0).toDouble();
				    origin.y() = coords.at(1).toDouble();
#ifdef XML_DEBUG
				    cerr << "coord = " << origin << endl;
#endif // XML_DEBUG
				    coordElements.push_back( origin );
				    tag = XMLTAGTYPE_DEFAULT;
			    }
				    break;
			    case XMLTAGTYPE_m:
			    {
				    origin.x() = coords.at(0).toDouble();
				    origin.y() = coords.at(1).toDouble();
#ifdef XML_DEBUG
				    cerr << "coord = " << origin << endl;
#endif // XML_DEBUG
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
#ifdef XML_DEBUG
					    cerr << "j = " << j << endl;
                            cerr << "c1s.size() = " << c1s.size() << endl;
                            cerr << "c2s.size() = " << c2s.size() << endl;
                            cerr << "es.size() = " << es.size() << endl;
                            cerr << "Subpath.size() = " << path.toSubpathPolygons().at(0).size() << endl;
                            cerr << "origin = " << origin.x() << ", " << origin.y() << endl;
                            cerr << "c1 = " << c1.x() << ", " << c1.y() << endl;
                            cerr << "c2 = " << c2.x() << ", " << c2.y() << endl;
                            cerr << "e = " << e.x() << ", " << e.y() << endl;
#endif // XML_DEBUG
					
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
#ifdef XML_DEBUG
					    cerr << "coord = " << coord;
#endif // XML_DEBUG
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
#ifdef XML_DEBUG
					    cerr << "coord = " << coord;
#endif // XML_DEBUG
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
					                               coords.at(1).toDouble() );
//                            // relative path
//	                        KeiRo::Base::Coord2 coord( origin.x() + coords.at(0).toDouble(),
//                                                origin.y() - coords.at(1).toDouble() );
					    if ( origin != coord ) coordElements.push_back( coord );
					    origin = coord;
#ifdef XML_DEBUG
					    cerr << "x = " << coords.at(0).toDouble() << " y = " << coords.at(1).toDouble() << endl;
                            cerr << "coord = " << coord;
#endif // XML_DEBUG
				    }
			    }
				    break;
			    default:
				    break;
			    }
		    }
		
			edge.elements() = coordElements;
	    }
	    static void getStyleElement( const QDomElement element, vector< unsigned int > &fill,
									 vector< unsigned int > &stroke, double &strokeWidth )
	    {
			// initialization
		    QStringList styles = element.attribute( "style" ).split( ";" );
			
		    for( unsigned int j = 0; j < styles.size(); j++ ){
			
			    QStringList type = styles.at( j ).split( ":" );
			    if( type.at(0).toStdString() == "fill" ){
				    QColor color( type.at(1) );
				    fill[0] = color.red();
				    fill[1] = color.green();
				    fill[2] = color.blue();
#ifdef XML_DEBUG
				    cerr << "color = " << c.red() << ", " << c.green() << ", " << c.blue() << endl;
                    cerr << "fill = " << fill[0] << ", "<< fill[1] << ", " << fill[2] << ", " << fill[3] << endl;
#endif // XML_DEBUG
			    }
			    if( type.at(0).toStdString() == "fill-opacity" ){
				    fill[3] = 255.0 * type.at(1).toDouble();
#ifdef XML_DEBUG
				    cerr << "fill = " << fill[0] << ", "<< fill[1] << ", " << fill[2] << ", " << fill[3] << endl;
#endif // XML_DEBUG
			    }
			    if( type.at(0).toStdString() == "stroke" ){
				    QColor c( type.at(1) );
				    stroke[0] = c.red();
				    stroke[1] = c.green();
				    stroke[2] = c.blue();
				    stroke[3] = 255;
#ifdef XML_DEBUG
				    cerr << "color = " << c.red() << ", " << c.green() << ", " << c.blue() << endl;
                    cerr << "stroke = " << stroke[0] << ", "<< stroke[1] << ", " << stroke[2] << ", " << stroke[3] << endl;
#endif // XML_DEBUG
			    }
			    if( type.at(0).toStdString() == "stroke-width" ){
				    strokeWidth = type.at(1).toDouble();
#ifdef XML_DEBUG
				    cerr << "stroke-width = " << strokeWidth << endl;
#endif // XML_DEBUG
			    }
			    if( type.at(0).toStdString() == "stroke-opacity" ){
				    stroke[3] = type.at(1).toDouble();
#ifdef XML_DEBUG
				    cerr << "stroke-opacity = " << strokeWidth << endl;
#endif // XML_DEBUG
			    }
		    }
	    }
		

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream & operator << ( ostream & stream, const XML & obj );
        // input
        friend istream & operator >> ( istream & stream, XML & obj );
        // class name
        virtual const char * className( void ) const { return "XML"; }

    };
	
} // namespace FileIO

#endif // _File_XML_H
