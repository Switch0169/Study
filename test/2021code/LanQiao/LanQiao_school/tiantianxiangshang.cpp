//http://lx.lanqiao.cn/problem.page?gpid=T753
//TTL
#include<cstdio>
#include<iostream>
using namespace std;
#define ll long long

ll w[3000];
ll visited[3000] = {0};
ll temp_w[6] = {0};
ll temp_d[6] = {0};
int n;
int minx = -1;

int xcount = 0;
void dfs(int x){
    for(int i=1; i<=n; i++){
        if(visited[i] == 0 && w[i] > temp_w[x-1] && i > temp_d[x-1]){
            visited[i] = 1;
            temp_w[x] = w[i];
            temp_d[x] = i;
            if(x == 4){
                xcount++;
            }
            else
                dfs(x+1);
            visited[i] = 0;
        }
    }
}
int main()
{
    cin>>n;
    temp_w[0] = minx;
    temp_d[0] = minx;
    for(int i=1; i<=n; i++){
        cin>>w[i];
    }
    dfs(1);
    cout<<xcount<<endl;
    return 0;
}