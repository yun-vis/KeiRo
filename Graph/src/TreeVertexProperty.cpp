//******************************************************************************
// TreeVertexProperty.h
//	: program file for tree vertex property
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

#include "TreeVertexProperty.h"

namespace Graph {

    //------------------------------------------------------------------------------
    //	Private Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------
    //
    //  TreeVertexProperty::_init -- initialize the graph.
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void TreeVertexProperty::_init( void )
    {
        BaseVertexProperty::_init();

        // leafID              = -1;
        meanCoord.x()       = 0.0;
        meanCoord.y()       = 0.0;
        // leafVec.clear();
    }

    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  TreeVertexProperty::TreeVertexProperty -- default constructor
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    TreeVertexProperty::TreeVertexProperty()
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
    //	obj	: TreeVertexProperty
    //
    //  Outputs
    //	reference to output stream
    //
    ostream & operator << ( ostream & stream, const TreeVertexProperty & obj )
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
    //	obj	: TreeVertexProperty
    //
    //  Outputs
    //	reference to input stream
    //
    istream & operator >> ( istream & stream, TreeVertexProperty & obj )
    {
        return stream;
    }

} // namespace Graph