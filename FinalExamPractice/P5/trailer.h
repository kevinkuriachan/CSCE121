#include "vehicle.h"

#ifndef __TRAILER__
#define __TRAILER__

class Trailer: public Vehicle
{
	public:

	Trailer();
	Trailer(string reg);
	virtual ~Trailer();

	private:
	/*
	string licensePlate;
	float regFee;
	*/
};

#endif 
