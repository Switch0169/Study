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
        cin>>str;
        int len = str.length();
        stack <char> s;
        for(int i=0; i<len; i++){
            s.push(str[i]);
        }
        while(!s.empty()){
            char tmp = s.top();
            cout<<tmp;
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}