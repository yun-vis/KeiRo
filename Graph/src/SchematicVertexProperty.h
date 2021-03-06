//******************************************************************************
// BoundaryVertexProperty.h
//	: header file for 2D coordinaes
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Dec 27 23:16:12 2011
//
//******************************************************************************

#ifndef _BoundaryVertexProperty_H
#define _BoundaryVertexProperty_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>

using namespace std;

#include "Coord2.h"
#include "Common.h"
#include "BaseVertexProperty.h"
//#include "ui/GraphicsVertexItem.h"

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//	Defining Classes
//------------------------------------------------------------------------------
namespace Graph {
	class SchematicVertexProperty : public BaseVertexProperty {
	
	protected:
		
		void _init( void );
	
	public:

//------------------------------------------------------------------------------
//	Constructors
//------------------------------------------------------------------------------
		SchematicVertexProperty();                // constructor (default)
		SchematicVertexProperty( const SchematicVertexProperty &v ) {
		}                    // copy constructor
		virtual ~SchematicVertexProperty() {}        // destructor

//------------------------------------------------------------------------------
//	Assignment operators
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	Reference to elements
//------------------------------------------------------------------------------
		unsigned int initID;
		bool isFixed;
		
		KeiRo::Base::Coord2 *geoPtr;         // initial position
		KeiRo::Base::Coord2 *smoothPtr;
		KeiRo::Base::Coord2 *centroidPtr;
//		GraphicsVertexItem *itemPtr;

//------------------------------------------------------------------------------
//	Special functions
//------------------------------------------------------------------------------
		
		void init( void ) { _init(); }

//------------------------------------------------------------------------------
//	Intersection check
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	Friend functions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//	I/O functions
//------------------------------------------------------------------------------
		
		friend ostream &operator<<( ostream &s, const SchematicVertexProperty &v );
		
		// Output
		friend istream &operator>>( istream &s, SchematicVertexProperty &v );
		
		// Input
		virtual const char *className( void ) const { return "BoundaryVertexProperty"; }
		// class name
		
	};
}
#endif // _BoundaryVertexProperty_H
