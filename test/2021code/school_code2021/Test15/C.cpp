#include<iostream>
using namespace std;
int d[10000];
int n;

void print()
{
    for(int i = 0; i <= n; i++){
        cout << d[i] << " ";
    }
    cout << endl;
}
void adjust(int i, int last)
{
    int left = 2 * i <= last ? 2 * i : -1;
    int right = 2 * i + 1 <= last ? 2 * i + 1 : -1;
    int mink = -1;
    if(left != -1 && right != -1){
        mink = d[left] < d[right] ? left : right;
    }
    else if(left != -1){
        mink = left;
    }
    else if(right != -1){
        mink = right;
    }
    if(mink != -1){
        if(d[i] <= d[mink]){
            return ;
        }
        else{
            swap(d[i], d[mink]);
            if(mink * 2 <= last)
                adjust(mink, last);
        }
    }
}
void mysort(int last)
{
    for(int j = last; j >= 1; j--){
        for(int i = j / 2; i > 0; i--){
            adjust(i, j);
        }
        print();
        swap(d[1], d[j]);
    }
}
int main()
{
    cin >> n;
    d[0] = n;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }
    mysort(n);
    return 0;
}