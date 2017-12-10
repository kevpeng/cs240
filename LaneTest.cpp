#include "Lane.h"

void printThisLane(Lane &myLane)
{
	for (int i = OVERHANG; i < myLane.length + OVERHANG; ++i)
	{
		cout << myLane[i] << " index: " << i << "\tvisible Pos: " << i - OVERHANG << endl;
	}
	cout << endl;
}

bool isSpaceAvailable(Vehicle v, Lane &myLane)
{
	bool result = true;

	// check to see if we can fit the length of the vehicle with an extra space
	for (int i = 0; i < v.length() + 1; ++i)
	{
		try
		{
			result &= (myLane[i]->toString() == ' ');
		}
		catch(...)
		{
			return false;
		}
	}
}

void conditionallyAddVehicle(Lane &myLane)
{
	// construct a vehicle
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

int main(int argc, char const *argv[])
{
	Lane myLane(10);

	while(true)
	{
		printThisLane(myLane);

		cin.get();
	}


	return 0;
}