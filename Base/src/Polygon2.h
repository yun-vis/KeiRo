//******************************************************************************
// Polygon2.h
//	: header file for 2D polygons
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Mon Feb 10 20:13:35 2020
//
//******************************************************************************

#ifndef	_Base_Polygon2_H
#define _Base_Polygon2_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

#define CGAL_DO_NOT_USE_BOOST_MP

#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>

typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef CGAL::Polygon_2< K >::Vertex_circulator Vertex_circulator;

using CGAL::ORIGIN;

#include "Object.h"
#include "Rectangle2.h"
#include "Coord2.h"
#include "Line2.h"
//#include "GraphicsPolygonItem.h"

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

namespace KeiRo {
namespace Base {

    //------------------------------------------------------------------------------
    //	Defining Classes
    //------------------------------------------------------------------------------
    class Polygon2 : public KeiRo::Base::Object {

    private:

    protected:

        double              _area;          // polygon area size
        Coord2              _center;        // average of the elements
        Coord2              _centroid;      // centroid of the elements
        //Polygon2 original coordinates of end points

        vector< KeiRo::Base::Coord2 >       _fixedElements;
        // Polygon2 sample points
        vector< KeiRo::Base::Coord2 >       _elements;
        // Polygon2 sample id
        vector< unsigned int >              _idElements;
        vector< double >                    _targetEdgeAngles;
	
        // width and height of the bounding box
//        KeiRo::Base::Rectangle2             _oldBoundingBox;
        KeiRo::Base::Rectangle2             _boundingBox;
        // initial bounding box size
        double                              _initArea;

        //------------------------------------------------------------------------------
        //	Attribute
        //------------------------------------------------------------------------------
        // select flag
        bool                    _isSelected;

        // graphics item pointer
//        Ui::Vector::GraphicsPolygonItem * _itemPtr;

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        virtual void	        _init( unsigned int __id, vector< KeiRo::Base::Coord2 > __elements );	// initialize all coordinates to zero
        void                    _init( void ) {}
        void                    _clear( void );

    public:

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        Polygon2();
        // parameterized constructor
        Polygon2( vector< KeiRo::Base::Coord2 > __elements );
        // copy constructor
        Polygon2( const Polygon2 & v );
        // destructor
        virtual ~Polygon2() {}

        //------------------------------------------------------------------------------
        //	Assignment operators
        //------------------------------------------------------------------------------
        // assignment
        Polygon2 &		operator = ( const Polygon2 & p );

        //------------------------------------------------------------------------------
        //	Reference to elements
        //------------------------------------------------------------------------------
        // area
        double &	                area( void )	        { return _area; }
        const double &	            area( void ) const	    { return _area; }

        // barycenter
        Coord2 &	                center( void )	        { return _center; }
        const Coord2 &	            center( void ) const	{ return _center; }

        // centroid
        Coord2 &	                centroid( void )	    { return _centroid; }
        const Coord2 &	            centroid( void ) const	{ return _centroid; }

        // reference to a vector of coordinates
        vector< KeiRo::Base::Coord2 > &	            elements( void )	            { return _elements; }
        const vector< KeiRo::Base::Coord2 > &	    elements( void ) const	        { return _elements; }

        // reference to an array of fixed coordinates
        vector< KeiRo::Base::Coord2 > &	            fixedElements( void )	        { return _fixedElements; }
        const vector< KeiRo::Base::Coord2 > &	    fixedElements( void ) const	    { return _fixedElements; }

        // reference to an array of coordinate pointers
        vector< unsigned int > &	    idElements( void )	            { return _idElements; }
        const vector< unsigned int > &  idElements( void ) const        { return _idElements; }

        // reference to an array of coordinate pointers
        vector< double > &	            targetEdgeAngles( void )	    { return _targetEdgeAngles; }
        const vector< double > &        targetEdgeAngles( void ) const  { return _targetEdgeAngles; }
	
	    // bounding box
//	    KeiRo::Base::Rectangle2 &	        oldBoundingBox( void )	        { return _oldBoundingBox; }
//	    const KeiRo::Base::Rectangle2 &	    oldBoundingBox( void ) const	{ return _oldBoundingBox; }
	
	    // bounding box
        KeiRo::Base::Rectangle2 &	        boundingBox( void )	            { return _boundingBox; }
        const KeiRo::Base::Rectangle2 &	    boundingBox( void ) const	    { return _boundingBox; }

        const double 	                bbArea( void ) const	        { return _boundingBox.width() * _boundingBox.height(); }
        const double &	                initArea( void ) const	        { return _initArea; }

        // select flag
        bool &	                        isSelected( void )	            { return _isSelected; }
        const bool &	                isSelected( void ) const	    { return _isSelected; }
        
	    // graphics item
//        void setItemPtr( Ui::Vector::GraphicsPolygonItem * ptr )	    { _itemPtr = ptr; }
//        Ui::Vector::GraphicsPolygonItem * getItemPtr( void )            { return _itemPtr; }

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        // initialization
        void init( unsigned int __id, vector< KeiRo::Base::Coord2 > __elements ) {
            _init( __id, __elements );
        }
	    void update( void ) {
		    computeBoundingBox();
		    computeCenter();
        }
        // clear the object
        void clear( void ) { _clear(); }

        void computeBoundingBox( void );
	    void computeCenter( void );
        void updateCentroid( void );
        void updateOrientation( void );
        bool inPolygon( const KeiRo::Base::Coord2 &cood );
        double minDistToPolygon( const KeiRo::Base::Coord2 &cood );
        double maxRadiusInPolygon( const KeiRo::Base::Coord2 &coord );
	    bool isSimple( void );
	    void cleanPolygon( void );
	    void normalization( Rectangle2 &r );

        //------------------------------------------------------------------------------
        //	Friend functions
        //------------------------------------------------------------------------------

        //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream &	operator << ( ostream & s, const Polygon2 & v );
        // input
        friend istream &	operator >> ( istream & s, Polygon2 & v );
        // class name
        virtual const char * className( void ) const { return "Polygon2"; }

    };

} // namespace Base
} // namespace KeiRo

#endif // _Base_Polygon2_H
