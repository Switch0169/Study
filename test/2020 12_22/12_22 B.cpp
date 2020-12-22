#include<iostream>
#include<cstring>
using namespace std;
template<class T>
int px(T* a, int n, T key)
{
    T temp;
    int flag = 0;
    for (int i = 0; i < n ; i++) {
        if(a[i]==key){
            flag = i+1;
        }
    }
    return flag;
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
            int key;
            cin>>key;
            cout<<px(a, n, key)<<endl;
        }
        if (x == 'C') {
            char* a = new char[n];
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            char key;
            cin>>key;
            cout<<px(a, n, key)<<endl;
        }
        if (x == 'D') {
            double* a = new double[n];
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            double key;
            cin>>key;
            cout<<px(a, n, key)<<endl;
        }
        if (x == 'S') {
            string* a = new string[n];
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            string key;
            cin>>key;
            cout<<px(a, n, key)<<endl;
        }
    }
    return 0;
}