#include<iostream>
#include<algorithm>
using namespace std;
int fa[1001];
int n;
int maxn = 0;
void init()
{
    for(int i=1; i<n; i++){
        fa[i]=0;
    }
    for(int i=1; i<=n; i++){
        cin>>fa[i];
    }
}
int find(int x)
{
    int temp = 1;
    while(fa[x]!=0){
        x=fa[x];
        temp++;
    }
    return temp;
}
int main()
{
    cin>>n;
    init();
    for(int i=1; i<=n; i++){
        int xxx = find(i);
        if(maxn<xxx){
            maxn = xxx;
        }
    }
    cout<<maxn;
    return 0;
}