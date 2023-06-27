#include "Produs.h"
#include <iostream>
#include <cstring>

using namespace std;

Produs::Produs(){
    for(int i=0;i<6;i++) cod[i] = 0;
    pret = 0;
}
Produs::Produs(char cod[], double pret){
    for(int i=0;i<6;i++)
        this ->cod[i] = cod[i];
    this->pret = pret;
}

Produs::Produs(const Produs& produs){
    for(int i=0;i<6;i++) this->cod[i] = produs.cod[i];
    this->pret = produs.pret;
}

Produs& Produs::operator= (const Produs& produs){
    for(int i=0;i<6;i++) this->cod[i] = produs.cod[i];
    this->pret = produs.pret;
    return *this;
}

void Produs::afisare(){
    for(int i=0;i<6;i++) cout<<cod[i];
    cout<<" ";
    cout<<pret;
    cout<<endl;
}

double Produs::get_vol(){
    return 0;
}

Produs::~Produs(){

}
