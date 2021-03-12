#ifndef CREWS_H
#define CREWS_H

#include "crew.h"
#include <map>

class Crews{
	private:
		map<string, Crew> crewList;
	public:
		Crews();
		void addCrew();
		void editCrew();
		void deleteCrew();
		void printCrews();
		void printPilots();
		void printCabins();
		bool isPilot(string id);
		bool isCabin(string id);
		Crew searchForCrew(string id);
		int crewExist(string id);
		void printCrewDetail(string id);
		void storeCrew();
		void loadCrew();
};

#endif