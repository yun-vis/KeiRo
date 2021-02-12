//******************************************************************************
// TreeDirectedGraph.h
//	: header file for tree graph
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sun Feb 09 23:16:12 2020
//
//******************************************************************************

#ifndef _Graph_TreeDirectedGraph_H
#define _Graph_TreeDirectedGraph_H

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
#include "TreeGraphProperty.h"
#include "TreeVertexProperty.h"
#include "TreeEdgeProperty.h"

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

namespace Graph {

    typedef adjacency_list< listS, listS, bidirectionalS,
            TreeVertexProperty, TreeEdgeProperty,
            TreeGraphProperty >  TreeDirectedGraph;

    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    void printGraph( const TreeDirectedGraph & g );
    void clearGraph( TreeDirectedGraph & g );

} // namespace Graph

#endif  // _Graph_TreeDirectedGraph_H
