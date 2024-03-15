#include <iostream>
#include <string>
using namespace std;

class Human{
private :
    string name;
    int age;

public :
    Human() {
        cout << "default constructor" << endl;
        name = "noname";
        age = 0;
    }

    Human(string iname) {
        cout << "constructor with name as the parameter " << endl;
        name = iname;
        age = 0;
    }
    Human(int iage) {
        cout << "constructor with name as the parameter " << endl;
        age = iage;
        name = "noname";
    }

    Human(string iname , int iage) {
        cout << "constructor with name as the parameter " << endl;
        age = iage;
        name = iname;
    }
    void display() {
        cout << name << endl << age << endl;
    }
};


int main()
{
    /* if we do not define the default constructor and 
       there is an overloading constructor we will get an error

       but if we do not define the default constructor and
       there is no an overloading constructor object will call default constructor with garabage values

       */
    Human osama;

    osama.display();

    Human mahmoud("mahmoud");
    mahmoud.display();

    Human hanafi(23);
    hanafi.display();

    Human ahmed("ahmed", 23);
    ahmed.display();


    return 0;
}


