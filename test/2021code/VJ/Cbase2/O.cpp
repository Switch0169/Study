#include<iostream>
using namespace std;
#define ll long long
ll num[55];
int main()
{
    int n;
    num[1] = 3;
    num[2] = 8;
    for(int i = 3; i <= 50; i++){
        num[i] = 2 * num[i - 2] + 2 * num[i - 1];
    }
    while(cin >> n){
        cout << num[n] << endl;
    }
    return 0;
}