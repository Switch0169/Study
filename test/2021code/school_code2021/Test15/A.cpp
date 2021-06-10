#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int d[10000];
void insert(int start, int gap, int index){
    int now = index - gap;
    int last = index;
    while(now >= start){
        if(d[last] > d[now]){
            swap(d[now], d[last]);
            now -= gap;
            last -= gap;
        }
        else{
            break;
        }
    }
}
int main()
{
    // freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(d, 0, sizeof(d));
        for(int i = 1; i <= n; i++){
            cin >> d[i];
        }
        int gap = n / 2;
        while(gap > 0){
            for(int i = 1; i + gap <= n; i++){
                int start = i;
                int index = i + gap;
                while(index <= n){
                    insert(start, gap, index);
                    index += gap;
                }
            }
            for(int i = 1; i <= n; i++){
                cout << d[i] << " ";
            }
            cout << endl;
            gap /= 2;
        }
        cout << endl;
    }
}