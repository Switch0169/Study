#include<iostream>
using namespace std;
class CVector{
protected:
    int *data;
    int n;
public:
    CVector(){
        n = 5;
        data = new int [n];
        for(int i=0; i<n; i++){
            data[i]=i;
        }
    }
    CVector(int n1, int *a){
        n = n1;
        data = new int [n];
        for(int i=0; i<n; i++){
            data[i]=a[i];
        }
    }
    void print(){
        for(int i=0; i<n; i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    ~CVector(){
        delete []data;
    }
};
int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    CVector x1;
    x1.print();
    CVector x2(n,a);
    x2.print();
    return 0;
}