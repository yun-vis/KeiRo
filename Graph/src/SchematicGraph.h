#ifndef _BoundaryGraph_H
#define _BoundaryGraph_H


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

// force-directed layout
#include <boost/graph/fruchterman_reingold.hpp>
//#include <boost/graph/kamada_kawai_spring_layout.hpp>
#include <boost/graph/random_layout.hpp>
#include <boost/graph/topology.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/graph/connected_components.hpp>

using namespace boost;

#include "Coord2.h"
//#include "Grid2.h"
#include "SchematicGraphProperty.h"
#include "SchematicVertexProperty.h"
#include "SchematicEdgeProperty.h"

namespace Graph {
	
	typedef adjacency_list< listS, listS, undirectedS,
			SchematicVertexProperty, SchematicEdgeProperty,
			SchematicGraphProperty > SchematicGraph;
	
	typedef pair< SchematicGraph::vertex_descriptor,
			SchematicGraph::edge_descriptor > VEPair;
//	typedef map< Grid2, VEPair > VEMap;

//------------------------------------------------------------------------------
//	Customized BaseGraph Functions
//------------------------------------------------------------------------------
	
	void printGraph( const SchematicGraph &g );
	
	void clearGraph( SchematicGraph &g );
	
	void resetVisitedTimes( SchematicGraph &g );
}
#endif  // _BoundaryGraph_H
