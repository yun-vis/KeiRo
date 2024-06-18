//******************************************************************************
// Contour2.cc
//	: program file for 2D simpleContour
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sun Sep 16 15:02:45 2012
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

#include "Contour2.h"

//------------------------------------------------------------------------------
//	Macro Definitions
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//	Protected Functions
//------------------------------------------------------------------------------
//
//  Contour2::_init --	initialization
//
//  Inputs
//  __elements
//
//  Outputs
//  none
//
void Contour2::_init( unsigned int __id, vector< KeiRo::Base::Polygon2 > __polygons ) {
	_id = __id;
	_polygons = __polygons;
	
	// detect non-simple polygon and remove overlapped vertices
	for( unsigned int i = 0; i < _polygons.size(); i++ ) {
		CGAL::Polygon_2< K > polygon;
		KeiRo::Base::Polygon2 &p = _polygons[ i ];
		for( unsigned int j = 0; j < p.elements().size(); j++ ) {
			if( ( p.elements()[ j ] - p.elements()[ ( j + 1 ) % ( int ) p.elements().size() ] ).norm() > 0.5 )
				polygon.push_back( K::Point_2( p.elements()[ j ].x(), p.elements()[ j ].y() ) );
		}
		
		p.elements().clear();
		for( unsigned int j = 0; j < polygon.size(); j++ ) {
			p.elements().push_back( KeiRo::Base::Coord2( CGAL::to_double( polygon[ j ].x() ),
			                                CGAL::to_double( polygon[ j ].y() ) ) );
		}
		
		bool isSimple = polygon.is_simple();
		
		if( polygon.is_simple() == false ) {
			cerr << "i = " << i << " isSimple = " << polygon.is_simple() << endl;
			cerr << p << endl;
		}
	}
}

//
//  Contour2::_clear --	clear elements
//
//  Inputs
//
//
//  Outputs
//  none
//
void Contour2::_clear( void ) {
	_polygons.clear();
	_fineContour.clear();
}

//------------------------------------------------------------------------------
//	Public functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	Constructors
//------------------------------------------------------------------------------
//
//  Contour2::Contour2 -- default constructor
//
//  Inputs
//  none
//
//  Outputs
//  none
//
Contour2::Contour2() {
	_fineContour.clear();
}

//
//  Contour2::Contour2 -- constructor
//
//  Inputs
//  __elements
//
//  Outputs
//  none
//
Contour2::Contour2( vector< KeiRo::Base::Polygon2 > __polygons ) {
	_polygons = __polygons;
}

//
//  Contour2::Contour2 -- copy constructor
//
//  Inputs
//  polygon
//
//  Outputs
//  none
//
Contour2::Contour2( const Contour2 &v ) {
	_id = v._id;
	_contour = v._contour;
	_polygons = v._polygons;
}


//------------------------------------------------------------------------------
//	Assignment operators
//------------------------------------------------------------------------------

//
//  Contour2::operator = --	assignment
//
//  Inputs
//	v	: 2D coordinates
//
//  Outputs
//	reference to this object
//
Contour2 &Contour2::operator=( const Contour2 &p ) {
	if( this != &p ) {
		_id = p._id;
		_contour = p._contour;
		_polygons = p._polygons;
	}
	return *this;
}

//------------------------------------------------------------------------------
//	Special functions
//------------------------------------------------------------------------------
bool Contour2::findVertexInComplex( const KeiRo::Base::Coord2 &coord, Graph::BaseUndirectedGraph &complex,
                                    Graph::BaseUndirectedGraph::vertex_descriptor &target ) {
	bool isFound = false;
	
	BGL_FORALL_VERTICES( vd, complex, Graph::BaseUndirectedGraph ) {
			//cerr << " vd " << *complex[vd].coordPtr << endl;
			if( ( coord - *complex[ vd ].coordPtr ).norm() < MIN_VERTEX_DISTANCE ) {
				target = vd;
				isFound = true;
			}
		}
	
	//cerr << "isFound = " << isFound << endl;
	return isFound;
}

double Contour2::randomCentroid( void ) {
	
	int num = 30;
	double radius = 20.0;
	if( _contour.elements().size() == 0 ) return 1.0;
	
	KeiRo::Base::Coord2 c = _contour.centroid();
	while( inContour( c ) == false ) {
		int size = _contour.elements().size();
		int idA = rand() % size;
		int idB = ( idA + 1 ) % size;
		int idC = ( idA + 2 ) % size;
		c = (_contour.elements()[ idA ] + _contour.elements()[ idB ] + _contour.elements()[ idC ])/3.0;
	}
	double min = minDistToPolygon( c );
	for( int i = 0; i < num; i++ ) {
		
		KeiRo::Base::Coord2 coord( 0.0, 0.0 );
		cerr << "HERE3" << endl;
		coord.x() = c.x() + radius * ( 2.0 * rand() / ( double ) RAND_MAX - 1.0 );
		coord.y() = c.y() + radius * ( 2.0 * rand() / ( double ) RAND_MAX - 1.0 );
		double minB = minDistToPolygon( coord );
		if( min < minB && inContour( coord ) ){
			c = coord;
			min = minB;
		}
	}
	
	_contour.centroid() = c;
	
	return MAX2( 1.0, min );
}

//
//  Contour2::minDistToPolygon --    find the minimum distance of a vertex to the polygon boundary
//
//  Inputs
//  none
//
//  Outputs
//  none
//
double Contour2::minDistToPolygon( const KeiRo::Base::Coord2 &coord ) {
	
	double minDist = INFINITY;
	
	for( unsigned int i = 0; i < _contour.elements().size(); i++ ) {
		
		KeiRo::Base::Coord2 &coordM = _contour.elements()[ i ];
		KeiRo::Base::Coord2 &coordN = _contour.elements()[ ( i + 1 ) % ( int ) _contour.elements().size() ];
		KeiRo::Base::Coord2 mnVec = coordN - coordM;
		KeiRo::Base::Coord2 cmVec = coord - coordM;
		double D = ( mnVec * cmVec ) / mnVec.squaredNorm();
		KeiRo::Base::Coord2 coordD = coordM + D * mnVec;
		
		if( KeiRo::Base::Line2::isOnLine( coordD, coordM, coordN ) ) {
			
			double dist = ( coord - coordD ).norm();
			if( dist < minDist ) minDist = dist;
		}
		double dist = (coordM - coord).norm();
		if( dist < minDist ) {
			minDist = dist;
		}
	}
	
	return minDist;
}

void Contour2::createContour( void ) {
	
	// copy cells to a graph
	Graph::BaseUndirectedGraph complex;
	unsigned int vid = 0;
	unsigned int eid = 0;
	for( unsigned int j = 0; j < _polygons.size(); j++ ) {
		
		KeiRo::Base::Polygon2 &p = _polygons[ j ];
		vector< Graph::BaseUndirectedGraph::vertex_descriptor > vdVec;
		
		// add vertices
		for( unsigned int k = 0; k < p.elements().size(); k++ ) {
			Graph::BaseUndirectedGraph::vertex_descriptor vd = NULL;
			
			bool isFound = findVertexInComplex( p.elements()[ k ], complex, vd );
			if( isFound == true ) {
				vdVec.push_back( vd );
				//cerr << k << " found = " << *complex[ vd ].coordPtr;
			}
			else {
				vd = add_vertex( complex );
				complex[ vd ].id = vid;
				complex[ vd ].coordPtr = new KeiRo::Base::Coord2( p.elements()[ k ].x(), p.elements()[ k ].y() );
				vdVec.push_back( vd );
				vid++;
				//cerr << k << " new = " << *complex[ vd ].coordPtr;
			}
			//cerr << "( " << complex[ vd ].id << " ) = " << *complex[ vd ].coordPtr << endl;
		}
		
		// add edges
		for( unsigned int k = 1; k < vdVec.size() + 1; k++ ) {
			
			Graph::BaseUndirectedGraph::vertex_descriptor vdS = vdVec[ k - 1 ];
			Graph::BaseUndirectedGraph::vertex_descriptor vdT = vdVec[ k % ( int ) vdVec.size() ];
			
			bool isFound = false;
			Graph::BaseUndirectedGraph::edge_descriptor oldED;
			tie( oldED, isFound ) = edge( vdS, vdT, complex );
			
			if( isFound == true ) {
				complex[ oldED ].weight += 1;
			}
			else {
				
				pair< Graph::BaseUndirectedGraph::edge_descriptor, unsigned int > foreE = add_edge( vdS, vdT, complex );
				Graph::BaseUndirectedGraph::edge_descriptor foreED = foreE.first;
				complex[ foreED ].id = eid;
				complex[ foreED ].weight = 0;
				eid++;
			}
			// cerr << "( " << complex[ vdS ].id << ", " << complex[ vdT ].id << " ) " << endl;
		}
		// cerr << endl;
	}

#ifdef DEBUG
	printGraph( complex );
#endif // DEBUG
	
	// remove inner edges
	vector< Graph::BaseUndirectedGraph::edge_descriptor > edVec;
	BGL_FORALL_EDGES( ed, complex, Graph::BaseUndirectedGraph ) {
			if( complex[ ed ].weight > 0 ) {
				edVec.push_back( ed );
				//cerr << "w = " << complex[ed].weight << endl;
			}
		}

#ifdef DEBUG
	cerr << "bnV = " << num_vertices( complex ) << " ";
	cerr << "bnE = " << num_edges( complex ) << endl;
#endif // DEBUG
	
	for( unsigned int j = 0; j < edVec.size(); j++ ) {
		remove_edge( edVec[ j ], complex );
	}
	// reorder edge id
	eid = 0;
	BGL_FORALL_EDGES( ed, complex, Graph::BaseUndirectedGraph ) {
			complex[ ed ].id = eid;
			complex[ ed ].visit = false;
			eid++;
		}
		
#ifdef DEBUG
	printGraph( complex );
#endif // DEBUG
	
	// find the vertex with degree > 0
#ifdef DEBUG
	cerr << "nV = " << num_vertices( complex ) << " ";
	cerr << "nE = " << num_edges( complex ) << endl;
#endif // DEBUG
	Graph::BaseUndirectedGraph::vertex_descriptor vdS;
	BGL_FORALL_VERTICES( vd, complex, Graph::BaseUndirectedGraph ) {
#ifdef DEBUG
			if ( true ){
				cerr << " degree = " << out_degree( vd, complex );
			}
#endif // DEBUG
			if( out_degree( vd, complex ) > 0 ) {
				vdS = vd;
				break;
			}
		}
	
	// find the simpleContour
	Graph::BaseUndirectedGraph::out_edge_iterator eo, eo_end;
	Graph::BaseUndirectedGraph::vertex_descriptor vdC = vdS;
	//cerr << "idC = " << complex[vdC].id << " ";
	
	KeiRo::Base::Polygon2 polygon;
	polygon.elements().push_back( KeiRo::Base::Coord2( complex[ vdS ].coordPtr->x(), complex[ vdS ].coordPtr->y() ) );
	while( true ) {
		
		Graph::BaseUndirectedGraph::vertex_descriptor vdT = NULL;
		for( tie( eo, eo_end ) = out_edges( vdC, complex ); eo != eo_end; eo++ ) {
			
			Graph::BaseUndirectedGraph::edge_descriptor ed = *eo;
			if( complex[ ed ].visit == false ) {
				vdT = target( ed, complex );
				complex[ ed ].visit = true;
				break;
			}
			//cerr << "(" << complex[source( ed, complex )].id << "," << complex[target( ed, complex )].id << ")" << endl;
		}
		
		if( vdS == vdT ) break;
		else
			assert( vdT != NULL );
		//cerr << complex[vdT].id << " ";
		polygon.elements().push_back( KeiRo::Base::Coord2( complex[ vdT ].coordPtr->x(), complex[ vdT ].coordPtr->y() ) );
		vdC = vdT;
	}
	
	// simplify polygon
	//cerr << "size = " << polygon.elements().size() << endl;
	for( unsigned int i = 0; i < polygon.elements().size(); i++ ) {
		
		KeiRo::Base::Coord2 prev;
		if( i == 0 ) prev = polygon.elements()[ polygon.elements().size() - 1 ];
		else prev = polygon.elements()[ i - 1 ];
		
		KeiRo::Base::Coord2 curr = polygon.elements()[ i ];
		KeiRo::Base::Coord2 next = polygon.elements()[ ( i + 1 ) % ( int ) polygon.elements().size() ];
		KeiRo::Base::Coord2 vecA = prev - curr;
		KeiRo::Base::Coord2 vecB = next - curr;

#ifdef DEBUG
		cerr << i << ": " << (i-1)%polygon.elements().size() << endl;
		cerr << "prev = " << prev;
		cerr << "next = " << next;
		cerr << "curr = " << curr;
		cerr << "vecA = " << vecA;
		cerr << "vecB = " << vecB;
#endif // DEBUG
		
		double cosTheta = vecA * vecB / ( vecA.norm() * vecB.norm() );
		if( fabs( M_PI - acos( cosTheta ) ) > 0.1 ) {
			//cerr << "acos = " << acos( cosTheta ) << endl;
			
			//Coord2 &prev = polygon.elements()[ (i-1+polygon.elements().size())%polygon.elements().size() ];
			//if( (prev-polygon.elements()[i]).norm() > 1 )
			_contour.elements().push_back( polygon.elements()[ i ] );
		}
	}
	
	//cerr << "(ori)::_contour = " << _contour << endl;
	_contour.cleanPolygon();
	_contour.updateCentroid();
	_contour.updateOrientation();
	//cerr << "simpleContour = " << _contour << endl;


#ifdef DEBUG
	cerr << "centroid = " << polygon.centroid() << endl;
	cerr << "p[" << i << "] = " << polygon << endl;
	cerr << "simpleContour = " << _contour << endl;
#endif // DEBUG
}

bool Contour2::inContour( KeiRo::Base::Coord2 &coord ) {
	return _contour.inPolygon( coord );
}

void Contour2::_initChaikinCurve( double unit = 50 ) {
	// initialization
	_fineContour.elements().clear();
	
	// store initial the path
	KeiRo::Base::Polygon2 &contour = _contour;
	
	// cerr << "simpleContour.elements().size() = " << simpleContour.elements().size() << endl;
	if( contour.elements().size() > 0 )
		_fineContour.elements().push_back( contour.elements()[ 0 ] );
	for( unsigned int j = 1; j <= contour.elements().size(); j++ ) {
		
		KeiRo::Base::Coord2 diff = ( contour.elements()[ j % contour.elements().size() ] - contour.elements()[ j - 1 ] );
		// cerr << "dist = " << diff.norm() << endl;
		if( diff.norm() > unit ) {
			
			int num = floor( diff.norm() / unit );
			double interval = diff.norm() / ( double ) num;
			
			for( int k = 1; k < num; k++ ) {
				// cerr << "here" << endl;
				KeiRo::Base::Coord2 c = contour.elements()[ j - 1 ] + ( double ) k * interval * diff / diff.norm();
				// cerr << "here " << c;
				_fineContour.elements().push_back( c );
			}
		}
		if( j < contour.elements().size() )
			_fineContour.elements().push_back( contour.elements()[ j ] );
	}
}

void Contour2::computeChaikinCurve( int num = 5, double unit = 100 ) {
	_initChaikinCurve( unit );
	
	double interval = 4.0;
	for( int k = 0; k < num; k++ ) {
		
		vector< KeiRo::Base::Coord2 > core;
		for( unsigned int j = 0; j < _fineContour.elements().size(); j++ ) {
			core.push_back( _fineContour.elements()[ j ] );
		}
		
		// compute Chaikin Curve
		_fineContour.clear();
		for( unsigned int j = 0; j < core.size(); j++ ) {
			
			KeiRo::Base::Coord2 &p1 = core[ j ];
			KeiRo::Base::Coord2 &p2 = core[ ( j + 1 ) % core.size() ];
			KeiRo::Base::Coord2 q = ( 1.0 - 1.0 / interval ) * p1 + ( 1.0 / interval ) * p2;
			KeiRo::Base::Coord2 r = ( 1.0 / interval ) * p1 + ( 1.0 - 1.0 / interval ) * p2;
			
			_fineContour.elements().push_back( q );
			_fineContour.elements().push_back( r );
		}
	}
}

//------------------------------------------------------------------------------
//	Friend functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	I/O functions
//------------------------------------------------------------------------------
//
//  operator << --	output
//
//  Inputs
//	s	: reference to output stream
//	v	: 2D coordinates
//
//  Outputs
//	reference to output stream
//
ostream &operator<<( ostream &stream, const Contour2 &obj ) {
	int i;        // loop counter
	// set the output formatting
	//stream << setiosflags( ios::showpoint );
	//stream << setprecision( 8 );
	//int width = 16;
	// print out the elements
	for( i = 0; i < obj._contour.elements().size(); i++ ) {
		//stream << setw( width ) << obj._element[ i ];
		stream << setw( 4 ) << obj._contour.elements()[ i ];
		if( i != 1 ) stream << "\t";
	}
	stream << endl;
	
	return stream;
}


//
//  operator >> --	input
//
//  Inputs
//	s	: reference to input stream
//	v	: 2D coordinates
//
//  Outputs
//	reference to input stream
//
istream &operator>>( istream &stream, Contour2 &obj ) {
	int i;        // loop counter
	// reading the elements
	for( i = 0; i < obj._contour.elements().size(); i++ )
		stream >> obj._contour.elements()[ i ];
	return stream;
}




