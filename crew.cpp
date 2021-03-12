#include "crew.h"
#include <iostream>

using namespace std;

Crew::Crew(){ //Getter and setter functions
	name = "NULL";
	ID = "NULL";
	type = -1;
}

void Crew::setName(string cName){
	name = cName;
}

string Crew::getName(){
	return name;
}

void Crew::setID(string id){
	ID = id;
}

string Crew::getID(){
	return ID;
}
void Crew::setType(int pos){
	type = pos;
}
int Crew::getType(){
	return type;
}
void Crew::printInfo(){
	cout << "Name: " << name << endl;
	cout << "ID: " << ID << endl;
	cout << "Type: " << type << endl;
}