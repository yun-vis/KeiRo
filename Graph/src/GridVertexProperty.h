//******************************************************************************
// GridVertexProperty.h
//	: header file for tree vertex property
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sun Feb 09 23:16:12 2020
//
//******************************************************************************

#ifndef	_Graph_GridVertexProperty_H
#define _Graph_GridVertexProperty_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>

using namespace std;

#include "Coord2.h"
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

    enum GRID_VERTEX_TYPE{ GRID_VERTEX_DEFAULT, GRID_VERTEX_CORNER,
                           GRID_VERTEX_BOUNDARY_ONX, GRID_VERTEX_BOUNDARY_ONY, GRID_VERTEX_FREE };

    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class GridVertexProperty: public BaseVertexProperty {

    private:

    protected:

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
          void		    _init( void );

    public:

        // gird type
        GRID_VERTEX_TYPE                        gridVType;
        // initial position
        KeiRo::Base::Coord2 *                   geoPtr;
        // position after deformation
        KeiRo::Base::Coord2 *                   smoothPtr;
        // flag on if the pixel is occupied
        bool                            isOccupied;

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        GridVertexProperty( void );
        // copy constructor
        GridVertexProperty( const GridVertexProperty & c ) {}
        // destructor
        virtual ~GridVertexProperty( void ) {}

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
        friend ostream &	operator << ( ostream & s, const GridVertexProperty & v );
        // input
        friend istream &	operator >> ( istream & s, GridVertexProperty & v );
        // class name
        virtual const char * className( void ) const { return "GridVertexProperty"; }

    };

} // namespace Graph

#endif // _Graph_GridVertexProperty_H
