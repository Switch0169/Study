#include<iostream>
using namespace std;
#define ll long long
ll num[55];
int main()
{
    int n;
    num[1] = 1;
    num[2] = 2; 
    for(int i = 3; i < 55; i++){
        num[i] = num[i - 1] + num[i - 2];
    }
    while(cin >> n){
        cout << num[n] << endl;
    }
    return 0;
}