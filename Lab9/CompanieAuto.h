#ifndef COMPANIEAUTO_H
#define COMPANIEAUTO_H

#include "Companie.h"
#include <string>
using namespace std;

class CompanieAuto : public Companie
{
    public:
        CompanieAuto();
        CompanieAuto(string, int, char*, int);
        CompanieAuto(const CompanieAuto&);
        CompanieAuto& operator=(const CompanieAuto&);
        friend istream& operator>>(istream&, CompanieAuto&);
        friend ostream& operator<<(ostream& ,const CompanieAuto&);
        int getModele();
        ~CompanieAuto();

    protected:
        string descriere;
        int nr_modele;

};

#endif // COMPANIEAUTO_H
