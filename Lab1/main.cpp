#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct Produs{
    char *nume;
    int pret;
    char cod[6];
};

void citire(Produs &p){
    char aux[100];
    cin>>aux;
    p.nume = (char*)malloc(sizeof(char)*(strlen(aux)+1));
    strcpy(p.nume,aux);
    cin>>p.pret;
    cin>>p.cod;
}

void salvare(Produs p){
    FILE *f = fopen("stoc.txt","a");
    fprintf(f,"%s",p.nume);
    fprintf(f,"%i",p.pret);
    fprintf(f,"%s\n",p.cod);
    fclose(f);
}

void setarenume(Produs &p, char nume[]){
    free(p.nume);
    p.nume = (char*)malloc(sizeof(char)*(strlen(nume)+1));
    strcpy(p.nume, nume);
}

void copie_profunda(Produs p, Produs &p2){
    p2.nume = (char*)malloc(sizeof(char)*(strlen(p.nume)+1));
    strcpy(p2.nume,p.nume);
    p2.pret = p.pret;
    strcpy(p2.cod,p.cod);
}

int mai_mic(Produs v[], int n, int i){
    int nr=0;
    for(int j=0;j<n;j++){
        if(v[j].pret<v[i].pret) nr++;
    }
    return nr;
}

int main()
{
    int n;
    cin>>n;
    Produs *v = (Produs*)malloc(n*sizeof(Produs));
    for(int i=0;i<n;i++){
        citire(v[i]);
        salvare(v[i]);
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(v[i].pret>v[j].pret){
                swap(v[i],v[j]);
            }
        }
    }
    Produs **m = (Produs**)malloc(n*sizeof(Produs*));
    for(int i=0;i<n;i++){
        m[i] = (Produs*)malloc(n*sizeof(Produs));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                copie_profunda(v[i],m[i][j]);
            }
            else{
                m[i][j].nume = NULL;
                m[i][j].pret = 0;
                strcpy(m[i][j].cod,"00000");
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<m[i][j].nume<<" "<<m[i][j].pret<<" "<<m[i][j].cod<<" ";
        }
        cout<<endl;
    }
    return 0;
}
