#include <iostream>
#include <string>

using namespace std;

class person {
public:
    string name;

    class Address {
    public:
        string country;
        string stname;
        int hno;
    };

    Address addr;
    void AddressPlease() {
        cout << name << endl << addr.country << endl << addr.stname << endl << addr.hno << endl;
    }
};


int main()
{
   // Address addr;      //error
    //person::Address ad;  // right
    person osama;
    osama.name = "osama";
    osama.addr.country = "Egypt";
    osama.addr.stname = "Eldwar";
    osama.addr.hno = 5;

    osama.AddressPlease();
  
    return 0;
}


