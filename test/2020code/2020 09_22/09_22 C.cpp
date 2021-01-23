#include<iostream>
using namespace std;
void strong(int &ra, int &rb, int &rc){
    int temp;
    if(rb>ra){
        temp=ra;
        ra=rb;
        rb=temp;
    }
    if(rc>rb){
        temp=rb;
        rb=rc;
        rc=temp;
    }
    if(rb>ra){
        temp=ra;
        ra=rb;
        rb=temp;
    }
}
int main ()
{
    int t;
    int a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        strong(a,b,c);
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    return 0;
}