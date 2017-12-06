#ifndef __STOPLIGHT_H__
#define __STOPLIGHT_H__

class Stoplight
{
public:
	enum Color {Red, Green, Yellow};

	Stoplight();
	~Stoplight();
	void setTime(int r, int g, int y);
	void setColor(Color c);
	void print();

private:
	Color myColor;
	int redCountDown;
	int yellowCountDown;
	int greenCountDown;



};
#endif