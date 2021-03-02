#include<iostream>
#include<cstdio>
using namespace std;
char ans1[101];
char ans2[101];
int differ = 0;
int same = 0;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        cin>>ans1[i];
    }
    for(int i=0; i<n; i++){
        cin>>ans2[i];
        if(ans1[i]!=ans2[i]){
            differ++;
        }
        else
            same++;
    }
    int max = same*2 + differ;
    int min = 0;
    cout<<max<<" "<<min;
    return 0;
}