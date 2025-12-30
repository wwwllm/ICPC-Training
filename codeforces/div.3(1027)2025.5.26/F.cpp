#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    vector<array<int, 2>> xp, yp;
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0)
                x /= i, s++;
            xp.push_back({i, s});
        }
    }
    if (x != 1)
        xp.push_back({x, 1});
    for (int i = 2; i <= y / i; i++)
    {
        if (y % i == 0)
        {
            int s = 0;
            while (y % i == 0)
                y /= i, s++;
            yp.push_back({i, s});
        }
    }
    if (y != 1)
        yp.push_back({y, 1});
    int ans = 0;
    bool ok = 1;
    map<int, int> mp;
    for (auto [p, s] : xp)
    {
        mp[p] += s;
    }
    for (auto [p, s] : yp)
    {
        mp[p] -= s;
    }
    vector<array<int, 2>> temp;
    for (auto [p, s] : mp)
        if (s)
        {
            ans += s / (k / p) + s % (k / p);
            if (p > k)
            {
                cout << -1 << '\n';
                return;
            }
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