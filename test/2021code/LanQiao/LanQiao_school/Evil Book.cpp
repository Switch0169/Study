#include<iostream>
using namespace std;

struct cook{
    int strength;
    int magic;
};
cook xcook[10]; 
int main()
{
    int T;
    while(T--){
        int N,X;
        cin>>N>>X;
        for(int i=0; i<N; i++){
            cin>>xcook[i].strength;
            cin>>xcook[i].magic;
        }
        
    }
    return 0;
}