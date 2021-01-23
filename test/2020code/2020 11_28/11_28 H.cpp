#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    int a;
    cin >> n;
    int fnumber = 0;
    int f = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        printf("%d\n", fnumber);
        if (a >= f) {
            fnumber = i+1;
            f = a;
        }
    }
    return 0;
}
