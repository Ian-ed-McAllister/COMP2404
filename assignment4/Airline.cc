
#include "Airline.h"

Airline::Airline(const string& name):name(name){}


//deletes all of the indeces of the arrays
Airline::~Airline(){
	for(int i=0;i<parts.getSize();i++){
		delete parts[i];
	}
	for(int i=0;i<aircrafts.getSize();i++){
		delete aircrafts[i];
	}
}

// returns part based off of name if none returns NULL
Part* Airline::getPart(const string& name){
	for(int i=0;i<parts.getSize();i++){
		if((parts[i]->getName()).compare(name) == 0){
			return parts[i];
		}
	}
	return NULL;
	
}
//returns aircraft based off of registration string if none returns NULL
Aircraft* Airline::getAircraft(const string& reg){
	for(int i=0;i<aircrafts.getSize();i++){
		if((aircrafts[i]->getRegistration()).compare(reg) == 0){
			return aircrafts[i];
		}
	}
	return NULL;	
	
}

//adds aircraft to the airline's aircraft array
void Airline::addAircraft(const string& type, const string& reg){
	aircrafts.add(new Aircraft(type,reg));
}
//adds part to the airlines parts array
void Airline::addPart(const string& part, int fh_inspect, int it_inspect){
	if(fh_inspect >0 && it_inspect >0){
		
		parts.add(new FHIT_Part(part,fh_inspect,it_inspect));
	}else if(fh_inspect >0 && it_inspect == 0){
	
		parts.add(new FH_Part(part,fh_inspect));
	}else if(fh_inspect ==0 && it_inspect > 0){
	
		parts.add(new IT_Part(part,it_inspect));
	}else{
		cout<<"NO PART ADDED fh_inspect and it_inspect not provided"<<endl;
	}


}



//checks if aircraft exisists if so then make it takeFlight()
void Airline::takeFlight(const string& reg, int hours){
	Aircraft* myAircraft;
	myAircraft = getAircraft(reg);
	if(myAircraft != NULL){
		myAircraft->takeFlight(hours);
		cout<<"Done flight"<<endl;
		return;
	}else{
		cout<<"No aircraft in system with requested registration Flight not flown"<<endl;
	}
}
//prints all aircrafts inb the airline
void Airline::printAircraft(){
	for(int i=0;i<aircrafts.getSize();i++){
		cout<<(*(aircrafts[i]));
	}
}
//prints all partts in the airline
void Airline::printParts(){
	for(int i=0;i<parts.getSize();i++){
		cout<<(*(parts[i]));
	}	
}
//checks if plane with reg string exsists if so then check to see if any parts need to be inspected and outputs it to the user
void Airline::inspectionReport(const string& reg, Date& date){
	Aircraft* myAircraft;
	myAircraft = getAircraft(reg);
	if(myAircraft != NULL){
		
	Array<Part*>* oldParts = new Array<Part*>();
	myAircraft->inspection(date, oldParts);
	
		if(oldParts->getSize() >0){
			cout<<myAircraft->getRegistration()<<" Parts that need inspection "<<endl;
			for(int i=0;i<oldParts->getSize();i++){
				cout<<*((*oldParts)[i])<<endl;
			}
			
		}else{
			cout<<myAircraft->getRegistration()<<" No parts to be inspected"<<endl;
			
		}
	
	
	delete oldParts;
	return;
	}else{
		cout<<"No aircraft in system with requested registration Inspection not ran"<<endl;
		return;
	}
	
}
//checks if aircraft exsists, then if part exsists in the airline if both do then install the part on the aircraft with the given date as the installtion date
bool Airline::install(const string& reg, const string& name, Date& date){
	Aircraft* myAircraft;
	myAircraft = getAircraft(reg);
	Part* myPart;
	myPart = getPart(name);
	if(myPart != NULL && myAircraft!=NULL){
		myAircraft->install(myPart, date);
		return true;
	}else{
		return false;
	}
	
}

