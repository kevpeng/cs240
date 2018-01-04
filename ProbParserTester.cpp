#include "ProbabilityParser.h"

int main(){
	ProbabilityParser temp = ProbabilityParser("input.txt");
	cout << "car chance: " << temp.getCarChance() << endl;
	cout << "SUV chance: " << temp.getSUVChance() << endl;
	cout << "truck chance: " << temp.getTruckChance() << endl;
//	cout << "sum: " << temp.getSum() << endl;
	cout << "left chance: " << temp.getLeftChance() << endl;
	cout << "straight: " << temp.getStraightChance() << endl;
	cout << "right: " << temp.getRightChance() << endl;

	ProbabilityParser temp1 = ProbabilityParser();
	cout << "car chance: " << temp1.getCarChance() << endl;
	cout << "SUV chance: " << temp1.getSUVChance() << endl;
	cout << "truck chance: " << temp1.getTruckChance() << endl;
//	cout << "sum: " << temp1.getSum() << endl;
	
	return 0;
}
