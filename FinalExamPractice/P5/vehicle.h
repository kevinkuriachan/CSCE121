#include <iostream>
#include <string>
using namespace std;

#ifndef __VEHICLE__
#define __VEHICLE__

class Vehicle {
	public:

	string getReg();
	float getFee();
	void setReg(string reg);
	string getType();

	protected:
	string licensePlate;
	float regFee; 
};

#endif 