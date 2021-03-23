#include<iostream>
using namespace std;
class SeqList{
private:
    int *list;
    int maxsize;
    int size;
public:
    SeqList(){
        maxsize = 1000;
        list = new int [maxsize];
        size = 0;
    }
    ~SeqList(){
        delete[] list;
    }
    int getsize(){
        return size;
    }
    void list_display(){
        cout<<size<<" ";
        for(int i=0; i<size; i++){
            cout<<list[i]<<" ";
        }
        cout<<endl;
    }
    int list_insert(int i, int item){
        for(int j = size-1; j>=i-1; j--){
            list[j+1] = list[j];
        }
        list[i-1] = item;
        size++;
        return 1;
    }
};
int main()
{
    int item1[1000],item2[1000];
    SeqList xx;
    int n,m;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>item1[i];
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>item2[i];
    }
    int t1=0,t2=0;
    int t3 = 1;
    while(t1<=n-1&&t2<=m-1){
        if(item1[t1]<item2[t2]){
            xx.list_insert(t3,item1[t1]);
            t1++;
        }
        else{
            xx.list_insert(t3,item2[t2]);
            t2++;
        }
        t3++;
    }
    while(xx.getsize()<n+m){
        if(t1<n){
            xx.list_insert(t3, item1[t1]);
            t1++;
        }
        if(t2<m){
            xx.list_insert(t3, item2[t2]);
            t2++;
        }
        t3++;
    }
    xx.list_display();
    return 0;
}