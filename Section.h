#ifndef __section_h
#define __section_h
#include "Vehicle.h"

class Section
{
	public:
		Vehicle *myVehicle;
		inline Section() { myVehicle = 0; }
		inline Section(Vehicle* v) { myVehicle = v; }
		inline ~Section() { delete myVehicle; }
};

#endif
