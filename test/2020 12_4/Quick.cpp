#include<iostream>
using namespace std;
int Quick(long long base, long long x)
{
    int ans = 1;
    while(x>0){
        if(x%2==1){
            ans = ans * base;
        }
        x = x/2;
        base = base * base;
    }
    return ans;
}
int Quickmod(long long base, long long x, long long mod)
{
    int ans = 1;
    base = base % mod;
    while(x>0){
        if(x%2==1){
            ans = ans * base % mod;
        }
        x = x/2;
        base = base * base % mod;
    }
    return ans;
}
int main()
{
    int base,x,mod;
    cin>>base>>x>>mod;
    cout<<Quick(base,x)<<endl;
    cout<<Quickmod(base,x,mod)<<endl;
    return 0;
}