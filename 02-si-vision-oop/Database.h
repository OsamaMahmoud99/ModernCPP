#ifndef DATABASE_H
#define DATABASE_H

#include "viewer.h"

class Database {

    friend void viewer::display(const Database& object);

    private:
        int data1;
        int data2;
};

#endif