//******************************************************************************
// GridVertexProperty.h
//	: program file for grid vertex property
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sun Feb 09 23:16:12 2020
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

#include "GridVertexProperty.h"

namespace Graph {

    //------------------------------------------------------------------------------
    //	Private Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------
    //
    //  GridVertexProperty::_init -- initialize the graph.
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void GridVertexProperty::_init( void )
    {
        BaseVertexProperty::_init();

        isOccupied          = false;
    }

    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  GridVertexProperty::GridVertexProperty -- default constructor
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    GridVertexProperty::GridVertexProperty()
    {
        _init();
    }



    //------------------------------------------------------------------------------
    //	Assignment operators
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	I/O functions
    //------------------------------------------------------------------------------
    //
    //  operator << --	output
    //
    //  Inputs
    //	stream	: reference to output stream
    //	obj	: GridVertexProperty
    //
    //  Outputs
    //	reference to output stream
    //
    ostream & operator << ( ostream & stream, const GridVertexProperty & obj )
    {
        // set the output formatting
        stream << setiosflags( ios::showpoint );
        stream << setprecision( 8 );
        stream << endl;

        return stream;
    }


    //
    //  operator >> --	input
    //
    //  Inputs
    //	stream	: reference to output stream
    //	obj	: GridVertexProperty
    //
    //  Outputs
    //	reference to input stream
    //
    istream & operator >> ( istream & stream, GridVertexProperty & obj )
    {
        return stream;
    }

} // namespace Graph