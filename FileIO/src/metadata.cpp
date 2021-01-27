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
		QString fileName = filePath + QString( "/metadata.xml" );
		cerr << "metadata fileName = " << fileName.toStdString() << endl;
		// uptr = unique_ptr< vector< vector< SVG > > >(new vector< vector< SVG > > );
		
		// Open your SVG-file
		QFile file( fileName );
		QDomDocument doc;
		
		// If it is not opened, or have failed to transmit the contents in QDocDocument
		if ( !file.open( QIODevice::ReadOnly ) || !doc.setContent( &file ) ) {
			// the refund list, but empty
			cerr << "something is wrong here... at " << __LINE__ << " in " << __FILE__ << endl;
			return false;
		}
		
		// get rectangles
		QDomNodeList objects = doc.elementsByTagName( "objects" );
		int maxLevel = objects.item(0).toElement().attribute( "maxlevel" ).toInt();
		QDomNodeList objectList = doc.elementsByTagName( "object" );
		
		_svgPtr.resize( maxLevel );
		
#ifdef DEBUG
		cerr << "maxlevel = " << maxLevel << endl;
		cerr << "objectList.size() = " << objectList.size() << endl;
#endif // DEBUG
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
			_svgPtr[ level ].push_back( s );
			unsigned int len = _svgPtr[ level ].size() - 1;
			
			
			QString name = file;
			name.remove( 0, 8 );
			name.truncate( name.lastIndexOf( '.' ) );
#ifdef METADATA_DEBUG
			cerr << "name = " << name.toStdString() << ", len = " << len << endl;
#endif // METADATA_DEBUG

			if( level == 0 ) {
				
				// read svg
				_svgPtr[ level ][len]->init( gridPtr, 0.0, 0.0,
				            KeiRo::Base::Common::getMainwidgetWidth(),
				            KeiRo::Base::Common::getMainwidgetHeight() );
				_svgPtr[ level ][len]->level() = level;
				_svgPtr[ level ][len]->name() = name.toStdString();
				_svgPtr[ level ][len]->readSVG( filePath + file );
				
				vector<  KeiRo::Base::Polygon2 > &polygonVec = _svgPtr[ level ][len]->polygonVec();
				// cerr << "name = " << name.toStdString() << endl;
				// cerr << "s.polygonVec().size() = " << ( *_svgPtr )[ level ][0].polygonVec().size() << endl;
			}
			else {

				double  x = 0.0, y = 0.0, w = 0.0, h = 0.0;

				// find object width and height at the previous level
				bool isFound = false;
				// string parent = "parent";
				QString objName = QString( "obj" ) + name.right(5 );
#ifdef METADATA_DEBUG
				cerr << "objName = " << objName.toStdString() << endl;
#endif // METADATA_DEBUG
				unsigned int parentPolygonID = 0;
				
				KeiRo::Base::Common::UIDPair parentFileID;
				for( unsigned int m = 0; m < _svgPtr[ level - 1 ].size(); m++ ) {
					for( unsigned int n = 0; n < _svgPtr[ level - 1 ][ m ]->polygonVec().size(); n++ ) {
#ifdef METADATA_DEBUG
						cerr << "(*_svgPtr)[level-1][m].polygonVec()[n].name() = " << (*_svgPtr)[level-1][m].polygonVec()[n].name()
								 << " ?= name.toStdString() = " << name.toStdString() << endl;
						cerr << "m = " << m << ", n = " << n << endl;
#endif // METADATA_DEBUG
						if( _svgPtr[ level - 1 ][ m ]->polygonVec()[ n ].name() == objName.toStdString() ) {

							x = _svgPtr[ level - 1 ][ m ]->polygonVec()[ n ].boxLeftTop().x();
							y = _svgPtr[ level - 1 ][ m ]->polygonVec()[ n ].boxLeftTop().y();
							w = _svgPtr[ level - 1 ][ m ]->polygonVec()[ n ].boundingBox().x();
							h = _svgPtr[ level - 1 ][ m ]->polygonVec()[ n ].boundingBox().y();
#ifdef METADATA_DEBUG
							cerr << "m = " << m << " name = " << _svgPtr[level-1][m]->polygonVec()[n].name()
									 << " objName = " << objName.toStdString() << endl;
								cerr << "x = " << x << " y = " << y
									 << " w = " << w << " h = " << h << endl;
#endif // METADATA_DEBUG
							isFound = true;
							// parent = name.toStdString();
							parentFileID.first = level - 1;
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
				cerr << "level = " << level << ", len = " << len << endl;
#endif // METADATA_DEBUG
				_svgPtr[ level ][ len ]->init( gridPtr, x + 0.5 * ( double ) w, y + 0.5 * ( double ) h,
				                             w, h );
				_svgPtr[ level ][ len ]->name() = name.toStdString();
				_svgPtr[ level ][ len ]->readSVG( filePath + file );

				for( unsigned int n = 0; n < _svgPtr[ level ][ len ]->polygonVec().size(); n++ ) {

					_svgPtr[ level ][ len ]->polygonVec()[ n ].parentFileID().first = parentFileID.first;
					_svgPtr[ level ][ len ]->polygonVec()[ n ].parentFileID().second = parentFileID.second;
					_svgPtr[ level ][ len ]->polygonVec()[ n ].parentPolygonID() = parentPolygonID;
				}
			}
			cerr << endl << endl;
		}
		
		// check
		for( unsigned int m = 0; m < _svgPtr.size(); m++ ) {
			for( unsigned int n = 0; n < _svgPtr[ m ].size(); n++ ) {
				
#ifdef METADATA_DEBUG
				cerr << "m = " << m << ", n = " << n << endl;
				cerr << "name = " << _svgPtr[m][n]->name() << " isVisible = " << _svgPtr[m][n]->isVisible() << endl;
				cerr << "size = " << _svgPtr[m][n]->polygonVec().size() << endl;
#endif // METADATA_DEBUG
			}
		}
		return true;
	}
    
} // namespace FileIO