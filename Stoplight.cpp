#include "Stoplight.h"
#include <fstream>
#include <iostream>
using namespace std;

Stoplight::Stoplight()
{
	myColor = Red;
	redCountDown = 20; 
	yellowCountDown = 5; 
	greenCountDown = 20;
}

Stoplight::~Stoplight() {}

void Stoplight::setTime(int r, int g, int y)
{
	redCountDown = r;
	yellowCountDown = g;
	greenCountDown = y;
}

void Stoplight::setColor(Color c)
{
	myColor = c;
}

void Stoplight::print()
{
	cout << " red: " << redCountDown << endl;
	cout << " green: " << greenCountDown << endl;
	cout << " yellow: " << yellowCountDown << endl;
	cout << " color: " << myColor << endl;
}