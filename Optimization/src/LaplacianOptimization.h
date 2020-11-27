//==============================================================================
// LaplacianOptimization.h
//  : header file for the laplacian optimization
//
//==============================================================================

#ifndef _LaplacianOptimization_H        // beginning of header file
#define _LaplacianOptimization_H        // notifying that this file is included

//----------------------------------------------------------------------
//  Including header files
//----------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>

using namespace std;

#include "Common.h"
#include "Config.h"

//------------------------------------------------------------------------------
//	Defining data types
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	Defining macros
//------------------------------------------------------------------------------
class LaplacianOptimization {

private:

protected:
	
	OPTTYPE _optType;
	
	Eigen::VectorXd _var;           // x
	Eigen::VectorXd _output;        // b
	Eigen::MatrixXd _coef;          // A
	
	unsigned int _nVars;
	unsigned int _nConstrs;
	unsigned int _iteration;        // iteration for the optimization
	
	virtual void _initCoefs( void ) = 0;
	
	virtual void _setConstraints( unsigned int &nRows ) = 0;
	
	virtual void _initVars( void ) = 0;
	
	virtual void _setVars( unsigned int &nRows ) = 0;
	
	virtual void _initOutputs( void ) = 0;
	
	virtual void _updateCoefs( void ) = 0;
	
	virtual void _updateOutputs( void ) = 0;
	
	virtual void _init( string confFileName ) = 0;
	
	void _reset( void );

public:
	
	// default constructor
	LaplacianOptimization( void ){ _reset(); }
	// Copy constructor
	LaplacianOptimization( const LaplacianOptimization  &obj ) {;}
	// Destructor
	~LaplacianOptimization( void ) {;}

//------------------------------------------------------------------------------
//  Reference to members
//------------------------------------------------------------------------------
	
	const OPTTYPE &opttype( void ) const { return _optType; }
	
	OPTTYPE &opttype( void ) { return _optType; }

//------------------------------------------------------------------------------
//  Specific functions
//------------------------------------------------------------------------------
	double _LeastSquare( void );

	double _ConjugateGradient( void );

//------------------------------------------------------------------------------
//      Initialization functions
//------------------------------------------------------------------------------
	void prepare( string confFileName ) {
		_init( confFileName );
	}

//------------------------------------------------------------------------------
//  File I/O
//------------------------------------------------------------------------------
	void clear( void );
	
	virtual void retrieve( void ) = 0;

//------------------------------------------------------------------------------
//      I/O
//------------------------------------------------------------------------------
	// Output
	friend ostream &operator<<( ostream &stream, const LaplacianOptimization &obj );
	
	// Input
	friend istream &operator>>( istream &stream, LaplacianOptimization &obj );
	
	// Class name
	virtual const char *className( void ) const { return "LaplacianOptimization"; }
};

#endif // _LaplacianOptimization_H

// end of header file
// Do not add any stuff under this line.
