#include "flights.h"
#include "planes.h"
#include "crews.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Flights::Flights(){
	flightList.clear();
}
void Flights::addFlight(Crews *c, Planes *p){
	//Temporary data
	Flight temp;
	string fID, pID, stat, sCode, eCode;
	int pilNum, cabNum, passNum, fYear, fMonth, fDay, fSHour, fSMin, fEHour, fEMin;
	time_t start, end;
	struct tm *fTime = new struct tm;
	
	do{
		cout << endl;
		cout << "Enter flight ID: "; cin >> fID; //Ask for ID number
		if(flightList.count(fID) == 1){ //Check if it exists
			cout << "That ID is taken." << endl;
		}
		else{
			temp.setFlightID(fID);
		}
	}while(flightList.count(fID) == 1);
	//Get all information
	cout << "Enter year of flight: "; cin >> fYear;
	fTime->tm_year = (fYear - 1900);
	cout << "Enter month of flight (1-12): "; cin >> fMonth;
	fTime->tm_mon = (fMonth-1);
	cout << "Enter day of flight (1-31): "; cin >> fDay;
	fTime->tm_mday = fDay;
	do{
		cout << "Enter hour of flight: (0-23): "; cin >> fSHour;
		fTime->tm_hour = fSHour;
		cout << "Enter minute of flight: (0-59): "; cin >> fSMin;
		fTime->tm_min = fEMin;
		
		start = mktime(fTime); //Convert struct tm to time_t
		
		temp.setSDate(start); //Set time start
		
		cout << "Enter hour of flights end: (0-23): "; cin >> fEHour;
		fTime->tm_hour = fEHour;
		cout << "Enter minute of flights end: (0-59): "; cin >> fEMin;
		fTime->tm_min = fEMin;
		
		end = mktime(fTime); //Convert struct tm to time_t
	
		temp.setEDate(end); //Set time end
		
		
		if(temp.getEDate() < temp.getSDate()){ //Check if ends before it begins
			cout << "Flight cannot end before it starts" << endl;
		}
	}while(end < start);
	delete fTime;
	cout << "Enter number of passengers: "; cin >> passNum;
	temp.setNumPass(passNum); //Set number of passengers
	//Plane check variables
	bool nExist = true;
	bool capacity = true;
	bool available = true;
	
	do{
		nExist = true;
		capacity = true;
		available = false;
		
		cout << "Enter plane ID: "; cin >> pID; //Enter plane ID
		if(p->planeExist(pID) == 0){ //Check if it exists
			cout << "PLANE NOT FOUND" << endl;
			cout << "Use this list" << endl;
			p->printPlanes(); //Print list
		}
		else{ 
			nExist = false;
		
			if(p->searchForPlane(pID).getNumSeats() < passNum){ //Check if plane has enough seats
				cout << "Too many passengers" << endl;
			}	
			else{
				capacity = false;
			}
		
			for(auto& it : flightList){ //Check if plane is available at this time
				if(it.second.getPlaneID() == pID){
					if(((start < it.second.getSDate()) && (end < it.second.getSDate())) || ((start > it.second.getEDate()) && (end > it.second.getEDate()))){
						available = false;
					}
					else{ 
						cout << "Plane is not available at this time" << endl;
						available = true;
					}
				}
			}
		}
	}while(nExist || capacity || available); //Check if all flags are passed
	
	temp.setPlaneID(pID); //Set plane ID
	
	if((end - start) > 28800){ //Check flight time is greater than 8 hours
		//Set min crew
		pilNum = 4;
		cabNum = 2*(p->searchForPlane(pID).getMinCrew());
		temp.setNumCabCrew(cabNum);
		temp.setNumPil(pilNum);
	}
	else{ 
		//Set min crew
		pilNum = 2;
		cabNum = (p->searchForPlane(pID).getMinCrew());
		temp.setNumCabCrew(cabNum);
		temp.setNumPil(pilNum);
	}
	string tempID;
	bool isPilot, pExist;
	bool pAvailable = false;
	for(int i = 0; i < pilNum; i++){
		do{
			cout << "Enter pilot #" << i+1 << " ID: "; cin >> tempID; //Get ID
			if(c->crewExist(tempID)==0){ //Check if exists
				cout << "CREW MEMBER NOT FOUND" << endl;
				cout << "Use this list of pilots" << endl;
				c->printPilots();
			}
			else{
				pExist = false;
				if(c->isPilot(tempID)){ //Check if it is a pilot
					isPilot = false;
				}
				else { 
					cout << "Not a pilot" << endl;
					cout << "Use this list of pilots" << endl;
					c->printPilots();
				}
				for(auto& it : flightList){
					if(tempID == it.second.getPilot(tempID)){ //Check if pilot is available
						if(((start < it.second.getSDate()) && (end < it.second.getSDate())) || ((start > it.second.getEDate()) && (end > it.second.getEDate()))){
							pAvailable = false;
						}
						else{
							cout << "Pilot not available" << endl;
						}
					}
				}
			}	
		}while(isPilot || pExist || pAvailable);
		temp.addPilot(tempID); //Add pilot to list
	}
	
	bool isCab, cExist;
	bool cAvailable = false;
	for(int i = 0; i < cabNum; i++){
		do{
			cout << "Enter cabin crew #" << i+1 << " ID: "; cin >> tempID; //Get ID
			if(c->crewExist(tempID)==0){ //Check if it exists
				cout << "CREW MEMBER NOT FOUND" << endl;
				cout << "Use this list of cabin crew" << endl;
				c->printCabins();
			}
			else{
				cExist = false;
				if(c->isCabin(tempID)){ //Check if it is a cabin crew member
					isCab = false;
				}
				else { 
					cout << "Not a cabin crew" << endl;
					cout << "Use this list of cabin crew" << endl;
					c->printCabins();
				}
				for(auto& it : flightList){
					if(tempID == it.second.getCabCrew(tempID)){ //Check if cabin crew is available
						if(((start < it.second.getSDate()) && (end < it.second.getSDate())) || ((start > it.second.getEDate()) && (end > it.second.getEDate()))){
							cAvailable = false;
						}
						else{
							cout << "Crew member not available" << endl;
						}
					}
				}
			}	
		}while(isCab || cExist || cAvailable);
		temp.addCabCrew(tempID); //Add crew member to list
	}
	//Get airport codes
	cout << "Enter starting airport code (ex. LAX): "; cin >> sCode;
	cout << "Enter ending airport code (ex. DAL): "; cin >> eCode;
	//Set airport codes
	temp.setSAirCode(sCode);
	temp.setEAirCode(eCode);
	//Set status to active
	temp.setStatus(0);
	//Add flight to flightList
	flightList.emplace(fID, temp);
}


void Flights::editFlight(Planes* p){
	string fID, sCode, eCode;
	int passNum, stat, fYear, fMonth, fDay, fHour, fMin, choice;
	struct tm *fTime;
	time_t start, end;
	
	cout << "Enter flight ID: "; cin >> fID; //Get flight ID
	cout << endl;
	
	if(flightList.count(fID) == 0){ //Check if it exists
		cout << "Flight not found" << endl;
	}
	else{ //Dislpay edit menu
		cout << "0. Quit " << endl;
		cout << "1. Edit flight time" << endl;
		cout << "2. Edit starting airport code" << endl;
		cout << "3. Edit ending airport code" << endl;
		cout << "4. Edit status" << endl;
		cout << "5. Edit number of passengers" << endl;
		cin >> choice;
		
		switch (choice) { 
			case 0: //Return to last menu
				break;
			case 1: //Change flight time
				cout << "Enter year of flight: "; cin >> fYear;
				fTime->tm_year - 1900;
				cout << "Enter month of flight (1-12): "; cin >> fMonth;
				fTime->tm_mon = fMonth-1;
				cout << "Enter day of flight (1-31): "; cin >> fDay;
				fTime->tm_mday = fDay;
				do{
					cout << "Enter hour of flight: (0-23): "; cin >> fHour;
					fTime->tm_hour = fHour;
					cout << "Enter minute of flight: (0-59): "; cin >> fMin;
					fTime->tm_min = fMin;
				
					start = mktime(fTime);
				
					flightList.at(fID).setSDate(start);
			
					cout << "Enter hour of flights end: (0-23): "; cin >> fHour;
					fTime->tm_hour = fHour;
					cout << "Enter minute of flights end: (0-59): "; cin >> fMin;
					fTime->tm_min = fMin;
			
					end = mktime(fTime);
		
					flightList.at(fID).setEDate(end);
			
					if(end < start){
						cout << "Flight cannot end before it starts" << endl;
					}
				}while(end < start);
				
				break;
			case 2: //Change starting airport code
				cout << "Enter starting airport code (ex. LAX): "; cin >> sCode;
				flightList.at(fID).setSAirCode(sCode);
				break;
			case 3: //Change ending airport code
				cout << "Enter ending airport code (ex. DAL): "; cin >> eCode;
				flightList.at(fID).setEAirCode(sCode);
				break;
			case 4: //Change flight status
				cout << "Enter flight status (active=0, completed=1, cancelled=2): "; cin >> stat;
				flightList.at(fID).setStatus(stat);
				break;
			case 5: //Change number of passengers
				do{
					cout << "Enter number of passengers"; cin >> passNum;
					if(p->searchForPlane(flightList.at(fID).getPlaneID()).getNumSeats() < passNum){
						cout << "Too many passengers" << endl;
						cout << "Max for plane is " << p->searchForPlane(flightList.at(fID).getPlaneID()).getNumSeats() << endl;
					}
				}while(p->searchForPlane(flightList.at(fID).getPlaneID()).getNumSeats() < passNum);
			default:
				break;
		}
	}
}

void Flights::deleteFlight(){
	string id;
	
	cout << "Enter flight ID: "; cin >> id; //Get flight ID
	cout << endl;
	
	if(flightList.count(id) == 0){ //Check if it exists
		cout << "Flight not found" << endl;
	}
	else{
		flightList.erase(id); //Erase it
	}
}


void Flights::printFlights(){
	cout << "Flight IDs: " << endl;
	for(auto& it : flightList){ //Print all flight IDs
		cout << it.first << endl;
	}
}


void Flights::printFlightDetail(string id){
	
	time_t start = flightList.at(id).getSDate();
	time_t end = flightList.at(id).getEDate();
	//Print all data for the flight with given ID
	cout << "ID: " << flightList.at(id).getFlightID() << endl;
	cout << "Tail number: " << flightList.at(id).getPlaneID() << endl;
	cout << "Pilot IDs: " << endl;
	flightList.at(id).printPil();
	cout << "Cabin Crew IDs: " << endl;
	flightList.at(id).printCab();
	cout << "Flight time is " << ctime(&start) << " to " << ctime(&end);
	cout << flightList.at(id).getSAirCode() << " to " << flightList.at(id).getEAirCode() << endl;
	cout << flightList.at(id).getNumPass() << " passengers" << endl;
	if(flightList.at(id).getStatus() == 0){
		cout << "Active" << endl;
	}
	else if(flightList.at(id).getStatus() == 1){
		cout << "Complete" << endl;
	}
	else{ 
		cout << "Cancelled" << endl;
	}
}
int Flights::flightExist(string id){
	return flightList.count(id); //Return 1 if exists and 0 if it doesn't
}
void Flights::printPlaneSchedule(Planes *p){
	string id;
	
	cout << "Enter plane ID: "; cin >> id; //Get plane ID
	cout << endl;
	
	if(p->planeExist(id) == 0){ //Check if it exists
		cout << "Flight not found" << endl;
	}
	else{ //Print all details for every flight involving this plane
		time_t start = flightList.at(id).getSDate();
		time_t end = flightList.at(id).getEDate();
		cout << "Tail number: " << id << endl;
		for(auto& it : flightList){
			if(it.second.getPlaneID() == id){
				cout << it.second.getSAirCode() << " to " << it.second.getEAirCode() << ctime(&start) << " to " << ctime(&end);
				if(it.second.getStatus() == 0){
					cout << " Active" << endl;
				}
				else if(it.second.getStatus() == 1){
					cout << " Completed" << endl;
				}
				else{
					cout << " Cancelled" << endl;
				}
			}
		}
	}
}
void Flights::printCrewSchedule(Crews *c){
	string id;
	
	cout << "Enter Crew ID: "; cin >> id; //Get crew member ID
	cout << endl;
	
	if(c->crewExist(id) == 0){ //Check if it exists
		cout << "Crew member not found" << endl;
	}
	else{ //Print all details for every flight involving this crew member
		time_t start;
		time_t end;
		cout << "ID number: " << id << endl;
		for(auto& it : flightList){
			if((it.second.getPil(id) == id) || (it.second.getCab(id) == id)){
				cout << it.second.getSAirCode() << " to " << it.second.getEAirCode() << " " << ctime(&start) << " to " << ctime(&end);
				if(it.second.getStatus() == 0){
					cout << " Active" << endl;
				}
				else if(it.second.getStatus() == 1){
					cout << " Completed" << endl;
				}
				else{
					cout << " Cancelled" << endl;
				}
			}
		}
	}
}
void Flights::printActive(){
	for(auto& it : flightList){
		if(it.second.getStatus() == 0){ //Check if active
			cout << it.second.getFlightID() << endl; //Print IDs
		}
	}
}
void Flights::printComplete(){
	for(auto& it : flightList){ 
		if(it.second.getStatus() == 1){ //Check if completed
			cout << it.second.getFlightID() << endl; //Print IDs
		}
	}
}
void Flights::printCancelled(){
	for(auto& it : flightList){
		if(it.second.getStatus() >= 2){ //Check if cancelled
			cout << it.second.getFlightID() << endl; //Print IDs
		}
	}
}
void Flights::deleteComplete(){
	int size = flightList.size();
	auto it = flightList.begin();
	for(int i = 0; i < size; i++){
		
		if(flightList.size() == 0) { //Check if flights exist
			cout << "Flight list is Empty" << endl;
			return;
		}
		
		if(it->second.getStatus() == 1){ //Check if complete

			flightList.erase(it->first); //Delete
		}

	}
	it++;
}
void Flights::deleteCancelled(){
	int size = flightList.size();
	auto it = flightList.begin();
	for(int i = 0; i < size; i++){
		
		if(flightList.size() == 0) { //Check if flights exist
			cout << "Flight list is empty" << endl;
			return;
		}

		if(it->second.getStatus() == 2){ //Check if cancelled

			flightList.erase(it->first); //Delete
		}

	}
	it++;
}
void Flights::updateStatus(){
	time_t currTime = time(0);
	
	for(auto& it : flightList){
		if(it.second.getStatus() == 0){ //If active
			if(currTime > it.second.getEDate()){ //If flight ends before current time
				it.second.setStatus(1); //Change status to complete
			}
		}
	}
}
void Flights::storeFlight(){
	ofstream fout;
	fout.open("flights.dat");
	fout << flightList.size() << endl; //Store number of planes
	for(auto& it : flightList){ //Store all data
		fout << it.second.getFlightID() << " " << it.second.getPlaneID() << " " << it.second.getSDate() << " " << it.second.getEDate() << " " << it.second.getSAirCode() << " " << it.second.getEAirCode() << " " << it.second.getNumPass() << " " << it.second.getStatus() << " " << it.second.getNumPil() << " " << it.second.getNumCabCrew() << " ";
		for(int i = 0; i < it.second.getNumPil(); i++){
			fout << it.second.storePil(i) << " ";
		}
		for(int i = 0; i < it.second.getNumCabCrew(); i++){
			fout << it.second.storeCab(i) << " ";
		}
		fout << endl;
	}
	fout.close();
}

void Flights::loadFlight(){
	ifstream fin;
	fin.open("flights.dat");
	string fID, pID, sCode, eCode, tempID; //Temp variables
	int size, passNum, pilNum, cabNum, stat;
	time_t start, end;
	Flight temp;
	
	fin >> size; //Get number of flights
	for(int i = 0; i < size; i++){ //Get all data
		fin >> fID >> pID >> start >> end >> sCode >> eCode >> passNum >> stat >> pilNum >> cabNum;
		for(int i = 0; i < pilNum; i++){
			fin >> tempID;
			temp.addPilot(tempID);
		}
		for(int i = 0; i < cabNum; i++){
			fin >> tempID;
			temp.addCabCrew(tempID);
		}
		
		temp.setFlightID(fID);
		temp.setPlaneID(pID);
		temp.setSDate(start);
		temp.setEDate(end);
		temp.setSAirCode(sCode);
		temp.setEAirCode(eCode);
		temp.setNumPass(passNum);
		temp.setStatus(stat);
		temp.setNumPil(pilNum);
		temp.setNumCabCrew(cabNum);
		//Set flight in list
		flightList.emplace(fID, temp);
	}
}	

