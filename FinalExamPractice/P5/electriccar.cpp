#include "car.h"
#include "electriccar.h"
#include <iostream>
using namespace std;

ElectricCar::ElectricCar()
{
	licensePlate = "";
	regFee = 100;
}

ElectricCar::ElectricCar(string reg)
{
	regFee = 100;
	licensePlate = reg;
}

ElectricCar::~ElectricCar()
{
	//cout << "insert electric car decontructor" << endl;
}