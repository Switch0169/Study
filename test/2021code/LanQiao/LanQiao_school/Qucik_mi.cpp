#include<iostream>
using namespace std;
#define ll long long
ll mod(ll n, ll p)
{
    if(n >= p){
        while(n >= p){
            n -= p;
        }
    }
    else if(n < 0){
        while(n < 0){
            n += p;
        }
    }
    return n;
}
ll Quick_mi(ll base, ll n, ll P)
{
    ll total = 1;
    base = base % P;
    while(n > 0){
        if(n % 2 == 1){
            total *= base;
            total %= P;
        }
        n = n / 2;
        base = base * base;
        base = base % P;
    }
    return total;
}
int main()
{ 
    //freopen("in.txt", "r", stdin);
    ll N, M, P;
    cin>>N>>M>>P;
    cout<<Quick_mi(N, M, P);
    return 0;
}