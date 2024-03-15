#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    virtual void introduce(){
        cout << "hey from person" << endl;
    }
};

class Student :public Person {
public:
    void introduce() {
        cout << "hey from student" << endl;
    }
};

class Farmer : public Person {
public:
    void introduce() {
        cout << "hey from Farmer" << endl;
    }
};

void whosThis(Person& p) {
    p.introduce();
}


int main()
{
    Farmer osama;
    Student mahmoud;
    
    /* will be same print -> "hey from person" without adding virtual to
       person class */
    whosThis(osama);   // "hey from Farmer"
    whosThis(mahmoud); // "hey from student"
    
    return 0;
}


