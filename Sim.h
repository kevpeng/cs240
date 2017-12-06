#ifndef SIM_H
#define SIM_H
#include "Lane.h"
#include "Stoplight.h"

using namespace std;

class Sim
{
public:
	//Sim();
	Sim(int len, int rTime, int yTime, int gTime);
	~Sim();

	void print();

	int len;

	Stoplight NS_light;
	Stoplight EW_light;

	Section* intersection[2][2];
	vector<Lane> lanes;	/*  Even indexed lanes are OUTBOUND
								--70--
								 6XX1
								 5XX2
								--43--
								 */   
	vector<Vehicle> vehicles;

}

#endif