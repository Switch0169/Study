#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int grade;
    cin >> grade;
    if(grade >= 90){
        printf("gong xi ni kao le %d fen!\n", grade);
    }
    else{
        printf("kao le %d fen bie xie qi!\n", grade);
    }
    return 0;
}