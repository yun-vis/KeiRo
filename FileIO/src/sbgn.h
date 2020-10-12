#ifndef _File_SBGN_H
#define _File_SBGN_H

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

#ifndef Q_MOC_RUN
#include "Polygon2.h"
#include "Line2.h"
#include "sbgn/SbgnTypes.h"
#endif // Q_MOC_RUN

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

namespace FileIO {

    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class SBGN
    {
    private:

        // glyphs in SBGN
        vector< KeiRo::Base::Polygon2 >    _polygonVec;
        // arcs in SBGN
        vector< KeiRo::Base::Line2 >       _polylineVec;

        int                                 _width, _height;

    protected:

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        void _init( int __width, int __height );

    public:

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        SBGN( void );
        // copy constructor
        SBGN( const SBGN & v );
        // destructor
        virtual ~SBGN( void ) {}

        //------------------------------------------------------------------------------
        //	Reference to elements
        //------------------------------------------------------------------------------
        vector< KeiRo::Base::Polygon2 > &	        polygonVec( void ) 	        { return _polygonVec; }
        const vector< KeiRo::Base::Polygon2 > &	polygonVec( void ) const	{ return _polygonVec; }
        vector< KeiRo::Base::Line2 > &	            polylineVec( void ) 	    { return _polylineVec; }
        const vector< KeiRo::Base::Line2 > &	    polylineVec( void ) const	{ return _polylineVec; }

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        void init( int __width, int __height ) {
            _init( __width, __height );
        }

        // handle sbgn file
        void addArc( SbgnArc *arc );
        void addGlyph( SbgnGlyph *glyph );
        void createMap( SbgnMap *map );
        void createPolygonVec( SbgnMap *map );
        void createPolylineVec( SbgnMap *map );
        void normalize( void );
        bool readSBGN( string fileName );
        bool writeSBGN( string fileName );

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream & operator << ( ostream & stream, const SBGN & obj );
        // input
        friend istream & operator >> ( istream & stream, SBGN & obj );
        // class name
        virtual const char * className( void ) const { return "SBGN"; }

    };
    
} // namespace FileIO

#endif // _File_SBGN_H
