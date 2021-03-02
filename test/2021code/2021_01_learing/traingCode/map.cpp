#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<string, int> mymap;

void action(string ss){
    string str;
    cin>>str;
    int value = 1;
    if(ss=="insert"){
        mymap[str]++;
    }
    if(ss=="find"){
        map<string, int>::iterator it = mymap.find(str);
        if(it != mymap.end()){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    string ss,str;
    while(n--){
        cin>>ss;
        action(ss);
    }
    return 0;
}
