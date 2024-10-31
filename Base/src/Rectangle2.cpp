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
    	_leftBottom.zero();
    	_oldLeftBottom.zero();
		_fixedLeftBottom.zero();
    	_width = _oldWidth = _fixedWidth = _height = _oldHeight = _fixedHeight = 0.0;
    }

    //
    //  Polygon2::_reset --	reset elements
    //
    //  Inputs
    //
    //
    //  Outputs
    //  none
    //
    void Rectangle2::_reset( void )
    {
        _leftBottom = _oldLeftBottom = _fixedLeftBottom;
        _oldWidth = _width;
        _oldHeight = _height;
        _width = _fixedWidth;
        _height = _fixedHeight;
    }

    //
    //  Polygon2::_setFixed --	set fixed elements
    //
    //  Inputs
    //
    //
    //  Outputs
    //  none
    //
    void Rectangle2::_setFixed( void )
    {
        _fixedLeftBottom = _leftBottom ;
        _fixedWidth = _width;
        _fixedHeight = _height;
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
	    _leftBottom.x()     = x;
	    _leftBottom.y()     = y;
	    _width              = w;
	    _height             = h;
	
	    _fixedLeftBottom.x()  = x;
	    _fixedLeftBottom.y()  = y;
	    _fixedWidth           = w;
	    _fixedHeight          = h;
		
	    _oldLeftBottom.x()  = x;
	    _oldLeftBottom.y()  = y;
	    _oldWidth           = w;
	    _oldHeight          = h;
	    
	    _intermediateLeftBottom.x()= x;
	    _intermediateLeftBottom.y()= y;
	    _intermediateWidth		= w;
	    _intermediateHeight	= h;
	    
	    _unshrunkLeftBottom.x()	= x;
	    _unshrunkLeftBottom.y()	= y;
	    _unshrunkWidth		= w;
	    _unshrunkHeight		= h;
	    
	    _inLocalMove		= false;
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
	
	    _leftBottom         = v._leftBottom;
        _width              = v._width;
        _height             = v._height;
	
	    _fixedLeftBottom    = v._fixedLeftBottom;
	    _fixedWidth         = v._fixedWidth;
	    _fixedHeight        = v._fixedHeight;
		
	    _oldLeftBottom      = v._oldLeftBottom;
	    _oldWidth           = v._oldWidth;
	    _oldHeight          = v._oldHeight;
	    
	    _intermediateLeftBottom	= v._intermediateLeftBottom;
	    _intermediateWidth		= v._intermediateWidth;
	    _intermediateHeight	= v._intermediateHeight;
	    
	    _unshrunkLeftBottom	= v._unshrunkLeftBottom;
	    _unshrunkWidth		= v._unshrunkWidth;
	    _unshrunkHeight		= v._unshrunkHeight;
	    
	    _inLocalMove		= false;
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
    	if ( ( _leftBottom.x() < c.x()) && ( c.x() < _leftBottom.x() + _width) &&
	         ( _leftBottom.y() < c.y()) && ( c.y() < _leftBottom.y() + _height) )
    		return true;
    	return false;
    }
	
	//
	//  Polygon2::isOverlap -- check if the two rectangle overlapped
	//
	//  Inputs
	//  Rectangle2 r
	//
	//  Outputs
	//  none
	//
	bool Rectangle2::isOverlap( Rectangle2 r, double &area )
	{
    	area = 0.0;
    	
    	Coord2 ci = _leftBottom + Coord2( 0.5*_width, 0.5*_height );
		Coord2 cj = r._leftBottom + Coord2( 0.5*r._width, 0.5*r._height );
    	double w = MAX2( 0.0, MIN2( 0.5*(_width+r._width)-fabs(ci.x()-cj.x()), MIN2( _width, r._width )) );
    	double h = MAX2( 0.0, MIN2( 0.5*(_height+r._height)-fabs(ci.y()-cj.y()), MIN2( _height, r._height )) );
		area = w*h;

		if( area > 0.0 ) return true;
		else return false;
	}
	
	//
	//  Polygon2::isOverlap -- check if the two rectangle overlapped
	//
	//  Inputs
	//  Rectangle2 r
	//
	//  Outputs
	//  none
	//
	Coord2 Rectangle2::projectedOnBoundary( Coord2 c )
	{
		Coord2 projectedC;
		Coord2 diff = c - _leftBottom;
		
		if( isInside( c ) == false ){
			cerr << "sth is wrong here... " << __LINE__ << " in file " << __FILE__ << endl;
		}
		
		double left = fabs( diff.x() );
		double right = _width - fabs( diff.x() );
		double bottom = fabs( diff.y() );
		double top = _height - fabs( diff.y() );
		
		if( left < right && left < bottom && left < top ){
			projectedC.x() = _leftBottom.x();
			projectedC.y() = c.y();
		}
		if( right < left && right < bottom && right < top ){
			projectedC.x() = _leftBottom.x() + _width;
			projectedC.y() = c.y();
		}
		if( bottom < left && bottom < right && bottom < top ){
			projectedC.x() = c.x();
			projectedC.y() = _leftBottom.y();
		}
		if( top < left && top < right && top < bottom ){
			projectedC.x() = c.x();
			projectedC.y() = _leftBottom.y() + _height;
		}
#ifdef DEBUG
		cerr << "c = " << c
			 << "lb = " << _leftBottom
			 << "w = " << _width << ",h = " << _height << endl
			 << "projC = " << projectedC << endl;
#endif // DEBUG
		return projectedC;
	}
	
	void Rectangle2::updateOldElement( void )
	{
		_oldLeftBottom  = _leftBottom;
		_oldWidth       = _width;
		_oldHeight      = _height;
		resetInLocalMove();
	}
	
	void Rectangle2::updateIntermediateElement( Coord2 & c, double width, double height )
	{
		// if already in local move, restrict intermediate element to intersection
		if(_inLocalMove) {
			// first fix horizontal measurements
			if( c.x() + width < _intermediateLeftBottom.x() + _intermediateWidth ) {
			// right side of new box is left of right side of old box
				if( c.x() < _intermediateLeftBottom.x() ) {
				// left side of new box is left of left side of old box
					_intermediateWidth = width - (_intermediateLeftBottom.x() - c.x());
					
				} else { // left side of new box is right of left side of old box
					_intermediateLeftBottom.x() = c.x();
					_intermediateWidth = width;
				}
				
			} else {
			// right side of new box is right of right side of old box
				if( c.x() >= _intermediateLeftBottom.x() ) {
				// left side of new box is right of left side of old box
					_intermediateWidth = _intermediateWidth - (c.x() - _intermediateLeftBottom.x());
					_intermediateLeftBottom.x() = c.x();
				
				} // no 'else' because then the old box is completely inside new box 
				
			}
			
			// then fix vertical measurements
			if( c.y() + height < _intermediateLeftBottom.y() + _intermediateHeight ) {
			// top side of new box is below of top side of old box
				if( c.y() < _intermediateLeftBottom.y() ) {
				// bottom side of new box is below the bottom side of old box
					_intermediateHeight = height - (_intermediateLeftBottom.y() - c.y());
					
				} else { // bottom side of new box is above the bottom side of old box
					_intermediateLeftBottom.y() = c.y();
					_intermediateHeight = height;
				}
				
			} else {
			// top side of new box is above the top side of old box
				if( c.y() >= _intermediateLeftBottom.y() ) {
				// bottom side of new box is above the bottom side of old box
					_intermediateHeight = _intermediateHeight - (c.y() - _intermediateLeftBottom.y());
					_intermediateLeftBottom.y() = c.y();
				
				} // no 'else' because then the old box is completely inside new box 
				
			}
			
		} else { // otherwise simply set intermediate values
			_intermediateLeftBottom  = c;
			_intermediateWidth       = width;
			_intermediateHeight      = height;
			_inLocalMove = true;
		}
	}
	
	void Rectangle2::updateUnshrunkElement( Coord2 & c, double width, double height )
	{
		_unshrunkLeftBottom	= c;
		_unshrunkWidth		= width;
		_unshrunkHeight	= height;
	}
	
	void Rectangle2::resetInLocalMove( void )
	{
		_inLocalMove = false;
	}
	
	void Rectangle2::updateFixedElement( void )
	{
		_fixedLeftBottom  = _leftBottom;
		_fixedWidth       = _width;
		_fixedHeight      = _height;
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
	    stream << setw( width ) << "ox = " << obj._oldLeftBottom.x() << ", oy = " << obj._oldLeftBottom.y() << ", ";
	    stream << setw( width ) << "ow = " << obj._oldWidth << ", oh = " << obj._oldHeight << endl;
//        stream << endl;

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
