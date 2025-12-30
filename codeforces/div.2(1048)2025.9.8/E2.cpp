#include <bits/stdc++.h>
#define pb push_back
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1), dep(n + 1), f(n + 1), cnt(n + 1);
    dep[1] = 1;
    cnt[1]++;
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i], f[p[i]] = 1;
        dep[i] = dep[p[i]] + 1;
        cnt[dep[i]]++;
        f[p[i]] = 1;
    }
    int d = n;
    for (int i = 1; i <= n; i++)
    {
        if (!f[i])
            d = min(d, dep[i]);
    }
    vector<int> c(n + 1);
    int sum = 0;
    for (int i = 1; i <= d; i++)
    {
        c[cnt[i]]++;
        sum += cnt[i];
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int x = 1; x <= n; x++)
    {
        if (!c[x])
            continue;
        for (int k = 1; k <= c[x]; k *= 2)
        {
            for (int i = n; i >= k * x; i--)
            {
                dp[i] |= dp[i - k * x];
            }
            c[x] -= k;
        }

        int k = c[x];
        for (int i = n; i >= k * x; i--)
            dp[i] |= dp[i - k * x];
    }
    for (int i = 0; i <= n; i++)
    {
        if (i <= k && sum - i <= n - k && dp[i])
        {
            cout << d << '\n';
            return;
        }
    }
    cout << d - 1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}