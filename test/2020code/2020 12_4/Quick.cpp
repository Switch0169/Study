#include<iostream>
using namespace std;
long long Quick(long long base, long long x)
{
    long long ans = 1;
    while(x>0){
        if(x%2==1){
            ans = ans * base;
        }
        x = x/2;
        base = base * base;
    }
    return ans;
}
long long Quickmod(long long base, long long x, long long mod)
{
    long long ans = 1;
    base = base % mod;
    while(x>0){
        if(x%2==1){
            ans = Quickaddmod(ans,base,mod);
        }
        x = x/2;
        base = Quickaddmod(base,base,mod);
    }
    return ans;
}
long long Quickaddmod(long long m, long long n, long long mod)
{
    long long ans = 0;
    m = m % mod;
    while(n>0){
        if(n%2==1){
            ans = (ans + m)% mod;
        }
        n = n/2;
        m = (m + m) % mod;
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