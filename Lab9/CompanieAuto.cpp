#include "CompanieAuto.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

CompanieAuto::CompanieAuto(){}

CompanieAuto::CompanieAuto(string descriere, int nrmodele, char* nume, int aninfiintare):Companie(nume, aninfiintare){
    this->descriere=descriere;
    this-> nr_modele =nrmodele;
}

CompanieAuto::CompanieAuto(const CompanieAuto& companieauto):Companie(companieauto.nume,companieauto.an_infiintare){
    this->descriere = companieauto.descriere;
    this->nr_modele = nr_modele;
}

CompanieAuto& CompanieAuto::operator= (const CompanieAuto& companieauto){
    this->descriere = companieauto.descriere;
    this->nr_modele = companieauto.nr_modele;
    Companie::operator=(companieauto);
    return *this;
}

istream& operator>>(istream&din, CompanieAuto& comp){
    char numec [101]; int an;
    din>>numec;
    din>>an;
    string descriere; int nrmodele;
    din>>descriere;
    din>>nrmodele;
    comp = CompanieAuto(descriere,nrmodele,numec,an);
    return din;
}
ostream& operator<<(ostream&dout, const CompanieAuto& comp){
    dout<<comp.nume;
    dout<<comp.an_infiintare;
    dout<<comp.descriere;
    dout<<comp.nr_modele;
    return dout;
}
int CompanieAuto::getModele(){
    return nr_modele;
}
CompanieAuto::~CompanieAuto(){}
