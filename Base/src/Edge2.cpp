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

	    _fill               = v._fill;
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
	
	bool Edge2::isOnEdge( Coord2 c ) {

    	bool isOn = false;
    	Coord2 diff = _elements[1] - _elements[0];
    	Coord2 diffC = c - _elements[0];
		
		if( diff.x() == 0 ){
			if( diffC.x() == 0 &&
				( c.y() >= MIN2( _elements[0].y(), _elements[1].y() ) ) &&
				( c.y() <= MAX2( _elements[0].y(), _elements[1].y() ) )
				)
				return true;
		}
		else{
			if( diffC.norm() < diff.norm() ){
				// L: mx -y + b = 0
				
			}
			double m = diff.y()/diff.x();
			double b = _elements[0].y() - m * _elements[0].x();
			double dist = fabs( m * c.x() - c.y() + b )/sqrt( SQUARE( m ) + 1.0 );
			if( dist == 0.0 &&
			    ( c.x() >= MIN2( _elements[0].x(), _elements[1].x() ) ) &&
			    ( c.x() <= MAX2( _elements[0].x(), _elements[1].x() ) ) &&
			    ( c.y() >= MIN2( _elements[0].y(), _elements[1].y() ) ) &&
			    ( c.y() <= MAX2( _elements[0].y(), _elements[1].y() ) )
				)
				return true;
		}
  
		return isOn;
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
