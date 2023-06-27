#include <iostream>

using namespace std;

class Companie
{
    public:
        Companie();
        Companie(char*, int);
        Companie(const Companie&);
        Companie& operator=(const Companie&);
        friend istream& operator>>(istream&, Companie&);
        friend ostream& operator<<(ostream& ,const Companie&);\
        char* getNumeComp();
        ~Companie();

    protected:
        char *nume;
        int an_infiintare;
};
