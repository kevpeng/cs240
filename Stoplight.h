#ifndef __STOPLIGHT_H__
#define __STOPLIGHT_H__

#include "LightParser.h"

class Stoplight
{
public:
	enum Color {Red, Green, Yellow};

	Stoplight();
	Stoplight(string file);
	~Stoplight();
	void setTime(int r, int y, int g);
	void setColor(Color c);
	void print();
	void update();
	inline Color getColor() { return myColor; }
private:
	Color myColor;
	int redCountDown;
	int yellowCountDown;
	int greenCountDown;
	int count;
};
#endif
