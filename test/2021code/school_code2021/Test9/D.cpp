#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int len;
void search(int i, char *str){
    if(str[i] == '0' || i > len){
        return ;
    }
    cout << str[i];
    search(2 * i, str);
    search(2 * i + 1, str);
}
int main()
{
    int n;
    cin >> n;
    while(n--){
        char str[1000];
        cin >> str + 1;
        len = strlen(str + 1);
        search(1, str);
        cout << endl;
    }
    return 0;
}