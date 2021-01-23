#include<iostream>
#include<cstring>
using namespace std;
template<class T>
void px(T* a, int n)
{
    T temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
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
            px(a, n);
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        if (x == 'C') {
            char* a = new char[n];
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            px(a, n);
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        if (x == 'D') {
            double* a = new double[n];
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            px(a, n);
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        if (x == 'S') {
            string* a = new string[n];
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            px(a, n);
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}