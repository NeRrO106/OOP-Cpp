#ifndef LADA_FRIGORIFICA_H
#define LADA_FRIGORIFICA_H

#include "Produs.h"
#pragma once

class Lada_Frigorifica : public Produs
{
    double dim[3];
    char *descriere;
    public:
        Lada_Frigorifica();
        Lada_Frigorifica(double[],char*,char[], double);
        Lada_Frigorifica(const Lada_Frigorifica&);
        Lada_Frigorifica& operator=(const Lada_Frigorifica&);
        virtual void afisare();
        virtual double get_vol();
        ~Lada_Frigorifica();
};

#endif // LADA_FRIGORIFICA_H
