#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    int n;
    cin>>n;
    while(n--){
        cin>>str;
        int len = str.length();
        int count = 0;
        for(int i=0; i<len; i++){
            if(str[i] <= '9' && str[i] >= '0'){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}