#include<cstdio>
#include<iostream>
#include<iomanip>
using namespace std;
int num=0,a[10001]={0},n,r;
bool b[10001]={0};
int search(int); //回溯过程
int print(); //输出方案
 
int main()
{
  cout<<"input n,r:";
  cin>>n>>r;
  search(1);
  cout<<"number="<<num<<endl;     //输出方案总数
}
int search(int k)//第几个数
{
    int i;
    for (i=1;i<=n;i++)//第k个数有n种可能的结果，要一个一个试。
     if  (!b[i]) //判断第i个数是否可用
      {
         a[k]=i;    //保存结果
         b[i]=1;
         if (k==r) print();
            else search(k+1);
         b[i]=0; 
      }
}
int print()
{
  num++;
  for (int i=1;i<=r;i++)
    cout<<setw(3)<<a[i];
  cout<<endl; 
}