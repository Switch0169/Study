#include<iostream>
using namespace std;
int main()
{
    int t;
    while(cin>>t){
        if(t==0){
            break;
        }
        int s[100];
        int min = 100000;
        int minf = 0;
        for(int i=0; i<t; i++){
            cin>>s[i];
        }
        for(int i=0; i<t; i++){
            if(min > s[i]){
                min = s[i];
                minf = i;
            }
        }
        s[minf] = s[0];
        s[0] = min;
        cout<<s[0];
        for(int i=1; i<t; i++){
            cout<<" "<<s[i];
        }
        cout<<endl;
    }
    return 0;
}