#include<iostream>
using namespace std;
int main()
{
    int i, j;
    while(cin >> i >> j){
        while(i != j){
            if(i > j){
                i /= 2;
            }
            else{
                j /= 2;
            }
        }
        cout << i << endl;
    }
    return 0;
}