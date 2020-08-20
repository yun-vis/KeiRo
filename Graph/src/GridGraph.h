//******************************************************************************
// GridGraph.h
//	: header file for grid graph
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sun Feb 09 23:16:12 2020
//
//******************************************************************************

#ifndef _Graph_GridGraph_H
#define _Graph_GridGraph_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

#include <boost/config.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/iteration_macros.hpp>

using namespace boost;

#include "Coord2.h"
#include "GridGraphProperty.h"
#include "GridVertexProperty.h"
#include "GridEdgeProperty.h"

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

namespace Graph {

    typedef adjacency_list< listS, listS, undirectedS,
            GridVertexProperty, GridEdgeProperty,
            GridGraphProperty >  GridGraph;

    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    void printGraph( const GridGraph & g );
    void clearGraph( GridGraph & g );

} // namespace Graph

#endif  // _Graph_GridGraph_H
