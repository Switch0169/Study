#include<iostream>
using namespace std;
class point{

    int x;
    int y;
    int z;
public:
    point(int X, int Y, int Z)
    {x=X;y=Y;z=Z;}
    void Set(int X, int Y, int Z)
    {
        x=X;
        y=Y;
        z=Z;
    }
    friend point operator ++(point &a);
    friend point operator ++(point &a, int m);
    friend point operator --(point &a);
    friend point operator --(point &a, int m);
    void show()
    {
        cout<<"x="<<x<<" "<<"y="<<y<<" "<<"z="<<z<<endl;
    }        
};
point operator ++(point &a)
{
    a.x++;
    a.y++;
    a.z++;
    a.show();
    return a;
}
point operator ++(point &a, int )
{
    point b(a.x,a.y,a.z);
    a.x++;
    a.y++;
    a.z++;
    return b;
}
point operator --(point &a)
{
    a.x--;
    a.y--;
    a.z--;
    a.show();
    return a;
}
point operator --(point &a, int )
{
    point b(a.x,a.y,a.z);
    a.x--;
    a.y--;
    a.z--;
    return b;
}
int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    point p1(x,y,z);
    point p2(0,0,0);
    p1++;
    p1.show();
    p1.Set(x,y,z);
    p2=p1++;
    p2.show();
    p1.Set(x,y,z);
    ++p1;
    p1.show();
    p1.Set(x,y,z);
    p1--;
    p1.show();
    p1.Set(x,y,z);
    p1.show();
    p1.Set(x,y,z);
    --p1;
    p1.show();
    return 0;
}