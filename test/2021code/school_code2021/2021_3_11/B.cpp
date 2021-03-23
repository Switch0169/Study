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
    void multiinsert(int i, int n, int item[]){
        int t = 0;
        for(int j = size-1; j>=i-1; j--){
            list[j+n] = list [j];
        }
        for(int j = i; j <= i-1+n; j++){
            list[j-1] = item[t];
            t++;
        }
        size += n;
    }
    void multidel(int i, int n){
        for(int j = i-1; j<= i-1+n ; j++){
            list[j] = list[j+n];
        }
        size -= n;
    }
    void list_display(){
        cout<<size<<" ";
        for(int i=0; i<size; i++){
            cout<<list[i]<<" ";
        }
        cout<<endl;
    }
    int list_insert(int i, int item){
        if(i>size+1||i<=0){
            return -1;
        }
        else{
            for(int j = size-1; j>=i-1; j--){
                list[j+1] = list[j];
            }
            list[i-1] = item;
            size++;
            return 1;
        }
    }
};
int main()
{
    int n;
    cin>>n;
    SeqList xx;
    for(int i=1; i<=n; i++){
        int tt;
        cin>>tt;
        xx.list_insert(i,tt);
    }
    xx.list_display();
    int item[1000];
    int k;
    int ii;
    cin>>ii;
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>item[i];
    }
    xx.multiinsert(ii,k,item);
    xx.list_display();
    cin>>ii;
    cin>>k;
    xx.multidel(ii,k);
    xx.list_display();
    return 0;    
}