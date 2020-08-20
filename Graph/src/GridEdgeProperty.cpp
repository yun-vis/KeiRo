//******************************************************************************
// GridEdgeProperty.xpp
//	: program file for grid edge property
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Feb 09 23:16:12 2020
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

#include "GridEdgeProperty.h"

namespace Graph {

    //------------------------------------------------------------------------------
    //	Private Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------
    //
    //  GridEdgeProperty::_init -- initialize the graph.
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void GridEdgeProperty::_init( void )
    {
        BaseEdgeProperty::_init();
    }

    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  GridEdgeProperty::GridEdgeProperty -- default constructor
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    GridEdgeProperty::GridEdgeProperty()
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
    //	obj	: GridEdgeProperty
    //
    //  Outputs
    //	reference to output stream
    //
    ostream & operator << ( ostream & stream, const GridEdgeProperty & obj )
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
    //	obj	: GridEdgeProperty
    //
    //  Outputs
    //	reference to input stream
    //
    istream & operator >> ( istream & stream, GridEdgeProperty & obj )
    {
        return stream;
    }

} // namespace Graph