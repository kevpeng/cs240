#include "Lane.h"
#include "Section.h"
#include <queue>
#include <iostream>
/*
 * This is a tester method for Lanes, Sections, and Vehicles.
 * It constructs a Lane of length 5 (causes it to be a vector
 * with *9* positions), adds two more new vehicles to the start.
 * Then it pops off one on the end, (which is an empty section)
 * and places it up front with push.
 * 
 * This will be the way in which this class is used.
 * 
 * Note: 
 */
int main(int argc, char const *argv[])
{
	Lane v(5);

	Section carA;
	cout << "the addr of carA is " << &carA << endl;

	Section carB(new Vehicle());
	cout << "the addr of carB is " << &carB << endl << endl;

	v.push(&carA);
	v.push(&carB);

	cout << "V[0] = " << v[0]->toString() << " at " << v[0] << endl;
	cout << "V[1] = " << v[1]->toString() << " at " << v[1] << endl << endl;

	cout << "Popping..." << endl;

	Section *temp = v.pop();

	cout << "Pushing... " << temp << endl;

	Section h;

	v.push(temp);

	cout << "V[0] = " << v[0]->toString() << " at " << v[0] << endl;
	cout << "V[1] = " << v[1]->toString() << " at " << v[1] << endl << endl;

	return 0;
}