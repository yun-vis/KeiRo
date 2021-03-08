//******************************************************************************
// svg.cpp
//	: program file svg
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sat Mar 7 15:02:45 2020
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include "metadata.h"
//#define _USE_MATH_DEFINES
//#include <math.h>

namespace FileIO {
	
	//------------------------------------------------------------------------------
    //	Private Static Variables
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Private Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Public Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  MetaData::MetaData --	constructor
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    MetaData::MetaData( void )
    {
	    // _svgPtr = new vector< vector< SVG > >;
    }

    //
    //  MetaData::MetaData --	copy constructor
    //
    //  Input
    //	none
    //
    //  Output
    //	none
    //
    MetaData::MetaData( const MetaData & v )
    {
    }
	
	
	//------------------------------------------------------------------------------
	//	Special functions
	//------------------------------------------------------------------------------
	void MetaData::_init( void )
	{
	}
	
	
	//
	//  MetaData::readMetaData --	read MetaData file
	//
	//  Inputs
	//	string filename
	//
	//  Outputs
	//	bool
	//
	bool MetaData::readMetaData( const QString filePath, const QString folderName, Grid2 *gridPtr )
	{
    	// initialization
		QString fileName = filePath + QString( "/metadata.xml" );
		cerr << "metadata fileName = " << fileName.toStdString() << endl;
		_svgPtrVec.clear();
		
		// Open your SVG-file
		QFile file( fileName );
		QDomDocument doc;
		unsigned int svgIndex = 0;
		
		// If it is not opened, or have failed to transmit the contents in QDocDocument
		if ( !file.open( QIODevice::ReadOnly ) || !doc.setContent( &file ) ) {
			// the refund list, but empty
			cerr << "something is wrong here... at " << __LINE__ << " in " << __FILE__ << endl;
			return false;
		}
		
		// get rectangles
		QDomNodeList objects = doc.elementsByTagName( "objects" );
		_maxLevel = objects.item(0).toElement().attribute( "maxlevel" ).toInt();
		QDomNodeList objectList = doc.elementsByTagName( "object" );
		
		// _svgPtr.resize( _maxLevel );
		
#ifdef METADATA_DEBUG
		cerr << "_maxlevel = " << _maxLevel << endl;
		cerr << "objectList.size() = " << objectList.size() << endl;
#endif // METADATA_DEBUG

		for( unsigned int i = 0; i < objectList.size(); i++ ) {

			// Select from the node list
			QDomNode gNode = objectList.item( i );
			// QDomElement rectangle = gNode.firstChildElement("rect" );
			QDomElement gElement = gNode.toElement();
			unsigned int id = gElement.attribute( "id" ).toInt();
			unsigned int level = gElement.attribute( "level" ).toInt();
			QString file = gElement.attribute( "file" );

#ifdef METADATA_DEBUG
			cerr << "i = " << i << ", id = " << id
				 << ", level = " << level
				 << ", file = " << file.toStdString()
				 << ", filename.size() = " << file.toStdString().size() << endl;
#endif // METADATA_DEBUG

			SVG *s = new SVG;
			s->id() = svgIndex;
			_svgPtrVec.push_back( s );
			// unsigned int len = _svgPtr[ level ].size() - 1;

			QString name = file;
			name.remove( 0, 8 );
			name.truncate( name.lastIndexOf( '.' ) );
#ifdef METADATA_DEBUG
			cerr << "name = " << name.toStdString() << endl;
#endif // METADATA_DEBUG
			
			double x = 0.0, y = 0.0, w = 0.0, h = 0.0;
			Graph::TreeDirectedGraph::vertex_descriptor vd = add_vertex( _svgTree );
			if( svgIndex == 0 ){

				_svgTreeRoot = vd;
				
				w = KeiRo::Base::Common::getMainwidgetWidth();
				h = KeiRo::Base::Common::getMainwidgetHeight();
				
				// read svg
				_svgPtrVec[ svgIndex ]->init( gridPtr, 0.0, 0.0, w, h );
				_svgPtrVec[ svgIndex ]->level() = level;
				_svgPtrVec[ svgIndex ]->name() = name.toStdString();
				_svgPtrVec[ svgIndex ]->readSVG( filePath + file );
				
				// set svgTree
				_svgTree[ vd ].id           = 0;
				_svgTree[ vd ].attributeID  = 0;
				_svgTree[ vd ].level        = level;
				_svgTree[ vd ].parentID     = 0;
			}
			else {
				
				// find object width and height at the previous level
				bool isFound = false;
				QString objName = QString( "obj" ) + name.right( 5 );
#ifdef METADATA_DEBUG
				cerr << "objName = " << objName.toStdString() << endl;
#endif // METADATA_DEBUG
				unsigned int parentPolygonID = 0;
				
				
				KeiRo::Base::Common::UIDPair parentFileID;
				for( unsigned int m = 0; m < _svgPtrVec.size(); m++ ) {
					for( unsigned int n = 0; n < _svgPtrVec[ m ]->polygonVec().size(); n++ ) {
#ifdef METADATA_DEBUG
						cerr << "_svgPtr[" << m << "]->polygonVec()[" << n << "].name() = " << _svgPtrVec[ m
						]->polygonVec()[ n ].name()
						     << " ?= objName.toStdString() = " << objName.toStdString() << endl;
						// cerr << "m = " << m << ", n = " << n << endl;
#endif // METADATA_DEBUG
						if( _svgPtrVec[ m ]->polygonVec()[ n ].name() == objName.toStdString() ) {
							
							x = _svgPtrVec[ m ]->polygonVec()[ n ].boundingBox().leftBottom().x();
							y = _svgPtrVec[ m ]->polygonVec()[ n ].boundingBox().leftBottom().y();
							w = _svgPtrVec[ m ]->polygonVec()[ n ].boundingBox().width();
							h = _svgPtrVec[ m ]->polygonVec()[ n ].boundingBox().height();
#ifdef METADATA_DEBUG
							cerr << "m = " << m << " name = " << _svgPtr[m]->polygonVec()[n].name()
								 << " objName = " << objName.toStdString() << endl;
							cerr << "x = " << x << " y = " << y
								 << " w = " << w << " h = " << h << endl;
#endif // METADATA_DEBUG
							isFound = true;
							parentFileID.first = level-1;
							parentFileID.second = m;
							parentPolygonID = n;
#ifdef METADATA_DEBUG
							cerr << "obj = " << objName.toStdString() << ", level-1 = " << parentFileID.first << ", m = " << m
									 << ", n = " << n << endl;
#endif // METADATA_DEBUG
							break;
						}
					}
				}
				
				if( isFound == false ) {
					cerr << "cannot find the corresponding files at " << __LINE__ << " in " << __FILE__ << endl;
					cerr << "name = " << name.toStdString() << endl;
					assert( isFound );
				}

#ifdef METADATA_DEBUG
				cerr << "level = " << level << endl;
				cerr << "parentFileID.first = " << parentFileID.first << endl;
				cerr << "parentFileID.second = " << parentFileID.second << endl;
				cerr << "parentPolygonID  = " << parentPolygonID << endl;
#endif // METADATA_DEBUG
				_svgPtrVec[ svgIndex ]->init( gridPtr, x + 0.5 * w, y + 0.5 * h, w, h );
				_svgPtrVec[ svgIndex ]->level() = level;
				_svgPtrVec[ svgIndex ]->name() = name.toStdString();
				_svgPtrVec[ svgIndex ]->readSVG( filePath + file );
				
				for( unsigned int n = 0; n < _svgPtrVec[ svgIndex ]->polygonVec().size(); n++ ) {
					
					_svgPtrVec[ svgIndex ]->polygonVec()[ n ].parentFileID().first = parentFileID.first;
					_svgPtrVec[ svgIndex ]->polygonVec()[ n ].parentFileID().second = parentFileID.second;
					_svgPtrVec[ svgIndex ]->polygonVec()[ n ].parentPolygonID() = parentPolygonID;
				}
				
				// set svgTree
				KeiRo::Base::Polygon2 &p = _svgPtrVec[ parentFileID.second ]->polygonVec()[parentPolygonID];
				_svgTree[ vd ].id           = s->id();
				_svgTree[ vd ].attributeID  = s->id();
				_svgTree[ vd ].level        = level;
				_svgTree[ vd ].leftBottomCoordPtr     = &p.boundingBox().leftBottom();
				_svgTree[ vd ].widthPtr     = &p.boundingBox().width();
				_svgTree[ vd ].heightPtr    = &p.boundingBox().height();
				_svgTree[ vd ].meanCoord    = p.center();

#ifdef METADATA_DEBUG
				cerr << "parentFileID.second = " << parentFileID.second << endl;
				cerr << "parentPolygonID = " << parentPolygonID << endl;
				cerr << "p = " << p << endl;
				cerr << "_svgTree[ vd ].widthPtr = " << *_svgTree[ vd ].widthPtr << endl;
				cerr << "_svgTree[ vd ].heightPtr = " << *_svgTree[ vd ].heightPtr << endl;
#endif // METADATA_DEBUG
				
				// add the child vd to the parent vertex
				Graph::TreeDirectedGraph::vertex_descriptor parentVD= vertex( parentFileID.second, _svgTree );
				_svgTree[ parentVD ].childMap.insert( pair< unsigned int, unsigned int >( parentPolygonID, s->id() ) );
				_svgTree[ vd ].parentID = _svgTree[ parentVD ].id;
				
				// add a directed edge from parent vertex to the child vertex
				pair< Graph::TreeDirectedGraph::edge_descriptor, unsigned int > foreE = add_edge( parentVD, vd, _svgTree );
				Graph::TreeDirectedGraph::edge_descriptor foreED = foreE.first;
				_svgTree[ foreED ].id = num_edges( _svgTree ) - 1;
			}
			svgIndex++;
		}
		
		// check
#ifdef METADATA_DEBUG
		for( unsigned int m = 0; m < _svgPtr.size(); m++ ) {
			for( unsigned int n = 0; n < _svgPtr[ m ].size(); n++ ) {
				
				cerr << "m = " << m << ", n = " << n << endl;
				cerr << "name = " << _svgPtr[m][n]->name() << " isVisible = " << _svgPtr[m][n]->isVisible() << endl;
				cerr << "size = " << _svgPtr[m][n]->polygonVec().size() << endl;
			}
		}
		printGraph( _svgTree );
#endif // METADATA_DEBUG
		
		return true;
	}
} // namespace FileIO