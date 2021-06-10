#include<iostream>
#include<string>
using namespace std;
int num[1001];
int len;
int ans(int i){
    if(i > len || num[i] == 0){
        return 0;
    }
    cout << num[i] << " "; 
    ans(2*i);
    ans(2*i + 1);
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> num[i];
        }
        len = n;
        ans(1);
        cout << endl;
    }
    return 0;
}