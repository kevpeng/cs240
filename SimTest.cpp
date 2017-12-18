#include "Sim.h"

mt19937 Random::rng(8675309);
uniform_int_distribution<int> Random::randInt01(15,18);
uniform_real_distribution<double> Random::randdouble(0.0,1.0);

int main(int argc, char const *argv[])
{
	int max = 100;
	if(argc > 1)
	{
		max = stoi(argv[1]);
	}
	int count = 0;
	Sim Lilly(10, "lights.txt"); // construct a sim
//	Sim Lilly(10, 10, 7, 3); 
	
	while(count != max)
	{
		cout << endl << endl << "clock tick: " << count << endl;

		cout << "NS: " << endl;
		Lilly.NS_light.print();

		cout << "EW: " << endl;
		Lilly.EW_light.print();

		Lilly.print();

		count++;
		Lilly.update();
		cin.get();

		Lilly.W_IN_LANE.conditionallyAddVehicle(1, "input.txt");
		Lilly.E_IN_LANE.conditionallyAddVehicle(5, "input.txt");
		Lilly.N_IN_LANE.conditionallyAddVehicle(3, "input.txt");
		Lilly.S_IN_LANE.conditionallyAddVehicle(7, "input.txt");
	}
	Lilly.printStats();

	return 0;
}
