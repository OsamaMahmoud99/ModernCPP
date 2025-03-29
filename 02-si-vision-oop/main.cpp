#include <iostream>
#include <stdint.h>
#include <string.h>

using namespace std;

enum order {
    FIRST,
    SECOND,
    THIRD
};

int main()
{
    order obj = FIRST;
    cout << obj << endl;

}