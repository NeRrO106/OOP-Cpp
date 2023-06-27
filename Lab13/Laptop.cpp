#include "Laptop.h"
#include <vector>
#include <iostream>

using namespace std;

Laptop::Laptop()
{

}

Laptop::Laptop(vector<Componenta>v, int n, vector<string> spec, OS sistem, int auton):Computer(v,n){
    for(auto el : spec){
        specificatii.push_back(el);
    }
    sist = sistem;
    this->autonomie = auton;
}

void Laptop::afisare(){
    for(auto i : specificatii) cout<<i<<" ";
    sist.afisare();
    cout<<autonomie<<endl;
}

int Laptop::getSuma(){
    int sum = 0;
    sum +=autonomie * 50;
    sum += sist.getSuma();
    return sum;
}

Laptop::~Laptop(){}
