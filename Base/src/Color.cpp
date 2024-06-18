//******************************************************************************
// Color.cpp
//	: program file for color schemes
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Sun Sep 16 15:02:45 2019
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------

#include "Color.h"


namespace KeiRo {
namespace Base {

    //------------------------------------------------------------------------------
    //	Private Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Protected Functions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------
    //
    //  Color::RGBtoHex --	convert RGB to HEX
    //
    //  Inputs
    //	r, g, b: color values
    //
    //  Outputs
    //	unsigned long
    //
    unsigned long Color::RGBtoHex( int r, int g, int b )
    {
        return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
    }

    //
    //  Color::pickMonotoneColor --	convert id to RGB color
    //
    //  Inputs
    //	id: id
    //  rgb: color
    //
    //  Outputs
    //	none
    //
    void Color::pickMonotoneColor( vector< double > &rgb )
    {
        rgb.resize( 3 );

        if ( true ){
            // gray
            rgb[ 0 ] = 217.0;
            rgb[ 1 ] = 217.0;
            rgb[ 2 ] = 217.0;
        }
        else {
            // blue
            rgb[ 0 ] = 198.0;
            rgb[ 1 ] = 219.0;
            rgb[ 2 ] = 239.0;
        }
    }

    //
    //  Color::pickPastelColor --	convert id to RGB color
    //
    //  Inputs
    //	id: id
    //  rgb: color
    //
    //  Outputs
    //	none
    //
    void Color::pickPastelColor( unsigned int id, vector< double > &rgb )
    {
        int index = id % MAX_COLOR_TYPE;
        int shift = -2*( id / MAX_COLOR_TYPE );

        rgb.resize( 3 );

        switch( index ){
            case 0:
                rgb[ 0 ] = MIN2( 255, shift+169 );
                rgb[ 1 ] = MIN2( 255, shift+207 );
                rgb[ 2 ] = MIN2( 255, shift+244 );
                break;
            case 1:
                rgb[ 0 ] = MIN2( 255, shift+255 );
                rgb[ 1 ] = MIN2( 255, shift+235 );
                rgb[ 2 ] = MIN2( 255, shift+176 );
                break;
            case 2:
                rgb[ 0 ] = MIN2( 255, shift+255 );
                rgb[ 1 ] = MIN2( 255, shift+211 );
                rgb[ 2 ] = MIN2( 255, shift+247 );
                break;
            case 3:
                rgb[ 0 ] = MIN2( 255, shift+219 );
                rgb[ 1 ] = MIN2( 255, shift+231 );
                rgb[ 2 ] = MIN2( 255, shift+155 );
                break;
            case 4:
                rgb[ 0 ] = MIN2( 255, shift+236 );
                rgb[ 1 ] = MIN2( 255, shift+236 );
                rgb[ 2 ] = MIN2( 255, shift+236 );
                break;
            case 5:
                rgb[ 0 ] = MIN2( 255, shift+138 );
                rgb[ 1 ] = MIN2( 255, shift+214 );
                rgb[ 2 ] = MIN2( 255, shift+237 );
                break;
            case 6:
                rgb[ 0 ] = MIN2( 255, shift+254 );
                rgb[ 1 ] = MIN2( 255, shift+212 );
                rgb[ 2 ] = MIN2( 255, shift+190 );
                break;
            case 7:
                rgb[ 0 ] = MIN2( 255, shift+233 );
                rgb[ 1 ] = MIN2( 255, shift+212 );
                rgb[ 2 ] = MIN2( 255, shift+241 );
                break;
            case 8:
                rgb[ 0 ] = MIN2( 255, shift+254 );
                rgb[ 1 ] = MIN2( 255, shift+244 );
                rgb[ 2 ] = MIN2( 255, shift+217 );
                break;
            case 9:
                rgb[ 0 ] = MIN2( 255, shift+251 );
                rgb[ 1 ] = MIN2( 255, shift+220 );
                rgb[ 2 ] = MIN2( 255, shift+226 );
                break;
            case 10:
                rgb[ 0 ] = MIN2( 255, shift+162 );
                rgb[ 1 ] = MIN2( 255, shift+232 );
                rgb[ 2 ] = MIN2( 255, shift+172 );
                break;
            case 11:
                rgb[ 0 ] = MIN2( 255, shift+256 );
                rgb[ 1 ] = MIN2( 255, shift+183 );
                rgb[ 2 ] = MIN2( 255, shift+174 );
                break;
            default:
                cerr << "sth is wrong here" << endl;
                break;
        }
    }

    //
    //  Color::pickBrewerColor --	convert id to RGB color
    //
    //  Inputs
    //	id: id
    //  rgb: color
    //
    //  Outputs
    //	none
    //
    void Color::pickBrewerColor( unsigned int id, vector< double > &rgb )
    {
        int index = id % MAX_COLOR_TYPE;
        int shift = -2*(id / MAX_COLOR_TYPE );

        rgb.resize( 3 );

        switch( index ){
            case 0:
                rgb[ 0 ] = MIN2( 255,  shift+141 );
                rgb[ 1 ] = MIN2( 255,  shift+211 );
                rgb[ 2 ] = MIN2( 255,  shift+199 );
                break;
            case 1:
                rgb[ 0 ] = MIN2( 255,  shift+255 );
                rgb[ 1 ] = MIN2( 255,  shift+255 );
                rgb[ 2 ] = MIN2( 255,  shift+179 );
                break;
            case 2:
                rgb[ 0 ] = MIN2( 255,  shift+190 );
                rgb[ 1 ] = MIN2( 255,  shift+186 );
                rgb[ 2 ] = MIN2( 255,  shift+218 );
                break;
            case 3:
                rgb[ 0 ] = MIN2( 255,  shift+251 );
                rgb[ 1 ] = MIN2( 255,  shift+128 );
                rgb[ 2 ] = MIN2( 255,  shift+114 );
                break;
            case 4:
                rgb[ 0 ] = MIN2( 255,  shift+128 );
                rgb[ 1 ] = MIN2( 255,  shift+177 );
                rgb[ 2 ] = MIN2( 255,  shift+211 );
                break;
            case 5:
                rgb[ 0 ] = MIN2( 255,  shift+253 );
                rgb[ 1 ] = MIN2( 255,  shift+180 );
                rgb[ 2 ] = MIN2( 255,  shift+98 );
                break;
            case 6:
                rgb[ 0 ] = MIN2( 255,  shift+179 );
                rgb[ 1 ] = MIN2( 255,  shift+222 );
                rgb[ 2 ] = MIN2( 255,  shift+105 );
                break;
            case 7:
                rgb[ 0 ] = MIN2( 255,  shift+252 );
                rgb[ 1 ] = MIN2( 255,  shift+205 );
                rgb[ 2 ] = MIN2( 255,  shift+229 );
                break;
            case 8:
                rgb[ 0 ] = MIN2( 255,  shift+217 );
                rgb[ 1 ] = MIN2( 255,  shift+217 );
                rgb[ 2 ] = MIN2( 255,  shift+217 );
                break;
            case 9:
                rgb[ 0 ] = MIN2( 255,  shift+188 );
                rgb[ 1 ] = MIN2( 255,  shift+128 );
                rgb[ 2 ] = MIN2( 255,  shift+189 );
                break;
            case 10:
                rgb[ 0 ] = MIN2( 255,  shift+204 );
                rgb[ 1 ] = MIN2( 255,  shift+235 );
                rgb[ 2 ] = MIN2( 255,  shift+197 );
                break;
            case 11:
                rgb[ 0 ] = MIN2( 255,  shift+255 );
                rgb[ 1 ] = MIN2( 255,  shift+237 );
                rgb[ 2 ] = MIN2( 255,  shift+111 );
                break;
            default:
                cerr << "sth is wrong here" << endl;
                break;
        }
    }

} // namespace Base
} // namespace KeiRo
