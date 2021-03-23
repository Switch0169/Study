//http://lx.lanqiao.cn/problem.page?gpid=T95
#include<iostream>
using namespace std;
int a[1001];
int f[1001];

int main()
{
    int k, N;
    cin>>k>>N;
    int c = 0;
    int nn = 1;
    while(c<N){
        int tt = c;
        f[c] = nn;
        c++;
        for(int i=0; i<tt && c<N; i++){
            f[c] = f[i] + nn;
            c++;
        }
        nn *= k;
    }
    cout<<f[N-1]<<endl;
    return 0;
}