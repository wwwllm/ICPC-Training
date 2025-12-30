#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2046/A
const int INF = 0x3f3f3f3f;
void solve()
{
    int n;
    cin >> n;
    int ma = -INF, ans = 0;
    vector<array<int, 2>> g(n);
    for (auto &[x, y] : g)
        cin >> x;
    for (auto &[x, y] : g)
        cin >> y;
    for (int i = 0; i < n; i++)
    {
        auto [a, b] = g[i];
        ans += max(a, b);
        ma = max(ma, min(a, b));
    }
    cout << ans + ma << endl;
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