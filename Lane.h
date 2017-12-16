#ifndef LANE_H
#define LANE_H
#define OVERHANG 4

// Lane ordering around an intersection
#define N_OUT 0
#define E_IN  1
#define E_OUT 2
#define S_IN  3
#define S_OUT 4
#define W_IN  5
#define W_OUT 6
#define N_IN  7

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
		} //roadSections.push_back(s);

		// inbound lanes have first position offscreen, last adj to
		// intersection. OUTBOUND lanes have first adj to intersection
		std::vector<Section*> roadSections;
		inline Section* operator[](int i) 
		{
        	return roadSections[i];
    	}
    	void conditionallyAddVehicle(string file);
    	bool isSpaceAvailable(Vehicle v);

    protected:
    	

};

#endif