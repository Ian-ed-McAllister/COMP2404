
#include "Aircraft.h"

Aircraft::Aircraft(const string& ty, const string& reg):type(ty),registration(reg){


}

Aircraft::Aircraft(Aircraft& Aircraft){


}


Aircraft::~Aircraft(){


}

const string& Aircraft::getRegistration(){return registration;}
//updates the part's installation date and then will add it to the arcrafts parts array
void Aircraft::install(Part* part, Date& date){
	part->install(date);
	partArr.add(part);
}
//updates all of the parts flighthours in the part array
void Aircraft::takeFlight(int hours){
	flighthours += hours;
	for(int i=0;i<partArr.getSize();i++){
		partArr[i]->addFlightHours(hours);
	}
}
//checks to see if the inspection needs to be done if so adds it to the outArray
void Aircraft::inspection(Date& date, Array<Part*>* outArr){
	for(int i=0;i<partArr.getSize();i++){
		if(partArr[i]->inspection(date)){
			outArr->add(partArr[i]);
		}
	}
}
const string& Aircraft::getType(){return type;} 
//print
ostream& operator<<(ostream& out,  Aircraft& air)
{
	out<<"Type"<< air.getType()<<endl<<"Registration: "<<air.getRegistration()<<endl;
	return out;
	
}



