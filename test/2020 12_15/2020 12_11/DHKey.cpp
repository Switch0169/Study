#include<iostream>
using namespace std;
int P;
int pNum = 0;
const int NUM = 32170;
int prime[NUM/4];

long long Quick(long long base, long long x)
{
    long long ans = 1;
    while(x>0){
        if(x%2==1){
            ans = ans * base;
        }
        x = x/2;
        base = base * base;
    }
    return ans;
}
long long Quickaddmod(long long m, long long n, long long mod)
{
    long long ans = 0;
    m = m % mod;
    while(n>0){
        if(n%2==1){
            ans = (ans + m)% mod;
        }
        n = n/2;
        m = (m + m) % mod;
    }
    return ans;
}
long long Quickmod(long long base, long long x, long long mod)
{
    long long ans = 1;
    base = base % mod;
    while(x>0){
        if(x%2==1){
            ans = Quickaddmod(ans,base,mod);
        }
        x = x/2;
        base = Quickaddmod(base,base,mod);
    }
    return ans;
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

bool judge(int num)//求num的所有的质因子
{
	int elem[1000];
	int elemNum = 0;
	int k = P - 1;
	for (int i = 0; i < pNum; ++ i)
	{
		bool flag = false;
		while (!(k%prime[i]))
		{
			flag = true;
			k /= prime[i];
		}
		if (flag)
		{
			elem[elemNum ++] = prime[i];
		}
		if (k==1)
		{
			break;
		}
		if (k/prime[i]<prime[i])
		{
			elem[elemNum ++] = prime[i];
			break;
		}
	}
	bool flag = true;
	for (int i = 0; i < elemNum; ++ i)
	{
		if (Quickmod(num,(P-1)/elem[i],P) == 1)
		{
			flag = false;
			break;
		}
	}
	return flag;
}
int main()
{
    long long p,g;
    long long a = rand();
    long long b = rand();
    while(cin>>p){
        P = p;
        cin>>g;
        if(IsPrime(p)){
            cout<<"Yes"<<endl;
        }
        if(judge(g)){
            long long A = Quickmod(g,a,p);
            long long B = Quickmod(g,b,p);
            long long Ka = Quickmod(B,a,p);
            long long Kb = Quickmod(A,b,p);
            long long K = Ka - Kb;
            cout<<K<<endl;
        }
    }
    return 0;
}