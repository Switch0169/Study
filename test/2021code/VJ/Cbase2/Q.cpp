#include<iostream>
using namespace std;
#define ll long long
ll num[55];
ll getv(ll m, ll n){
    ll base = 1;
    ll top = 1;
    for(int i = 1; i <= n; i++){
        base *= i;
    }
    for(int i = m; i >= m - n + 1; i--){
        top *= i;
    }
    return top / base;
}
int main()
{
    int C;
    cin >> C;
    num[1] = 0;
    num[2] = 1;
    num[3] = 2;
    for(int i = 4; i <= 55; i++){
        num[i] = (i - 1) * (num[i - 1] + num[i - 2]);
    }
    while(C--){
        ll N, M;
        cin >> N >> M;
        cout << getv(N, M) * num[M] << endl;
    }
    return 0;
}