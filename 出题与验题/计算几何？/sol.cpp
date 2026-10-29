#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    array<int, 2> s, t;
    for (int i = 0; i < 2; i++)
        cin >> s[i];
    for (int i = 0; i < 2; i++)
        cin >> t[i];

    if (s == t)
    {
        cout << -1 << '\n';
        return;
    }
    set<int> x, y;
    x.insert((s[0] + t[0]));
    x.insert(2 * n - (s[0] + t[0]));
    x.insert(abs(s[0] - t[0]));
    x.insert(2 * n - abs(s[0] - t[0]));
    y.insert(s[1] + t[1]);
    y.insert(2 * m - (s[1] + t[1]));
    y.insert(abs(s[1] - t[1]));
    y.insert(2 * m - abs(s[1] - t[1]));
    cout << x.size() * y.size() << '\n';
    for (auto xx : x)
    {
        for (auto yy : y)
            cout << fixed << setprecision(9) << (long double)xx / 2.0 << ' ' << (long double)yy / 2.0 << '\n';
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