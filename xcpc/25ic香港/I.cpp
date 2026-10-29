#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9, mod = 1e9 + 7;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
            g[i][j]--;
        }
    }
    vector dp1(n, vector<int>(n)), dp2(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        dp1[i][i] = 1;
        dp2[i][i] = 1;
    }
    vector rank(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rank[i][g[i][j]] = j;
        }
    }
    vector st(n, vector<int>(n, 1));
    {

        for (int l = 0; l < n; l++)
        {
            vector<int> mi(m, inf), mx(m, -1);
            for (int r = l; r < n; r++)
            {
                int u = g[0][r];
                for (int i = 0; i < m; i++)
                {
                    mi[i] = min(mi[i], rank[i][u]);
                    mx[i] = max(mx[i], rank[i][u]);
                }
                for (int i = 0; i < m; i++)
                {
                    st[l][r] &= (mx[i] - mi[i] == r - l);
                    st[l][r] &= rank[i][g[0][l]] == mi[i];
                }
            }
        }
    }
    for (int len = 2; len <= n; len++)
    {
        for (int l = 0; l + len - 1 < n; l++)
        {
            int r = l + len - 1;
            if (st[l][r])
                dp1[l][r] = dp2[l + 1][r];
            int res = dp1[l][r];
            for (int k = l; k < r; k++)
            {
                if (st[l][k])
                    (res += dp1[l][k] * dp2[k + 1][r]) %= mod;
            }
            dp2[l][r] = res;
        }
    }
    cout << dp1[0][n - 1] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}