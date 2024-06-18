//==============================================================================
// BaseGraph.cpp
//      : program file for graph function
//
//==============================================================================

#include "SchematicGraph.h"

namespace Graph {
//------------------------------------------------------------------------------
//	Customized Vertex Functions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//	Customized Edge Functions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//	Customized Layout Functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	Customized SchematicGraph Functions
//------------------------------------------------------------------------------
//
//  SchematicGraph::resetVisitedTimes -- reset edge visitedTimes values.
//
//  Inputs
//  g   : object of Graph
//
//  Outputs
//  none
//
	void resetVisitedTimes( SchematicGraph &graph ) {
		BGL_FORALL_EDGES( ed, graph, SchematicGraph )
		{
			
			graph[ ed ].visitedTimes = -1;
		}
	}

//
//  SchematicGraph::printGraph -- print the graph.
//
//  Inputs
//  g   : object of Graph
//
//  Outputs
//  none
//
	void printGraph( const SchematicGraph &graph ) {
		cerr << "Printing SchematicGraph..." << endl;
		cerr << "num_vertices = " << num_vertices( graph ) << endl;
		cerr << "num_edges = " << num_edges( graph ) << endl;

//#ifdef  DEBUG
		// print vertex information
		BGL_FORALL_VERTICES( vd, graph, SchematicGraph )
		{
			
			SchematicGraph::degree_size_type degrees = out_degree( vd, graph );
			cerr << "id = " << graph[ vd ].id << endl;
			//cerr << "initID = " << graph[ vd ].initID << endl;
			//cerr << "lineID.size() = " << graph[ vd ].lineID.size() << endl;
			//cerr << "isFixed = " << graph[ vd ].isFixed << endl;
			
			//cerr << "coord = " << *graph[ vd ].coordPtr;
			//cerr << "geo = " << *graph[ vd ].geoPtr;
			//cerr << "smooth = " << *graph[ vd ].smoothPtr;
			//v1cerr << "centroid = " << *graph[ vd ].centroidPtr;
		}
//#endif  // DEBUG

//#ifdef  DEBUG
		// print edge information
		BGL_FORALL_EDGES( ed, graph, SchematicGraph )
		{
			
			SchematicGraph::vertex_descriptor vdS = source( ed, graph );
			SchematicGraph::vertex_descriptor vdT = target( ed, graph );
			
			cerr << "eid = " << graph[ ed ].id << " ( " << graph[ vdS ].id << " == " << graph[ vdT ].id << " ) "
			     << endl;
			//cerr << "w = " << graph[ ed ].weight << endl;
			//cerr << "angle = " << graph[ ed ].angle << endl;
			//cerr << "geoangle = " << graph[ ed ].geoAngle << endl;
			//cerr << "smoangle = " << graph[ ed ].smoothAngle << endl;
			//cerr << "targetangle = " << graph[ ed ].targetAngle << endl;
		}
//#endif  // DEBUG
	}

//
//  SchematicGraph::clearGraph -- clear the graph.
//
//  Inputs
//  g   : object of Grpah
//
//  Outputs
//  none
//
	void clearGraph( SchematicGraph &graph ) {
		// clear edges
		SchematicGraph::edge_iterator ei, ei_end, e_next;
		tie( ei, ei_end ) = edges( graph );
		for( e_next = ei; ei != ei_end; ei = e_next ) {
			e_next++;
			remove_edge( *ei, graph );
		}

#ifdef  SKIP
		BGL_FORALL_EDGES( edge, graph, BaseGraph )
		{
			remove_edge( edge, graph );
		}
#endif  // SKIP
		
		// clear vertices
		pair <SchematicGraph::vertex_iterator, SchematicGraph::vertex_iterator> vp;
		for( vp = vertices( graph ); vp.first != vp.second; ) {
			SchematicGraph::vertex_descriptor vd = ( *vp.first );
			++vp.first;
			clear_vertex( vd, graph );
			remove_vertex( vd, graph );
		}
	}
	
}