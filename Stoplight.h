#ifndef __STOPLIGHT_H__
#define __STOPLIGHT_H__

class Stoplight
{
public:
	enum Color {Red, Green, Yellow};

	Stoplight();
	~Stoplight();
	void setTime(int r, int y, int g);
	void setColor(Color c);
	void print();
	void update();

private:
	Color myColor;
	int redCountDown;
	int yellowCountDown;
	int greenCountDown;
	int count;
};
#endif