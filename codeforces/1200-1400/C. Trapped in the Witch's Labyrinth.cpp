#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2034/C
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<int>> st(n, vector<int>(m, -1)), path(n, vector<int>(m, 0));
    for (auto &it : g)
        for (auto &ele : it)
            cin >> ele;
    auto cmp = [&](int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    array<int, 2> d[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    auto dfs = [&](auto &&self, int x, int y) -> bool
    {
        if (!cmp(x, y) || st[x][y] == 1)
            return 1;
        if (cmp(x, y) && st[x][y] == 0)
            return 0;
        if (path[x][y])
            return 0;
        path[x][y] = 1;
        if (g[x][y] == '?')
        {
            bool flag = 1;
            for (auto [xx, yy] : d)
            {
                flag &= self(self, x + xx, y + yy);
            }
            st[x][y] = flag;
        }
        else if (g[x][y] == 'U')
        {
            st[x][y] = self(self, x - 1, y);
        }
        else if (g[x][y] == 'D')
        {
            st[x][y] = self(self, x + 1, y);
        }
        else if (g[x][y] == 'L')
        {
            st[x][y] = self(self, x, y - 1);
        }
        else
        {
            st[x][y] = self(self, x, y + 1);
        }
        path[x][y] = 0;
        return st[x][y];
    };
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (!dfs(dfs, i, j))
                ans++;
        }
    cout << ans << '\n';
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
