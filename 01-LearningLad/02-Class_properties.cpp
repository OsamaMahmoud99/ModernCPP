#include <iostream>
#include <string>
using namespace std;

class HumanBeing {
public :
    string name;

    void introduce() {
        cout << "hi i am " << name << endl;
    }
};

int main()
{
    HumanBeing osama;

    osama.name = "osama";
    osama.introduce();

    HumanBeing mahmoud;
    mahmoud.name = "mahmoud";

    mahmoud.introduce();

    return 0;

}


