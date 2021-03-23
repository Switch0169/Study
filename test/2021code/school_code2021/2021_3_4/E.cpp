#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        char type;
        cin>>type;
        int n;
        cin>>n;
        if(type=='I'){
            int *x = new int [n];
            int tt = 0;
            for(int i=0; i<n; i++){
                cin>>*x;
                tt += *x;
                x++;
            }
            tt = tt / n;
            cout<<tt<<endl;
        }
        else if(type=='C'){
            char *x = new char [n];
            int nn;
            for(int i=0; i<n; i++){
                cin>>*(x+i);
            }
            char maxc = 0;
            for(int i=0; i<n; i++){
                if(maxc<*(x+i)){
                    maxc = *(x+i);
                }
            }
            cout<<maxc<<endl;
        }
        else if(type=='F'){
            double *x = new double [n];
            int nn;
            for(int i=0; i<n; i++){
                cin>>*(x+i);
            }
            double minc = 100000;
            for(int i=0; i<n; i++){
                if(minc>*(x+i)){
                    minc = *(x+i);
                }
            }
            cout<<minc<<endl;
        }
    }
    return 0;
}