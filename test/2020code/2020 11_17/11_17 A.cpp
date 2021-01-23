#include<iostream>
#include<cmath>
using namespace std;
class C2D{
protected:
    double x;
    double y;
public:
    C2D(double x1, double y1)
    {
        x=x1;
        y=y1;
    }
    virtual double getDistance( )
    {
        double d;
        d=sqrt(x*x+y*y);
        return d;
    }
};
class C3D : public C2D{
protected:
    double z;
public:
    C3D(double x1, double y1, double z1):C2D(x1,y1)
    {
        z=z1;
    }
    double getDistance( )
    {
        double d;
        d=sqrt(x*x+y*y+z*z);
        return d;
    }
};
int main()
{
    double x1,y1,z1;
    cin>>x1>>y1;
    C2D a(x1,y1);
    cout<<a.getDistance( )<<endl;
    cin>>x1>>y1>>z1;
    C3D b(x1,y1,z1);
    cout<<b.getDistance( )<<endl;
    cin>>x1>>y1>>z1;
    C3D c(x1,y1,z1);
    cout<<c.getDistance( )<<endl;
    C2D d = c;
    cout<<d.getDistance( )<<endl;
    return 0;
}