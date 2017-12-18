#ifndef LANE_H
#define LANE_H
#define OVERHANG 4

#include <vector>
#include "Section.h"

class Lane
{
	public:
		inline Lane() {}
		inline Lane(int n)
		{
			length = n;

			for (int i = 0; i < n + OVERHANG; ++i)
			{
				roadSections.push_back(new Section);
			}
		}
		inline ~Lane() {}

		int length;
		
		inline Section*	back()
		{
			return roadSections.back();
		}
		inline Section*	pop()
		{
			Section* temp = roadSections.back();
			roadSections.pop_back(); 
			return temp;
		}
		inline void		push(Section* s) 
		{
			roadSections.emplace(roadSections.cbegin(), s);
		}

		std::vector<Section*> roadSections;
		inline Section* operator[](int i) 
		{
        	return roadSections[i];
    	}
    	void conditionallyAddVehicle(string file);
    	bool isSpaceAvailable(Vehicle v);
		inline void conditionallyDeleteVehicle() 
		{	
			Vehicle *temp = this->pop()->myVehicle;
			if(this->back() == 0) delete temp; 
		}
		inline int size() { return roadSections.size(); }

    	

};

#endif
