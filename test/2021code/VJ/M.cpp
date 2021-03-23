#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        if(n == 0)
            break;
        int number = 1;
        int smallnumber = 0;
        int k = 0;
        int kk = 0;
        int nn[10];
        for(int i=1; i<n; i++){
            if(i>=4){
                smallnumber -= nn[kk];
                number += nn[kk];
                k=0;
                kk++;
                if(kk>=4){
                    kk = 0;
                }
            }
            smallnumber += number;
            nn[k] = number;
            k++;
        }
        cout<<number+smallnumber<<endl;
    }
    return 0;
}