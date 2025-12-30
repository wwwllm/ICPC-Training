#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2002/C
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 2>> p(n);
    for (auto &[x, y] : p)
        cin >> x >> y;
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    auto dist = [&](int x, int y) -> int
    {
        return (x - xt) * (x - xt) + (y - yt) * (y - yt);
    };
    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        auto [x, y] = p[i];
        d[i] = dist(x, y);
    }
    int mi = *min_element(d.begin(), d.end());
    int res = dist(xs, ys);
    if (mi > res)
        cout << "YES\n";
    else
        cout << "NO\n";
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