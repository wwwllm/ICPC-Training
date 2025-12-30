#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f3f3f3f;
void solve()
{
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(l + 1);
    int sum = 0, mi = INF;
    for (int i = 1; i <= l; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] & 1)
            mi = min(mi, a[i]);
    }
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 1; i <= m; i++)
    {
        int v, u;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<array<int, 2>> d(n + 1, {INF, INF});
    d[1][0] = 0;
    auto dij = [&]()
    {
        queue<array<int, 2>> q;
        q.push({1, 0});
        while (q.size())
        {
            auto [v, op] = q.front();
            q.pop();
            for (auto u : g[v])
            {
                if (d[u][!op] > d[v][op] + 1)
                {
                    d[u][!op] = d[v][op] + 1;
                    q.push({u, !op});
                }
            }
        }
    };
    dij();
    int s0 = 0, s1 = 0;
    if (sum & 1)
        s1 = sum, s0 = sum - mi;
    else
        s0 = sum, s1 = sum - mi;
    // cout << s0 << ' ' << s1 << '\n';
    for (int i = 1; i <= n; i++)
    {
        bool ok = 0;
        if (d[i][0] <= s0 || d[i][1] <= s1)
            ok = 1;
        cout << ok;
    }
    cout << '\n';
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