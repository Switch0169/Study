#include<stdio.h>
int main()
{
    int m = 0x006D30F4;
    int n = 0x00FF0000;//引进一个操作数
    n=(m&n)>>16;
    printf("%d,",n);//将逗号以及逗号前的转化后数据输出
    n=0x00FFFF;
    n=(n&m);
    printf("%d",n);//将逗号后面的数据输出
    return 0;
}
