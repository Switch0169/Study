#include<iostream>
using namespace std;
#define ll long long
int main()
{
    ll A, B;
    while(cin >> A >> B){
        if(A == 0 && B == 0){
            break;
        }
        ll ans = 1;
        while(B--){
            ans *= A;
            ans %= 1000;
        }
        cout << ans << endl;
    }
    return 0;
}