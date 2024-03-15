#include <iostream>
#include <string>

using namespace std;



class Person {
public:
	string *name;
	int age;

	Person(string name, int age) {
		this->name = new string(name);
		this->age = age;
	}

	Person(const Person& p) {
		cout << "copy istructor called\n";
		name = new string(*p.name);
		age = p.age;
	}
	void changeNameandAge(string name, int age) {
		*(this->name) = name;
		this->age = age;
	}

	void introduce() {
		cout << "hey i am " << *name << " and i am " << age << " years old" << endl;
	}
};



int main()
{
	Person osama("osama", 24);
	osama.introduce();

	Person duplicatosama = osama;
	duplicatosama.introduce();

	osama.changeNameandAge("osama mahmoud", 25);
	osama.introduce();
	duplicatosama.introduce();                  // not sharing the same memory location of osama

 	return 0;

}

