#include<iostream>
using namespace std;
#define ll long long
ll get11(ll k){
    ll v = 1;
    for(int i = 0; i < k - 1; i++){
        v *= 10;
        v ++;
    }
    return v;
}
int main()
{
    ll x;
    cin >> x;
    for(int i = 1; 1 ; i++){
        if(get11(i) % x == 0){
            cout << get11(i) / x << " ";
            cout << i <<endl;
            break;
        }
    }
    return 0;
}