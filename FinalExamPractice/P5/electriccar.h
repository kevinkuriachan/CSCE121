#include "car.h"

#ifndef __ELECTRIC_CAR__
#define __ELECTRIC_CAR__

class ElectricCar : public Car 
{
	public:

	ElectricCar(); 
	ElectricCar(string reg);
	virtual ~ElectricCar();

	private:
};

#endif 