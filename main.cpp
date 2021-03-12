/*
Author: Jeremy Kracy
Email: JeremyKracy@my.unt.edu
Description: Basic functions for scheduling flights and assigning planes and crew to the flights
			 This includes:
			 adding data
			 storing and loading data from disk files
			 and printing data
*/

#include "plane.h"
#include "crew.h"
#include "flight.h"
#include "planes.h"
#include "crews.h"
#include "flights.h"
#include <iostream>

using namespace std;

void loadData();
void storeData();

//Instances of all collections
Planes p;
Crews c;
Flights f;

int main() {
		
		int choice = -1; //Choice for start menu
		
		loadData(); //Load all data from files
		
		cout << "CSCE1040 Homework4 Jeremy Kracy jeremykracy@my.unt.edu" << endl;
		
		while(choice != 0){ //Show mwnu until quit is entered
			//Display menu
			cout << "0. Quit " << endl;
			cout << "1. Plane functions " << endl;
			cout << "2. Crew member functions " << endl;
			cout << "3. Flight functions " << endl;
			cout << "4. Store all data " << endl;
			cout << "5. Load all data " << endl;
			cout << "Enter your selection: ";
			cin >> choice;
			cout << endl;
			int pChoice = -1;
			int cChoice = -1;
			int fChoice = -1;
			switch (choice) { //Check which item was selected
				case 0: break; //Exit switch
				case 1: //Show menu for all plane functions
				
				do{ //Show menu until quit is entered
					cout << "0. Quit " << endl;
					cout << "1. Add plane " << endl;
					cout << "2. Edit plane " << endl;
					cout << "3. Delete plane " << endl;
					cout << "4. Print a list of all planes " << endl;
					cout << "5. Print details for 1 plane " << endl;
					cout << "6. Print schedule for 1 plane " << endl;
					cout << "Enter your selection: "; cin >> pChoice;
					cout << endl;
					string tail;
					
					switch(pChoice){ //Check which selection in plane menu
						case 0: break; //Exit switch to start menu
						case 1: p.addPlane(); break; //Add a plane to p instance
						case 2: p.editPlane(); break; //Edit a plane in p instance
						case 3: p.deletePlane(); break; //Delete a plane from p instance
						case 4: p.printPlanes(); break; //Print all planes in p instance
						case 5: //Print details for 1 plane
							
							cout << "Enter tail number "; cin >> tail; //Get plane ID
							if(p.planeExist(tail) == 0){ //Check if it exists
								cout << "PLANE NOT FOUND" << endl;
							}
							else{
								p.printPlaneDetail(tail); //Print all data for entered plane
							}
							break;
						case 6: f.printPlaneSchedule(&p); break; //Print a schedule for an entered plane
						default: break;
					}
				}while(pChoice != 0);
				break;
				case 2: //Show menu for all crew functions
				
				do{	//Show menu until quit is entered
					cout << "0. Quit " << endl;
					cout << "1. Add crew member " << endl;
					cout << "2. Edit crew member " << endl;
					cout << "3. Delete crew member " << endl;
					cout << "4. Print a list of all crew members " << endl;
					cout << "5. Print details for 1 crew member " << endl;
					cout << "6. Print schedule for 1 crew member " << endl;
					cout << "Enter your selection: "; cin >> cChoice;
					cout << endl;
					string cID;
					
					switch(cChoice){ //Check which selection in crew menu
						case 0: break; //Exit switch to start menu
						case 1: c.addCrew(); break; //Add a crew member to c instance
						case 2: c.editCrew(); break; //Edit a crew member in c instance
						case 3: c.deleteCrew(); break; //Delete a crew member from c instance
						case 4: c.printPilots(); c.printCabins(); break; //Print all crew members in c instance
						case 5: //Print details for 1 crew member
							
							cout << "Enter ID "; cin >> cID; //Get crew member ID
							if(c.crewExist(cID) == 0){ //Check if it exists
								cout << "CREW MEMBER NOT FOUND" << endl;
							}
							else{
								c.printCrewDetail(cID); //Print all data for entered crew member
							}
							break;
						case 6: f.printCrewSchedule(&c); break; // Print a schedule for an entered crew member
						default: break;
					}
				}while(cChoice != 0);
				break;
				case 3: //Show menu for all flight functions
					
				do{	//Show menu until quit is entered
					cout << "0. Quit " << endl; 
					cout << "1. Add flight " << endl; 
					cout << "2. Edit flight " << endl; 
					cout << "3. Delete flight " << endl; 
					cout << "4. Print a list of all flights " << endl; 
					cout << "5. Print details for 1 flight " << endl; 
					cout << "6. Print active flights " << endl;
					cout << "7. Print completed flights " << endl;
					cout << "8. Print cancelled flights " << endl;
					cout << "9. Delete all completed flights " << endl;
					cout << "10. Delete all cancelled flights " << endl;
					cout << "11. Update flight statuses " << endl;
					cout << "Enter your selection: "; cin >> fChoice;
					cout << endl;
					string fID;
					switch(fChoice){ //Check which selection in flight menu
						case 0: break; //Exit switch to start menu
						case 1: f.addFlight(&c, &p); break; //Add a flight to f instance
						case 2: f.editFlight(&p); break; //Edit a flight in f instance
						case 3: f.deleteFlight(); break; //Delete a flight from f instance
						case 4: f.printFlights(); break; //Print all flights in f instance
						case 5: //Print details for 1 flight
							
							cout << "Enter ID "; cin >> fID; //Get flight ID
							if(f.flightExist(fID) == 0){ //Check if it exists
								cout << "FLIGHT NOT FOUND" << endl;
							}
							else{
								f.printFlightDetail(fID); //Print all data for entered flight
							}
							break;
						case 6: f.printActive(); break; //Print a list of all active flights
						case 7: f.printComplete(); break; //Print a list of all completed flights
						case 8: f.printCancelled(); break; //Print a list of all cancelled flights
						case 9: f.deleteComplete(); break; //Delete all completed flights
						case 10: f.deleteCancelled(); cout << "AFTER DELETE" << endl; break; //Delete all cancelled flights
						case 11: f.updateStatus(); break; //Update all flights scheduled to end passed the current date to complete
						default: break;
					}
					
				}while(fChoice != 0);
				break;
				case 4: storeData(); //Store all data
				case 5: loadData(); //Load all data
				default:
					break;
			}
		}
		
	storeData(); //Store all data
		
	return 0;
}

void storeData(){ //Call all store functions
	p.storePlane();
	c.storeCrew();
	f.storeFlight();
}
void loadData(){ //Call all load functions
	p.loadPlane();
	c.loadCrew();
	f.loadFlight();
}