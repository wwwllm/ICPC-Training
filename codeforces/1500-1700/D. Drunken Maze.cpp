#include <bits/stdc++.h>
#define pb push_back
using namespace std;

// https://codeforces.com/problemset/problem/2041/D
const int INF = 0x3f3f3f3f;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> g(n + 1);
    array<int, 2> s, t;
    for (int i = 1; i <= n; i++)
        cin >> g[i], g[i] = ' ' + g[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == 'S')
                s = {i, j};
            if (g[i][j] == 'T')
                t = {i, j};
        }
    }
    vector<int> dx(4), dy(4);
    dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
    vector<vector<array<array<int, 4>, 4>>> st(n + 1, vector<array<array<int, 4>, 4>>(m + 1));
    queue<array<int, 5>> q;
    q.push({s[0], s[1], 0, 0, -1});
    st[s[0]][s[1]][0][0] = 1;
    int ans = -1;
    auto cmp = [&](int x, int y) -> bool
    {
        return (x >= 1 && x <= n) && y >= 1 && y <= m;
    };
    while (q.size())
    {
        auto [x, y, d, k, r] = q.front();
        q.pop();
        //cout << x << ' ' << y << '\n';
        if (x == t[0] && y == t[1])
        {
            ans = d;
            break;
        }
        if (r == -1)
        {
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i], yy = y + dy[i];
                if (cmp(xx, yy) && g[xx][yy] == '.' && st[xx][yy][i][1] == 0)
                    q.push({xx, yy, d + 1, 1, i}), st[xx][yy][i][1] = 1;
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i], yy = y + dy[i];
                if ((!cmp(xx, yy)) || g[xx][yy] == '#')
                    continue;
                if (r != i && st[xx][yy][i][1] == 0)
                    q.push({xx, yy, d + 1, 1, i}), st[xx][yy][i][1] = 1;
                else
                {
                    if (k + 1 <= 3 && st[xx][yy][i][k + 1]==0)
                        q.push({xx, yy, d + 1, k + 1, i}), st[xx][yy][i][k+1] = 1;
                }
            }
        }
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