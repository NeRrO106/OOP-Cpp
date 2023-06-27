#include <iostream>
#include "Stud_Angajat.h"

using namespace std;

int main()
{
    int note1[] = {9,8,7};
    Student p1(24,3,note1);
    Angajat p2(0,10000);
    int note2[] = {5,6,7,8,9};
    Stud_Angajat p3(1,5,note2,1,4000);

    Persoana **p = new Persoana*[3];
    p[0] = new Student(p1);
    p[1] = new Angajat(p2);
    p[2] = new Stud_Angajat(p3);

    for(int i=0;i<3;i++){
        p[i]->afisare();
        cout<<endl;
    }

    for(int i=0;i<2;i++){
        for(int j=i+1;j<3;j++){
            if(p[i]->getVenit()<p[j]->getVenit()){
                swap(p[i],p[j]);
            }
        }
    }

    cout<<endl;
    for(int i=0;i<3;i++){
        p[i]->afisare();
        cout<<endl;
    }
    return 0;
}
