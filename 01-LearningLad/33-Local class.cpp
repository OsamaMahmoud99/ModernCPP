#include <iostream>
#include <string>

using namespace std;


void studentList();

int main()
{
    studentList();
  
    return 0;
}

void studentList() {
    class student {
    public:
        string name;
        int age;

        void display() {
            cout << name << endl << age << endl;
        }
    };

    student osama;
    osama.name = "osama";
    osama.age = 23;
    osama.display();
}

