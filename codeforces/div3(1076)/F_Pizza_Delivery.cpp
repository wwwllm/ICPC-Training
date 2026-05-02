#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int inf = 1e9;
void solve()
{
    int n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    vector<array<int, 2>> p(n);
    vector<int> b;
    for (int i = 0; i < n; i++)
        cin >> p[i][0], b.pb(p[i][0]);
    for (int i = 0; i < n; i++)
        cin >> p[i][1];
    ranges::sort(b);
    b.erase(ranges::unique(b).begin(), b.end());
    auto find = [&](int x)
    {
        return ranges::lower_bound(b, x) - b.begin();
    };
    int m = b.size();
    vector<array<int, 2>> q(m, {inf, 0});
    for (auto [x, y] : p)
    {
        int idx = find(x);
        q[idx][0] = min(y, q[idx][0]);
        q[idx][1] = max(y, q[idx][1]);
    }
    vector<array<int, 2>> dp(m);
    dp[0][0] = abs(q[0][0] - q[0][1]) + abs(ay - q[0][1]) + abs(ax - b[0]);
    dp[0][1] = abs(q[0][0] - q[0][1]) + abs(ay - q[0][0]) + abs(ax - b[0]);
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + abs(q[i - 1][0] - q[i][1]), dp[i - 1][1] + abs(q[i - 1][1] - q[i][1])) + abs(q[i][0] - q[i][1]) + abs(b[i] - b[i - 1]);
        dp[i][1] = min(dp[i - 1][0] + abs(q[i - 1][0] - q[i][0]), dp[i - 1][1] + abs(q[i - 1][1] - q[i][0])) + abs(q[i][0] - q[i][1]) + abs(b[i] - b[i - 1]);
    }
    int ans = min(dp[m - 1][0] + abs(by - q[m - 1][0]), dp[m - 1][1] + abs(by - q[m - 1][1])) + abs(b[m - 1] - bx);
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}