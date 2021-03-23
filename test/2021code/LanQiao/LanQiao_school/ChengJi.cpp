//http://lx.lanqiao.cn/problem.page?gpid=T77
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int num[100];
int maxn = 0;
int N,K;
int visited[100] = {0};
void getmax(int c)
{
    if(maxn < c)
        maxn = c;
}
int getnum(int start, int end)
{
    int total = 0;
    int xx = 0;
    for(int i=end; i>=start; i--){
        total += num[i] * pow(10, xx);
        xx++;
    }
    return total;
}
int dfs(int x)
{
    if(x == 0){
        int start = 1;
        int total = 1;
        for(int i=1; i<N; i++){
            if(visited[i] == 1){
                total *= getnum(start, i);
                start = i+1;
            }
        }
        total *= getnum(start, N);
        getmax(total);
        return 0;
    }
    else{
        for(int i=1; i<N; i++){
            if(visited[i] == 0){
                visited[i] = 1;
                dfs(x-1);
                visited[i] = 0;
            }
        }
    }
    return 1;
}
int main()
{
    cin>>N>>K;
    char xx[100];
    for(int i=1; i<=N; i++){
        cin>>xx[i];
        num[i] = xx[i] - '0';
    }
    dfs(K);
    cout<<maxn<<endl;
    return 0;
}