#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int N;
    int M;
    int K;
    cin >> N >> M >> K;
    while(K--){
        stack<int> bottle;
        stack<int> table;
        for(int i = N; i >= 1; i--){
            bottle.push(i);
        }
        int t[1001];
        for(int i = 0; i < N; i++){
            cin >> t[i];
        }
        int able = 1;
        for(int i = 0; i < N; i++){
            int action = 0;
            if((int)table.size() > M){
                able = 0;
                break;
            }
            if(!bottle.empty()){
                if(t[i] == bottle.top()){
                    bottle.pop();
                    action = 1;
                }
                else{
                    table.push(t[i]);
                    action = 1;
                }
                if(!table.empty()){
                    if(table.top() == bottle.top()){
                        table.pop();
                        bottle.pop();
                        action = 1;
                    }
                }
            }
            else{
                able = 1;
                break;
            }
            if(action == 0){
                able = 0;
                break;
            }
        }
        while(!bottle.empty() && !table.empty() && able == 1){
            int action = 0;
            if((int)table.size() > M){
                able = 0;
                break;
            }
            if(!bottle.empty()){
                if(!table.empty()){
                    if(table.top() == bottle.top()){
                        table.pop();
                        bottle.pop();
                        action = 1;
                    }
                }
            }
            else{
                able = 1;
                break;
            }
            if(action == 0){
                able = 0;
                break;
            }
        }
        if(!bottle.empty()){
            able = 0;
        }
        if(able == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}