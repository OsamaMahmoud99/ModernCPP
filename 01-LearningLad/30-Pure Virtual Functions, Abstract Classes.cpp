#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    //pure virtual virtual function
    virtual void introduce() = 0;
};

void Person::introduce() {
    cout << "hey from person" << endl;
}

class Student :public Person {
public:
   void introduce() {
        cout << "hi i am a student" << endl;
        Person::introduce();
    }
};



int main()
{
    Student osama;
    /* we cannot creat an object from abstract class*/
   // Person mahmoud;
    osama.introduce();


  
    return 0;
}


