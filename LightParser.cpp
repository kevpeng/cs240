#include "LightParser.h"

// Parses the input file. 
// Input file should only contain green and yellow light times.
// Red will be found as the sum of green and yellow
LightParser::LightParser(string file)
{
	fstream in;
	in.open(file.c_str());
	if(in.bad()) { cout << "BAD INPUT FILE" << endl; }
	else {
		string line;
		while(getline(in, line))
		{
			// file contains that file's content is 'light=value'
			unsigned int index = line.find('='); 
			string str = line.substr(0,index); // light type
			string time = line.substr(index+1, line.length());
			
			if(str == "yellow"){ yellowTime = stoi(time); }
			if(str == "green"){ greenTime = stoi(time); }
		}
		redTime = yellowTime + greenTime;
	}
}
