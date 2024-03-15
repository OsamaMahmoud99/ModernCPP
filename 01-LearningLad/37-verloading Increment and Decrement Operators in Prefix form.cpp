#include <iostream>
#include <string>

using namespace std;


/*class Marks {
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

    void operator++() {
        mark += 1;
    }

    friend void operator--(Marks&m);
  
};

void operator--(Marks& m){
    m.mark -= 1;
}
*/

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

    Marks operator++() {
        mark += 1;
        return *this;
    }

    friend Marks operator--(Marks& m);

};

Marks operator--(Marks& m) {
    m.mark -= 1;

    return m;
}


int main()
{
    /*Marks osamamark(75);
    osamamark.display();

    ++osamamark;
    osamamark.display();

    --osamamark;
    osamamark.display();
    */
    Marks osamamark(75);
    osamamark.display();

    (++osamamark).display();
    (--osamamark).display();

  
    return 0;
}


