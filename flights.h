#ifndef FLIGHTS_H
#define FLIGHTS_H

#include "flight.h"
#include "crews.h"
#include "planes.h"
#include <map>

class Flights{
	private:
		map<string, Flight> flightList;
	public:
		Flights();
		void addFlight(Crews *c, Planes *p);
		void editFlight(Planes *p);
		void deleteFlight();
		void printFlights();
		int searchForFlight(int id);
		void printFlightDetail(string id);
		int flightExist(string id);
		void printPlaneSchedule(Planes *p);
		void printCrewSchedule(Crews *c);
		void printActive();
		void printComplete();
		void printCancelled();
		void deleteComplete();
		void deleteCancelled();
		void updateStatus();
		void storeFlight();
		void loadFlight();
};

#endif