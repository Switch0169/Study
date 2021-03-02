#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1001;
int fa[maxn];
int r[maxn];
int find(int x){
    if(x==fa[x]){
        return x;
    }
    else{
        fa[x]=find(fa[x]);
        return fa[x];
    }
}
void initSet(int n){
    for(int i=1; i<n+1; i++){
        fa[i]=i;
        r[i]=0;
    }
}
void Unite(int x, int y){
    x = find(x);
    y = find(y);
    if(r[x]>r[y]){
        fa[y]=x;
    }
    else{
        fa[x]=y;
        if(r[x]==r[y]){
            r[y]++;
        }
    }
}
bool same(int x, int y){
    if(x==y)
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    int m;
    while(scanf("%d",&n)!=EOF&&n!=0){
        initSet(n);
        scanf("%d",&m);
        for(int i=0; i<m; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            Unite(x,y);
        }
        int finalsame = 1;
        for(int i=1; i<n+1; i++){
            for(int j=i+1; j<n+1; j++){
                if(same(find(i),find(j))==1){

                }
                else
                    finalsame = finalsame *0;
            }
        }
        if(finalsame==1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}