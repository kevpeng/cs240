#ifndef __random_h__
#define __random_h__

#include <random>
using namespace std;

class Random
{
	protected:
   		static mt19937 rng; 
		static uniform_int_distribution<int> randInt01;
		static uniform_real_distribution<double> randdouble;
	public:
		// constructor of a a random. Takes in a seed.
	//	inline Random(string s) { Random::seed_seq(str.begin(), str.end()); 
	//		randint01(1,3); default_random_engine generator(seed); }
		
		inline static int  randint() { return Random::randInt01(Random::rng); }
    	inline static int  randint(int a, int b)
    	{
      		double u = Random::randdouble(Random::rng);
			int mappedValue = a + (int)((b - a + 1)*u);
			return(mappedValue);
		}
		inline static int getRandInt() { return randint(1,3); }
};
#endif
