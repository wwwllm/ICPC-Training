#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, w, k;
    cin >> n >> w >> k;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    ranges::sort(a);
    vector dp(n, vector<int>(w + 1, 0));
    for (int i = 0; i < n; i++)
    {
        auto [cost, val] = a[i];
        if (i)
            dp[i] = dp[i - 1];
        for (int j = cost; j <= w; j++)
        {
            if (i == 0)
            {
                dp[i][j] = val;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost] + val);
            }
        }
    }
    vector<int> suf(n + 1);
    multiset<int> s;
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        auto [_, val] = a[i];
        s.insert(val);
        sum += val;
        if (s.size() > k)
        {
            sum -= *s.begin();
            s.erase(s.begin());
        }
        suf[i] = sum;
    }
    int ans = suf[0];
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, suf[i + 1] + dp[i][w]);
    }
    cout << ans << '\n';
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