//http://lx.lanqiao.cn/problem.page?gpid=T580
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int tx[1000];
int main()
{
    int n,sum;
    cin>>n>>sum;
    int maxn = pow(10,n);
    vector<int> x;
    for(int i=3124; i<maxn; i++){
        int temp = i;
        int xx[1000];
        for(int j=0; j<n; j++){
            xx[j] = temp % 10;
            temp = temp / 10;
        }
        for(int j=n-1; j>=0; j--){
            x.push_back(xx[j]);
        }
        while(x.size()!=1){
            int t = 0;
            for(int k=0; k<x.size()-1; k++){
                tx[t] = x[k] + x[k+1];
                t++;
            }
            x.clear();
            for(int k=0; k<t; k++){
                x.push_back(tx[k]);
            }
        }
        if(x[0]==sum){
            cout<<xx[n-1];
            for(int j=n-2; j>=0; j--){
                cout<<" "<<xx[j];
            }
            cout<<endl;
            break;
        }
        x.clear();
    }
    return 0;
}