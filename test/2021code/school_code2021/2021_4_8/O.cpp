#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b){
    if(a < 0){
        a = -a;
    }
    if(b < 0){
        b = -b;
    }
    return a > b;
}
int main()
{
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        int a[100];
        for(int i = 0; i < n; i ++){
            cin >> a[i];
        }
        sort(a, a+n, cmp);
        cout << a[0];
        for(int i = 1; i < n; i ++){
            cout << " "<< a[i];
        }
        cout << endl;
    }
    return 0;
}