#include "Lane.h"
#include "Section.h"
#include <queue>
#include <iostream>

int main(int argc, char const *argv[])
{
	Lane v(5);
	Section carA;
	Section carB;
	v.push(&carA);
	v.push(&carB);

	//std::cout << v[0] << std::endl;

	return 0;
}