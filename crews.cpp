#include "crews.h"
#include <iostream>
#include <fstream>

using namespace std;

Crews::Crews(){
	crewList.clear();
}
void Crews::addCrew(){
	//Temporary data
	Crew temp;
	string cName;
	string id;
	int job;
	
	do{
		cout << endl;
		cout << "Enter ID: "; cin >> id; //Ask for ID number
		if(crewList.count(id) == 1){ //Check if it exists
			cout << "That ID is taken." << endl;
		}
	}while(crewList.count(id) == 1);
	//Get all information
	cout << "Enter Name: "; cin >> cName;
	do{
		cout << "Enter type (pilot=0,cabin=1): "; cin >> job;
	}while((job != 0) && (job != 1));
	//Set all information to temporary crew member
	temp.setID(id);
	temp.setName(cName);
	temp.setType(job);
	//Place crew member in crewList
	crewList.emplace(id, temp);
}
void Crews::editCrew(){
	//Temporary data
	string cName;
	string id;
	int job, choice;
	cout << "Enter ID: "; cin >> id; //Get ID
	cout << endl;
	
	if(crewList.count(id) == 0){ ////Check if it exists
		cout << "Crew member" << endl;
	}
	else{ //Display edit menu
		cout << "0. Quit " << endl;
		cout << "1. Edit Name " << endl;
		cout << "2. Edit type " << endl;
		cout << "Enter selection: ";
		cin >> choice;
		
		switch (choice) { 
			case 0: //Return to last menu
				break;
			case 1: //Change name
				cout << "Enter name: "; cin >> cName;
				crewList.at(id).setName(cName);
				break;
			case 2: //Change type
				cout << "Enter type(0=pilot, 1=cabin crew): "; cin >> job;
				crewList.at(id).setType(job);
				break;
			default:
				break;
		}
	}
}
void Crews::deleteCrew(){
	string id;
	
	cout << "Enter ID: "; cin >> id; //Get ID
	cout << endl;
	
	if(crewList.count(id) == 0){ //Check if it exists
		cout << "Crew member not found" << endl;
	}
	else{
		crewList.erase(id); //Erase it
	}
}
void Crews::printCrews(){
	cout << "Crew member IDs: " << endl;
	for(auto& it : crewList){ //Print all crew IDs
		cout << it.first << endl;
	}
}
void Crews::printPilots(){
	cout << "Pilot IDs: " << endl;
	for(auto& it : crewList){
		if(it.second.getType() == 0){ //Check if pilot
			cout << it.first << endl; //Print all pilot IDs
		}
	}
}
void Crews::printCabins(){
	cout << "Cabin Crew IDs: " << endl;
	for(auto& it : crewList) {
		if(it.second.getType() == 1){ //Check if cabin crew
			cout << it.first << endl; //Print all cabin crew IDs
		}
	}
}
bool Crews::isPilot(string id){
	if(crewList.at(id).getType() == 0){ //Check if crew member with given ID is a pilot
		return true;
	}
	return false;
}
bool Crews::isCabin(string id){
	if(crewList.at(id).getType() == 1){ //Check if crew member with Given ID is a cabin crew
		return true;
	}
	return false;
}
Crew Crews::searchForCrew(string id){ 
	return crewList.at(id); //Return the crew member with given ID
}
int Crews::crewExist(string id){
	return crewList.count(id); //Return 1 if exists and 0 if it doesn't
}
void Crews::printCrewDetail(string id){
	//Print all data for crew member with given ID
	cout << "ID: " << crewList.at(id).getID() << endl;
	cout << "Name: " << crewList.at(id).getName() << endl;
	cout << "Type: ";
	if(crewList.at(id).getType() == 0){
		cout << "Pilot" << endl;
	}
	else{
		cout << "Cabin Crew" << endl;
	}
}
void Crews::storeCrew(){
	ofstream fout;
	fout.open("crews.dat");
	fout << crewList.size() << endl; //Store number of crew
	for(auto& it : crewList){ //Store all data
		fout << it.second.getID() << " " << it.second.getName() << " " << it.second.getType() << endl;
	}
	fout.close();
}
void Crews::loadCrew(){
	ifstream fin;
	fin.open("crews.dat");
	string cName, id; //Temp variables
	int size, job;
	Crew temp;
	
	fin >> size; //Get number of crew
	for(int i = 0; i < size; i++){ //Get all data
		fin >> id >> cName >> job;
		temp.setID(id);
		temp.setName(cName);
		temp.setType(job);
		
		crewList.emplace(id, temp);
	}
}