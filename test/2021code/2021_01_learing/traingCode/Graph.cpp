#include<iostream>
#include<cstdio>
using namespace std;
int access[100][100];
int main()
{
    int m;
    scanf("%d",&m);
    int mm = m;
    while(m--){
        int n;
        scanf("%d",&n);
        int q;
        scanf("%d",&q);
        while(q--){
            int k;
            scanf("%d",&k);
            access[n][k]=1;
        }
    }
    for(int i=1; i<mm+1; i++){
        cout<<access[i][1];
        for(int j=2; j<mm+1; j++){
            cout<<" "<<access[i][j];
        }
        cout<<endl;
    }
    return 0;
}