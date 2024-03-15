#include <iostream>
#include <string>

using namespace std;

class Person {
public:

    void introduce() {
        cout << "hi i am a person" << endl;
   }
};

class Student :public Person {
public:
    void introduce() {
        cout << "hi i am a student and i am awesome" << endl;
    }
};
int main()
{
    /* Overriding Base class */
    Student osama;
    osama.introduce();

    


    return 0;
}


