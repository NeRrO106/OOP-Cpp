#include "Lada_Frigorifica.h"
#include "Frigider.h"
#include <iostream>
#include <cstring>

using namespace std;

Lada_Frigorifica::Lada_Frigorifica(){
    for(int i=0;i<3;i++) dim[i] = 0;
    descriere = NULL;
}
Lada_Frigorifica::Lada_Frigorifica(double dim[3], char*descr, char cod[], double pret):Produs(cod,pret){
    for(int i=0;i<3;i++) this->dim[i] = dim[i];
    if(descr != NULL){
        descriere = new char[strlen(descr)+1];
        strcpy(descriere,descr);
    }
}

Lada_Frigorifica::Lada_Frigorifica(const Lada_Frigorifica& lada):Produs(lada){
    for(int i=0;i<3;i++) this->dim[i] = lada.dim[i];
    if(lada.descriere != NULL){
        descriere = new char[strlen(lada.descriere)+1];
        strcpy(descriere,lada.descriere);
    }
}

Lada_Frigorifica& Lada_Frigorifica::operator= (const Lada_Frigorifica& lada){
    for(int i=0;i<3;i++) this->dim[i] = lada.dim[i];
    if(lada.descriere != NULL){
        descriere = new char[strlen(lada.descriere)+1];
        strcpy(descriere,lada.descriere);
    }
    Produs::operator=(lada);
    return *this;
}

istream& operator>>(istream&din, Lada_Frigorifica& lada){
    char cod [6]; double pret;
    din>>cod;
    din>>pret;
    double dim[3]; char descriere[101];
    for(int i=0;i<3;i++) din>>dim[i];
    cin>>descriere;
    lada = Lada_Frigorifica(dim,descriere,cod,pret);
    return din;
}

void Lada_Frigorifica::afisare(){
    Produs::afisare();
    for(int i=0;i<3;i++) cout<<dim[i]<<" ";
    cout<<endl;
    if(descriere != NULL){
        cout<<descriere<<"\n";
    }
}

double Lada_Frigorifica::get_vol(){
    return Produs::get_vol()+(dim[0]*dim[1]*dim[2]);
}

Lada_Frigorifica::~Lada_Frigorifica()
{
    if(descriere != NULL) delete[] descriere;
}
