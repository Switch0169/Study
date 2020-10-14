#include<iostream>
#include<cmath>
using namespace std;
class Equation
{
    double a,b,c;
public:
    Equation();
    Equation(double a_value, double b_value, double c_value);
    void set(double _a, double _b, double _c);
    void getRoot();
};
Equation::Equation()
{
    a=1;
    b=1;
    c=0;
}
Equation::Equation(double a_value, double b_value, double c_value)
{
    a=a_value;
    b=b_value;
    c=c_value;
}
void Equation::set(double _a, double _b, double _c)
{
    a=_a;
    b=_b;
    c=_c;
}
void Equation::getRoot()
{
    double x1,x2;
    if((b*b-4*a*c)>0){
        x1=(-b+sqrt(b*b-4*a*c))/(2*a);
        x2=(-b-sqrt(b*b-4*a*c))/(2*a);
        printf("x1=%.2lf x2=%.2lf\n",x1,x2);
    }
    if((b*b-4*a*c)==0)
    {
        x1=(-b+sqrt(b*b-4*a*c))/(2*a);
        printf("x1=x2=%.2lf\n",x1);
    }
    if((b*b-4*a*c)<0){
        x1=(-b)/(2*a);
        x2=(sqrt(-(b*b-4*a*c)))/(2*a);
        printf("x1=%.2lf+%.2lfi x2=%.2lf-%.2lfi\n",x1,x2,x1,x2);
    }
}
int main()
{
    int t;
    double a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        Equation e(a,b,c);
        e.getRoot();
    }
    return 0;
}