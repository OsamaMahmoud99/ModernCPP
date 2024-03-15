#include <iostream>

using namespace std;

class Human{
public :
    Human() {
        cout << "constructor called" << endl;
    }

    /* we cannot pass parameters to destructor*/
    ~Human() {
        cout << "Destructor called" << endl;
    }
};


int main()
{
    Human *osama;

    osama = new Human(); //constructor called

    delete osama;       // destructor called
    
    return 0;
}


