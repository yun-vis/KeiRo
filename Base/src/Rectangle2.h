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
	
	    // Rectangle2 old coordinates of end points
        Coord2      _oldLeftBottom;
	    double      _oldWidth;
	    double      _oldHeight;
	
	    // Rectangle2 original coordinates of end points
        Coord2      _leftBottom;
        double      _width;
        double      _height;

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

        // left-top corner
        Coord2 &	        oldLeftBottom( void )       { return _oldLeftBottom; }
	    const Coord2 &	    oldLeftBottom( void ) const	{ return _oldLeftBottom; }

	    double &	        oldWidth( void )	        { return _oldWidth; }
	    const double &	    oldWidth( void ) const	    { return _oldWidth; }
	
	    double &	        oldHeight( void )	        { return _oldHeight; }
	    const double &	    oldHeight( void ) const	    { return _oldHeight; }
	
	    // left-top corner
	    Coord2 &	        leftBottom( void )	        { return _leftBottom; }
	    const Coord2 &	    leftBottom( void ) const	{ return _leftBottom; }
	
	    double &	        width( void )	            { return _width; }
	    const double &	    width( void ) const	        { return _width; }
	
	    double &	        height( void )	            { return _height; }
	    const double &	    height( void ) const	    { return _height; }
	
	    //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        // initialization
        void init( void ) { _init(); }
        bool isInside( Coord2 c );
	    void        updateOldElement( void );
	    
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
