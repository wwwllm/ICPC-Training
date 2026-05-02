#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5;
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 2>> a;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
            a.push_back({x, y});
    }
    vector<int> dp(N + 1);
    for (auto [x, y] : a)
    {
        int d = x - y;
        for (int i = x; i <= N; i += x)
        {
            dp[i] = max(dp[i], (i / x) * d);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        dp[i] = max(dp[i], dp[i - 1]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << x - dp[x] << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}