#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;


class Flight {
	private:
		string flightID;
		string planeID;
		int numPil;
		int numCabCrew;
		vector<string> pilots;
		vector<string> cabCrew;
		time_t sDate;
		time_t eDate;
		string sAirCode;
		string eAirCode;
		int numPass;
		int status;
		
	public:
		Flight();
		void setFlightID(string fID);
		string getFlightID();
		void setPlaneID(string tailNum);
		string getPlaneID();
		void setNumPil(int num);
		int getNumPil();
		void setNumCabCrew(int num);
		int getNumCabCrew();
		void addPilot(string id);
		string getPilot(string id);
		void addCabCrew(string id);
		string getCabCrew(string id);
		void setSDate(time_t start);
		time_t getSDate();
		void setEDate(time_t end);
		time_t getEDate();
		void setSAirCode(string code);
		string getSAirCode();
		void setEAirCode(string code);
		string getEAirCode();
		void setNumPass(int num);
		int getNumPass();
		void setStatus(int stat);
		int getStatus();
		void printPil();
		string storePil(int i);
		string getPil(string id);
		void printCab();
		string storeCab(int i);
		string getCab(string id);
};

#endif