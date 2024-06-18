//******************************************************************************
// GridGraphProperty.h
//	: header file for tree graph property
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sun Feb 09 23:16:12 2020
//
//******************************************************************************

#ifndef	_Graph__GridGraphProperty_H
#define _Graph__GridGraphProperty_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <iostream>

using namespace std;

#include "Coord2.h"
#include "Common.h"
#include "BaseGraphProperty.h"


//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

namespace Graph {

    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class GridGraphProperty: public BaseGraphProperty {

    private:

    protected:

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
         void		    _init( double &width, double &height );

    public:

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        GridGraphProperty( void );
        // copy constructor
        GridGraphProperty( const GridGraphProperty & c ) {}
        // destructor
        virtual ~GridGraphProperty( void ) {}

        //------------------------------------------------------------------------------
        //	Assignment operators
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Reference to elements
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------

        void        init( double &__width, double &__height ) {
            _init( __width, __height );
        }

        //------------------------------------------------------------------------------
        //	Friend functions
        //------------------------------------------------------------------------------


        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream &	operator << ( ostream & s, const GridGraphProperty & v );
        // input
        friend istream &	operator >> ( istream & s, GridGraphProperty & v );
        // class name
        virtual const char * className( void ) const { return "GridGraphProperty"; }

    };

} // namespace Graph

#endif // _Graph_GridGraphProperty_H
