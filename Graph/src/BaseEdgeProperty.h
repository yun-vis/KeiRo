//******************************************************************************
// BaseEdgeProperty.h
//	: header file for base edge property
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Dec 27 23:16:12 2018
//
//******************************************************************************

#ifndef	_Graph_BaseEdgeProperty_H
#define _Graph_BaseEdgeProperty_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

#include "Coord2.h"
#include "Edge2.h"
//#include "GraphicsEdgeItem.h"

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

namespace Graph {

    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class BaseEdgeProperty {

    private:

    protected:

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        void		    _init( void );

    public:

        unsigned int                id;

        double                      angle;
        double                      weight;
        bool                        visit;
        int                         visitedTimes;
		int                         level;
        
        bool                        isFore;
        bool                        isBack;
        bool                        isShow;

        unsigned int                itemID;             // item ID for graphics
	    KeiRo::Base::Edge2          edge;               // store non-straight-line edge
		
        //Ui::Vector::GraphicsEdgeItem * itemPtr;

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        BaseEdgeProperty( void );
        // copy constructor
        BaseEdgeProperty( const BaseEdgeProperty & e ) {
            id	    = e.id;
            weight	= e.weight;
        }
        // destructor
        virtual ~BaseEdgeProperty( void ) {}

        //------------------------------------------------------------------------------
        //	Assignment operators
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Reference to elements
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------

        void        init( void )		      { _init(); }

        //------------------------------------------------------------------------------
        //	Friend functions
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream &	operator << ( ostream & s, const BaseEdgeProperty & v );
        // input
        friend istream &	operator >> ( istream & s, BaseEdgeProperty & v );
        // class name
        virtual const char * className( void ) const { return "BaseEdgeProperty"; }
    };

} // namespace Graph

#endif // _Graph_BaseEdgeProperty_H
