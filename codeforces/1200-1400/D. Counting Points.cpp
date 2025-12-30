#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2074/D
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(n);
    for (auto &[x, r] : a)
        cin >> x;
    for (auto &[x, r] : a)
        cin >> r;
    auto d = [&](int ox, int r, int x)
    {
        int ans = sqrt(r * r - (x - ox) * (x - ox));
        return ans;
    };
    map<int, int> mp;
    for (auto [x, r] : a)
    {
        for (int xx = x - r; xx <= x + r; xx++)
        {
            mp[xx] = max(mp[xx], d(x, r, xx));
        }
    }
    int ans = 0;
    for (auto [x, n] : mp)
        ans += 2 * n + 1;
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