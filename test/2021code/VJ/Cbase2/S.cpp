#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int num;
    while(cin >> num){
        stack<bool> m;
        while(num > 0){
            if(num % 2 == 0){
                m.push(0);
            }
            else{
                m.push(1);
            }
            num >>= 1;
        }
        while(!m.empty()){
            cout << m.top();
            m.pop();
        }
        cout << endl;
    }
    return 0;
}