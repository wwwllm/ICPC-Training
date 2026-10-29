#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    map<string, int> mp;
    int sum = 0;
    vector<pair<int, string>> a(n);
    int c = 1e9;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        c = min(c, x);
    }
    vector<int> pos(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        pos[i] = i;
    }
    ranges::sort(pos, [&](int x, int y)
                 { return a[x] > a[y]; });
    ranges::sort(a, greater<>());
    for (int i = 0; i < n; i++)
    {
        sum -= mp[a[i].second];
        mp[a[i].second] = min(c, mp[a[i].second] + 1);
        sum += mp[a[i].second];
        ans[pos[i]] = sum;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << '\n';
    }
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