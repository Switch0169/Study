//https://ac.nowcoder.com/acm/contest/9983
#include<iostream>
using namespace std;
int get(int n)
{
    int temp = n;
    int count = 0;
    while(temp>0){
        int tt = temp % 10;
        count = count + tt;
        temp = temp / 10;
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    int nn = get(n);
    for(int i=n+1; 1; i++){
        if(nn == get(i)){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}