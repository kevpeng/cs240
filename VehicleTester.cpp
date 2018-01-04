#include "Vehicle.h"
#include "ProbabilityParser.h" 

using namespace std; 

	// let's define the static members in Random
  	mt19937 Random::rng(8675309);
	uniform_int_distribution<int> Random::randInt01(15,18);
  	uniform_real_distribution<double> Random::randdouble(0.0,1.0);
int main()
{
	ProbabilityParser temp = ProbabilityParser("input.txt");
	cout << "left: " << temp.getLeftChance() << endl;
	cout << "straight: " << temp.getStraightChance() << endl;
	cout << "right: " << temp.getRightChance() << endl;
	for(int i = 0; i < 5; i++){
		cout << "rand int: " << Random::randInt(0, temp.getLeftChance() + temp.getStraightChance() + temp.getRightChance()) << endl;
	}
	/*
	for(int i = 0; i < 5; i++){
	Vehicle temp = Vehicle(1, "input.txt");
		temp.print();

	}
*/
	return 0;
}
