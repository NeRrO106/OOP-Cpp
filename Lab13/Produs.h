#ifndef PRODUS_H
#define PRODUS_H

#include <iostream>
#include <string>
using namespace std;

class Produs
{
public:
    virtual int getSuma() = 0;
    virtual void afisare() = 0;
};

#endif // PRODUS_H
