#include "Sim.h"
#include <iostream>

#ifndef N_OUT_LANE

#define N_OUT_LANE lanes[0]
#define E_IN_LANE  lanes[1]
#define E_OUT_LANE lanes[2]
#define S_IN_LANE  lanes[3]
#define S_OUT_LANE lanes[4]
#define W_IN_LANE  lanes[5]
#define W_OUT_LANE lanes[6]
#define N_IN_LANE  lanes[7]

#endif

//Sim::Sim()
//{
//}

Sim::Sim(int len, int rTime, int yTime, int gTime)
{
	this->len = len;

	NS_light.setTime(rTime, yTime, gTime);
	EW_light.setTime(rTime, yTime, gTime);

	NS_light.setColor(Stoplight::Red);
	EW_light.setColor(Stoplight::Green);
}
Sim::~Sim()
{

}

void Sim::update()
{

}


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
/*
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

		// N_IN and N_OUT are macros for 7 and 0 respectively (in Lane.h)

		cout << (N_IN_LANE[OVERHANG + i]) << (N_OUT_LANE[len - i - 1]);

		//same, but for this one the adjacent inbound lane is EW, so EW light
		for(int j = 0; j < len; ++j)
			cout << (i == 0 && j == i) ? 'L' : ' ';
	}
	*/

	// lets print the two east lanes

	for (int i = 0; i < len; ++i)
	{
		cout << "Here, my len is: " << len + OVERHANG - i - 1 << endl;
		cout << E_IN_LANE[len + OVERHANG - i - 1];
	}
	cout << endl;
	for (int i = 0; i < len; ++i)
	{
		cout << E_OUT_LANE[i];
	}
	cout << endl;

}



