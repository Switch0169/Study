#include<iostream>
using namespace std;
int isprime[100000];
int prime[1000];
int F[1000000];
int Eratosthenes(int n) {
  int p = 0;
  for (int i = 0; i <= n; ++i) isprime[i] = 1;
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i <= n; ++i) {
    if (isprime[i]) {
      prime[p] = i;
      p++;  
      for (int j = i * i; j <= n; j += i)  
        isprime[j] = 0;
    }
  }
  return p;
}
void getF(int n){
    for(int i=2; i<n; i++){
        int temp = i;
        
    }

}
int main()
{
    Eratosthenes(100);
    int n;
    cin>>n;
    return 0;
}