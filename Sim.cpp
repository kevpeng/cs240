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

#define EndVehicleMovement(X) X.back()->myVehicle->movementType()
#define EndEmpty(X) X.back()->isEmpty()
#define IntVehicleMovement(X, Y) intersection[X][Y]->myVehicle->movementType()

// maps a lane index to which intersection position it is touching
#define adjInt(X) (X % 2 != 0 ? adjIntersection(X) : adjIntersection(X + 1))
#define adjIntersection(X) (X == 1 ? intersection[0][1] : (X == 3 ? intersection[1][1] : (X == 5 ? intersection[1][0] : intersection[0][0])))
#define HEADING(X) (X->movementType() == Vehicle::left ? "Left" : (X->movementType() == Vehicle::right ? "Right" : "Left"))
#define COLOR(X) (X.getColor() == Stoplight::Red ? "R" : (X.getColor() == Stoplight::Green ? "G" : "Y"))
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
Sim::~Sim() 
{ 
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			delete intersection[i][j];
}


// how many clock itcks it takes for a vehicle's movement to make it go from out of the intersection to past the intersection
int getMovementLength(Vehicle *veh) 
{
	int sum = (int)(veh->length()) + (int)(veh->movementType()) + 2;

	return sum;
}

/*
 *	This update method counts down the light timers and moves the proper lanes
 *
 */
void Sim::update()
{
	NS_light.update();
	EW_light.update();	

	// first have any vehicles inside of the intersection continue their movements
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			Vehicle *temp = intersection[i][j]->myVehicle;

			if(temp != 0)
			{
//				cout << "Int[" << i << "][" << j << "] is " << intersection[i][j]->toString() << " and turning " << HEADING(temp) << endl;

				switch(temp->movementType())
				{
					case Vehicle::right: 
						turnRight(temp->getStartIndex(), temp);
						break;
					case Vehicle::straight:
						goStraight(temp->getStartIndex(), temp);
						break;
					default:
						turnLeft(temp->getStartIndex(), temp);
						break;
				}
			}
		}
	}	

	for(int i = 1; i < 8; i += 2)
	{
		if(EndEmpty(lanes[i]))  // checks if spot in intersection is empty.
		{
			continueOn(i);
		}	
		else
		{
			if(i == 1 || i == 5)
			{	
				if(EW_light.getColor() != Stoplight::Red)	
				{
					if(EW_light.getCount() + ((EW_light.getColor() == Stoplight::Yellow) ? 0 : EW_light.getYellowCountDown()) 
						> getMovementLength(lanes[i].back()->myVehicle))
					{
						// if light is green, go		
						switch(lanes[i].back()->myVehicle->movementType())
						{
							case Vehicle::right: 
								turnRight(i, lanes[i].back()->myVehicle);
								break;
							case Vehicle::straight:
								goStraight(i, lanes[i].back()->myVehicle);
								break;
							default:
								turnLeft(i, lanes[i].back()->myVehicle);
								break;
						}
					}
				}	
				else 
				{
					// no op/hold because light is red. 
				}	
			}
			else
			{
				if(NS_light.getColor() != Stoplight::Red)	
				{
					if(NS_light.getCount() + ((NS_light.getColor() == Stoplight::Yellow) ? 0 : NS_light.getYellowCountDown()) 
						> getMovementLength(lanes[i].back()->myVehicle))
					{
						// if light is green, go		
						switch(lanes[i].back()->myVehicle->movementType())
						{
							case Vehicle::right: 
							turnRight(i, lanes[i].back()->myVehicle);
						break;
							case Vehicle::straight:
							goStraight(i, lanes[i].back()->myVehicle);
							break;
						default:
							turnLeft(i, lanes[i].back()->myVehicle);
							break;
						}
					}
				}	
				else 
				{
					// no op/hold because light is red. 
				}	
			}
		}	
	}

	for(int i = 0; i < 8; i++)
	{
		if(i % 2 == 0)	// if any of the outbound lanes haven't otherwise been moved, move them.
			continueOn(i);

		lanes[i].resetMove();
	}
}


/*
 * Give a lane number as an input, the cars in this lane will advance through the intersection
 * in a continuous fashion, like a seive. This continuous block of cars will follow an L-shape
 * turning right from the lane of the input number to the accompanying outbound lane for that move.
 */	
void Sim::turnRight(int inboundLane, Vehicle *v)
{
	// final lane is the outbound of the right turn
	int final = inboundLane - 1;

	if(!lanes[final].hasMoved() && !lanes[inboundLane].hasMoved())
	{
		// cout << "IN TURn RIGhT: " << inboundLane << endl;
		// pop off last section from right lane to make room (now length - 1)
		lanes[final].conditionallyDeleteVehicle();

		// push the traffic from the intersection into the right lane (restoring length)
		lanes[final].push(adjInt(inboundLane));

			// pop from inbound lane into the intersection (length - 1)
			if(lanes[inboundLane].back()->myVehicle == v || lanes [inboundLane].back()->isEmpty())
			{
		//		delete adjInt(inboundLane);
				adjInt(inboundLane) = lanes[inboundLane].pop();

				// add a new section to the end of the inbound lane (length)
				lanes[inboundLane].push(new Section);
			}
			else
			{
				adjInt(inboundLane) = new Section;
			}

		lanes[final].moved();
		lanes[inboundLane].moved();
	}
}

/*
 * Give a lane number as an input, the cars in this lane will advance through the intersection
 * in a continuous fashion, like a seive. This continuous block of cars will follow a straight
 * line from the lane of the input number to the oundbound lane across the intersecton.
 */	
void Sim::goStraight(int inboundLane, Vehicle *v)
{
	
	// final lane is the outbound of the right turn
	int finalLane = (inboundLane - 3 + 8) % 8; // the outbound lane
	int final2 = (inboundLane - 2 + 8) % 8; // used to find 2nd intersection spot
	int oppCorner = (inboundLane + 3 + 8) % 8;
	int adjCorner = (inboundLane + 1 + 8) % 8;

	if(!lanes[finalLane].hasMoved() && !lanes[inboundLane].hasMoved())
	{
		// checks if the corners adjacent to the inbound and outbound lanes are either empty or left-turning
		if((adjInt(oppCorner)->isEmpty() || (adjInt(oppCorner)->myVehicle->movementType() != Vehicle::left)) 
			&& (adjInt(adjCorner)->isEmpty() || (adjInt(adjCorner)->myVehicle->movementType() != Vehicle::left))
				&& (adjInt(inboundLane)->isEmpty() || (adjInt(inboundLane)->myVehicle->movementType() == Vehicle::straight)))
		{
			// cout << "IN StraiGHT: " << inboundLane << endl;

			// pop off last section from right lane to make room (now length - 1)
			lanes[finalLane].conditionallyDeleteVehicle();

			// push the traffic from the intersection into the right lane (restoring length)
			lanes[finalLane].push(adjInt(final2));

			// move section through intersection
			adjInt(final2) = adjInt(inboundLane);

			// pop from inbound lane into the intersection (length - 1)
			if(lanes[inboundLane].back()->myVehicle == v || lanes [inboundLane].back()->isEmpty())
			{
		//		delete adjInt(inboundLane);
				adjInt(inboundLane) = lanes[inboundLane].pop();

				// add a new section to the end of the inbound lane (length)
				lanes[inboundLane].push(new Section);
			}
			else
			{
				adjInt(inboundLane) = new Section;
			}

			lanes[finalLane].moved();
			lanes[inboundLane].moved();
		}
	}
}

/*
 * Give a lane number as an input, the cars in this lane will advance through the intersection
 * in a continuous fashion, like a seive. This continuous block of cars will follow an L-shape
 * turning left from the lane of the input number to the accompanying outbound lane for that move.
 */	
void Sim::turnLeft(int inboundLane, Vehicle *v)
{
	
	// final lane is the outbound of the right turn
	int outboundLane = (inboundLane + 3 + 8) % 8; // the outbound lane
	int final2 = (inboundLane - 2 + 8) % 8; // used to find 2nd intersection spot
	int final3 = (final2 -2 + 8) % 8;
	int adjCorner = (inboundLane + 1 + 8) % 8;

	if(!lanes[outboundLane].hasMoved() && !lanes[inboundLane].hasMoved())
	{
		// checks if the corners adjacent to the inbound and outbound lanes are either empty or left-turning
		if((adjInt(inboundLane)->isEmpty() || (adjInt(inboundLane)->myVehicle == v)) 
			&& (adjInt(final3)->isEmpty() || (adjInt(final3)->myVehicle == v)))
		{
			// cout << "In left: " << inboundLane << endl;

			// pop off last section from right lane to make room (now length - 1)
			lanes[outboundLane].conditionallyDeleteVehicle();
	
			// push the traffic from the intersection into the right lane (restoring length)
			lanes[outboundLane].push(adjInt(final3));
	
			// move section through intersection
			adjInt(final3) = adjInt(final2);
	
			// move section through intersection
			adjInt(final2) = adjInt(inboundLane);
	
			// pop from inbound lane into the intersection (length - 1)
			if(lanes[inboundLane].back()->myVehicle == v || lanes[inboundLane].back()->isEmpty())
			{
		//		delete adjInt(inboundLane);
				adjInt(inboundLane) = lanes[inboundLane].pop();

				// add a new section to the end of the inbound lane (length)
				lanes[inboundLane].push(new Section);
			}
			else
			{
				adjInt(inboundLane) = new Section;
			}

			lanes[outboundLane].moved();
			lanes[inboundLane].moved();

			// move any vehicle from adjacent corner if can do
			if(!lanes[adjCorner].hasMoved())
			{
				lanes[adjCorner].push(adjInt(adjCorner));
				lanes[adjCorner].conditionallyDeleteVehicle();

				adjInt(adjCorner) = new Section;

				lanes[adjCorner].moved();
			}
		}
	}
}

/*
 * A function to be called on lanes when they should continue and need no extra functionality, pop and push
 */
void Sim::continueOn(int outboundLane)
{
	if(!lanes[outboundLane].hasMoved())  // checks if the lane has moved.
	{
		lanes[outboundLane].conditionallyDeleteVehicle();
   		lanes[outboundLane].push(new Section);					// fill empty spot with new empty section		
		lanes[outboundLane].moved();
	}	
}

/*
 * This function prints the "board"
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
		for(int j = 0; j < len; j++) { cout << ((i == len - 1 && j == i) ? COLOR(NS_light) : "-"); }

		cout << '*' << S_IN_LANE[i+OVERHANG] << N_OUT_LANE[len-i-1] << '*';	

		for(int j = 0; j < len; j++) { cout << ((i == len - 1 && j == 0) ? COLOR(EW_light) : "-"); }
 		cout << endl;

	}
	
	for(int i = 0; i < len * 2 + 4; i++) { cout << "*"; }
	cout << endl;

	for(int i = 0; i < len; i++){ cout << W_OUT_LANE[len-i-1]; }
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
		for(int j = 0; j < len; j++) { cout << ((i == 0 && j == len-1) ? COLOR(EW_light) : "-"); }
		cout << '*' << S_OUT_LANE[i] << N_IN_LANE[len+OVERHANG-1-i] << '*';	

		for(int j = 0; j < len; j++) { cout << ((i == 0 && j == i) ? COLOR(NS_light) : "-"); }
 		cout << endl;
		
	}
}



