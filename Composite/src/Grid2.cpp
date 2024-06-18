//******************************************************************************
// Grid2.cpp
//	: program file for 2D grid coordinates
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Mon Mar 14 02:16:23 2011
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cmath>

using namespace std;

#include "Grid2.h"

    //------------------------------------------------------------------------------
    //	Private Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------
    //
    //  Grid2::_init --	initialize Grid2
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    void Grid2::_init( const double *widthPtr, const double *heightPtr  )
    {
	    _widthPtr = widthPtr;
	    _heightPtr = heightPtr;

        _quadSize = MIN2( KeiRo::Base::Common::getMainwidgetWidth() / (2.0*_minRange),
						  KeiRo::Base::Common::getMainwidgetHeight() / (2.0*_minRange) );
        _range[ 0 ] = ceil( KeiRo::Base::Common::getMainwidgetWidth() / ( 2.0*_quadSize ) );
        _range[ 1 ] = ceil( KeiRo::Base::Common::getMainwidgetHeight() / ( 2.0*_quadSize ) );

#ifdef GRID_DEBUG
        cerr << "quadSize = "  << _quadSize << endl;
        cerr << "xrange = "  << _range[0] << endl;
        cerr << "yrange = "  << _range[1] << endl;
#endif // GRID_DEBUG

    }

    //
    //  Grid2::_clear --	clear Grid2
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    void Grid2::_clear( void )
    {
        _quadFourCorners.clear();
    }



    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------
    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  Grid2::Grid2 --	constructor
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    Grid2::Grid2( void )
    {
        // initialization
        _range.resize(2);

        //------------------------------------------------------------------------------
        // configuration file
        //------------------------------------------------------------------------------
        string configFilePath = qApp->applicationDirPath().toStdString() + "/../config/MainWindow.conf";
        KeiRo::Base::Config conf( configFilePath );

        if ( conf.has( "min_range" ) ){
            string paramMinRange = conf.gets( "min_range" );
            _minRange = stoi( paramMinRange );
        }

#ifdef GRID_DEBUG
        cerr << "minRange = " << _minRange << endl;
#endif // GRID_DEBUG
    }

    //
    //  Grid2::createDefaultGrid --	create a default grid
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    void Grid2::createDefaultGrid( void )
    {

        // initialize grid matrix
        _gridIDMatrix.resize( 2*_range[ 0 ]+1 );
        _gridCoord2Matrix.resize( 2*_range[ 0 ]+1 );
        for( unsigned int i = 0; i < _gridIDMatrix.size(); i++ ){

            _gridIDMatrix[ i ].resize( 2*_range[ 1 ]+1 );
            _gridCoord2Matrix[ i ].resize( 2*_range[ 1 ]+1 );

            for( unsigned int j = 0; j < _gridIDMatrix[ i ].size(); j++ ){
                _gridIDMatrix[ i ][ j ].first = -1.0 * (int)_range[ 0 ] + (int)i;
                _gridIDMatrix[ i ][ j ].second = -1.0 * (int)_range[ 1 ] + (int)j;
                _gridCoord2Matrix[ i ][ j ].x() = _gridIDMatrix[ i ][ j ].first * _quadSize;
                _gridCoord2Matrix[ i ][ j ].y() = _gridIDMatrix[ i ][ j ].second * _quadSize;
            }
        }

        // build grid graph
        unsigned int nVertices = 0, nEdges = 0;

        _grid[ graph_bundle ].centerPtr        = new KeiRo::Base::Coord2( 0.0, 0.0 );
        _grid[ graph_bundle ].widthPtr         = & KeiRo::Base::Common::getMainwidgetWidth();
        _grid[ graph_bundle ].heightPtr        = & KeiRo::Base::Common::getMainwidgetHeight();

        // add grid vertices
        unsigned int index = 0;
        for( unsigned int i = 0; i < _gridIDMatrix.size(); i++ ){
            for( unsigned int j = 0; j < _gridIDMatrix[ i ].size(); j++ ){

                index = i*_gridIDMatrix[ i ].size() + j;
                // cerr << "index = " << index << " id = " << id << endl;

                Graph::GridGraph::vertex_descriptor gridVD  = add_vertex( _grid );

                // base_graph
                _grid[ gridVD ].id                  = nVertices;
                _grid[ gridVD ].initID              = nVertices;
                _grid[ gridVD ].groupID             = 0;
                _grid[ gridVD ].componentID         = 0;

                _grid[ gridVD ].namePtr             = new string( "" );
                _grid[ gridVD ].namePixelWidthPtr   = new double( 0.0 );
                _grid[ gridVD ].namePixelHeightPtr  = new double( 0.0 );

                _grid[ gridVD ].weight              = 1.0;

                _grid[ gridVD ].coordPtr            = &_gridCoord2Matrix[ i ][ j ];
                _grid[ gridVD ].widthPtr            = new double( 10.0 );
                _grid[ gridVD ].heightPtr           = new double( 10.0 );
                _grid[ gridVD ].areaPtr             = new double( *_grid[ gridVD ].widthPtr * *_grid[ gridVD ].heightPtr );

                _grid[ gridVD ].color               = 0;
                _grid[ gridVD ].flag                = false;

                // grid_graph
                _grid[ gridVD ].gridVType           = Graph::GRID_VERTEX_DEFAULT;
                _grid[ gridVD ].geoPtr              = new KeiRo::Base::Coord2( _gridCoord2Matrix[ i ][ j ].x(),
                                                                  _gridCoord2Matrix[ i ][ j ].y() );
                _grid[ gridVD ].smoothPtr           = new KeiRo::Base::Coord2( _gridCoord2Matrix[ i ][ j ].x(),
                                                                  _gridCoord2Matrix[ i ][ j ].y() );

                nVertices++;
            }
        }
        assert( index == nVertices-1 );

        // add grid vertical edges
        for( unsigned int i = 0; i < _gridIDMatrix.size(); i++ ){
            for( unsigned int j = 1; j < _gridIDMatrix[ i ].size(); j++ ){

                unsigned int idS = i*_gridIDMatrix[ i ].size() + j-1;
                unsigned int idT = i*_gridIDMatrix[ i ].size() + j;

                Graph::GridGraph::vertex_descriptor vdS  = vertex( idS, _grid );
                Graph::GridGraph::vertex_descriptor vdT  = vertex( idT, _grid );

                pair< Graph::GridGraph::edge_descriptor, unsigned int > foreE = add_edge( vdS, vdT, _grid );
                Graph::GridGraph::edge_descriptor foreED = foreE.first;

                // base_graph
                _grid[ foreED ].id              = nEdges;

                _grid[ foreED ].angle           = 0.0;
                _grid[ foreED ].weight          = 1.0;
                _grid[ foreED ].visit           = false;
                _grid[ foreED ].visitedTimes    = 0;

                _grid[ foreED ].isFore          = false;
                _grid[ foreED ].isBack          = false;

                // grid_graph
                // calculate geographical angle
                KeiRo::Base::Coord2 coordO;
                KeiRo::Base::Coord2 coordD;
                if( _grid[ vdS ].id < _grid[ vdT ].id ){
                    coordO = *_grid[ vdS ].coordPtr;
                    coordD = *_grid[ vdT ].coordPtr;
                }
                else{
                    coordO = *_grid[ vdT ].coordPtr;
                    coordD = *_grid[ vdS ].coordPtr;
                }
                double diffX = coordD.x() - coordO.x();
                double diffY = coordD.y() - coordO.y();
                double angle = atan2( diffY, diffX );

                _grid[ foreED ].geoAngle        = angle;

                nEdges++;
            }
        }

        // add grid horizontal edges
        for( unsigned int j = 0; j < _gridIDMatrix[ 0 ].size(); j++ ){
            for( unsigned int i = 1; i < _gridIDMatrix.size(); i++ ){

                unsigned int idS = (i-1)*_gridIDMatrix[ i-1 ].size() + j;
                unsigned int idT = i*_gridIDMatrix[ i ].size() + j;

                Graph::GridGraph::vertex_descriptor vdS  = vertex( idS, _grid );
                Graph::GridGraph::vertex_descriptor vdT  = vertex( idT, _grid );

                pair< Graph::GridGraph::edge_descriptor, unsigned int > foreE = add_edge( vdS, vdT, _grid );
                Graph::GridGraph::edge_descriptor foreED = foreE.first;

                // base_graph
                _grid[ foreED ].id              = nEdges;

                _grid[ foreED ].angle           = 0.0;
                _grid[ foreED ].weight          = 1.0;
                _grid[ foreED ].visit           = false;
                _grid[ foreED ].visitedTimes    = 0;

                _grid[ foreED ].isFore          = false;
                _grid[ foreED ].isBack          = false;

                // grid_graph
                // calculate geographical angle
                KeiRo::Base::Coord2 coordO;
                KeiRo::Base::Coord2 coordD;
                if( _grid[ vdS ].id < _grid[ vdT ].id ){
                    coordO = *_grid[ vdS ].coordPtr;
                    coordD = *_grid[ vdT ].coordPtr;
                }
                else{
                    coordO = *_grid[ vdT ].coordPtr;
                    coordD = *_grid[ vdS ].coordPtr;
                }
                double diffX = coordD.x() - coordO.x();
                double diffY = coordD.y() - coordO.y();
                double angle = atan2( diffY, diffX );
                _grid[ foreED ].geoAngle        = angle;

                nEdges++;
            }
        }

        for( unsigned int i = 0; i < _gridIDMatrix.size()-1; i++ ){
            for( unsigned int j = 0; j < _gridIDMatrix[ i ].size()-1; j++ ){

                vector< Graph::GridGraph::vertex_descriptor > vdVec;
                getQuadVD( i, j, vdVec );

                _quadFourCorners.push_back( vdVec );
            }
        }

        _element[ 0 ] = _element[ 1 ] = 0;

        // cerr << "_gridMatrix.size() = " << _gridMatrix.size() << endl;

    }

    //
    //  Grid2::resetGridPosition --	reset grid node position
    //
    //  Inputs
    //	none
    //
    //  Outputs
    //	none
    //
    void Grid2::resetGridPosition( void )
    {
        // reset grid node position
        BGL_FORALL_VERTICES( vd, _grid, Graph::GridGraph ) {

            _grid[vd].coordPtr->x() = _grid[vd].smoothPtr->x() = _grid[vd].geoPtr->x();
            _grid[vd].coordPtr->y() = _grid[vd].smoothPtr->y() = _grid[vd].geoPtr->y();

        }
    }


    //
    //  Grid2::Grid2 --	parameterized constructor
    //
    //  Input
    //	 x, y :	2D coordinates
    //
    //  Output
    //	none
    //
    Grid2::Grid2( const int x, const int y )
    {
        _element[ 0 ]	= x;
        _element[ 1 ]	= y;
    }

    //
    //  Grid2::Grid2 --	copy constructor
    //
    //  Input
    //	v	: 2D coordinates
    //
    //  Output
    //	none
    //
    Grid2::Grid2( const Grid2 & v )
    {
        _element[ 0 ]	= v._element[ 0 ];
        _element[ 1 ]	= v._element[ 1 ];
     }


    //------------------------------------------------------------------------------
    //	Assignment operators
    //------------------------------------------------------------------------------
    //
    //  Grid2::operator = --	assignment
    //
    //  Inputs
    //	v	: 2D coordinates
    //
    //  Outputs
    //	reference to this object
    //
    Grid2 & Grid2::operator = ( const Grid2 & v )
    {
        if ( this != &v ) {
            _element[ 0 ]	= v._element[ 0 ];
            _element[ 1 ]	= v._element[ 1 ];
        }
        return *this;
    }


    //
    //  Grid2::operator += --	addition + assignment
    //
    //  Inputs
    //	v	: 2D coordinates
    //
    //  Outputs
    //	reference to this object
    //
    Grid2 & Grid2::operator += ( const Grid2 & v )
    {
        _element[ 0 ]	+= v._element[ 0 ];
        _element[ 1 ]	+= v._element[ 1 ];
        return *this;
    }


    //
    //  Grid2::operator -= --	subtraction + assignment
    //
    //  Inputs
    //	v	: 2D coordinates
    //
    //  Outputs
    //	reference to this object
    //
    Grid2 & Grid2::operator -= ( const Grid2 & v )
    {
        _element[ 0 ]	-= v._element[ 0 ];
        _element[ 1 ]	-= v._element[ 1 ];
        return *this;
    }


    //
    //  Grid2::operator -= --	scalar product + assignment
    //
    //  Inputs
    //	d	: scalar value
    //
    //  Outputs
    //	reference to this object
    //
    Grid2 & Grid2::operator *= ( const int d )
    {
        _element[ 0 ]	*= d;
        _element[ 1 ]	*= d;
        return *this;
    }


    //
    //  Grid2::operator [] --	reference to an element
    //
    //  Inputs
    //	i	: index of the coordinate
    //
    //  Outputs
    //	the corresponding coordinate
    //
    const int & Grid2::operator [] ( int i ) const
    {
    #ifdef GRID2_INDEX_CHECK
        const char theName[] = "Grid2::operator [] : ";
        if ( ( i < 0 ) || ( i > 1 ) ) {
        cerr << theName << " index = " << i << endl;
        assert( ( 0 <= i ) && ( i <= 1 ) );
        }
    #endif	// GRID2_INDEX_CHECK
        return _element[ i ];
    }


    //
    //  Grid2::operator [] --	reference to an element
    //
    //  Inputs
    //	i	: index of the coordinate
    //
    //  Outputs
    //	the corresponding coordinate
    //
    int & Grid2::operator [] ( int i )
    {
    #ifdef GRID2_INDEX_CHECK
        const char theName[] = "Grid2::operator [] : ";
        if ( ( i < 0 ) || ( i > 1 ) ) {
        cerr << theName << " index = " << i << endl;
        assert( ( 0 <= i ) && ( i <= 1 ) );
        }
    #endif	// GRID2_INDEX_CHECK
        return _element[ i ];
    }


    //
    //  Grid2::set --	set all the coordinates
    //
    //  Inputs
    //	x, y	: x and y coordinates
    //
    //  Returns
    //	none
    //
    void Grid2::set( const int x, const int y )
    {
        _element[ 0 ]	= x;
        _element[ 1 ]	= y;
    }

    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    //
    //  Grid2::getQuadVID --	get corner ids of a quad
    //
    //  Inputs
    //	i	: x index
    //	j	: y index
    //	vid	: id vector
    //
    //  Outputs
    //	none
    //
    void Grid2::getQuadVD ( unsigned int i, unsigned int j,
                            vector< Graph::GridGraph::vertex_descriptor > &vdVec )
    {
        unsigned int xrange = 2*_range[0]+1;
        unsigned int yrange = 2*_range[1]+1;

        vdVec.resize( 4 );

        vdVec[ 0 ] = vertex( i*yrange + j, _grid );
        vdVec[ 1 ] = vertex( (i+1)*yrange + j, _grid );
        vdVec[ 2 ] = vertex( (i+1)*yrange + j+1, _grid );
        vdVec[ 3 ] = vertex( i*yrange + j+1, _grid );

#ifdef DEBUG
        cerr << "i = " << i << " j = " << j << endl;
        for( unsigned int k = 0; k < vid.size(); k++ ){
            cerr << vid[ k ] << " ";
        }
        cerr << endl;
#endif // DEBUG
    }

    //------------------------------------------------------------------------------
    //	Friend functions
    //------------------------------------------------------------------------------
    //
    //  operator - --	sign change
    //
    //  Inputs
    //	a	: 2D coordinates
    //
    //  Outputs
    //	2D coordinates in the opposite direction
    //
    Grid2 operator - ( const Grid2 & a )
    {
        return Grid2( -a._element[ 0 ], -a._element[ 1 ] );
    }


    //
    //  operator + --	addition
    //
    //  Inputs
    //	a, b	: 2D coordinates
    //
    //  Outputs
    //	addition of the two 2D coordinates
    //
    Grid2 operator + ( const Grid2 & a, const Grid2 & b )
    {
        return Grid2( a._element[ 0 ] + b._element[ 0 ],
              a._element[ 1 ] + b._element[ 1 ] );
    }


    //
    //  operator - --	difference
    //
    //  Inputs
    //	a, b	: 2D coordinates
    //
    //  Outputs
    //	difference of the two 2D coordinates
    //
    Grid2 operator - ( const Grid2 & a, const Grid2 & b )
    {
        return Grid2( a._element[ 0 ] - b._element[ 0 ],
              a._element[ 1 ] - b._element[ 1 ] );
    }


    //
    //  operator * --	scalar product
    //
    //  Inputs
    //	d	: scalar value
    //	a	: 2D coordinates
    //
    //  Outputs
    //	scalar product
    //
    Grid2 operator * ( const int d, const Grid2 & a )
    {
        return Grid2( d * a._element[ 0 ], d * a._element[ 1 ] );
    }


    //
    //  operator * --	inner product
    //
    //  Inputs
    //	a, b	: 2D coordinates
    //
    //  Outputs
    //	inner product
    //
    int operator * ( const Grid2 & a, const Grid2 & b )
    {
        return ( a._element[ 0 ] * b._element[ 0 ] +
             a._element[ 1 ] * b._element[ 1 ] );
    }


    //
    //  operator == --	equivalence
    //
    //  Inputs
    //	a, b	: 2D coordinates
    //
    //  Outputs
    //	boolean value
    //
    int operator == ( const Grid2 & a, const Grid2 & b )
    {
        return ( ( a._element[ 0 ] == b._element[ 0 ] ) &&
             ( a._element[ 1 ] == b._element[ 1 ] ) );
    }


    //
    //  operator < --	comparison (less than)
    //
    //  Inputs
    //	a, b	: 2D coordinates
    //
    //  Outputs
    //	boolean value
    //
    int operator < ( const Grid2 & a, const Grid2 & b )
    {
        if ( a._element[ 0 ] < b._element[ 0 ] ) return true;
        else if ( a._element[ 0 ] > b._element[ 0 ] ) return false;
        else {
        if ( a._element[ 1 ] < b._element[ 1 ] ) return true;
        else if ( a._element[ 1 ] > b._element[ 1 ] ) return false;
        else return false;
        }
    }


    //
    //  operator > --	comparison (more than)
    //
    //  Inputs
    //	a, b	: 2D coordinates
    //
    //  Outputs
    //	boolean value
    //
    int operator > ( const Grid2 & a, const Grid2 & b )
    {
        if ( a._element[ 0 ] > b._element[ 0 ] ) return true;
        else if ( a._element[ 0 ] < b._element[ 0 ] ) return false;
        else {
        if ( a._element[ 1 ] > b._element[ 1 ] ) return true;
        else if ( a._element[ 1 ] < b._element[ 1 ] ) return false;
        else return false;
        }
    }


    //------------------------------------------------------------------------------
    //	I/O functions
    //------------------------------------------------------------------------------
    //
    //  operator << --	output
    //
    //  Inputs
    //	s	: reference to output stream
    //	v	: 2D coordinates
    //
    //  Outputs
    //	reference to output stream
    //
    ostream & operator << ( ostream & stream, const Grid2 & obj )
    {
        // set the output formatting
        int width = 16;
        // print out the elements
        for ( int i = 0; i < 2; i++ ) {
        stream << setw( width ) << obj._element[ i ];
        if ( i != 1 ) stream << "\t";
        }
        stream << endl;

        return stream;
    }


    //
    //  operator >> --	input
    //
    //  Inputs
    //	s	: reference to input stream
    //	v	: 2D coordinates
    //
    //  Outputs
    //	reference to input stream
    //
    istream & operator >> ( istream & stream, Grid2 & obj )
    {
        // reading the elements
        for ( int i = 0; i < 2; i++ )
        stream >> obj._element[ i ];
        return stream;
    }




