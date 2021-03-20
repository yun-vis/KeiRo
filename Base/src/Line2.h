//******************************************************************************
// Line2.h
//	: header file for 2D Line2 coordinates
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Dec 27 23:16:12 2017
//
//******************************************************************************

#ifndef	_Base_Line2_H
#define _Base_Line2_H

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
    class Line2 : public Object {

    protected:

        // Line2 original coordinates of end points
        vector< Coord2 >        _fixedElements;
	    // Line2 old sample points
	    vector< Coord2 >        _oldElements;
        // Line2 sample points
        vector< Coord2 >        _elements;
	    // Line2 pointer-based sample points
	    vector< Coord2* >       _elementPointers;
        // Line2 sample id
        vector< unsigned int >  _idElements;
        // Line2 curve sample points
        vector< Coord2 >        _fineElements;
        

        //------------------------------------------------------------------------------
        //	Attribute
        //------------------------------------------------------------------------------
        // select flag
        bool                    _isSelected;

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
        Line2( void );
        // parameterized constructor
        Line2( vector< Coord2 > __elements );
        // copy constructor
        Line2( const Line2 & v );
        // destructor
        virtual ~Line2( void ) {}

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
	
	    // reference to a vector of coordinates
	    vector< Coord2* > &	            elementPointers( void )	        { return _elementPointers; }
	    const vector< Coord2* > &	    elementPointers( void ) const   { return _elementPointers; }

        // reference to an array of fixed coordinates
        vector< Coord2 > &	            fixedElements( void )	        { return _fixedElements; }
        const vector< Coord2 > &	    fixedElements( void ) const	    { return _fixedElements; }

        // reference to an array of coordinate pointers
        vector< unsigned int > &	    idElements( void )	            { return _idElements; }
        const vector< unsigned int > &  idElements( void ) const        { return _idElements; }

        // reference to the fine sample points
        vector< Coord2 > &              fineElements( void )            { return _fineElements; }
        const vector< Coord2 > &        fineElements( void ) const      { return _fineElements; }

        // select flag
        bool &	                        isSelected( void )	            { return _isSelected; }
        const bool &	                isSelected( void ) const	    { return _isSelected; }
        
        
	    // graphics item
//        void setItemPtr( Ui::Vector::GraphicsEdgeItem * ptr )	        { _itemPtr = ptr; }
//        Ui::Vector::GraphicsEdgeItem * getItemPtr( void )               { return _itemPtr; }

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        // initialization
        void init( void ) { _init(); }
        void initElementPointers( void );

        void addSample( Coord2 &coord );
        void computeChaikinCurve( int num, double unit );

        static bool isOnLine( Coord2 &a, Coord2 &b, Coord2 &c );
	    void updateOldElement( void );
	    void updateOldElementByPointers( void );
	    void simplifyGeometry( void );
	
	    //------------------------------------------------------------------------------
        //	Friend functions
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream &	operator << ( ostream & s, const Line2 & v );
        // input
        friend istream &	operator >> ( istream & s, Line2 & v );
        // class name
        virtual const char * className( void ) const { return "Line2"; }

    };
	
} // namespace Base
} // namespace KeiRo

#endif // _Base_Line2_H
