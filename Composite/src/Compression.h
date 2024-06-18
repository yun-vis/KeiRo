//******************************************************************************
// Compression.h
//	: header file for Compression
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Mon Sep 06 20:58:23 2021
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

#include "BaseUndirectedGraph.h"
#include "Edge2.h"

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	Defining Classes
//------------------------------------------------------------------------------
class Compression {

private:

    Graph::BaseUndirectedGraph                  _graph;
    bool        _closeToSamplesInt( KeiRo::Base::Coord2 coordS,
									KeiRo::Base::Coord2 coordT );

protected:

    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    void	    _init( void );
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
    
    Graph::BaseUndirectedGraph &                graph( void )		        { return _graph; }
    const Graph::BaseUndirectedGraph &	        graph( void ) const 	    { return _graph; }

    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    void init( void ){
        _init();
    }

    void clear( void ){
        _clear();
    }

    bool findVertex( KeiRo::Base::Coord2 coord, unsigned int sortedID, unsigned int &index );
    unsigned int addVertex( KeiRo::Base::Coord2 coord, unsigned int level, unsigned int sortedID );
    void addEdge( unsigned int idS, unsigned int idT, vector< unsigned int > &intermediateVec,
				  unsigned int sortedID, bool isCompressed );
    void addBridgeEdge( unsigned int idS, unsigned int idT );
    
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
