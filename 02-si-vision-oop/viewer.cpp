#include <iostream>

#include "viewer.h"
#include "Database.h"

void viewer::display(const Database& object)
{
    std::cout << object.data1 << std::endl;
    std::cout << object.data2 << std::endl;
}