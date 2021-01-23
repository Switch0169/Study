#include<iostream>
using namespace std;
class Material{
protected:
    int strength;
    int weight;
    int volume;
public:
    Material(int s, int w, int v)
    {
        strength = s;
        weight = w;
        volume = v;
    }
    friend Material operator +(Material &ra, Material &rb);
    friend Material operator *(Material &ra, int n);
    friend Material operator ++(Material &ra);
    friend Material operator --(Material &ra, int )
    {
        int s = ra.strength - 1;
        int w = ra.weight * 9 / 10;
        int v = ra.volume * 9 / 10;
        Material x(s,w,v);
        return x;
    }
    void print(){
        cout<<"硬度"<<strength<<"--"<<"重量"<<weight<<"--"<<"体积"<<volume<<endl;
    }
};
Material operator +(Material &ra, Material &rb){
    int s = ra.strength + rb.strength;
    int w = ra.weight + rb.weight;
    int v = ra.volume + rb.volume;
    Material x(s,w,v);
    return x;
}
Material operator *(Material &ra, int n){
    int s = ra.strength;
    int w = ra.weight;
    int v = ra.volume * n;
    Material x(s,w,v);
    return x;
}
Material operator ++(Material &ra){
    int s = ra.strength + 1;
    int w = ra.weight * 11 / 10;
    int v = ra.volume * 11 / 10;
    Material x(s,w,v);
    return x;
}
int main()
{
    int s,w,v;
    cin>>s>>w>>v;
    Material a(s,w,v);
    cin>>s>>w>>v;
    Material b(s,w,v);
    Material c(0,0,0);
    int n;
    cin>>n;
    c = a + b;
    c.print();
    c = a * n;
    c.print();
    c = ++a;
    c.print();
    c = b--;
    c.print();
    return 0;
}