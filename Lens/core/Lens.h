#ifndef _Lens_H
#define _Lens_H

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

#include "Base.h"

class Lens : public Base
{
	//------------------------------------------------------------------------------
	//  Defining Classes
	//------------------------------------------------------------------------------
	
private:
	int id;
protected:

public:
	
	//------------------------------------------------------------------------------
	//      Constructors & Destructors
	//------------------------------------------------------------------------------
	// default constructor
	Lens( void ) {}
	// copy constructor
	Lens( const Lens & v ) {}
	// destructor
	virtual ~Lens( void ) {}
	
	//------------------------------------------------------------------------------
	//      Special functions
	//------------------------------------------------------------------------------
	void init( void ) override;
	void run( void ) override;
	
	//------------------------------------------------------------------------------
	//      Reference to elements
	//------------------------------------------------------------------------------
	
	//------------------------------------------------------------------------------
	//      I/O functions
	//------------------------------------------------------------------------------
	// output
	friend ostream & operator << ( ostream & stream, const Lens & obj );
	// input
	friend istream & operator >> ( istream & stream, Lens & obj );
	// class name
	virtual const char * className( void ) const { return "Lens"; }
};

#endif // _Lens_H
