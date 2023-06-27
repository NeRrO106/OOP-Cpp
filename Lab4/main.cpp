#include <iostream>
#include "fractie.h"

using namespace std;

int main()
{
    Fractie a;
    int x,y;
    cin>>x>>y;
    a.setdata(x,y);
    cout<<"a:";
    a.afis();

    Fractie b,c,d,e,f;
    b=c=d=e=f=a;
    cout<<"b:";b.afis();

    Fractie w;
    int v,z;
    cin>>v>>z;
    w.setdata(v,z);

    cout<<"operator+(a+w):";
    Fractie f3 = a+w;
    f3.afis();

    cout<<"operator-(a-w):";
    Fractie f4 = a-w;
    f4.afis();

    cout<<"operator*(a*w):";
    Fractie f5 = a*w;
    f5.afis();

    cout<<"operator==:";
    Fractie f1,f2;
    f1 = Fractie(2,3);
    f2 = Fractie(4,5);
    bool abc = f1 == f2;
    cout<<abc<<endl;

    cout<<"operator<:";
    Fractie f6,f7;
    f6 = Fractie(2,3);
    f7 = Fractie(4,5);
    bool abd = f6 < f7;
    cout<<abd<<endl;

    cout<<"operator>:";
    Fractie f8,f9;
    f8 = Fractie(2,3);
    f9 = Fractie(4,5);
    bool abe = f8 > f9;
    cout<<abe;
    return 0;
}
