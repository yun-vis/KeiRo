#ifndef _File_GraphML_H
#define _File_GraphML_H

#include <QtXml/QDomDocument>
#include <QtCore/QFile>

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

#ifndef Q_MOC_RUN
#include "TreeDirectedGraph.h"
#include "BaseUndirectedGraph.h"
#endif // Q_MOC_RUN

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

namespace FileIO {

    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class GraphML
    {
    private:
    
		bool _isWithGeometry;
		unsigned int _maxLevel;
	    Graph::TreeDirectedGraph                        *_graphmlTree;
	    Graph::BaseUndirectedGraph                      _graph;
	    vector< Graph::BaseUndirectedGraph >            _subgraphVec;

    protected:

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        void _init( int __width, int __height );

    public:

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        GraphML( void );
        // copy constructor
        GraphML( const GraphML & v );
        // destructor
        virtual ~GraphML( void ) {}

        //------------------------------------------------------------------------------
        //	Reference to elements
        //------------------------------------------------------------------------------
        bool &	                    isWithGeometry( void ) 	        { return _isWithGeometry; }
	    const bool &	            isWithGeometry( void ) const	{ return _isWithGeometry; }
	
	    unsigned int &	            maxLevel( void ) 	            { return _maxLevel; }
	    const unsigned int &	    maxLevel( void ) const	        { return _maxLevel; }

	    Graph::TreeDirectedGraph &	            graphmlTree( void ) 	    { return _graphmlTree; }
	    const Graph::TreeDirectedGraph &  	    graphmlTree( void ) const	{ return _graphmlTree; }
		
	    //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        void init( int __width, int __height ) {
            _init( __width, __height );
        }
        void load( const string filename );
        void loadGroup( QDomElement & groupElement, int parentID = -1 );
        void loadNode( QDomElement & nodeElement );
        void loadEdge( QDomElement & graphElement );

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream & operator << ( ostream & stream, const GraphML & obj );
        // input
        friend istream & operator >> ( istream & stream, GraphML & obj );
        // class name
        virtual const char * className( void ) const { return "GraphML"; }

    };
    
} // namespace FileIO


#endif // _File_GraphML_H
