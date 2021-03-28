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
        _name           = "unknown";
        _label          = "unknown";
        _isVisible          = true;
	    _isTextVisible      = true;
        _parentFileID.first = _parentFileID.second = 0;
        _parentPolygonID = 0;
	
	    _stroke.resize( 4 );
	    _stroke[0] = _stroke[1] = _stroke[2] = 0;
	    _stroke[3] = 255;
	    _strokeWidth = 1.0;
	    _strokeOpacity = 1.0;
	    
	    _fill.resize( 4 );
	    _fill[0] = _fill[1] = _fill[2] = 100;
	    _fill[3] = 255;
	    _fillOpacity = 1.0;
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
    Object::Object( const Object & v )
    {
        _id                     = v._id;
        _gid                    = v._gid;
        _name                   = v._name;
	    _label                  = v._label;
        _isVisible              = v._isVisible;
	    _isTextVisible          = v._isTextVisible;
        _parentFileID.first     = v._parentFileID.first;
        _parentFileID.second    = v._parentFileID.second;
        _parentPolygonID        = v._parentPolygonID;
	
	    _stroke                 = v._stroke;
	    _strokeWidth            = v._strokeWidth;
	    _strokeOpacity          = v._strokeOpacity;
	
	    _fill                   = v._fill;
	    _fillOpacity            = v._fillOpacity;
    }
	
} // namespace Base
} // namespace KeiRo
