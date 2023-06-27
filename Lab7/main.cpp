#include <iostream>
#include "Produs.h"
#include <cstring>

using namespace std;

int main()
{
    int n;
    cin>>n;
    Produs* p = new Produs[n];
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cout<<p[i]<<" ";
    cout<<endl;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].getPrice() > p[j].getPrice()){
                Produs temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<p[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++){
        if(p[i].getGarantie() > 12) cout<<p[i];
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        if(p[i].getService() == "SerVice") cout<<p[i];
        cout<<endl;
    }
    return 0;
}
