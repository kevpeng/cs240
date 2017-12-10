#ifndef VEHICLE_H
#define VEHICLE_H

/*
 * This vehicle file provdes the methods and variables of our vehicle class.
 * The default constructor will initialize a vehicle based on a random integer, 
 * and it's proposed type of movement will be initialized the same way. 
 *
 */
#include "Random.h"
#include "ProbabilityParser.h"
#include <iostream>

class Vehicle
{
	public:	
		// variables
		enum movementTypes { straight, left, right };
		enum vehicleTypes { car, SUV, truck };

		inline Vehicle() { myLength = 0;}
		// default constructor from file
		inline Vehicle(string file) { 
			ProbabilityParser temp = ProbabilityParser(file);
			int maxVehicles = temp.getVehicleSum();
			int maxTurns = temp.getMovementSum();
			int myVehicleInt = Random::randInt(0, maxVehicles);			
			if(myVehicleInt < temp.getCarChance()){
				myVehicle = vehicleTypes(0);
			}
			else if(myVehicleInt < temp.getSUVChance() + temp.getCarChance()){
				myVehicle = vehicleTypes(1);
			}
			else{
				myVehicle = vehicleTypes(2);
			}
			myLength = myVehicle + 2;
			
			
			int myTurnInt = Random::randInt(0, maxTurns);
			if(myTurnInt < temp.getStraightChance()){
				myMovement = movementTypes(0);
			}
			else if(myTurnInt < temp.getStraightChance() + temp.getLeftChance()){
				myMovement = movementTypes(1);
			}
			else{
				myMovement = movementTypes(2);
			}
			
		/*
			cout << "ERROR TESTING IN VEHICLE CONSTRUCTOR: " << endl << "movement = " << myMovement << endl;
			cout << "straight chance: " << temp.getStraightChance() << endl << "left chance: " << temp.getLeftChance()+temp.getStraightChance() << endl
				<< "right chance: " << temp.getRightChance() << endl;
			cout << "myVehicleInt: " << myVehicleInt << endl;
			cout << "vehicle = " << myVehicle << endl << "+++++++++++++++++++++++" << endl;
		*/	

		}
		
		inline void print() {
			cout << "myVehicle = " << myVehicle << endl;
			cout << "myLength = " << myLength << endl;
			cout << "myMovement = " << myMovement << endl << endl;}

		inline vehicleTypes type()   { return myVehicle; }	// accessor method for vehicleType
		inline int			length() { return myLength;  }	// accessor method for length


	private:				
		int myLength;  				// length of vehicle
		vehicleTypes myVehicle; 	// type of vehicle
		movementTypes myMovement;	// type of movement
		vector<int> positionInRoad; // location of road on vehicle

};
#endif
