#include<iostream>
#include<queue>
using namespace std;
int Search(int *q, int n){
    for(int i = n; i >= 0; i--){
        if(q[0] == q[i]){
            return i;
        }
    }
}
int main()
{
    int n;
    while(cin >> n){
        int q[10000];
        for(int i = 1; i <= n; i++){
            cin >> q[i];
        }
        int t;
        cin >> t;
        for(int i = 0; i < t; i++){
            cin >> q[0];
            int ans = Search(q, n);
            if(ans == 0){
                cout << "error" << endl;
            }
            else{
                cout << ans << endl;
            }
        }
    }
    return 0;
}