#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a;
    for (int i = 1; i <= m; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        a.push_back({l, 0, c});
        a.push_back({r, 1, c});
    }
    sort(a.begin(), a.end());
    int res = 0;
    int ans = INF;
    for (int i = 0; i < a.size(); i++)
    {
        auto [d, op, c] = a[i];
        if (op)
        {
            res -= c;
            if (d < n)
                ans = min(ans, res);
        }
        else
        {
            while (a[i + 1][0] == a[i][0] && a[i + 1][1] == a[i][1])
                res += a[i++][2];
            res += a[i][2];
            ans = min(res, ans);
        }
    }
    if (a[0][0] != 1 || a.back()[0] != n)
        cout << 0 << '\n';
    else
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