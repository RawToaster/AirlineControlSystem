#ifndef COPILOT_H
#define COPILOT_H

#include <string>
#include "crew.h"

using namespace std;

class CoPilot : public Crew {
	private:
		string rCode;
		int hours;
	public: 
		CoPilot();
		void setCode(string code);
		string getCode();
		void setHours(int hour);
		int getHours();
		void printInfo();
};

#endif