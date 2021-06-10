#include<iostream>
#include<cstdio>
using namespace std;
#define ll double
ll getv(ll m, ll n){
    ll base = 1;
    ll top = 1;
    for(int i = 1; i <= n; i++){
        base *= i;
    }
    top /= base;
    for(int i = m; i >= m - n + 1; i--){
        top *= i;
    }
    return top;
}
int main()
{
    int N;
    cin >> N;
    while(N--){
        int M;
        cin >> M;
        ll ans = 0;
        for(int i = 0; i <= (M - 1) / 2; i++){
            ans += getv(M - i - 1, i);
        }
        printf("%.0lf\n", ans);
    }
    return 0;
}
