#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    vector<vector<int>> num(n, vector<int>(m));
    vector<vector<bool>> st(n, vector<bool>(m));
    for (auto &it : g)
        cin >>
            it;
    int id = 0;
    array<int, 2> d[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    auto dfs = [&](auto &&self, int x, int y, int id) -> void
    {
        num[x][y] = id;
        st[x][y] = 1;
        for (auto [dx, dy] : d)
        {
            int xx = x + dx, yy = y + dy;
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] == '1' && !st[xx][yy])
                self(self, xx, yy, id);
        }
    };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (!st[i][j] && g[i][j] == '1')
            {
                id++;
                dfs(dfs, i, j, id);
            }
        }
    vector<int> res(n * m + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '0')
            {
                map<int, bool> mp;
                for (auto [dx, dy] : d)
                {
                    int x = i + dx, y = j + dy;
                    if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '1' && mp[num[x][y]] == 0)
                    {
                        res[num[x][y]]++;
                        mp[num[x][y]] = 1;
                    }
                }
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= id; i++)
    {
        ans = min(ans, res[i]);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}