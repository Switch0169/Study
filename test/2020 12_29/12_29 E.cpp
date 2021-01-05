#include<iostream>
using namespace std;
class CVector{
protected:
    int *data;
    int n;
public:
    friend class CMatrix;
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
class CMatrix{
protected:
    int Cn;
    int **Ca;
public:
    CMatrix(int Cn1){
        Cn = Cn1;
        Ca = new int *[Cn];
        for(int i=0; i<Cn; i++){
            Ca[i] = new int [Cn];
        }
        for(int i=0; i<Cn; i++){
            for(int j=0; j<Cn; j++){
                cin>>Ca[i][j];
            }
        }
    }
    bool ableMul(CVector &ra){
        if(Cn!=ra.n){
            return 0;
        }
        else
            return 1;
    }
    void Multi(CVector &V1){
        int *bn = new int [Cn];
        if(ableMul(V1)!=1){
            cout<<"error"<<endl;
        }
        else{
            for(int i=0; i<Cn; i++){
                bn[i]=0;
            }
            for(int j=0; j<Cn; j++){
                for(int i=0;i<Cn;i++){
                    bn[j]+=Ca[i][j]*V1.data[i];
                }
            }
            for(int i=0; i<Cn; i++){
                cout<<bn[i]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        CMatrix x1(n);
        int n1;
        cin>>n1;
        int *ra = new int [n1];
        for(int i=0; i<n1; i++){
            cin>>ra[i];
        }
        CVector x2(n1,ra);
        x1.Multi(x2);
    }
    return 0;
}