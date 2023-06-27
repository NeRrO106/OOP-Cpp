#include "Frigider.h"
#include <iostream>
#include <cstring>

using namespace std;

Frigider::Frigider(){
    vol =0;
    culoare = NULL;
    no_frost = false;
}
Frigider::Frigider(double vol, char*col, bool no_frst, char cod[],double pret):Produs(cod,pret){
    this->vol = vol;
    if(col != NULL){
        culoare = new char[strlen(col)+1];
        strcpy(culoare,col);
    }
    no_frost = no_frst;
}

Frigider::Frigider(const Frigider& frigider):Produs(frigider){
    this->vol = frigider.vol;
    if(culoare != NULL) delete[] culoare;
    culoare = new char[strlen(frigider.culoare)+1];
    strcpy(culoare,frigider.culoare);
    no_frost = frigider.no_frost;
}

Frigider& Frigider::operator= (const Frigider& frigider){
    this->vol = frigider.vol;
    if(this->culoare != NULL) delete[] this->culoare;
    this->culoare = new char[strlen(frigider.culoare)+1];
    strcpy(this->culoare,frigider.culoare);
    no_frost = frigider.no_frost;
    Produs::operator=(frigider);
    return *this;
}

void Frigider::afisare(){
    Produs::afisare();
    cout<<vol<<" ";
    if(culoare != NULL){
        cout<< culoare<<" ";
    }
    cout<<no_frost<<" ";
}

double Frigider::get_vol(){
    return Produs::get_vol()+vol;
}

Frigider::~Frigider(){
    if(culoare!=NULL) delete[] culoare;
}
