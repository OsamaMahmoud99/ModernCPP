#pragma once

#include <iostream>
#include <string>
using namespace std;

class CAR
{

private:
	string maker;
	int model;
	string color;
	static int counter;

public:

	CAR();
	CAR(string m , int mo);
	~CAR();

	int getCountCars();
	void setMaker(string m);
	string getMaker();
	void setModel(int m);
	int getModel();

};
