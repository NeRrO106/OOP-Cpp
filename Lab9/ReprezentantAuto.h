#include "CompanieAuto.h"


class ReprezentantAuto : public CompanieAuto
{
    public:
        ReprezentantAuto();
        ReprezentantAuto(char*, int, string, int,char*,int);
        ReprezentantAuto(const ReprezentantAuto&);
        ReprezentantAuto& operator=(const ReprezentantAuto&);
        friend istream& operator>>(istream&, ReprezentantAuto&);
        friend ostream& operator<<(ostream& ,const ReprezentantAuto&);
        int getStoc();
        ~ReprezentantAuto();

    protected:
        char *nume_rep;
        int stoc;
};
