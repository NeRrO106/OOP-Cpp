#include <iostream>
#include <cstring>
#include "Garantie.h"

using namespace std;

class Produs
{
    int pret; // ex: 45
    char* marca; // ex: "LG"
    Garantie g;
    public:
        Produs();
        Produs(int, char*, Garantie);
        Produs(const Produs&);
        Produs& operator=(const Produs&);
        friend ostream& operator<<(ostream&, const Produs&);
        friend istream& operator>>(istream&, Produs&);
        int getPrice();
        int getGarantie();
        string getService();
        virtual ~Produs();
};
