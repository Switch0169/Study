#include<iostream>
using namespace std;
class complex{
public:
    complex(){
        real=0;
        imag=0;
    }
    complex(double r, double i)
    {
        real=r;
        imag=i;
    }
    complex(complex &r){
        real=r.real;
        imag=r.imag;
    }
    friend complex addCom(complex c1, complex c2){
        int r,i;
        r=c1.real+c2.real;
        i=c1.imag+c2.imag;
        complex a(r,i);
        return a;
    }
    friend complex minusCom(complex c1,complex c2){
        double r,i;
        r=c1.real-c2.real;
        i=c1.imag-c2.imag;
        complex a(r,i);
        return a;
    }
    friend void outCom(complex c){
        cout<<"("<<c.real<<","<<c.imag<<")"<<endl;
    }
private:
    double real;
    double imag;
};
int main()
{
    double t;
    double a,b;
    cin>>a>>b;
    cin>>t;
    char ch;
    complex m(a,b);
    while(t--){
        cin>>ch;
        cin>>a>>b;
        complex n(a,b);
        if(ch=='+'){
            m=addCom(m,n);
        }
        if(ch=='-'){
            m=minusCom(m,n);
        }
        outCom(m);
    }
    return 0;
}