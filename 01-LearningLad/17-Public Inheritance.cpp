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

class student : public person{
public:

    void display() {
        cout << name << endl;       // name accessable here as student inherit from person
    }

};


int main()
{
    /*person osama;
    osama.name = "osama";*/     // cannot access protectd member outside class 

    student osama;
    osama.SetName("osama");
    osama.display();


    return 0;
}


