//******************************************************************************
// Compression.cpp
//	: program file for Compression
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Mon Mar 16 07:58:23 2020
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include "Compression.h"


    //------------------------------------------------------------------------------
    //	Private Functions
    //------------------------------------------------------------------------------
    //
    //  Compression::_closeToSamplesInt --	find if the two points are at the same position
    //
    //  Inputs
    //	coord
    //  index
    //
    //  Outputs
    //	none
    //
    bool Compression::_closeToSamplesInt( KeiRo::Base::Coord2 coordS, KeiRo::Base::Coord2 coordT )
    {
//		cerr << "norm = " << ( coordS - coordT ).norm() << endl;
		if( ( coordS - coordT ).norm() == 0 ){
			return true;
		}
		else{
			return false;
		}
    }
    
    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------
    //
    //  Compression::_init -- initialize the compressed data
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void Compression::_init( void )
    {
        _clear();
    }

    //
    //  Compression::_clear -- clear the compressed data
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void Compression::_clear( void )
    {
		clearGraph( _graph );
    }

    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------
    
    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  Compression::Compression --	default constructor
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    Compression::Compression( void )
    {
        //------------------------------------------------------------------------------
        // configuration file
        //------------------------------------------------------------------------------
    }

	//
	//  Compression::Compression --	copy constructor
	//
	//  Inputs
	//	none
	//
	//  Outputs
	//	none
	//
	Compression::Compression( const Compression & v )
	{
		_graph        = v._graph;
	}

    //
    //  Compression::~Compression --	destructor
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    Compression::~Compression()
    {
    }

    //------------------------------------------------------------------------------
    //	Assignment operators
    //------------------------------------------------------------------------------
    Compression & Compression::operator = ( const Compression & v )
    {
	    if ( this != &v ) {
		    _graph        = v._graph;
	    }
	    return *this;
    }


    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    //
    //  Compression::findVertex --	find if the coordinate has been occupied
    //
    //  Inputs
    //	coord
    //  vertex_descriptor
    //
    //  Outputs
    //	none
    //
    bool Compression::findVertex( KeiRo::Base::Coord2 coord, unsigned int sortedID, unsigned int &index )
    {
		index = 0;
		BGL_FORALL_VERTICES( vd, _graph, Graph::BaseUndirectedGraph ) {

			if( _graph[vd].initID == sortedID ){
				if( _closeToSamplesInt( *_graph[vd].coordPtr, coord ) ){
					index = _graph[vd].id;
					return true;
				}
			}
		}
		return false;
    }

    //
    //  Compression::addVertex --	add a new vertex
    //
    //  Inputs
    //	coordPtr
    //  level
    //
    //  Outputs
    //	vertex id
    //
    unsigned int Compression::addVertex( KeiRo::Base::Coord2 coord, unsigned int level, unsigned int sortedID )
    {
		unsigned int vid = num_vertices( _graph );
		Graph::BaseUndirectedGraph::vertex_descriptor vdNew = add_vertex( _graph );
		_graph[ vdNew ].level     = level;
		_graph[ vdNew ].id        = vid;
	    _graph[ vdNew ].namePtr   = new string( to_string( vid ) );
		_graph[ vdNew ].initID    = sortedID;
		_graph[ vdNew ].weight    = 0;
		_graph[ vdNew ].coordPtr  = new KeiRo::Base::Coord2( coord.x(), coord.y() );
		_graph[ vdNew ].widthPtr  = new double( 10.0 );
		_graph[ vdNew ].heightPtr = new double( 10.0 );
	
		return vid;
    }
    
    //
    //  Compression::addEdge --	add a new edge
    //
    //  Inputs
    //	source vid
    //  target vid
    //  isCompressed
    //
    //  Outputs
    //	none
    //
    void Compression::addEdge( unsigned int idS, unsigned int idT, vector< unsigned int > &intermediateVec,
							   unsigned int sortedID, bool isCompressed )
    {
		cerr << "here isCompressed = " << isCompressed << endl;
	    unsigned int eid = num_edges( _graph );
//	    cerr << "idS = " << idS << " idT = " << idT << endl;
        Graph::BaseUndirectedGraph::vertex_descriptor vdS = vertex( idS, _graph );
        Graph::BaseUndirectedGraph::vertex_descriptor vdT = vertex( idT, _graph );

        if( isCompressed == true ){

        	map< int, Graph::BaseUndirectedGraph::vertex_descriptor > vdMap;
        	vector< KeiRo::Base::Coord2 > elements;
        	elements.push_back( *_graph[vdS].coordPtr );
        	elements.push_back( *_graph[vdT].coordPtr );
        	KeiRo::Base::Edge2 e( elements );
        	
        	// sort vertices on the edge
        	vdMap.insert( pair< int, Graph::BaseUndirectedGraph::vertex_descriptor >( 0, vdS ) );
        	BGL_FORALL_VERTICES( vd, _graph, Graph::BaseUndirectedGraph ) {
        	
#ifdef DEBUG_COMPRESSION
        		if( _graph[vdS].id == 12 && _graph[vdT].id == 13 ) {
        			cerr << "vid = " << _graph[vd].id << endl;
        			cerr << "_graph[vdS].coord = " << *_graph[vdS].coordPtr;
        			cerr << "_graph[vdT].coord = " << *_graph[vdT].coordPtr;
        			cerr << "_graph[vd].coord = " << *_graph[vd].coordPtr;
        			cerr << "e.isOnEdge( *_graph[vd].coordPtr ) = " << e.isOnEdge( *_graph[vd].coordPtr ) << endl;
        		}
#endif // DEBUG_COMPRESSION
				if( (vd != vdS) && (vd != vdT) && sortedID == _graph[vd].initID &&
        		    e.isOnEdge( *_graph[vd].coordPtr ) == true ){
        			int distance = (*_graph[vd].coordPtr - *_graph[vdS].coordPtr).norm();
        			vdMap.insert( pair< int, Graph::BaseUndirectedGraph::vertex_descriptor >( distance, vd ) );
        		}
        	}
        	vdMap.insert( pair< int, Graph::BaseUndirectedGraph::vertex_descriptor >( (*_graph[vdT].coordPtr - *_graph[vdS].coordPtr).norm(), vdT ) );
        	
        	// insert edge segments
//        	cerr << "vdMap.size() = " << vdMap.size() << endl;
        	for( unsigned int i = 1; i < vdMap.size(); i++ ){

        		map< int, Graph::BaseUndirectedGraph::vertex_descriptor >::iterator itS = vdMap.begin();
        		map< int, Graph::BaseUndirectedGraph::vertex_descriptor >::iterator itT = vdMap.begin();
        		std::advance( itS, i-1 );
        		std::advance( itT, i );
        		Graph::BaseUndirectedGraph::vertex_descriptor vdSS = itS->second;
        		Graph::BaseUndirectedGraph::vertex_descriptor vdST = itT->second;
		        if( i != vdMap.size()-1 ) intermediateVec.push_back( _graph[ vdST ].id );

        		bool found = false;
        		Graph::BaseUndirectedGraph::edge_descriptor oldED;
        		tie( oldED, found ) = edge( vdSS, vdST, _graph );

        		if( found == false ){
        			
        			pair< Graph::BaseUndirectedGraph::edge_descriptor, unsigned int > foreE = add_edge( vdSS, vdST, _graph );
        			Graph::BaseUndirectedGraph::edge_descriptor foreED = foreE.first;

        			// base_graph
        			_graph[ foreED ].id = eid;
        			_graph[ foreED ].level = _graph[vdS].level;

        			_graph[ foreED ].angle = 0.0;
        			_graph[ foreED ].weight = (_graph[ foreED ].level + 1) * (*_graph[vdST].coordPtr - *_graph[vdSS].coordPtr).norm();;
        			_graph[ foreED ].visit = false;
        			_graph[ foreED ].visitedTimes = 0;

        			_graph[ foreED ].isFore = false;
        			_graph[ foreED ].isBack = false;
        			eid++;
#ifdef DEBUG_COMPRESSION
        			cerr << "new edge = ( " << _graph[ vdSS ].id << ", " << _graph[ vdST ].id << " ) " << endl;
#endif // DEBUG_COMPRESSION
        		}
        	}
        }
        else{
        	
        	bool found = false;
        	Graph::BaseUndirectedGraph::edge_descriptor oldED;
        	tie( oldED, found ) = edge( vdS, vdT, _graph );

        	if( found == false ){
        		pair< Graph::BaseUndirectedGraph::edge_descriptor, unsigned int > foreE = add_edge( vdS, vdT, _graph );
        		Graph::BaseUndirectedGraph::edge_descriptor foreED = foreE.first;

        		// base_graph
        		_graph[ foreED ].id = eid;
        		_graph[ foreED ].level = _graph[vdS].level;

        		_graph[ foreED ].angle = 0.0;
        		_graph[ foreED ].weight = (_graph[ foreED ].level + 1) * (*_graph[vdT].coordPtr - *_graph[vdS].coordPtr).norm();
        		_graph[ foreED ].visit = false;
        		_graph[ foreED ].visitedTimes = 0;

        		_graph[ foreED ].isFore = false;
        		_graph[ foreED ].isBack = false;
#ifdef DEBUG_COMPRESSION
        		cerr << "new edge = ( " << _graph[ vdS ].id << ", " << _graph[ vdT ].id << " ) " << endl;
#endif // DEBUG_COMPRESSION
        	}
        }
    }

    //
    //  Compression::addBridgeEdge --	add a new bridge edge
    //
    //  Inputs
    //	source vid
    //  target vid
    //
    //  Outputs
    //	none
    //
    void Compression::addBridgeEdge( unsigned int idS, unsigned int idT )
	{
		unsigned int eid = num_edges( _graph );
		Graph::BaseUndirectedGraph::vertex_descriptor vdS = vertex( idS, _graph );
		Graph::BaseUndirectedGraph::vertex_descriptor vdT = vertex( idT, _graph );

		bool found = false;
		Graph::BaseUndirectedGraph::edge_descriptor oldED;
		tie( oldED, found ) = edge( vdS, vdT, _graph );

		if( found == false ){
			pair< Graph::BaseUndirectedGraph::edge_descriptor, unsigned int > foreE = add_edge( vdS, vdT, _graph );
			Graph::BaseUndirectedGraph::edge_descriptor foreED = foreE.first;
			
			// base_graph
			_graph[ foreED ].id = eid;
			_graph[ foreED ].level = _graph[vdS].level;
			
			_graph[ foreED ].angle = 0.0;
			_graph[ foreED ].weight = 0.0;
			_graph[ foreED ].visit = false;
			_graph[ foreED ].visitedTimes = 0;
			
			_graph[ foreED ].isFore = false;
			_graph[ foreED ].isBack = false;
#ifdef DEBUG_COMPRESSION
			cerr << "new bridge edge = ( " << _graph[ vdS ].id << ", " << _graph[ vdT ].id << " ) " << endl;
#endif // DEBUG_COMPRESSION
		}
    }
    //------------------------------------------------------------------------------
    //	Friend functions
    //------------------------------------------------------------------------------


    //------------------------------------------------------------------------------
    //	I/O functions
    //------------------------------------------------------------------------------




