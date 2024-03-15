#include <iostream>
#include <string>

using namespace std;


class Marks {
private:
    int mark;
public:
    Marks() {
        mark = 0;
    }

    Marks(int m) {
        mark = m;
    }

    void display() {
        cout << mark << endl;
    }

    void operator+=(int bonusmark) {
        mark = mark + bonusmark;
    }

    friend void operator-=(Marks& curObj, int redmark);

  
};

void operator-=(Marks& curObj, int redmark) {
    curObj.mark -= redmark;
}



int main()
{
    Marks osamamark(45);
    osamamark.display();
    
    int x = 20;

    //x += osamamark;  // error

    osamamark += x;
    osamamark.display();

    osamamark -= x;
    osamamark.display();

  
    return 0;
}


