# include "Part.h"

//code for the part class
Part::Part(const string& name):name(name),flighthours(0){
}
    
Part::~Part(){
}

string Part::getName(){return name;}

void Part::addFlightHours(int hours){this->flighthours = this->flighthours + hours; }

void Part::install(Date& date){this->installationDate = (date);}


void Part::print(ostream& os){
	os<<"Part: "<<this->name<<endl;
}


bool Part::inspection(Date date){return true;}


//code for FH PART class
FH_Part::FH_Part(const string& name, int hours):Part(name),fh_inspect(hours)
{
}

FH_Part::~FH_Part()
{
}
//if the parts flight hours is greater than its inspection integer return true else false
bool FH_Part::inspection(Date date){

    if(flighthours >= fh_inspect) return true;
    return false;
}


void FH_Part::print(ostream& os){
	 os <<"FH Part: "<< this->name<<endl<<"Flight Hours: "<<this->flighthours<<endl<<"Installation date: "<<this->installationDate<<"Inspect Every: "<<this->fh_inspect<<" Flight hours"<<endl<<endl;
}


int FH_Part::getFHinspect(){return fh_inspect;}


//code for IT PART CLASS

IT_Part::IT_Part(const string& name, int days):Part(name),it_inspect(days)
{
}

IT_Part::~IT_Part()
{
}
//checks if the part needs to be inspected based on its inspection days and the diffrence between the given date and installtion date 
bool IT_Part::inspection(Date date){

	
    if((date.toDays() - this->installationDate.toDays()) >= it_inspect){
        return true;
    }
    return false;
}
void IT_Part::print(ostream& os){
	 os <<"IT Part: "<< this->name<<endl<<"Flight Hours: "<<this->flighthours<<endl<<"Installation date: "<<this->installationDate<<"Inspect Every: "<<this->it_inspect<<" Flight hours"<<endl<<endl;
}

int IT_Part::getITinspect(){return it_inspect;}

//copde for FHIT part class


FHIT_Part::FHIT_Part(const string& name, int fhHours, int itDays):FH_Part(name,fhHours),IT_Part(name,itDays),Part(name)
{
}

FHIT_Part::~FHIT_Part()
{
}


//checks the inspeciton of both IT and FH if either is true then it needs to be inspected
bool FHIT_Part::inspection(Date date){
	
	
	
    if(IT_Part::inspection(date) || FH_Part::inspection(date)){
        return true;
    }
    
    return false;
}
void FHIT_Part::print(ostream& os){
	 os <<"FHIT Part: "<< this->getName()<<endl<<"Flight Hours: "<<this->flighthours<<endl<<"Installation date: "<<this->installationDate<<"Inspect Every: "<<this->getITinspect()<< "Days"<<endl<<"Inspect Every: "<<this->getFHinspect()<<" Flight hours"<<endl<<endl;
}










ostream& operator<<(ostream& ost, Part& t){
    t.print(ost);
    return ost;
}




