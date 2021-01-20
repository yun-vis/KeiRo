#ifndef _File_MetaData_H
#define _File_MetaData_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <utility>

using namespace std;

#include <QtWidgets/QApplication>
#include <QtXml/QDomDocument>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QRegExp>
#include <QtSvg/QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>
#include <QtGui/QPainterPath>

#ifndef Q_MOC_RUN
#include "Object.h"
#include "Rectangle2.h"
#include "data.h"
#include "svg.h"
#endif // Q_MOC_RUN

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------
namespace FileIO {
	
    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class MetaData : public KeiRo::Base::Object {

    private:
    	
        // data
//        Data< SVG >                 *_dataPtr;
	    vector< vector< SVG* > >       _svgPtr;
	    vector< vector< unique_ptr< SVG > > > uptr;
	    
    protected:

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        void _init( void );

    public:
    
        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        MetaData( void );
        // copy constructor
        MetaData( const MetaData & v );
        // destructor
        virtual ~MetaData( void ) {;}

        //------------------------------------------------------------------------------
        //	Reference to elements
        //------------------------------------------------------------------------------
        vector< vector< SVG* > > 	            svgData( void ) 	    { return _svgPtr; }
	    const vector< vector< SVG* > > 	        svgData( void ) const	{ return _svgPtr; }

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        void init( void ) {
            _init();
        }

        // handle meta data file
        bool readMetaData( const QString filePath, const QString folderName, Grid2 *gridPtr );

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream & operator << ( ostream & stream, const MetaData & obj );
        // input
        friend istream & operator >> ( istream & stream, MetaData & obj );
        // class name
        virtual const char * className( void ) const { return "MetaData"; }

    };
	
} // namespace FileIO

#endif // _File_MetaData_H
