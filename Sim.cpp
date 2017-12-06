#include "Sim.h"
#include <iostream>


//Sim::Sim()
//{
//}

Sim::Sim(int len, int rTime, int yTime, int gTime)
{
	this.len = len;

	NS_light.setTime(rTime, yTime, gTime);
	EW_light.setTime(rTime, yTime, gTime);

	NS_light.setColor(Color.Red);
	EW_light.setColor(Color.Green);
}
Sim::~Sim();
/*
 * This function prints the "board"
 *
 *
 *
 */
void Sim::print()
{
	//00  00
	//0L  L0
	//       
	//       
	//0L  L0
	//00  00

	// print each line, containing len blanks,
	// a road section of an outbound and inbound
	// lane, then len blanks
	for(int i = 0; i < len; ++i)
	{
		// if on the last block before the intersection, print the NS light
		// todo: make it actually print the light
		for(int j = 0; j < len; ++j)
			cout << (i == len - 1 && j == i) ? 'L' : ' ';

		// now print the two sections of each lane
		// since theyre ordered in opposite directions
		// (one pointing up and another down) we will
		// need to count back for one

		cout << (lanes[7][4 + i])->toString() << (lanes[0][len - i - 1])->toString();

		//same, but for this one the adjacent inbound lane is EW, so EW light
		for(int j = 0; j < len; ++j)
			cout << (i == 0 && j == i) ? 'L' : ' ';
	}

}



Section* intersection[2][2];
std::vector<Lane> lanes;/*  Even indexed lanes are OUTBOUND
							--70--
							 6XX1
							 5XX2
							--43--
							 */   
vector<Vehicle> vehicles;

