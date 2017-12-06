#include "Vehicle.h"

using namespace std; 

	// let's define the static members in Random
  	mt19937 Random::rng(8675309);
	uniform_int_distribution<int> Random::randInt01(15,18);
  	uniform_real_distribution<double> Random::randdouble(0.0,1.0);
int main()
{
	for(int i = 0; i < 10; i++){
		Vehicle temp = Vehicle("input.txt");
		temp.print();
	}
	return 0;
}
