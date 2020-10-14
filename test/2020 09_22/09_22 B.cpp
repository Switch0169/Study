#include <iostream>
using namespace std;
int main ()
{
    int m,i,j,t,n,low=0,high=0;
    cin>>t;
    int **a = new int* [m];
    while(t--){
        cin>>m>>n;
        for(i = 0; i < m; i++)
            a[i] = new int [n];
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cin>>a[i][j];
                if(i==0&&j==0){
                    low=a[i][j];
                    high=a[i][j];
                }
                if(a[i][j]>high){
                    high=a[i][j];
                }
                if(a[i][j]<low){
                    low=a[i][j];
                }
            }
        }
        cout<<low<<" "<<high<<endl;
    }
    return 0;
}