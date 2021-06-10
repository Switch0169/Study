#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    int len = str.length();
    int sixflag = 0;
    for(int i = 0; i < len; i++){
        while(str[i] == '6'){
            sixflag++;
            i++;
        }
        if(sixflag <= 3){
            for(int i = 0; i < sixflag; i++ )
                cout << "6";
        }
        else if(sixflag > 3 && sixflag <= 6){
            cout << "9";
        }
        else if(sixflag > 6){
            cout << "27";
        }
        else if(sixflag == 0){
            cout << str[i];
        }
        if(str[i] != '6'){
            sixflag = 0;
            cout << str[i];
        }
    }
    cout << endl;
    return 0;
}