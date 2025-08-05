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
	    _subGraphNodeIndex = 0;
	    
		_subGraphMap.clear();
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
		_isWithGeometry = v._isWithGeometry;
		_maxLevel       = v._maxLevel;
	    _subGraphNodeIndex = v._subGraphNodeIndex;
	
	    _graphmlTree    = v._graphmlTree;
	    _subGraphMap    = v._subGraphMap;
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
    	// element level
    	unsigned int level = parentElement.attribute( "level" ).toUInt();
		if( level > _maxLevel ) _maxLevel = level;
//	    cerr << "level = " << level << endl;
		
		// element name
    	QString name = parentElement.attribute( "name" );
//    	cerr << "name = " << name.toStdString() << endl;
	
		// add _graphmlTree node
	    Graph::TreeDirectedGraph::vertex_descriptor vdNew = add_vertex( _graphmlTree );
	    _graphmlTree[ vdNew ].id = num_vertices( _graphmlTree ) - 1;
	    _graphmlTree[ vdNew ].namePtr = new string( name.toStdString() );
	    _graphmlTree[ vdNew ].level = level;
	    _graphmlTree[ vdNew ].initID = 0;
	    _graphmlTree[ vdNew ].parentID = parentID;
	    _graphmlTree[ vdNew ].isSelected = false;
	    _graphmlTree[ vdNew ].coordPtr = new KeiRo::Base::Coord2( 0, 0 );
	
		// load group attribute
	    XML::getStyleElement( parentElement,
	                          _graphmlTree[ vdNew ].attribute.fill(), _graphmlTree[ vdNew ].attribute.stroke(),
	                          _graphmlTree[ vdNew ].attribute.strokeWidth() );
		
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
    			loadNode( groupElement, _graphmlTree[ vdNew ].id );
    		}
    		else{
    			cerr << "Unrecognized tagName at " << groupElement.tagName().toStdString()<< __LINE__ << " in " << __FILE__ << endl;
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
    void GraphML::loadNode( QDomElement & nodeElement, int parentID )
    {
	    // element level
	    unsigned int level = nodeElement.attribute( "level" ).toUInt();
 	    if( level > _maxLevel ) _maxLevel = level;
//	    cerr << "node level = " << level << " _maxLevel = " << _maxLevel
//			 << " level > _maxLevel = " << (level > _maxLevel) << endl;
//	    cerr << "node level = " << level.toStdString() << endl;
	
	    Graph::BaseUndirectedGraph *subGraphPtr;
	    map< unsigned int, Graph::BaseUndirectedGraph >::iterator itSubG = _subGraphMap.find( parentID );
		if( itSubG == _subGraphMap.end() ){
			Graph::BaseUndirectedGraph g;
			_subGraphMap.insert( pair< unsigned int, Graph::BaseUndirectedGraph >( parentID, g ) );
			itSubG = _subGraphMap.find( parentID );
			subGraphPtr = &itSubG->second;
		}
		else{
			subGraphPtr = &itSubG->second;
//			cerr << " num_vertices( itSubG->second ) = " << num_vertices( itSubG->second ) << endl;
//			cerr << " num_vertices( *subGraphPtr ) = " << num_vertices( *subGraphPtr ) << endl;
		}

	    // element id
        QString id = nodeElement.attribute( "id" );
//        cerr << "id = " << id.toStdString() << endl;
	    // element name
	    QString name = nodeElement.attribute( "name" );

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
	
	    Graph::BaseUndirectedGraph::vertex_descriptor vdNew = add_vertex( *subGraphPtr );
	    (*subGraphPtr)[ vdNew ].id = num_vertices( *subGraphPtr ) - 1;
	    (*subGraphPtr)[ vdNew ].namePtr = new string( name.toStdString() );
	    (*subGraphPtr)[ vdNew ].namePixelWidthPtr = new double( 0.0 );
	    (*subGraphPtr)[ vdNew ].namePixelHeightPtr = new double( 0.0 );
	    (*subGraphPtr)[ vdNew ].initID  = _subGraphNodeIndex;
	    (*subGraphPtr)[ vdNew ].level   = level;
	    (*subGraphPtr)[ vdNew ].isSelected   = false;
	    (*subGraphPtr)[ vdNew ].coordPtr = new KeiRo::Base::Coord2( x, y );

	    // read vertex style
	    XML::getStyleElement( nodeElement,
	                          (*subGraphPtr)[ vdNew ].attribute.fill(), (*subGraphPtr)[ vdNew ].attribute.stroke(),
	                          (*subGraphPtr)[ vdNew ].attribute.strokeWidth() );

#ifdef DEBUG
		cerr << " pid = " << parentID
			 << " nid = " << (*subGraphPtr)[ vdNew ].id
			 << " num_vertices( *subGraphPtr ) = " << num_vertices( *subGraphPtr ) << endl;
#endif // DEBUG
	    _subGraphNodeIndex++;
    }
	
	//
	//  GraphML::findNodesinSubGraphs --	find nodes in subGraphs
	//
	//  Input
	//	idS, idT, initS, initT, subGSPtr, subGTPtr
	//
	//  Output
	//	none
	//
	void GraphML::findNodesinSubGraphs( unsigned int idS, unsigned int idT,
	                                    unsigned int &idSinSubG, unsigned int &idTinSubG,
	                                    unsigned int &idGS, unsigned int &idGT,
	                                    Graph::BaseUndirectedGraph **subGraphSPtr,
										Graph::BaseUndirectedGraph **subGraphTPtr )
	{
		for( map< unsigned int, Graph::BaseUndirectedGraph >::iterator it = _subGraphMap.begin();
			 it != _subGraphMap.end(); it++ ){
			
			Graph::BaseUndirectedGraph *subGPtr = &it->second;
			
			BGL_FORALL_VERTICES( vd, *subGPtr, Graph::BaseUndirectedGraph ) {
				if( (*subGPtr)[vd].initID == idS ){
					idSinSubG = (*subGPtr)[vd].id;
					idGS = it->first;
					*subGraphSPtr = subGPtr;
				}
				if( (*subGPtr)[vd].initID == idT ){
					idTinSubG = (*subGPtr)[vd].id;
					idGT = it->first;
					*subGraphTPtr = subGPtr;
				}
			}
		}
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
			
		    Graph::BaseUndirectedGraph *subGraphSPtr, *subGraphTPtr;
		    unsigned int idSinSubG, idTinSubG, idGS, idGT;
			findNodesinSubGraphs( idS, idT,
			                      idSinSubG, idTinSubG,
								  idGS, idGT,
			                      &subGraphSPtr, &subGraphTPtr );
#ifdef DEBUG
		    cerr << "(source, target) = (" << idS << ", " << idT << ")"<< endl;
		    cerr << "(initIDS, initIDT) = (" << initIDS << ", " << initIDT << ")"<< endl;
#endif // DEBUG
			if( subGraphSPtr == subGraphTPtr ){

				// local edge
				Graph::BaseUndirectedGraph::vertex_descriptor vdS= vertex( idSinSubG, *subGraphSPtr );
				Graph::BaseUndirectedGraph::vertex_descriptor vdT= vertex( idTinSubG, *subGraphTPtr );
				
				bool found = false;
				Graph::BaseUndirectedGraph::edge_descriptor oldED;
				tie( oldED, found ) = edge( vdS, vdT, *subGraphSPtr );

				if( found == false ){
					
					pair< Graph::BaseUndirectedGraph::edge_descriptor, unsigned int > foreE = add_edge( vdS, vdT, *subGraphSPtr );
					Graph::BaseUndirectedGraph::edge_descriptor foreED = foreE.first;
					(*subGraphSPtr)[ foreED ].id = num_edges( *subGraphSPtr ) - 1;

					// read edge page
					XML::getEdgeDElement( edgeElement,
										  (*subGraphSPtr)[ foreED ].edge, (*subGraphSPtr)[ foreED ].edge.isClosed() );
					// read edge style
					XML::getStyleElement( edgeElement,
											  (*subGraphSPtr)[ foreED ].edge.fill(), (*subGraphSPtr)[ foreED ].edge.stroke(),
											  (*subGraphSPtr)[ foreED ].edge.strokeWidth() );
#ifdef DEBUG
					cerr << "(*subGraphSPtr)[ foreED ].edge.size() = " << (*subGraphSPtr)[ foreED ].edge.elements().size() << endl;
					cerr << "(*subGraphSPtr)[ foreED ].strokeWidth = " << (*subGraphSPtr)[ foreED ].edge.strokeWidth() << endl;
#endif // DEBUG
				}
			}
			else{
				
				// global path
				_globalPathMap.insert( pair< KeiRo::Base::Common::UIDPair,
						KeiRo::Base::Common::UIDPair >( pair< unsigned int, unsigned int >( idGS, idSinSubG ),
				                                        pair< unsigned int, unsigned int >( idGT, idTinSubG ) ) );
				KeiRo::Base::Edge2 edge;

				// read edge style
				XML::getStyleElement( edgeElement, edge.fill(),
									  edge.stroke(), edge.strokeWidth() );
				_globalPathAttributeMap.insert( pair< pair< KeiRo::Base::Common::UIDPair, KeiRo::Base::Common::UIDPair >,
				        KeiRo::Base::Edge2 >( pair< pair< unsigned int, unsigned int >, pair< unsigned int, unsigned int > >(
						pair< unsigned int, unsigned int >( idGS, idSinSubG ),
						pair< unsigned int, unsigned int >( idGT, idTinSubG ) ), edge ) );
			}
#ifdef DEBUG
		    cerr << "num_edges( *subGraphSPtr ) = " << num_edges( *subGraphSPtr ) << endl;
#endif // DEBUG
    	}
#ifdef DEBUG
		for( multimap< KeiRo::Base::Common::UIDPair, KeiRo::Base::Common::UIDPair >::iterator it = _globalPath.begin();
			 it != _globalPath.end(); it++ ){
			cerr << "(" << it->first.first << ", " << it->first.second << ")" << " -- "
				 << "(" << it->second.first << ", " << it->second.second << ")" << endl;
		}
#endif // DEBUG
    }
	
	//
	//  GraphML::computeGroupBoundary --	load function
	//
	//  Input
	//	none
	//
	//  Output
	//	none
	//
	void GraphML::computeGroupBoundary( void )
	{
		// leaf nodes
		for( map< unsigned int, Graph::BaseUndirectedGraph >::iterator it = _subGraphMap.begin();
		     it != _subGraphMap.end(); it++ ){
			
			unsigned int parentID = it->first;
			Graph::BaseUndirectedGraph *subGPtr = &it->second;
			Graph::TreeDirectedGraph::vertex_descriptor parentVD = vertex( parentID, _graphmlTree );

			double minX = INFINITY, minY = INFINITY, maxX = -INFINITY, maxY = -INFINITY;
			BGL_FORALL_VERTICES( vd, *subGPtr, Graph::BaseUndirectedGraph ) {
				
				KeiRo::Base::Coord2 &coord = *(*subGPtr)[vd].coordPtr;
				if( minX > coord.x() ) minX = coord.x();
				if( minY > coord.y() ) minY = coord.y();
				if( maxX < coord.x() ) maxX = coord.x();
				if( maxY < coord.y() ) maxY = coord.y();
			}

            		double diffX = maxX-minX;
            		double diffY = maxY-minY;
            		if( diffX == 0 ){
                		diffX += 2;
                		minX -= 1;
            		}
            		if( diffY == 0 ){
                		diffY += 2;
                		minY -= 1;
            		}

			_graphmlTree[ parentVD ].boundingBoxPtr = new KeiRo::Base::Rectangle2( minX, minY, diffX, diffY );
			//_graphmlTree[ parentVD ].boundingBoxPtr = new KeiRo::Base::Rectangle2( minX, minY, maxX-minX, maxY-minY );
			
#ifdef DEBUG
			cerr << "cid = " << parentID
 				 << " level = " << _graphmlTree[ parentVD ].level
				 << " w = " << *_graphmlTree[ parentVD ].widthPtr
				 << " h = " << *_graphmlTree[ parentVD ].heightPtr
				 << " lb = " << *_graphmlTree[ parentVD ].leftBottomCoordPtr;
#endif // DEBUG
		}
		
		// non-leaf nodes
		// cerr << "_maxLevel = " << _maxLevel << endl;
		for( int i = _maxLevel-2; i >= 0; i-- ){
			
			BGL_FORALL_VERTICES( vd, _graphmlTree, Graph::TreeDirectedGraph ) {

//				cerr << "level = " << _graphmlTree[ vd ].level << endl;
//				cerr << "i = " << i << endl;
				if( i == _graphmlTree[ vd ].level ){
					
					double minX = INFINITY, minY = INFINITY, maxX = -INFINITY, maxY = -INFINITY;
					Graph::TreeDirectedGraph::out_edge_iterator e, e_end;
					for( tie( e, e_end ) = out_edges( vd, _graphmlTree ); e != e_end; ++e ) {
						Graph::TreeDirectedGraph::edge_descriptor ed = *e;
						Graph::TreeDirectedGraph::vertex_descriptor vdS = source( ed, _graphmlTree );
						Graph::TreeDirectedGraph::vertex_descriptor vdT = target( ed, _graphmlTree );
						
						if( minX > _graphmlTree[ vdT ].boundingBoxPtr->leftBottom().x() )
							minX = _graphmlTree[ vdT ].boundingBoxPtr->leftBottom().x();
						if( minY > _graphmlTree[ vdT ].boundingBoxPtr->leftBottom().y() )
							minY = _graphmlTree[ vdT ].boundingBoxPtr->leftBottom().y();
						if( maxX < _graphmlTree[ vdT ].boundingBoxPtr->leftBottom().x() + _graphmlTree[ vdT ].boundingBoxPtr->width() )
							maxX = _graphmlTree[ vdT ].boundingBoxPtr->leftBottom().x() + _graphmlTree[ vdT ].boundingBoxPtr->width();
						if( maxY < _graphmlTree[ vdT ].boundingBoxPtr->leftBottom().y() + _graphmlTree[ vdT ].boundingBoxPtr->height() )
							maxY = _graphmlTree[ vdT ].boundingBoxPtr->leftBottom().y() + _graphmlTree[ vdT ].boundingBoxPtr->height();
					}
					
					_graphmlTree[ vd ].boundingBoxPtr = new KeiRo::Base::Rectangle2( minX, minY, maxX-minX, maxY-minY );

#ifdef DEBUG
					cerr << "cid = " << _graphmlTree[ vd ].id
					     << " level = " << _graphmlTree[ vd ].level
						 << " bbox = " << *_graphmlTree[ vd ].boundingBoxPtr
						 << " obbox = " << _graphmlTree[ vd ].boundingBoxPtr->oldWidth() << endl;
//						 << " w = " << *_graphmlTree[ vd ].widthPtr
//					     << " h = " << *_graphmlTree[ vd ].heightPtr
//					     << " lb = " << *_graphmlTree[ vd ].leftBottomCoordPtr;
#endif // DEBUG
				}
			}
		}
		
#ifdef DEBUG
		BGL_FORALL_VERTICES( vd, _graphmlTree, Graph::TreeDirectedGraph ) {
				cerr << " id = " << _graphmlTree[ vd ].id
				     << " boundingBox = " << *_graphmlTree[ vd ].boundingBoxPtr;
		}
#endif // DEBUG
	
	}
	
	//
	//  GraphML::normalize --	normalize the data
	//
	//  Input
	//	none
	//
	//  Output
	//	none
	//
	void GraphML::normalize( void )
	{
		// leaf nodes
		double minX = INFINITY, minY = INFINITY, maxX = -INFINITY, maxY = -INFINITY;
		for( map< unsigned int, Graph::BaseUndirectedGraph >::iterator it = _subGraphMap.begin();
		     it != _subGraphMap.end(); it++ ){
			
			unsigned int parentID = it->first;
			Graph::BaseUndirectedGraph *subGPtr = &it->second;
			
			// iterate edge sample points
			BGL_FORALL_EDGES( ed, *subGPtr, Graph::BaseUndirectedGraph ) {
				KeiRo::Base::Edge2 &edge = (*subGPtr)[ed].edge;
				for( unsigned int i = 0; i < edge.elements().size(); i++ ){
					KeiRo::Base::Coord2 &coord = edge.elements()[i];

					if( minX > coord.x() ) minX = coord.x();
					if( minY > coord.y() ) minY = coord.y();
					if( maxX < coord.x() ) maxX = coord.x();
					if( maxY < coord.y() ) maxY = coord.y();
				}
			}
			// iterate vertices
			BGL_FORALL_VERTICES( vd, *subGPtr, Graph::BaseUndirectedGraph ) {
				
				KeiRo::Base::Coord2 &coord = *(*subGPtr)[vd].coordPtr;

				if( minX > coord.x() ) minX = coord.x();
				if( minY > coord.y() ) minY = coord.y();
				if( maxX < coord.x() ) maxX = coord.x();
				if( maxY < coord.y() ) maxY = coord.y();
			}
		}

		// update the coordinates
		for( map< unsigned int, Graph::BaseUndirectedGraph >::iterator it = _subGraphMap.begin();
		     it != _subGraphMap.end(); it++ ){
			
			unsigned int parentID = it->first;
			Graph::BaseUndirectedGraph *subGPtr = &it->second;
			
			// iterate edge sample points
			BGL_FORALL_EDGES( ed, *subGPtr, Graph::BaseUndirectedGraph ) {
				KeiRo::Base::Edge2 &edge = (*subGPtr)[ed].edge;
				for( unsigned int i = 0; i < edge.elements().size(); i++ ){

					KeiRo::Base::Coord2 &coord = edge.elements()[i];
                    coord.fixedX() = coord.x() = ( coord.x() - minX ) / ( maxX - minX ) * KeiRo::Base::Common::getMainwidgetWidth() - 0.5 * KeiRo::Base::Common::getMainwidgetWidth();
                    coord.fixedY() = coord.y() = ( coord.y() - minY ) / ( maxY - minY ) * KeiRo::Base::Common::getMainwidgetHeight() - 0.5 * KeiRo::Base::Common::getMainwidgetHeight();
					coord.updateOldElement();

//                    cerr << "coord = " << coord;
//                    cerr << "coordF = " << coord.fixedX() << ", " << coord.fixedY() << endl;

                }
			}
			// iterate vertices
			BGL_FORALL_VERTICES( vd, *subGPtr, Graph::BaseUndirectedGraph ) {
				
				KeiRo::Base::Coord2 &coord = *(*subGPtr)[vd].coordPtr;
                coord.fixedX() = coord.x() = ( coord.x() - minX ) / ( maxX - minX ) * KeiRo::Base::Common::getMainwidgetWidth() - 0.5 * KeiRo::Base::Common::getMainwidgetWidth();
                coord.fixedY() = coord.y() = ( coord.y() - minY ) / ( maxY - minY ) * KeiRo::Base::Common::getMainwidgetHeight() - 0.5 * KeiRo::Base::Common::getMainwidgetHeight();
				coord.updateOldElement();
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
    	cerr <<"starting loading "<<endl;
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
	    _graphmlTree[ vdNew ].namePtr = new string( "root" );
	    _graphmlTree[ vdNew ].level = 0;
	    _graphmlTree[ vdNew ].initID = 0;
	    _graphmlTree[ vdNew ].parentID = 0;
	    _graphmlTree[ vdNew ].isSelected = false;
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
    		cerr << "Unrecognized tagName " << graphElement.firstChild().toElement().tagName().toStdString() << " at " << __LINE__ << " in " << __FILE__ << endl;
    	}
	
    	// load edges
	    loadEdge( graphElement );

		// nomalization
		normalize();
		
		// compute group boundary
	    computeGroupBoundary();

#ifdef DEBUG
	    cerr << "*****************************" << endl;
		cerr << "_maxLevel = " << _maxLevel << endl;
	    Graph::printGraph( _graphmlTree );
	    cerr << "*****************************" << endl;

		for( map< unsigned int, Graph::BaseUndirectedGraph >::iterator it = _subGraphMap.begin();
			 it != _subGraphMap.end(); it++ ){
			cerr << "gid = " << it->first << endl;
			Graph::printGraph( it->second );
			cerr << "*****************************" << endl;
		}
#endif // DEBUG
    }
	
} // namespace FilIO
