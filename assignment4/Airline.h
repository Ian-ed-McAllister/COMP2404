
#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Array.h"
#include "Part.h"
#include "Aircraft.h"

using namespace std;

class Airline {
		
	public:
		//constructor
		Airline(const string& name);

		//destructor
		~Airline();
		

		void addAircraft(const string& type, const string& reg);
		void addPart(const string& part, int fh_inspect, int it_inspect);
		void takeFlight(const string& reg, int hours);
		void printAircraft();
		void printParts();
		void inspectionReport(const string& reg, Date& date);
		bool install(const string& reg, const string& name, Date& date);
		
	
	private:
		Part* getPart(const string& name);
		Aircraft* getAircraft(const string& reg);
		
		const string name;
		Array<Part*> parts;
		Array<Aircraft*> aircrafts;

		
		
	
};
#endif
