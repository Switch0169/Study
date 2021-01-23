#include<iostream>
#include<stdio.h>
using namespace std;
class CFraction
{
private:
     int fz, fm;
public:
     CFraction(int fz_val, int fm_val);
     CFraction add(const CFraction &r);
     CFraction sub(const CFraction &r);
     CFraction mul(const CFraction &r);
     CFraction div(const CFraction &r);
     int getfz()const;
     int getfm()const;
     int getGCD();
     void print();
};
int CFraction::getfm()const
{
    return fm;
}
int CFraction::getfz()const
{
    return fz;
}
CFraction::CFraction(int fz_val, int fm_val)
{
    fz=fz_val;
    fm=fm_val;
}
CFraction CFraction::add(const CFraction &r)
{
    int c;
    int fm2,fz2;
    int fm1,fz1;
    fm1=fm*(r.getfm());
    fz1=fz*(r.getfm())+fm*(r.getfz());
    CFraction a(fz1,fm1);
    c=a.getGCD();
    fm2=fm1/c;
    fz2=fz1/c;
    CFraction e(fz2,fm2);
    return e;
}
CFraction CFraction::sub(const CFraction &r)
{
    int c;
    int fm2,fz2;
    int fm1,fz1;
    fm1=fm*(r.getfm());
    fz1=fz*(r.getfm())-fm*(r.getfz());
    CFraction a(fz1,fm1);
    c=a.getGCD();
    fm2=fm1/c;
    fz2=fz1/c;
    CFraction e(fz2,fm2);
    return e;
}
CFraction CFraction::mul(const CFraction &r)
{
    int c;
    int fm2,fz2;
    int fm1,fz1;
    fm1=fm*(r.getfm());
    fz1=fz*(r.getfz());
    CFraction a(fz1,fm1);
    c=a.getGCD();
    fm2=fm1/c;
    fz2=fz1/c;
    CFraction e(fz2,fm2);
    return e;
}
CFraction CFraction::div(const CFraction &r)
{
    int c;
    int fm2,fz2;
    int fm1,fz1;
    fm1=fm*(r.getfz());
    fz1=fz*(r.getfm());
    CFraction a(fz1,fm1);
    c=a.getGCD();
    fm2=fm1/c;
    fz2=fz1/c;
    CFraction e(fz2,fm2);
    return e;
}
int CFraction::getGCD()
{
    int a,b,r,temp;
    a=fz;
    b=fm;
    if(a<b){
        temp=a;
        a=b;
        b=temp;
    }
    while(1){
        r=a%b;
        if(r==0){
            break;
        }
        a=b;
        b=r;
    }
    return b;
}
void CFraction::print()
{
    if(fm<0){
        fz=-fz;
        fm=-fm;
    }
    cout<<fz<<"/"<<fm<<endl;
}
int main()
{
    int t;
    int fz_val,fm_val;
    cin>>t;
    while (t--)
    {
        scanf("%d/%d",&fz_val,&fm_val);
        CFraction a(fz_val,fm_val);
        CFraction b(0,0);
        scanf("%d/%d",&fz_val,&fm_val);
        CFraction r(fz_val,fm_val);
        b=a.add(r);
        b.print();
        b=a.sub(r);
        b.print();
        b=a.mul(r);
        b.print();
        b=a.div(r);
        b.print();
        cout<<endl;
    }
    return 0;
}