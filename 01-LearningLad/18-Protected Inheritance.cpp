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

class student : protected person{
public:

    void display() {
        cout << name << endl;       // name accessable here as student inherit from person
    }

    void SetStudentName(string iname) {
        SetName(iname);
    }

};


int main()
{
    student osama;
    //osama.SetName("osama");    // setName not accessible outside parent and child class

    osama.SetStudentName("osama");
    osama.display();


    return 0;
}


