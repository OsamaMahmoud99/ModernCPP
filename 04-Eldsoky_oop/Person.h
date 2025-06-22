#pragma once

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string name;
	string gender;
	int age;

public:

	Person()
	{
		name = "";
		gender = "";
		age = 0;
	}

	Person(string n, string g, int a)
	{
		name = n;
		gender = g;
		age = a;
	}

	void display()
	{
		cout << name << " "<< gender <<" "<< age << "\n";
	}
};

