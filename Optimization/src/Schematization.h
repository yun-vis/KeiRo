//==============================================================================
// Schematization.h
//  : header file for the optimization
//
//==============================================================================

#ifndef _Schematization_H        // begining of header file
#define _Schematization_H        // notifying that this file is included

//----------------------------------------------------------------------
//  Including header files
//----------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>

using namespace std;

#include "Config.h"
#include "SchematicGraph.h"
#include "LaplacianOptimization.h"

//------------------------------------------------------------------------------
//	Defining data types
//------------------------------------------------------------------------------
//#define Schematization_CONFLICT
//#define Schematization_BOUNDARY

//------------------------------------------------------------------------------
//	Defining macros
//------------------------------------------------------------------------------
template <typename GraphType>
class Schematization : public LaplacianOptimization
	{
private:
	
	GraphType _graph;               // inner + outer boundary
	
	double _half_width;             // half_window_width
	double _half_height;            // half_window_height
	
	unsigned int _schematization_degree;    // othogonal, octilinear, or others
	double _w_schematization, _w_position, _w_fixposition;
	double _w_boundary, _w_crossing;
	//double _d_Alpha;
	double _d_Beta;
	vector< double > _theta;         // closest Schematization theta

protected:
	
	void _initCoefs( void ) override;
	
	void _setConstraints( unsigned int &nRows ) override;
	
	void _initVars( void ) override;
	
	void _setVars( unsigned int &nRows ) override;
	
	void _initOutputs( void ) override;
	
	void _updateCoefs( void ) override;
	
	void _updateOutputs( void ) override;
	
	void _init( string confFileName ) override;

	void _reset( void );

	void _setTargetAngle( void );
	
	void _updateEdgeCurAngle( void );
	
	bool _isOnLine( KeiRo::Base::Coord2 &a, KeiRo::Base::Coord2 &b, KeiRo::Base::Coord2 &c );

public:
	
	// default constructor
	Schematization ( void ) {
		_reset();
	}
	// Copy constructor
	Schematization( const Schematization<GraphType> &obj );
	// Destructor
	~Schematization( void );

//------------------------------------------------------------------------------
//  Reference to members
//------------------------------------------------------------------------------
	const GraphType &graph( void ) const { return _graph; }
	
	GraphType &graph( void ) { return _graph; }

//------------------------------------------------------------------------------
//  Specific functions
//------------------------------------------------------------------------------
	double LeastSquare( void ){
		_LeastSquare();
	};
	
	double ConjugateGradient( void ){
		_ConjugateGradient();
	};

//------------------------------------------------------------------------------
//      Initialization functions
//------------------------------------------------------------------------------
//	void prepare( string confFileName ) {
//		_init( confFileName );
//	}

//------------------------------------------------------------------------------
//  File I/O
//------------------------------------------------------------------------------
	void clear( void );
	
	void retrieve( void );

//------------------------------------------------------------------------------
//      I/O
//------------------------------------------------------------------------------
	friend ostream &operator<<( ostream &stream, const Schematization<GraphType> &obj );
	// Output
	
	friend istream &operator>>( istream &stream, Schematization<GraphType> &obj );
	// Input
	
	virtual const char *className( void ) const { return "Schematization"; }
	// Class name
};

//------------------------------------------------------------------------------
//	Protected functions
//------------------------------------------------------------------------------
//
//  Schematization::_reset --        reset the class
//
//  Inputs
//      none
//
//  Outputs
//      none
//
template <typename GraphType>
void Schematization<GraphType>::_reset( void ) {
	
	_optType = LEAST_SQUARE;
	
	_graph = NULL;
	_half_width = 0.0;    // window_width
	_half_height = 0.0;   // window_height
	
	_nVars = 0;
	_nConstrs = 0;
	_w_schematization = 0.0;
	_w_position = 0.0;
	_w_fixposition = 0.0;
	_w_boundary = 0.0;
	_w_crossing = 0.0;
	//_d_Alpha = 0.0;
	_d_Beta = 0.0;
	_theta.clear();
}

//
//  Schematization::_init --        initialize the constrained optimization problem
//
//  Inputs
//      __boundary : pointer to boundary
//
//  Outputs
//      none
//
template <typename GraphType>
void Schematization<GraphType>::_init( string confFileName ) {
	
	GraphType &g = _graph;
	unsigned int nVertices = num_vertices( g );
	unsigned int nEdges = num_edges( g );
	
	// initialization
	_nVars = _nConstrs = 0;
	_half_width = KeiRo::Base::Common::getMainwidgetWidth() / 2.0;
	_half_height = KeiRo::Base::Common::getMainwidgetHeight() / 2.0;
	
	//_d_Alpha = _OrthogonalBoundaryVec->dAlpha();
	_d_Beta = 1.0;
	
	// read config file
	string configFilePath = qApp->applicationDirPath().toStdString() + confFileName;
	// string configFilePath = qApp->applicationDirPath().toStdString() + "/../../ResponsiveLens/config/Orthogonal.conf";
	
	KeiRo::Base::Config conf( configFilePath );
	
	if( conf.has( "schematization_degree" ) ) {
		string paramDegree = conf.gets( "schematization_degree" );
		_schematization_degree = KeiRo::Base::Common::stringToDouble( paramDegree );
	}
	
	if( conf.has( "iteration" ) ) {
		string paramIteration = conf.gets( "iteration" );
		_iteration = KeiRo::Base::Common::stringToDouble( paramIteration );
	}
	
	if( conf.has( "w_schematization" ) ) {
		string paramSchematization = conf.gets( "w_schematization" );
		_w_schematization = sqrt( KeiRo::Base::Common::stringToDouble( paramSchematization ) );
	}
	
	if( conf.has( "w_position" ) ) {
		string paramPosition = conf.gets( "w_position" );
		_w_position = sqrt( KeiRo::Base::Common::stringToDouble( paramPosition ) );
	}
	
	if( conf.has( "w_fixposition" ) ) {
		string paramFixPosition = conf.gets( "w_fixposition" );
		_w_fixposition = sqrt( KeiRo::Base::Common::stringToDouble( paramFixPosition ) );
	}
	
	if( conf.has( "w_boundary" ) ) {
		string paramBoundary = conf.gets( "w_boundary" );
		_w_boundary = sqrt( KeiRo::Base::Common::stringToDouble( paramBoundary ) );
	}
	
	if( conf.has( "w_crossing" ) ) {
		string paramCrossing = conf.gets( "w_crossing" );
		_w_crossing = sqrt( KeiRo::Base::Common::stringToDouble( paramCrossing ) );
	}
	
	if( conf.has( "opttype" ) ) {
		string paramType = conf.gets( "opttype" );
		if( paramType == "LEAST_SQUARE" )
			_optType = LEAST_SQUARE;
		else if( paramType == "CONJUGATE_GRADIENT" )
			_optType = CONJUGATE_GRADIENT;
		else {
			assert( false );
		}
	}

// #ifdef DEBUG
	//cerr << "nAlpha = " << nAlpha << " nBeta = " << nBeta << " nVertices = " << nEdges << endl;
	//cerr << "_d_Alpha = " << _d_Alpha << endl;
	//cerr << " _d_Beta = " << _d_Beta << endl;
	cerr << " w_schematization = " << _w_schematization << endl;
	cerr << " schematization_degree = " << _schematization_degree << endl;
	cerr << " iteration = " << _iteration << endl;
// #endif  // DEBUG

//------------------------------------------------------------------------------
//      Total number of linear variables
//------------------------------------------------------------------------------
	_nVars = 2 * nVertices;

//------------------------------------------------------------------------------
//      Total number of linear constraints
//------------------------------------------------------------------------------
	// Regular edge length
	_nConstrs += 2 * nEdges;
	
	// Positional constraints
	_nConstrs += 2 * nVertices;
	
	_initCoefs();
	_initVars();
	_initOutputs();
	_updateCoefs();
	_updateOutputs();

#ifdef  DEBUG
	//printGraph( g );
	cerr << " nVertices = " << nVertices << " nEdges = " << nEdges << endl;
	cerr << " nVars = " << _nVars << " nConstrs = " << _nConstrs << endl;
	cerr << "Finished initializing the linear system" << endl;
	cerr << "_opttype = " << _opttype << endl;
#endif  // DEBUG
}

//
//  Schematization::_initCoefs --        initialize the coefficient
//
//  Inputs
//      none
//
//  Outputs
//      none
//
template <typename GraphType>
void Schematization<GraphType>::_initCoefs( void ) {
	
	GraphType &g = _graph;
	unsigned int nVertices = num_vertices( g );
	
	// initialization
	unsigned int nRows = 0;
	_coef.resize( _nConstrs, _nVars );
	_coef << Eigen::MatrixXd::Zero( _nConstrs, _nVars );
	
	// Regular edge schematization
	BGL_FORALL_EDGES_T( edge, g, GraphType) {
			
			typename GraphType::vertex_descriptor vdS = source( edge, g );
			typename GraphType::vertex_descriptor vdT = target( edge, g );
			unsigned int idS = MIN2( g[ vdS ].id, g[ vdT ].id );
			unsigned int idT = MAX2( g[ vdS ].id, g[ vdT ].id );
			
			// x
			_coef( nRows, idS ) = _w_schematization;
			_coef( nRows, idT ) = -_w_schematization;
			nRows++;
			
			// y
			_coef( nRows, idS + nVertices ) = _w_schematization;
			_coef( nRows, idT + nVertices ) = -_w_schematization;
			nRows++;
		}
	
	// Positional constraints
	BGL_FORALL_VERTICES_T( vertex, g, GraphType ) {
			
			unsigned int id = g[ vertex ].id;
			bool fix = false;
			
			// collect fixed vertices
			vector< typename GraphType::vertex_descriptor > vdVec;
			typename GraphType::out_edge_iterator eo, eo_end;
			for( tie( eo, eo_end ) = out_edges( vertex, g ); eo != eo_end; ++eo ) {
				
				typename GraphType::edge_descriptor ed = *eo;
				typename GraphType::vertex_descriptor vdT = target( ed, g );
				
				if( g[ vertex ].isFixed == true ) {
					vdVec.push_back( vdT );
				}
			}
			
			// check if on a line
			if( vdVec.size() == 2 ) {
				
				fix = ! KeiRo::Base::Line2::isOnLine( *g[ vertex ].coordPtr,
				                                      *g[ vdVec[ 0 ] ].coordPtr, *g[ vdVec[ 1 ] ].coordPtr );
				
				// cerr << "vid = " << g[ vertex ].id << endl;
			}
			
			if( fix == true ) {
				
				// cerr << "vid = " << g[ vertex ].id << " node = " << *g[ vertex ].coordPtr;
				
				// x
				_coef( nRows, id ) = _w_fixposition;
				nRows++;
				
				// y
				_coef( nRows, id + nVertices ) = _w_fixposition;
			}
			else {
				// x
				_coef( nRows, id ) = _w_position;
				nRows++;
				
				// y
				_coef( nRows, id + nVertices ) = _w_position;
			}
			nRows++;
		}

#ifdef  DEBUG
	cerr << "_coef:" << endl;
	cerr << _coef << endl;
#endif  // DEBUG
}

//
//  Schematization::_setConstraints --        set the Constraints
//
//  Inputs
//      none
//
//  Outputs
//      none
//
template <typename GraphType>
void Schematization<GraphType>::_setConstraints( unsigned int &nRow ) {

}

//
//  Schematization::_initVars --        initialize the variables
//
//  Inputs
//      none
//
//  Outputs
//      none
//
template <typename GraphType>
void Schematization<GraphType>::_initVars( void ) {
	
	GraphType &g = _graph;
	unsigned int nVertices = num_vertices( g );
	
	// initialization
	_var.resize( _nVars );
	
	unsigned int nRows = 0;
	BGL_FORALL_VERTICES_T( vertex, g, GraphType ) {
			
			_var( nRows, 0 ) = g[ vertex ].coordPtr->x();
			_var( nRows + nVertices, 0 ) = g[ vertex ].coordPtr->y();
			nRows++;
		}

#ifdef  DEBUG
	cerr << "_initvar:" << endl;
	cerr << _var << endl;
#endif  // DEBUG
}

//
//  Schematization::_setVars --        set the variables
//
//  Inputs
//      none
//
//  Outputs
//      none
//
template <typename GraphType>
void Schematization<GraphType>::_setVars( unsigned int &nRow ) {

}

template <typename GraphType>
void Schematization<GraphType>::_updateEdgeCurAngle( void ) {
	
	GraphType &g = _graph;
	
	// initialization
	BGL_FORALL_EDGES_T( edge, g, GraphType ) {
			
			typename GraphType::vertex_descriptor vS = source( edge, g );
			typename GraphType::vertex_descriptor vT = target( edge, g );
			KeiRo::Base::Coord2 vi, vj;
			if( g[ vS ].id < g[ vT ].id ) {
				vi = *g[ vS ].coordPtr;
				vj = *g[ vT ].coordPtr;
			}
			else {
				vi = *g[ vT ].coordPtr;
				vj = *g[ vS ].coordPtr;
			}
			KeiRo::Base::Coord2 vji = vj - vi;
			
			double angle = atan2( vji.y(), vji.x() );
			g[ edge ].angle = angle;
		}

#ifdef  DEBUG
	BGL_FORALL_EDGES( edge, g, GraphType ){
		cerr << "EID = " << g[ edge ].id
			 << ", edgeCurAngle = " << g[ edge ].angle << endl;
	}
#endif  // DEBUG
}

template <typename GraphType>
void Schematization<GraphType>::_setTargetAngle( void ) {
	
	GraphType &g = _graph;
	
	unsigned int axis = _schematization_degree + 1;
	vector< double > sector;
	for( unsigned int i = 0; i < axis; i++ ){
		double m = (axis - 1.0) / 2.0;
		double angle = ( 0 + (double)i * 1.0/m ) * M_PI -M_PI;
		// cerr << "i = " << angle << endl;
		sector.push_back( angle );
	}
//	double sector[9] = {-M_PI, -3.0 * M_PI / 4.0, -M_PI / 2.0, -M_PI / 4.0, 0.0,
//	                    M_PI / 4.0, M_PI / 2.0, 3.0 * M_PI / 4.0, M_PI};
	
	// initialization
	BGL_FORALL_EDGES_T( edge, g, GraphType ) {
			
			double targetAngle = 2.0 * M_PI;
			double minDist = 2.0 * M_PI + 1.0;
			for( unsigned int i = 0; i < axis; i++ ) {
				double dist = fabs( g[ edge ].geoAngle - sector[ i ] );
				if( dist < minDist ) {
					minDist = dist;
					targetAngle = sector[ i ];
				}
			}
			g[ edge ].targetAngle = targetAngle;
		}
}

#ifdef  SKIP
void Schematization::_setTargetAngle( void )
{
	GraphType        & g            = _OrthogonalBoundaryVec->boundary();

	double sector[ 9 ] = { -M_PI, -3.0*M_PI/4.0, -M_PI/2.0, -M_PI/4.0, 0.0,
						   M_PI/4.0, M_PI/2.0, 3.0*M_PI/4.0, M_PI };

	vector< vector< GraphType::vertex_descriptor > > vdVec( Orthogonal_SECTOR );
	BGL_FORALL_VERTICES( vertex, g, GraphType ){
		GraphType::degree_size_type degrees = out_degree( vertex, g );
		vdVec[ Orthogonal_SECTOR - degrees ].push_back( vertex );
	}

#ifdef  DEBUG
	for( int i = 0; i < vdVec.size(); i++ ){
		cerr << " i = " << Orthogonal_SECTOR-i << " ";
		for( int j = 0; j < vdVec[ i ].size(); j++ ){
			cerr << vertexCoord[ vdVec[i][j] ] <<  " ";
		}
		cerr << endl;
	}
#endif  // DEBUG

	// initialization
	BGL_FORALL_EDGES( edge, g, GraphType ){
		g[ edge ].targetAngle = 2.0*M_PI;
	}

	// set target angles
	for( int i = 0; i < vdVec.size(); i++ ){
		for( int j = 0; j < vdVec[ i ].size(); j++ ){

			map< double, GraphType::edge_descriptor > circM;
			// sort the angle
			GraphType::out_edge_iterator e, e_end;
			for ( tie( e, e_end ) = out_edges( vdVec[i][j], g ); e != e_end; ++e ) {
				GraphType::edge_descriptor ed = *e;
				GraphType::vertex_descriptor vS = source( ed, g );
				GraphType::vertex_descriptor vT = target( ed, g );
				double angle = g[ ed ].angle;

				if ( g[ vS ].id > g[ vT ].id ) {
					if ( angle > 0 ) angle = -M_PI + g[ ed ].angle;
					else angle = M_PI + g[ ed ].angle;
				}
				circM.insert( pair< double, GraphType::edge_descriptor >( angle, ed ) );
				//cerr << "eID = " << edgeID[ ed ] << " angle = " << angle << " curAngle = " << edgeCurAngle[ ed ] << endl;
				// cerr << "sID = " << vertexID[ vS ] << " tID = " << vertexID[ vT ] << endl;
			}

			// assign the sector
			int index = 0;
			for ( map< double, GraphType::edge_descriptor >::iterator it = circM.begin();
				  it != circM.end(); it++ ) {

				GraphType::edge_descriptor ed = it->second;
				GraphType::vertex_descriptor vS = source( ed, g );
				GraphType::vertex_descriptor vT = target( ed, g );

				if( g[ ed ].targetAngle == 2.0*M_PI ){
					double angle = g[ ed ].angle;
					if ( g[ vS ].id > g[ vT ].id ) {
						if ( angle > 0 ) angle = -M_PI + g[ ed ].angle;
						else angle = M_PI + g[ ed ].angle;
					}
					double target = 0.0, minDist = M_PI;

					for ( int k = index; k < 9 ; k++ ) {

						double dist = fabs( sector[ k ] - angle );
						if( minDist > dist ) {
							minDist = dist;
							target = sector[ k ];
							index = k+1;
						}
					}
					if ( g[ vS ].id > g[ vT ].id ) {
						if ( target > 0 ) g[ ed ].targetAngle = -M_PI + target;
						else g[ ed ].targetAngle = M_PI + target;
					}
					else{
						g[ ed ].targetAngle = target;
					}
					//cerr << "EID = " << edgeID[ ed ] << ", index = " << index << ", target = " << edgeTarget[ ed ] << endl;
					//cerr << "EID = " << edgeID[ ed ] << ", angle = " << edgeCurAngle[ ed ] << ", target = " << edgeTarget[ ed ] << endl;
				}
				else{
					double target = g[ ed ].targetAngle;

					if ( g[ vS ].id > g[ vT ].id ) {
						if ( target > 0 ) target = -M_PI + g[ ed ].targetAngle;
						else target = M_PI + g[ ed ].targetAngle;
					}
					for( int k = index; k < 9; k++ ){
						if( target == sector[ k ] ) index = k+1;
					}
					//cerr << "EID = " << edgeID[ ed ] << " skipping... " << index << endl;
				}
			}
		}
	}

#ifdef  DEBUG
	BGL_FORALL_EDGES( edge, g, GraphType ){
		cerr << "eid = "<< edgeID[ edge ] << " angle = " << edgeCurAngle[ edge ]
			 << " target = " << edgeTarget[ edge ] + edgeCurAngle[ edge ]
			 << " rotate = " << edgeTarget[ edge ] << endl;
	}
#endif  // DEBUG
}
#endif // SKIP

#ifdef  SKIP
double Schematization::_findRotateAngle( double input )
{
	double target = 0.0, minDist = M_PI;
	double sector[ 9 ] = { -M_PI, -3.0*M_PI/4.0, -M_PI/2.0, -M_PI/4.0, 0.0,
						   M_PI/4.0, M_PI/2.0, 3.0*M_PI/4.0, M_PI };

	for ( int i = 0; i < 9 ; i++ ) {

		double dist = fabs( sector[ i ] - input );
		if( minDist > dist ) {
			minDist = dist;
			target = sector[ i ];
		}
	}

#ifdef  DEBUG
	cerr << "inputAngle = " << input << " targetAngle = " << target << " rotate = " << target-input << endl;
#endif  // DEBUG
	return target - input;
}
#endif  // SKIP

//
//  Schematization::_initOutputs --        initialize the output
//
//  Inputs
//      none
//
//  Outputs
//      none
//
template <typename GraphType>
void Schematization<GraphType>::_initOutputs( void ) {
	
	GraphType &g = _graph;
	
	// initialization
	unsigned int nRows = 0;
	_output.resize( _nConstrs );
	_output << Eigen::VectorXd::Zero( _nConstrs );
	
	_updateEdgeCurAngle();
	_setTargetAngle();
	
	// Regular edge Orthogonalty
	BGL_FORALL_EDGES_T( edge, g, GraphType ) {
			typename GraphType::vertex_descriptor vdS = source( edge, g );
			typename GraphType::vertex_descriptor vdT = target( edge, g );
			KeiRo::Base::Coord2 vi, vj;
			if( g[ vdS ].id < g[ vdT ].id ) {
				vi = *g[ vdS ].smoothPtr;
				vj = *g[ vdT ].smoothPtr;
			}
			else {
				vi = *g[ vdT ].smoothPtr;
				vj = *g[ vdS ].smoothPtr;
			}
			KeiRo::Base::Coord2 vji = vi - vj;
#ifdef  DEBUG
			cerr << "vji = " << vji;
#endif  // DEBUG
			double angle = g[ edge ].angle;
			double theta = g[ edge ].targetAngle - angle;
#ifdef  DEBUG
			cerr << "e( " << g[vdS].id << "," << g[vdT].id << " )"
				 << " targetAngle = " << g[ edge ].targetAngle
				 << " angle = " << g[ edge ].angle << endl;
			cerr << "eid = " << edgeID[ edge ] << " ";
#endif  // DEBUG
			double cosTheta = cos( theta ), sinTheta = sin( theta );
			// double s = _d_Beta * g[ edge ].weight / vji.norm();
			double s = g[ edge ].weight;
			
			// x
			_output( nRows, 0 ) = _w_schematization * s * ( cosTheta * vji.x() - sinTheta * vji.y() );
			nRows++;
			
			// y
			_output( nRows, 0 ) = _w_schematization * s * ( sinTheta * vji.x() + cosTheta * vji.y() );
			nRows++;
		}
	
	
	// Positional constraints
	BGL_FORALL_VERTICES_T( vertex, g, GraphType ) {
			
			bool fix = false;
			
			// collect fixed vertices
			vector< typename GraphType::vertex_descriptor > vdVec;
			typename GraphType::out_edge_iterator eo, eo_end;
			for( tie( eo, eo_end ) = out_edges( vertex, g ); eo != eo_end; ++eo ) {
				
				typename GraphType::edge_descriptor ed = *eo;
				typename GraphType::vertex_descriptor vdT = target( ed, g );
				
				if( g[ vertex ].isFixed == true ) {
					vdVec.push_back( vdT );
				}
			}
			
			// check if on a line
			if( vdVec.size() == 2 ) {
				
				//fix = true;
				fix = ! KeiRo::Base::Line2::isOnLine( *g[ vertex ].coordPtr,
				                                      *g[ vdVec[ 0 ] ].coordPtr, *g[ vdVec[ 1 ] ].coordPtr );
			}
			
			if( fix == true ) {
				
				_output( nRows, 0 ) = _w_fixposition * g[ vertex ].smoothPtr->x();
				nRows++;
				_output( nRows, 0 ) = _w_fixposition * g[ vertex ].smoothPtr->y();
				nRows++;
			}
			else {
				_output( nRows, 0 ) = _w_position * g[ vertex ].smoothPtr->x();
				nRows++;
				_output( nRows, 0 ) = _w_position * g[ vertex ].smoothPtr->y();
				nRows++;
			}
		}

#ifdef  DEBUG
	cerr << "_initOutput:" << endl;
	cerr << _output << endl;
#endif  // DEBUG
}


//
//  Schematization::_updateCoefs --        update the coefs
//
//  Inputs
//      none
//
//  Outputs
//      none
//
template <typename GraphType>
void Schematization<GraphType>::_updateCoefs( void ) {
	
	GraphType &g = _graph;
	unsigned int nVertices = num_vertices( g );
	unsigned int nVE = 0;
	unsigned int nB = 0;
	//vector< double > ratioR = _OrthogonalBoundaryVec->ratioR();
	
	Eigen::MatrixXd oldCoef;
	oldCoef = _coef.block( 0, 0, _nConstrs, _nVars );

#ifdef Orthogonal_CONFLICT
	nVE = _OrthogonalBoundaryVec->VEconflict().size();
#endif // Orthogonal_CONFLICT
#ifdef Orthogonal_BOUNDARY
	BGL_FORALL_VERTICES( vd, g, GraphType )
	{
		double minD = _d_Beta/2.0;
		//if( vertexIsStation[ vd ] == false )
		//    minD = vertexExternal[ vd ].leaderWeight() * _d_Beta/2.0;
		if ( g[ vd ].coordPtr->x() <= -( _half_width - minD ) ) nB++;
		if ( g[ vd ].coordPtr->x() >= ( _half_width - minD ) ) nB++;
		if ( g[ vd ].coordPtr->y() <= -( _half_height - minD ) ) nB++;
		if ( g[ vd ].coordPtr->y() >= ( _half_height - minD ) ) nB++;
	}
#endif // Orthogonal_BOUNDARY
	_coef.resize( _nConstrs + nB + 2 * nVE, _nVars );
	// _coef << Eigen::MatrixXd::Zero( _nConstrs + 2*nVE, _nVars );
	
	// copy old coefficient
	_coef << oldCoef, Eigen::MatrixXd::Zero( nB + 2 * nVE, _nVars );
	
	// cerr << "nVE = " << nVE << endl;
	unsigned int nRows = _nConstrs;

#ifdef  Orthogonal_BOUNDARY
	// add boundary coefficient
	BGL_FORALL_VERTICES( vd, g, GraphType ){

		unsigned int id = g[ vd ].id;
		double minD = _d_Beta/2.0;
		//if( vertexIsStation[ vd ] == false )
		//    minD = vertexExternal[ vd ].leaderWeight() * _d_Beta/2.0;

		if ( g[ vd ].coordPtr->x() <= -( _half_width - minD ) ) {
			_coef( nRows, id ) = _w_boundary;
			nRows++;
		}
		if ( g[ vd ].coordPtr->x() >= ( _half_width - minD ) ) {
			_coef( nRows, id ) = _w_boundary;
			nRows++;
		}
		if ( g[ vd ].coordPtr->y() <= -( _half_height - minD ) ) {
			_coef( nRows, id + nVertices ) = _w_boundary;
			nRows++;
		}
		if ( g[ vd ].coordPtr->y() >= ( _half_height - minD ) ) {
			_coef( nRows, id + nVertices ) = _w_boundary;
			nRows++;
		}
	}
#endif  // Orthogonal_BOUNDARY

#ifdef  Orthogonal_CONFLICT
	// copy conflict coefficient
	unsigned int countVE = 0;
	for ( VEMap::iterator it = _OrthogonalBoundaryVec->VEconflict().begin();
		  it != _OrthogonalBoundaryVec->VEconflict().end(); ++it ) {
		GraphType::vertex_descriptor vdV = it->second.first;
		GraphType::edge_descriptor ed = it->second.second;
		GraphType::vertex_descriptor vdS = source( ed, g );
		GraphType::vertex_descriptor vdT = target( ed, g );
		unsigned int idV = g[ vdV ].id;
		unsigned int idS = g[ vdS ].id;
		unsigned int idT = g[ vdT ].id;
		double r = ratioR[ countVE ];

		// x
		_coef( nRows, idV ) = 1.0 * _w_crossing;
		_coef( nRows, idS ) = -r * _w_crossing;
		_coef( nRows, idT ) = ( r - 1.0 ) * _w_crossing;
		nRows++;

		// y
		_coef( nRows, idV + nVertices ) = 1.0 * _w_crossing;
		_coef( nRows, idS + nVertices ) = -r * _w_crossing;
		_coef( nRows, idT + nVertices ) = ( r - 1.0 ) * _w_crossing;
		nRows++;
		
		countVE++;
	}
#endif  // Orthogonal_CONFLICT

#ifdef  DEBUG
	cerr << "###############" << endl;
	cerr << "newCoef:" << endl;
	cerr << _coef << endl;
	cerr << "###############" << endl;
#endif  // DEBUG
}

//
//  Schematization::_updateOutputs --        update the output
//
//  Inputs
//      none
//
//  Outputs
//      none
//
template <typename GraphType>
void Schematization<GraphType>::_updateOutputs( void ) {
	
	GraphType &g = _graph;
	unsigned int nVE = 0;
	unsigned int nB = 0;
	//vector< double > ratioR = _OrthogonalBoundaryVec->ratioR();
	
	unsigned int nRows = 0;
	Eigen::VectorXd oldOutput;
	oldOutput = _output;
#ifdef  Orthogonal_CONFLICT
	nVE = _OrthogonalBoundaryVec->VEconflict().size();
#endif  // Orthogonal_CONFLICT
#ifdef  Orthogonal_BOUNDARY
	BGL_FORALL_VERTICES( vd, g, GraphType )
	{
		double minD = _d_Beta/2.0;
		//if( vertexIsStation[ vd ] == false )
		//    minD = vertexExternal[ vd ].leaderWeight() * _d_Beta/2.0;
		if ( g[ vd ].coordPtr->x() <= -( _half_width - minD ) ) nB++;
		if ( g[ vd ].coordPtr->x() >= ( _half_width - minD ) ) nB++;
		if ( g[ vd ].coordPtr->y() <= -( _half_height - minD ) ) nB++;
		if ( g[ vd ].coordPtr->y() >= ( _half_height - minD ) ) nB++;
	}
#endif  // Orthogonal_BOUNDARY
	_output.resize( _nConstrs + nB + 2 * nVE );
	_output << Eigen::VectorXd::Zero( _nConstrs + nB + 2 * nVE );
	
	_updateEdgeCurAngle();
	//_setTargetAngle();
	
	// Regular edge Orthogonalty
	BGL_FORALL_EDGES_T( edge, g, GraphType ) {
			
			typename GraphType::vertex_descriptor vdS = source( edge, g );
			typename GraphType::vertex_descriptor vdT = target( edge, g );
			//Coord2 vi = vertexSmooth[ vdS ];
			//Coord2 vj = vertexSmooth[ vdT ];
			KeiRo::Base::Coord2 vi, vj;
			if( g[ vdS ].id < g[ vdT ].id ) {
				vi = *g[ vdS ].coordPtr;
				vj = *g[ vdT ].coordPtr;
			}
			else {
				vi = *g[ vdT ].coordPtr;
				vj = *g[ vdS ].coordPtr;
			}
			KeiRo::Base::Coord2 vji = vi - vj;
			double angle = g[ edge ].angle;
			double theta = g[ edge ].targetAngle - angle;
			double cosTheta = cos( theta ), sinTheta = sin( theta );
			// double s = _d_Beta * g[ edge ].weight / vji.norm();
			double s = g[ edge ].weight;

#ifdef  DEBUG
			cerr << "vji = " << vji;
			if( vertexID[ vdS ] == 4 && vertexID[ vdT ] == 5 )
				cerr << "( " << vertexID[ vdS ] << ", " << vertexID[ vdT ] << ") angle = " << angle << " theta = " << theta << endl;
#endif  // DEBUG
			
			// x
			_output( nRows, 0 ) = _w_schematization * s * ( cosTheta * vji.x() - sinTheta * vji.y() );
			nRows++;
			
			// y
			_output( nRows, 0 ) = _w_schematization * s * ( sinTheta * vji.x() + cosTheta * vji.y() );
			nRows++;
		}
	
	// Positional constraints
	BGL_FORALL_VERTICES_T( vertex, g, GraphType ) {
			
			// x
			_output( nRows, 0 ) = oldOutput( nRows, 0 );
			nRows++;
			
			// y
			_output( nRows, 0 ) = oldOutput( nRows, 0 );
			nRows++;
		}

#ifdef  Orthogonal_BOUNDARY
	// boundary constraints
	BGL_FORALL_VERTICES( vd, g, GraphType ){

		double minD = _d_Beta/2.0;
		//if( vertexIsStation[ vd ] == false )
		//    minD = vertexExternal[ vd ].leaderWeight() * _d_Beta/2.0;

		if ( g[ vd ].coordPtr->x() <= -( _half_width - minD ) ) {
			_output( nRows, 0 ) = _w_boundary * -( _half_width - minD );
			nRows++;
		}
		if ( g[ vd ].coordPtr->x() >= ( _half_width - minD ) ) {
			_output( nRows, 0 ) = _w_boundary * ( _half_width - minD );
			nRows++;
		}
		if ( g[ vd ].coordPtr->y() <= -( _half_height - minD ) ) {
			_output( nRows, 0 ) = _w_boundary * -( _half_height - minD );
			nRows++;
		}
		if ( g[ vd ].coordPtr->y() >= ( _half_height - minD ) ) {
			_output( nRows, 0 ) = _w_boundary * ( _half_height - minD );
			nRows++;
		}
	}
#endif  // Orthogonal_BOUNDARY

#ifdef  Orthogonal_CONFLICT
	// copy conflict coefficient
	unsigned int countVE = 0;
	for ( VEMap::iterator it = _OrthogonalBoundaryVec->VEconflict().begin();
		  it != _OrthogonalBoundaryVec->VEconflict().end(); ++it ) {
		GraphType::vertex_descriptor vdV = it->second.first;
		GraphType::edge_descriptor ed = it->second.second;
		GraphType::vertex_descriptor vdS = source( ed, g );
		GraphType::vertex_descriptor vdT = target( ed, g );
		unsigned int idV = g[ vdV ].id;
		unsigned int idS = g[ vdS ].id;
		unsigned int idT = g[ vdT ].id;
		double r = ratioR[ countVE ];

		Coord2 v = *g[ vdV ].geoPtr;
		Coord2 p = r * *g[ vdS ].geoPtr + ( 1.0-r ) * *g[ vdT ].geoPtr;
		double minD = _d_Beta/2.0;
		//if( vertexIsStation[ vdV ] == false )
		//    minD = vertexExternal[ vdV ].leaderWeight() * _d_Beta/2.0;
		double delta = minD / ( v - p ).norm();

		// x
		_output( nRows, 0 ) = _w_crossing * delta * ( v - p ).x();
		nRows++;

		// y
		_output( nRows, 0 ) = _w_crossing * delta * ( v - p ).y();
		nRows++;
	}
#endif  // Orthogonal_CONFLICT

#ifdef  DEBUG
	cerr << "_updatedOutput:" << endl;
	cerr << _output << endl;
#endif  // DEBUG
}

//
//  Schematization::retrieve --        retrieve the result
//
//  Inputs
//      none
//
//  Outputs
//      none
//
template <typename GraphType>
void Schematization<GraphType>::retrieve( void ) {
	
	GraphType &g = _graph;
	const unsigned int nVertices = num_vertices( g );
	
	// find the vertex that is too close to an edge
	vector< typename GraphType::vertex_descriptor > vdVec;
#ifdef  Orthogonal_CONFLICT
	for( VEMap::iterator it = _OrthogonalBoundaryVec->VEconflict().begin();
	     it != _OrthogonalBoundaryVec->VEconflict().end(); ++it ) {
		GraphType::vertex_descriptor vdV = it->second.first;
		vdVec.push_back( vdV );
	}
#endif  // Orthogonal_CONFLICT
	
	unsigned int nRows = 0;
	// update coordinates
	// but freeze the vertex that is too close to an edge
	BGL_FORALL_VERTICES_T( vertex, g, GraphType ) {
			
			bool doClose = false;
			for( unsigned int i = 0; i < vdVec.size(); i++ ) {
				if( vertex == vdVec[ i ] ) doClose = true;
			}
			
			double x = _var( nRows, 0 );
			double y = _var( nRows + nVertices, 0 );
			if( !isnan( x ) && !isnan( y ) ) {
				if( false ) {
					//if( _OrthogonalBoundaryVec->VEconflict().size() > 0 ) {
					KeiRo::Base::Coord2 downscale;
					downscale.x() = ( x - g[ vertex ].coordPtr->x() ) / 2.0 + g[ vertex ].coordPtr->x();
					downscale.y() = ( y - g[ vertex ].coordPtr->y() ) / 2.0 + g[ vertex ].coordPtr->y();
					//if( g[ vertex ].isFixed != true ){
					g[ vertex ].coordPtr->x() = downscale.x();
					g[ vertex ].coordPtr->y() = downscale.y();
					//}
					//cerr << "x = " << x << " y = " << y << endl;
				}
				else {
					
					bool fix = false;
					
					// collect fixed vertices
					vector< typename GraphType::vertex_descriptor > vdVec;
					typename GraphType::out_edge_iterator eo, eo_end;
					for( tie( eo, eo_end ) = out_edges( vertex, g ); eo != eo_end; ++eo ) {
						
						typename GraphType::edge_descriptor ed = *eo;
						typename GraphType::vertex_descriptor vdT = target( ed, g );
						
						if( g[ vertex ].isFixed == true ) {
							vdVec.push_back( vdT );
						}
					}
					
					// check if on a line
					if( vdVec.size() == 2 ) {
						
						fix = ! KeiRo::Base::Line2::isOnLine( *g[ vertex ].coordPtr,
						                                      *g[ vdVec[ 0 ] ].coordPtr, *g[ vdVec[ 1 ] ].coordPtr );
						
						// cerr << "vid = " << g[ vertex ].id << endl;
					}
					
					//if( fix != true ){
					//if( g[ vertex ].isFixed != true ){
					g[ vertex ].coordPtr->x() = x;
					g[ vertex ].coordPtr->y() = y;
					//}
				}
			}
			nRows++;
		}

#ifdef  Orthogonal_CONFLICT
	// check possible conflict
	_OrthogonalBoundaryVec->checkVEConflicts();
#endif  // Orthogonal_CONFLICT

#ifdef  DEBUG
	cerr << "retrieve:" << endl;
	BGL_FORALL_VERTICES( vertex, g, GraphType ){
		cerr << "V(" << g[ vertex ].id << ") = " << *g[ vertex ].smoothPtr;
	}
	BGL_FORALL_EDGES( edge, g, GraphType ){
		cerr << "E(" << g[ edge ].id << ") : smoAngle= " << edgeSmoAngle[ edge ] << endl;
	}
#endif  // DEBUG
}

#endif // _Schematization_H

// end of header file
// Do not add any stuff under this line.
