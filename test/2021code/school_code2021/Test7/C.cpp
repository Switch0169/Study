#include<iostream>
#include<string>
using namespace std;
bool equals(int count, string str){
    char front[100] = {0};
    int len = str.size();
    char back[100] = {0};
    for(int i = 0; i < count; i++){
        front[i] = str[i];
    }
    for(int i = 0; i < count; i++){
        back[i] = str[len - count + i];
    }
    int flag = 1;
    for(int i = 0; i < count; i++){
        if(front[i] != back[i]){
            flag = 0;
            break;
        }
    }
    return flag;
}
void print(int count, string str){
    for(int i = 0; i < count; i++){
        cout << str[i];
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    while(n --){
        string str;
        cin >> str;
        int len = str.size();
        int isflag = 0;
        int m = 0;
        for(int i = 1; i < len; i ++){
            int count = i;
            if(equals(count, str)){
                isflag = 1;
                m = count;
                continue;
            }
        }
        if(isflag == 1){
            print(m, str);
        }
        if(isflag == 0){
            cout << "empty" << endl;
        }
    }
    return 0;
}