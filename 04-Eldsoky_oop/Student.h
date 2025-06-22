#pragma once
#include "Person.h"
class Student :public Person
{
private:
	int level;
	float gpa;
	string depart;

public:

	Student(string n , string g , int a , int l , float gp , string d):Person(n , g , a)
	{
		level = l;
		gpa = gp;
		depart = d;
	}

	void display()
	{
		Person::display();
		cout << level << " " << gpa << " " << depart << "\n";
	}
};

