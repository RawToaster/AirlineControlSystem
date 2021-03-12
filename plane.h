#ifndef PLANE_H
#define PLANE_H

#include <string>
using namespace std;

class Plane {
	private:
		int model;
		string make, tailNum;
		int numSeats;
		int range;
		int minCrew;
	public:
		Plane();
		void setTailNum(string id);
		string getTailNum();
		void setMake(string pMake);
		string getMake();
		void setModel(int pModel);
		int getModel();
		void setNumSeats(int num);
		int getNumSeats();
		void setRange(int dist);
		int getRange();
		void setMinCrew(int numCrew);
		int getMinCrew();
};

#endif