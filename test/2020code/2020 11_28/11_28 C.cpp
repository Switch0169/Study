#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char m[100]={0};
    while(cin>>m){
        int flag =1;
        int len = 0;
        len=strlen(m);
        if(len<8){
            flag=flag*0;
        }
        int count=0;
        int temp1=1;
        int temp2=1;
        int temp3=1;
        int temp4=1;
        for(int i=0;i<len;i++){
            if(m[i]>='A'&&m[i]<='Z'){
                temp1=temp1*0;
            }
            if(m[i]>='a'&&m[i]<='z'){
                temp2=temp2*0;
            }
            if(m[i]>='0'&&m[i]<='9'){
                temp3=temp3*0;
            }
            if(m[i]=='~'||m[i]=='!'||m[i]=='@'||m[i]=='#'||m[i]=='$'||m[i]=='%'||m[i]=='^'){
                temp4=temp4*0;
            }
        }
        if(temp1==0){
            count++;
        }
        if(temp2==0){
            count++;
        }
        if(temp3==0){
            count++;
        }
        if(temp4==0){
            count++;
        }
        if(count<3){
            flag=flag*0;
        }
        if(flag==1){
            cout<<"YES"<<endl;
        }
        if(flag==0){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}