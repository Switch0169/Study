#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn = 1000;

ll mod_mul(ll a, ll b, ll mod)
{
    ll res = 0;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

ll quickMi(ll a, ll b, ll m)
{
    ll aa = a;
    ll ret = 1;
    while (b)
    {
        if (b % 2 == 1)
            // ret = (ret * aa) % m;
            ret = mod_mul(ret, aa, m);
        // aa = (aa * aa) % m;
        aa = mod_mul(aa, aa, m);
        b /= 2;
    }
    return ret;
}
ll h[maxn];
ll a[maxn];
ll fz[maxn];
ll fm[maxn];
int main()
{
    ll p;
    int n, t;
    // while (cin >> p >> n >> t)
    // {
    cin >> p >> n >> t;
    for (int i = 0; i < t; i++)
    {
        a[i] = rand() % (p);
    }
    for (int i = 1; i <= n; i++)
    {
        int k = t;
        while (k)
        {
            h[i] += (a[k - 1] * quickMi(i, k - 1, p));
            k -= 1;
        }
    }
    h[0] = a[0];
    int xishu = (t % 2 == 0) ? -1 : 1;
    ll calS = 0;
    for (int i = 1; i <= t; i++)
    {
        // ll cnt = h[i];
        fz[i] = fm[i] = 1;
        for (int j = 1; j <= t; j++)
        {
            if (i == j)
                continue;
            fz[i] *= j;
            fm[i] *= (i - j);
        }
        fz[i] *= h[i];
    }
    ll totfz, totfm;
    totfz = 0;
    totfm = 1;
    for (int i = 1; i <= t; i++)
    {
        ll tfz = totfz;
        ll tfm = totfm;
        totfz = tfz * fm[i] + fz[i] * tfm;
        totfm = tfm * fm[i];
    }
    while (totfm < 0)
        totfm = (totfm + p) % p;
    while (totfz < 0)
        totfz = (totfz + p) % p;
    totfm = quickMi(totfm, p - 2, p);
    calS = (totfz * totfm) % p;
    calS *= xishu;
    cout << (calS - a[0]) << endl;
    // cout<<calS<<endl;
    // cout<<a[0]<<endl;
    // }
    return 0;
}