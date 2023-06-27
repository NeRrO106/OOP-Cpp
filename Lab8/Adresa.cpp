#include "Adresa.h"
#include <cstring>

Adresa::Adresa(){
    strada = NULL;
    nr=0;
}

Adresa::Adresa(char* stradan, int nrn){
    strada =  new char[strlen(stradan)+1];
    strcpy(strada, stradan);
    nr = nrn;
}
Adresa::Adresa(const Adresa&adr){
    if(adr.strada != NULL){
        strada = new char[strlen(adr.strada)+1];
        strcpy(strada, adr.strada);
    }
    else strada = NULL;
    nr = adr.nr;
}
Adresa& Adresa::operator= (const Adresa&adr){
    if(strada != NULL){
        delete [] strada;
        strada = NULL;
    }
    if(adr.strada != NULL){
        strada = new char[strlen(adr.strada)+1];
        strcpy(strada, adr.strada);
    }
    nr = adr.nr;
    return *this;
}
ostream& operator<<(ostream&dout, const Adresa&adr){
    dout<<adr.strada;
    dout<<adr.nr;
    return dout;
}
Adresa::~Adresa(){
    if(strada != NULL) delete[]strada;
}
