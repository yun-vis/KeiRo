//******************************************************************************
// Object.h
//	: header file for object schemes
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Jun 19 02:36:37 2019
//
//******************************************************************************

#ifndef _Base_Object_H
#define _Base_Object_H

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
namespace KeiRo {
namespace Base {
	
    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class Object {

    private:

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------

    protected:

        unsigned int            _id;
        unsigned int            _gid;
        string                  _name;
        Base::Common::IDPair    _parentFileID;
        unsigned int            _parentPolygonID;
        // string                  _parent;
        bool                    _isVisible;

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        virtual void	    _init( void );
        virtual void        _clear( void ) {}

    public:

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        Object( void );
        // copy constructor
        Object( const Object & c );
        // destructor
        ~Object( void ){}

        //------------------------------------------------------------------------------
        //	Assignment operators
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Reference to elements
        //------------------------------------------------------------------------------
        // id
        unsigned int &	            id( void )	            { return _id; }
        const unsigned int &	    id( void ) const	    { return _id; }
        // group id
        unsigned int &	            gid( void )	            { return _gid; }
        const unsigned int &	    gid( void ) const	    { return _gid; }
        // name
        string &	                name( void )	        { return _name; }
        const string &	            name( void ) const	    { return _name; }

        // parent file id
        Base::Common::IDPair &	        parentFileID( void )	        { return _parentFileID; }
        const Base::Common::IDPair &    parentFileID( void ) const	    { return _parentFileID; }

        // parent polygon id
        unsigned int &	                parentPolygonID( void )	        { return _parentPolygonID; }
        const unsigned int &	        parentPolygonID( void ) const	{ return _parentPolygonID; }

        // parent name
        // string &	                parent( void )	        { return _parent; }
        //const string &	            parent( void ) const	{ return _parent; }
        // is visible
        bool &	                    isVisible( void )       { return _isVisible; }
        const bool &	            isVisible( void ) const { return _isVisible; }

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Friend functions
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream &	operator << ( ostream & s, const Object & v );
        // input
        friend istream &	operator >> ( istream & s, Object & v );
        // class name
        virtual const char * className( void ) const { return "Object"; }

    };

} // namespace Base
} // namespace KeiRo

#endif // _Base_Object_H