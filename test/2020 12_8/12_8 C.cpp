#include<iostream>
using namespace std;
class Matrix
{
protected:
    int m;
    int n;
    int **data;
public:
    Matrix(){
        m=0;
        n=0;
    }
    Matrix(int rm,int rn){
        m=rm;
        n=rn;
        data = new int *[m];
        for(int i=0;i<m;i++){
            data[i] = new int [n];
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>data[i][j];
            }
        }
    }
    void Set(int rm,int rn)
    {
        m=rm;
        n=rn;
        data = new int *[m];
        for(int i=0;i<m;i++){
            data[i] = new int [n];
        }
    }
    void Setdata(int i, int j, int m)
    {
        data[i][j]=m;
    }
    int Getdata(int i, int j)
    {
        return data[i][j];
    }
    void display()
    {
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    ~Matrix(){
        for(int i=0; i<m; i++){
            delete []data[i];
        }
        delete []data;
    }
    friend Matrix operator+(Matrix &a, Matrix &b);
};
Matrix operator+(Matrix &a, Matrix &b)
{
    int m=a.m;
    int n=a.n;
    Matrix ans;
    ans.Set(m,n);
    for(int i = 0; i<m;i++){
        for(int j=0;j<n;j++){
            ans.Setdata(i,j,a.Getdata(i,j)+b.Getdata(i,j));
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int m=0,n=0;
        cin>>m>>n;
        Matrix a(m,n);
        Matrix b(m,n);
        (a+b).display();
    }
    return 0;
}