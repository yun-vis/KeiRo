#ifndef _File_SVG_H
#define _File_SVG_H

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

#include <QtWidgets/QApplication>
#include <QtXml/QDomDocument>
#include <QtCore/QFile>
#include <QtCore/QRegExp>
#include <QtSvg/QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>
#include <QtGui/QPainterPath>

#ifndef Q_MOC_RUN
#include "Object.h"
#include "Polygon2.h"
#include "core/Compression.h"
#include "core/Grid2.h"
#endif // Q_MOC_RUN

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

namespace FileIO {

    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class SVG : public  KeiRo::Base::Object {

    private:

        // glyphs in SVG
        vector<  KeiRo::Base::Polygon2 >    _polygonVec;
        // arcs in SVG
        vector< KeiRo::Base::Line2 >       _polylineVec;
        Base::Grid2                *_gridPtr;

        int                         _x, _y, _width, _height;

        static int                  _curveDownSample;

        Base::Compression           _compression;

    protected:

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        void _init( Base::Grid2 * __gridPtr, double __x, double __y, int __width, int __height );

    public:

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        SVG( void );
        // copy constructor
        SVG( const SVG & v );
        // destructor
        virtual ~SVG( void ) {}

        //------------------------------------------------------------------------------
        //	Reference to elements
        //------------------------------------------------------------------------------
        vector< Base::Polygon2 > &	        polygonVec( void ) 	        { return _polygonVec; }
        const vector< Base::Polygon2 > &	polygonVec( void ) const	{ return _polygonVec; }
        vector< Base::Line2 > &	            polylineVec( void ) 	    { return _polylineVec; }
        const vector< Base::Line2 > &	    polylineVec( void ) const	{ return _polylineVec; }

        Base::Compression &	                compression( void ) 	    { return _compression; }
        const Base::Compression &	        compression( void ) const	{ return _compression; }

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        void init( Base::Grid2 * __gridPtr, double __x, double __y, int __width, int __height ) {
            _init( __gridPtr, __x, __y, __width, __height );
        }

        // handle vg file
        void getPolygonElements( const QString fileName );
        void getCircleElements( const QString fileName );
        void getRectangleElements( const QString fileName );
        void getPathElements( const QString fileName );
        QRectF getCanvasSize( const QString fileName );
        void normalize( void );
        bool readSVG( const QString fileName );
        bool writeSVG( const QString fileName );

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream & operator << ( ostream & stream, const SVG & obj );
        // input
        friend istream & operator >> ( istream & stream, SVG & obj );
        // class name
        virtual const char * className( void ) const { return "SVG"; }

    };
    
} // namespace FileIO

#endif // _File_SVG_H
