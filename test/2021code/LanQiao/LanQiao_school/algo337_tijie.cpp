#include <iostream>
#include <cstdio>

using namespace std;
#define min(a, b) a < b ? a : b
const int maxn = 20;
int n;
int x;
double ans;
bool vis[maxn];
double pc[maxn], pm[maxn];

void dfs(double c, double m)
{
    if (m >= 666)
        ans = min(ans, c);
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            vis[i] = 1;
            double nowc = pc[i];
            double nowm = pm[i];
            dfs(c+nowc,m+nowm);
            for (int j = 1; j <= 30; j++)
            {
                nowc /= 3;
                nowm /= 3;
                if (m >= x * j)
                    dfs(c + nowc, m + nowm - x * j);
                if (nowc <= 0.1 || nowm <= 0.1)
                    break;
            }
            vis[i] = 0;
        }
    }
}

int main()
{
    /**
     * 直接暴力即可
     * 打不打这个厨师？
     * 要不要先用邪恶之树？
     * 如果要用，想用几次？
     */
    // freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &x);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &pc[i], &pm[i]);
        for (int i = 0; i < n; i++)
            vis[i] = 0;
        ans = 1e18;
        dfs(0, 0);
        if (ans < 1e18)
            printf("%.0lf\n", ans);
        else
            printf("impossible\n");
    }
    return 0;
}