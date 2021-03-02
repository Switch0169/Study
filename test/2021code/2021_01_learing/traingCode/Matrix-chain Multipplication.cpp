#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n, r, c;
    scanf("%d",&n);
    int p[101]={0};
    int m[100][100]={{0}};
    for(int i=1; i<=n; i++){
        scanf("%d %d",&r, &c);
        if(i==1){
            p[0]=r;
        }
        p[i]=c;
    }
    for(int i=n; i>=1; i--){
        for(int j=i; j<=n; j++){
            if(i==j){
                m[i][j]=0;
            }
            else if(i<j){
                int min = 1000000000;
                int temp = 0;
                for(int k=i; k<j; k++){
                    temp = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                    if(min>temp){
                        min = temp;
                    }
                }
                m[i][j]=min;
            }
        }
    }
    cout<<m[1][n]<<endl;     
    return 0;
}