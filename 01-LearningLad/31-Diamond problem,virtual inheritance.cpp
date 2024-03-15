#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    Animal() {
        cout << "constructor of Animal" << endl;
    }
    int age;
    void walk() {
        cout << "animal walks" << endl;
    }
};

class Tiger : virtual public Animal {
public:
    Tiger() {
        cout << "constructor of Tiger" << endl;
    }
};

class Lion : virtual public Animal {
public:
    Lion() {
        cout << "constructor of Lion" << endl;
    }
};

class Liger :public Tiger, public Lion {
public:
    Liger() {
        cout << "constructor of Liger" << endl;
    }
};


int main()
{
    Liger osama;
    osama.walk();
  

  
    return 0;
}


