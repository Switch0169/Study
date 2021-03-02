#include<iostream>
using namespace std;
int t = 0;
bool is_ji(int x){
    if(x%2!=0){
        return 1;
    }
    else
        return 0;
}
int last_hand(int x){
    int hander = 1;
    while(x>2){
        x = x - 1;
        hander = -hander;
        if(hander == 1){
            t++;
        }
    }
    return hander;
}
int main()
{
    int n;
    cin>>n;
    int Jicount = 0;
    int a;
    for(int i=0; i<n; i++){
        cin>>a;
        if(is_ji(a)){
            Jicount++;
        }
    }
    if(last_hand(n)==-1)
        cout<<"NiuMei"<<endl;
    else{
        if(t*2>=Jicount){
            cout<<"NiuMei"<<endl;
        }
        else{
            cout<<"NiuNiu"<<endl;
        }
    }
    return 0;
}