#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int Fi[100000];
int main()
{
    int n;
    cin>>n;
    Fi[0]=1;
    Fi[1]=1;
    cout<<Fi[0]<<" "<<Fi[1];
    for(int i=2; i<n; i++){
        Fi[i]=Fi[i-1]+Fi[i-2];
        cout<<" "<<Fi[i];
    }
    return 0;
}