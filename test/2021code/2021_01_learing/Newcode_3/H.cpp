#include<iostream>
#include<string>
using namespace std;
char T[3000000];
void check(){
    int flag = -1;
    for(int i=0; T[i]!='\0'; i++){
        int temp = T[i] - 'a' + 1;
        if(temp >= 11 && temp <= 26 && temp != 20){
            flag = 1;
            if(temp / 10 == 1){
                char tempx;
                tempx = 'a' + temp % 10; 
                cout<<'a';
                cout<<tempx;
            }
            
        }
    }

}
int main()
{
    cin>>T;
    return 0;
}