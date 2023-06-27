#ifndef FRIGIDER_H
#define FRIGIDER_H

#include "Produs.h"
#pragma once

class Frigider : public Produs{
    double vol;
    char *culoare;
    bool no_frost;
    public:
        Frigider();
        Frigider(double,char*,bool, char[], double);
        Frigider(const Frigider&);
        Frigider& operator=(const Frigider&);
        virtual void afisare();
        virtual double get_vol();
        ~Frigider();
};

#endif // FRIGIDER_H
