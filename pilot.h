#ifndef PILOT_H
#define PILOT_H

#include <string>
#include "crew.h"

using namespace std;

class Pilot : public Crew {
	private:
		string rCode;
		int hours;
	public: 
		Pilot();
		void setCode(string code);
		string getCode();
		void setHours(int hour);
		int getHours();
		void printInfo();
};

#endif