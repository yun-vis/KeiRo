//******************************************************************************
// TreeVertexProperty.h
//	: header file for tree vertex property
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sun Feb 09 23:16:12 2020
//
//******************************************************************************

#ifndef	_Graph_TreeVertexProperty_H
#define _Graph_TreeVertexProperty_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#include "Coord2.h"
#include "Rectangle2.h"
#include "Common.h"
#include "BaseVertexProperty.h"

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------
#define VERTEX_CAPACITY (1)

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

namespace Graph {

    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class TreeVertexProperty: public BaseVertexProperty {

    private:

    protected:

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
          void		    _init( void );

    public:

        unsigned int                level;                  // hierarchical level
        unsigned int                attributeID;            // external attribute ID
	
	    KeiRo::Base::Coord2         meanCoord;
	    KeiRo::Base::Coord2         *leftBottomCoordPtr;    // area of the tree cell
	    double                      *areaCoveragePtr;       // area coverage of the tree node
	    KeiRo::Base::Rectangle2     *boundingBoxPtr;        // bounding box of the tree cell
	
	    vector< unsigned int >      leafIDVec;              // id in samples
	    map< unsigned int, unsigned int >      childMap;    // vid of children in TreeGraph
		unsigned int                parentID;               // each tree node has one parent node, the root has the parent node as itself
	    
        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        TreeVertexProperty( void );
        // copy constructor
        TreeVertexProperty( const TreeVertexProperty & c ) {}
        // destructor
        virtual ~TreeVertexProperty( void ) {}

        //------------------------------------------------------------------------------
        //	Assignment operators
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Reference to elements
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------

        void        init( void )		{ _init(); }

        //------------------------------------------------------------------------------
        //	Friend functions
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream &	operator << ( ostream & s, const TreeVertexProperty & v );
        // input
        friend istream &	operator >> ( istream & s, TreeVertexProperty & v );
        // class name
        virtual const char * className( void ) const { return "TreeVertexProperty"; }

    };

} // namespace Graph

#endif // _Graph_TreeVertexProperty_H
