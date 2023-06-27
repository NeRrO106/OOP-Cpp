#include "MyString.h"
#include <iostream>
#include <cstring>
#include <assert.h>
#include <cstdlib>

using namespace std;


MyString::MyString(){
    l=0;
    buf = NULL;
}

MyString::MyString(char *s){
    l = strlen(s);
    if(s != NULL){
        buf = new char[strlen(s)+1];
        strcpy(buf,s);
    }
}

MyString::MyString(const MyString &v){
    if(this != &v){
        if(buf != NULL) delete []buf;
        l=v.l;
        if(l<=0) buf = NULL;
        else{
            buf = new char[l];
            for(int i=0;i<l;i++)
                buf[i] = v.buf[i];
        }
    }
}
MyString& MyString::operator=(const MyString &v){
    if(this !=&v){
        if(buf != NULL) delete []buf;
        l=v.l;
        if(l<=0) buf = NULL;
        else{
            buf = new char[l];
            for(int i=0;i<l;i++) buf[i] = v.buf[i];
        }
    }
    return *this;
}
MyString::~MyString(){
    if(buf !=NULL) delete[] buf;
}
ostream& operator<<(ostream &dout, const MyString &v){
    if(v.buf != NULL && v.l>0){
        dout<<"Vector:";
        dout<<v.l<<" ";
        for(int i=0;i<v.l;i++) dout<<v.buf[i];
        dout<<endl;
    }
    return dout;
}
istream& operator>>(istream &din, MyString &v){
    char aux[101];
    din>>aux;
    v.buf = new char [strlen(aux)+1];
    strcpy(v.buf,aux);
    v.l = strlen(aux);
    return din;
}
char& MyString::operator[](int x){
    assert (x >= 0 && x < l);
    return buf[x];
}
const MyString operator+(const MyString &sir1,const MyString &sir2){
    if(sir1.l && sir2.l > 0){
        if(sir1.buf != NULL && sir2.buf != NULL){
            MyString v;
            v.l = sir1.l+sir2.l;
            v.buf = new char(v.l+1);
            strcat(v.buf,sir1.buf);
            strcat(v.buf,sir2.buf);
        }
    }
}

MyString& MyString::operator+=(const MyString &m){
    if(m.l !=0 && m.buf != NULL){
        l+=m.l;
        char temp[l];
        strcpy(temp,buf);
        delete [] buf;
        strcat(buf,temp);
        strcat(buf,m.buf);
    }
    if(this->buf==NULL){
        this->buf = (char*)malloc(sizeof(char)*(strlen(m.buf)+1));
        strcpy(this->buf,m.buf);
    }
    return *this;
}
bool operator==(const MyString &sir1, const MyString &sir2){
    if(sir1.l != sir2.l) return false;
    if(strcmp(sir1.buf,sir2.buf))return false;
    return true;
}
bool operator!=(const MyString &sir1, const MyString &sir2){
    return !(sir1==sir2);
}
int MyString::lookFor(char s){
    int k=0;
    for(int i=0;i<l;i++){
        if(buf[i]==s) k++;
    }
    return k;
}
int MyString::unic() {
	int cnt = 0;
	for (int i = 0; i < strlen(buf); i++)
		if (lookFor(buf[i]) == 1)cnt++;
	return cnt;
}
