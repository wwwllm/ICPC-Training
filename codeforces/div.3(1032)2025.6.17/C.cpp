#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    vector<array<int, 3>> pq;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            pq.push_back({g[i][j], i, j});
        }
    sort(pq.begin(), pq.end(), greater<array<int, 3>>());
    int ans = 200, res = 200;
    auto f = pq[0];
    ans = res = f[0] - 1;
    int p = -1;
    for (auto [n, x, y] : pq)
    {
        if (x == f[1] || y == p)
        {
            ans = max(ans, n - 1);
        }
        else if (p == -1)
        {
            ans = max(ans, n - 1);
            p = y;
        }
        else
        {
            ans = max(ans, n);
            break;
        }
    }
    p = -1;
    for (auto [n, x, y] : pq)
    {
        if (y == f[2] || x == p)
        {
            res = max(res, n - 1);
        }
        else if (p == -1)
        {
            res = max(res, n - 1);
            p = x;
        }
        else
        {
            res = max(res, n);
            break;
        }
    }
    cout << min(ans, res) << '\n';
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