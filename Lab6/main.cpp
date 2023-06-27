#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int numarlinii(char *path){
    ifstream fin("date.in");
    char CNP[14];
    int cnt = -1;
    while(!fin.eof()){
        fin>>CNP;
        cnt++;
    }
    fin.close();
    return cnt;
}

void citire(char *path,string *v){
    ifstream fin(path);
    int i=0;
    while(!fin.eof()){
        fin>>v[i];
        i++;
    }
    fin.close();
}

void afisare(string *v, int n){
    ofstream fout("femei.out");
    ofstream bout("barbati.out");
    for(int i=0;i<n;i++){
        if(v[i].at(0)%2==0){
            fout<<v[i]<<endl;
        }
        else bout<<v[i]<<endl;
    }
    fout.close();
    bout.close();
}

void date_nastere(string *v, int n){
    ofstream dnout("date_nastere.out");
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int an1 = (int)v[i].at(1)*10+(int)v[i].at(2);
            int an2 = (int)v[j].at(1)*10+(int)v[j].at(2);
            if(an1<an2){
                swap(v[i],v[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        dnout<<v[i]<<endl;
    }
    dnout.close();
}

void inlocuire(string *v, int n){
    char *path = "date_nastere.out";
    int q = numarlinii(path);
    string *p = new string[q];
    citire(path,p);
    for(int i=0;i<q;i++){
        int poz = v[i].find("010");
        p[i].replace(poz,3,"XY");
    }
    ofstream dnout("date_nastere.out");
    for(int i=0;i<q;i++){
        dnout<<p[i];
    }
    dnout.close();
}

int bonus(string *v, int n){
    int cnt;
    for(int i=0;i<n;i++){
        int sec = (int)v[i].at(8)*10+(int)v[i].at(9);
        if(sec>=40&&sec<50) cnt++;
    }
    return cnt;
}

int main()
{
    char *path = "date.in";
    int n = numarlinii(path);
    string *v = new string[n];
    citire(path,v);
    afisare(v,n);
    date_nastere(v,n);
    cout<<bonus(v,n);
    return 0;
}
