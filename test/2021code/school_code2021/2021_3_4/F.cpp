#include<iostream>
using namespace std;
int xx[2][3];
int main()
{
    int t;
    cin>>t;
    while(t--){
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                cin>>xx[i][j];
            }
        }
        for(int i=2; i>=0; i--){
            for(int j=0; j<2; j++){
                cout<<*(*xx+i+j*3)<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}