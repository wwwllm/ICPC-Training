#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(n);
    for (auto &[w, l, r] : a)
        cin >> w >> l >> r;
    ranges::sort(a, greater<>());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        m -= a[i][1];
        sum += a[i][1] * a[i][0];
    }
    vector<int> pre_cnt(n), pre_cost(n);
    pre_cnt[0] = a[0][2] - a[0][1];
    pre_cost[0] = (a[0][2] - a[0][1]) * a[0][0];
    for (int i = 1; i < n; i++)
    {
        pre_cnt[i] = pre_cnt[i - 1] + (a[i][2] - a[i][1]);
        pre_cost[i] = pre_cost[i - 1] + a[i][0] * (a[i][2] - a[i][1]);
    }
    int d = m * a[0][0];
    for (int i = 1; i < n; i++)
    {
        int c = a[i][1] + m;
        int pos = ranges::upper_bound(pre_cnt, c) - pre_cnt.begin() - 1;
        pos = min(pos, i - 1);
        if (pos == -1)
        {
            d = max(d, c * a[pos + 1][0] - a[i][1] * a[i][0]);
            continue;
        }
        int val1 = pre_cost[pos];
        int val2 = (c - pre_cnt[pos]) * a[pos + 1][0];
        d = max(d, val1 + val2 - a[i][1] * a[i][0]);
    }
    cout << sum + d << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}