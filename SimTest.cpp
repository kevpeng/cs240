#include "Sim.h"

mt19937 Random::rng(8675309);
uniform_int_distribution<int> Random::randInt01(15,18);
uniform_real_distribution<double> Random::randdouble(0.0,1.0);

int main(int argc, char const *argv[])
{
	int count = 0;
	Sim John(10, 5, 2, 5);

	John.W_IN_LANE.conditionallyAddVehicle("input.txt");
	John.E_IN_LANE.conditionallyAddVehicle("input.txt");
	John.N_IN_LANE.conditionallyAddVehicle("input.txt");
	John.S_IN_LANE.conditionallyAddVehicle("input.txt");

	while(true)
	{
		//printThisLane(myLane);
		cout << endl << endl << count << endl;
		John.print();

		// todo: do something about deleting vehicle at the end...
		// attempt: if popping and it eave an empty space, that means the vehicle is off this board
		Vehicle *tempw = John.W_IN_LANE.pop()->myVehicle;
		Vehicle *tempe = John.E_IN_LANE.pop()->myVehicle;
		Vehicle *temps = John.S_IN_LANE.pop()->myVehicle;
		Vehicle *tempn = John.N_IN_LANE.pop()->myVehicle;

		// conditionally delete this vehicle if we have an empty space at the end
		// pop space > delete veh popped if empty >> push empty spot to end
		if(John.W_IN_LANE.back() == 0)
			delete tempw;

		if(John.E_IN_LANE.back() == 0)
			delete tempe;

		if(John.S_IN_LANE.back() == 0)
			delete temps;

		if(John.N_IN_LANE.back() == 0)
			delete tempn;

		John.W_IN_LANE.push(new Section);
		John.E_IN_LANE.push(new Section);
		John.S_IN_LANE.push(new Section);
		John.N_IN_LANE.push(new Section);

		//myLane.conditionallyAddVehicle("input.txt");

		count++;
		cin.get();
	}

	//John.print();

	return 0;
}