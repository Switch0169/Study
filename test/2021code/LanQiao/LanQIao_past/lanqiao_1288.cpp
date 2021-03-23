#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn = 1001;
char str[maxn];
char str1[maxn];
char str2[maxn];
int len;
int child_len;
int c[maxn][maxn];

void init_str(){
    len = strlen(str);
    for(int i=0; i<len+1; i++){
        str1[i+1] = str[i];
        c[i][0] = 0;
    }
    int j=len;
    for(int i=0; i<len+1; i++){
        str2[i+1] = str1[j];
        c[0][i] = 0;
        j--;
    }
}
int LCS(){
    for(int i=0; i<len+1; i++){
        for(int j=0; j<len+1; j++){
            if(str1[i]==str2[j]&&i>0&&j>0){
                c[i][j]=c[i-1][j-1]+1;
            }
            if(str1[i]!=str2[j]&&i>0&&j>0){
                c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    return c[len][len];
}
int main()
{
    while(scanf("%s",str)!=EOF){
        init_str();
        cout<<len - LCS()<<endl;
    }
    return 0;
}