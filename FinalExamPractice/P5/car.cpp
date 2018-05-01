#include "car.h"
#include <iostream>
using namespace std;

Car::Car()
{
	regFee = 200;
	licensePlate = "";
}

Car::Car(string reg)
{
	regFee = 200;
	licensePlate = reg;
}

Car::~Car()
{
	//cout << "insert car deconstructor" << endl;
}