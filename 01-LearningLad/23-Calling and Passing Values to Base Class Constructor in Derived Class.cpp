#include <iostream>
#include <string>

using namespace std;
/*
class Father {
protected:
    int height;
public:

    Father(int h) {
        cout << "constructor of father class called" << endl;
        height = h;
    }
};
*/

class Father {
protected:
    int height;
public:

    Father() {
        cout << "constructor of father class called" << endl;
    }
};
class Mother {
protected:
    string skincolor;
public:

    Mother() {
        cout << "constructor of mother class called" << endl;
    }
};

class child : public Father,public Mother {
public:
    child(int x , string color) : Father(),Mother() {
        height = x;
        skincolor = color;
        cout << "constructor of child class called" << endl;
    }

    void display() {
        cout << "height is " << height << "skin color is "<<skincolor<< endl;
    }
};

int main()
{
    child ahmed(24 , "white");

    ahmed.display();


    return 0;
}


