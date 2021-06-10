#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0){
            break;
        }
        map<int, int> a;
        for(int i = 0; i < n; i++){
            int value;
            cin >> value;
            a[value] = 1;
        }
        for(int i = 0; i < m; i++){
            int value;
            cin >> value;
            if(a[value] == 1){
                a[value] = 0;
            }
        }
        int flag = 1;
        for(auto i = a.begin(); i != a.end(); i++){
            if(i->second == 1){
                cout << i->first << " ";
                flag = 0;
            }
        }
        if(flag){
            cout << "NULL";
        }
        cout << endl;
    }
    return 0;
}