//******************************************************************************
// Line2.cpp
//	: program file for 2D Line2 coordinates
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Dec 27 23:15:32 2011
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

#include "Line2.h"

namespace KeiRo {
namespace Base {
		

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------
    //
    //  Line2::init -- initialization
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void Line2::_init( void )
    {
        _clear();
    }

    //
    //  Polygon2::_clear --	clear elements
    //
    //  Inputs
    //
    //
    //  Outputs
    //  none
    //
    void Line2::_clear( void )
    {
        _elements.clear();
        _fixedElements.clear();
        _idElements.clear();
    }

    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  Line2::Line2 -- default constructor
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    Line2::Line2()
    {
        _init();
	
//	    _stroke.resize( 4 );
//	    _stroke[0] = _stroke[1] = _stroke[2] = 0;
//	    _stroke[3] = 255;
//	    _strokeWidth = 1.0;
//	    _strokeOpacity = 1.0;
//
//	    _fill.resize( 4 );
//	    _fill[0] = _fill[1] = _fill[2] = 100;
//	    _fill[3] = 255;
//	    _fillOpacity = 1.0;

//        _stroke.resize( 4 );
//        _stroke[0] = _stroke[1] = _stroke[2] = 0;
//        _stroke[3] = 255;
//        _fill.resize( 4 );
//        _fill[0] = _fill[1] = _fill[2] = _fill[3] = 0;
        //Object::Object();
    }

    //
    //  Line2::Line2 -- parameterized constructor
    //
    //  Inputs
    //  __elements
    //
    //  Outputs
    //  none
    //
    Line2::Line2( vector< Coord2 > __elements )
    {
        _elements           = __elements;
	    _oldElements        = _elements;
        _fixedElements      = _elements;
		
        _idElements.clear();
    }

    //
    //  Polygon2::Polygon2 -- copy constructor
    //
    //  Inputs
    //  polygon
    //
    //  Outputs
    //  none
    //
    Line2::Line2( const Line2 & v )
    {
        _id                 = v._id;
        _gid                = v._gid;
        _name               = v._name;
        _elements           = v._elements;
	    _oldElements        = v._oldElements;
        _fixedElements      = v._fixedElements;
        _idElements         = v._idElements;
        _isSelected         = v._isSelected;
		_fineElements       = v._fineElements;
		_elementPointers    = v._elementPointers;
		
	    _stroke             = v._stroke;
	    _strokeWidth        = v._strokeWidth;
	    _strokeOpacity      = v._strokeOpacity;

	    _fill               = v._fill;
	    _fillOpacity        = v._fillOpacity;
    }

    //------------------------------------------------------------------------------
    //	Assignment operators
    //------------------------------------------------------------------------------


    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    void Line2::addSample( Coord2 & coord )
    {
        _elements.push_back( coord );
    }


    //
    //  Line2::isOnLine --        check if point a lies on line segment [b,c]
    //
    //  Inputs
    //      Coord2 &a, &b, &c
    //
    //  Outputs
    //      bool
    //
    bool Line2::isOnLine( Coord2 &a, Coord2 &b, Coord2 &c )
    {
        bool isOnLine = false;

        Coord2 ab = b - a;
        Coord2 ac = c - a;

        double cross = ab.x() * ac.y() - ab.y() * ac.x();
        if( fabs( cross ) < 0.01 ) {

            if ( ( MIN2( b.x(), c.x() ) <= a.x() ) && ( a.x() <= MAX2( b.x(), c.x() ) ) &&
                 ( MIN2( b.y(), c.y() ) <= a.y() ) && ( a.y() <= MAX2( b.y(), c.y() ) ) )
                isOnLine = true;
        }

        return isOnLine;
    }


    void Line2::_initChaikinCurve( double unit = 100 )
    {
        // initialization
        _fineElements.clear();

        // store initial the path
        vector< Coord2 > &elements = _elements;

        cerr << "sample.size() = " << elements.size() << endl;
        if( elements.size() > 0 )
            _fineElements.push_back( elements[0] );
        for( unsigned int j = 1; j < elements.size(); j++ ){

            Coord2 diff = ( elements[ j%elements.size() ]- elements[ j-1 ] );
            // cerr << "dist = " << diff.norm() << endl;
            if( diff.norm() > unit ) {

                int num = floor( diff.norm()/unit );
                double interval = diff.norm()/(double)num;

                for( int k = 1; k < num; k++ ){

                    Coord2 c = elements[j-1] + (double)k * interval * diff / diff.norm();
                    _fineElements.push_back( c );
                }
            }
            _fineElements.push_back( elements[ j ] );
        }

    #ifdef DEBUG
        cerr << "fineP = ";
        for( unsigned int i = 0; i < _fineElements.size(); i++ ){
            cerr << "( " << _fineElements[i].x() << ", " << _fineElements[i].y() << ") ";
        }
        cerr << endl;
    #endif // DEBUG
    }

    void Line2::computeChaikinCurve( int num = 5, double unit = 100 )
    {
        _initChaikinCurve( unit );

        double interval = 4.0;
        for( int k = 0; k < num; k++ ){

            vector< Coord2 > core = _fineElements;

            // compute Chaikin Curve
            _fineElements.clear();
            _fineElements.push_back( core[0] );
            for( unsigned int j = 0; j < core.size()-1; j++ ){

                Coord2 &p1 = core[j];
                Coord2 &p2 = core[(j+1)%core.size()];
                Coord2 q = (1.0-1.0/interval)*p1 + (1.0/interval)*p2;
                Coord2 r = (1.0/interval)*p1 + (1.0-1.0/interval)*p2;

                _fineElements.push_back( q );
                _fineElements.push_back( r );
            }
            _fineElements.push_back( core[core.size()-1] );
        }
    }
    
	void Line2::simplifyGeometry( void )
	{
		vector< Coord2 >        simpleElements;
		if( _elements.size() > 0 ) simpleElements.push_back( _elements[0] );

		for( unsigned int i = 1; i < _elements.size()-1; i++ ){
			Coord2 pred = _elements[i-1];
			Coord2 curr = _elements[i];
			Coord2 succ = _elements[i+1];
			Coord2 diff1 = curr - pred;
			Coord2 diff2 = succ - curr;
#ifdef DEBUG
			cerr << "pred = " << pred;
			cerr << "curr = " << curr;
			cerr << "succ = " << succ;
#endif // DEBUG
			if( fabs( diff1.x()*diff2.y() - diff1.y()*diff2.x() ) > 1e-5 ){
				// not colinear
				//cerr << "fabs( diff1.x()*diff2.y() - diff1.y()*diff2.x() ) = " << fabs( diff1.x()*diff2.y() - diff1.y()*diff2.x() ) << endl;
				simpleElements.push_back( curr );
			}
		}
		if( _elements.size() > 1 ) simpleElements.push_back( _elements[_elements.size()-1] );
#ifdef DEBUG
		for( unsigned int i = 0; i < simpleElements.size(); i++ ) {
			cerr << simpleElements[i];
		}
		cerr << endl;
#endif // DEBUG
		_fixedElements = _oldElements = _elements = simpleElements;
	}
	
	void Line2::initElementPointers( void )
	{
    	_elementPointers.resize( _elements.size() );
    	for( unsigned int i = 0; i < _elements.size(); i++ ){
    		_elementPointers[ i ] = &_elements[ i ];
	    }
	}
	
	void Line2::updateOldElement( void )
	{
		_oldElements = _elements;
	}
	
	
	void Line2::updateOldElementByPointers( void )
	{
    	for( unsigned int i = 0; i < _elements.size(); i++ ){
		    _oldElements[i] = *_elementPointers[i];
    	}
	}
	
    //------------------------------------------------------------------------------
    //	Friend functions
    //------------------------------------------------------------------------------


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
    ostream & operator << ( ostream & stream, const Line2 & obj )
    {
        // set the output formatting
        stream << setiosflags( ios::showpoint );
        stream << setprecision( 8 );

        int width = 8;
        // print out the elements
        for ( unsigned int i = 0; i < obj.elements().size(); i++ ) {
            stream << setw( width ) << "(" << obj.elements()[i].x() << ", " << obj.elements()[i].y() << ") ";
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
    istream & operator >> ( istream & stream, Line2 & obj )
    {
        return stream;
    }


} // namespace Base
} // namespace KeiRo
