#include "LightParser.h" 

int main(){
	LightParser temp = LightParser("lights.txt");
	cout << "red time: " << temp.getRedTime() << endl;
	cout << "yellow time: " << temp.getYellowTime() << endl;

	cout << "green time: " << temp.getGreenTime() << endl;

	return 0;
}
