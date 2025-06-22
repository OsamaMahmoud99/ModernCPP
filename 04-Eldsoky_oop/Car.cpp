#include "Car.h"


int CAR::counter = 0;

CAR::CAR():maker("marcedes"),model(2022)
{
}

CAR::CAR(string m, int mo):maker(m),model(mo)
{
	
}

CAR::~CAR()
{
	cout << "good by";
}

int CAR::getCountCars()
{
	return counter;
}

void CAR::setMaker(string m)
{
	maker = m;
}

string CAR::getMaker()
{
	return maker;
}

void CAR::setModel(int m)
{
	model = m;
}

int CAR::getModel()
{
	return model;
}
