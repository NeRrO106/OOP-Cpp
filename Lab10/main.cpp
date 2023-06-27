#include <iostream>
#include "Produs.h"
#include "Frigider.h"
#include "Lada_Frigorifica.h"

using namespace std;

int main()
{

    Produs **v = new Produs*[2];
    Frigider frig(50,"galben",true,"abcd",1000);
    double dimension[3] = {1,1,1};
    Lada_Frigorifica lada(dimension,"da","efgh",2000);
    v[0] = new Frigider(frig);
    v[1] = new Lada_Frigorifica(lada);
    for(int i=0;i<1;i++){
        for(int j=i+1;j<2;j++){
            if(v[i]->get_vol()<v[j]->get_vol()){
                swap(v[i],v[j]);
            }
        }
    }
    for(int i=0;i<2;i++){
        v[i]->afisare();
    }
    for(int i=0;i<2;i++){
        if(v[i]->get_vol() < 100) v[i]->afisare();
        cout<<endl;
    }
    return 0;
}
