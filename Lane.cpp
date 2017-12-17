#include "Lane.h"

void Lane::conditionallyAddVehicle(string input)
{
	// construct a vehicle temporarily
	Vehicle *temp = new Vehicle(input);

	// check if it can fit in the lane
	if(this->isSpaceAvailable(*temp))
	{
		// we can! put it in
		for (int i = 0; i < temp->length(); ++i)
		{
			(*this)[i]->assign(temp);	
		}
	}
	else
	{
		// we can't, that means we don't need the vehicle we constructed anymore
		delete temp;
	}
}

bool Lane::isSpaceAvailable(Vehicle v)
{
	bool result = true;

	// check to see if we can fit the length of the vehicle with an extra space
	for (int i = 0; i < v.length() + 1; ++i)
	{
		try
		{
			result &= (*this)[i]->isEmpty();
		}
		catch(...)
		{
			return false;
		}
	}

	return result;
}