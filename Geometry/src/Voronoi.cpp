// Voronoi.cpp
//  : program file for the metro network
//
//------------------------------------------------------------------------------
//
//              Date: Mon Dec 10 04:28:26 2012
//
//==============================================================================

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------
#include "Voronoi.h"

//------------------------------------------------------------------------------
//	Protected functions
//------------------------------------------------------------------------------
//
//  Voronoi::_init --        initialization
//
//  Inputs
//      none
//
//  Outputs
//      none
//
void Voronoi::_init( vector< Seed > &__seedVec, KeiRo::Base::Polygon2 &__contour ) {
	_seedVecPtr = &__seedVec;
	_contourPtr = &__contour;
}

//
//  Voronoi::_clear --        memory management
//
//  Inputs
//      none
//
//  Outputs
//      none
//
void Voronoi::_clear( void ) {
	_contourPtr = NULL;        // simpleContour of the voronoi diagram
	
	// seeds
	_seedVecPtr = NULL;
	_polyVec2D.clear();
}

//------------------------------------------------------------------------------
//	Public functions
//------------------------------------------------------------------------------
K::Segment_2 Voronoi::_convertToSeg( const CGAL::Object seg_obj, bool outgoing,
                                     bool &isLine, double &slope ) {
	//CGAL often returns objects that are either segments or rays. This converts
	//these objects into segments. If the object would have resolved into a ray,
	//that ray is intersected with the bounding box defined above and returned as
	//a segment.
	
	//One of these will succeed and one will have a NULL pointer
	const K::Segment_2 *dseg = CGAL::object_cast< K::Segment_2 >( &seg_obj );
	const K::Line_2 *line = CGAL::object_cast< K::Line_2 >( &seg_obj );
	const K::Ray_2 *dray = CGAL::object_cast< K::Ray_2 >( &seg_obj );
	
	if( dseg != NULL ) { //Okay, we have a segment
		//cerr << "dseg = " << *dseg << endl;
		return *dseg;
	}
	else if( dray != NULL ) {    //Must be a ray
		//cerr << "ray" << endl;
		const auto &source = dray->source();
		const auto dsx = source.x();
		const auto dsy = source.y();
		const auto &dir = dray->direction();
		const auto tpoint = K::Point_2( dsx + RAY_LENGTH * dir.dx(), dsy + RAY_LENGTH * dir.dy() );
		if( outgoing ) {
			// cerr << "source = " << dray->source() << ", " << tpoint << endl;
			return K::Segment_2( dray->source(), tpoint );
		}
		else {
			return K::Segment_2( tpoint, dray->source() );
		}
	}
	else if( line != NULL ) {    //Must be a line
		
		isLine = true;
		//cerr << "line" << endl;
		//cerr << "a = " << line->a() << " b = " << line->b() << " c = " << line->c() << endl;
		double m;
		if( line->b() == 0.0 )
			m = INFINITY;
		else
			m = -1.0 * CGAL::to_double( line->a() / line->b() );
		
		if( line->b() == 0.0 ) {
			//cerr << "1st: m = " << m << endl;
			slope = m;
			K::Point_2 source( -1.0 * CGAL::to_double( line->c() / line->a() ), -LINE_LENGTH ),
					target( -1.0 * CGAL::to_double( line->c() / line->a() ), LINE_LENGTH );
			return K::Segment_2( source, target );
		}
		else if( m >= -1.0 && m <= 1.0 ) {
			//cerr << "2nd: m = " << m << endl;
			slope = -1.0 * CGAL::to_double( line->a() / line->b() );
			K::Point_2 source( LINE_LENGTH, line->y_at_x( LINE_LENGTH ) ),
					target( -LINE_LENGTH, line->y_at_x( -LINE_LENGTH ) );
			return K::Segment_2( source, target );
		}
		else { // m > 1.0 or m < -1.0
			//cerr << "3rd: m = " << m << endl;
			slope = -1.0 * CGAL::to_double( line->a() / line->b() );
			K::Point_2 source( LINE_LENGTH, line->y_at_x( LINE_LENGTH ) ),
					target( -LINE_LENGTH, line->y_at_x( -LINE_LENGTH ) );
			return K::Segment_2( source, target );
		}
	}
	else {
		cerr << "Something is wong here at " << __LINE__ << " in " << __FILE__ << endl;
	}
	
	// cerr << "myslope = " << slope << endl;
	return K::Segment_2( K::Point_2( 0.0, 0.0 ), K::Point_2( 0.0, 0.0 ) ); // should never happens
}

//
//  Voronoi::createVoronoiDiagram --        create voronoi diagram
//
//  Inputs
//      none
//
//  Outputs
//      none
//
void Voronoi::createVoronoiDiagram( bool isWeighted ) {
	
	vector< RT2::Weighted_point > wpoints;
	
	// initialization
	_polyVec2D.clear();
	//_polygonVecPtr->clear();
	wpoints.clear();
	
	// copy points
	//cerr << "id = " << _id << " size = " << _seedVecPtr->size() << " points:" << endl;
	for( unsigned int i = 0; i < _seedVecPtr->size(); i++ ) {
		
		// cerr << "w(" << i << ") = " << (*_seedVecPtr)[i].weight << endl;
		if( isWeighted ) {
			//if ( _seedVecPtr->size() == 2 ) cerr << "w = " << ((*_seedVecPtr)[i].weight ) << endl;
			wpoints.push_back( RT2::Weighted_point( K::Point_2( ( *_seedVecPtr )[ i ].coordPtr->x(),
			                                                    ( *_seedVecPtr )[ i ].coordPtr->y() ),
			                                        10.0 * ( ( *_seedVecPtr )[ i ].weight ) ) );
		}
		else {
			wpoints.push_back( RT2::Weighted_point( K::Point_2( ( *_seedVecPtr )[ i ].coordPtr->x(),
			                                                    ( *_seedVecPtr )[ i ].coordPtr->y()  ),
			                                        0 ) );
		}
		//cerr << "sid = " << (*_seedVecPtr)[i].id << " coord = " << (*_seedVecPtr)[i].coord;
	}
	
	//Find the bounding box of the points. This will be used to crop the Voronoi
	//diagram later.
	//const K::Iso_rectangle_2 bbox = CGAL::bounding_box( wpoints.begin(), wpoints.end() );
	//const K::Iso_rectangle_2 bbox( K::Point_2( -(int)_width/2, -(int)_height/2 ), K::Point_2( (int)_width/2, (int)_height/2 ) );
	//cerr << "bbox = " << bbox << endl;
	
	//Create a Regular Triangulation from the points
	RT2 rt( wpoints.begin(), wpoints.end() );
	rt.is_valid();
	
	//Wrap the triangulation with a Voronoi diagram adaptor. This is necessary to
	//get the Voronoi faces.
	VD vd( rt );
	
	//Loop over the faces of the Voronoi diagram in some arbitrary order (does not match with seed order)
	int fnum = 0;
	for( VD::Face_iterator fit = vd.faces_begin(); fit != vd.faces_end(); ++fit, fnum++ ) {
		
		CGAL::Polygon_2< K > pgon;
		
		//Edge circulators traverse endlessly around a face. Make a note of the
		//starting point so we know when to quit.
		VD::Face::Ccb_halfedge_circulator ec_start = fit->ccb();
		
		//Find a bounded edge to start on
		//for(;ec_start->is_unbounded();ec_start++){}
		
		//Current location of the edge circulator
		VD::Face::Ccb_halfedge_circulator ec = ec_start;
		
		bool isLine = false;
		double slope = 0.0;
		do {
			//A half edge circulator representing a ray doesn't carry direction
			//information. To get it, we take the dual of the dual of the half-edge.
			//The dual of a half-edge circulator is the edge of a Delaunay triangle.
			//The dual of the edge of Delaunay triangle is either a segment or a ray.
			//const CGAL::Object seg_dual = rt.dual( ec->dual() );
			const CGAL::Object seg_dual = vd.dual().dual( ec->dual() );
			
			// cerr << "seg_dual = " << vd << endl;
			
			//Convert the segment/ray into a segment
			K::Segment_2 this_seg = _convertToSeg( seg_dual, ec->has_target(), isLine, slope );
			
			// const auto this_seg = ConvertToSeg( seg_dual, ec->has_target(), isLine, slope );
			pgon.push_back( this_seg.source() );
			
			//If the segment has no target, it's a ray. This means that the next
			//segment will also be a ray. We need to connect those two rays with a
			//segment. The following accomplishes this.
			if( !ec->has_target() ) {
				const CGAL::Object nseg_dual = vd.dual().dual( ec->next()->dual() );
				K::Segment_2 next_seg = _convertToSeg( nseg_dual, ec->next()->has_target(), isLine, slope );
				pgon.push_back( next_seg.target() );
			}
			
		} while( ++ec != ec_start ); //Loop until we get back to the beginning
		
		if( isLine ) {
			
			//cerr << "fnum = " << fnum << endl;
			auto end = pgon.vertices_end();
			end--;
			K::Point_2 source( pgon.vertices_begin()->x(), pgon.vertices_begin()->y() ),
					target( end->x(), end->y() );
			pgon.clear();
			if( fnum == 0 ) {
				
				if( slope >= -1.0 && slope <= 1.0 ) {
					pgon.push_back( K::Point_2( source.x(), source.y() ) );
					pgon.push_back( K::Point_2( source.x(), source.y() + LINE_LENGTH ) );
					pgon.push_back( K::Point_2( target.x(), target.y() + LINE_LENGTH ) );
					pgon.push_back( K::Point_2( target.x(), target.y() ) );
				}
				else {
					pgon.push_back( K::Point_2( source.x(), source.y() ) );
					pgon.push_back( K::Point_2( source.x() + LINE_LENGTH, source.y() ) );
					pgon.push_back( K::Point_2( target.x() + LINE_LENGTH, target.y() ) );
					pgon.push_back( K::Point_2( target.x(), target.y() ) );
				}
			}
			else {
				if( slope >= -1.0 && slope <= 1.0 ) {
					pgon.push_back( K::Point_2( source.x(), source.y() ) );
					pgon.push_back( K::Point_2( target.x(), target.y() ) );
					pgon.push_back( K::Point_2( target.x(), target.y() - LINE_LENGTH ) );
					pgon.push_back( K::Point_2( source.x(), source.y() - LINE_LENGTH ) );
				}
				else {
					pgon.push_back( K::Point_2( source.x(), source.y() ) );
					pgon.push_back( K::Point_2( target.x(), target.y() ) );
					pgon.push_back( K::Point_2( target.x() - LINE_LENGTH, target.y() ) );
					pgon.push_back( K::Point_2( source.x() - LINE_LENGTH, source.y() ) );
				}
			}
#ifdef DEBUG
			for( auto v=pgon.vertices_begin(); v!=pgon.vertices_end(); v++ ) {
				cerr << "pgon = " << v->x() << " " << v->y() << endl;
			}
			cerr << endl << endl;
#endif // DEBUG
		}
		
		//In order to crop the Voronoi diagram, we need to convert the bounding box
		//into a polygon. You'd think there'd be an easy way to do this. But there
		//isn't (or I haven't found it).
		CGAL::Polygon_2< K > bpoly;
		const vector< KeiRo::Base::Coord2 > &eleVec = _contourPtr->elements();
		
		for( unsigned int i = 0; i < eleVec.size(); i++ ) {
			bpoly.push_back( K::Point_2( eleVec[ i ].x(), eleVec[ i ].y() ) );
			//cerr << i << ": eleVec[i] = " << eleVec[i] << endl;
		}
		
		// cerr << "slope = " << slope << endl;
		
		if( pgon.orientation() == -1 ) {     // special case of Line_2
			
			pgon.reverse_orientation();
#ifdef DEBUG
			for( auto v=pgon.vertices_begin(); v!=pgon.vertices_end(); v++ ) {
				cerr << "pgon = " << v->x() << " " << v->y() << endl;
			}
			cerr << endl << endl;
#endif // DEBUG
		}

#ifdef DEBUG
		cerr << "bpoly_orientation: " << bpoly.orientation() << endl;
		cerr << "pgon_orientation: " << pgon.orientation() << endl;
		// check the polygon orientation
		if( bpoly.orientation() == -1 ){
			bpoly.reverse_orientation();
		}
		if( pgon.orientation() == -1 ){
			pgon.reverse_orientation();
		}
		cerr << "bpoly_orientation: " << bpoly << endl;
#endif // DEBUG
		
		if( pgon.is_simple() == false ) {
			cerr << "NOT_SIMPLE::pgon: " << pgon << endl;
		}
		if( bpoly.is_simple() == false ) {
			cerr << "NOT_SIMPLE::bpoly: " << bpoly << endl;
		}
		
		//Perform the intersection. Since CGAL is very general, it believes the
		//result might be multiple polygons with holes.
		std::list< CGAL::Polygon_with_holes_2< K > > isect;
		CGAL::intersection( pgon, bpoly, std::back_inserter( isect ) );
		
		//But we know better. The intersection of a convex polygon and a box is
		//always a single polygon without holes. Let's assert this.
		if( isect.size() == 0 ) {
			
			// skip small fragments
#ifdef DEBUG
			cerr << "sth is wrong here... at " << __LINE__ << " in " << __FILE__ << endl;
			cerr << "isect.size() = " << isect.size() << endl;
			cerr << "pgon: " << pgon.size() << endl;
			cerr << "pgon: " << pgon << endl << endl;
			cerr << "bpoly: " << bpoly << endl << endl;
#endif // DEBUG
			//assert( isect.size() == 1 );
		}
		else if( isect.size() >= 1 ) {
			
			if( isect.size() > 1 ) {
				cerr << "sth is wrong here... at " << __LINE__ << " in " << __FILE__ << endl;
				cerr << "isect.size() = " << isect.size() << endl;
			}
			//And recover the polygon of interest
			auto &poly_w_holes = isect.front();
			auto &poly_outer = poly_w_holes.outer_boundary();
			
			//Print the polygon as a WKT polygon
			vector< K::Point_2 > p;
			//cerr << fnum << ", ""\"POLYGON ((" << endl;
			for( auto v = poly_outer.vertices_begin(); v != poly_outer.vertices_end(); v++ ) {
				
				//cerr << setprecision(20) << "x = " << v->x() << " y = " << v->y() << endl;
				p.push_back( K::Point_2( CGAL::to_double( v->x() ), CGAL::to_double( v->y() ) ) );
			}
			
			// std::cout<<poly_outer.vertices_begin()->x()<<" "<<poly_outer.vertices_begin()->y()<<"))\"\n";
			_polyVec2D.push_back( p );
		}
	}
	mapSeedsandPolygons();
}

//
//  Voronoi::mapSeedsandPolygons -- map seeds and polygons
//
//  Inputs
//  none
//
//  Outputs
//  none
//
void Voronoi::mapSeedsandPolygons( void ) {
	
	for( unsigned int i = 0; i < _seedVecPtr->size(); i++ ) {
		
		K::Point_2 pt( ( *_seedVecPtr )[ i ].coordPtr->x(), ( *_seedVecPtr )[ i ].coordPtr->y() );
		
		// find appropriate polygon boundary
		for( unsigned int m = 0; m < _polyVec2D.size(); m++ ) {
			
			K::Point_2 *points = new K::Point_2[_polyVec2D[ m ].size()];
			vector< KeiRo::Base::Coord2 > coords;
			for( unsigned int n = 0; n < _polyVec2D[ m ].size(); n++ ) {
				
				// copy to points
				points[ n ] = K::Point_2( _polyVec2D[ m ][ n ].x(), _polyVec2D[ m ][ n ].y() );
				coords.push_back( KeiRo::Base::Coord2( CGAL::to_double( _polyVec2D[ m ][ n ].x() ),
				                          CGAL::to_double( _polyVec2D[ m ][ n ].y() ) ) );
			}
			
			CGAL::Bounded_side bside = CGAL::bounded_side_2( points, points + _polyVec2D[ m ].size(), pt );
			
			if( bside == CGAL::ON_BOUNDED_SIDE ) {
				
				// copy polygon
				KeiRo::Base::Polygon2 &p = *( *_seedVecPtr )[ i ].voronoiCellPtr;
				p.elements() = coords;
				p.updateCentroid();
				p.center() = p.centroid();
				p.area() = p.area();
				
#ifdef  DEBUG
				cerr << "poly.coords = " << poly.elements()[0];
				cerr << "test = " << (*_seedVecPtr)[i].voronoiCellPtr.elements()[0];
				cerr << "area = " << (*_seedVecPtr)[i].voronoiCellPtr->area() << " c = " << (*_seedVecPtr)[i].voronoiCellPtr->center();
				cerr << "area = " << itP->second.area() << endl;
				cerr << "pgon_area = " << poly.area() << endl;
#endif  // DEBUG
				// cout << " is inside the polygon.\n";
				// point inside
			}
			else if( bside == CGAL::ON_BOUNDARY ) {
				//cout << " is on the polygon boundary.\n";
				// point on the border
			}
			else if( bside == CGAL::ON_UNBOUNDED_SIDE ) {
				//cout << " is outside the polygon.\n";
				// point outside
			}
			
			delete[] points;
		}
	}
}

//
//  Voronoi::Voronoi -- default constructor
//
//  Inputs
//  none
//
//  Outputs
//  none
//
Voronoi::Voronoi( void ) {
	_id = 0;
	_contourPtr = NULL;
	_seedVecPtr = NULL;
	
	_polyVec2D.clear();
}

//
//  Voronoi::Voronoi -- copy constructor
//
//  Inputs
//  obj : object of this class
//
//  Outputs
//  none
//
Voronoi::Voronoi( const Voronoi &obj ) {
	_clear();
}


//------------------------------------------------------------------------------
//	Destructor
//------------------------------------------------------------------------------

//
//  Voronoi::~Voronoi --    destructor
//
//  Inputs
//  none
//
//  Outputs
//  none
//
Voronoi::~Voronoi( void ) {
}

// end of header file
// Do not add any stuff under this line.

