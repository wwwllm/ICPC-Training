#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    multiset<int> x, y;
    vector<array<int, 2>> p(n), q;
    for (auto &[xx, yy] : p)
    {
        cin >> xx >> yy;
        x.insert(xx);
        y.insert(yy);
    }
    if (p.size() == 1)
    {
        cout << 1 << '\n';
        return;
    }
    int lx = *x.begin(), rx = *x.rbegin();
    int ly = *y.begin(), ry = *y.rbegin();
    int ans = (rx - lx + 1) * (ry - ly + 1);
    for (auto [xx, yy] : p)
    {
        if (xx == lx || xx == rx || yy == ly || yy == ry)
            q.push_back({xx, yy});
    }
    for (auto [xx, yy] : q)
    {
        auto itx = x.find(xx), ity = y.find(yy);
        x.erase(itx), y.erase(ity);
        lx = *x.begin(), rx = *x.rbegin();
        ly = *y.begin(), ry = *y.rbegin();
        int res = (rx - lx + 1) * (ry - ly + 1);
        if (res == x.size())
            res += min(rx - lx + 1, ry - ly + 1);
        ans = min(res, ans);
        x.insert(xx);
        y.insert(yy);
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