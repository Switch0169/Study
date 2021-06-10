#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double pointx[100];
double pointy[100];
int n;
double getarea(int a, int b, int c, int d, int e, int f)
{
    return (a*d + b*e + c*f - a*f - b*c - d*e) / 2.0;
}
int main()
{
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        for(int i = 0; i < n; i++){
            cin >> pointx[i] >> pointy[i];
        }
        double ans = 0;
        for(int i = 1; i < n-1; i++) {
            ans += getarea(pointx[0], pointy[0], pointx[i], pointy[i], pointx[i+1], pointy[i+1]);
        }
        printf("%.1f\n", ans);
    }
    return 0;
}