// LalacianMatrix.cpp
//  : program file for the boundary network
//
//------------------------------------------------------------------------------
//
//              Date: Mon Dec 10 04:28:26 2012
//
//==============================================================================

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#include "LaplacianOptimization.h"

//------------------------------------------------------------------------------
//	Protected functions
//------------------------------------------------------------------------------
//
//  LaplacianOptimization::_reset --        reset the class
//
//  Inputs
//      none
//
//  Outputs
//      none
//
void LaplacianOptimization::_reset( void ) {
	
	_optType = LEAST_SQUARE;
	
	_nVars = 0;
	_nConstrs = 0;
	_iteration = 0;
}

//
//  LaplacianOptimization::_LeastSquare --        optimization
//
//  Inputs
//      none
//
//  Outputs
//      err:
//
double LaplacianOptimization::_LeastSquare( void ) {
	
	double mse = 0.0;
	unsigned int iter = _iteration;
	for( int i = 0; i < iter; i++ ) {
		
		Eigen::VectorXd last_var = _var;

#ifdef  DEBUG_TIME
		clock_t start_time = 0;
		float time1 = 0, time2 = 0, time3 = 0, time4 = 0;
		start_time = clock();
#endif  // DEBUG_TIME
		
		// ### optimization ###
		_var = ( ( _coef.transpose() * _coef ) ).inverse() * _coef.transpose() * _output;
#ifdef  DEBUG_TIME
		time1 = clock() - start_time;
		start_time = clock();
#endif  // DEBUG_TIME
		
		// ### retrieve the result ###
		retrieve();
#ifdef  DEBUG_TIME
		time2 = clock() - start_time;
		start_time = clock();
#endif  // DEBUG_TIME
		
		// ### update coefficient matrix ###
		_updateCoefs();
#ifdef  DEBUG_TIME
		time3 = clock() - start_time;
		start_time = clock();
#endif  // DEBUG_TIME
		
		// ### update target values ###
		_updateOutputs();
#ifdef  DEBUG_TIME
		time4 = clock() - start_time;
#endif  // DEBUG_TIME
		
		// node movement
		Eigen::VectorXd err = last_var - _var;
		mse = err.adjoint() * err;
		
		if( ( i + 1 ) % 100 == 0 )
			cerr << setprecision( 10 ) << "Loop(" << i << ") mse = " << mse << endl;
#ifdef  DEBUG_TIME
		cerr << "time1 = " << time1 << " time2 = " << time2 << " time3 = " << time3 << " time4 = " << time4 << endl;
#endif  // DEBUG_TIME
		if( ( mse ) < 5.0e-4 ) break;
	}

#ifdef  DEBUG
	cerr << "_var:" << endl;
	cerr << _var << endl;
#endif  // DEBUG
	return mse;
}

//
//  LaplacianOptimization::_ConjugateGradient --        optimization
//
//  Inputs
//      none
//
//  Outputs
//      err
//
double LaplacianOptimization::_ConjugateGradient( void ) {

	unsigned int iter = _iteration;
	
	// initialization, prepareBoundary the square matrix
	Eigen::MatrixXd A;
	Eigen::VectorXd b, Ap;
	A = _coef.transpose() * _coef;
	b = _coef.transpose() * _output;

	// initialization
	Eigen::VectorXd err = b - A * _var;
	Eigen::VectorXd p = err;
	double rsold = err.adjoint() * err;

	// main algorithm
	// cerr << "iter = " << iter << endl;
	for( int i = 0; i < iter; i++ ) {

		// cerr << "i = " << i << endl;
		// prepareBoundary the square matrix
		A = _coef.transpose() * _coef;
		b = _coef.transpose() * _output;
		Ap = A * p;

		double alpha = ( double ) ( p.transpose() * err ) / ( double ) ( p.transpose() * Ap );
		_var = _var + alpha * p;
		err = b - A * _var;

		if( sqrt( err.adjoint() * err ) < 1e-10 ) {
			cerr << "sqrterror(" << i << ") = " << sqrt( err.adjoint() * err ) << endl;
			break;
		}
		else {
			double beta = -1.0 * ( double ) ( err.transpose() * Ap ) / ( double ) ( p.transpose() * Ap );
			p = err + beta * p;
		}

		// update
		retrieve();
		_updateCoefs();
		_updateOutputs();
	}

	// cerr << "sqrterror = " << sqrt( err.adjoint() * err ) << endl;
	return sqrt( err.adjoint() * err );
}

//
//  LaplacianOptimization::clear --        memory management
//
//  Inputs
//      none
//
//  Outputs
//      none
//
void LaplacianOptimization::clear( void ) {

}

//------------------------------------------------------------------------------
//	Public functions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//	Destructor
//------------------------------------------------------------------------------
