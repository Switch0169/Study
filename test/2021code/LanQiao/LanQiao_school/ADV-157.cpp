#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    int xmax = 0;
    string str;
    string str1, str2;
    cin>>str;
    int len = str.length();
    for(int i=1; i<=len; i++){
        int flag = 1;
        for(int j=0; j<=len; j++){
            int tempmax = 1;
            str1 = str.substr(j,i);
            for(int k=j+i; k<len; k+=i){
                str2 = str.substr(k,i);
                if(str1 == str2){
                    tempmax++;
                }
                else{
                    flag = 0;
                    break;
                }
            }
            if(tempmax>xmax&&flag == 1){
                xmax = tempmax;
            }
        }
    }
    cout<<xmax<<endl;
    return 0;
}