#include "OS.h"
#include <iostream>
#include <cstring>

using namespace std;

OS::OS(){
    pret =0;
    versiune = "";
}

OS::OS(int pret, string versiune){
    this->pret = pret;
    this->versiune = versiune;
}

void OS::afisare(){
    cout<<pret<<" " <<versiune<<endl;
}

int OS::getSuma(){
    return pret;
}

OS::~OS(){}
