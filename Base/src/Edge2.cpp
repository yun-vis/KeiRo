//******************************************************************************
// Edge2.cpp
//	: program file for 2D Edge2 coordinates
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

#include "Edge2.h"

namespace KeiRo {
namespace Base {
		

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------
    //
    //  Edge2::init -- initialization
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void Edge2::_init( void )
    {
	    _elements.resize(2);
	    _oldElements.resize(2);
	    _fixedElements.resize(2);
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
    void Edge2::_clear( void )
    {
        _elements.clear();
	    _oldElements.clear();
        _fixedElements.clear();
    }

    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  Edge2::Edge2 -- default constructor
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    Edge2::Edge2()
    {
        _init();
        //Object::Object();
    }

    //
    //  Edge2::Edge2 -- parameterized constructor
    //
    //  Inputs
    //  __elements
    //
    //  Outputs
    //  none
    //
    Edge2::Edge2( vector< Coord2 > __elements )
    {
        _elements           = __elements;
	    _oldElements        = _elements;
        _fixedElements      = _elements;
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
    Edge2::Edge2( const Edge2 & v )
    {
        _id                 = v._id;
        _gid                = v._gid;
        _name               = v._name;
        _elements           = v._elements;
	    _oldElements        = v._oldElements;
        _fixedElements      = v._fixedElements;
        _isSelected         = v._isSelected;
	
	    _stroke             = v._stroke;
	    _strokeWidth        = v._strokeWidth;
	    _strokeOpacity      = v._strokeOpacity;

	    _fill               = v._fill;
	    _fillOpacity        = v._fillOpacity;
    }

    //------------------------------------------------------------------------------
    //	Assignment operators
    //------------------------------------------------------------------------------


    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    bool Edge2::isIntersected( Edge2 e ){
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
    ostream & operator << ( ostream & stream, const Edge2 & obj )
    {
        // set the output formatting
        stream << setiosflags( ios::showpoint );
        stream << setprecision( 8 );

        int width = 8;
        // print out the elements
        for ( unsigned int i = 0; i < obj.elements().size(); i++ ) {
            stream << setw( width ) << "(" << obj.elements()[i].x() << ", " << obj.elements()[i].y() << ") ";
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
    istream & operator >> ( istream & stream, Edge2 & obj )
    {
        return stream;
    }


} // namespace Base
} // namespace KeiRo
