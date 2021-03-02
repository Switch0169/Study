#include<iostream>
#include<cstdio>
using namespace std;
int x[100000];
int find(int s){
    int xt = s;
    if(s == x[s]){
        return s;
    }
    else{
        x[s] = find(x[s]);
        return x[s];
    }
}
int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        x[i]=i;
    }
    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        x[find(b)] = find(a);
    }
    
    int x;
    scanf("%d",&x);
    while(x--){
        int a,b;
        scanf("%d %d", &a, &b);
        if(find(a)==find(b))
            printf("yes\n");
        else{
            printf("no\n");
        }
    }
    return 0;
}