#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    int ans = 1e9;
    for (int i = 0; i <= z; i++)
    {
        int X = i + x, Y = y + (z - i);
        int res1 = (X / 2) * a + (Y / 2) * c + min(((X % 2) | (Y % 2)) * b, (X % 2) * min(a, b) + (Y % 2) * min(b, c));
        int res2 = (min(X, Y) + abs(X - Y)) * b;
        int res3 = min(X, Y) * b + max(0, X - Y) / 2 * a + max(0, X - Y) % 2 * min(a, b) + max(0, Y - X) / 2 * c + max(0, Y - X) % 2 * min(b, c);
        ans = min({ans, res1, res2, res3});
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