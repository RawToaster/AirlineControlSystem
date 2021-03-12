#include "cabcrew.h"
#include <string>
#include <iostream>

using namespace std;

CabinCrew::CabinCrew(){
	type = 0;
}
void CabinCrew::setType(int pos){
	type = pos;
}
int CabinCrew::getType(){
	return type;
}
void CabinCrew::printInfo(){
	cout << "Working as: ";
	if(type == 0){
		cout << "First Class" << endl;
	}
	else if(type == 1){
		cout << "Business Class" << endl;
	}
	else if(type == 2){
		cout << "Economy Front" << endl;
	}
	else if(type == 3){
		cout << "Economy Rear" << endl;
	}
	else if(type == 4){
		cout << "Lead" << endl;
	}
}