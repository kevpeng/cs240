#ifndef SIM_H
#define SIM_H
#include "Lane.h"
#include "Stoplight.h"

#define N_OUT_LANE lanes[0]
#define W_IN_LANE  lanes[1]
#define E_OUT_LANE lanes[2]
#define N_IN_LANE  lanes[3]
#define S_OUT_LANE lanes[4]
#define E_IN_LANE  lanes[5]
#define W_OUT_LANE lanes[6]
#define S_IN_LANE  lanes[7]

using namespace std;

class Sim
{
	public:
		Sim(int len, string file);
		Sim(int len, int rTime, int yTime, int gTime);
		~Sim();

		void update();
		void print();
		void turnRight(int laneNum);
		int len;

		Stoplight NS_light;
		Stoplight EW_light;

		Section* intersection[2][2];
		Lane lanes[8];

		vector<Vehicle> vehicles;

};

#endif
