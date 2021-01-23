#include<iostream>
using namespace std;
int isNumber(char *a){
    int amount=0;
    int turn=0;
    int total=0;
    int b=0;
    int j=0;
    for(int i=0;;i++){
        if(*(a+i)==0)
            break;
        if(*(a+i)>='0'&&*(a+i)<='9'){
            amount++;
        }
        else{
            amount=0;
            break;
        }
    }
    if(amount==0){
        return -1;
    }
    else{
        turn=amount;
        for(int i=0;i<turn;i++){
                b=(*(a+i)-'0');
                for(j=amount-1;j>0;j--){
                    b=b*10;
                }
                total=total+b;
                amount--;
        }
        return total;
    }
}
int main()
{
    int t;
    char *a= new char ;
    cin>>t;
    while(t--){
        int amount =0;
        cin>>a;
        amount =isNumber(a);
        if(amount==0){
            cout<<amount<<endl;
        }
        else{
            cout<<amount<<endl;
        }
    }
    return 0;
}