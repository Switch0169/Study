#include<iostream>
#include<cstdio>

using namespace std;

const int maxn = 1001;
int n;
int numberofnow = 1;

struct Area{
    char c;
    int islandnumber;
};


Area sea[maxn][maxn];
void myinput(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>sea[i][j].c;
        }
    }
}
void count_island(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(sea[i][j].c=='#' && sea[i-1][j].islandnumber==0 && sea[i+1][j].islandnumber==0 && sea[i][j-1].islandnumber==0 && sea[i-1][j+1].islandnumber==0){
                sea[i][j].islandnumber = numberofnow;
                numberofnow++;
            }
        }
    }
}
int main()
{
    myinput();
    return 0;
}