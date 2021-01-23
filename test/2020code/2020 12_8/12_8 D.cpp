#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
class Quanternary {
protected:
    int m[100] = { 0 };
    int len = 0;
public:
    Quanternary() {}
    Quanternary(char* n)
    {
        len = strlen(n);
        for (int i = 0; i < len; i++) {
            m[len - i - 1] = n[i] - '0';
        }
    }
    void Set(char* n)
    {
        len = strlen(n);
        for (int i = 0; i < len; i++) {
            m[len - i -1] = n[i] - '0';
        }
    }
    Quanternary operator +(Quanternary& b)
    {
        int ans[100] = { 0 };
        int len1 = len;
        if (b.len > len) {
            len1 = b.len;
        }
        for (int i = 0; i < len1; i++) {
            ans[i] = m[i] + b.m[i] + ans[i];
            while (ans[i] >= 4) {
                ans[i] = ans[i] - 4;
                ans[i + 1]++;
            }
        }
        char ans1[100] = { 0 };
        if (ans[len1] == 0) {
            for (int i = 0; i < len1; i++) {
                ans1[i] = ans[len1 - 1 - i] + '0';
            }
        }
        else if (ans[len1] == 1) {
            for (int i = 0; i < len1 + 1; i++) {
                ans1[i] = ans[len1 - i] + '0';
            }
        }
        Quanternary end(ans1);
        return end;
    }
    void display()
    {
        if (m[len] == 0) {
            for (int i = 0; i < len; i++) {
                cout << m[len -1 - i];
            }
        }
        else {
            cout << m[len];
            for (int i = 0; i < len; i++) {
                cout << m[len -1 - i];
            }
        }
        cout << endl;
    }
};
int main()
{
    int t;
    cin >> t;
    Quanternary* x = new Quanternary[t];
    for (int i = 0; i < t; i++) {
        char a[100] = { 0 };
        scanf("%s", &a);
        x[i].Set(a);
    }
    Quanternary ans;
    ans = x[0] + x[1];
    for (int i = 2; i < t; i++) {
        ans = ans + x[i];
    }
    ans.display();
    return 0;
}