#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using namespace std;

class MyString {
    private:
        char *buf;
        int l;
    public:
        MyString();
        MyString(char *);
        MyString(const MyString &);
        MyString& operator=(const MyString &);
        ~MyString();
        friend ostream& operator<<(ostream &, const MyString &);
        friend istream& operator>>(istream &, MyString &);
        char& operator[](int);
        friend const MyString operator+(const MyString &,const MyString &);
        MyString& operator+=(const MyString &);
        friend bool operator==(const MyString &, const MyString &);
        friend bool operator!=(const MyString &, const MyString &);
        int lookFor(char);
        int unic();
};

#endif // MYSTRING_H
