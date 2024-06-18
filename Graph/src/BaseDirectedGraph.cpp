//******************************************************************************
// BaseDirectedGraph.cpp
//      : program file for graph function
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Mon Mar 14 02:16:23 2019
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include "graph/BaseDirectedGraph.h"

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
    void randomGraphLayout( BaseDirectedGraph & graph, double width, double height )
    {
        boost::random::minstd_rand gen;
        topologyType topo( gen, -width/2.0, -height/2.0, width/2.0, height/2.0 );

        PositionVec positionVec( num_vertices( graph ) );
        //PositionMap position( positionVec.begin(), get( vertex_index, graph ) );
        PositionMap position( positionVec.begin(), get( &BaseVertexProperty::id, graph ) );

        random_graph_layout( graph, position, topo );

        // write the posotion
        BGL_FORALL_VERTICES( vd, graph, BaseDirectedGraph ) {
                graph[ vd ].coordPtr->x() = position[ vd ][0];
                graph[ vd ].coordPtr->y() = position[ vd ][1];
                //cerr << "vertexIndex[ " << vertexIndex[ vd ] << " ] = " << vertexCoord[ vd ] << endl;
            }
    }

    void fruchtermanGraphLayout( BaseDirectedGraph & graph, double width, double height )
    {
        boost::random::minstd_rand gen;
        double shift = 1e-5;
        //topologyType topo( gen, -DEFAULT_WIDTH/2.0, -DEFAULT_HEIGHT/2.0, DEFAULT_WIDTH/2.0, DEFAULT_HEIGHT/2.0 );
        //topologyType topo( gen, -DEFAULT_WIDTH/shift, -DEFAULT_HEIGHT/shift, DEFAULT_WIDTH/shift, DEFAULT_HEIGHT/shift );
        //topologyType topo2( gen, -DEFAULT_WIDTH/2.0, -DEFAULT_HEIGHT/2.0, DEFAULT_WIDTH/2.0, DEFAULT_HEIGHT/2.0 );
        topologyType topo( gen, -1.0, -1.0, 1.0, 1.0 );
        //topologyType topo( gen, -shift, -shift, shift, shift );

        PositionVec positionVec( num_vertices( graph ) );
        //PositionMap position( positionVec.begin(), get( vertex_index, graph ) );
        PositionMap position( positionVec.begin(), get( &BaseVertexProperty::id, graph ) );
        DifferenceVec differenceVec( num_vertices( graph ) );
        //DifferenceMap difference( differenceVec.begin(), get( vertex_index, graph ) );
        DifferenceMap difference( differenceVec.begin(), get( &BaseVertexProperty::id, graph ) );


        BGL_FORALL_VERTICES( vd, graph, BaseDirectedGraph ) {
                position[ vd ][0] = position[ vd ][0] * shift;
                position[ vd ][1] = position[ vd ][1] * shift;
                //cerr << "vertexIndex[ " << vertexIndex[ vd ] << " ] = " << position[ vd ][0] << ", " << position[ vd ][1] << endl;
            }

        //fruchterman_reingold_force_directed_layout( graph, position, topo );
        fruchterman_reingold_force_directed_layout( graph, position, topo,
                                                    square_distance_attractive_force(),
                                                    square_distance_repulsive_force(),
                                                    make_grid_force_pairs( topo, position, graph ),
                                                    linear_cooling< double >( 100 ),
                                                    difference );

        //kamada_kawai_spring_layout( graph, position, edgeWeight, topo, true, done );
        //detail::graph::edge_or_side<EdgeOrSideLength, double> edge_or_side_length;
        //kamada_kawai_spring_layout( graph, position, edgeWeight, topo, true );
        //                            , edge_or_side_length,
        //                            layout_tolerance< double >(),
        //                            weight_type(1.0) );

        // write the posotion
        BGL_FORALL_VERTICES( vd, graph, BaseDirectedGraph ) {
            graph[ vd ].coordPtr->x() = position[ vd ][0]*width/4.0;
            graph[ vd ].coordPtr->y() = position[ vd ][1]*height/4.0;
            //cerr << "vertexIndex[ " << vertexIndex[ vd ] << " ] = " << position[ vd ][0] << ", " << position[ vd ][1] << endl;
            //cerr << "vertexIndex[ " << vertexIndex[ vd ] << " ] = " << vertexCoord[ vd ] << endl;
        }
    }

    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    //
    //  BaseDirectedGraph::printGraph -- print the graph.
    //
    //  Inputs
    //  g   : object of Grpah
    //
    //  Outputs
    //  none
    //
    void printGraph( BaseDirectedGraph & graph )
    {
        cerr << "num_vertices = " << num_vertices( graph ) << endl;
        cerr << "num_edges = " << num_edges( graph ) << endl;

    #ifdef  DEBUG
        // print vertex information
        BGL_FORALL_VERTICES( vd, graph, BaseDirectedGraph ) {

            BaseDirectedGraph::degree_size_type      degrees         = out_degree( vd, graph );
        }
    #endif  // DEBUG

    #ifdef  DEBUG
        // print edge information
        BGL_FORALL_EDGES( ed, graph, BaseDirectedGraph ) {

            BaseDirectedGraph::vertex_descriptor vdS = source( ed, graph );
            BaseDirectedGraph::vertex_descriptor vdT = target( ed, graph );

            cerr << "eid = " << graph[ ed ].id << " ( " << graph[ vdS ].id << " == " << graph[ vdT ].id << " ) " << endl;
        }
    #endif  // DEBUG
    }

    //
    //  BaseDirectedGraph::clearGraph -- clear the graph.
    //
    //  Inputs
    //  g   : object of Graph
    //
    //  Outputs
    //  none
    //
    void clearGraph( BaseDirectedGraph & graph )
    {
        // clear edges
        BaseDirectedGraph::edge_iterator ei, ei_end, e_next;
        tie( ei, ei_end ) = edges( graph );
        for ( e_next = ei; ei != ei_end; ei = e_next ) {
            e_next++;
            remove_edge( *ei, graph );
        }

        // clear vertices
        pair< BaseDirectedGraph::vertex_iterator, BaseDirectedGraph::vertex_iterator > vp;
        for ( vp = vertices( graph ); vp.first != vp.second;  ) {
            BaseDirectedGraph::vertex_descriptor vd = (*vp.first);
            ++vp.first;
            clear_vertex( vd, graph );
            remove_vertex( vd, graph );
        }
    }

} // namespace Graph