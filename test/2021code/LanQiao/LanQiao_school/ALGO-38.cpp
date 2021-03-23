#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int w[10000];
int now[10000];
int m,n;
queue<int> Q;
bool check(){
    int flag = 1;
    if(Q.empty()){
        for(int i=1; i<=m; i++){
            if(now[i]!=0){
                flag = 0;
                break;
            }
        }
    }
    return flag;
}
int main()
{
    int time = 0;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>w[i];
        Q.push(i);
    }
    for(int i=1; i<=m; i++){
        if(!Q.empty()){
            now[i]=w[Q.front()];
            Q.pop();
        }
    }
    while(1){
        int minx = 100000;
        for(int i=1; i<=m ;i++){
            if(now[i] < minx && now[i] > 0){
                minx = now[i];
            }
        }
        for(int i=1; i<=m; i++){
            now[i] = now[i] - minx;
        }
        for(int i=1; i<=m; i++){
            if(now[i]==0){
                if(!Q.empty()){
                    now[i]=w[Q.front()];
                    Q.pop();
                }
            }
            if(now[i]<=0)
                now[i]=0;
        }
        time += minx;
        if(Q.empty()){
            if(check()){
                break;
            }
        }
    }
    cout<<time<<endl;
    return 0;
}