#include<iostream>
using namespace std;
int q[100000];
int Search(int *q, int n){
    if(n == 0)
        return 0;
    int left = 1;
    int right = n;
    while(left <= right){
        int mid = (left + right) / 2;
        if(q[mid] == q[0]){
            return mid;
        }
        else if(q[mid] > q[0]){
            right = mid - 1;
        }
        else if(q[mid] < q[0]){
            left = mid + 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    while(cin >> n){
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