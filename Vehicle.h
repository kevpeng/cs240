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
		enum movementTypes { right, straight, left };
		enum vehicleTypes { car, SUV, truck };

		// Default constructor
		inline Vehicle() { myLength = 0;}
		// Type constructor (for testing)
		inline Vehicle(vehicleTypes type, movementTypes movement)
		{
			myLength = type + 2;
			myVehicle = type;
			myMovement = movement;
		}
		// File constructor
		inline Vehicle(int index, string file) { 
			ProbabilityParser temp = ProbabilityParser(file);
			int maxVehicles = temp.getVehicleSum();
			int maxTurns = temp.getMovementSum();
			int myVehicleInt = Random::randInt(1, maxVehicles);			

			if(myVehicleInt <= temp.getCarChance())
			{
				myVehicle = vehicleTypes(0);
			}
			else if(myVehicleInt <= temp.getCarChance() + temp.getSUVChance())
			{
				myVehicle = vehicleTypes(1);
			}
			else
			{
				myVehicle = vehicleTypes(2);
			}



		/*	if(myVehicleInt > 0 && myVehicleInt < temp.getCarChance()){
				myVehicle = vehicleTypes(0);
			}
			else if(temp.getCarChance() < myVehicleInt && myVehicleInt <= temp.getSUVChance() + temp.getCarChance()){
				myVehicle = vehicleTypes(1);
			}
			else{
				myVehicle = vehicleTypes(2);
			}*/
			myLength = myVehicle + 2;
			
			
			int myTurnInt = Random::randInt(1, maxTurns);
			if(myTurnInt <= temp.getRightChance())
			{
				myMovement = movementTypes(0);
			}
			else if(myTurnInt <= temp.getRightChance() + temp.getStraightChance())
			{
				myMovement = movementTypes(1);
			}
			else
			{
				myMovement = movementTypes(2);
			}
/*			if(0 < myTurnInt && myTurnInt <= temp.getRightChance() || temp.getRightChance() != 0){
				myMovement = movementTypes(0);
			}
			else if(temp.getRightChance() < myTurnInt && myTurnInt <= temp.getRightChance() + temp.getStraightChance()){
				myMovement = movementTypes(1); 
			}
			else if(temp.getRightChance() + temp.getStraightChance() < myTurnInt && 
				myTurnInt <= temp.getRightChance() + temp.getStraightChance() + temp.getLeftChance()){
				myMovement = movementTypes(2);
			}*/
			startLaneIndex = index;
		}		

		inline void print() {
			cout << "myVehicle = " << myVehicle << endl;
			cout << "myLength = " << myLength << endl;
			cout << "myMovement = " << myMovement << endl << endl;}

		inline vehicleTypes vehicleType()   { return myVehicle; }	// accessor method for vehicleType
		inline movementTypes movementType()   { return myMovement; }	// accessor method for vehicleType
		inline int			length() { return myLength;  }	// accessor method for length
		inline int getStartIndex() { return startLaneIndex; } // accessor method for index of starting lane
	private:				
		int myLength;  				// length of vehicle
		vehicleTypes myVehicle; 	// type of vehicle
		movementTypes myMovement;	// type of movement
		int startLaneIndex;			// starting lane
};

#endif

