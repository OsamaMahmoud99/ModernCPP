#include <iostream>
#include <string>

using namespace std;

class Human{
 
public :

    static int human_count;         //we cannot initialize it here

    Human() {
        human_count++;
    }

    void human_total() {
        cout << "There are " << human_count << " people in this program" << endl;
    }

    static void humanCount() {
        cout << "There are " << human_count << " people in this program" << endl;
    }

};


int Human::human_count = 0;

int main()
{
    cout << Human::human_count << endl;

    Human osama;
    Human mahmoud;
    Human hanafi;

   // Human::human_total();   //call of non static member function requires an object

    Human::humanCount();

    cout << Human::human_count << endl;
    
    return 0;
}


