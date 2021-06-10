#include<iostream>
#include<cstdio>
using namespace std;
double num[55];
double getv(int n){
    double ans = 1;
    for(int i = 1; i <= n; i++){
        ans *= i;
    }
    return ans;
}
int main()
{
    int C;
    cin >> C;
    num[1] = 0;
    num[2] = 1;
    num[3] = 2;
    for(int i = 4; i <= 21; i++){
        num[i] = (i - 1) * (num[i - 1] + num[i - 2]);
    }
    while(C--){
        int N;
        cin >> N;
        printf("%.2lf%%\n", (num[N] / getv(N)) * 100);
    }
    return 0;
}