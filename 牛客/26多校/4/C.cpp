#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector t(n + 1, vector<int>(m));
    vector<int> st(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> t[i][j];
        }
        int mask = 0;
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == 'R')
                mask |= 1LL << j;
        }
        st[i] = mask;
    }
    vector cost(m, vector<int>(1LL << m));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cost[j][st[i]] += t[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int bit = 0; bit < m; bit++)
        {
            for (int mask = 0; mask < (1LL << m); mask++)
            {
                if ((mask >> bit & 1))
                    cost[i][mask] += cost[i][mask ^ (1LL << bit)];
            }
        }
    }
    vector<int> dp((1LL << m), inf);
    dp[0] = 0;
    for (int mask = 0; mask < (1LL << m); mask++)
    {
        for (int bit = 0; bit < m; bit++)
        {
            if (mask >> bit & 1)
                continue;
            int tmp = mask | (1LL << bit);
            dp[tmp] = min(dp[tmp], dp[mask] + cost[bit][mask ^ ((1LL << m) - 1)]);
        }
    }
    cout << dp[(1LL << m) - 1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}