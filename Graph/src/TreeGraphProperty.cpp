//******************************************************************************
// TreeGraphProperty.cpp
//	: program file for tree graph
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Dec 27 23:15:32 2017
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

#include "TreeGraphProperty.h"

namespace Graph {

    //------------------------------------------------------------------------------
    //	Private Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------
    //
    //  TreeGraphProperty::_init -- initialize the graph.
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void TreeGraphProperty::_init( double &width, double &height )
    {
        BaseGraphProperty::_init( width, height );
    }

    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  TreeGraphProperty::TreeGraphProperty -- default constructor
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    TreeGraphProperty::TreeGraphProperty()
    {
        //BaseGraphProperty::init();
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
    //	obj	: TreeGraphProperty
    //
    //  Outputs
    //	reference to output stream
    //
    ostream & operator << ( ostream & stream, const TreeGraphProperty & obj )
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
    //	obj	: TreeGraphProperty
    //
    //  Outputs
    //	reference to input stream
    //
    istream & operator >> ( istream & stream, TreeGraphProperty & obj )
    {
        return stream;
    }

} // namespace Graph