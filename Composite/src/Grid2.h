//******************************************************************************
// Grid2.h
//	: header file for 2D grid coordinates
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Mon Feb 10 20:13:35 2020
//
//******************************************************************************

#ifndef _Base_Grid2_H
#define _Base_Grid2_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <vector>
#include <iostream>

using namespace std;

#include <qapplication.h>
#include "Config.h"
#include "Coord2.h"
#include "GridGraph.h"

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	Defining Classes
//------------------------------------------------------------------------------
class Grid2 {

private:
	
	// window width and height
	double const * _widthPtr;
	double const * _heightPtr;
	// grid graph
	Graph::GridGraph _grid;
	vector< vector< Graph::GridGraph::vertex_descriptor > > _quadFourCorners;
	// grid level
	unsigned int _level;

protected:
	
	// grid range
	unsigned int _minRange;
	vector< unsigned int > _range;
	// width and height of a quad
	double _quadSize;
	vector< vector< KeiRo::Base::Common::IDPair > > _gridIDMatrix;
	vector< vector< KeiRo::Base::Coord2 > > _gridCoord2Matrix;
	
	// x, y coordinates
	int _element[2];
	
	//------------------------------------------------------------------------------
	//	Special functions
	//------------------------------------------------------------------------------
	// initialize griz
	virtual void _init( const double *_widthPtr, const double *_heightPtr );
	
	virtual void _clear( void );

public:
	
	//------------------------------------------------------------------------------
	//	Constructors & Destructors
	//------------------------------------------------------------------------------
	// default constructor
	Grid2( void );
	
	// parameterized constructor
	Grid2( const int x, const int y );
	
	// copy constructor
	Grid2( const Grid2 &v );
	
	// destructor
	virtual ~Grid2( void ) {}
	
	//------------------------------------------------------------------------------
	//	Assignment operators
	//------------------------------------------------------------------------------
	// assignment
	Grid2 &operator=( const Grid2 &v );
	
	// addition + assignment
	Grid2 &operator+=( const Grid2 &v );
	
	// subtraction + assignment
	Grid2 &operator-=( const Grid2 &v );
	
	// scalar product + assignment
	Grid2 &operator*=( const int d );
	
	//------------------------------------------------------------------------------
	//	Reference to elements
	//------------------------------------------------------------------------------
	// reference to a specific coordinate
	const int &operator[]( int i ) const;
	
	int &operator[]( int i );
	
	// pointer to an array of coordinates
	const int *element( void ) const { return _element; }
	
	int &p( void ) { return _element[ 0 ]; }
	
	int &q( void ) { return _element[ 1 ]; }
	
	const int &p( void ) const { return _element[ 0 ]; }
	
	const int &q( void ) const { return _element[ 1 ]; }
	
	// reference to a specific coordinate
	const int &getP( void ) const { return _element[ 0 ]; }
	
	const int &getQ( void ) const { return _element[ 1 ]; }
	
	// set the coordinate(s)
	void set( const int p, const int q );
	
	void setP( const int p ) { _element[ 0 ] = p; }
	
	void setQ( const int q ) { _element[ 1 ] = q; }
	
	
	Graph::GridGraph &gridG( void ) { return _grid; }
	
	const Graph::GridGraph &gridG( void ) const { return _grid; }
	
	unsigned int &minRange( void ) { return _minRange; }
	
	const unsigned int &minRange( void ) const { return _minRange; }
	
	vector< unsigned int > &range( void ) { return _range; }
	
	const vector< unsigned int > &range( void ) const { return _range; }
	
	double &quadSize( void ) { return _quadSize; }
	
	const double &qudaSize( void ) const { return _quadSize; }
	
	// grid level
	unsigned int &level( void ) { return _level; }
	
	const unsigned int &level( void ) const { return _level; }
	
	vector< vector< Graph::GridGraph::vertex_descriptor > > &quadFourCorners( void ) { return _quadFourCorners; }
	
	const vector< vector< Graph::GridGraph::vertex_descriptor > > &
	quadFourCorners( void ) const { return _quadFourCorners; }
	
	//vector< vector< Base::Common::IDPair > > &          gridIDMatrix( void )            { return _gridIDMatrix; }
	//const vector< vector< Base::Common::IDPair > > &    gridIDMatrix( void ) const      { return _gridIDMatrix; }
	//vector< vector< Base::Coord2 > > &                  gridCoordMatrix( void )         { return _gridCoord2Matrix; }
	//const vector< vector< Base::Coord2 > > &            gridCoordMatrix( void ) const   { return _gridCoord2Matrix; }
	
	
	//------------------------------------------------------------------------------
	//	Special functions
	//------------------------------------------------------------------------------
	// initialization
	void init( const double *__widthPtr, const double *__heightPtr  ) {
		_init( __widthPtr, __heightPtr );
	}
	
	// clear
	void clear( void ) { _clear(); }
	
	void getQuadVD( unsigned int i, unsigned int j,
	                vector< Graph::GridGraph::vertex_descriptor > &vdVec );
	
	void createDefaultGrid( void );
	
	void resetGridPosition( void );
	
	//------------------------------------------------------------------------------
	//	Friend functions
	//------------------------------------------------------------------------------
	// sign change
	friend Grid2 operator-( const Grid2 &v );
	
	// addition
	friend Grid2 operator+( const Grid2 &a, const Grid2 &b );
	
	// subtraction
	friend Grid2 operator-( const Grid2 &a, const Grid2 &b );
	
	// scalar product
	friend Grid2 operator*( const int d, const Grid2 &a );
	
	// inner product
	friend int operator*( const Grid2 &a, const Grid2 &b );
	
	// equivalence
	friend int operator==( const Grid2 &a, const Grid2 &b );
	
	// inequivalence
	friend int operator!=( const Grid2 &a, const Grid2 &b ) {
		return ( !( a == b ) );
	}
	
	// comparison (less than)
	friend int operator<( const Grid2 &a, const Grid2 &b );
	
	// comparison (more than)
	friend int operator>( const Grid2 &a, const Grid2 &b );
	
	// comparison (equal to or less than)
	friend int operator<=( const Grid2 &a, const Grid2 &b ) {
		return ( ( a == b ) || ( a < b ) );
	}
	
	// comparison (equal to or more than)
	friend int operator>=( const Grid2 &a, const Grid2 &b ) {
		return ( ( a == b ) || ( a > b ) );
	}
	
	//------------------------------------------------------------------------------
	//	I/O functions
	//------------------------------------------------------------------------------
	// output
	friend ostream &operator<<( ostream &s, const Grid2 &v );
	
	// input
	friend istream &operator>>( istream &s, Grid2 &v );
	
	// class name
	virtual const char *className( void ) const { return "Grid2"; }
	
};


#endif // _Base_Grid2_H
