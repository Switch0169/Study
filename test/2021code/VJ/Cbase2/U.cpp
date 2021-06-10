#include<iostream>
using namespace std;
bool state = 0;
int main()
{
    int n;
    while(cin >> n){
        state = 0;
        for(int i = 1; i <= n; i++){
            if(n % i == 0){
                if(state == 1)
                    state = 0;
                else
                    state = 1;
            }
        }
        cout << state << endl;
    }
    return 0;
}