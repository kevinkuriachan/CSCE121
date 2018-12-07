#include "trailer.h"
#include <iostream>
using namespace std;

Trailer::Trailer()
{
	regFee = 50;
	licensePlate = "";
}

Trailer::Trailer(string reg)
{
	regFee = 50;
	licensePlate = reg;
}

Trailer::~Trailer()
{
}