#include<iostream>
using namespace std;
int visited[10000];
int Table[10000];
int Hash(int val){
    int key;
    if(val >= 0){
        key = val % 11;
    }
    else{
        while(val < 0){
            val += 11;
        }
        key = val;
    }
    return key + 1;
}
int main()
{
    int t;
    while(cin >> t){
        int m, n;
        cin >> m >> n;
        for(int i = 1; i <= m; i++){
            visited[i] = 0;
        }
        for(int i = 0; i < n; i++){
            int val;
            cin >> val;
            int key = Hash(val);
            if(visited[key] == 0){
                visited[key] = 1;
                Table[key] = val;
            }
            else{
                for(int i = key + 1; i != key; i++){
                    if(i == m + 1){
                        i = 1;
                    }
                    if(visited[i] == 0){
                        visited[i] = 1;
                        Table[i] = val;
                        break;
                    }
                }
            }
        }
        for(int i = 1; i <= m; i++){
            if(visited[i] == 1)
                cout << Table[i] << " ";
            else
                cout << "NULL" << " ";
        }
        cout << endl;
        int k;
        cin >> k;
        for(int i = 0; i < k; i++){
            int val;
            cin >> val;
            int key = Hash(val);
            int count = 0;
            bool flag = 0;
            if(Table[key] == val){
                count ++;
                flag = 1;
            }
            else if(visited[key] == 0){
                count ++;
            }
            else{
                count ++;
                for(int i = key + 1; i != key; i++){
                    if(i == m + 1){
                        i = 1;
                    }
                    count ++;
                    if(visited[i] == 0){
                        break;
                    }
                    if(Table[i] == val && visited[i] == 1){
                        flag = 1;
                        key = i;
                        break;
                    }
                }
            }
            if(flag){
                cout << flag << " " << count << " " << key << endl;
            }
            else{
                cout << flag << " " << count << endl;
            }
        }
    }
    return 0;
}