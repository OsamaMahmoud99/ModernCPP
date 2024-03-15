#include <iostream>
#include <string>
using namespace std;

class Human{
public :
    string name;

    void introduce() {
        cout << "hi " << name << endl;
    }
};

int main()
{
    // class object allocated in stack
    Human osama;

    // class object allocated in heap
    Human* mahmoud = new Human();

    osama.name = "osama";
    osama.introduce();

    mahmoud->name = "mahmoud";
    mahmoud->introduce();


    return 0;

}


