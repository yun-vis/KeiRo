//******************************************************************************
// TreeDirectedGraph.cpp
//	: program file for tree graph
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Dec 27 23:16:12 2018
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------
#include "TreeDirectedGraph.h"

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
    //	Special functions
    //------------------------------------------------------------------------------
    //
    //  TreeDirectedGraph::printGraph -- print the graph.
    //
    //  Inputs
    //  g   : object of Grpah
    //
    //  Outputs
    //  none
    //
    void printGraph( const TreeDirectedGraph & graph )
    {
    	cerr << "TreeDirectedGraph:" << endl;
        cerr << "num_vertices = " << num_vertices( graph ) << endl;
        cerr << "num_edges = " << num_edges( graph ) << endl;

//	#ifdef  DEBUG
        // print vertex information
	    BGL_FORALL_VERTICES( vd, graph, TreeDirectedGraph ) {
		
		    TreeDirectedGraph ::degree_size_type      degrees         = out_degree( vd, graph );
		    cerr << "vid = " << graph[vd].id
			     << " name = " << *graph[vd].namePtr
			     << " level = " << graph[vd].level
		         << " childSize = " << graph[vd].childMap.size() << " ?= " << degrees
			     << " parentID = " << graph[vd].parentID
			     << " coord = " << *graph[vd].coordPtr;
	    }
//	#endif  // DEBUG

//    #ifdef  DEBUG
        // print edge information
        BGL_FORALL_EDGES( ed, graph, TreeDirectedGraph ) {

            TreeDirectedGraph::vertex_descriptor vdS = source( ed, graph );
            TreeDirectedGraph::vertex_descriptor vdT = target( ed, graph );

            cerr << "eid = " << graph[ ed ].id << " ( " << graph[ vdS ].id << " == " << graph[ vdT ].id << " ) " << endl;
        }
//    #endif  // DEBUG
    }

    //
    //  TreeDirectedGraph::clearGraph -- clear the graph.
    //
    //  Inputs
    //  g   : object of Grpah
    //
    //  Outputs
    //  none
    //
    void clearGraph( TreeDirectedGraph & graph )
    {
        // clear edges
        TreeDirectedGraph::edge_iterator ei, ei_end, e_next;
        tie( ei, ei_end ) = edges( graph );
        for ( e_next = ei; ei != ei_end; ei = e_next ) {
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
        pair< TreeDirectedGraph::vertex_iterator, TreeDirectedGraph::vertex_iterator > vp;
        for ( vp = vertices( graph ); vp.first != vp.second;  ) {
            TreeDirectedGraph::vertex_descriptor vd = (*vp.first);
            ++vp.first;
            clear_vertex( vd, graph );
            remove_vertex( vd, graph );
        }
    }

} // namespace Graph