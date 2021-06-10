#include<iostream>
using namespace std;
int main()
{
    int n, m;
    while(cin >> n >> m){
        cout << "+";
        for(int i = 0; i < n; i++){
            cout << '-';
        }
        cout << "+" << endl;
        for(int j = 0; j < m; j++){
            cout << "|";
            for(int i = 0; i < n; i++){
                cout << ' ';
            }
            cout << "|" << endl;
        }
        cout << "+";
        for(int i = 0; i < n; i++){
            cout << '-';
        }
        cout << "+" << endl << endl;
    }
    return 0;
}