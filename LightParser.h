#ifndef LIGHTPARSER_H
#define LIGHTPARSER_H

#include <string> 
#include <iostream>
#include <fstream>
using namespace std;
/*
 *	Author: Kevin Peng
 *	This parser reads in a file that contains int values for 
 * 	the desired length of each light.
 *
 */

class LightParser
{
	public: 
		inline LightParser() { }
		LightParser(string file);
		
		inline int getRedTime() { return redTime; }
		inline int getYellowTime() { return yellowTime; }
		inline int getGreenTime() { return greenTime; } 
	

	private:
		// private instance variable
		int redTime; // time for red light
		int yellowTime; // time for yellow light
		int greenTime; // time for green light

	

};
#endif
