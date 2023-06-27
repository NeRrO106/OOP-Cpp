#ifndef STUD_ANGAJAT_H
#define STUD_ANGAJAT_H

#include "Student.h"
#include "Angajat.h"
#pragma once

class Stud_Angajat:public Student, public Angajat
{
    public:
        Stud_Angajat();
        Stud_Angajat(int, int, int*, int, int);
        Stud_Angajat(const Stud_Angajat&);
        Stud_Angajat&operator=(const Stud_Angajat&);
        int getVenit();
        virtual void afisare();
        virtual ~Stud_Angajat();
};

#endif // STUD_ANGAJAT_H
