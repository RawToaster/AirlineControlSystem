#include "plane.h"

using namespace std;

Plane::Plane(){ //Getter and setter functions
	tailNum = "NULL";
	make = "NULL";
	model = 0;
	numSeats = 0;
	range = 0;
	minCrew = 0;
}

void Plane::setTailNum(string id){
	tailNum = id;
}

string Plane::getTailNum(){
	return tailNum;
}

void Plane::setMake(string pMake){
	make = pMake;
}

string Plane::getMake(){
	return make;
}
void Plane::setModel(int pModel){
	model = pModel;
}

int Plane::getModel(){
	return model;
}
void Plane::setNumSeats(int num){
	numSeats = num;
}
int Plane::getNumSeats(){
	return numSeats;
}
void Plane::setRange(int dist){
	range = dist;
}
int Plane::getRange(){
	return range;
}
void Plane::setMinCrew(int numCrew){
	minCrew = numCrew;
}
int Plane::getMinCrew(){
	return minCrew;
}