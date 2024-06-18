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

#include "CompressionGrid.h"


    //------------------------------------------------------------------------------
    //	Private Functions
    //------------------------------------------------------------------------------

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
    void CompressionGrid::_init( Grid2 * __gridPtr,
                             vector< KeiRo::Base::Polygon2 > *__polygonVecPtr,
                             vector< KeiRo::Base::Line2 > *__polylineVecPtr )

    {
        _clear();
        _gridPtr        =  __gridPtr;
        _polygonVecPtr  = __polygonVecPtr;
        _polylineVecPtr = __polylineVecPtr;
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
    void CompressionGrid::_clear( void )
    {
        _fixedSamples.clear();
        _samples.clear();
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
    CompressionGrid::CompressionGrid( void )
    {
        //------------------------------------------------------------------------------
        // configuration file
        //------------------------------------------------------------------------------

        string configFilePath = qApp->applicationDirPath().toStdString() + "/../config/MainWindow.conf";
	    KeiRo::Base::Config conf( configFilePath );

        if ( conf.has( "min_point_distance" ) ){
            string paramMinPointDistance = conf.gets( "min_point_distance" );
            _min_point_distance = stoi( paramMinPointDistance );
        }
	
	    _fixedSamples.clear();
        _samples.clear();
	
	    _polygonVecPtr = NULL;
	    _polylineVecPtr = NULL;
	    _gridPtr = NULL;
	    
#ifdef COMPRESSION_DEBUG
        cerr << "_min_point_distance: " << _min_point_distance << endl;
#endif // COMPRESSION_DEBUG

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
	CompressionGrid::CompressionGrid( const CompressionGrid & v )
	{
		_fixedSamples   = v._fixedSamples;
		_samples        = v._samples;
		
		_polygonVecPtr  = v._polygonVecPtr;
		_polylineVecPtr = v._polylineVecPtr;
		_gridPtr        = v._gridPtr;
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
    CompressionGrid::~CompressionGrid()
    {
    }

    //------------------------------------------------------------------------------
    //	Assignment operators
    //------------------------------------------------------------------------------
    CompressionGrid & CompressionGrid::operator = ( const CompressionGrid & v )
    {
	    if ( this != &v ) {
		    _fixedSamples   = v._fixedSamples;
		    _samples        = v._samples;
		
		    _polygonVecPtr  = v._polygonVecPtr;
		    _polylineVecPtr = v._polylineVecPtr;
		    _gridPtr        = v._gridPtr;
	    }
	    return *this;
    }


    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    //
    //  Compression::createCompression --	create compression from polygons and polylines
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    bool CompressionGrid::_closeToSamples( KeiRo::Base::Coord2 &coord, unsigned int &index )
    {
		return false;
        index = 0;
        for( unsigned int i = 0; i < _samples.size(); i++ ){

            double distance = distanceBetween( coord, _samples[i] );
            if( distance < _min_point_distance ) {
                index = i;
                return true;
            }
        }

        return false;
    }

    //
    //  Compression::createCompressedSamples --	create compression from samples of polygons and polylines
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    void CompressionGrid::createCompressedSamples( void )
    {
        // sample size index
        unsigned int nV = 0;

        // add polygonal objects
        for( unsigned int i = 0; i < _polygonVecPtr->size(); i++ ){

            vector< KeiRo::Base::Coord2 > &elements = (*_polygonVecPtr)[i].elements();
            vector< unsigned int > &idElements = (*_polygonVecPtr)[i].idElements();
//            cerr << "i = " << i << ", elements.size() = " << elements.size() << endl;

            for( unsigned int j = 0; j < elements.size(); j++ ){
	
	            KeiRo::Base::Coord2 &coord = elements[j];
                unsigned int index = 0;
                if( _closeToSamples( coord, index ) == true ){
                    // cerr << "index = " << index << endl;
                    idElements.push_back( index );
                }
                else{
                	coord.updateOldElement();
                    _fixedSamples.push_back( coord );
                    _samples.push_back( coord );
                    idElements.push_back( nV );
                    nV++;
                }
            }
        }
        
#ifdef COMPRESSION_DEBUG
        for( unsigned int i = 0; i < _polygonVecPtr->size(); i++ ){

        	vector< KeiRo::Base::Coord2 > &elements = (*_polygonVecPtr)[i].elements();
        	vector< unsigned int > &idElements = (*_polygonVecPtr)[i].idElements();
        	cerr << " i = " << i << ", elements.size() = " << elements.size() << endl;
        	cerr << " i = " << i << ", idElements.size() = " << idElements.size() << endl;
        }

        for( unsigned int i = 0; i < _samples.size(); i++ ){
            cerr << "ref = " << &_samples[i] << ", i = " << i << " , " << _samples[i];
        }
        cerr << endl;
        for( unsigned int i = 0; i < _polygonVecPtr->size(); i++ ){

            cerr << "i = " << i << endl;
            vector< KeiRo::Base::Coord2 > &elements = (*_polygonVecPtr)[i].elements();
            vector< unsigned int > &idElements = (*_polygonVecPtr)[i].idElements();

            for( unsigned int j = 0; j < elements.size(); j++ ){
                // pointerElements[j] = &elements[j];
                cerr << "j = " << j << ", " << idElements[j] << ", c = " << elements[j];
            }
            cerr << endl;
        }
#endif // COMPRESSION_DEBUG

        // add line objects
        for( unsigned int i = 0; i < _polylineVecPtr->size(); i++ ){

            vector< KeiRo::Base::Coord2 > &elements = (*_polylineVecPtr)[i].elements();
            vector< unsigned int > &idElements = (*_polylineVecPtr)[i].idElements();
            for( unsigned int j = 0; j < elements.size(); j++ ){
	
	            KeiRo::Base::Coord2 &coord = elements[j];
                unsigned int index = 0;
                if( _closeToSamples( coord, index ) == true ){
                    idElements.push_back( index );
                }
                else{
	                coord.updateOldElement();
	                _fixedSamples.push_back( coord );
                    _samples.push_back( coord );
                    idElements.push_back( nV );
                    nV++;
                }
            }
        }

#ifdef COMPRESSION_DEBUG
        cerr << "nV = " << nV << endl;
        cerr << "nPolygons = " << _polygonVecPtr->size() << " _nPolylines = " << _polylineVecPtr->size() << endl;
        cerr << "_samples.size() = " << _samples.size() << " _fixedSamples.size() = " << _fixedSamples.size() << endl;
#endif // COMPRESSION_DEBUG
    }

    //
    //  Compression::createCompressedJoints --	create compression from joints of polygons and polylines
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    void CompressionGrid::createCompressedJoints( void )
    {
        // sample size index
        unsigned int nV = 0;

        // add polygonal x line intersection
        for( unsigned int i = 0; i < _polygonVecPtr->size(); i++ ){

            // get polygon elements
            vector< KeiRo::Base::Coord2 > newPolygonElements;
            vector< unsigned int > newPolygonIDElements;
            vector< KeiRo::Base::Coord2 > &polygonElements = (*_polygonVecPtr)[i].elements();
            newPolygonElements.push_back( polygonElements[0] );

            for( unsigned int j = 0; j < polygonElements.size(); j++ ){
	
	            KeiRo::Base::Coord2 &coordA = polygonElements[j];
	            KeiRo::Base::Coord2 &coordB = polygonElements[ (j+1)%polygonElements.size() ];
	            KeiRo::Base::Coord2 unitBA = (coordA-coordB)/(coordA-coordB).norm();
	            KeiRo::Base::Coord2 a = coordA + _min_point_distance * unitBA;
	            KeiRo::Base::Coord2 b = coordB - _min_point_distance * unitBA;

                // get line elements
                for( unsigned int m = 0; m < _polylineVecPtr->size(); m++ ){

                    map< double, KeiRo::Base::Coord2 > intersectionMap;
                    vector< KeiRo::Base::Coord2 > &lineElements = (*_polylineVecPtr)[m].elements();
                    //vector< unsigned int > &lineIDElements = (*_polylineVecPtr)[m].idElements();
                    for( unsigned int n = 0; n < lineElements.size()-1; n++ ){
	
	                    KeiRo::Base::Coord2 &coordC = lineElements[ n ];
	                    KeiRo::Base::Coord2 &coordD = lineElements[ n+1 ];
	                    KeiRo::Base::Coord2 unitDC = (coordC-coordD)/(coordC-coordD).norm();
	
	                    KeiRo::Base::Coord2 c = coordC + _min_point_distance * unitDC;
	                    KeiRo::Base::Coord2 d = coordD - _min_point_distance * unitDC;
	                    KeiRo::Base::Coord2 intersection;
                        if( isIntersected( a, b, c, d, intersection ) == true ){

                            // add intermediate sample points
                            double distance = ( intersection-coordA ).norm();

                            if( !( ( distance < _min_point_distance ) ||
                                   ( ( intersection-coordB ).norm() < _min_point_distance ) ) ) {
                                // cerr << "intersection = " << intersection;
                                intersectionMap.insert( pair< double, KeiRo::Base::Coord2 >( distance, intersection ) );
                            }

#ifdef COMPRESSION_DEBUG
                            cerr << "isIntersected = " << true << endl;
                            cerr << setprecision(50) << " coordC = " << coordC;
                            cerr << setprecision(50) << " coordD = " << coordD;
                            cerr << setprecision(50) << "intersection = " << intersection;
                            if( distanceBetween( coordC, intersection ) < 1e-5 ){
                                cerr << "coordC == intersection" << endl;
                            }
                            if( distanceBetween( coordD, intersection ) < 1e-5 ){
                                cerr << "coordD == intersection" << endl;
                            }
                            cerr << endl;
#endif // COMPRESSION_DEBUG
                        }
                    }

                    // add intersected nodes
                    // cerr << "intersectionMap.size() = " << intersectionMap.size() << endl;
                    if( intersectionMap.size() > 0 ){

                        map< double, KeiRo::Base::Coord2 >::iterator it = intersectionMap.begin();
                        newPolygonElements.push_back( it->second );
                        map< double, KeiRo::Base::Coord2 >::iterator itPrev = it;
                        it++;
                        for( ; it != intersectionMap.end(); it++ ){

                            if( ( itPrev->second - it->second ).norm() > _min_point_distance ){
                                newPolygonElements.push_back( it->second );
                            }
                            itPrev = it;
                        }
                    }

                }

                if( (j+1)%polygonElements.size() != 0 ){
                    newPolygonElements.push_back( polygonElements[(j+1)%polygonElements.size()] );
                }
            }

#ifdef COMPRESSION_DEBUG
            cerr << "ori = " << polygonElements.size() << endl;
            for( unsigned int j = 0; j < polygonElements.size(); j++ ){
                cerr << "j = " << j << ", " << polygonElements[j];
            }
            cerr << "new = " << newPolygonElements.size() << endl;
            for( unsigned int j = 0; j < newPolygonElements.size(); j++ ){
                cerr << "j = " << j << ", " << newPolygonElements[j];
            }
            cerr << endl;
#endif // COMPRESSION_DEBUG

            (*_polygonVecPtr)[i].elements() = newPolygonElements;
            (*_polygonVecPtr)[i].fixedElements() = newPolygonElements;
        }

    }

    //
    //  Compression::createCompressedGridJoints --	create compression from joints of polygons and grids
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    void CompressionGrid::createCompressedGridJoints( void )
    {
        Graph::GridGraph & gridG = _gridPtr->gridG();
//        printGraph( gridG );

        for( unsigned int i = 0; i < _polygonVecPtr->size(); i++ ){

            // get polygon elements
            vector< KeiRo::Base::Coord2 > newPolygonElements;
            vector< unsigned int > newPolygonIDElements;
            vector< KeiRo::Base::Coord2 > &polygonElements = (*_polygonVecPtr)[i].elements();
            newPolygonElements.push_back( polygonElements[0] );
            for( unsigned int j = 0; j < polygonElements.size(); j++ ) {
	
	            KeiRo::Base::Coord2 &coordA = polygonElements[j];
	            KeiRo::Base::Coord2 &coordB = polygonElements[(j + 1) % polygonElements.size()];
	            KeiRo::Base::Coord2 unitBA = (coordA - coordB) / (coordA - coordB).norm();
	            KeiRo::Base::Coord2 a = coordA + _min_point_distance * unitBA;
	            KeiRo::Base::Coord2 b = coordB - _min_point_distance * unitBA;

                // draw grid graph edges
                map< double, KeiRo::Base::Coord2 > intersectionMap;
                BGL_FORALL_EDGES( ed, gridG, Graph::GridGraph ) {

                    Graph::GridGraph::vertex_descriptor vdS = source( ed, gridG );
                    Graph::GridGraph::vertex_descriptor vdT = target( ed, gridG );
                    KeiRo::Base::Coord2 &coordC = *gridG[ vdS ].coordPtr;
                    KeiRo::Base::Coord2 &coordD = *gridG[ vdT ].coordPtr;
                    KeiRo::Base::Coord2 unitDC = (coordC-coordD)/(coordC-coordD).norm();

                    KeiRo::Base::Coord2 c = coordC + _min_point_distance * unitDC;
                    KeiRo::Base::Coord2 d = coordD - _min_point_distance * unitDC;
                    KeiRo::Base::Coord2 intersection;
                    if( isIntersected( a, b, c, d, intersection ) == true ){

                        // add intermediate sample points
                        double distance = ( intersection-coordA ).norm();

                        if( !( ( distance < _min_point_distance ) ||
                            ( ( intersection-coordB ).norm() < _min_point_distance ) ) ) {
                            intersectionMap.insert( pair< double, KeiRo::Base::Coord2 >( distance, intersection ) );
                        }
#ifdef COMPRESSION_DEBUG
                        else{
                            cerr << "skip... " << endl;
                        }
                        cerr << "eid = " << gridG[ed].id << endl;
                        cerr << "distance to A = " << distance << endl;
                        cerr << "distance to B = " << ( intersection-coordB ).norm() << endl;

                        cerr << "isIntersected = " << true << endl;
                        cerr << setprecision(50) << " coordC = " << coordC;
                        cerr << setprecision(50) << " coordD = " << coordD;
                        cerr << setprecision(50) << "intersection = " << intersection;
                        if( distanceBetween( coordC, intersection ) < 1e-5 ){
                            cerr << "coordC == intersection" << endl;
                        }
                        if( distanceBetween( coordD, intersection ) < 1e-5 ){
                            cerr << "coordD == intersection" << endl;
                        }
                        cerr << endl;
#endif // COMPRESSION_DEBUG
                    }
                }

                // add intersected nodes
                if( intersectionMap.size() > 0 ){
                    map< double, KeiRo::Base::Coord2 >::iterator it = intersectionMap.begin();
                    newPolygonElements.push_back( it->second );
                    map< double, KeiRo::Base::Coord2 >::iterator itPrev = it;
                    it++;
                    for( ; it != intersectionMap.end(); it++ ){

                        if( ( itPrev->second - it->second ).norm() > _min_point_distance ){
                            newPolygonElements.push_back( it->second );
                        }
                        itPrev = it;
                    }
                }

#ifdef COMPRESSION_DEBUG
                cerr << "list = " << intersectionMap.size() << endl;
                cerr << "A: " << coordA;
                map< double, KeiRo::Base::Coord2 >::iterator it = intersectionMap.begin();
                cerr << it->second;
                newPolygonElements.push_back( it->second );
                map< double, KeiRo::Base::Coord2 >::iterator itPrev = it;
                it++;
                for( ; it != intersectionMap.end(); it++ ){
                    if( ( itPrev->second - it->second ).norm() > _min_point_distance ){
                        cerr << "( itPrev->second - it->second ).norm() = " << ( itPrev->second - it->second ).norm()
                             << ", " << it->second;
                    }
                    itPrev = it;
                }
                cerr << "B: " << coordB;
                cerr << endl;
#endif // COMPRESSION_DEBUG

                if( (j+1)%polygonElements.size() != 0 ){
                    newPolygonElements.push_back( polygonElements[(j+1)%polygonElements.size()] );
                }
            }

            (*_polygonVecPtr)[i].elements() = newPolygonElements;
            (*_polygonVecPtr)[i].fixedElements() = newPolygonElements;
        }
    }

    //
    //  Compression::createCompression --	create compression from polygons and polylines
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    void CompressionGrid::createCompression( bool isOn )
    {
		if( isOn ){
	        createCompressedGridJoints();
	        createCompressedJoints();
		}
		else{
			createCompressedSamples();
		}
    }

    //------------------------------------------------------------------------------
    //	Friend functions
    //------------------------------------------------------------------------------


    //------------------------------------------------------------------------------
    //	I/O functions
    //------------------------------------------------------------------------------




