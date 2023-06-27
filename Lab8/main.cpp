#include <iostream>
#include "Angajat.h"

using namespace std;

int main()
{
    int dim; cin>>dim;
    Angajat *vect;
    vect = new Angajat[dim];
    for(int i=0;i<dim;i++){
        char str[101];
        cin>>str;
        int nr;
        cin>>nr;
        char aux[101];
        cin>>aux;
        int salar[3];
        for(int i=0;i<3;i++){
            cin>>salar[i];
        }
        Adresa adresa(str,nr);
        Angajat ang(aux,adresa,salar);
        vect[i] = ang;
    }
    for(int i=0;i<dim;i++)cout<<vect[i]<<" ";
    cout<<endl;
    for(int i=0;i<dim-1;i++){
        for(int j=i+1;j<dim;j++){
            if(vect[i].salariu_mediu()>vect[j].salariu_mediu()){
                swap(vect[i],vect[j]);
            }
        }
    }
    return 0;
}
