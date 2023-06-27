#include "Garantie.h"
#include <iostream>
#include <cstring>

using namespace std;

Garantie::Garantie(){
    nr_luni = 0;
    service = "";
}

Garantie::Garantie(int nrluni, string serv){
    nr_luni = nrluni;
    service = serv;
}

Garantie::Garantie(const Garantie& g){
    nr_luni = g.nr_luni;
    service = g.service;
}

Garantie& Garantie::operator=(const Garantie& g){
    nr_luni = g.nr_luni;
    service = g.service;
    return *this;
}

istream& operator>>(istream& din, Garantie& g){
    int nr;
    string serv;
    din>>nr>>serv;
    g = Garantie(nr,serv);
    return din;
}

ostream& operator<<(ostream& dout, const Garantie& g){
    dout<<g.nr_luni<<" "<<g.service<<"\n";
    return dout;
}
int Garantie::getLuni(){
    return nr_luni;
}
string Garantie::getServ(){
    return service;
}
Garantie::~Garantie(){}
