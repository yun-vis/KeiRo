//******************************************************************************
// GridGraph.cpp
//	: program file for grid graph
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Dec 27 23:16:12 2018
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------
#include "GridGraph.h"

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
    //  GridGraph::printGraph -- print the graph.
    //
    //  Inputs
    //  g   : object of Grpah
    //
    //  Outputs
    //  none
    //
    void printGraph( const GridGraph & graph )
    {
        cerr << "num_vertices = " << num_vertices( graph ) << endl;
        cerr << "num_edges = " << num_edges( graph ) << endl;

    #ifdef  DEBUG
        // print vertex information
        int count = 0;
        BGL_FORALL_VERTICES( vd, graph, GridGraph ) {

            //GridGraph::degree_size_type      degrees         = out_degree( vd, graph );
            //cerr << "vid = " << graph[vd].id << " level = " << graph[vd].level
            //     << " leafSize = " << graph[vd].leafVec.size() << endl;
            //if( graph[vd].leafVec.size() == 1 ) count++;
        }
        cerr << "count = " << count << " ?= nVertices = " << num_vertices( graph ) << endl;
    #endif  // DEBUG

    #ifdef  DEBUG
        // print edge information
        BGL_FORALL_EDGES( ed, graph, GridGraph ) {

            GridGraph::vertex_descriptor vdS = source( ed, graph );
            GridGraph::vertex_descriptor vdT = target( ed, graph );

            cerr << "eid = " << graph[ ed ].id << " ( " << graph[ vdS ].id << " == " << graph[ vdT ].id << " ) " << endl;
        }
    #endif  // DEBUG
    }

    //
    //  GridGraph::clearGraph -- clear the graph.
    //
    //  Inputs
    //  g   : object of Grpah
    //
    //  Outputs
    //  none
    //
    void clearGraph( GridGraph & graph )
    {
        // clear edges
        GridGraph::edge_iterator ei, ei_end, e_next;
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
        pair< GridGraph::vertex_iterator, GridGraph::vertex_iterator > vp;
        for ( vp = vertices( graph ); vp.first != vp.second;  ) {
            GridGraph::vertex_descriptor vd = (*vp.first);
            ++vp.first;
            clear_vertex( vd, graph );
            remove_vertex( vd, graph );
        }
    }

} // namespace Graph