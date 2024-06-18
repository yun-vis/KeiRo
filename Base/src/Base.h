#ifndef _Base_H
#define _Base_H

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

namespace KeiRo {
namespace Base {

class Base
{
	//------------------------------------------------------------------------------
	//  Defining Classes
	//------------------------------------------------------------------------------
	
private:

protected:

public:
	
	//------------------------------------------------------------------------------
	//      Constructors & Destructors
	//------------------------------------------------------------------------------
	// default constructor
	Base( void ) {}
	// copy constructor
	Base( const Base & v ) {}
	// destructor
	virtual ~Base( void ) {}
	
	//------------------------------------------------------------------------------
	//      Special functions
	//------------------------------------------------------------------------------
	virtual void init( void ) = 0;
	virtual void run( void ) = 0;
	
	//------------------------------------------------------------------------------
	//      I/O functions
	//------------------------------------------------------------------------------
	// output
	friend ostream & operator << ( ostream & stream, const Base & obj );
	// input
	friend istream & operator >> ( istream & stream, Base & obj );
	// class name
	virtual const char * className( void ) const { return "Base"; }
};

} // namespace Base
} // namespace KeiRo

#endif // _Base_H
