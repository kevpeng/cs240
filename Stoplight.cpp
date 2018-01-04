#include "Stoplight.h"
#include <fstream>
#include <iostream>
using namespace std;

Stoplight::Stoplight() {}

Stoplight::Stoplight(string file)
{
	// parses the file
	LightParser temp = LightParser(file);
	myColor = Red;
	redCountDown = temp.getRedTime(); 
	yellowCountDown = temp.getYellowTime(); 
	greenCountDown = temp.getGreenTime();
	count = redCountDown;

}

Stoplight::~Stoplight() {}


void Stoplight::setTime(int r, int y, int g)
{
	redCountDown = r;
	yellowCountDown = y;
	greenCountDown = g;
}

void Stoplight::setColor(Color c)
{
	myColor = c;

	switch(myColor)
	{
		case Red:
			count = redCountDown;
			break;
		case Green:
			count = greenCountDown;
			break;
		case Yellow:
			count = yellowCountDown;
			break;
	}
}

void Stoplight::update()
{
	if (count > 1)
	{
		count--;
	}
	else
	{
		switch(myColor)
		{
			case Red:
				setColor(Green);
				break;
			case Green:
				setColor(Yellow);
				break;
			case Yellow:
				setColor(Red);
				break;
		}
	}
}

void Stoplight::print()
{
/*	cout << " red: " << redCountDown << endl;
	cout << " green: " << greenCountDown << endl;
	cout << " yellow: " << yellowCountDown << endl;*/
	cout << " count: " << count << endl;
	cout << " color: ";// << myColor << endl;

	switch(myColor)
	{
		case Red:
			cout << "Red";
			break;
		case Green:
			cout << "Green";
			break;
		case Yellow:
			cout << "Yellow";
			break;
	}

	cout << endl;
}
