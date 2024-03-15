#include <iostream>
#include <string>
using namespace std;

class Human{
private :
    string name;
    int age;

public :
    /*Human() {
        cout << "default constructor" << endl;
        name = "noname";
        age = 0;
    }*/
    Human(string iname="noname", int iage = 0) {
        cout << "overloaded constructor" << endl;
        age = iage;
        name = iname;
    }
    void display() {
        cout << name << endl << age << endl;
    }
};


int main()
{

    //Human osama("osama" , 23);

    /* we can do that as iage=0*/
    //Human osama("osama");

    /* we can do that as iage = 0 , iname="noname" 
     but here we should remove the default constructor*/
    Human osama;
    osama.display();


    return 0;
}


