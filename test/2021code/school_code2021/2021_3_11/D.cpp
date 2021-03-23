#include<iostream>
using namespace std;
int temp[1000];
int fushu_mod(int x, int y){
    int tt = x;
    if(x<0){
        while(tt<0){
            tt += y;
        }
    }
    else{
        tt = x%y;
    }
    return tt;
}
class SeqList{
private:
    int *list;
    int maxsize;
    int size;
public:
    SeqList(){
        maxsize = 1000;
        size = 0;
        list = new int [maxsize];
    }
    ~SeqList(){
        delete[] list;
    }
    int list_size(){
        return size;
    }
    void list_insert(int i, int item){
        for(int j = size-1; j>=i-1; j--){
            list[j+1] = list[j];
        }
        list[i-1] = item;
        size++;
    }
    void multidel(int i, int n){
        for(int j = i-1; j<= i-1+n ; j++){
            list[j] = list[j+n];
        }
        size -= n;
    }
    void move(int w, int f)
    {
        if(f==0){
            int tsize = size;
            for(int j=0; j<tsize; j++){
                temp[j] = list[(j+w)%tsize];
            }
            multidel(1,tsize);
            for(int j=0; j<tsize; j++){
                list_insert(j+1,temp[j]);
            }
        }
        else{
            int tsize = size;
            for(int j=0; j<tsize; j++){
                temp[j] = list[fushu_mod(j-w,tsize)];
            }
            multidel(1,tsize);
            for(int j=0; j<tsize; j++){
                list_insert(j+1,temp[j]);
            }
        }
    }
    void list_display(){
        for(int i=0; i<size; i++){
            cout<<list[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    SeqList xx;
    int n;
    cin>>n;
    int temp;
    for(int i=0; i<n; i++){
        cin>>temp;
        xx.list_insert(i+1, temp);
    }
    xx.list_display();
    int f, w;
    cin>>f>>w;
    xx.move(w,f);
    xx.list_display();
    cin>>f>>w;
    xx.move(w,f);
    xx.list_display();
    return 0;
}