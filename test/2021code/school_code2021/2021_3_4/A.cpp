#include<iostream>
#include<cstring>

using namespace std;
int main()
{
    char *yy[100] = {"January","February","March","April","May","June","July","Aguest","September","October","November","December"};
    int t;
    cin>>t;
    int temp;
    while(t--){
        cin>>temp;
        if(temp<=12&&temp>=1)
            cout<<yy[temp-1]<<endl;
        else
            cout<<"error"<<endl;
    }
    return 0;
}