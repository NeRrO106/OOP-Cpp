#include <iostream>
#include <vector>
#include "Produs.h"
#include "OS.h"
#include "Componenta.h"
#include "Computer.h"
#include "Laptop.h"

using namespace std;

int main()
{
    vector<Produs*> vec;
    vec.push_back(new OS(50,"2023"));
    vector<Componenta> comp;
    int nr; cin>>nr;
    for(int i=0;i<nr;i++){
        int pret; string nume;
        cin>>pret>>nume;
        comp.push_back(Componenta(nume, pret));
    }
    vec.push_back(new Computer(comp,nr));
    vector<string> specs;
    OS sist = OS(50, "2023");
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        specs.push_back(tmp);
    }
    vec.push_back(new Laptop(comp,nr,specs,sist,10));
    int stotal = 0;
    for(auto el:vec){
        stotal+=el->getSuma();
    }
    cout<<stotal<<endl;
    for(auto el:vec) el->afisare();
    if(vec.size()>2){
        vec.erase(vec.begin()+0);
        vec.erase(vec.begin()+1);
    }
    int i;cin>>i;
    if(vec.size()==0) vec.push_back(new OS(10,"2003"));
    else{
        if(i > vec.size()) vec.push_back(new OS(10,"2003"));
        else vec.insert(vec.begin()+i,new OS(10,"2004"));
    }
    return 0;
}
