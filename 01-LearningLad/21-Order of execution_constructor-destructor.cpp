#include <iostream>
#include <string>

using namespace std;

class person {
public:

    person() {
        cout << "constructor of person class called" << endl;
    }

    ~person() {
        cout << "destructor of person class called" << endl;
    }

};

class student : public person{
public:
    student() {
        cout << "constructor of student class called" << endl;
    }

    ~student() {
        cout << "destructor of student class called" << endl;
    }
    

};

int main()
{
    /*
    * constructor of person class called first
    * Then, constructor of student class
    * destructor of student class called first
    * Then, destructor of person class
    */
    student osama;


    return 0;
}


