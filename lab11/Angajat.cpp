#include "Angajat.h"
#include <iostream>

using namespace std;

Angajat::Angajat()
{
    id_angajat = 0;
    salariu = 0;
}

Angajat::Angajat(int id, int sal){
    id_angajat = id;
    salariu = sal;
}

void Angajat::afisare(){
    Persoana::afisare();
    cout<<id_angajat<<" "<<salariu<<endl;
}

Angajat& Angajat::operator=(const Angajat &s){
    id_angajat = s.id_angajat;
    salariu = s.salariu;
    return *this;
}

Angajat::~Angajat()
{
    //dtor
}

int Angajat::getVenit(){
    return Persoana::getVenit() + salariu;
}
