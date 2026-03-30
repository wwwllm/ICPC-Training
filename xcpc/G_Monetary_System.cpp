#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105945
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> cnt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp(a[n - 1] + 1);
    for (int i = 1; i <= a[n - 1]; i++)
    {
        int pos = ranges::upper_bound(a, i) - a.begin() - 1;
        dp[i] = dp[i - a[pos]] + 1;
    }
    ranges::sort(dp);
    while (q--)
    {
        int m;
        cin >> m;
        cout << ranges::upper_bound(dp, m) - dp.begin() - 1 << ' ';
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