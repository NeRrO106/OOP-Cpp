#ifndef LAPTOP_H
#define LAPTOP_H

#include "Computer.h"
#include "OS.h"
#include <vector>

using namespace std;

class Laptop : virtual public Computer
{
    protected:
        vector<string> specificatii;
        OS sist;
        int autonomie;
    public:
        Laptop();
        Laptop(vector<Componenta>,int,vector<string>, OS, int);
        int getSuma();
        void afisare();
        ~Laptop();
};

#endif // LAPTOP_H
