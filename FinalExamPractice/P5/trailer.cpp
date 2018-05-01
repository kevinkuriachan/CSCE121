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
	//cout << "insert trailer deconstructor" << endl;
}
/*
void Trailer::setReg(string reg)
{
	licensePlate = reg;
}

string Trailer::getReg()
{
	return licensePlate;
}

float Trailer::getFee()
{
	return regFee;
}
*/