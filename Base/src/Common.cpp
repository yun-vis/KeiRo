//******************************************************************************
// Config.cpp
//	: program file for system configuration
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sun Aug 16 15:02:45 2020
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include "Common.h"

using namespace std;

namespace KeiRo {
namespace Base {
	
	double Common::_mainwidget_width = 800;
	double Common::_mainwidget_height = 600;
	double Common::_maincontent_width = 800;
	double Common::_maincontent_height = 600;
	double Common::_dockwidget_width = 60;
	double Common::_menubar_height = 60;
	unsigned int Common::_font_size = 12;
	string Common::_batch_str = "0";
	
	//------------------------------------------------------------------------------
	//	Private Functions
	//------------------------------------------------------------------------------
	
	//------------------------------------------------------------------------------
	//	Protected Functions
	//------------------------------------------------------------------------------
	
	//------------------------------------------------------------------------------
	//	Public functions
	//------------------------------------------------------------------------------
	//  Common::_stringToDouble -- convert string to double
	//
	//  Inputs
	//      string
	//
	//  Outputs
	//  double
	//
	double Common::stringToDouble( const std::string str )
	{
		stringstream ss( str );
		double val = 0;
		ss >> val;
		
		return val;
	}
	
	
	const double &Common::getMainwidgetWidth() {
		return _mainwidget_width;
	}
	
	void Common::setMainwidgetWidth( double mainwidgetWidth ) {
		_mainwidget_width = mainwidgetWidth;
	}
	
	double & Common::mainwidgetWidth( void ) {
		return _mainwidget_width;
	}
	
	const double &Common::getMainwidgetHeight() {
		return _mainwidget_height;
	}
	
	void Common::setMainwidgetHeight( double mainwidgetHeight ) {
		_mainwidget_height = mainwidgetHeight;
	}
	
	double & Common::mainwidgetHeight( void ) {
		return _mainwidget_height;
	}
	
	const double &Common::getMaincontentWidth() {
		return _maincontent_width;
	}
	
	void Common::setMaincontentWidth( double maincontentWidth ) {
		_maincontent_width = maincontentWidth;
	}
	
	double & Common::maincontentWidth( void ) {
		return _maincontent_width;
	}
	
	const double &Common::getMaincontentHeight() {
		return _maincontent_height;
	}
	
	void Common::setMaincontentHeight( double maincontentHeight ) {
		_maincontent_height = maincontentHeight;
	}
	
	double & Common::maincontentHeight( void ) {
		return _maincontent_height;
	}
	
	const double Common::getDockWidgetWidth() {
		return _dockwidget_width;
	}
	
	void Common::setDockWidgetWidth( double dockwidgetWidth ) {
		_dockwidget_width = dockwidgetWidth;
	}
	
	const double Common::getMenubarHeight() {
		return _menubar_height;
	}
	
	void Common::setMenubarHeight( double menubarHeight ) {
		_menubar_height = menubarHeight;
	}
	
	const unsigned int Common::getFontSize() {
		return _font_size;
	}
	
	void Common::setFontSize( unsigned int fontSize ) {
		_font_size = fontSize;
	}
	
	const std::string &Common::getBatchStr( void ) {
		return _batch_str;
	}
	
	void Common::setBatchStr( const std::string &batchStr ) {
		_batch_str = batchStr;
	}
	
} // namespace Base
} // namespace KeiRo
