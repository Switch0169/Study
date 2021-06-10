#include<iostream>
using namespace std;
#define ll long long
ll road[60];
int main()
{
    ll N;
    cin >> N;
    road[1] = 0;
    road[2] = 1;
    road[3] = 2;
    for(int i = 4; i <= 50; i++){
        road[i] = road[i - 1] + road[i - 2];
    }
    while(N--){
        ll a, b;
        cin >> a >> b;
        cout << road[b - a + 1] << endl;
    }
    return 0;
}