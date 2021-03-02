//https://ac.nowcoder.com/acm/contest/9981
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int mod = pow(10,9) + 7;
long long Quick(long long base, long long x)
{
    long long ans = 1;
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
    long long n;
    scanf("%d",&n);
    long long ans = (n*(n-1))/2*Quick(26,n-2) - Quick(((n*(n-1))/2-1),2);
    printf("%lld",ans);
    return 0;
}