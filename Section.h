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
		inline String toString()
		{
			if(myVehicle == 0)
				return ' ';
			else
			{
				switch(myVehicle.myVehicle)
				{
					case car:
						return 'C';
						break;
					case SUV:
						return 'S';
						break;
					case truck:
						return 'T';
						break;
					default:
						return ' ';
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
