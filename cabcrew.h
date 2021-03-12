#ifndef CABCREW_H
#define CABCREW_H

#include <string>
#include "crew.h"

using namespace std;

class CabinCrew : public Crew {
	private:
		int type;
	public: 
		CabinCrew();
		void setType(int pos);
		int getType();
		void printInfo();
};

#endif