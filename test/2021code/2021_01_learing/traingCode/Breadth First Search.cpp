#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int access[100][100];
int visited[100];
int allowvisit[100];
int lenth[100];
queue<int> Q;
int main()
{
    int m;
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        int n;
        scanf("%d",&n);
        int q;
        scanf("%d",&q);
        while(q--){
            int k;
            scanf("%d",&k);
            access[n][k]=1;
        }
        lenth[i+1]=-1;
    }
    lenth[1]=0;
    int i=1;
    // for(int i=1; i<m+1; i++){
    //     if(visited[i]==0){
            Q.push(i);
        // }
        while(Q.empty()!=true){
            int temp = Q.front();
            Q.pop();
            visited[temp]=1;
            for(int j=1; j<m+1; j++){
                if(access[temp][j]==1 && visited[j]!=1){
                    Q.push(j);
                    if(lenth[j]==-1/*&&lenth[temp]!=-1*/)
                        lenth[j]=lenth[temp]+1;
                }
            }
        }
    // }
    for(int i=1; i<m+1; i++){
        cout<<i<<" "<<lenth[i]<<endl;
    }
    return 0;
}