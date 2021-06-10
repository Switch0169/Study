#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main()
{
    string str;
    while(cin>>str){
        deque<char> Q;
        deque<char> pre;
        int len = str.length();
        for(int i = 0; i < len; i ++){
            if(str[i] == '['){
                i++;
                while(1){
                    if(str[i] == ']' || str[i] == '[' || i >= len){
                        while(!pre.empty()){
                            Q.push_front(pre.back());
                            pre.pop_back();
                        }
                        if(i < len)
                            i--;
                        break;
                    }
                    else{
                        pre.push_back(str[i]);
                    }
                    i++;
                }
            }
            else if(str[i] == ']'){
                i++;
                while(1){
                    if(str[i] == ']' || str[i] == '[' || i >= len){
                        if(i < len)
                            i--;
                        break;
                    }
                    else{
                        Q.push_back(str[i]);
                    }
                    i++;
                }
            }
            else{
                Q.push_back(str[i]);
            }
        }
        while(!Q.empty()){
            cout<<Q.front();
            Q.pop_front();
        }
        cout<<endl;
    }
    return 0;
}