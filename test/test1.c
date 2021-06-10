#include<stdio.h>
int main()
{
    int m = 0x006D30F4;
    int n = 0x00FF0000;//引进一个操作数
    int a[] = {0, 1, 2, 3};
    for(int i = 0; i < 4; i++){
        printf(" %d" + !i, a[i]);//偏移地址取消a[0]前的空格
    }
    // printf("1234" + 1);
    return 0;
}
