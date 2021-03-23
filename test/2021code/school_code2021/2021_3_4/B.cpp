#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int xx[100];
        for(int i=1; i<=n; i++){
            cin>>xx[i];
        }
        int *p = &xx[n/2 + 1];
        p--;
        cout<<*p<<" ";
        p++;
        p++;
        cout<<*p<<endl;
        p--;
        int temp;
        cin>>temp;
        p = p - (n/2 + 1 - temp);
        cout<<*p<<endl;
    }

    return 0;
}