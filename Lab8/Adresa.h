#include <iostream>

using namespace std;

class Adresa
{
    char* strada;
    int nr;
    public:
        Adresa();
        Adresa(char*, int);
        Adresa(const Adresa&);
        Adresa& operator=(const Adresa&);
        ~Adresa();
        friend ostream& operator<<(ostream&, const Adresa&);
};
