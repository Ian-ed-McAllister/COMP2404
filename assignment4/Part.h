#ifndef PART_H
#define PART_H
#include "Date.h"
#include "Part.h"
#include <string>
#include <iostream>
using namespace std;
class Part{
	friend ostream& operator<<(ostream& out, Part&);
    protected:
        string name;
        Date installationDate;
        int flighthours;
    private:
        /* data */


    public:
        Part(const string& name);
        virtual ~Part();
        string getName();
        void addFlightHours(int hours);
        void install(Date& date);
     	
        virtual bool inspection(Date date);
        
        
        
        
        
        virtual void print(ostream& os);
    };
    
   



class FH_Part: virtual public Part
{

private:
    /* data */
    int fh_inspect;
public:
    FH_Part(const string& name, int hours);
    virtual ~FH_Part();
    bool inspection(Date date) override;
    
    int getFHinspect();
    
    
    
    
    
    virtual void print(ostream& os) ;

};




class IT_Part : virtual public Part
{

private:
    /* data */
    int it_inspect;
public:
    IT_Part(const string& name, int days);
    virtual ~IT_Part();
    
    bool inspection(Date date) override;
    int getITinspect();
    
    
    virtual void print(ostream& os) override;
};




class FHIT_Part: virtual public IT_Part, virtual public FH_Part
{
private:
    /* data */
public:
    FHIT_Part(const string& name, int fhHours, int itDays);
    ~FHIT_Part();
    bool inspection(Date date) override;
    
    
    
    virtual void print(ostream& os) override;
};













#endif
