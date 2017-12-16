#include "Lane.h"

	// static members of random.
  	mt19937 Random::rng(8675309);
	uniform_int_distribution<int> Random::randInt01(15,18);
  	uniform_real_distribution<double> Random::randdouble(0.0,1.0);

void printThisLane(Lane &myLane)
{
	for (int i = 0; i < myLane.length + OVERHANG; ++i)
	{
		cout << myLane[i] << " index: " << i << "\tvisible Pos: " << i - OVERHANG << endl;
	}
	cout << endl;
}
/*
bool isSpaceAvailable(Vehicle v, Lane &myLane)
{
	bool result = true;

	// check to see if we can fit the length of the vehicle with an extra space
	for (int i = 0; i < v.length() + 1; ++i)
	{
		try
		{
			result &= !(myLane[i]->hasVehicle());
		}
		catch(...)
		{
			return false;
		}
	}

	return result;
}

void conditionallyAddVehicle(Lane &myLane)
{
	// construct a vehicle
	// doesn't work, gives undef reference
	Vehicle *temp = new Vehicle("input.txt");

	// check if it can fit in the lane
	if(isSpaceAvailable(*temp, myLane))
	{
		// we can! put it in
		for (int i = 0; i < temp->length(); ++i)
		{
			myLane[i]->assign(temp);	
		}
	}
	else
	{
		// we can't, that means we don't need the vehicle we constructed anymore
		delete temp;
	}
}
*/
int main(int argc, char const *argv[])
{
	Lane myLane(10);

	while(true)
	{
		printThisLane(myLane);

		// todo: do something about deleting vehicle at the end...
		// attempt: if popping and it eave an empty space, that means the vehicle is off this board
		Vehicle *temp = myLane.pop()->myVehicle;

		// conditionally delete this vehicle if we have an empty space at the end
		// pop space > delete veh popped if empty >> push empty spot to end
		if(myLane.back() == 0)
			delete temp;

		myLane.push(new Section);

		myLane.conditionallyAddVehicle("input.txt");

		cin.get();
	}


	return 0;
}
