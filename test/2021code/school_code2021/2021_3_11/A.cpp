#include<iostream>
using namespace std;

#define ok 0
#define error -1

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
    int list_insert(int i, int item){
        if(i>size+1||i<=0){
            return error;
        }
        else{
            for(int j = size-1; j>=i-1; j--){
                list[j+1] = list[j];
            }
            list[i-1] = item;
            size++;
            return ok;
        }
    }
    int list_del(int i){
        if(i>size||i<=0){
            return error;
        }
        else{
            for(int j = i-1; j <=size-1; j++){
                list[j] = list[j+1];
            }
            size--;
            return ok;
        }
    }
    int list_get(int i){
        if(i>size||i<=0){
            return error;
        }
        else{
            return list[i-1];
        }
    }
    void list_display(){
        cout<<size<<" ";
        for(int i=0; i<size; i++){
            cout<<list[i]<<" ";
        }
        cout<<endl;
    }
    void err(){
        cout<<"error"<<endl;
    }
};
int main()
{
    int n;
    cin>>n;
    SeqList xx;
    for(int i=1; i<=n; i++){
        int temp;
        cin>>temp;
        xx.list_insert(i,temp);
    }
    xx.list_display();
    int ii,itt;
    cin>>ii;
    cin>>itt;
    if(xx.list_insert(ii,itt)==ok)
        xx.list_display();
    else
        xx.err();
    cin>>ii;
    cin>>itt;
    if(xx.list_insert(ii,itt)==ok)
        xx.list_display();
    else
        xx.err();
    cin>>ii;
    if(xx.list_del(ii)==ok)
        xx.list_display();
    else    
        xx.err();
    cin>>ii;
    if(xx.list_del(ii)==ok)
        xx.list_display();
    else
        xx.err();
    cin>>ii;
    if(xx.list_get(ii)==error)
        xx.err();
    else
        cout<<xx.list_get(ii);
    cin>>ii;
    if(xx.list_get(ii)==error)
        xx.err();
    else
        cout<<xx.list_get(ii);
    return 0;
}