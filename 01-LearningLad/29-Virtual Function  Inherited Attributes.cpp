#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    virtual void introduce(){
        cout << "hi from person" << endl;
    }
};

class Student :public Person {
public:
    void introduce() {
        cout << "hi from student" << endl;
    }
};

class GStudent : public Student {
public:
    void introduce() {
        cout << "hi from Graduated Student" << endl;
    }
};

void whoIsThis(Person& p) {
    p.introduce();
}

int main()
{
    Person osama;
    Student mahmoud;
    GStudent hanafi;

    whoIsThis(osama);
    whoIsThis(mahmoud);

    /* will print "hi from student"
       when remove introduce function from GStudent Class*/
    whoIsThis(hanafi);
    
    return 0;
}


