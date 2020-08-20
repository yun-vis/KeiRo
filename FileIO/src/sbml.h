#ifndef _File_SBML_H
#define _File_SBML_H

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

#include <sbml/SBMLTypes.h>
#include <sbml/xml/XMLNode.h>

//LIBSBML_CPP_NAMESPACE_USE

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

namespace FileIO {

    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class SBML
    {
    private:

        SBMLDocument *sbmlDocPtr;
        string _current_path;
        int _width, _height;

    protected:

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        void _init( int __width, int __height );

    public:

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        SBML( void );
        // copy constructor
        SBML( const SBML & v );
        // destructor
        virtual ~SBML( void ) {}

        //------------------------------------------------------------------------------
        //	Reference to elements
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        void init( int __width, int __height ) {
            _init( __width, __height );
        }
/*
    string _current_path;
    SBMLDocument *sbmlDocPtr;
    int _width, _height;

protected:

public:

    BioNetSBML();                     // default constructor
    BioNetSBML( const BioNetSBML & obj );   // Copy constructor
    virtual ~BioNetSBML();            // Destructor

//------------------------------------------------------------------------------
//  	Specific functions
//------------------------------------------------------------------------------
    void init( string __current_path, int __width, int __height ) {
        _current_path = __current_path;
        _width = __width;
        _height = __height;
    }
    void buildSBML( string fileName );
    void buildSBMLModel( string fileName, Model* modelPtr );
    void buildSBMLDefinition( string fileName, Model* modelPtr );

    void printNotes( SBase *sb, const string& id = "" );
    void printAnnotation(SBase *sb, const string& id = "" );
    void getCDMetabolite( SBase *sb, const string& id = "" );
    void getSBMLMetabolite( Model *model, const string& id = "" );
    void getCDReaction( Model *model, const string& id = "" );
    void exportMetaType( void );

    int readBioNetSBSML( string fileName );
    bool writeBioNetSBML( string fileName );
*/

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream & operator << ( ostream & stream, const SBML & obj );
        // input
        friend istream & operator >> ( istream & stream, SBML & obj );
        // class name
        virtual const char * className( void ) const { return "SBML"; }

    };
    
} // namespace FileIO


#endif // _File_SBML_H
