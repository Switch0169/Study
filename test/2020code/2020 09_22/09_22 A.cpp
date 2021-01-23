#include<iostream>
using namespace std;
int main()
{
    const char *month[]={"January","February","March","April","May","June","July","Augest","September","October","November","December"};
    const char**pmonth;
    pmonth=month;
    int t,a;
    cin>>t;
    while(t--){
        cin>>a;
        if(a>12){
            cout<<"error"<<endl;
            continue;
        }
        cout<<*(pmonth+a-1)<<endl;
    }
    return 0;
}