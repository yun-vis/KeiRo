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
	
	    // Rectangle2 fixed coordinates of end points, usually the initial value
	    Coord2      _fixedLeftBottom;
	    double      _fixedWidth;
	    double      _fixedHeight;
	
	    // Rectangle2 old coordinates of end points
        Coord2      _oldLeftBottom;
	    double      _oldWidth;
	    double      _oldHeight;
	
	    // Rectangle2 original coordinates of end points
        Coord2      _leftBottom;
        double      _width;
        double      _height;
        
            // Rectangle2 intermediate coordinates of end points
        Coord2      _intermediateLeftBottom;
        double      _intermediateWidth;
        double      _intermediateHeight;
        
        // Rectangle2 intermediate coordinates of end points
        Coord2      _unshrunkLeftBottom;
        double      _unshrunkWidth;
        double      _unshrunkHeight;
        
        // whether -Intermediate... holds useful information
        bool	_inLocalMove;
        
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
        
        // left-bottom corner
        Coord2 &	        fixedLeftBottom( void )         { return _fixedLeftBottom; }
	    const Coord2 &	    fixedLeftBottom( void ) const	{ return _fixedLeftBottom; }
	
	    double &	        fixedWidth( void )	        { return _fixedWidth; }
	    const double &	    fixedWidth( void ) const	{ return _fixedWidth; }
	
	    double &	        fixedHeight( void )	        { return _fixedHeight; }
	    const double &	    fixedHeight( void ) const	{ return _fixedHeight; }
	    
        // left-bottom corner
        Coord2 &	        oldLeftBottom( void )       { return _oldLeftBottom; }
	    const Coord2 &	    oldLeftBottom( void ) const	{ return _oldLeftBottom; }

	    double &	        oldWidth( void )	        { return _oldWidth; }
	    const double &	    oldWidth( void ) const	    { return _oldWidth; }
	
	    double &	        oldHeight( void )	        { return _oldHeight; }
	    const double &	    oldHeight( void ) const	    { return _oldHeight; }
	
	    // left-bottom corner
	    Coord2 &	        leftBottom( void )	        { return _leftBottom; }
	    const Coord2 &	    leftBottom( void ) const	{ return _leftBottom; }
	
	    double &	        width( void )	            { return _width; }
	    const double &	    width( void ) const	        { return _width; }
	
	    double &	        height( void )	            { return _height; }
	    const double &	    height( void ) const	    { return _height; }
	    
	    // left-bottom corner
	    Coord2 &		intermediateLeftBottom( void )	{ return _intermediateLeftBottom; }
	    const Coord2 &	intermediateLeftBottom( void ) const	{ return _intermediateLeftBottom; }
	
	    double &		intermediateWidth( void )		{ return _intermediateWidth; }
	    const double &	intermediateWidth( void ) const	{ return _intermediateWidth; }
	
	    double &		intermediateHeight( void )		{ return _intermediateHeight; }
	    const double &	intermediateHeight( void ) const	{ return _intermediateHeight; }
	    
	    Coord2 &		unshrunkLeftBottom( void )	{ return _unshrunkLeftBottom; }
	    const Coord2 &	unshrunkLeftBottom( void ) const	{ return _unshrunkLeftBottom; }
	
	    double &		unshrunkWidth( void )		{ return _unshrunkWidth; }
	    const double &	unshrunkWidth( void ) const	{ return _unshrunkWidth; }
	
	    double &		unshrunkHeight( void )		{ return _unshrunkHeight; }
	    const double &	unshrunkHeight( void ) const	{ return _unshrunkHeight; }
	    
	    bool &		inLocalMove( void )		{ return _inLocalMove; }
	    const bool &	inLocalMove( void ) const	{ return _inLocalMove; }
	    
	    //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        // initialization
        void init( void ) { _init(); }
	    void clear( void ) { _clear(); }
        bool isInside( Coord2 c );
	    bool isOverlap( Rectangle2 r, double &area );
	    void updateOldElement( void );
	    void updateIntermediateElement( Coord2 & c, double width, double height );
	    void updateUnshrunkElement( Coord2 & c, double width, double height );
	    void resetInLocalMove( void );
	    void updateFixedElement( void );
	    Coord2 projectedOnBoundary( Coord2 c );
		
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
