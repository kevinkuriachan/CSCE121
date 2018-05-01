#include "vehicle.h"
#include <iostream>
using namespace std;

string Vehicle::getReg()
{
	return licensePlate;
}

float Vehicle::getFee()
{
	return regFee;
}

void Vehicle::setReg(string reg)
{
	licensePlate = reg;
}

string Vehicle::getType()
{
	if (regFee == 50) return "trailer";
	if (regFee == 200) return "car";
	if (regFee == 100) return "electric car"; 
}