#include <iostream>
#include "MyString.h"
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin>>n;
    MyString*  vect = (MyString*)malloc(n*sizeof(MyString));
    for(int i=0;i<n;i++){
        cin>>vect[i];
    }
    for(int i=0;i<n;i++){
        cout<<vect[i];
    }
    int lafel = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(vect[i]==vect[j]) lafel++;
        }
    }
    cout<<"Avem "<<lafel<<" cv-uri la fel"<<endl;
    MyString sir;
    for(int i=0;i<n;i++){
        sir + vect[i];
    }
    cout<<sir;
    cout<<"In v[0] sunt "<<vect[0].unic()<<" litere distincte";
    return 0;
}
