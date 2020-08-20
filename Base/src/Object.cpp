//******************************************************************************
// Object.cpp
//	: program file for object
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sun Mar 9 6:02:45 2019
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include "Object.h"
#include "Common.h"

namespace KeiRo {
namespace Base {

    //------------------------------------------------------------------------------
    //	Private Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------
    //
    //  Polygon2::_init --	initialization
    //
    //  Inputs
    //  __elements
    //
    //  Outputs
    //  none
    //
    void Object::_init( void )
    {
        _clear();

        _id             = 0;
        _gid            = 0;
        _name           = "unkown";
        _isVisible      = true;
        _parentFileID.first = _parentFileID.second = 0;
        _parentPolygonID = 0;
    }

    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------
    //
    //  Object::Object -- default constructor
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    Object::Object()
    {
        _init();
    }

    //
    //  Object::Object -- copy constructor
    //
    //  Inputs
    //  object
    //
    //  Outputs
    //  none
    //
    Object::Object( const Object & c )
    {
        _id                     = c._id;
        _gid                    = c._gid;
        _name                   = c._name;
        _isVisible              = c._isVisible;
        _parentFileID.first     = c._parentFileID.first;
        _parentFileID.second    = c._parentFileID.second;
        _parentPolygonID        = c._parentPolygonID;
    }
	
} // namespace Base
} // namespace KeiRo
