#include<iostream>
using namespace std;
template<class T>
class List{
protected:
    T a[100]={-1};
    int len;
public:
    List(T *ra, int n){
        len = n;
        for(int i=0; i<n; i++){
            a[i]=ra[i];
        }
    }
    void add(int x, T c){
        len = len + 1;
        for(int i=len; i>x; i--){
            a[i]=a[i-1];
        }
        a[x]=c;
    }
    void del(int x){
        len = len - 1;
        for(int i=x; i<len; i++){
            a[i]=a[i+1];
        }
    }
    void print(){
        for(int i=0; i<len; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    int n;
    int ra[100]={-1};
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ra[i];
    }
    List <int>m(ra, n);
    int x,c;
    cin>>x>>c;
    m.add(x,c);
    cin>>x;
    m.del(x);
    m.print();
    double va[100]={-1};
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>va[i];
    }
    List <double>d(va, n);
    double xc;
    cin>>x>>xc;
    d.add(x,xc);
    int b;
    cin>>b;
    d.del(b);
    d.print();
    return 0;
}