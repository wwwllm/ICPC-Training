#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &x : g)
        cin >> x;
    bool flag = g[0][m-1]=='.';
    vector cnt(n, vector<array<int, 2>>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int x = i, y = j, op = 0;
            if (g[i][j] == '.' && (i != 0 || j != m - 1))
                flag = 0;
            if (g[i][j] != 'C' && g[i][j] != '.')
            {
                if (g[i][j] == 'L')
                    y--;
                if (g[i][j] == 'R')
                    y++;
                if (g[i][j] == 'U')
                    x--, op = 1;
                if (g[i][j] == 'D')
                    x++, op = 1;
                if (x >= 0 & x < n && y >= 0 && y < m && g[x][y] == 'C')
                    cnt[x][y][op]++;
                else
                    flag = 0;
            }
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'C' && (cnt[i][j][0] != 1 || cnt[i][j][1] != 1))
                flag = 0;
        }
    cout << (flag ? "Yes" : "No") << endl;
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