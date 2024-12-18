//******************************************************************************
// Coord2.h
//	: header file for 2D coordinaes
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Jun 19 02:36:37 2012
//
//******************************************************************************

#ifndef	_Coord2_H
#define _Coord2_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <cmath>
#include <iostream>
using namespace std;


//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//	Defining Classes
//------------------------------------------------------------------------------
namespace KeiRo {
namespace Base {

class Coord2 {

  protected:
	
    double		_element[ 2 ];	    // x, y coordinates
    double		_fixedElement[ 2 ];	// x, y coordinates
    double		_oldElement[ 2 ];	// old x, y coordinates
	double		_intermediateElement[ 2 ];	// intermediate x, y coordinates
	bool 		_inLocalMove;			// whether _intermediateElement holds useful information

    virtual void	_init( void );	// initialize all coordinates to zero
    void	    _reset( void );	    // reset all coordinates to initial coordinates

  public:

//------------------------------------------------------------------------------
//	Constructors
//------------------------------------------------------------------------------
    Coord2();				// constructor (default)
    Coord2( const double x, const double y );
					// 2D coordinates as input
    Coord2( const Coord2 & v );		// copy constructor
    virtual ~Coord2() {}		// destructor

//------------------------------------------------------------------------------
//	Assignment operators
//------------------------------------------------------------------------------
    Coord2 &		operator = ( const Coord2 & v );
				// assignment
    Coord2 &		operator += ( const Coord2 & v );
				// addition + assignment
    Coord2 &		operator -= ( const Coord2& v );
				// subtraction + assignment
    Coord2 &		operator *= ( const double d );
				// scalar product + assignment
    Coord2 &		operator /= ( const double d );
				// scalar division + assignment
//------------------------------------------------------------------------------
//	Reference to elements
//------------------------------------------------------------------------------
    void		init( void )		{ _init(); }
    void		zero( void )		{ _init(); }
				// initialze all the coordinates to zero
    void		reset( void )		{ _reset(); }
                // reset all the coordinates to initial coordinatesZ
    const double &	operator [] ( int i ) const;
    double &		operator [] ( int i );
				// reference to a specific coordinate
	const double *	element( void ) const	    { return _element; }
    const double *	fixedElement( void ) const	{ return _fixedElement; }
	const double *	oldElement( void ) const	{ return _oldElement; }
	const double *	intermediateElement( void ) const	{ return _intermediateElement; }
	bool & inLocalMove( void )	 	 	{ return _inLocalMove; }
	const bool & inLocalMove( void ) const 	{ return _inLocalMove; }
				// pointer to an array of coordinates
    double &	x( void ) 	{ return _element[ 0 ]; }
    const double &	x( void ) const	{ return _element[ 0 ]; }
    double &	y( void ) 	{ return _element[ 1 ]; }
    const double &	y( void ) const	{ return _element[ 1 ]; }
    const double &	getX( void ) const	{ return _element[ 0 ]; }
    const double &	getY( void ) const	{ return _element[ 1 ]; }
				// reference to a specific coordinate
    void		set( const double x, const double y );
    void		setX( const double x ) { _element[ 0 ] = x; }
    void		setY( const double y ) { _element[ 1 ] = y; }
				// set the coordinate(s)
    double &	fixedX( void ) 	{ return _fixedElement[ 0 ]; }
    const double &	fixedX( void ) const	{ return _fixedElement[ 0 ]; }
    double &	fixedY( void ) 	{ return _fixedElement[ 1 ]; }
    const double &	fixedY( void ) const	{ return _fixedElement[ 1 ]; }

//------------------------------------------------------------------------------
//	Special functions
//------------------------------------------------------------------------------
    double		norm( void ) const;	// norm
    double		manhattan( void ) const;// manhattan norm
    double		squaredNorm( void ) const;
						// squared norm
    Coord2 &		normalize( void );	// transformed into a unit vector
    Coord2		unit( void ) const;	// return a unit vector
						// without normalization of that vector
	void		updateOldElement( void );
	void		updateIntermediateElement( double x, double y ); //set intermediate element if participating in local move
	void		resetInLocalMove( void ); //reset _inLocalMove to false
	
//------------------------------------------------------------------------------
//	Intersection check
//------------------------------------------------------------------------------
    friend double	crossProd	( const Coord2 & a, const Coord2 & b );
    friend double	doubleArea	( const Coord2 & a, const Coord2 & b, const Coord2 & c );
    friend bool		isCollinear	( const Coord2 & a, const Coord2 & b, const Coord2 & c );
    friend bool		isLeft		( const Coord2 & a, const Coord2 & b, const Coord2 & c );
    friend bool		isCCW		( const Coord2 & a, const Coord2 & b, const Coord2 & c );
    friend bool		isLeftOn	( const Coord2 & a, const Coord2 & b, const Coord2 & c );
    friend bool		isSeparate	( const Coord2 & a, const Coord2 & b,
					  const Coord2 & c, const Coord2 & d );
    friend bool		isIntersected	( const Coord2 & a, const Coord2 & b,
					  const Coord2 & c, const Coord2 & d );
    friend bool		isIntersected	( const Coord2 & a, const Coord2 & b,
					  const Coord2 & c, const Coord2 & d,
					  Coord2 & intersection );
    friend bool		doConflict	( const Coord2 & a, const Coord2 & b,
					  const Coord2 & c, const Coord2 & d );

    friend double	distanceBetween	( const Coord2 & a, const Coord2 & b ) {
	return ( ( a - b ).norm() );
    }

//------------------------------------------------------------------------------
//	Friend functions
//------------------------------------------------------------------------------
    friend Coord2	operator - ( const Coord2 & v );
				// sign change
    friend Coord2	operator + ( const Coord2 & a, const Coord2 & b );
				// addition
    friend Coord2	operator - ( const Coord2 & a, const Coord2 & b );
				// subtraction
    friend Coord2	operator * ( const double d, const Coord2 & a );
				// scalar product
    friend double	operator * ( const Coord2 & a, const Coord2 & b );
				// inner product
    friend Coord2	operator / ( const Coord2 & a, const double d );
				// scalar division

    friend int		operator == ( const Coord2 & a, const Coord2 & b );
				// equivalence
    friend int		operator != ( const Coord2 & a, const Coord2 & b ) {
	return ( ! ( a == b ) );
    }				// inequivalence
    friend int		operator < ( const Coord2 & a, const Coord2 & b );
				// comparison (less than)
    friend int		operator > ( const Coord2 & a, const Coord2 & b );
				// comparison (more than)
    friend int		operator <= ( const Coord2 & a, const Coord2 & b ) {
	return ( ( a == b ) || ( a < b ) );
    }				// comparison (equal to or less than)
    friend int		operator >= ( const Coord2 & a, const Coord2 & b ) {
	return ( ( a == b ) || ( a > b ) );
    }				// comparison (equal to or more than)


//------------------------------------------------------------------------------
//	I/O functions
//------------------------------------------------------------------------------
    friend ostream &	operator << ( ostream & s, const Coord2 & v );
				// $B=PNO(B
    friend istream &	operator >> ( istream & s, Coord2 & v );
				// $BF~NO(B
    virtual const char * className( void ) const { return "Coord2"; }
				// $B%/%i%9L>(B

};
} // namespace Base
} // namespace KeiRo

#endif // _Coord2_H
