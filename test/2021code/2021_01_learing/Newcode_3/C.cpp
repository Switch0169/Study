#include<iostream>
using namespace std;
int table[8][8];
void getpoint(int x, int y, int r){
    for(int i=0; i<=7; i++){
        for(int j=0; j<=7; j++){
            if(mydistance(i,j,x,y)<=r){
                table[i][j]++;
            }
        }
    }
}
int mydistance(int x1, int y1, int x2, int y2){
    int d = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    return d;
}
int main()
{
    int n,k,R;
    int x,y,r;
    cin>>n>>k>>R;
    for(int i=0; i<n; i++){
        cin>>x>>y>>r;

    }
}