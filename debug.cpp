#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18, mod = 1e9 + 7;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector pre1(n + 1, vector<int>(m + 1));
    vector pre2(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cur = 0;
            if (i == j)
                cur = 1;
            else if (i > j)
                cur = pre1[j][i - j];

            pre2[j][i] = (pre2[j - 1][i] + cur) % mod;
            pre1[j][i] = (pre1[j - 1][i] + pre2[j][i]) % mod;
        }
    }
    if (n == m)
        cout << 1 << '\n';
    else
        cout << pre1[n][m - n] << '\n';
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