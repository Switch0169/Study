#include<iostream>
#include<queue>
#include<stack>
using namespace std;

char change(int t){
    if(t < 10){
        return ('0' + t);
    }
    else{
        return ('A'+ t - 10);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        double n;
        int k;
        cin>>n>>k;
        stack<char> zheng;
        queue<char> xiao;
        int z = (int) n;
        double x = n - z;
        while(z != 0){
            int temp = z % k;
            z /= k;
            zheng.push(change(temp));
        }
        int count = 0;
        while(1){
            x = x * k;
            int temp = (int) x;
            x -= temp;
            xiao.push(change(temp));
            count++;
            if(count == 3){
                break;
            }
        }
        while(!zheng.empty()){
            cout<<zheng.top();
            zheng.pop();
        }
        cout<<'.';
        while(!xiao.empty()){
            cout<<xiao.front();
            xiao.pop();
        }
        cout<<endl;
    }
    return 0;
}