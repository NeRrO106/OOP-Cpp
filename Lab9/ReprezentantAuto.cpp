#include "ReprezentantAuto.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

ReprezentantAuto::ReprezentantAuto(){}

ReprezentantAuto::ReprezentantAuto(char* numepr, int stoc,string descr, int nrmodel, char* nume, int aninfiintare):CompanieAuto(descr,nrmodel,nume,aninfiintare){
    if(numepr != NULL){
        nume_rep = new char[strlen(numepr)+1];
        strcpy(nume_rep,numepr);
    }
    this->stoc = stoc;
}

ReprezentantAuto::ReprezentantAuto(const ReprezentantAuto&reprezentant):CompanieAuto(reprezentant){
    if(reprezentant.nume_rep != NULL){
         nume_rep = new char[strlen(reprezentant.nume_rep)+1];
        strcpy(nume_rep,reprezentant.nume_rep);
    }
    this->stoc = reprezentant.stoc;
}

ReprezentantAuto& ReprezentantAuto::operator= (const ReprezentantAuto& repauto){
    nume_rep = new char[strlen(repauto.nume_rep)+1];
    strcpy(nume_rep,repauto.nume_rep);

    this->stoc = repauto.stoc;
    CompanieAuto::operator=(repauto);
    return *this;
}

istream& operator>>(istream&din, ReprezentantAuto& rep){
    char numec [101]; int an;
    din>>numec;
    din>>an;
    string descriere; int nrmodele;
    din>>descriere;
    din>>nrmodele;
    char nume2[101]; int stoc2;
    din>>nume2>>stoc2;
    rep = ReprezentantAuto(nume2,stoc2,descriere,nrmodele,numec,an);
    return din;
}
ostream& operator<<(ostream&dout, const ReprezentantAuto& comp){
    dout<<comp.nume;
    dout<<comp.an_infiintare;
    dout<<comp.descriere;
    dout<<comp.nr_modele;
    dout<<comp.nume_rep;
    dout<<comp.stoc;
    return dout;
}
int ReprezentantAuto::getStoc(){
    return stoc;
}
ReprezentantAuto::~ReprezentantAuto()
{
    if(nume_rep !=NULL) delete[] nume_rep;
}
