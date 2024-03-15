#include <iostream>
#include <string>

using namespace std;

class Human{
private:
    string* name;
    int* age;

public :
    Human(string iname , int iage) {
        name = new string;
        age = new int;

        *name = iname;
        *age = iage;
    }

    void dispaly() {
        cout << "Hi I am " << *name << "and i am " << *age <<" years old"<< endl;
    }

    /* we cannot pass parameters to destructor*/
    ~Human() {
        delete name;
        delete age;

        cout << "all memories are released" << endl;
    }
};


int main()
{
    Human *osama;

    osama = new Human("osama" , 23); //constructor called
    osama->dispaly();

    delete osama;
    
    return 0;
}


