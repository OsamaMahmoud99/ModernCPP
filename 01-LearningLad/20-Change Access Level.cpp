#include <iostream>
#include <string>

using namespace std;

class person {
protected:
    string name;
public:

    void SetName(string iname) {
        name = iname;
    }
};

class student : private person {
public:

    /* change access level */
    person::name; // act as a public member

    person::SetName;

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

   // osama.name = "osama";
    osama.SetName("osama");

    osama.display();

    return 0;
}


