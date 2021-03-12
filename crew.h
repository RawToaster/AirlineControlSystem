#ifndef CREW_H
#define CREW_H

#include <string>
using namespace std;

class Crew {
	private:
		string name;
		string ID;
		int type;
	public:
		Crew();
		void setName(string cName);
		string getName();
		void setID(string id);
		string getID();
		void setType(int pos);
		int getType();
		virtual void printInfo();
};
#endif