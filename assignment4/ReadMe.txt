Ian McAllister 

Purpose: A mock airline that has planes, keeps track of when the parts on the planes need to be inspected

Content:
	Aircraft.h/cc : Code for the Entity/container object Aircraft
	Airline.h/cc : Code for the COntrol object Airline
	Array.h : code for the array container obejct
	Control.c/cc : code for the control object
	Date.h/cc : code for the entity object date
	defs.h : header file for useful global variables such as array sizes
	Part.h/cc: code for the Part entity object that gets inherited by both the FH_Part and IT_Part entity objects which then both get inherited by the FHIT_Part entity object
	
	View.h/cc: code for the view object
	Makefile: make file to complie the executable

How to run:
	Open the command prompt in the assignment4 directory
	In the command prompt run "make" this will make a executable nammed a4
	now run "./a4" to start the program if you would like to remove the object files afterwards run "make clean"




