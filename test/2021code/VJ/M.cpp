#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        if(n == 0){
            break;
        }
        int cow[55]={1, 1, 2};
        for(int i = 3; i <= n; i ++){
            cow[i] = cow[i - 1] + cow[i - 3];
        }
        cout << cow[n] << endl;
    }
    return 0;
}