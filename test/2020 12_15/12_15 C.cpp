#include<iostream>
using namespace std;
class RMB{
protected:
    int yuan;
    int jiao;
    int fen;
public:
    RMB(double a){
        a = a + 0.000001;
        int ra = a * 100;
        fen = ra %10;
        ra = ra / 10;
        jiao = ra % 10;
        ra = ra / 10;
        yuan = ra ;
    }
    void display(ostream &out)
    {
        cout<<"yuan="<<yuan<<" "<<"jiao="<<jiao<<" "<<"fen="<<fen<<endl;
    }
    friend ostream& operator<<(ostream &oo, RMB &a);
};
ostream& operator<<(ostream &oo, RMB &a)
{
    a.display(oo);
    return oo;
}
int main()
{
    int t;
    cin>>t;
    double x;
    while(t--){
        cin>>x;
        RMB a(x);
        cout<<a;
    }
    return 0;
}