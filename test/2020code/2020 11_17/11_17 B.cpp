#include<iostream>
using namespace std;
class CVehicle{
protected:
    int max_speed;
    int speed;
    int weight;
public:
    CVehicle(int m, int s, int w)
    {
        max_speed=m;
        speed=s;
        weight=w;
    }
    virtual void display()
    {
        cout<<"Vehicle:"<<endl<<"max_speed:"<<max_speed<<endl<<"speed:"<<speed<<endl<<"weight:"<<weight<<endl<<endl;
    }
};
class CBicycle : public CVehicle{
protected:
    int height;
public:
    CBicycle(int m, int s, int w, int h):CVehicle(m,s,w)
    {
        height=h;
    }
    virtual void display()
    {
        cout<<"Bicycle:"<<endl<<"max_speed:"<<max_speed<<endl<<"speed:"<<speed<<endl<<"weight:"<<weight<<endl<<"height:"<<height<<endl<<endl;
    }
};
class CMotocar:public CVehicle{
protected:
    int seat_num;
public:
    CMotocar(int m, int s, int w, int num):CVehicle(m,s,w)
    {
        seat_num=num;
    }
    virtual void display()
    {
        cout<<"Motocar:"<<endl<<"max_speed:"<<max_speed<<endl<<"speed:"<<speed<<endl<<"weight:"<<weight<<endl<<"seat_num:"<<seat_num<<endl<<endl;
    }
};
class CMotocycle:public CBicycle, public CMotocar{
public:
    CMotocycle(int m, int s, int w, int h, int num):CMotocar(m,s,w,num),CBicycle(m,s,w,h)
    {

    }
    virtual void display()
    {
        cout<<"Motocycle:"<<endl<<"max_speed:"<<CMotocar::max_speed<<endl<<"speed:"<<CMotocar::speed<<endl<<"weight:"<<CMotocar::weight<<endl<<"height:"<<height<<endl<<"seat_num:"<<seat_num<<endl<<endl;
    }
};
int main ()
{
    int m, s, w;
    int h,num;
    cin>>m>>s>>w;
    CVehicle a(m,s,w);
    a.display();
    cin>>h;
    CBicycle b(m,s,w,h);
    b.display();
    cin>>num;
    CMotocar c(m,s,w,num);
    c.display();
    CMotocycle d(m,s,w,h,num);
    d.display();
    return 0;
}