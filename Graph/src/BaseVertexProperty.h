//******************************************************************************
// BaseVertexProperty.h
//	: header file for base vertex property
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Dec 27 23:16:12 2018
//
//******************************************************************************

#ifndef	_Graph_BaseVertexProperty_H
#define _Graph_BaseVertexProperty_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

#include "Coord2.h"
#include "Common.h"
//#include "GraphicsBallItem.h"

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

namespace Graph {

    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class BaseVertexProperty {

    private:

    protected:

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        void		    _init( void );

    public:

        unsigned int                id;
        unsigned int                initID;                 // initial id
        unsigned int                groupID;                // group id
        unsigned int                componentID;            // component id

        string *                    namePtr;
        double *                    namePixelWidthPtr;      // pixel width of the name
        double *                    namePixelHeightPtr;     // pixel height of the name

        double                      weight;

        KeiRo::Base::Coord2 *              coordPtr;               // center coordinates
        double *                    widthPtr;               // vertex width
        double *                    heightPtr;              // vertex height
        double *                    areaPtr;                // vertex area

        int                         color;                  // color type
        bool                        flag;                   // flag

        // Ui::Vector::GraphicsBallItem * itemPtr;

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        BaseVertexProperty( void );
        // copy constructor
        BaseVertexProperty( const BaseVertexProperty & c ) {}
        // destructor
        virtual ~BaseVertexProperty( void ) {}

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
        friend ostream &	operator << ( ostream & s, const BaseVertexProperty & v );
        // input
        friend istream &	operator >> ( istream & s, BaseVertexProperty & v );
        // class name
        virtual const char * className( void ) const { return "BaseVertexProperty"; }

    };

} // namespace Graph

#endif // _Graph_BaseVertexProperty_H
