//http://lx.lanqiao.cn/problem.page?gpid=T547
#include<iostream>
using namespace std;
int table[52];
int perfect[52];
int now[52];
void init()
{
    for(int i=0; i<52; i++){
        table[i] = i;
        perfect[i] = i;
        //cin>>now[i];
    }
}
void perfectswap()
{
    int pre = 0;
    int last = 26;
    int temp[52];
    for(int i=0; i<52; i++){
        temp[i] = perfect[i];
    }
    for(int i=0; i<52; i+=2){
        perfect[i] = temp[last];
        perfect[i+1] = temp[pre];
        last++;
        pre++;
    }
}
bool check()
{
    int T = 0;
    int F = 0;
    for(int i=0; i<52; i++){
        if(now[i]==table[i]){
            T++;
        }
        else{
            F++;
        }
    }
    return T>F;
}
int main()
{
    int n;
    // cin>>n;
    // for(int c=1; c<=n; c++){
    //     init();
    //     while(check()!=true){
    //         perfectswap();
    //     }
        
    // }
    init();
    n=9;
    while(n--){
        perfectswap();
        for(int i=0; i<52; i++){
            cout<<perfect[i]<<" ";
        }
        cout<<endl<<endl;
    }
    return 0;
}