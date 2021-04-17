#include<iostream>
#include<cstdio>
using namespace std;
int grade[100000];
int maxn = 0;
int minx = 100000;
double t = 0;
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>grade[i];
        if(grade[i] > maxn){
            maxn = grade[i];
        }
        if(grade[i] < minx){
            minx = grade[i];
        }
        t += grade[i];
    }
    t /= n;
    cout<<maxn<<endl<<minx<<endl;
    printf("%.2lf", t);
    return 0;
}