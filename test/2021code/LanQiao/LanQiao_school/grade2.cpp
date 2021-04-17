#include<iostream>
#include<cstdio>
using namespace std;
double y = 0;
double j = 0;
double rate1 = 0;
double rate2 = 0;
double grade[100000];
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin>>grade[i];
        if(grade[i] >= 60){
            j++;
        }
        if(grade[i] >= 85){
            y++;
        }
    }
    rate1 = j / n;
    rate2 = y / n;
    printf("%.0f%%\n", rate1*100);
    printf("%.0f%%\n", rate2*100);
    return 0;
}