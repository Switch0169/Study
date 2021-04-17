#include<iostream>
using namespace std;
int m,n;
int ans;
int t;
int have = 0;
int need = 0;

int dfs(int goal)
{
    if(need > have){
        return 0;
    }
    if(goal == t+1){
        ans ++;
        return 0;
    }
    else{
        if(m > 0){
            have ++;
            m --;
            dfs(goal + 1);
            have --;
            m++;
        }
        if(n > 0){
            need ++;
            n --;
            dfs(goal + 1);
            need --;
            n ++;
        }
    }
    return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    cin>>m>>n;
    t = m+n;
    dfs(1);
    cout<<ans;
    return 0;
}
