#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int m[1001][1001] = { {0} };

int main()
{
    int q;
    cin >> q;
    while (q--) {
        char X[1001] = { 0 };
        char Y[1001] = { 0 };
        char rX[1001] = { 0 };
        char rY[1001] = { 0 };
        cin>>rX;
        cin>>rY;
        int Xlen = strlen(rX);
        int Ylen = strlen(rY);
        for(int i=1; i<=Xlen; i++){
            X[i]=rX[i-1];
            m[i-1][0]=0;
        }
        for(int i=1; i<=Ylen; i++){
            Y[i]=rY[i-1];
            m[0][i-1]=0;
        }
        for (int i = 1; i <= Xlen; i++) {
            for (int j = 1; j <= Ylen; j++) {
                if (X[i] != Y[j]) {
                    m[i][j] = max(m[i - 1][j], m[i][j - 1]);
                }
                else if (X[i] == Y[j]) {
                    m[i][j] = m[i - 1][j - 1] + 1;
                }
            }
        }
        cout << m[Xlen][Ylen] << endl;
    }
    return 0;
}