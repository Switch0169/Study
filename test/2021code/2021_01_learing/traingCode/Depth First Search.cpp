#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
int access[100][100];
int visited[100];
int discovertime[100];
int finishtime[100];
int timeofnow = 0;
stack<int> S;
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
    }
    for(int i=1; i<m+1; i++){
        if(visited[i]!=1){
            S.push(i);
            timeofnow++;
            discovertime[i] = timeofnow;
        }
        while(S.empty()!=true){
            int temp = S.top();
            S.pop();
            if(visited[temp]!=1){
                visited[temp]=1;
                for(int j=1; j<m+1; j++){
                    if(access[temp][j]==1){
                        S.push(j);
                        timeofnow++;
                        discovertime[j] = timeofnow;
                    }
                }
            }
        }
    }
    for(int i=1; i<m+1; i++){
        cout<<i<<" "<<discovertime[i]<<" "<<finishtime[i]<<endl;
    }
    return 0;
}