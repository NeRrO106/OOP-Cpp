#ifndef ANGAJAT_H
#define ANGAJAT_H
#include <iostream>
#include "Persoana.h"
#pragma once

class Angajat:virtual public Persoana
{
    protected:
        int id_angajat;
        int salariu;
    public:
        Angajat();
        Angajat(int, int);
        int getVenit();
        Angajat&operator=(const Angajat&);
        virtual void afisare();
        virtual ~Angajat();
};

#endif // ANGAJAT_H
