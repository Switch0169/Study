#include<iostream>
using namespace std;

int d[10000];
int n;
void print(){
    for(int i = 1; i <= n; i++){
        cout << d[i] << " ";
    }
    cout << endl;
}
void mysort(int low, int height)
{
    int left = low;
    int right = height;  
    if(low >= height)
        return ;
    int key = d[left];
    while(left < right){
        while(left < right && d[right] >= key){
            right--;
        }
        d[left] = d[right];
        while(left < right && d[left] <= key){
            left++;
        }
        d[right] = d[left];
    }
    int mid = left;
    d[mid] = key;
    print();
    mysort(low, mid - 1);
    mysort(mid + 1, height);
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> d[i];
        }
        mysort(1, n);
        cout << endl;
    }
    return 0;
}