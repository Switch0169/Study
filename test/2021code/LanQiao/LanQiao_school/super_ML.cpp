//http://lx.lanqiao.cn/problem.page?gpid=T318
#include<iostream>
using namespace std;
int ans = 0;
int road[1000];

int n, m;
int dfs(int goal)
{
    if(goal == n){
        ans++;
        return 0;
    }
    else if(goal > n){
        return 0;
    }
    else{
        if(road[goal] == 1){
            return 0;
        }
        else{
            dfs(goal+1);
            dfs(goal+2);
        }
    }
    return 0;
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int temp;
        cin>>temp;
        road[temp] = 1;
    }
    dfs(1);
    cout<<ans;
    return 0;
}