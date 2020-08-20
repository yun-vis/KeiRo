//******************************************************************************
// Color.h
//	: header file for color schemes
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Jun 19 02:36:37 2019
//
//******************************************************************************

#ifndef _Base_Color_H
#define _Base_Color_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <vector>
#include <iostream>

using namespace std;

#include "Common.h"

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------
#define MAX_COLOR_TYPE      (12)

namespace KeiRo {
namespace Base {

    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class Color {

    private:

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        // initialize color
        virtual void	_init( void );

    protected:

    public:

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        Color( void ) {}
        // copy constructor
        Color( const Color & c ) {}
        // destructor
        ~Color( void ){}

        //------------------------------------------------------------------------------
        //	Assignment operators
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Reference to elements
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        static unsigned long RGBtoHex( int r, int g, int b );
        // select a color scheme
        static void pickMonotoneColor( vector< double > &rgb );
        static void pickPastelColor( unsigned int id, vector< double > &rgb );
        static void pickBrewerColor( unsigned int id, vector< double > &rgb );

        //------------------------------------------------------------------------------
        //	Friend functions
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream &	operator << ( ostream & s, const Color & v );
        // input
        friend istream &	operator >> ( istream & s, Color & v );
        // class name
        virtual const char * className( void ) const { return "Color"; }

    };
	
} // namespace Base
} // namespace KeiRo

#endif // _Base_Color_H