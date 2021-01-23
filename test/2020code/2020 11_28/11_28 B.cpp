#include<iostream>
using namespace std;
int main()
{
    int m,n;
    while(cin>>m){
        cin>>n;
        int flag=1;
        for(int i =m;i<=n;i++){
            int b=0;
            int s=0;
            int g=0;
            g=i%10;
            b=i/100;
            s=(i-b*100)/10;
            if(i==(g*g*g+s*s*s+b*b*b)){
                if(flag!=1){
                    cout<<" ";
                }
                cout<<i;
                flag=flag*0;
            }
        }
        if(flag==1){
            cout<<"no";
        }
        cout<<endl;
    }
    return 0;
}