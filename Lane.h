#ifndef LANE_H
#define LANE_H
#include <vector>
#include "Section.h"

class Lane
{
	public:
		inline Lane() {}
		inline Lane(int n) { roadSections.resize(n + 4); } // 4 extra spots for "spawning zone", hidden
		inline ~Lane() {}

		//inline int		readVehicle(int )
		inline Section*	pop()
		{ 
			Section* temp = roadSections.back();
			roadSections.pop_back(); 
			return temp;
		}
		inline void		push(Section* s) { roadSections.insert(roadSections.cbegin, s); } //roadSections.push_back(s);

		// inbound lanes have first position offscreen, last adj to
		// intersection. OUTBOUND lanes have first adj to intersection
		std::vector<Section*> roadSections;
		inline Section* operator[](int i) 
		{
          return roadSections[i];
    	}
};

#endif