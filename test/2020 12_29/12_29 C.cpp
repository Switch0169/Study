#include<iostream>
#include<algorithm>
using namespace std;
template<class T>
class BoundArray{
protected:
    T a[100]={0};
    int len = 0;
public:
    BoundArray(T *ra, int n){
        len = n;
        for(int i=0; i<len; i++){
            a[i]=ra[i];
        }
    }
    void Mysort(){
        sort(a,a+len);
        for(int i=0; i<len; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    void find(T xa){
        int count = -1;
        for(int i=0; i<len; i++){
            if(a[i]==xa){
                count = i;
                break;
            }
        }
        cout<<count<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        char x1;
        int n;
        cin>>x1;
        cin>>n;
        if(x1=='I'){
            int *ra = new int [n];
            for(int i=0; i<n; i++){
                cin>>ra[i];
            }
            BoundArray <int>Ia(ra, n);
            Ia.Mysort();
            int h;
            cin>>h;
            Ia.find(h);
        }
        if(x1=='C'){
            char *ra = new char [n];
            for(int i=0; i<n; i++){
                cin>>ra[i];
            }
            BoundArray <char>Ia(ra, n);
            Ia.Mysort();
            char h;
            cin>>h;
            Ia.find(h);
        }
        if(x1=='D'){
            double *ra = new double [n];
            for(int i=0; i<n; i++){
                cin>>ra[i];
            }
            BoundArray <double>Ia(ra, n);
            Ia.Mysort();
            double h;
            cin>>h;
            Ia.find(h);
        }
    }
    return 0;
}