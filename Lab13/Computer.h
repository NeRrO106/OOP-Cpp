#ifndef COMPUTER_H
#define COMPUTER_H

#include "Produs.h"
#include "Componenta.h"
#include <vector>

using namespace std;

class Computer : virtual public Produs
{
    protected:
        vector<Componenta> vec;
        int nr_componenta;
    public:
        Computer();
        Computer(vector<Componenta>, int);
        int getSuma();
        void afisare();
        ~Computer();
};

#endif // COMPUTER_H
