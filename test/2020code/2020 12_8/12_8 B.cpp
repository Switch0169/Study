#include<iostream>
using namespace std;
class Complex
{
protected:
    float Real,Image;
public:
    Complex()
    {
        Real = 0;
        Image = 0;
    }
    Complex(float x,float y)
    {
        Real = x;
        Image = y;
    }
    friend Complex operator -(Complex &, Complex &);
    friend Complex operator +(Complex &, Complex &);
    friend Complex operator *(Complex &, Complex &);
    void show()
    {
        cout<<"Real="<<Real<<" "<<"Image="<<Image<<endl;
    }
};
Complex operator -(Complex &a, Complex &b){
    Complex ans(a.Real - b.Real,a.Image-b.Image);
    return ans;
}
Complex operator +(Complex &a, Complex &b){
    Complex ans(a.Real + b.Real,a.Image + b.Image);
    return ans;
}
Complex operator *(Complex &a, Complex &b){
    Complex ans(a.Real*b.Real-a.Image*b.Image,a.Real*b.Image+a.Image*b.Real);
    return ans;
}
int main()
{
    float a,b;
    cin>>a>>b;
    Complex x1(a,b);
    cin>>a>>b;
    Complex x2(a,b);
    Complex ans1,ans2,ans3;
    ans1=x1+x2;
    ans1.show();
    ans2=x1-x2;
    ans2.show();
    ans3=x1*x2;
    ans3.show();
    return 0;
}