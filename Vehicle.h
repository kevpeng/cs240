#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
	public:	
		// variables
		enum movementType { straight, left, right };
		enum vehicleType { car, SUV, truck };

		// default constructor
		Vehicle();

	private:				
		int length;  				// length of vehicle
		vehicleType myVehicle; 	// type of vehicle
		movementType myMovement;	// type of movement
		vector<int> positionInRoad; // location of road on vehicle




};
#endif
