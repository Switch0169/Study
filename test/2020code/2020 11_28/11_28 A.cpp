#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[100]={0};
    int len=0;
    int count = 1;
    while(cin>>a){
        char b[100]={0};
        len=strlen(a);
        for(int i=0;i<len;i++){
            b[i]=a[len-1-i];
        }
        if(strcmp(a,b)==0){
            cout<<"case"<<count<<":"<<" yes"<<endl;
        }
        else{
            cout<<"case"<<count<<":"<<" no"<<endl;
        }
        count++;
    }
    return 0;
}