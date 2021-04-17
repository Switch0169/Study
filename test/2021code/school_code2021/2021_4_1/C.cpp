#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        string str;
        stack<char> s;
        cin>>str;
        int len = str.length();
        for(int i=0; i<len; i++){
            char tmp = str[i];
            if(tmp == '(' || tmp == '{' || tmp == '['){
                s.push(tmp);
            }
            else if(tmp == ')' || tmp == '}' || tmp == ']'){
                if(!s.empty()){
                    if(tmp == ')'){
                        if(s.top() == '(')
                            s.pop();
                    }
                    else if(tmp == ']'){
                        if(s.top() == '[')
                            s.pop();
                    }
                    else if(tmp == '}'){
                        if(s.top() == '{')
                            s.pop();
                    }
                    else{
                        break;
                    }
                }
                else{
                    s.push(tmp);
                }
            }
        }
        if(s.empty()){
            cout<<"ok";
        }
        else{
            cout<<"error";
        }
        cout<<endl;
    }
    return 0;
}