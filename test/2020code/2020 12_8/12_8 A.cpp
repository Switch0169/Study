#include<iostream>
using namespace std;
class Fraction{
    int denominator,numerator;
    int common_divisor();
    void contracted();
public:
    Fraction()
    {
        denominator = 0;
        numerator = 0;
    }
    Fraction(int a, int b)
    {
        numerator = a;
        denominator = b;
    }
    Fraction operator+(Fraction d)
    {
        Fraction a;
        a.denominator=denominator*d.denominator;
        a.numerator=numerator*d.denominator+d.numerator*denominator;
        return a;
    }
    Fraction operator-(Fraction d)
    {
        Fraction a;
        a.denominator=denominator*d.denominator;
        a.numerator=numerator*d.denominator-d.numerator*denominator;
        return a;
    }
    Fraction operator*(Fraction d)
    {
        Fraction a;
        a.denominator=denominator*d.denominator;
        a.numerator=numerator*d.numerator;
        return a;
    }
    Fraction operator/(Fraction d)
    {
        Fraction a;
        a.denominator=denominator*d.numerator;
        a.numerator=numerator*d.denominator;
        return a;
    }
    void Set(int=0,int=1);
    void disp(){cout<<"fraction="<<numerator<<"/"<<denominator<<endl;}
};
int main()
{
    int a,b;
    cin>>a>>b;
    Fraction x1(a,b);
    cin>>a>>b;
    Fraction x2(a,b);
    Fraction x3;
    x3 = x1 + x2;
    x3.disp();
    x3 = x1 - x2;
    x3.disp();
    x3 = x1 * x2;
    x3.disp();
    x3 = x1 / x2;
    x3.disp();
    return 0;
}