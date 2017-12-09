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
		inline char toString()
		{
			if(myVehicle == 0)
				return 'n';
			else
			{
				switch(myVehicle->type())
				{
					case Vehicle::car:
						return 'C';
						break;
					case Vehicle::SUV:
						return 'S';
						break;
					case Vehicle::truck:
						return 'T';
						break;
					default:
						return 'd';
						break;
				}
			}
		}

		//overloading the << operator
		/*
		std::ostream& operator<<(std::ostream &strm, const Section &a) 
		{
		  return strm << ;
		}
		*/
};

#endif
