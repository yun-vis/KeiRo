//******************************************************************************
// Polygon2.cc
//	: program file for 2D coordinates
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sun Sep 16 15:02:45 2012
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

#include "Polygon2.h"

namespace KeiRo {
namespace Base {

    //------------------------------------------------------------------------------
    //	Private Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------
    //
    //  Polygon2::_init --	initialization
    //
    //  Inputs
    //  __elements
    //
    //  Outputs
    //  none
    //
    void Polygon2::_init( unsigned int __id, vector< KeiRo::Base::Coord2 > __elements )
    {
        _clear();

        _id             = __id;
        _gid            = 0;
        _fixedElements  = __elements;
        _elements       = __elements;
        _initArea       = 0.0;

        //_area               = 0.0;
        //_center.zero();        // average of the elements
        //_centroid.zero();      // centroid of the elements
        _boundingBox.zero();        // width and height of the bounding box
        _boxLeftTop.zero();         // left-top corner of the bounding box
    }

    //
    //  Polygon2::_clear --	clear elements
    //
    //  Inputs
    //
    //
    //  Outputs
    //  none
    //
    void Polygon2::_clear( void )
    {
        _elements.clear();
        _fixedElements.clear();
        _idElements.clear();
    }

    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  Polygon2::Polygon2 -- default constructor
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    Polygon2::Polygon2()
    {
        _clear();

        //Object::Object();

        //_area               = 0.0;
        //_center.zero();        // average of the elements
        //_centroid.zero();      // centroid of the elements
        _boundingBox.zero();        // width and height of the bounding box
        _boxLeftTop.zero();         // left-top corner of the bounding box
        _isSelected = false;        // select flag is set to false by default
        _initArea   = 0.0;

        _stroke.resize( 4 );
        _stroke[0] = _stroke[1] = _stroke[2] = 0;
        _stroke[3] = 255;
        _fill.resize( 4 );
        _fill[0] = _fill[1] = _fill[2] = 200;
        _fill[3] = 255;
    }

    //
    //  Polygon2::Polygon2 -- parameterized constructor
    //
    //  Inputs
    //  __elements
    //
    //  Outputs
    //  none
    //
    Polygon2::Polygon2( vector< KeiRo::Base::Coord2 > __elements )
    {
        _elements           = __elements;
        _fixedElements      = _elements;
        _isSelected         = false;
        _initArea           = 0.0;
        _idElements.clear();
    }

    //
    //  Polygon2::Polygon2 -- copy constructor
    //
    //  Inputs
    //  polygon
    //
    //  Outputs
    //  none
    //
    Polygon2::Polygon2( const Polygon2 & v )
    {
        _id                 = v._id;
        _gid                = v._gid;
        _name               = v._name;
        //_area               = v._area;
        //_center             = v._center;
        //_centroid           = v._centroid;
        _elements           = v._elements;
        _fixedElements      = v._fixedElements;
        _idElements         = v._idElements;
        _boundingBox        = v._boundingBox;
        _boxLeftTop         = v._boxLeftTop;
        _isSelected         = v._isSelected;
        _fill               = v._fill;
        _stroke             = v._stroke;
        _initArea           = v._initArea;
    }


    //------------------------------------------------------------------------------
    //	Assignment operators
    //------------------------------------------------------------------------------

    //
    //  Polygon2::operator = --	assignment
    //
    //  Inputs
    //	v	: 2D coordinates
    //
    //  Outputs
    //	reference to this object
    //
    Polygon2 & Polygon2::operator = ( const Polygon2 & p )
    {
        if ( this != &p ) {
            _id                 = p._id;
            _gid                = p._gid;
            //_area           = p._area;
            //_center         = p._center;
            //_centroid       = p._centroid;
            _elements           = p._elements;
            _fixedElements      = p._fixedElements;
            _idElements         = p._idElements;
            _boundingBox        = p._boundingBox;
            _boxLeftTop         = p._boxLeftTop;
            _isSelected         = p._isSelected;
            _fill               = p._fill;
            _stroke             = p._stroke;
            _initArea           = p._initArea;
        }

        return *this;
    }

    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    //
    //  Polygon2::computeBoundingBox --    compute bounding box
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void Polygon2::computeBoundingBox( void )
    {
        double minX = INFINITY, maxX = -INFINITY, minY = INFINITY, maxY = -INFINITY;
        for( unsigned int i = 0; i < _elements.size(); i++ ){
            if( minX > _elements[i].x() ) minX = _elements[i].x();
            if( maxX < _elements[i].x() ) maxX = _elements[i].x();
            if( minY > _elements[i].y() ) minY = _elements[i].y();
            if( maxY < _elements[i].y() ) maxY = _elements[i].y();
        }

        _boxLeftTop.x() = minX;
        _boxLeftTop.y() = minY;
        _boundingBox.x() = maxX - minX;
        _boundingBox.y() = maxY - minY;

        // compute the initial area
        if( _initArea == 0.0 ) _initArea = _boundingBox.x() * _boundingBox.y();
    }

    //
    //  Polygon2::maxRadiusInPolygon --    find the maximun radius in the polygon
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    double Polygon2::maxRadiusInPolygon( const KeiRo::Base::Coord2 &coord )
    {
        double maxR = INFINITY;

        for( unsigned int i = 0; i < _elements.size(); i++ ){
	
	        KeiRo::Base::Coord2 &coordM = _elements[ i ];
            double dist = (coordM-coord).norm();
            // cerr << " dist = " << dist;
            if( dist < maxR ) maxR = dist;
        }
        // cerr << " return " << maxR << endl;

        for( unsigned int i = 0; i < _elements.size(); i++ ){
	
	        KeiRo::Base::Coord2 &coordM = _elements[ i ];
	        KeiRo::Base::Coord2 &coordN = _elements[ (i+1)%(int)_elements.size() ];
	        KeiRo::Base::Coord2 mnVec = coordN - coordM;
	        KeiRo::Base::Coord2 cmVec = coord - coordM;
            double D = ( mnVec * cmVec ) / mnVec.squaredNorm();
	        KeiRo::Base::Coord2 coordD = coordM + D*mnVec;

            if( KeiRo::Base::Line2::isOnLine( coordD, coordM, coordN )){

                double dist = ( coord - coordD ).norm();
                if( dist < maxR ) maxR = dist;
            }
        }

        return maxR;
    }

    //------------------------------------------------------------------------------
    //	Friend functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	I/O functions
    //------------------------------------------------------------------------------
    //
    //  operator << --	output
    //
    //  Inputs
    //	s	: reference to output stream
    //	v	: 2D coordinates
    //
    //  Outputs
    //	reference to output stream
    //
    ostream & operator << ( ostream & stream, const Polygon2 & obj )
    {
        // set the output formatting
        //stream << setiosflags( ios::showpoint );
        //stream << setprecision( 8 );
        //int width = 16;
        // print out the elements
        for ( unsigned int i = 0; i < obj._elements.size(); i++ ) {
            //stream << setw( width ) << obj._element[ i ];
            stream << setw( 4 ) << obj._elements[ i ];
            if ( i != 1 ) stream << "\t";
        }
        stream << endl;

        return stream;
    }

    //
    //  operator >> --	input
    //
    //  Inputs
    //	s	: reference to input stream
    //	v	: 2D coordinates
    //
    //  Outputs
    //	reference to input stream
    //
    istream & operator >> ( istream & stream, Polygon2 & obj )
    {
        // reading the elements
        for ( unsigned int i = 0; i < obj._elements.size(); i++ )
        stream >> obj._elements[ i ];
        return stream;
    }

} // namespace Base
} // namespace KeiRo




