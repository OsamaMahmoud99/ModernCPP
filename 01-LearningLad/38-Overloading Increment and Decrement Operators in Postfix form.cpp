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

    Marks operator++(int) {
        Marks duplicate(*this);
        mark += 1;
        return duplicate;
    }

    friend Marks operator--(Marks& m ,int);

};

Marks operator--(Marks& m , int) {
    Marks duplicate(m);
    m.mark -= 1;

    return duplicate;
}


int main()
{
    Marks osama(75);
    osama.display();

    (osama++).display();
    osama.display();

    (osama--).display();
    osama.display();

  
    return 0;
}


