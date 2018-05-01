#include <iostream>
using namespace std;

#include "vehicle.h"
#include "electriccar.h"
#include "car.h"
#include "trailer.h"

void printTaxDetails(Vehicle* ride)
{
	string type_ = ride->getType();
	string license = ride->getReg();
	float fee = ride->getFee();
	string toPrint = license+" Tax for "+type_+"s is $";
	cout <<toPrint << fee <<endl;
}

int main(int argc, char **argv)
{
	Trailer *oneHorseSlant = new Trailer();
	Car *lincolnCont = new Car("TX567");
	ElectricCar *tesla = new ElectricCar("TX945");
	oneHorseSlant->setReg("TX642");
	printTaxDetails(oneHorseSlant);
	printTaxDetails(lincolnCont);
	printTaxDetails(tesla);

	delete oneHorseSlant;
	delete lincolnCont;
	delete tesla;
}