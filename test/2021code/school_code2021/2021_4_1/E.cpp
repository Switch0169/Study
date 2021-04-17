#include<iostream>
#include<stack>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
bool isDigital(char ch)
{
    if(ch <= '9' && ch >= '0')
        return 1;
    else
        return 0;
}
int len;
class SN{
public:
    int num;
    char ch;
    int type;
    SN(){
        num = -1;
        ch = '\0';
        type = -1;
        len = 0;
    }
    SN(int n, char c, int t){
        num = n;
        ch = c;
        type = t;
        len ++;
    }
};
int getnum(string ss, int start, int end){
    int ff = 0;
    int total = 0;
    for(int i = end; i >= start; i--){
        total += (ss[i] - '0') * pow(10,ff);
        ff++;
    }
    return total;
}
void getSN(string str, SN *origin){
    int len = str.length();
    int start = 0;
    int end = 0;
    int i = 0;
    int t = 0;
    while(i < len){
        if(isDigital(str[i])){
            while(isDigital(str[i])){
                i++;
            }
            end = i - 1;
            SN temp(getnum(str, start, end), '\0', 1);
            origin[t]=temp;
            t++;
        }
        else{
            while(!isDigital(str[i]) && i < len){
                SN temp(-1, str[i], 0);
                origin[t] = temp;
                t++;
                i++;
            }
            start = i;
        }
    }
}
int getvalue(char ch)
{
    if(ch == '+' || ch == '-'){
        return 1;
    }
    else if(ch == '*' || ch == '/'){
        return 2;
    }
    else{
        return 0;
    }
}
void Bolan(SN origin[], stack<SN>&s1, stack<SN>&s3){
    for(int i = len - 1; i >= 0; i--){
        if(origin[i].type == 1){
            s3.push(origin[i]);
        }
        while(origin[i].type == 0){
            if(origin[i].ch == ')' || s1.empty() || getvalue(s1.top().ch) <= getvalue(origin[i].ch)){
                s1.push(origin[i]);
                break;
            }
            else if(origin[i].ch == '('){
                while(s1.top().ch != ')'){
                    s3.push(s1.top());
                    s1.pop();
                }
                s1.pop();
                break;
            }
            else{ 
                s3.push(s1.top());
                s1.pop();
            }
        }
    }
    while(!s1.empty()){
        s3.push(s1.top());
        s1.pop();
    }
}
void n_Bolan(SN origin[], stack<SN>&s1, stack<SN>&s3){
    for(int i=0; i < len; i++){
        if(origin[i].type == 1){
            s3.push(origin[i]);
        }
        while(origin[i].type == 0){
            if(origin[i].ch == '(' || s1.empty() || getvalue(origin[i].ch) > getvalue(s1.top().ch)){
                s1.push(origin[i]);
                break;
            }
            else if(origin[i].ch == ')'){
                while(s1.top().ch != '('){
                    s3.push(s1.top());
                    s1.pop();
                }
                s1.pop();
                break;
            }
            else{
                s3.push(s1.top());
                s1.pop();
            }
        }
    }
    while(!s1.empty()){
        s3.push(s1.top());
        s1.pop();
    }
}
void print2(stack<SN> &s4){
    while(!s4.empty()){
        if(s4.top().type == 1){
            cout<<s4.top().num<<' ';
        }
        else{
            cout<<s4.top().ch<<' ';
        }
        s4.pop();
    }
    cout<<endl;
}
void print(stack<SN> &s1){
    stack<SN> s4;
    while(!s1.empty()){
        s4.push(s1.top());
        s1.pop();
    }
    while(!s4.empty()){
        if(s4.top().type == 1){
            cout<<s4.top().num<<' ';
        }
        else{
            cout<<s4.top().ch<<' ';
        }
        s4.pop();
    }
    cout<<endl;
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    int flag = 0;
    while(t--){
        if(flag == 1){
            cout<<endl;
        }
        flag = 1;
        SN origin[1000];
        vector<int> num;
        string str;
        stack<SN> s1;
        stack<SN> s3;
        stack<SN> ss1;
        stack<SN> ss3;  
        cin>>str;
        getSN(str, origin);
        Bolan(origin, ss1, ss3);
        print2(ss3);
        n_Bolan(origin, s1, s3);
        print(s3);
    }
    return 0;
}