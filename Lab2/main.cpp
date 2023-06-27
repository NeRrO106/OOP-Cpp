#include <iostream>
#include <cstring>


using namespace std;

struct Angajat {
private:

    char *nume;
    int CNP[14];
    int salariu_baza;
    int spor_salariu[4];
public:
    void init();
    void afisare() const;
    void modificare(const char []);
    void modificare(const Angajat &);
    void modificare(int, int);
int salariu();
};

void Angajat::init(){
    char aux[101];
    cin>>aux;
    nume = new char[strlen(aux)+1];
    strcpy(nume,aux);
    for(int i=0;i<14;i++) cin>>CNP[i];
    cin>>salariu_baza;
    for(int i=0;i<4;i++) cin>>spor_salariu[i];
}

void Angajat::afisare()const{
    cout<<nume<<" ";
    for(int i=0;i<14;i++)cout<<CNP[i];
    cout<<" ";
    cout<<salariu_baza<<" ";
    for(int i=0;i<4;i++)cout<<spor_salariu[i];
}

void Angajat::modificare(const char numenou[]){
    if(nume != NULL)delete[]nume;
    nume = new char[strlen(numenou)+1];
    strcpy(nume,numenou);
}

void Angajat::modificare(const Angajat &copie){
    if(nume != NULL)delete[]nume;
    nume = new char[strlen(copie.nume)+1];
    strcpy(nume,copie.nume);
    for(int i=0;i<14;i++) CNP[i] = copie.CNP[i];
    salariu_baza = copie.salariu_baza;
    for(int i=0;i<4;i++) spor_salariu[i] = copie.spor_salariu[i];
}

void Angajat::modificare(int param1, int param2){//index si valoare
    spor_salariu[param1] = param2;
}

int Angajat::salariu(){
    return salariu_baza+spor_salariu[0]+spor_salariu[1]+spor_salariu[2]+spor_salariu[3];
}

int main()
{
    int n;cin>>n;
    Angajat *vector = new Angajat[n];
    for(int i=0;i<n;i++){
        vector[i].init();
    }
    for(int i=0;i<n;i++){
        vector[i].afisare();
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;i++){
            if(vector[i].salariu() > vector[j].salariu()){
                Angajat aux;
                aux.modificare(vector[i]);
                vector[i].modificare(vector[j]);
                vector[j].modificare(aux);
            }
        }
    }
    delete[]vector;
    return 0;
}
