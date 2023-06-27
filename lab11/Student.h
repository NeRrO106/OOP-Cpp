#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Persoana.h"
#pragma once

class Student:virtual public Persoana
{
    protected:
        int id_student;
        int n;
        int *note;
    public:
        Student();
        Student(int, int, int*);
        Student(const Student&);
        Student&operator=(const Student&);
        int getVenit();
        double medie();
        bool bursa();
        virtual void afisare();
        virtual ~Student();
};

#endif // STUDENT_H
