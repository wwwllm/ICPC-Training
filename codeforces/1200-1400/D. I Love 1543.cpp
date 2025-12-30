#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2036/D
const int T[4] = {1, 5, 4, 3};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &it : s)
        cin >> it;
    vector<vector<int>> g(n + 2, vector<int>(m + 2, 0)), st(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            g[i][j] = s[i - 1][j - 1] - '0';
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> res;
    int q = min(n, m) / 2;
    auto cmp = [&](int x, int y) -> bool
    {
        return x <= n && x >= 1 && y <= m && y >= 1 && st[x][y] == 0;
    };
    int ans = 0;
    for (int i = 1; i <= q; i++)
    {
        vector<int> res;
        int x = i, y = i;
        res.push_back(g[x][y]);
        st[x][y] = 1;
        int op = 0;
        while (1)
        {
            int dx = x + d[op][0], dy = y + d[op][1];
            if (cmp(dx, dy))
            {
                x = dx, y = dy;
                st[x][y] = 1;
                res.push_back(g[x][y]);
            }
            else
            {
                op++;
                if (op == 4)
                    break;
                dx = x + d[op][0], dy = y + d[op][1];
                if (cmp(dx, dy))
                {
                    x = dx, y = dy;
                    st[x][y] = 1;
                    res.push_back(g[x][y]);
                }
                else
                    break;
            }
        }
        res.insert(res.end(), res.begin(), res.end());
        int len = res.size();
        for (int i = 0; i < len / 2; i++)
        {
            if (res[i] == 1)
            {
                int j = 0;
                for (; j < 4; j++)
                {
                    if (res[i + j] != T[j])
                        break;
                }
                if (j == 4)
                    ans++, i += j - 1;
            }
        }
    }
    cout << ans << endl;
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