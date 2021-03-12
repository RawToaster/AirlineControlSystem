#include "planes.h"
#include <iostream>
#include <fstream>

using namespace std;

Planes::Planes(){
	planeList.clear();
}
void Planes::addPlane(){
	//Temporary data
	Plane temp; 
	string tail, pMake;
	int pModel, seatNum, dist, numCrew;
	
	do{
		cout << endl;
		cout << "Enter tail number: "; cin >> tail; //Ask for ID number
		if(planeList.count(tail) == 1){ //Check if it exists
			cout << "That tail number is taken." << endl;
		}
	}while(planeList.count(tail) == 1);
	//Get all information
	cout << "Enter make: "; cin >> pMake;
	cout << "Enter model: "; cin >> pModel;
	cout << "Enter number of seats: "; cin >> seatNum;
	cout << "Enter max range: "; cin >> dist;
	cout << "Enter minimum number of crew: "; cin >> numCrew;
	
	//Set all information to temporary plane
	temp.setTailNum(tail);
	temp.setMake(pMake);
	temp.setModel(pModel);
	temp.setNumSeats(seatNum);
	temp.setRange(dist);
	temp.setMinCrew(numCrew);
	//Place plane in planeList
	planeList.emplace(tail, temp);
}
void Planes::editPlane(){
	//Temporary data
	string id, pMake;
	int pModel, seatNum, dist, numCrew, choice;
	cout << "Enter tail number: "; cin >> id; //Get ID
	cout << endl;
	
	if(planeList.count(id) == 0){ //Check if it exists
		cout << "Plane not found" << endl;
	}
	else{ //Display edit menu
		cout << "0. Quit " << endl;
		cout << "1. Edit make " << endl;
		cout << "2. Edit model " << endl;
		cout << "3. Edit number of seats " << endl;
		cout << "4. Edit max range " << endl;
		cout << "5. Enter minimum number of crew " << endl;
		cout << "Enter selection: ";
		cin >> choice;
		
		switch (choice) { 
			case 0: //Return to last menu
				break;
			case 1: //Change the make
				cout << "Enter make: "; cin >> pMake;
				planeList.at(id).setMake(pMake);
				break;
			case 2: //Change the model
				cout << "Enter model: "; cin >> pModel;
				planeList.at(id).setModel(pModel);
				break;
			case 3: //Change the number of seats
				cout << "Enter number of seats: "; cin >> seatNum;
				planeList.at(id).setNumSeats(seatNum);
				break;
			case 4: //Change the max range
				cout << "Enter max range: "; cin >> dist;
				planeList.at(id).setRange(dist);
				break;
			case 5: //CHange number of crew
				cout << "Enter minimum number of crew: "; cin >> numCrew;
				planeList.at(id).setMinCrew(numCrew);
				break;
			default:
				break;
		}
	}
}
void Planes::deletePlane(){
	string id;
	
	cout << "Enter tail number: "; cin >> id; //Get plane ID
	cout << endl;
	
	if(planeList.count(id) == 0){ //Check if it exists
		cout << "Plane not found" << endl;
	}
	else{
		planeList.erase(id); //Erase it
	}
}
void Planes::printPlanes(){
	cout << "Plane IDs: " << endl;
	for(auto& it : planeList){ //Print all plane IDs
		cout << it.first << endl;
	}
}
Plane Planes::searchForPlane(string id){
	return planeList.at(id); //Return the plane with given ID
}
int Planes::planeExist(string id){
	return planeList.count(id); //Return 1 if exists and 0 if it doesn't
}
void Planes::printPlaneDetail(string id){
	//Print all data for plane with given ID
	cout << "Tail Number: " << planeList.at(id).getTailNum() << endl;
	cout << "Make and model: " << planeList.at(id).getMake() << " " << planeList.at(id).getModel() << endl;
	cout << "Number of seats: " << planeList.at(id).getNumSeats() << endl;
	cout << "Range: " << planeList.at(id).getRange() << endl;
	cout << "Minimum number of crew: " << planeList.at(id).getMinCrew() << endl;
}
void Planes::storePlane(){
	ofstream fout;
	fout.open("planes.dat");
	fout << planeList.size() << endl; //Store number of planes
	for(auto& it : planeList){ //Store all data
		fout << it.second.getTailNum() << " " << it.second.getMake() << " " << it.second.getModel() << " " << it.second.getNumSeats() << " " << it.second.getRange() << " " << it.second.getMinCrew() << endl;
	}
	fout.close();
}
void Planes::loadPlane(){
	ifstream fin;
	fin.open("planes.dat");
	string id, pMake; //Temp variables
	int pModel, seatNum, dist, numCrew, size;
	Plane temp;
	
	fin >> size; //Get number of planes
	for(int i = 0; i < size; i++){ //Get all data
		fin >> id >> pMake >> pModel >> seatNum >> dist >> numCrew;
		temp.setTailNum(id);
		temp.setMake(pMake);
		temp.setModel(pModel);
		temp.setNumSeats(seatNum);
		temp.setRange(dist);
		temp.setMinCrew(numCrew);
		//Set plane in list
		planeList.emplace(id, temp);
	}
}	