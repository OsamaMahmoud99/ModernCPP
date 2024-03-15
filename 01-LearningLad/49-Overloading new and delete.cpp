#include <iostream>
#include <cstdlib>

using namespace std;



class Student {
	string name;
	int age;

public:
	Student() {
		name = "noname";
		age = 0;
	}

	Student(string name, int age) {
		this->name = name;
		this->age = age;
	}

	void whoAreYou() {
		cout << "hi my name is " << name << " and my age is " << age << endl;

	}

	void* operator new(size_t size) {
		void* pointer;
		cout << "overloaded new. size is" <<size<< endl;

		pointer = malloc(size);
		if (!pointer) {
			bad_alloc ba;
			throw ba;
		}

		return pointer;
	}

	void operator delete(void* pointer) {
		cout << "overloaded delete" << endl;
		free(pointer);
	}

};

int main()
{
	Student* osamaptr;

	try {
		osamaptr = new Student("osama", 23);
		osamaptr->whoAreYou();
		delete osamaptr;

	}
	catch (bad_alloc b) {
		cout << b.what() << endl;
	}



	
	return 0;

}

