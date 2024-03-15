#include <iostream>
#include <string>

using namespace std;



class Person {
	string name;
	int age;

public:
	Person() {
		name = "noname";
		age = 0;
	}

	friend ostream& operator << (ostream& output, Person& p);
	friend istream& operator >> (istream& input, Person& p);

};

ostream& operator << (ostream& output, Person& p) {
	output << "what the hack " << endl;
	output << "my name is " << p.name << " and my age is " << p.age << endl;
	return output;

}
istream& operator >> (istream& input, Person& p) {
	input >> p.name >> p.age;
	return input;
}
int main()
{
	cout << "enter the name and age " << endl;
	Person osama;
	cin >> osama;
	cout << osama;
	
	return 0;

}

