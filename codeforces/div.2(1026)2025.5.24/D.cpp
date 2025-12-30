#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> g(n + 1);
    vector<int> b(n + 1);
    int r = 0;
    for (int i = 1; i <= n; i++)
        cin >> b[i], r += b[i];
    r++;
    int sum = r;
    int l = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    auto cmp = [&](int x)
    {
        vector<int> sum(n + 1);
        for (int i = 1; i < n; i++)
        {
            if (i > 1 && !sum[i])
                continue;
            sum[i] = min(sum[i] + b[i], x);
            for (auto [v, w] : g[i])
            {
                if (w <= sum[i])
                    sum[v] = max(sum[i], sum[v]);
            }
        }
        return sum[n] > 0;
    };
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (cmp(mid))
            r = mid;
        else
            l = mid;
    }
    if (r == sum)
        cout << -1 << '\n';
    else
        cout << r << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}