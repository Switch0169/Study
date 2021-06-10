#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int h[10002];
int num[10002];
int main()
{
    int N;
    while(cin >> N){
        memset(num, 0, sizeof(num));
        for(int i = 0; i < N; i++){
            scanf("%d", &h[i]);
        }
        int total = 0;
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                if(h[j] < h[i]){
                    num[i]++;
                }
                else{
                    break;
                }
            }
            total += num[i];
        }
        cout << total << endl;
    }
    return 0;
}