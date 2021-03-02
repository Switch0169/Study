#include<iostream>
using namespace std;
#define ll long long
ll divisor(ll a, ll b) {
	ll temp;
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int main()
{
    return 0;
}