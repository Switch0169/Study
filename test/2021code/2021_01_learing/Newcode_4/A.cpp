//https://ac.nowcoder.com/acm/contest/9984
#include<iostream>
#include<string>
using namespace std;
#define ll long long
struct T
{
    double acrate = 1;
    double tcount = 0;
    double account = 0;
    int flag = 1;
};
T code[22];
void cal(int k){
    code[k].acrate = code[k].account / code[k].tcount;
    if(code[k].acrate < 0.5){
        code[k].flag = code[k].flag * 0;
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    int temp;
    string op;
    for(int i=0; i<m; i++){
        cin>>temp;
        cin>>op;
        code[temp].tcount++;
        if(op=="AC"){
            code[temp].account++;
        }
        cal(temp);
    }
    for(int i=1; i<=n; i++){
        if(code[i].flag == 1){
            cout<<i<<" ";
        }
    }
    return 0;
}