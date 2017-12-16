#include "Sim.h"
#include <iostream>
//#include <stdio.h>
//#define UPPERLINE (char)238u
#ifndef N_OUT_LANE

#define N_OUT_LANE lanes[0]
#define W_IN_LANE  lanes[1]
#define E_OUT_LANE lanes[2]
#define N_IN_LANE  lanes[3]
#define S_OUT_LANE lanes[4]
#define E_IN_LANE  lanes[5]
#define W_OUT_LANE lanes[6]
#define S_IN_LANE  lanes[7]

#endif

//Sim::Sim()
//{
//}



Sim::Sim(int len, int rTime, int yTime, int gTime)
{
	this->len = len;
	intersection[0][0] = new Section;
	intersection[0][1] = new Section;
	intersection[1][0] = new Section;
	intersection[1][1] = new Section;




	for (int i = 0; i < 8; ++i)
	{
		lanes[i] = Lane(len);
	}

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

/*
	Visually:
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	_________|XX|_________
	XXXXXXXXXXIIXXXXXXXXXX
	XXXXXXXXXXIIXXXXXXXXXX
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	---------|XX|---------
	
*/	
		

	for(int i = 0; i < len; i++) // len = 10
	{
	/*	if(i != len-1)
		{
	*/
		for(int j = 0; j < len; j++) { cout << "-"; }
		cout << '*' << S_IN_LANE[i+OVERHANG] << N_OUT_LANE[len-i-1] << '*';	
		for(int j = 0; j < len; j++) { cout << "-"; }
 		cout << endl;
	/*	} else {
			for(int j = 0; j < len; j++) { cout << "*"; }
			cout << '*' << S_IN_LANE[i+OVERHANG] << N_OUT_LANE[len-i-1] << '*';	
			for(int j = 0; j < len; j++) { cout << "*"; }
 			cout << endl;
		}
	*/

	}
	
	for(int i = 0; i < len * 2 + 4; i++) { cout << "*"; }
	cout << endl;
	for(int i = 0; i < len; i++){ cout << W_OUT_LANE[len-i-1]; }
	cout << '*' << intersection[0][0] << intersection[0][1] << '*';
	for(int i = 0; i < len; i++){ cout << W_IN_LANE[i+OVERHANG]; }
	cout << endl; 
	for(int i = 0; i < len; i++){ cout << E_IN_LANE[i+OVERHANG]; }
	cout << '*' << intersection[1][0] << intersection[1][1] << '*';
	for(int i = 0; i < len; i++){ cout << W_IN_LANE[len-i-1]; }
	cout << endl;
	for(int i = 0; i < len * 2 + 4; i++) { cout << "*"; }
	cout << endl;

	for(int i = 0; i < len; i++) // len = 10
	{	
	/*	if(i == 0)
		{	
	*/
		for(int j = 0; j < len; j++) { cout << "-"; }
		cout << '*' << S_OUT_LANE[i] << N_IN_LANE[len+OVERHANG-1-i] << '*';	
		for(int j = 0; j < len; j++) { cout << "-"; }
 		cout << endl;
		
	/*
			} else {
			for(int j = 0; j < len; j++) { cout << "-"; }
			cout << '*' << S_OUT_LANE[i] << N_IN_LANE[len+OVERHANG-1-i] << '*';	
			for(int j = 0; j < len; j++) { cout << "-"; }
 			cout << endl;	
		}
	*/
	}

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



/*


	// lets print the two east lanes

	for (int i = OVERHANG; i < len; ++i)
	{
		//cout << "Here, my len is: " << len + OVERHANG - i - 1 << endl;
		cout << E_IN_LANE[E_IN_LANE.length() - i - 1];
		//cout << E_IN_LANE[i];
	}
	cout << endl;
	for (int i = 0; i < len; ++i)
	{
		cout << E_OUT_LANE[i];
	}
	cout << endl;
*/
}



