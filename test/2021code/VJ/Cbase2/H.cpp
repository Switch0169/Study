#include<iostream>
using namespace std;
int getv(int A){
    int ans = 0;
    for(int i = 1; i <= A / 2; i++){
        if(A % i == 0){
            ans += i;
        }
    }
    return ans;
}
int main()
{
    int M;
    cin >> M;
    while(M--){
        int A, B;
        cin >> A >> B;
        if(getv(A) == B && getv(B) == A){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}