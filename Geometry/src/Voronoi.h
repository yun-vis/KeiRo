//==============================================================================
// Voronoi.h
//  : header file for the optimization
//
//==============================================================================

#ifndef _Voronoi_H        // begining of header file
#define _Voronoi_H        // notifying that this file is included

//----------------------------------------------------------------------
//  Including header files
//----------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cmath>

using namespace std;

// add to avoid apple clang 11.0.0 parser bug
#define CGAL_DO_NOT_USE_BOOST_MP

#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Regular_triangulation_filtered_traits_2.h>
#include <CGAL/Regular_triangulation_adaptation_traits_2.h>
#include <CGAL/Regular_triangulation_adaptation_policies_2.h>
#include <CGAL/Regular_triangulation_2.h>
#include <CGAL/Voronoi_diagram_2.h>
#include <CGAL/Boolean_set_operations_2.h>
#include <CGAL/bounding_box.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/Polygon_2_algorithms.h>
#include <CGAL/centroid.h>
#include <CGAL/double.h>

#include <boost/lexical_cast.hpp>
#include "Common.h"
#include "Seed.h"
#include "Polygon2.h"

//------------------------------------------------------------------------------
//	Defining data types
//------------------------------------------------------------------------------

//Used to convert otherwise infinite rays into long line segments
const int RAY_LENGTH = 1000;
const int LINE_LENGTH = 1e8;


typedef CGAL::Exact_predicates_exact_constructions_kernel K;
//typedef CGAL::Exact_predicates_inexact_constructions_kernel KI;

#ifdef __linux__
typedef CGAL::Regular_triangulation_filtered_traits_2<K>  Traits;
typedef CGAL::Regular_triangulation_2<Traits> RT2;
#endif  // __linux__

#ifdef __APPLE__
typedef CGAL::Regular_triangulation_2< K > RT2;
#endif  // __MAC__

typedef CGAL::Regular_triangulation_adaptation_traits_2< RT2 > AT;
typedef CGAL::Regular_triangulation_degeneracy_removal_policy_2< RT2 > DRP;
typedef CGAL::Voronoi_diagram_2< RT2, AT, DRP > VD;
typedef CGAL::Polygon_2< K >::Vertex_circulator Vertex_circulator;

using CGAL::ORIGIN;

//----------------------------------------------------------------------
//	Defining macros
//----------------------------------------------------------------------

class Voronoi {

private:
	
	unsigned _id;
	// outer simpleContour of the voronoi diagram
	KeiRo::Base::Polygon2 *_contourPtr;
	
	// seeds
	vector< Seed > *_seedVecPtr;
	// map seed points and cell polygon
	vector< vector< K::Point_2 > > _polyVec2D;
	
	K::Segment_2 _convertToSeg( const CGAL::Object seg_obj, bool outgoing,
	                            bool &isLine, double &slope );

protected:
	
	void _init( vector< Seed > &__seedVec, KeiRo::Base::Polygon2 &__contour );
	
	void _clear();

public:
	
	Voronoi();                      // default constructor
	Voronoi( const Voronoi &obj );  // Copy constructor
	virtual ~Voronoi();             // Destructor

//------------------------------------------------------------------------------
//  Reference to members
//------------------------------------------------------------------------------
	const unsigned int &id( void ) const { return _id; }
	
	unsigned int &id( void ) { return _id; }
	
	const vector< Seed > *seedVec( void ) const { return _seedVecPtr; }
	
	vector< Seed > *seedVec( void ) { return _seedVecPtr; }

//------------------------------------------------------------------------------
//  Specific functions
//------------------------------------------------------------------------------
	void init( vector< Seed > &__seedVec, KeiRo::Base::Polygon2 &__contour ) {
		_init( __seedVec, __contour );
	}
	
	void createVoronoiDiagram( bool isWeighted );
	
	void mapSeedsandPolygons( void );

//------------------------------------------------------------------------------
//  Initialization functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  File I/O
//------------------------------------------------------------------------------
	void clear( void ) { _clear(); }

//------------------------------------------------------------------------------
//      I/O
//------------------------------------------------------------------------------
	friend ostream &operator<<( ostream &stream, const Voronoi &obj );
	
	// Output
	friend istream &operator>>( istream &stream, Voronoi &obj );
	// Input
	
	virtual const char *className( void ) const { return "Voronoi"; }
	// Class name
};

#endif // _Voronoi_H

// end of header file
// Do not add any stuff under this line.
