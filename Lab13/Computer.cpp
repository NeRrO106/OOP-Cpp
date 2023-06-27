#include "Computer.h"
#include "Componenta.h"
#include <iostream>
#include <vector>

using namespace std;

Computer::Computer(){}
Computer::Computer(vector<Componenta> v, int n){
    for(auto el: v){
        vec.push_back(el);
    }
    nr_componenta = n;
}
int Computer::getSuma(){
    int sum = 0;
    for(auto i : vec) sum+=i.getSuma();
    return sum;
}
void Computer::afisare(){
    for(auto i : vec) i.afisare();
    cout<<" "<<nr_componenta<<endl;
}
Computer::~Computer(){
}
