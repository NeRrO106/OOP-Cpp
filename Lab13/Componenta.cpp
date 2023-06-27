#include "Componenta.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

Componenta::Componenta()
{
    nume = "";
    pret = 0;
}
Componenta::Componenta(string nume, int pret){
    this->pret = pret;
    this->nume = nume;
}

int Componenta::getSuma(){
    return pret;
}

void Componenta::afisare(){
    cout<<pret<<" "<<nume<<endl;
}

Componenta::~Componenta(){}
