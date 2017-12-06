#include "ProbabilityParser.h"

ProbabilityParser::ProbabilityParser(string file)
{
	fstream in;
	in.open(file.c_str());
	
	// check if file is good
	if(in.bad()) { cout << "BAD INPUT FILE" << endl; }
	
	else{
		string line;
		while(getline(in, line))
		{
			// this code assumes that the file's only contents are 'type=number'
			unsigned int index = line.find('=');
			string str = line.substr(0,index); // car type
//			std::cout << "carType " << carType << " index of = "  << index << endl;
			string probability = line.substr(index+1, line.length());
//			std::cout << "probability: " << probability << endl;
			if(str == "car"){ carChance = stoi(probability); }
			if(str == "SUV"){ SUVChance = stoi(probability); } 
			if(str == "truck"){ truckChance = stoi(probability); }	
			if(str == "left"){ leftChance = stoi(probability); }
			if(str == "right"){ rightChance = stoi(probability); }
			if(str == "straight"){ straightChance = stoi(probability); }

		}
		vehicleSum = carChance + SUVChance + truckChance;
		movementSum = leftChance + rightChance + straightChance;
	}
}

