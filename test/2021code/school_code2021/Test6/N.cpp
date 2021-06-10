#include<iostream>
using namespace std;
int main()
{
    int n, m;
    while(cin >> n){
        cin >> m;
        if(n == 0 && m == 0){
            break;
        }
        int a[100] = {0};
        int p = n;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i ++){
            if(a[i] >= m){
                p = i;
                break;
            }
        }
        for(int i = n; i > p; i--){
            a[i] = a[i-1];
        }
        a[p] = m;
        cout << a[0];
        for(int i = 1; i <= n; i++){
            cout << " " << a[i];
        }
        cout<<endl;
    }
    return 0;
}