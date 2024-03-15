#include <iostream>
#include <string>

using namespace std;

class person{
protected:
    string name;
public :

    void SetName(string iname) {
        name = iname;
    }
};

class student : private person{
public:

    void display() {
        cout << name << endl;       // name accessable here as student inherit from person
    }

    void SetStudentName(string iname) {
        SetName(iname);
    }

};

class Gstudent : public student {
public:
    void setGstudentName(string iname) {
        //SetName(iname);    //cannot access private member declared in class student
        SetStudentName(iname);
    }
};
int main()
{  
    Gstudent osama;

    osama.setGstudentName("osama");

    osama.display();

    return 0;
}


