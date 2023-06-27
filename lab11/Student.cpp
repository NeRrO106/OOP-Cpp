#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(){
    id_student = 0;
    n = 0;
    note = {};
}

Student::Student(int id, int n, int *note){
    id_student = id;
    this->n = n;
    this->note = new int[n];
    for(int i=0;i<n;i++){
        this->note[i] = note[i];
    }
}

Student::Student(const Student&s){
    id_student = s.id_student;
    n = s.n;
    note = new int[s.n];
    for(int i=0;i<n;i++){
        note[i] = s.note[i];
    }
}

Student& Student::operator=(const Student &s){
    id_student = s.id_student;
    n = s.n;
    note = new int[s.n];
    for(int i=0;i<n;i++){
        note[i] = s.note[i];
    }
    return *this;
}

int Student::getVenit(){
    if(bursa()) return Persoana::getVenit() + 800;
    return 0;
}

double Student::medie(){
    double s = 0;
    for(int i=0;i<n;i++) s+=note[i];
    return s/n;
}

bool Student::bursa(){
    return medie()>8.5;
}

void Student::afisare(){
    Persoana::afisare();
    cout<<id_student<<" ";
    for(int i = 0;i<n;i++) cout<<note[i]<<" ";
    cout<<endl;
}

Student::~Student()
{
    delete[] note;
}
