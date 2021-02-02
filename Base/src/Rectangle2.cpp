//******************************************************************************
// Rectangle2.cpp
//	: program file for 2D Rectangle2 coordinates
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Dec 27 23:15:32 2011
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

#include "Rectangle2.h"

namespace KeiRo {
namespace Base {
		

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------
    //
    //  Rectangle2::init -- initialization
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void Rectangle2::_init( void )
    {
        _clear();
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
    void Rectangle2::_clear( void )
    {
    }

    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  Rectangle2::Rectangle2 -- default constructor
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    Rectangle2::Rectangle2()
    {
        _init();
        
        //Object::Object();
    }

    //
    //  Rectangle2::Rectangle2 -- parameterized constructor
    //
    //  Inputs
    //  __elements
    //
    //  Outputs
    //  none
    //
    Rectangle2::Rectangle2( double x, double y, double w, double h )
    {
	    _leftBottom.x()    = x;
	    _leftBottom.y()    = y;
	    _width          = w;
	    _height         = h;
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
    Rectangle2::Rectangle2( const Rectangle2 & v )
    {
        _id                 = v._id;
        _gid                = v._gid;
        _name               = v._name;

        _leftBottom            = v._leftBottom;
        _width              = v._width;
        _height             = v._height;
    }

    //------------------------------------------------------------------------------
    //	Assignment operators
    //------------------------------------------------------------------------------


    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    //
    //  Polygon2::isInside -- check if the vertex inside the rectangle
    //
    //  Inputs
    //  Coord2 c
    //
    //  Outputs
    //  none
    //
    bool Rectangle2::isInside( Coord2 c )
    {
    	if ( (_leftBottom.x() < c.x()) && (c.x() < _leftBottom.x() + _width) &&
			 (_leftBottom.y() > c.y()) && (c.y() > _leftBottom.y() - _height) )
    		return true;
    	return false;
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
    ostream & operator << ( ostream & stream, const Rectangle2 & obj )
    {
        // set the output formatting
        stream << setiosflags( ios::showpoint );
        stream << setprecision( 8 );

        int width = 8;
        // print out the elements
        stream << setw( width ) << "x = " << obj._leftBottom.x() << ", y = " << obj._leftBottom.y() << ", ";
	    stream << setw( width ) << "w = " << obj._width << ", h = " << obj._height << endl;
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
    istream & operator >> ( istream & stream, Rectangle2 & obj )
    {
        return stream;
    }


} // namespace Base
} // namespace KeiRo
