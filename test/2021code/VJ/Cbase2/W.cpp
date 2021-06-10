#include<iostream>
using namespace std;
int f(char ch)
{
    if(ch >= 'a' && ch <= 'z'){
        return -(ch - 'a' + 1);
    }
    else{
        return ch - 'A' + 1;
    }
}
int main()
{
    int T;
    cin >> T;
    while(T--){
        char ch;
        int num;
        cin >> ch >> num;
        cout << num + f(ch) << endl;
    }
    return 0;
}