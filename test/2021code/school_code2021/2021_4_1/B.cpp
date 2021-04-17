#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int len = str.length();
        stack<char> s;
        for(int i=0; i<len; i++){
            s.push(str[i]);
            if(s.top() == '#'){
                if(!s.empty())
                    s.pop();
                if(!s.empty())
                    s.pop();
            }
        }
        stack<char> ss;
        if(s.empty()){
            cout<<"NULL";
        }
        else{
            while(!s.empty()){
                ss.push(s.top());
                s.pop();
            }
            while(!ss.empty()){
                cout<<ss.top();
                ss.pop();
            }
        }
        cout<<endl;
    }
    return 0;
}