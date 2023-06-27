#include "Angajat.h"
#include <cstring>

Angajat::Angajat(){
    nume = NULL;
    Adresa(adr);
    for(int i=0;i<3;i++) salariu[i] = 0;
}

Angajat::Angajat(char* numen, Adresa adrn, int salariun[]){
    nume =  new char[strlen(numen)+1];
    strcpy(nume, numen);
    adr = adrn;
    for(int i=0;i<3;i++) salariu[i] = salariun[i];
}
Angajat::Angajat(const Angajat& ang){
    nume =  new char[strlen(ang.nume)+1];
    strcpy(nume, ang.nume);
    adr = ang.adr;
    for(int i=0;i<3;i++) salariu[i] = ang.salariu[i];
}
Angajat& Angajat::operator= (const Angajat& ang){
    if(nume!=NULL) delete[] nume;
    nume =  new char[strlen(ang.nume)+1];
    strcpy(nume, ang.nume);
    adr = ang.adr;
    for(int i=0;i<3;i++) salariu[i] = ang.salariu[i];
    return *this;
}
ostream& operator<<(ostream&dout, const Angajat& ang){
    dout<<ang.nume;
    dout<<ang.adr;
    for(int i=0;i<3;i++) dout<<ang.salariu[i];
    return dout;
}
int Angajat::salariu_mediu(){
    return(salariu[0]+salariu[1]+salariu[2])/3;
}
Angajat::~Angajat(){
    adr.~Adresa();
    if(nume != NULL) delete []nume;
}
