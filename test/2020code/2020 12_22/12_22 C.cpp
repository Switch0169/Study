#include<iostream>
#include<cstring>
using namespace std;
template<class T>
void max(T* a, int n)
{
    int x[100] = { 0 };
    int flag = 0;
    int h = 0;
    for (int i = 0; i < n; i++) {
        int flag1 = 1;
        for (int k = 0; k < i; k++) {
            if (a[i] == a[k])
                flag1 = flag1 * 0;
        }
        if (flag1 == 1) {
            for (int j = i; j < n; j++) {
                if (a[i] == a[j]) {
                    x[i]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (x[i] > h) {
            h = x[i];
            flag = i;
        }
    }
    cout << a[flag] << " " << h << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        char x = 0;
        int n = 0;
        cin >> x;
        cin >> n;
        if (x == 'I') {
            int* a = new int[n];
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            max(a, n);
        }
        if (x == 'C') {
            char* a = new char[n];
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            max(a, n);
        }
        if (x == 'S') {
            string* a = new string[n];
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            max(a, n);
        }
    }
    return 0;
}