#include <iostream>
#include <string>

using namespace std;

class person{
public :
    string name;
    int age;

    void SetName(string iname) {
        name = iname;
    }

    void SetAge(int iage) {
        age = iage;
    }

};

class student : public person{
public:
    int id;

    void SetId(int iid){
        id = iid;
    }

    void introduce() {
        cout << "I am " << name << " and I am " << age << " years old " << "and my id is " << id << endl;
    }

};


int main()
{
    student osama;

    osama.SetName("osama");
    osama.SetAge(23);
    osama.SetId(12345);

    osama.introduce();
    
    return 0;
}


