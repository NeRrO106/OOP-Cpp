#include <iostream>
#include <cstring>

using namespace std;

class Garantie
{
    int nr_luni;
    string service;
    public:
        Garantie();
        Garantie(int, string);
        Garantie(const Garantie& g);
        Garantie& operator=(const Garantie&);
        int getLuni();
        string getServ();
        friend ostream& operator<<(ostream&, const Garantie&);
        friend istream& operator>>(istream&, Garantie&);
        virtual ~Garantie();
};
