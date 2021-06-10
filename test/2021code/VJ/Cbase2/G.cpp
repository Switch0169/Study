#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int M;
    cin >> M;
    for(int i = 0; i < M; i++){
        double A, B, C;
        cin >> A >> B >> C;
        if(A + B > C && A + C > B && B + C > A && pow((A - B), 2) < pow(C, 2) && pow((A - C), 2) < pow(B, 2) && pow((B - C), 2) < pow(A, 2)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}