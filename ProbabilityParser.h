#ifndef PROBPARSER_H
#define PROBPARSER_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;
/*
 * Author: Kevin Peng
 * This parser reads in a file that contains the 
 * probability of vehicle occurance and sets 
 * the variables properly
 *
 */

class ProbabilityParser 
{
	public:
		inline ProbabilityParser() {carChance = 0; SUVChance = 0; truckChance = 0; 
			vehicleSum = 0; straightChance = 0; rightChance = 0; leftChance = 0; movementSum = 0;}
		ProbabilityParser(string file); 

		// getters
		inline int getCarChance() { return carChance; }
		inline int getSUVChance() { return SUVChance; }
		inline int getTruckChance() { return truckChance; }
		inline int getVehicleSum() { return vehicleSum; }
		inline int getLeftChance() { return leftChance; }
		inline int getRightChance() { return rightChance; }
		inline int getStraightChance() { return straightChance; }
		inline int getMovementSum() { return movementSum; } 
	private: 
		// private instance variables
		int carChance;
		int SUVChance;
		int truckChance;
		int vehicleSum; // the probability of cars and movement ability will have the same sum
				
		int leftChance;
		int rightChance;
		int straightChance;
		int movementSum;
};

#endif



