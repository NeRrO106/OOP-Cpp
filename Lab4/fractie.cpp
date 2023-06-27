#include "fractie.h"
#include <iostream>

using namespace std;


Fractie::Fractie(int x, int y){
    a=x;
    b=y;
}
Fractie::Fractie(const Fractie &f){
    a=f.a;
    b=f.b;
}
Fractie& Fractie::operator=(const Fractie &f){
    a=f.a;
    b=f.b;
    return *this;
}
Fractie::~Fractie(){

}
void Fractie::afis() const{
    cout<<a<<"/"<<b<<endl;
}
double Fractie::getValoare() const{
    return (double)a/b;
}
Fractie Fractie::getInv() const{
    return Fractie(b,a);
}
void Fractie::setdata(int x, int y){
    a=x;
    b=y;
}
int Fractie::getA()const{
    return a;
}
int Fractie::getB()const{
    return b;
}

const Fractie operator+(const Fractie &f1, const Fractie &f2){
    return Fractie(f1.a*f2.b+f2.a*f1.b,f1.b*f2.b);
}
const Fractie operator-( const Fractie &f1, const Fractie &f2){
    return Fractie(f1.a*f2.b-f2.a*f1.b,f1.b*f2.b);
}
const Fractie operator-(const Fractie &f){
    return Fractie(-f.a,f.b);
}
const Fractie operator*(const Fractie &f1, const Fractie &f2){
    return Fractie(f1.a*f2.a,f1.b*f2.b);
}
const Fractie operator/(const Fractie &f1, const Fractie &f2){
    return Fractie(f1.a*f2.b,f1.b*f2.a);
}

Fractie& Fractie::operator+=(const Fractie &f){
    *this = *this + f;
    return *this;
}
Fractie& Fractie::operator-=(const Fractie &f){
    *this = *this - f;
    return *this;
}
Fractie& Fractie::operator*=(const Fractie &f){
    *this = *this * f;
    return *this;
}
Fractie& Fractie::operator/=(const Fractie &f){
    *this = *this / f;
    return *this;
}

bool operator==(const Fractie &f1, const Fractie &f2){
    return f1.getValoare() == f2.getValoare();
}
bool operator!=(const Fractie &f1, const Fractie &f2){
    return f1.getValoare() != f2.getValoare();
}
bool operator>(const Fractie &f1, const Fractie &f2){
    return f1.getValoare() > f2.getValoare();
}
bool operator<(const Fractie &f1, const Fractie &f2){
    return f1.getValoare() < f2.getValoare();
}
bool operator>=(const Fractie &f1, const Fractie &f2){
    return f1.getValoare() >= f2.getValoare();
}
bool operator<=(const Fractie &f1, const Fractie &f2){
    return f1.getValoare() <= f2.getValoare();
}
