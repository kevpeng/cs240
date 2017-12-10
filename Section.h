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
		inline char toString() const
		{
			if(myVehicle == 0)
				return '-';
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
		inline void assign(Vehicle* v) { myVehicle = v; }
};
/*
inline std::ostream& operator<<(std::ostream &out, const Section &a) 
{
	return out << a.toString();
}
*/

inline std::ostream& operator<<(std::ostream &out, const Section *a) 
{
	return out << a->toString();
}

#endif
