//******************************************************************************
// BaseEdgeProperty.cc
//	: program file for 2D coordinatse
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

#include "BoundaryEdgeProperty.h"

namespace Graph {
//------------------------------------------------------------------------------
//	Macro Definitions
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//	Protected Functions
//------------------------------------------------------------------------------
//
//  BoundaryEdgeProperty::_init -- initialize the graph.
//
//  Inputs
//  none
//
//  Outputs
//  none
//
	void BoundaryEdgeProperty::_init( void ) {
		id = 0;
		weight = 1.0;
		visitedTimes = -1;
	}

//------------------------------------------------------------------------------
//	Public functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	Constuructors
//------------------------------------------------------------------------------

//
//  BoundaryEdgeProperty::BoundaryEdgeProperty -- default constructor
//
//  Inputs
//  none
//
//  Outputs
//  none
//
	BoundaryEdgeProperty::BoundaryEdgeProperty() {
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
//	obj	: BoundaryEdgeProperty
//
//  Outputs
//	reference to output stream
//
	ostream &operator<<( ostream &stream, const BoundaryEdgeProperty &obj ) {
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
//	obj	: BoundaryEdgeProperty
//
//  Outputs
//	reference to input stream
//
	istream &operator>>( istream &stream, BoundaryEdgeProperty &obj ) {
		return stream;
	}
	
}