#include <assert.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template <typename T>
class vector{
    int dim;
    T* buf;
public:
        vector();
        vector(int, T*);
        vector(const vector&);
        vector &operator=(const vector&);
        ~vector();
        T& operator[](int i);
        int getDim();
        friend ostream & operator << (ostream& dout, vector& v){
            dout<<v.dim<<endl;
            for(int i=0;i<v.dim;i++){
                dout<<v.buf[i];
                dout<<" ";
            }
            dout<<endl;
            return dout;
        }
        void addElem(int i, T&elem){
            if(i>dim) {
                cout<<"Nu se poate adauga un element pe poz "<<i<<endl;
                return;
            }
            else{
                dim+=1;
                buf = (T*)realloc(buf, dim*sizeof(T));
                for(int j=dim-2;j>=i;j--)buf[j+1] = buf[j];
                buf[i] = elem;
            }
        }
        void removeElem(int i){
            for(int j=i;j<dim;j++){
                    buf[j] = buf[j+1];
            }
            dim-=1;
            buf=(T*)realloc(buf,dim*sizeof(T));
        }
        void sortare(){
            for(int i=0;i<dim-1;i++){
                for(int j=i+1;j<dim;j++){
                    if(buf[i] > buf[j]) swap(buf[i],buf[j]);
                }
            }
        }
};
template <typename T>
vector<T>::vector(){
    dim = 0;
    buf = NULL;
}
template <typename T>
vector<T>::vector(int d, T*b){
       dim=d;
       if (b==NULL) buf = NULL;
       else{
          buf=new T[dim];
          for (int i=0;i<dim;i++)
            buf[i]=b[i];
        }
     }


template <typename T>
vector<T>::vector(const vector<T>& v){
       dim=v.dim;
       if (v.buf==NULL) buf=NULL;
       else{
          buf=new T[dim];
          for (int i=0;i<dim;i++)
             buf[i]=v.buf[i];
        }
     }


template <typename T>
vector<T>::~vector(){
        if (buf!=NULL) delete [] buf;
}

template <typename T>
vector<T>&  vector<T>::operator=(const vector &v){
       dim=v.dim;
       if (buf!=NULL) delete [] buf;
       if (v.buf==NULL) buf=NULL;
       else{
          buf=new T[dim];
          for (int i=0;i<dim;i++)
             buf[i]=v.buf[i];
        }
        return *this;
}

template <typename T>
T& vector<T>::operator[](int i){
      assert ((i>-1 && i<dim));
      return buf[i];
}

template <typename T>
int vector<T>::getDim(){
   return dim;
}
class complex{
    double re,im;
    public:
        complex(double r=0,double i=0):re(r),im(i){}
        friend ostream& operator<<(ostream& dout, complex &x){
            dout<<x.re<<"."<<x.im<<" ";
            return dout;
        }
        bool operator>(complex n){
            return re<n.re;
        }

};

class fractie{
    double a, b;
    public:
        fractie(double x=0,double y=0):a(x),b(y){}
        friend ostream& operator<<(ostream& dout, fractie&x){
            dout<<x.a<<"/"<<x.b<<" ";
            return dout;
        }
        bool operator>(fractie x){
            return a/b < x.a/x.b;
        }
};

template <typename X, typename Y>
class pereche{
    X elem1;
    Y elem2;
    public:
        pereche(){}
        pereche(const X&e1, const Y&e2){
            elem1 = e1;
            elem2 = e2;
        }
        friend ostream& operator<<(ostream &dout, const pereche&x){
            dout<<x.elem1<<" si "<<x.elem2<<endl;
            return dout;
        }
        bool operator<(pereche n){
            return true;
        }
};

int main()
{
    cout<<"clasa complex din alt laborator"<<endl;;
    complex *b = new complex[2];
    b[0] = complex(4,7);
    b[1] = complex(7,9);
    vector<complex> v(2,b);
    cout<<v<<endl;
    complex x(6,6);
    complex y(9,9);
    v.addElem(1,x);
    v.addElem(1,y);
    v.removeElem(1);
    cout<<v<<endl;
    v.sortare();
    cout<<v<<endl;

    cout<<"specializare int"<<endl;
    int *intv = new int[2];
    intv[0] = 4;
    intv[1] = 10;
    vector<int> v2(2,intv);
    cout<<v2;
    cout<<endl;

    cout<<"specializare string"<<endl;
    string *stringvect = new string[3];
    stringvect[0] = "mere";
    stringvect[1] = "are";
    stringvect[2] = "ana";
    vector<string> v3(3,stringvect);
    cout<<v3;
    cout<<endl;

    cout<<"Specializare fractie"<<endl;
    fractie *vfrc =  new fractie[3];
    vfrc[0] = fractie(10,4);
    vfrc[1] = fractie(5,6);
    vfrc[2] = fractie(6,9);
    vector<fractie> v4(3,vfrc);
    v4.sortare();
    cout<<v4<<endl;

    cout<<"Specializare pereche(BONUS)"<<endl;
    pereche<string, string> a1 = pereche<string, string>("dog","catel");
    pereche<string, string> b1 = pereche<string, string>("car","masina");
    pereche<string, string> c1 = pereche<string, string>("cat","pisica");
    pereche<string, string> vp[] = {a1,b1,c1};
    pereche<string, string> *vpr = vp;
    vector<pereche<string, string> > v5(3,vpr);
    cout<<v5;
    return 0;
}
