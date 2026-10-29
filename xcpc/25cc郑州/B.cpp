#include <bits/stdc++.h>
// #define int long long
using namespace std;

using i64 = long long;
const i64 inf = 4e18, mod = 1e9 + 7;
void solve()
{
    array<int, 3> W;
    cin >> W[0] >> W[1] >> W[2];
    array<int, 3> cnt;
    cin >> cnt[0] >> cnt[1] >> cnt[2];
    i64 sum = (cnt[0] + 1) * (cnt[1] + 1) * (cnt[2] + 1);
    int n;
    cin >> n;
    vector<array<int, 3>> p(n);
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        p[i] = {x, y, z};
    }
    for (int i = 0; i < 3; i++)
    {
        if (n % (cnt[i] + 1) != 0)
        {
            cout << "0\n";
            return;
        }
    }
    if (n % sum != 0)
    {
        cout << "0\n";
        return;
    }
    i64 ans = 1;
    vector cut(3, vector<int>{0});

    for (int i = 0; i < 3; i++)
    {
        if (cnt[i] == 0)
            continue;
        ranges::sort(p, [&](auto a, auto &b)
                     { return a[i] < b[i]; });
        int m = n / (cnt[i] + 1);
        for (int j = m - 1; j < n - 1; j += m)
        {
            cut[i].push_back(p[j][i]);
            (ans *= (p[j + 1][i] - p[j][i])) %= mod;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cut[i].push_back(W[i] + 1);
    }
    if (ans == 0)
    {
        cout << ans << '\n';
        return;
    }
    vector<vector<int>> C;
    auto check = [&](int i, int j) -> bool
    {
        // cerr << "{" << i << ' ' << j << "}\n";
        int n = cut[i].size() - 1, m = cut[j].size() - 1;
        C.assign(n, vector<int>(m, 0));
        for (auto pp : p)
        {
            int x = ranges::lower_bound(cut[i], pp[i]) - cut[i].begin() - 1;
            int y = ranges::lower_bound(cut[j], pp[j]) - cut[j].begin() - 1;
            // cerr << pp[i] << ' ' << pp[j] << ": " << x << ' ' << y << '\n';
            C[x][y]++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (C[i][j] != C[0][0])
                    return 0;
            }
        }
        return 1;
    };
    bool ok = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i < j)
                ok &= check(i, j);
        }
    }
    if (ok)
    {
        cout << ans << '\n';
    }
    else
    {
        cout << "0\n";
    }
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