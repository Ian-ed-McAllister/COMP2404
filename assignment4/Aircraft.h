
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Array.h"
#include "Part.h"
#include "Date.h"

using namespace std;

class Aircraft {
	friend ostream& operator<<(ostream&, Aircraft&);	
	public:
		//constructor
		Aircraft(const string& ty, const string& reg);
		//copy constructor
		Aircraft(Aircraft&);
		
		//destructor
		~Aircraft();
		const string& getRegistration();
		const string& getType();
		void install(Part*, Date&);
		void takeFlight(int);
		void inspection(Date&, Array<Part*>*);
		
	
	private:
		const string type;
		const string registration;
		int flighthours;
		Array<Part*> partArr;
		
	
};
#endif
