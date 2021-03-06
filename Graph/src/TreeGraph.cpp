//******************************************************************************
// TreeGraph.cpp
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
#include "TreeGraph.h"

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
    //  TreeGraph::printGraph -- print the graph.
    //
    //  Inputs
    //  g   : object of Grpah
    //
    //  Outputs
    //  none
    //
    void printGraph( const TreeGraph & graph )
    {
    	cerr << "TreeGraph:" << endl;
        cerr << "num_vertices = " << num_vertices( graph ) << endl;
        cerr << "num_edges = " << num_edges( graph ) << endl;

    #ifdef  DEBUG
        // print vertex information
        BGL_FORALL_VERTICES( vd, graph, TreeGraph ) {

            TreeGraph::degree_size_type      degrees         = out_degree( vd, graph );
            cerr << "vid = " << graph[vd].id << " level = " << graph[vd].level
                 << " childSize = " << graph[vd].childMap.size() << " ?= " << degrees
                 << " parentID = " << graph[vd].parentID << endl;
        }
    #endif  // DEBUG

    #ifdef  DEBUG
        // print edge information
        BGL_FORALL_EDGES( ed, graph, TreeGraph ) {

            TreeGraph::vertex_descriptor vdS = source( ed, graph );
            TreeGraph::vertex_descriptor vdT = target( ed, graph );

            cerr << "eid = " << graph[ ed ].id << " ( " << graph[ vdS ].id << " == " << graph[ vdT ].id << " ) " << endl;
        }
    #endif  // DEBUG
    }

    //
    //  TreeGraph::clearGraph -- clear the graph.
    //
    //  Inputs
    //  g   : object of Grpah
    //
    //  Outputs
    //  none
    //
    void clearGraph( TreeGraph & graph )
    {
        // clear edges
        TreeGraph::edge_iterator ei, ei_end, e_next;
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
        pair< TreeGraph::vertex_iterator, TreeGraph::vertex_iterator > vp;
        for ( vp = vertices( graph ); vp.first != vp.second;  ) {
            TreeGraph::vertex_descriptor vd = (*vp.first);
            ++vp.first;
            clear_vertex( vd, graph );
            remove_vertex( vd, graph );
        }
    }

} // namespace Graph