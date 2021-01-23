#include<iostream>
#include<cstdio>
using namespace std;
long long Quickmod(long long base, long long x, long long mod)//快速幂取余
{
    long long result = 1;
    base = base % mod;
    while(x>0){
        if(x%2==1){
            result = result * base % mod;
        }
        x=x/2;
        base = base * base % mod;
    }
    return result;
}
long long Quick(long long base, long long x)//快速幂
{
    long long result = 1;
    base = base;
    while(x>0){
        if(x%2==1){
            result = result * base ;
        }
        x=x/2;
        base = base * base ;
    }
    return result;
}
int IsPrime(long long n)//判断是否为素数
{
    if(n==2){
        return 1;
    }
    if(n==0||n==1||n%2==0){
        return 0;
    }
    if(Quickmod(2,n-1,n)!=1){
        return 0;
    }
    long long a[]= {2,3,5,7,11};
    for(int i = 0; i < 5; i++){
        long long s = 10;        //设一个s使得2^s*t = n-1
        long long t = (n-1)/1024;
        long long temp = Quick(a[i],t); 
        long long k;
        while(s--){
            k=Quick(temp,2);
            if(temp!=n-1&&temp!=1&&k==1){
                return 0;
            }
            temp = k;
        }
    }
    return 1;
}
int exgcd(int a, int b, int &x, int &y){//拓展欧几里得算法
    if(b == 0){
	    x = 1;
	    y = 0;
	    return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
int cal(int a,int m)//求逆元
{
    int x,y;
    int gcd = exgcd(a,m,x,y);
    if(1%gcd!=0) 
        return -1;
    x*=1/gcd;
    m = abs(m);
    int ans = x%m;
    if(ans<=0)
        ans += m;
    return ans;
}
int main()
{
    long long p=0,q=0,e=0,n=0;
    long long d=0;
    long long c=0,c1=0;
    long long m=0,m1=0;
    while(cin>>p>>q>>e){
        cin>>m1;
        cin>>c1;
        if(IsPrime(p)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        if(IsPrime(q)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        n=p*q;
        cout<<n<<endl;
        d=cal(e,(p-1)*(q-1));
        cout<<d<<endl;
        c=Quickmod(m1,e,n);
        cout<<c<<endl;
        m=Quickmod(c1,d,n);
        cout<<m<<endl;
    }
    return 0;
}