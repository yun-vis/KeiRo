//******************************************************************************
// sbgn.cpp
//	: program file sbgn
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sat Mar 7 15:02:45 2020
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include "sbgn.h"

namespace FileIO {

    //------------------------------------------------------------------------------
    //	Private Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  SBGN::SBGN --	constructor
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    SBGN::SBGN( void )
    {
    }

    //
    //  SBGN::SBGN --	copy constructor
    //
    //  Input
    //	none
    //
    //  Output
    //	none
    //
    SBGN::SBGN( const SBGN & v )
    {
    }

    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    void SBGN::_init( int __width, int __height )
    {
        _width = __width;
        _height = __height;

        // level 3, version 2
        // sbmlDocPtr = new SBMLDocument( 3, 2 );
        cerr << "initializing SBGN file..." << endl;
    }

    void SBGN::addArc( SbgnArc* arc )
    {
        if( arc == NULL ) return;

#ifdef SBGN_DEBUG
        cout << "Arc" << endl;
        if( arc->isSetId() )
            cout << "  id      : " << arc->getId() << endl;
        if( arc->isSetClazz() )
            cout << "  class   : " << arc->getClazz() << endl;
        if( arc->isSetSource() )
            cout << "  source  : " << arc->getSource() << endl;
        if( arc->isSetTarget() )
            cout << "  target  : " << arc->getTarget() << endl;
        if( arc->getNumNexts() > 0 )
            cout << "  # next: " << arc->getNumNexts() << endl;
#endif // SBGN_DEBUG
	
	    KeiRo::Base::Line2 polyline;
        if( arc->isSetStart() )
        {
#ifdef SBGN_DEBUG
            cout << "  start   : x: " << arc->getStart()->getX()
                 << " y: " << arc->getStart()->getY() << endl;
#endif // SBGN_DEBUG
            double x = arc->getStart()->getX(),
                   y = -arc->getStart()->getY();
	        KeiRo::Base::Coord2 coord( x, y );
            polyline.elements().push_back( coord );
        }

        for( unsigned int i = 0; i < arc->getNumNexts(); i++ )
        {
            auto* next = arc->getNext(i);
#ifdef SBGN_DEBUG
            std::cout << "  next    : x: " << next->getX()
                      << " y: " << next->getY() << std::endl;
#endif // SBGN_DEBUG
            double x = next->getX(),
                   y = -next->getY();
	        KeiRo::Base::Coord2 coord( x, y );
            polyline.elements().push_back( coord );
        }

        if( arc->isSetEnd() )
        {
#ifdef SBGN_DEBUG
            std::cout << "  end     : x: " << arc->getEnd()->getX()
                      << " y: " << arc->getEnd()->getY() << std::endl;
#endif // SBGN_DEBUG
            double x = arc->getEnd()->getX(),
                   y = -arc->getEnd()->getY();
	        KeiRo::Base::Coord2 coord( x, y );
            polyline.elements().push_back( coord );
        }

        polyline.fixedElements() = polyline.elements();
        _polylineVec.push_back( polyline );
    }

    void SBGN::addGlyph( SbgnGlyph *glyph )
    {
        if( glyph == NULL ) return;

#ifdef SBGN_DEBUG
        std::cout << "Glyph" << std::endl;
        if( glyph->isSetId() )
            std::cout << "  id      : " << glyph->getId() << std::endl;
        if( glyph->isSetClazz() )
            std::cout << "  class   : " << glyph->getClazz() << std::endl;
        if( glyph->getNumGlyphs() > 0 )
            std::cout << "  # glyphs: " << glyph->getNumGlyphs() << std::endl;
        if( glyph->getNumPorts() > 0 )
            std::cout << "  # ports : " << glyph->getNumPorts() << std::endl;
        if( glyph->getLabel() )
            std::cout << "  # label : " << glyph->getLabel()->getText() << std::endl;
        // top-left corner
        if( glyph->getBBox() )
            std::cout << "  # bbox  : " << glyph->getBBox()->getX() << ", "
                    << glyph->getBBox()->getY() << ", "
                    << glyph->getBBox()->getWidth() << ", "
                    << glyph->getBBox()->getHeight() << std::endl;
#endif // SBGN_DEBUG
	
	    KeiRo::Base::Polygon2 polygon;
        if( glyph->getLabel() )
            polygon.name() = glyph->getLabel()->getText();
        else
            polygon.name() = "unknown";
        double w = glyph->getBBox()->getWidth();
        double h = glyph->getBBox()->getHeight();
        double x = glyph->getBBox()->getX();
        double y = -glyph->getBBox()->getY();
        polygon.boxLeftTop().x() = x;
        polygon.boxLeftTop().y() = y;
        polygon.boundingBox().x() = w;
        polygon.boundingBox().y() = h;

        // add polygon contour
        polygon.elements().push_back( KeiRo::Base::Coord2( x, y-h ) );
        polygon.elements().push_back( KeiRo::Base::Coord2( x, y ) );
        polygon.elements().push_back( KeiRo::Base::Coord2( x+w, y ) );
        polygon.elements().push_back( KeiRo::Base::Coord2( x+w, y-h ) );
        polygon.fixedElements() = polygon.elements();
        _polygonVec.push_back( polygon );

        for( unsigned int i = 0; i < glyph->getNumGlyphs(); i++ ){
            addGlyph( glyph->getGlyph(i) );
        }
    }

    void SBGN::createPolygonVec( SbgnMap *map )
    {
        for( unsigned int i = 0; i < map->getNumGlyphs(); i++ )
        {
           addGlyph( map->getGlyph(i) );
        }

    }

    void SBGN::createPolylineVec( SbgnMap *map )
    {
        for (unsigned int i = 0; i < map->getNumArcs(); i++ )
        {
            addArc(map->getArc(i));
        }
    }

    void SBGN::createMap( SbgnMap *map )
    {
        if( map == NULL) return;
        _polygonVec.clear();
        _polylineVec.clear();

#ifdef SBGN_DEBUG
        cout << "##############################" << endl;
        cout << "# Map" << endl;
        cout << "##############################" << endl;
        cout << "  id      : " << map->getId() << endl;
        cout << "  language: " << map->getLanguageAsString() << endl;
        cout << "  version : " << map->getVersion() << endl;
        cout << "  level   : " << map->getLevel() << endl;
        if( map->getNumGlyphs() > 0 )
            cout << "  # glyphs: " << map->getNumGlyphs() << endl;
        if( map->getNumArcs() > 0 )
            cout << "  # arcs  : " << map->getNumArcs() << endl;
        cerr << endl;
#endif // SBGN_DEBUG

        createPolygonVec( map );
        createPolylineVec( map );
        normalize();
    }

    void SBGN::normalize( void )
    {
        double xMin =  INFINITY;
        double xMax = -INFINITY;
        double yMin =  INFINITY;
        double yMax = -INFINITY;
        double aspect = ( double )_width/( double )_height;

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
        if( ( xMax - xMin ) / ( double )_width > ( yMax - yMin ) / ( double )_height ) {
            xRange  = ( xMax - xMin );
            yRange  = ( xMax - xMin ) * ( 1.0/ aspect );
        }
        else {
            xRange  = ( yMax - yMin ) * aspect;
            yRange  = ( yMax - yMin );
        }

        xRange *= 1.05;
        yRange *= 1.05;
        xMid    = 0.5 * ( xMin + xMax );
        yMid    = 0.5 * ( yMin + yMax );

        // normalize polygons
        for( unsigned int i = 0; i < _polygonVec.size(); i++ ){
            for( unsigned int j = 0; j < _polygonVec[i].elements().size(); j++ ){

                KeiRo::Base::Coord2 coord = _polygonVec[i].elements()[j];

                coord.setX( (double)_width  * ( coord.x() - xMid ) / xRange );
                coord.setY( (double)_height * ( coord.y() - yMid ) / yRange );

                // cerr << "coord = " << coord;
                _polygonVec[i].elements()[j].x() = coord.x();
                _polygonVec[i].elements()[j].y() = coord.y();
            }
            _polygonVec[i].fixedElements() = _polygonVec[i].elements();

            // normalize boundingBox
            _polygonVec[i].computeBoundingBox();
        }

        // normalize polylines
        for( unsigned int i = 0; i < _polylineVec.size(); i++ ){
            for( unsigned int j = 0; j < _polylineVec[i].elements().size(); j++ ){
	
	            KeiRo::Base::Coord2 coord = _polylineVec[i].elements()[j];

                coord.setX( (double)_width  * ( coord.x() - xMid ) / xRange );
                coord.setY( (double)_height * ( coord.y() - yMid ) / yRange );

                // cerr << "coord = " << coord;
                _polylineVec[i].elements()[j].x() = coord.x();
                _polylineVec[i].elements()[j].y() = coord.y();
            }
            _polylineVec[i].fixedElements() = _polylineVec[i].elements();
        }
    }

    bool SBGN::readSBGN( string fileName )
    {
        auto* doc = readSBGNFromFile( fileName.c_str() );

        if( !doc->getNumMaps() )
        {
            cout << " The file has no map" << endl;
        }

        createMap(doc->getMap(0) );

        delete doc;
        return true;
    }

    bool SBGN::writeSBGN( string fileName )
    {
        return true;
    }
} // namespace FileIO
