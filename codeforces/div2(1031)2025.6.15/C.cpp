#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i];
        g[i] = '1' + g[i];
    }
    vector<vector<int>> sum(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + (g[i][j] == 'g') - sum[i - 1][j - 1];
    auto get = [&](int x, int y) -> int
    {
        int lx = max(1, x - k + 1), ly = max(1, y - k + 1);
        int rx = min(n, x + k - 1), ry = min(m, y + k - 1);
        return sum[rx][ry] - sum[lx - 1][ry] - sum[rx][ly - 1] + sum[lx - 1][ly - 1];
    };
    int res = 1e9;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (g[i][j] == '.')
                res = min(res, get(i, j));
    }
    cout << sum[n][m] - res << '\n';
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