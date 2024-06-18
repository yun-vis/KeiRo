//******************************************************************************
// GraphicsBase.h
//	: header file for base items
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: The Dec 20 10:48:37 2020
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include "GraphicsBase.h"

namespace Ui {
namespace Vector {
	//------------------------------------------------------------------------------
	//	Private functions
	//------------------------------------------------------------------------------
	
	//------------------------------------------------------------------------------
	//	Protected functions
	//------------------------------------------------------------------------------
	//
	//  GraphicsBase::_init -- initialization
	//
	//  Inputs
	//  none
	//
	//  Outputs
	//  none
	//
	void GraphicsBase::_init( void ) {

		_id             = 0;
		_weight         = 1.0;
		_name           = "NULL";

		_text           = "NULL";
		_textOn         = false;
		_font           = QFont( "Arial", 12, QFont::Normal, false );
		_textpen        = QPen( QColor( 100, 100, 100, 255 ), 3 );
	}
	
	//------------------------------------------------------------------------------
	//	Public functions
	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	//	Constructors & Destructors
	//------------------------------------------------------------------------------
	//
	//  GraphicsBase::GraphicsBase -- copy constructor
	//
	//  Inputs
	//  parent: parent object
	//
	//  Outputs
	//  none
	//
	GraphicsBase::GraphicsBase( GraphicsBase &o ) {
		
		_id             = o._id;
		_weight         = o._weight;
		_name           = o._name;

		_text           = o._text;
		_textOn         = o._textOn;
		_font           = o._font;
		_textpen        = o._textpen;
	}
	
}
} // namespace Ui
