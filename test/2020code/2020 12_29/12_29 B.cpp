#include<iostream>
using namespace std;
template<class T>
class Matrix{
protected:
    T a[100][100]={{0}};
    int mlen;
    int nlen;
public:
    Matrix(int m, int n, T **ra){
        mlen = m;
        nlen = n;
        for(int i=0; i<mlen; i++){
            for(int j=0; j<nlen; j++){
                a[i][j]=ra[i][j];
            }
        }
    }
    void transport(){
        T c[100][100]={{0}};
        for(int i=0; i<nlen; i++){
            for(int j=0; j<mlen; j++){
                c[i][j]=a[j][i];
            }
        }
        for(int i=0; i<mlen; i++){
            for(int j=0; j<nlen; j++){
                a[i][j]=0;
            }
        }
        int temp = mlen;
        mlen = nlen;
        nlen = temp;
        for(int i=0; i<mlen; i++){
            for(int j=0; j<nlen; j++){
                a[i][j]=c[i][j];
            }
        }
    }
    void print(){
        for(int i=0; i<mlen; i++){
            for(int j=0; j<nlen; j++){
                cout<<a[i][j]<<" ";
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
        char x1;
        cin>>x1;
        int m,n;
        cin>>m>>n;
        if(x1=='I'){
            int **ra;
            ra = new int *[m];
            for(int i=0; i<m; i++){
                ra[i] = new int [n];
            }
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    cin>>ra[i][j];
                }
            }
            Matrix <int>pa(m,n,ra);
            pa.transport();
            pa.print();
        }
        if(x1=='D'){
            double **da;
            da = new double *[m];
            for(int i=0; i<m; i++){
                da[i] = new double [n];
            }
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    cin>>da[i][j];
                }
            }
            Matrix <double>xa(m,n,da);
            xa.transport();
            xa.print();
        }
        if(x1=='C'){
            char **ca;
            ca = new char *[m];
            for(int i=0; i<m; i++){
                ca[i] = new char [n];
            }
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    cin>>ca[i][j];
                }
            }
            Matrix <char>xa1(m,n,ca);
            xa1.transport();
            xa1.print();
        }
    }
    return 0;
}