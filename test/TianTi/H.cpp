#include<iostream>
#include<cstdio>
using namespace std;
int Teamnum[10000];
int grade[10000];
int main()
{
    int N;
    cin >> N;
    int t = 0;
    while(N--){
        int temp;
        int x;
        scanf("%d-%d %d", &Teamnum[t], &x, &temp);
        grade[Teamnum[t]] += temp;
        t++;
    }
    int maxn = 0;
    int maxid = 0;
    for(int i = 0; Teamnum[i] != 0; i ++){
        if(grade[Teamnum[i]] > maxn){
            maxn = grade[Teamnum[i]];
            maxid = Teamnum[i];
        }
    }
    cout << maxid << " " << maxn << endl;
    return 0;
}