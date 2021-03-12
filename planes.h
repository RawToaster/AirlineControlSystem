#ifndef PLANES_H
#define PLANES_H

#include "plane.h"
#include <map>

class Planes{
	private:
		map<string, Plane> planeList;
	public:
		Planes();
		void addPlane();
		void editPlane();
		void deletePlane();
		void printPlanes();
		Plane searchForPlane(string id);
		int planeExist(string id);
		void printPlaneDetail(string id);
		void storePlane();
		void loadPlane();
};

#endif