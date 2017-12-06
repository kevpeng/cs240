#ifndef LANE_H
#define LANE_H
#include <vector>
#include "Section.h"

class Lane
{
	public:
		Lane() {}
		Lane(int n) { roadSections.resize(n + 4); } // 4 extra spots for "spawning zone", hidden
		~Lane() {}

		inline Section*	pop()
		{ 
			Section* temp = roadSections.back();
			roadSections.pop_back(); 
			return temp;
		}
		inline void		push(Section* s) { roadSections.push_back(s); }

		std::vector<Section*> roadSections;
};

#endif