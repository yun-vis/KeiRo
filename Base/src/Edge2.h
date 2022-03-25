//******************************************************************************
// Edge2.h
//	: header file for 2D Edge2 coordinates
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Dec 27 23:16:12 2017
//
//******************************************************************************

#ifndef	_Base_Edge2_H
#define _Base_Edge2_H

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
    class Edge2 : public Object {

    protected:

        // Edge2 original coordinates of end points
        vector< Coord2 >        _fixedElements;
	    // Edge2 old sample points
	    vector< Coord2 >        _oldElements;
        // Edge2 sample points
        vector< Coord2 >        _elements;

        //------------------------------------------------------------------------------
        //	Attribute
        //------------------------------------------------------------------------------
        // select flag
        bool                    _isSelected;
		
	    // edge style
	    bool                    _isClosed;

        // graphics item pointer
//        Ui::Vector::GraphicsEdgeItem * _itemPtr;

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        // initialize all coordinates to zero
        void _init( void );
        void _clear( void );
        void _initChaikinCurve( double unit );

    public:

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        Edge2( void );
        // parameterized constructor
        Edge2( vector< Coord2 > __elements );
        // copy constructor
        Edge2( const Edge2 & v );
        // destructor
        virtual ~Edge2( void ) {}

        //------------------------------------------------------------------------------
        //	Assignment operators
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Reference to elements
        //------------------------------------------------------------------------------
	
	    // reference to a vector of coordinates
	    vector< Coord2 > &	            oldElements( void )	            { return _oldElements; }
	    const vector< Coord2 > &	    oldElements( void ) const	    { return _oldElements; }

        // reference to a vector of coordinates
        vector< Coord2 > &	            elements( void )	            { return _elements; }
        const vector< Coord2 > &	    elements( void ) const	        { return _elements; }

        // reference to an array of fixed coordinates
        vector< Coord2 > &	            fixedElements( void )	        { return _fixedElements; }
        const vector< Coord2 > &	    fixedElements( void ) const	    { return _fixedElements; }

		// style
		bool &	                        isClosed( void )	            { return _isClosed; }
	    const bool &	                isClosed( void ) const	        { return _isClosed; }
		
	    // graphics item
//        void setItemPtr( Ui::Vector::GraphicsEdgeItem * ptr )	        { _itemPtr = ptr; }
//        Ui::Vector::GraphicsEdgeItem * getItemPtr( void )               { return _itemPtr; }

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        // initialization
        void init( void ) { _init(); }
        bool isIntersected( Edge2 e );
        bool isOnEdge( Coord2 c );
        
	    //------------------------------------------------------------------------------
        //	Friend functions
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream &	operator << ( ostream & s, const Edge2 & v );
        // input
        friend istream &	operator >> ( istream & s, Edge2 & v );
        // class name
        virtual const char * className( void ) const { return "Edge2"; }

    };
	
} // namespace Base
} // namespace KeiRo

#endif // _Base_Edge2_H
