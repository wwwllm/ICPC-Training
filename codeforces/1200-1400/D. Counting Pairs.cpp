#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2051/D
void solve()
{
    int n;
    int x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    int sum = 0;
    for (auto &it : a)
        cin >> it, sum += it;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // 因为l,r是单调的所以还可以用双指针
        auto l = upper_bound(a.begin() + i + 1, a.end(), sum - a[i] - x);
        auto r = lower_bound(a.begin() + i + 1, a.end(), sum - a[i] - y);
        ans += abs(l - r);
        // cout << ans << endl;
    }
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