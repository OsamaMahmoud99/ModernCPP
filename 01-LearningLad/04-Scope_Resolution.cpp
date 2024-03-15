#include <iostream>
#include <string>
using namespace std;

class Human{
public :
    string name;

    void introduce(); 
       
};

/* error: redeclaration of member is not allowed 
          if it a static member so we can do that*/
//string Human::name = "noname";

void Human::introduce() {
    cout << Human :: name << endl;
}

int main()
{
    Human osama;

    osama.name = "osama";
    osama.introduce();

    return 0;

}


