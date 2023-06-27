#ifndef OS_H
#define OS_H

#include "Produs.h"
#include <string>
class OS: virtual public Produs
{
    protected:
        int pret;
        string versiune;
    public:
        OS();
        OS(int, string);
        int getSuma();
        void afisare();
        ~OS();
};

#endif // OS_H
