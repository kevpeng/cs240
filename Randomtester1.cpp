#include <iostream>
#include <random>
#include "Random.h"
 
using namespace std; 
//mt19937 Random::rng(12345);
//uniform_int_distribution<int> Random::randint01(1,3);

int main()
{	
	string str;
	cout << "Please enter a seed: ";
	Random temp = Random(str);

//	getline(cin, str);
//	seed_seq seed(str.begin(), str.end());
//	mt19937 generator (seed);
//	uniform_int_distribution<int> distribution(1,3); 
//	default_random_engine generator(seed);
	for(int i = 0; i < 10; i++)
		cout <<	temp.randint01(1,3) << " ";

	cout << endl;


/*
	string str;
	cout << "Please enter a seed: ";
	getline(cin, str);
		
//    int seed = 1;
//  	std::mt19937 rng(seed); // this constructs an instance of mt19937
	for(int i = 0; i < 20; i++)
		cout << Random::randint(1,3) << endl;

	default_random_engine generator; 
	uniform_int_distribution<int> distribution(1,3);
	cout << "hi" << endl;
	for(int i = 0; i < 10; i++){
		cout << distribution(generator) << endl;;
	}
//	std::cout << Random::getRandInt() << "****" << std::endl;	
   	
	for (int i = 0; i < 30; i++)
   	{
   	   int randIntIn1To10 = randint01(rng);
   	   std::cout << randIntIn1To10 << std::endl;
   	}
*/
   	return 0;
}
