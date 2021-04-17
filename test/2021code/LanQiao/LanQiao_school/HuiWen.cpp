#include<iostream>
using namespace std;
char str[8];
void getHui(){
    str[3] += 1;
    for(int i  = 0; i < 4; i++){
        str[7-i] = str[i];
    }
    for(int i = 0; i < 8; i++){
        cout<<str[i];
    }
    cout<<endl;
}
void turnstr(int num){
    for(int i = 7; i >= 0; i--){
        int temp = num % 10;
        num /= 10;
        str[i] = temp + '0';
    }
}
void gets(){
    str[7] = str[5] = str[2] = str[0];
    str[6] = str[4] = str[3] = str[1];
    for(int i = 0; i < 8; i++){
        cout<<str[i];
    }
    cout<<endl;
}
int main()
{
    int num;
    cin>>num;
    turnstr(num);
    getHui();
    gets();
    return 0;
}