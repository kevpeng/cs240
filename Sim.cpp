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

#define N_OUT_INDEX 0
#define W_IN_INDEX  1
#define E_OUT_INDEX 2
#define N_IN_INDEX  3
#define S_OUT_INDEX 4
#define E_IN_INDEX  5
#define W_OUT_INDEX 6
#define S_IN_INDEX  7
//Sim::Sim()
//{
//}


/*
 *	This sim function starts the simulation and sets the values properly
 *
 */
Sim::Sim(int len, string file) 
{
	// set length of the visible lane
	this->len = len;

	// make section instances for the intersection
	intersection[0][0] = new Section;
	intersection[0][1] = new Section;
	intersection[1][0] = new Section;
	intersection[1][1] = new Section;

	// initialize lanes
	for (int i = 0; i < 8; ++i)
	{
		lanes[i] = Lane(len);
	}
	
	LightParser temp = LightParser(file);

	// initialize lights properly
	NS_light.setTime(temp.getRedTime(), temp.getYellowTime(), temp.getGreenTime());
	EW_light.setTime(temp.getRedTime(), temp.getYellowTime(), temp.getGreenTime());
	
	// hard code what the starting colors are			
	EW_light.setColor(Stoplight::Red);
	NS_light.setColor(Stoplight::Green);
}

Sim::Sim(int len, int rTime, int yTime, int gTime)
{
	// set visible length of lane
	this->len = len;

	// make section instances for the intersection
	intersection[0][0] = new Section;
	intersection[0][1] = new Section;
	intersection[1][0] = new Section;
	intersection[1][1] = new Section;

	// initialize lanes
	for (int i = 0; i < 8; ++i)
	{
		lanes[i] = Lane(len);
	}
	
	// initialize lights properly
	NS_light.setTime(rTime, yTime, gTime);
	EW_light.setTime(rTime, yTime, gTime);

	// hard code what the starting colors are 
	NS_light.setColor(Stoplight::Red);
	EW_light.setColor(Stoplight::Green);
}

// default destructor
Sim::~Sim() {}

/*
 *	This update method counts down the light timers and moves the proper lanes
 *
 */
void Sim::update()
{
	NS_light.update();
	EW_light.update();

	cout << "IS W_IN_LANE.back empty??" << W_IN_LANE.back()->isEmpty() << endl;	
	// attempt: if popping and it eave an empty space, that means the vehicle is off this board
	// these if statements check if a lane can collectively move up one space. 
	if(W_IN_LANE.back()->isEmpty())
	{
        Vehicle *tempw = W_IN_LANE.pop()->myVehicle;
        W_IN_LANE.push(new Section);
	} 
	else 
	{
		cout << EW_light.getColor() << endl;
		if(EW_light.getColor() == Stoplight::Green) 
		{
			cout << W_IN_LANE.back()->myVehicle->movementType() << endl;
			if(W_IN_LANE.back()->myVehicle->movementType() == Vehicle::right)
			{
				this->turnRight(W_IN_INDEX);
				this->turnRight(W_IN_INDEX);
				this->turnRight(W_IN_INDEX);
				
			}
			else if(W_IN_LANE.back()->myVehicle->movementType() == Vehicle::straight)
			{
			//	John.W_IN_LANE.goStraight(W_IN_INDEX);
			}
			else if(W_IN_LANE.back()->myVehicle->movementType() == Vehicle::left)
			{
				if(E_IN_LANE.back()->isEmpty()){
			//		John.W_IN_LANE.turnLeft(W_IN_INDEX);
				}
			}
	
			Section* temp = W_IN_LANE.pop();
		//	intersection[][];
		}
		
	}
	
	if(E_IN_LANE.back()->isEmpty())
	{
        Vehicle *tempe = E_IN_LANE.pop()->myVehicle;
        E_IN_LANE.push(new Section);
	} 
	else
	{
	}
	
	if(N_IN_LANE.back()->isEmpty())
	{
        Vehicle *tempn = N_IN_LANE.pop()->myVehicle;
        N_IN_LANE.push(new Section);
	}
	else
	{
	}

	if(S_IN_LANE.back()->isEmpty())
	{
        Vehicle *temps = S_IN_LANE.pop()->myVehicle;
        S_IN_LANE.push(new Section);
	}
	else
	{
	}
    //myLane.conditionallyAddVehicle("input.txt");			
		
	
	

}

// given a lane number, have the thing turn right	
void Sim::turnRight(int laneNum)
{
	// final lane is the outbound of the right turn
	int final = laneNum - 1;
	lanes[final].conditionallyDeleteVehicle();
	if(laneNum == 1)
	{
		lanes[final].push(intersection[0][1]);
		intersection[0][1] = lanes[laneNum].pop();
		cout << "IN TURNRIGHT METHOD" << endl;
		lanes[laneNum].push(new Section);
	}
	else if(laneNum == 3)
	{
		lanes[final].push(intersection[1][1]);
		intersection[1][1] = lanes[laneNum].pop();
		lanes[laneNum].push(new Section);
	}
	else if(laneNum == 5)
	{
		lanes[final].push(intersection[1][0]);
		intersection[1][0] = lanes[laneNum].pop();
		lanes[laneNum].push(new Section);
	}
	else if(laneNum == 7)
	{
		lanes[final].push(intersection[0][0]);
		intersection[0][0] = lanes[laneNum].pop();
		lanes[laneNum].push(new Section);
	}
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
	for(int i = 0; i < len; i++){ cout << W_OUT_LANE[len+OVERHANG-i-1]; }
	cout << '*' << intersection[0][0] << intersection[0][1] << '*';
	for(int i = 0; i < len; i++){ cout << W_IN_LANE[len+OVERHANG-i-1]; }
	cout << endl; 
	for(int i = 0; i < len; i++){ cout << E_IN_LANE[i+OVERHANG]; }
	cout << '*' << intersection[1][0] << intersection[1][1] << '*';
	for(int i = 0; i < len; i++){ cout << E_OUT_LANE[i]; }
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



