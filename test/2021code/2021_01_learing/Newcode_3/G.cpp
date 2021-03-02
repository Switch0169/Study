#include<iostream>
#include<cmath>
using namespace std;
int fa[10000000];
int a[10000000];
// int find(int x){
//     if(x==fa[x]){
//         return x;
//     }
//     else{
//         fa[x]=find(fa[x]);
//         return fa[x];
//     }
// }
int find(int x){
    while(x!=fa[x]){
        x = fa[x]；
        fa[x] = fa[fa[x]];
    } 
    return x;
}
void initSet(int n){
    for(int i=1; i<n+1; i++){
        fa[i]=i;
    }
}
void Unite(int x, int y){
    x = find(x);
    y = find(y);
    if(a[x]>a[y]){
        fa[y]=x;
    }
    else{
        fa[x]=y;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    long long need = 0;
    initSet(n);
    for(int i=1; i<n+1; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        int z,x;
        cin>>z>>x;
        Unite(z,x);
    }
    for(int i=1; i<n+1; i++){
        need += a[find(i)];
    }
    cout<<need<<endl;
    return 0;
}