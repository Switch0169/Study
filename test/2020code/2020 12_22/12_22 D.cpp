#include<iostream>
#include<cstring>
using namespace std;
template<class T>
void print(T* a, T *b, int n)
{
    for(int i=0;i<n;i++){
        cout<<b[i];
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<endl;
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
            int* b = new int[n];
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            for (int i = 0; i < n; i++) {
                cin >> b[i];
            }
            print(a,b,n);
        }
        if (x == 'C') {
            char* a = new char[n];
            char* b = new char[n];
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            for (int i = 0; i < n; i++) {
                cin >> b[i];
            }
            print(a,b,n);
        }
        if (x == 'D') {
            double* a = new double[n];
            double* b = new double[n];
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            for (int i = 0; i < n; i++) {
                cin >> b[i];
            }
            print(a,b,n);
        }
    }
    return 0;
}