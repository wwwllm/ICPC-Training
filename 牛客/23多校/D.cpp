#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            g[i][j] = c - '0';
        }
    }
    auto calc = [&](const vector<vector<int>> &g) -> int
    {
        auto a = g[0];
        auto ra = a;
        for (int i = 0; i < n; i++)
        {
            ra[i] ^= 1;
        }
        bool ok = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            ok &= (g[i] == a || g[i] == ra);
            if (g[i] == ra)
            {
                cnt++;
            }
        }
        if (!ok)
            return -1;
        int c1 = ranges::count(a, 1);
        return min(c1, n - c1) + min(cnt, n - cnt);
    };
    cout << calc(g) << '\n';
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