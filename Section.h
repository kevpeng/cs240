#ifndef __section_h
#define __section_h
#include "Vehicle.h"

class Section
{
	public:
		inline Section() { myVehicle = NULL; };
		inline Section(Vehicle* v) { myVehicle = v; };
		inline ~Section() {};
		Vehicle *myVehicle;
};

#endif