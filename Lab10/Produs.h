#include <iostream>

using namespace std;
#pragma once
class Produs
{
    protected:
        char cod[6];
        double pret;
    public:
        Produs();
        Produs(char[], double);
        Produs(const Produs&);
        Produs& operator=(const Produs&);
        virtual void afisare();
        virtual double get_vol();
        ~Produs();
};
