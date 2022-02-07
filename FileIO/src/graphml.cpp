//******************************************************************************
// gml.cpp
//	: program file gml
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Nov 2 15:02:45 2021
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include "graphml.h"

namespace FileIO {

    //------------------------------------------------------------------------------
    //	Private Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  GraphML::GraphML --	constructor
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    GraphML::GraphML( void )
    {
		_isWithGeometry = false;
		_maxLevel = 0;
    }

    //
    //  GraphML::GraphML --	copy constructor
    //
    //  Input
    //	none
    //
    //  Output
    //	none
    //
    GraphML::GraphML( const GraphML & v )
    {
	    _graphmlTree    = v._graphmlTree;
		_graph          = v._graph;
	    _isWithGeometry = v._isWithGeometry;
		_maxLevel       = v._maxLevel;
    }
    
    
    //
    //  GraphML::loadGroup --	loadGroup function
    //
    //  Input
    //	QDomElement: xml element
    //
    //  Output
    //	none
    //
    void GraphML::loadGroup( QDomElement &parentElement, int parentID )
    {
    	// element layer
    	unsigned int layer = parentElement.attribute( "layer" ).toUInt();
		if( layer > _maxLevel ) _maxLevel = layer;
//	    cerr << "layer = " << layer << endl;
		
		// element name
    	QString name = parentElement.attribute( "name" );
//    	cerr << "name = " << name.toStdString() << endl;
	
		// add _graphmlTree node
	    Graph::TreeDirectedGraph::vertex_descriptor vdNew = add_vertex( _graphmlTree );
	    _graphmlTree[ vdNew ].id = num_vertices( _graphmlTree ) - 1;
	    _graphmlTree[ vdNew ].level = layer;
	    _graphmlTree[ vdNew ].initID = 0;
	    _graphmlTree[ vdNew ].parentID = parentID;
	    _graphmlTree[ vdNew ].coordPtr = new KeiRo::Base::Coord2( 0, 0 );
	
	    // add _graphmlTree edge
		if( parentID != -1 ){
			Graph::TreeDirectedGraph::vertex_descriptor vdP = vertex( parentID, _graphmlTree );
			pair< Graph::TreeDirectedGraph::edge_descriptor, unsigned int > foreE = add_edge( vdP, vdNew, _graphmlTree );
			Graph::TreeDirectedGraph::edge_descriptor foreED = foreE.first;
			_graphmlTree[ foreED ].id = num_edges( _graphmlTree ) - 1;
		}
	
	    QDomNodeList groupList = parentElement.childNodes();
    	for( unsigned int i = 0; i < groupList.size(); i++ ) {

    		// Select from the node list
    		QDomElement groupElement = groupList.item( i ).toElement();
    		// cerr << "name = " << groupElement.tagName().toStdString() << endl;

    		if( groupElement.tagName() == QString( "group" ) ){
    			loadGroup( groupElement, _graphmlTree[ vdNew ].id );
    		}
    		else if( groupElement.tagName() == QString( "node" ) ){
    			loadNode( groupElement );
    		}
    		else{
    			cerr << "Unrecognized tagName at " << __LINE__ << " in " << __FILE__ << endl;
    		}
    	}
    }
    
    //
    //  GraphML::loadNode --	loadNode function
    //
    //  Input
    //	QDomElement: xml element
    //
    //  Output
    //	none
    //
    void GraphML::loadNode( QDomElement & nodeElement )
    {
	    // element layer
	    unsigned int layer = nodeElement.attribute( "layer" ).toUInt();
 	    if( layer > _maxLevel ) _maxLevel = layer;
//	    cerr << "node layer = " << layer << " _maxLevel = " << _maxLevel
//			 << " layer > _maxLevel = " << (layer > _maxLevel) << endl;
//	    cerr << "node layer = " << layer.toStdString() << endl;
		
	    // element id
        QString id = nodeElement.attribute( "id" );
//        cerr << "id = " << id.toStdString() << endl;

        QDomNodeList dataList = nodeElement.childNodes();
		double x = 0.0, y = 0.0;
        // cerr << "dataList.size() = " << dataList.size() << endl;
        for( unsigned int j = 0; j < dataList.size(); j++ ){

            // Select from the node list
            QDomElement dataElement = dataList.item( j ).toElement();
			
            // element key
            QString key = dataElement.attribute( "key" );
//			cerr << "key = " << key.toStdString() << endl;
            if( key == QString( "d0" ) )
            {
				x = dataElement.firstChild().toText().data().toDouble();
//	            cerr << "x = " << x << endl;
			}
            else if( key == QString( "d1" ) ) {
				y = dataElement.firstChild().toText().data().toDouble();
//	            cerr << "y = " << y << endl;
			}
            else {
	            cerr << "sth is wrong here at " << __LINE__ << " in " << __FILE__ << endl;
			}
        }
	
	    Graph::BaseUndirectedGraph::vertex_descriptor vdNew = add_vertex( _graph );
	    _graph[ vdNew ].id = num_vertices( _graph ) - 1;
	    _graph[ vdNew ].initID = 0;
	    _graph[ vdNew ].level = layer;
	    _graph[ vdNew ].coordPtr = new KeiRo::Base::Coord2( x, y );
		
    }
    //
    //  GraphML::loadEdge --	loadEdge function
    //
    //  Input
    //	QDomElement: xml element
    //
    //  Output
    //	none
    //
    void GraphML::loadEdge( QDomElement & graphElement )
    {
    	QDomNodeList edgeList = graphElement.elementsByTagName( "edge" );
		cerr << "edgeList.size() = " << edgeList.size() << endl;
    	for( unsigned int i = 0; i < edgeList.size(); i++ ) {

    		// Select from the node list
    		QDomElement edgeElement = edgeList.item( i ).toElement();

    		// element source
    		QString source = edgeElement.attribute( "source" );
			unsigned int idS = source.toUInt();

    		// element target
    		QString target = edgeElement.attribute( "target" );
		    unsigned int idT = target.toUInt();
//		    cerr << "(source, target) = (" << idS << ", " << idT << ")"<< endl;
		
		    Graph::BaseUndirectedGraph::vertex_descriptor vdS= vertex( idS, _graph );
		    Graph::BaseUndirectedGraph::vertex_descriptor vdT= vertex( idT, _graph );
		
		    bool found = false;
		    Graph::BaseUndirectedGraph::edge_descriptor oldED;
		    tie( oldED, found ) = edge( vdS, vdT, _graph );
		
			if( found == false ){
				
				pair< Graph::BaseUndirectedGraph::edge_descriptor, unsigned int > foreE = add_edge( vdS, vdT, _graph );
				Graph::BaseUndirectedGraph::edge_descriptor foreED = foreE.first;
				_graph[ foreED ].id = num_edges( _graph ) - 1;
			}

    	}
    }

    //
    //  GraphML::load --	load function
    //
    //  Input
    //	string: file name
    //
    //  Output
    //	none
    //
    void GraphML::load( const string filename )
    {
		// initialization
	    _maxLevel = 0;

    	QString fileName = QString::fromStdString( filename );
    			
        // document object
        QDomDocument doc;
    	// Open your GraphML-file
    	QFile file( fileName );

    	// If it is not opened, or have failed to transmit the contents in QDocDocument
    	if ( !file.open( QIODevice::ReadOnly ) || !doc.setContent( &file ) ) {
    		// the refund list, but empty
    		cerr << "something is wrong here... at " << __LINE__ << " in " << __FILE__ << endl;
    		cerr << "fileName = " << fileName.toStdString() << endl;
    		return;
    	}
    	
    	// read the xml file
    	// get root names and attributes
    	QDomNodeList rootNodeList = doc.documentElement().childNodes();
    	QDomElement graphElement;
    	for( unsigned int i = 0; i < rootNodeList.size(); i++ ) {
    		if( rootNodeList.item( i ).toElement().tagName() == QString( "graph" ) ){
    			cerr << "rootElem.tagName() = " << rootNodeList.item( i ).toElement().tagName().toStdString() << endl;
    			graphElement = rootNodeList.item( i ).toElement();
    		}
    	}
		
		// add root node for the _graphmlTree
	    Graph::TreeDirectedGraph::vertex_descriptor vdNew = add_vertex( _graphmlTree );
	    _graphmlTree[ vdNew ].id = 0;
	    _graphmlTree[ vdNew ].level = 0;
	    _graphmlTree[ vdNew ].initID = 0;
	    _graphmlTree[ vdNew ].parentID = 0;
	    _graphmlTree[ vdNew ].coordPtr = new KeiRo::Base::Coord2( 5, 0 );
    	
    	// load nodes
    	if( graphElement.firstChild().toElement().tagName() == QString( "node" ) ){
    		QDomNodeList nodeList = graphElement.childNodes();
    		for( unsigned int i = 0; i < nodeList.size(); i++ ){
    			QDomElement nodeElement = nodeList.item( i ).toElement();
    			if( nodeElement.tagName() == QString( "node" ) )
	                loadNode( nodeElement );
    		}
    	}
    	// load groups
    	else if( graphElement.firstChild().toElement().tagName() == QString( "group" ) ){
    		QDomNodeList groupList = graphElement.childNodes();
    		// cerr << "groupList = " << groupList.size() << endl;
    		for( unsigned int i = 0; i < groupList.size(); i++ ){
    			QDomElement groupElement = groupList.item( i ).toElement();
    			if( groupElement.tagName() == QString( "group" ) )
    				loadGroup( groupElement, 0 );
    		}
    	}
    	else{
    		cerr << "Unrecognized tagName at " << __LINE__ << " in " << __FILE__ << endl;
    	}
	
    	// load edges
	    loadEdge( graphElement );

//#ifdef DEBUG
	    cerr << "*****************************" << endl;
		cerr << "_maxLevel = " << _maxLevel << endl;
	    Graph::printGraph( _graphmlTree );
	    cerr << "*****************************" << endl;
	    Graph::printGraph( _graph );
	    cerr << "*****************************" << endl;
//#endif // DEBUG
    }
	
} // namespace FilIO
