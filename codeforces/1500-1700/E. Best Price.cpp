#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), val;
    for (auto &x : a)
        cin >> x, val.push_back(x);
    for (auto &x : b)
        cin >> x, val.push_back(x);
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto f = [&](int x) -> int
    {
        int l = n - (lower_bound(a.begin(), a.end(), x) - a.begin());
        int r = n - (lower_bound(b.begin(), b.end(), x) - b.begin());
        if (r - l > k)
            return 0;
        else
            return r * x;
    };
    int ans = 0;
    for (auto x : val)
    {
        ans = max(ans, f(x));
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