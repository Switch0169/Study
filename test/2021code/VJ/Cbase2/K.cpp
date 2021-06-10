#include<iostream>
#include<string>
using namespace std;
int main()
{
    int M;
    cin >> M;
    while(M--){
        string str;
        cin >> str;
        int len = str.size();
        int safe = 1;
        int jug = 0;
        if(len < 8 || len > 16){
            safe = 0;
        }
        else{
            for(int i = 0; i < len; i++){
                if(str[i] >= 'A' && str[i] <= 'Z'){
                    jug++;
                    break;
                }
            }
            for(int i = 0; i < len; i++){
                if(str[i] >= 'a' && str[i] <= 'z'){
                    jug++;
                    break;
                }
            }
            for(int i = 0; i < len; i++){
                if(str[i] >= '0' && str[i] <= '9'){
                    jug++;
                    break;
                }
            }
            for(int i = 0; i < len; i++){
                if(str[i] == '~' || str[i] == '!' || str[i] == '@' || str[i] == '#' || str[i] == '$' || str[i] == '%' || str[i] == '^'){
                    jug++;
                    break;
                }
            }
            if(jug < 3){
                safe = 0;
            }
        }
        if(safe){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}