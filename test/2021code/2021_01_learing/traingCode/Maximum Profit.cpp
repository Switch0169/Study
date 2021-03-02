#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int min = 0;
    int temp;
    cin>>temp;
    min = temp;
    int tempans;
    int ans;
    cin>>temp;
    ans = temp - min;
    if(min > temp){
        min = temp;
    }
    for(int i =2; i<n; i++){
        cin>>temp;
        tempans = temp - min;
        if(ans < tempans){
            ans = tempans;
        }
        if(min > temp){
            min = temp;
        }
    }
    cout<<ans<<endl;
    return 0;
}