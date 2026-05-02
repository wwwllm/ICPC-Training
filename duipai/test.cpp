#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
const int N = 20, M = 30, Mod = 998244353, INF = 0x3f3f3f3f;

char s[N];
bool vis[N];
int n, k, a[N], b[N];

int dfs(int pos)
{
    if (pos == k)
    {
        int sum = 0;
        for (int i = 1; i <= k; i++)
            sum = (LL)(sum + b[i]) % n;
        return a[sum];
    }

    int temp;
    if (vis[pos])
        temp = 1;
    else
        temp = 0;
    for (int i = 0; i < n; i++)
    {
        b[pos] = i;
        int x = dfs(pos + 1);
        if (vis[pos])
            temp = (LL)(temp * x) % Mod;
        else
            temp = (LL)(temp + x) % Mod;
    }
    return temp;
}

signed main()
{
    //	freopen("meet.in","r",stdin);
    //	freopen("meet.out","w",stdout);

    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    scanf("%s", s);
    for (int i = 0; i < k; i++)
    {
        if (s[i] == 's')
            vis[i] = false;
        else
            vis[i] = true;
    }

    printf("%lld\n", dfs(0));

    return 0;
}