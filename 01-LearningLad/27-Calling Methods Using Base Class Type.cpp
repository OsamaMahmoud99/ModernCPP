#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    void introduce(){
        cout << "hey from person" << endl;
    }
};

class Student :public Person {
public:
    void introduce() {
        cout << "hey from student" << endl;
    }
};

// pass by address
/*void whosThis(Person* p) {
    p->introduce();
}
*/
// pass by reference
void whosThis(Person& p) {
    p.introduce();
}
int main()
{
    Student osama;
    osama.introduce();
    // pass by reference
    whosThis(osama);

    // pass by address
   // whosThis(&osama);
    
    return 0;
}


