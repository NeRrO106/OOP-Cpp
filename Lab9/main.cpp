#include <iostream>
#include <cstring>
#include "ReprezentantAuto.h"
using namespace std;

int main()
{
    int n; cin>>n;
    ReprezentantAuto *ra = new ReprezentantAuto[n];
    for(int i=0;i<n;i++){
        cin>>ra[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ra[i].getStoc() > ra[j].getStoc()){
                ReprezentantAuto temp = ra[i];
                ra[i] = ra[j];
                ra[j] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(strcmp(ra[i].getNumeComp(),"PSA")==0&&ra[i].getModele()>5&&ra[i].getStoc()<10){
            cout<<ra[i];
        }
    }
    return 0;
}
