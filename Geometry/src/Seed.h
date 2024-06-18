
#ifndef _Seed_H        // beginning of header file
#define _Seed_H        // notifying that this file is included

#include "Coord2.h"
#include "Polygon2.h"

class Seed {

public:
	
	unsigned int id;                // id
	unsigned int gid;               // group id
	double weight;                  // weight
	KeiRo::Base::Coord2 *coordPtr;               // position
	KeiRo::Base::Polygon2 *voronoiCellPtr;       // cell polygon
};

#endif // _Seed_H

// end of header file
// Do not add any stuff under this line.