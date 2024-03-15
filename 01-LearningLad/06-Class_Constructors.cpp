#include <iostream>
#include <string>
using namespace std;

class Human{
private :
    string name;
    int age;

public :
    /*called when we create an object
      
      if we put it in private we will get an error*/
    Human() {
        name = "noname";
        age = 0;
        cout << "constructor is called when you create an object of human" << endl;
    }

    void display() {
        cout << name << endl << age << endl;
    }
};


int main()
{
    Human osama;

    osama.display();


    return 0;
}


