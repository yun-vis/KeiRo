//******************************************************************************
// GraphicsBase.h
//	: header file for base items
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: The Dec 20 10:48:37 2020
//
//******************************************************************************

#ifndef Ui_Vector_GraphicsBase_H
#define Ui_Vector_GraphicsBase_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <QtGui/QPainter>
#include <QtCore/QString>
#include <QtCore/QDebug>

#ifndef Q_MOC_RUN
#endif // Q_MOC_RUN

namespace Ui {
namespace Vector {
	
	//------------------------------------------------------------------------------
	//	Class definition
	//------------------------------------------------------------------------------
	class GraphicsBase {

	private:
	
	protected:
		
		// graphics item
		unsigned int    _id;
		double          _weight;
		QString         _name;          // object name
		
		// associated text
		QString         _text;          // shown object name, usually a acronym of _name
		bool            _textOn;
		QFont           _font;
		QPen            _textpen;
		
		//------------------------------------------------------------------------------
		//	Special functions
		//------------------------------------------------------------------------------
		void            _init( void );
		
	public:
		
		//------------------------------------------------------------------------------
		//	Constructors & Destructors
		//------------------------------------------------------------------------------
		// default constructor
		explicit GraphicsBase( void ) {
			_init();
		}
		
		// parameterized constructor
		
		// copy constructor
		explicit GraphicsBase( GraphicsBase &o );
		
		// destructor
		~GraphicsBase( void ) {}
		
		//------------------------------------------------------------------------------
		//      Reference to elements
		//------------------------------------------------------------------------------
		unsigned int &id( void ) { return _id; }
		
		const unsigned int &id( void ) const { return _id; }
		
		double &weight( void ) { return _weight; }

		const double &weight( void ) const { return _weight; }
		
		QString &name( void ) { return _name; }
		
		const QString &name( void ) const { return _name; }
		
		QString &text( void ) { return _text; }
		
		const QString &text( void ) const { return _text; }
		
		bool &textOn( void ) { return _textOn; }
		
		const bool &textOn( void ) const { return _textOn; }
		
		QFont &font( void ) { return _font; }
		
		const QFont &font( void ) const { return _font; }
		
		QPen &textpen( void ) { return _textpen; }
		
		const QPen &textpen( void ) const { return _textpen; }
		
		//------------------------------------------------------------------------------
		//	Special functions
		//------------------------------------------------------------------------------
		void init( void ) { _init(); }
		
	};
}
} // namespace Ui

#endif // Ui_Vector_GraphicsBase_H
