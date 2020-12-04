#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        int M[100]={0};
        for(int i=0;i<n;i++){
            cin>>M[i];
        }
        int tcount = 0;
        for(int i=0;i<n;i++){
            int temp = M[i];
            while(temp>=100){
                temp=temp-100;
                tcount++;
            }
            while(temp>=50){
                temp=temp-50;
                tcount++;
            }
            while(temp>=10){
                temp=temp-10;
                tcount++;
            }
            while(temp>=5){
                temp=temp-5;
                tcount++;
            }
            while(temp>=2){
                temp=temp-2;
                tcount++;
            }
            while(temp>=1){
                temp=temp-1;
                tcount++;
            }
            if(temp!=0){
                cout<<"Impossible"<<endl;
            }
        }
        cout<<tcount<<endl;    
    }
    return 0;
}