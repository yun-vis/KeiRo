//******************************************************************************
// Line2.h
//	: header file for 2D Line2 coordinates
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Dec 27 23:16:12 2017
//
//******************************************************************************

#ifndef	_Base_Rectangle2_H
#define _Base_Rectangle2_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <vector>
#include <iostream>

using namespace std;

#include "Coord2.h"
#include "Object.h"
//#include "ui/vector/GraphicsEdgeItem.h"

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------
namespace KeiRo {
namespace Base {

    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class Rectangle2 : public Object {

    protected:

        // Rectangle2 original coordinates of end points
        double		_elements[ 4 ];	// x, y coordinates & width & height


        //------------------------------------------------------------------------------
        //	Attribute
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        // initialize all coordinates to zero
        void _init( void );
        void _clear( void );

    public:

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        Rectangle2( void );
        // parameterized constructor
        Rectangle2( double x, double y, double w, double h );
        // copy constructor
        Rectangle2( const Rectangle2 & v );
        // destructor
        virtual ~Rectangle2( void ) {}

        //------------------------------------------------------------------------------
        //	Assignment operators
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Reference to elements
        //------------------------------------------------------------------------------

        // reference to a vector of coordinates
        void 	            setX( double x )	        { _elements[0] = x; }
	    const double &	    getX( void ) const	        { return _elements[0]; }
	
	    void 	            setY( double y )	        { _elements[1] = y; }
	    const double &	    getY( void ) const	        { return _elements[1]; }
	
	    void 	            setWidth( double w )	    { _elements[2] = w; }
	    const double &	    getWidth( void ) const	    { return _elements[2]; }
	
	    void 	            setHeight( double h )	    { _elements[3] = h; }
	    const double &	    getHeight( void ) const	    { return _elements[3]; }
	    
        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        // initialization
        void init( void ) { _init(); }

        //------------------------------------------------------------------------------
        //	Friend functions
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream &	operator << ( ostream & s, const Rectangle2 & v );
        // input
        friend istream &	operator >> ( istream & s, Rectangle2 & v );
        // class name
        virtual const char * className( void ) const { return "Rectangle2"; }

    };
	
} // namespace Base
} // namespace KeiRo

#endif // _Base_Rectangle2_H
