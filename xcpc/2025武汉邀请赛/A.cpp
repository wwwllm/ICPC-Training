#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
void solve()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n + 1);
    vector<array<int, 2>> q(n + 1, {1LL, INF});
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    bool ok = 1;
    while (t--)
    {
        int p, l, r;
        cin >> p >> l >> r;
        l = max(q[p][0], l);
        r = min(q[p][1], r);
        q[p] = {l, r};
        if (l > r)
            ok = 0;
    }
    if (!ok)
    {
        cout << -1 << '\n';
        return;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        auto [l, r] = q[i];
        if (a[i] > r)
            res = a[i] - r;
        else if (a[i] < l)
            res = l - a[i];
        ans += res;
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