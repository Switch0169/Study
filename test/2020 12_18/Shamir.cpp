#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long Qucik_Mi(long long base, long long x, long long p)
{
    long long ans = 1;
    base = base % p;
    while(x>0){
        if(x%2==1){
            ans = ans * base % p;
        }
        x = x / 2;
        base = base * base % p;
    }
    return ans;
}
int cal(int a,int m)//求逆元
{
    a = Qucik_Mi(a,m-2,m);
    return a;
}

long long mod(long long x, long long p){
    if(x>=0){
        x = x % p;
    }
    else{
        while(x<0){
            x = x + p;
        }
    }
    return x;
}
long long modx(long long fz, long long fm, long long p){
    long long ans = 1;
    long long a = cal(fm,p);
    long long b = mod(fz,p);
    ans = cal(fm,p) * mod(fz,p);
    return ans;
}
int main()
{
    long long p = 0;
    long long n = 0;
    long long t = 0;
    long long a[1000]={0};
    cin>>p;
    cin>>n;
    cin>>t;
    for(int i=0; i<=t-1; i++){
        a[i]=rand() % (p/100);
    }
    long long s[1000]={0};
    long long x[1000]={0};
    for(int i=1; i<=t; i++){
        x[i]= i;
        s[i]=a[0];
        for(int j = 1; j<=t-1; j++){
            s[i]=s[i]+a[j]*pow(x[i],j);
        }
    }
    long long ans = 0;
    long long temp = 1;
    long long fz[1000] = {0};
    long long fm[1000] = {0};
    for(int i=1; i<=t; i++){
        temp = 1;
        fz[i] = 1;
        fm[i] = 1;
        for(int j=1; j<=t; j++){
            if(i==j) continue;
            fz[i] = fz[i] * (-x[j]);
            fm[i] = fm[i] * (x[i]-x[j]);
        }
        fz[i] = s[i] * fz[i];
    }
    long long total_fz = 0;
    long long total_fm = 1;
    for(int i=1; i<=t; i++){
        total_fm = fm[i] * total_fm; 
    }
     for(int i=1; i<=t; i++){
        total_fz = total_fz + (fz[i] * total_fm / fm[i]) ; 
    }
    ans = modx(total_fz, total_fm, p);
    ans=ans%p;
    while(ans<0){
        ans=(ans+p)%p;
    }
    cout<<a[0]-ans<<endl;
    return 0;
}