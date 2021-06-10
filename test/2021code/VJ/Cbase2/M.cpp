#include<iostream>
using namespace std;
#define ll long long
ll num[55];
int main()
{
    int N;
    num[1] = 3;
    num[2] = 6;
    num[3] = 6;
    for(int i = 4; i <= 55; i++){
        num[i] = num[i - 1] + 2 * num[i - 2];
    }
    while (cin >> N){
        cout << num[N] << endl;
    }
    return 0;
}