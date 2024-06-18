// Orthogonal.cpp
//  : program file for the boundary network
//
//------------------------------------------------------------------------------
//
//              Date: Mon Dec 10 04:28:26 2012
//
//==============================================================================

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>

using namespace std;

#include <qapplication.h>
#include "Schematization.h"

//template function bodies need to ALL be in the header files
//template class Schematization< Graph::SchematicGraph >;

//------------------------------------------------------------------------------
//	Protected functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	Public functions
//------------------------------------------------------------------------------
//
//  Schematization::clear --        memory management
//
//  Inputs
//      none
//
//  Outputs
//      none
//
template <typename GraphType>
void Schematization<GraphType>::clear( void ) {
}

//------------------------------------------------------------------------------
//	Public functions
//------------------------------------------------------------------------------
//
//  Schematization::Orthogonal -- copy constructor
//
//  Inputs
//  obj : object of this class
//
//  Outputs
//  none
//
template <typename GraphType>
Schematization<GraphType>::Schematization( const Schematization<GraphType> &obj ) {

	_optType = obj._opttype;

	_graph = obj._graph;
	_half_width = obj._half_width;      // window_width
	_half_height = obj._half_height;    // window_height

	_nVars = obj._nVars;
	_nConstrs = obj._nConstrs;
	_w_schematization = obj._w_Orthogonal;
	_w_position = obj._w_position;
	_w_fixposition = obj._w_fixposition;
	_w_boundary = obj._w_boundary;
	_w_crossing = obj._w_crossing;
	//_d_Alpha = obj._d_Alpha;
	_d_Beta = obj._d_Beta;
	_theta = obj._theta;
}


//------------------------------------------------------------------------------
//	Destructor
//------------------------------------------------------------------------------
//
//  Schematization::~Orthogonal --    destructor
//
//  Inputs
//  none
//
//  Outputs
//  none
//
template <typename GraphType>
Schematization<GraphType>::~Schematization<GraphType>( void ) {
}

// end of header file
// Do not add any stuff under this line.

