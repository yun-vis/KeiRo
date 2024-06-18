//******************************************************************************
// TreeGraphProperty.h
//	: header file for tree graph property
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sun Feb 09 23:16:12 2020
//
//******************************************************************************

#ifndef	_Graph__TreeGraphProperty_H
#define _Graph__TreeGraphProperty_H

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
    class TreeGraphProperty: public BaseGraphProperty {

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
        TreeGraphProperty( void );
        // copy constructor
        TreeGraphProperty( const TreeGraphProperty & c ) {}
        // destructor
        virtual ~TreeGraphProperty( void ) {}

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
        friend ostream &	operator << ( ostream & s, const TreeGraphProperty & v );
        // input
        friend istream &	operator >> ( istream & s, TreeGraphProperty & v );
        // class name
        virtual const char * className( void ) const { return "TreeGraphProperty"; }

    };

} // namespace Graph

#endif // _Graph_TreeGraphProperty_H
