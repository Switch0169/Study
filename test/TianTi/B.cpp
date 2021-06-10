#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    double A;
    double B;
    cin >> A >> B;
    double X = A / B;
    printf("%.0f/%.1f=%.0f\n", A, X, B);
    return 0;
}