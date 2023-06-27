#include "Produs.h"
#include <iostream>
#include <cstring>

using namespace std;

Produs::Produs(){
    pret = 0;
    marca = NULL;
}

Produs::Produs(int prt, char* marca, Garantie g){
    this->pret = prt;
    if(marca !=NULL){
        this->marca = new char[strlen(marca)+1];
        strcpy(this->marca, marca);
    }
    this->g = g;
}

Produs::Produs(const Produs& p){
    this->pret = p.pret;
    if(p.marca !=NULL){
        this->marca = new char[strlen(p.marca)+1];
        strcpy(this->marca, p.marca);
    }
    this->g = p.g;
}

Produs& Produs::operator=(const Produs& p){
    this->pret = p.pret;
    if(marca != NULL) delete[]marca;
    if(p.marca !=NULL){
        this->marca = new char[strlen(p.marca)+1];
        strcpy(this->marca, p.marca);
    }
    this->g = p.g;
    return *this;
}

int Produs::getGarantie(){
    return g.getLuni();
}
int Produs::getPrice(){
    return pret;
}
string Produs::getService(){
    return g.getServ();
}
istream& operator>>(istream& din, Produs& p){
    int pret;
    char marca[101];
    Garantie gar;
    din>>pret>>marca>>gar;
    p = Produs(pret,marca,gar);
    return din;
}

ostream& operator<<(ostream& dout, const Produs& p){
    dout<<p.pret<<" "<<p.marca<<" "<<p.g<<"\n";
    return dout;
}
Produs::~Produs()
{
    if(marca != NULL) delete[] marca;
}
