#include<iostream>
#include<string>
using namespace std;
string A, B;
void getReal(string &str){
    int len = str.size();
    int flag = 0;
    for(int i = 0; i < len; i++){
        if(str[i] == '.'){
            flag = 1;
            break;
        }
    }
    for(int i = 0; i < len; i++){
        if(str[i] == '.'){
            str = str.substr(i - 1);
            break;
        }
        if(str[i] >= '1' && str[i] <= '9'){
            str = str.substr(i);
            break;
        }
    }
    len = str.size();
    int count = 0;
    if(flag){
        for(int i = len - 1; i >= 0; i--){
            if(str[i] == '.'){
                str = str.substr(0, len - count  - 1);
                break;
            }
            if(str[i] >= '1' && str[i] <= '9'){
                str = str.substr(0, len - count);
                break;
            }
            count++;
        }
    }
}
int main()
{
    while(cin >> A >> B){
        getReal(A);
        getReal(B);
        if(A == B)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}