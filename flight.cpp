#include "flight.h"

using namespace std;

Flight::Flight(){ //Getter and setter functions
	flightID = "NULL";
	planeID = "NULL";
	numPil = 0;
	numCabCrew = 0;
	sDate = 0;
	eDate = 0;
	sAirCode = "NULL";
	eAirCode = "NULL";
	numPass = 0;
	status = 0;
}
void Flight::setFlightID(string fID){
	flightID = fID;
}
string Flight::getFlightID(){
	return flightID;
}
void Flight::setPlaneID(string tailNum){
	planeID = tailNum;
}
string Flight::getPlaneID(){
	return planeID;
}
void Flight::setNumPil(int num){
	numPil = num;
}
int Flight::getNumPil(){
	return numPil;
}
void Flight::setNumCabCrew(int num){
	numCabCrew = num;
}
int Flight::getNumCabCrew(){
	return numCabCrew;
}
void Flight::addPilot(string id){
	pilots.push_back(id);
}
string Flight::getPilot(string id){
	string pID = "-1";
	for(auto& it : pilots){
		if(id == it){
			pID = it;
			return pID;
		}
	}
	return pID;
}
void Flight::addCabCrew(string id){
	cabCrew.push_back(id);
}
string Flight::getCabCrew(string id){
	string cID = "-1";
	for(auto& it : cabCrew){
		if(id == it){
			cID = it;
			break;
		}
	}
	return cID;
}
void Flight::setSDate(time_t start){
	sDate = start;
}
time_t Flight::getSDate(){
	return sDate;
}
void Flight::setEDate(time_t end){
	eDate = end;
}
time_t Flight::getEDate(){
	return eDate;
}
void Flight::setSAirCode(string code){
	sAirCode = code;
}
string Flight::getSAirCode(){
	return sAirCode;
}
void Flight::setEAirCode(string code){
	eAirCode = code;
}
string Flight::getEAirCode(){
	return eAirCode;
}
void Flight::setNumPass(int num){
	numPass = num;
}
int Flight::getNumPass(){
	return numPass;
}
void Flight::setStatus(int stat){
	status = stat;
}
int Flight::getStatus(){
	return status;
}
void Flight::printPil(){
	for(auto& it : pilots){
		cout << it << endl;
	}
}
string Flight::storePil(int i){
	return pilots.at(i);
}
string Flight::getPil(string id){
	for(unsigned int i = 0; i < pilots.size(); i++ ){
		if(pilots.at(i) == id){
			return id;
		}
	}
	return "NULL";
}
void Flight::printCab(){
	for(auto& it : cabCrew){
		cout << it << endl;
	}
}
string Flight::storeCab(int i){
	return cabCrew.at(i);
}
string Flight::getCab(string id){
	for(unsigned int i = 0; i < cabCrew.size(); i++){
		if(cabCrew.at(i) == id){
			return id;
		}
	}
	return "NULL";
}