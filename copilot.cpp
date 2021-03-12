#include "copilot.h"
#include <string>
#include <iostream>

using namespace std;

CoPilot::CoPilot(){
	rCode = "00000";
	hours = 0;
}
void CoPilot::setCode(string code){
	rCode = code;
}
string CoPilot::getCode(){
	return rCode;
}
void CoPilot::setHours(int hour){
	hours = hour;
}
int CoPilot::getHours(){
	return hours;
}
void CoPilot::printInfo(){
	cout << "Rating Code: " << rCode << endl;
	cout << "Cumulative Hours: " << hours << endl;
}