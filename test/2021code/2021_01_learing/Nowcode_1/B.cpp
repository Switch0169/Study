#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int maxn = pow(10,5);
int main()
{
    int n;
    cin>>n;
    if(n<=maxn){
        printf("(");
        while(n--){
            printf(")");
        }
    }
    else{
        int tt = sqrt(n);
        int ttt = tt * tt;
        int singel = n - ttt;
        
    }
    return 0;
}