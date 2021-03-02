#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int turn(string s) {
    int len = s.length();
    long long int m = 0;
    for (int i = 0; i < len; i++) {
        m += (s[i] - '0') * pow(10, len - i -1);
    }
    return m;
}
int main()
{
    stack<int> S;
    string m;
    while (cin >> m) {
        if (m == "+" || m == "-" || m == "*") {
            int a, b;
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            int k;
            if (m == "+") {
                k = a + b;
            }
            else if (m == "-") {
                k = b - a;
            }
            else if (m == "*") {
                k = a * b;
            }
            S.push(k);
        }
        else
            S.push(turn(m));
    }
    int ans = S.top();
    printf("%d\n", ans);
    return 0;
}
