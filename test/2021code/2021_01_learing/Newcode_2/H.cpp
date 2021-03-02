#include<iostream>
using namespace std;
int Q[1000][1000];
int main()
{
    int n;
    scanf(" %d",&n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0&&j==0){
                continue;
            }
            else if(i==0){
                if(Q[i][j-1]==0){
                    Q[i][j]=1;
                }
                else{
                    Q[i][j]=0;
                }
            }
            else if(j==0){
                if(Q[i-1][j]==0){
                    Q[i][j]=1;
                }
                else{
                    Q[i][j]=0;
                }
            }
            else{
                if(Q[i][j-1]==0){
                    Q[i][j]=1;
                }
                else{
                    Q[i][j]=0;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d",Q[i][j]);
        }
        printf("\n");
    }
    return 0;
}