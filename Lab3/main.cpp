#include <iostream>
#include "Client.cpp"
#include "Client.h"


using namespace std;

int main()
{
    int n;cin>>n;
    Client *v = new Client[n];

    for(int i=0;i<n;i++){
        char nume[101],cnp[14];
        double sold;
        cin>>nume>>cnp>>sold;
        Client temp = Client(nume,cnp,sold);
        v[i].modificare(temp);
    }
    for(int i=0;i<n;i++){
        v[i].afisare();

        cout<<endl;
    }
    cout<<"ok";
    cout<<endl;
    int cl1,cl2;
    cin>>cl1>>cl2;
    Client temp = Client();
    temp.modificare(v[cl1]);
    v[cl1].modificare(v[cl2]);
    v[cl2].modificare(temp);

    int f=0,b=0;
    for(int i=0;i<n;i++){
        char *cnp = v[i].getCNP();
        if((int)cnp[0]%2==0) f++;
        else b++;
    }
    cout<<b<<" "<<f<<"baieti+fete";

    for(int i=0;i<n;i++){
        if(v[i].getSold()>50000){
            v[i].afisare();
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(v[i].getName(),v[j].getName())<0){
                Client temp = Client();
                temp.modificare(v[i]);
                v[i].modificare(v[j]);
                v[j].modificare(temp);
            }
        }
    }

    return 0;
}
