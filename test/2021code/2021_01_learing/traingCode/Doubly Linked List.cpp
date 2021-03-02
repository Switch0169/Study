#include<iostream>
#include<list>
#include<cstring>
#include<string>
using namespace std;
list<int> s;
void action(string ss){
    int x;
    if(ss=="insert"){
        cin>>x;
        s.push_front(x);
    }
    if(ss=="delete"){
        cin>>x;
        for(list<int>::iterator it = s.begin(); it != s.end(); it++){
            if(*it == x){
                s.erase(it);
                break;
            }
        }
    }
    if(ss=="deleteFirst"){
        s.pop_front();
    }
    if(ss=="deleteLast"){
        s.pop_back();
    }
}
int main()
{
    string ss;
    int n;
    cin>>n;
    while(n--){
        cin>>ss;
        action(ss);
    }
    cout<<s.front();
    s.pop_front();
    while(s.empty()!=true){
        cout<<" ";
        cout<<s.front();
        s.pop_front();
    }
    cout<<endl;
    return 0;
}