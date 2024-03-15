#include <iostream>
#include <string>

using namespace std;

class Human{
 
    string name;
    int age;
public :

    Human(string iname , int iage) {
        name = iname;
        age = iage;
    }

    void tell_me() {
        cout << name << endl << age << endl;
    }

    friend void display(Human man);

    //friend class  classname; // to make a class friend to another class

};


void display(Human man)
{
    cout << man.name << endl << man.age << endl;
}

int main()
{
    Human osama("osama", 23);

    osama.tell_me();

    display(osama);
    
    return 0;
}


