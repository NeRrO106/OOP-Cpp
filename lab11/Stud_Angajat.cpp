#include "Stud_Angajat.h"
#include "Student.h"
#include "Angajat.h"
#include <iostream>

using namespace std;

Stud_Angajat::Stud_Angajat()
{

}

Stud_Angajat::Stud_Angajat(int ids, int n, int *note, int ida, int salariu):Student(ids, n, note),Angajat(ida, salariu){

}

Stud_Angajat::Stud_Angajat(const Stud_Angajat&s):Student(s.id_student, s.n, s.note), Angajat(s.id_angajat, s.salariu){

}

Stud_Angajat& Stud_Angajat::operator=(const Stud_Angajat&s){
    Student::operator=(s);
    Angajat::operator=(s);
    return *this;
}

void Stud_Angajat::afisare(){
    Student::afisare();
    Angajat::afisare();
}
int Stud_Angajat::getVenit(){
    return Student::getVenit() + Angajat::getVenit();
}

Stud_Angajat::~Stud_Angajat()
{

}
