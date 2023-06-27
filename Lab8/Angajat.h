#include <iostream>
#include "Adresa.h"

using namespace std;

class Angajat{
    char* nume;
    Adresa adr;
    int salariu[3];
    public:
        Angajat();
        Angajat(char*, Adresa, int[]);
        Angajat(const Angajat&);
        Angajat& operator=(const Angajat&);
        ~Angajat();
        int salariu_mediu();
        friend ostream& operator<<(ostream& ,const Angajat&);
};
