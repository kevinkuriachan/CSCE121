#include "vehicle.h"

#ifndef __CAR__
#define __CAR__

class Car : public Vehicle 
{
	public:

	Car();
	Car(string reg);
	virtual ~Car();

	private:
};

#endif 