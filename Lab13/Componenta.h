#ifndef COMPONENTA_H
#define COMPONENTA_H


#include <string>
#include <iostream>

using namespace std;

class Componenta{
        string nume;
        int pret;
    public:
        Componenta();
        Componenta(string, int);
        ~Componenta();
        int getSuma();
        void afisare();
};

#endif // COMPONENTA_H
