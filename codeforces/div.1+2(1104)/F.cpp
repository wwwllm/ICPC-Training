#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
    {
        l[i] = i - a[i] + 1;
        r[i] = i + m - a[i];
        if (l[i] < 1 || r[i] > n)
            l[i] = r[i] = -1;
    }
    vector<int> t(n + 1);
    vector<int> pre1(n + 1);
    vector<int> pre2(n + 1);
    vector<int> dp(n + 1);
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        if (l[i] == -1)
        {
            pre2[i] = pre2[i - 1];
            cur = max(cur, pre1[i]);
            continue;
        }
        dp[i] = 1;
        dp[i] = max(dp[i], t[l[i]] + 1);
        dp[i] = max(dp[i], pre2[l[i] - 1] + 1);
        dp[i] = max(dp[i], cur + 1);
        pre2[i] = max(pre2[i - 1], dp[i]);
        pre1[r[i]] = max(pre1[r[i]], dp[i]);
        cur = max(pre1[i], cur);
        t[l[i]] = max(t[l[i]], dp[i]);
    }
    cout << n - *ranges::max_element(dp) << '\n';
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
