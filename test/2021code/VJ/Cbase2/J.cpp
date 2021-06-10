#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    while(N--){
        int a;
        cin >> a;
        int ans = 3;
        for(int i = 0; i < a; i++){
            ans = 2 * (ans - 1);
        }
        cout << ans << endl;
    }
    return 0;
}