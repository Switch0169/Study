#include<iostream>
using namespace std;
#define ll long long
ll line[100001];
int main()
{
    line[1] = 2;
    line[2] = 4;
    for(int i = 3; i < 100000; i++){
        line[i] = line[i - 1] - 2 * (i - 1) + (i - 2) + 2 * i;
    }
    int C;
    cin >> C;
    while(C--){
        int n;
        cin >> n;
        cout << line[2 * n] - 2 * n << endl;
    }
    return 0;
}