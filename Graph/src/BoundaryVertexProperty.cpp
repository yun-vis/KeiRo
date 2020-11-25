//******************************************************************************
// BaseVertexProperty.cc
//	: program file for 2D coordinates
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

#include "BoundaryVertexProperty.h"


//------------------------------------------------------------------------------
//	Macro Definitions
//------------------------------------------------------------------------------

namespace Graph {

//------------------------------------------------------------------------------
//	Protected Functions
//------------------------------------------------------------------------------
//
//  BoundaryVertexProperty::_init -- initialize the graph.
//
//  Inputs
//  none
//
//  Outputs
//  none
//
	void BoundaryVertexProperty::_init( void ) {
		BaseVertexProperty::init();
		
		initID = 0;
		isFixed = false;
		
		geoPtr = NULL;
		smoothPtr = NULL;
		centroidPtr = NULL;
	}

//------------------------------------------------------------------------------
//	Public functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	Constructors
//------------------------------------------------------------------------------

//
//  BoundaryVertexProperty::BoundaryVertexProperty -- default constructor
//
//  Inputs
//  none
//
//  Outputs
//  none
//
	BoundaryVertexProperty::BoundaryVertexProperty() {
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
//	obj	: BoundaryVertexProperty
//
//  Outputs
//	reference to output stream
//
	ostream &operator<<( ostream &stream, const BoundaryVertexProperty &obj ) {
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
//	obj	: BoundaryVertexProperty
//
//  Outputs
//	reference to input stream
//
	istream &operator>>( istream &stream, BoundaryVertexProperty &obj ) {
		return stream;
	}
	
}