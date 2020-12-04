#include<iostream>
#include<cstdio>
using namespace std;
class Shape{
protected:

public:
    virtual void Area()
    {

    } 
};
class Circle:public Shape{
protected:
    double r;
public:
    Circle(double rr)
    {
        r=rr;
    }
    virtual void Area()
    {
        double a;
        a=r*r*3.14;
        printf("%.2lf\n",a);
    }
};
class Square:public Shape{
protected:
    double l;
public:
    Square(double rl)
    {
        l=rl;
    }
    virtual void Area()
    {
        double a;
        a=l*l;
        printf("%.2lf\n",a);
    }
};
class Rectangle:public Shape{
protected:
    double m;
    double n;
public:
    Rectangle(double mm, double nn)
    {
        m=mm;
        n=nn;
    }
    virtual void Area()
    {
        double a;
        a=m*n;
        printf("%.2lf\n",a);
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        Shape *x[3];
        double r;
        double l;
        double m,n;
        cin>>r>>l>>m>>n;
        Circle a(r);
        Square b(l);
        Rectangle c(m,n);
        x[0]=&a;
        x[1]=&b;
        x[2]=&c;
        x[0]->Area();
        x[1]->Area();
        x[2]->Area();
    }
    return 0;
}