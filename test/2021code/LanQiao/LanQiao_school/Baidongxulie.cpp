//http://lx.lanqiao.cn/problem.page?gpid=T44
#include<iostream>
using namespace std;
int k;
int a[100];
int number[100];
int xcount = 0;
void dfs(int x, int change){
    for(int i=1; i<=k; i++){
        if(number[i] == 0 && change == 0 && a[x-1] > i && a[x-2] > i ){
            number[i] = 1;
            a[x] = i;
            xcount++;
            if(x < k)
                dfs(x+1, 1);
            number[i] = 0;
        }
        else if(number[i] == 0 && change == 1 && a[x-1] < i && a[x-2] < i){
            number[i] = 1;
            a[x] = i;
            xcount++;
            if(x < k)
                dfs(x+1, 0);
            number[i] = 0;
        }
        
    }
}
int main()
{
    cin>>k;
    for(int i=1; i<=k; i++){
        a[0] = a[1] = i;
        number[i] = 1;
        if(k>1){
            dfs(2, 0);
            dfs(2, 1);
        }
        number[i] = 0;
    }
    cout<<xcount;
    return 0;
}