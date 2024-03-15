#include <iostream>

using namespace std;

class Human{
private :
    int age;

    int getAge() {
        return age - 5;
    }


public :
   /* void displayAge() {
        cout << age << endl;
    }*/

    /* we can use also a private method*/
    void displayAge() {
        cout << getAge() << endl;
    }
       
    void setAge(int value) {
        age = value;
    }
};


int main()
{
    Human osama;

    /* error : can not access private member directly*/
    //osama.age = 23;

    osama.setAge(23);
    osama.displayAge();


    return 0;
}


