#include<iostream>
using namespace std;
#define ll long long
int num[] = {2, 3, 4, 5, 6, 7, 8, 9};
ll getvalue(ll t){
    ll v = 0;
    while(t > 0){
        v += t % 10;
        t /= 10;
    }
    return v;
}
int main()
{
    ll N;
    cin >> N;
    while (N --){
        int k;
        cin >> k;
        int o = getvalue(k * num[0]);
        int flag = 1;
        for(int i = 1; i < 8; i++){
            if(o != getvalue(k * num[i])){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            cout << o << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}