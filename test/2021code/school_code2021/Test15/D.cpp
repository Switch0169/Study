#include<iostream>
using namespace std;
int d[10000];
int n;
void print()
{
    for(int i = 1; i <= n; i++){
        cout << d[i] << " ";
    }
    cout << endl;
}
void insert(int left, int right){
    int now = right - 1;
    int last = right;
    while(now >= left){
        if(d[last] < d[now]){
            swap(d[last], d[now]);
            last--;
            now--;
        }
        else{
            break;
        }
    }
    print();
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }
    for(int i = 2; i <= n; i++){
        insert(1, i);
    }
    return 0;
}