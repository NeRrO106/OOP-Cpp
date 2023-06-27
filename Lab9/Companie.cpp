#include "Companie.h"
#include <iostream>
#include <cstring>

using namespace std;

Companie::Companie()
{
    nume = NULL;
    an_infiintare = 0;
}

Companie::Companie(char* nume, int an){
    if(nume != NULL) delete[]nume;
    this -> nume = new char[strlen(nume)+1];
    strcpy(this -> nume, nume);
    this->an_infiintare = an;
}

Companie::Companie(const Companie& companie){
    if(nume != NULL) delete[] nume;
    this -> nume = new char[strlen(companie.nume)+1];
    strcpy(this->nume,companie.nume);
    this->an_infiintare = companie.an_infiintare;
}

Companie& Companie::operator= (const Companie& companie){
    if(nume != NULL) delete[] nume;
    this -> nume = new char[strlen(companie.nume)+1];
    strcpy(this->nume,companie.nume);
    this->an_infiintare = companie.an_infiintare;
    return *this;
}
istream& operator>>(istream& din, Companie& comp){
    char numec [101]; int an;
    din>>numec;
    din>>an;
    comp = Companie(numec,an);
    return din;
}
ostream& operator<<(ostream& dout, const Companie& comp){
    dout<<comp.nume;
    dout<<comp.an_infiintare;
    return dout;
}
char* Companie::getNumeComp(){
    return nume;
}
Companie::~Companie()
{
    if(nume != NULL) delete[] nume;
}
