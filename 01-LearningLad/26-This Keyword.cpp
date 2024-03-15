#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    int age;
public:
    void setAge(int age) {

       // age = age; //print garbage value
        /* so we should do that */
        this->age = age;
    }
    void showAge() {
        cout << this->age << endl;
    }
};


int main()
{
    Person osama;
    osama.setAge(23);
    osama.showAge();
    
    return 0;
}


