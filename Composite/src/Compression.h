//******************************************************************************
// Compression.h
//	: header file for Compression
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Mon Mar 16 07:58:23 2020
//
//******************************************************************************

#ifndef	_Compression_H
#define _Compression_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

#include <qapplication.h>

//#include "Config.h"
#include "Polygon2.h"
#include "Line2.h"
#include "Grid2.h"

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	Defining Classes
//------------------------------------------------------------------------------
class Compression {

private:

    double                                              _min_point_distance;

    vector< KeiRo::Base::Coord2 >                       _fixedSamples;
    vector< KeiRo::Base::Coord2 >                       _samples;

    vector< KeiRo::Base::Polygon2 >                     *_polygonVecPtr;
    vector< KeiRo::Base::Line2 >                        *_polylineVecPtr;
    Grid2                                               *_gridPtr;

    bool        _closeToSamples( KeiRo::Base::Coord2 &coord, unsigned int &index );

protected:

    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    void	    _init( Grid2 * __gridPtr,
                       vector< KeiRo::Base::Polygon2 > *__polygonVecPtr,
                       vector< KeiRo::Base::Line2 > *__polylineVecPtr );
    void	    _clear( void );

public:

    //------------------------------------------------------------------------------
    //	Constructors
    //------------------------------------------------------------------------------
    // default constructor
    Compression( void );
	// copy constructor
	Compression( const Compression & v );
    // destructor
    virtual ~Compression( void );

    //------------------------------------------------------------------------------
    //	Assignment operators
    //------------------------------------------------------------------------------
	Compression &		operator = ( const Compression & v );
	
    //------------------------------------------------------------------------------
    //	Reference to elements
    //------------------------------------------------------------------------------
    vector< KeiRo::Base::Coord2 > &              fixedSamples( void )		{ return _fixedSamples; }
    const vector< KeiRo::Base::Coord2 > &	    fixedSamples( void ) const  { return _fixedSamples; }

    vector< KeiRo::Base::Coord2 > &              samples( void )		        { return _samples; }
    const vector< KeiRo::Base::Coord2 > &	    samples( void ) const 	    { return _samples; }

    vector< KeiRo::Base::Polygon2 > *	        polygonVecPtr( void ) 	        { return _polygonVecPtr; }
    const vector< KeiRo::Base::Polygon2 > *	polygonVecPtr( void ) const	{ return _polygonVecPtr; }
    vector< KeiRo::Base::Line2 > *	            polylineVecPtr( void ) 	    { return _polylineVecPtr; }
    const vector< KeiRo::Base::Line2 > *	    polylineVecPtr( void ) const	{ return _polylineVecPtr; }

    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    void init( Grid2 * __gridPtr,
               vector< KeiRo::Base::Polygon2 > *__polygonVecPtr,
               vector< KeiRo::Base::Line2 > *__polylineVecPtr ){
        _init( __gridPtr, __polygonVecPtr, __polylineVecPtr );
    }
    void clear( void ){
        _clear();
    }
    void createCompressedSamples( void );
    void createCompressedJoints( void );
    void createCompressedGridJoints( void );
    void createCompression( void );


    //------------------------------------------------------------------------------
    //	Friend functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	I/O functions
    //------------------------------------------------------------------------------
    // output
    friend ostream &	operator << ( ostream & s, const Compression & v );
    // input
    friend istream &	operator >> ( istream & s, Compression & v );
    // class name
    virtual const char * className( void ) const { return "Compression"; }

};


#endif // _Compression_H
